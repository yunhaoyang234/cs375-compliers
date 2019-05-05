#!/bin/bash

# grading script for CS375 Spring2018 project 6 --- code generation
# with unittesting
#
# Lixun Zhang
# May. 11, 2018


echo "################### graph1.pas ######################"
for entry in ./graph1_test/*
do
    testN=$(basename "$entry")
    testN="${testN%.*}"
    echo "testing $entry: "
    ./compiler < $entry | sed -n "/# ------------------------- begin Your code -----------------------------/,//p" > tmp_result

    DIFF=$(diff -w ./graph1_sample/"$testN.sample" tmp_result)
    if [ "$DIFF" != "" ]
    then
        diff -w ./graph1_sample/"$testN.sample" tmp_result
    else
        echo "PASS!"
    fi
done

echo "################### pasrec.pas ######################"
for entry in ./pasrec_test/*
do
    testN=$(basename "$entry")
    testN="${testN%.*}"
    echo "testing $entry: "
    ./compiler < $entry | sed -n "/# ------------------------- begin Your code -----------------------------/,//p" > tmp_result

    DIFF=$(diff -w ./pasrec_sample/"$testN.sample" tmp_result)
    if [ "$DIFF" != "" ]
    then
        diff -w ./pasrec_sample/"$testN.sample" tmp_result
    else
        echo "PASS!"
    fi
done

rm tmp_result
