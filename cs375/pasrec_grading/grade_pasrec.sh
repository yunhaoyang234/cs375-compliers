#!/bin/bash

# grading script for CS375 Fall2018 project 5 --- parsing pasrec.pas
#
# Lixun Zhang
# Apr. 22nd, 2018


echo "#################################################################################"
echo "##############################  pasrec.pas output ###############################"
echo "#################################################################################"
./parser < pasrec.pas | sed -n "/Symbol table level 1/,//p"
echo ""
echo "#################################################################################"
echo "##############################  graph1.pas output ###############################"
echo "#################################################################################"
./parser < graph1.pas | sed -n "/Symbol table level 1/,//p"

echo ""
echo "###################################################################################"
echo "############################## Starting unit testing ##############################"
echo "###################################################################################"

# test0: symbol table
echo ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>> test0 symbol table >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
echo ">>> Symbol table level 1 should contain type and var defs"
echo ">>> common mistakes:"
echo ">>>     john, mary, fred, and ptr should have basicdt set to 4 instead of 0"
echo ">>>     Symbol c and d’s typ should be the same as complex’s typ, not complex’s address."
echo ">>>     Symbol john, mary, fred, and ptr’s typ should be same as pp’s typ, not pp’s address."
echo ">>> Result:"
unamestr=`uname`
if [[ "$unamestr" == 'Linux' ]]; then
    ./parser < test0_symtab.pas | sed -n "/Symbol table level 1/,//p" | head -n-1
else # for macOS
    ./parser < test0_symtab.pas | sed -n "/Symbol table level 1/,//p" | tail -r | tail -n +4 | tail -r
fi

# test1: new()
./parser < test1_newfun.pas | sed -n "/(program/,//p" > test1_result
echo ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>> test1 funcall new() >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
echo ">>> test cases:"
echo ">>>    new(john);new(mary);new(fred)   [line 19-21]"
echo ">>> Result:"
DIFF=$(diff test1_newfun.sample test1_result)
if [ "$DIFF" != "" ]
then
    diff -w test1_newfun.sample test1_result
else
    echo "PASS!"
fi

# test2: single level record reference
./parser < test2_simpleRec.pas | sed -n "/(program/,//p" > test2_result
echo ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>> test2 pointer and rec reference (simple) >>>>>>>>>>>"
echo ">>> test cases:"
echo ">>>    john^.favorite := blue;   [line 22]"
echo ">>>    john^.age := 19;          [line 23]"
echo ">>>    john^.friend := mary;     [line 25]"
echo ">>>    john^.salary := 40000.0;  [line 26]"
echo ">>>    mary^.age := 21;          [line 28]"
echo ">>>    mary^.friend := fred;     [line 29]"
echo ">>>    fred^.age := 20;          [line 31]"
echo ">>>    fred^.friend := nil;      [line 32]"
echo ">>>    sum := sum + ptr^.age;    [line 40]"
echo ">>>    ptr := ptr^.friend        [line 43]"
echo ">>> Result:"
DIFF=$(diff test2_simpleRec.sample test2_result)
if [ "$DIFF" != "" ]
then
    diff -w test2_simpleRec.sample test2_result
else
    echo "PASS!"
fi

# test3: multi-level record reference
./parser < test3_hardRec.pas | sed -n "/(program/,//p" > test3_result
echo ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>> test3 pointer and rec reference (hard) >>>>>>>>>>>>>"
echo ">>> test cases:"
echo ">>>    john^.location.re := 3;                    [line 27]"
echo ">>>    john^.friend^.friend^.location.im := 4.5   [line 33]"
echo ">>> Result:"
DIFF=$(diff test3_hardRec.sample test3_result)
if [ "$DIFF" != "" ]
then
    diff -w test3_hardRec.sample test3_result
else
    echo "PASS!"
fi

# test4: array access
./parser < test4_arr.pas | sed -n "/(program/,//p" > test4_result
echo ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>> test4 array access >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
echo ">>> test cases:"
echo ">>>    ac[7].re := john^.salary;        [line 34]"
echo ">>>    people[i].age := ptr^.age;       [line 41]"
echo ">>>    aco[i,white] := john^.favorite   [line 42]"
echo ">>> Result:"
DIFF=$(diff test4_arr.sample test4_result)
if [ "$DIFF" != "" ]
then
    diff -w test4_arr.sample test4_result
else
    echo "PASS!"
fi

# test5: while loop
./parser < test5_while.pas | sed -n "/(program/,//p" > test5_result
# - compare the difference
echo ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>> test5 while loop >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
echo ">>> test cases:"
echo ">>>    while ptr <> nil do   [line 38]"
echo ">>>      begin               [line 39]"
echo ">>>        i := i + 1        [line 44]"
echo ">>>      end                 [line 45]"
echo ">>> Result:"
DIFF=$(diff test5_while.sample test5_result)
if [ "$DIFF" != "" ]
then
    diff -w test5_while.sample test5_result
else
    echo "PASS!"
fi

# test6: label/goto
./parser < test6_label.pas | sed -n "/(program/,//p" > test6_result
echo ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>> test6 label/goto stmt >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
echo ">>> test cases:"
echo ">>>    1492: -----------> label 1  [line 24]"
echo ">>>      john^.friend := mary;     [line 25]"
echo ">>>    1776: -----------> label 0  [line 30]"
echo ">>>      fred^.age := 20           [line 31]"
echo ">>>    if sum < 3 then goto 1776   [line 52]"
echo ">>> Result:"
DIFF1=$(diff test6_label.sample test6_result)
DIFF2=$(diff test6_label1.sample test6_result)
if [ "$DIFF1" != "" ] && [ "$DIFF2" != "" ]
then
    diff -w test6_label.sample test6_result
else
    echo "PASS!"
fi

# test7: write funcall
./parser < test7_write.pas | sed -n "/(program/,//p" > test7_result
echo ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>> test7 write funcall >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
echo ">>> test cases:"
echo ">>>    write('i = ');                [line 46]"
echo ">>>    writeln(i);                   [line 47]"
echo ">>>    write('Sum of ages = ');      [line 48]"
echo ">>>    writeln(sum);                 [line 49]"
echo ">>>    write('Fred loc im = ');      [line 50]"
echo ">>>    writeln(fred^.location.im);   [line 51]"
echo ">>> Result:"
DIFF=$(diff test7_write.sample test7_result)
if [ "$DIFF" != "" ]
then
    diff -w test7_write.sample test7_result
else
    echo "PASS!"
fi

# clean generated files
rm test*_result
