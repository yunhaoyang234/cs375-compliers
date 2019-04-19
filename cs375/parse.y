%{     /* pars1.y    Pascal Parser      Gordon S. Novak Jr.  ; 30 Jul 13   */

/* Copyright (c) 2013 Gordon S. Novak Jr. and
   The University of Texas at Austin. */

/* 14 Feb 01; 01 Oct 04; 02 Mar 07; 27 Feb 08; 24 Jul 09; 02 Aug 12 */

/*
; This program is free software; you can redistribute it and/or modify
; it under the terms of the GNU General Public License as published by
; the Free Software Foundation; either version 2 of the License, or
; (at your option) any later version.

; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.

; You should have received a copy of the GNU General Public License
; along with this program; if not, see <http://www.gnu.org/licenses/>.
  */


/* NOTE:   Copy your lexan.l lexical analyzer to this directory.      */

       /* To use:
                     make pars1y              has 1 shift/reduce conflict
                     pars1y                   execute the parser
                     i:=j .
                     ^D                       control-D to end input

                     pars1y                   execute the parser
                     begin i:=j; if i+j then x:=a+b*c else x:=a*b+c; k:=i end.
                     ^D

                     pars1y                   execute the parser
                     if x+y then if y+z then i:=j else k:=2.
                     ^D

           You may copy pars1.y to be parse.y and extend it for your
           assignment.  Then use   make parser   as above.
        */

        /* Yacc reports 1 shift/reduce conflict, due to the ELSE part of
           the IF statement, but Yacc's default resolves it in the right way.*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "token.h"
#include "lexan.h"
#include "symtab.h"
#include "parse.h"
#include "pprint.h"

        /* define the type of the Yacc stack element to be TOKEN */

#define YYSTYPE TOKEN

TOKEN parseresult;

%}

/* Order of tokens corresponds to tokendefs.c; do not change */

%token IDENTIFIER STRING NUMBER   /* token types */

%token PLUS MINUS TIMES DIVIDE    /* Operators */
%token ASSIGN EQ NE LT LE GE GT POINT DOT AND OR NOT DIV MOD IN

%token COMMA                      /* Delimiters */
%token SEMICOLON COLON LPAREN RPAREN LBRACKET RBRACKET DOTDOT

%token ARRAY BEGINBEGIN           /* Lex uses BEGIN */
%token CASE CONST DO DOWNTO ELSE END FILEFILE FOR FUNCTION GOTO IF LABEL NIL
%token OF PACKED PROCEDURE PROGRAM RECORD REPEAT SET THEN TO TYPE UNTIL
%token VAR WHILE WITH


%%

program    : PROGRAM IDENTIFIER LPAREN id_list RPAREN SEMICOLON lblock DOT { parseresult = makeprogram($2, $4, $7); } ;
           ;
  id_list    :  IDENTIFIER COMMA id_list       { $$ = cons($1, $3); }
             |  IDENTIFIER                    
             ;
  block      :  BEGINBEGIN statement endpart   { $$ = makeprogn($1,cons($2, $3)); }
             ;
  sign       :  PLUS 
             |  MINUS
             ;
  constant   :  IDENTIFIER                     { $$ = findid($1); }
             |  sign IDENTIFIER                { $$ = unaryop($1, $2); }
             |  NUMBER
             |  sign NUMBER                    { $$ = unaryop($1, $2); }
             |  STRING
             ;
  vdef       :  id_list COLON type             { instvars($1, $3); }
             ;
  vdef_list  :  vdef SEMICOLON vdef_list
             |  vdef SEMICOLON
             ;
  vblock     :  VAR vdef_list block            { $$ = $3; }
             |  block
             ;
  tdef       :  IDENTIFIER EQ type             { insttype($1, $3); }
             ;
  tdef_list  :  tdef SEMICOLON tdef_list
             |  tdef SEMICOLON
             ;
  tblock     :  TYPE tdef_list vblock          { $$ = $3; }
             |  vblock
             ;
  cdef       :  IDENTIFIER EQ constant         { instconst($1, $3); }
             ;
  cdef_list  :  cdef SEMICOLON cdef_list
             |  cdef SEMICOLON
             ;
  cblock     :  CONST cdef_list tblock         { $$ = $3; }
             |  tblock
             ;
  label      :  NUMBER COLON statement         { $$ = dolabel($1, $2, $3); }
             ;
  numlist    :  NUMBER COMMA numlist           { instlabel($1); }
             |  NUMBER                         { instlabel($1); }
             ;
  lblock     :  LABEL numlist SEMICOLON cblock { $$ = $4; }
             |  cblock
             ;
  simpletype :  IDENTIFIER                     { $$ = findtype($1); }
             |  LPAREN id_list RPAREN          { $$ = instenum($2); }
             |  constant DOTDOT constant       { $$ = instdotdot($1, $2, $3); }
             ;
  simple_type_list : simpletype COMMA simple_type_list  { $$ = cons($1, $3); }
             |  simpletype                    { $$ = cons($1, NULL); }
             ;
  type       :  simpletype		               { $$ = $1; }
             |  ARRAY LBRACKET simple_type_list RBRACKET OF type  { $$ = instarray($3, $6); }
             |  RECORD field_list END		   { $$ = instrec($1, $2); }
             |  POINT IDENTIFIER               { $$ = instpoint($1, $2); }
             ;
  statement_list :  statement SEMICOLON statement_list { $$ = cons($1, $3); }
             |  statement                      { $$ = cons($1, NULL); }
             ;
  statement  :  BEGINBEGIN statement endpart          { $$ = makeprogn($1,cons($2, $3)); }
             |  IF expression THEN statement endif    { $$ = makeif($1, $2, $4, $5); }
             |  assignment
             |  funcall
             |  REPEAT statement_list UNTIL expression      { $$ = makerepeat($1, $2, $3, $4); }
             |  FOR assignment TO expression DO statement   { $$ = makefor(1, $1, $2, $3, $4, $5, $6); }
             |  WHILE expression DO statement		   { $$ = makewhile($1, $2, $3, $4); }
             |  GOTO NUMBER					   { $$ = dogoto($1, $2); }
             |  label
             ;
  assignment :  variable ASSIGN expression     { $$ = binop($2, $1, $3); }
             ;
  funcall    :  IDENTIFIER LPAREN expr_list RPAREN  { $$ = makefuncall($2, $1, $3); }
             ;
  expr_list  :  expression COMMA expr_list     { $$ = cons($1, $3); }
             |  expression
             ;
  fields     :  id_list COLON type             { $$ = instfields($1, $3); }
             ;
  field_list :  fields SEMICOLON field_list    { $$ = nconc($1, $3); }
             |  fields
             ;
  variable   :  IDENTIFIER                     { $$ = findid($1); }
             |  variable LBRACKET expr_list RBRACKET  { $$ = arrayref($1, $2, $3, $4); }
             |  variable DOT IDENTIFIER		   { $$ = reducedot($1, $2, $3); }
             |  variable POINT				   { $$ = dopoint($1, $2); }
             ;
  plus_op    :  PLUS 
             |  MINUS 
             |  OR
             ;
  times_op   :  TIMES 
             |  DIVIDE 
             |  DIV 
             |  MOD 
             |  AND
             ;
  compare_op :  EQ 
             |  LT 
             |  GT 
             |  NE 
             |  LE 
             |  GE 
             |  IN
             ;
  endpart    :  SEMICOLON statement endpart    { $$ = cons($2, $3); }
             |  END                            { $$ = NULL; }
             ;
  endif      :  ELSE statement                 { $$ = $2; }
             |  /* empty */                    { $$ = NULL; }
             ;
  term       :  term times_op factor           { $$ = binop($2, $1, $3); }
             |  factor
             ;
  simple_expression :  sign term               { $$ = unaryop($1, $2); }
             |  term
             |  simple_expression plus_op term { $$ = binop($2, $1, $3); }
             ;
  expression :  expression compare_op simple_expression { $$ = binop($2, $1, $3); }
             |  simple_expression
             ;
  factor     :  constant
             |  variable
             |  funcall
             |  LPAREN expression RPAREN       { $$ = $2; }
             |  NOT factor                     { $$ = unaryop($1, $2); }
             ;
%%

/* You should add your own debugging flags below, and add debugging
   printouts to your programs.

   You will want to change DEBUG to turn off printouts once things
   are working.
  */

#define DEBUG        31              /* set bits here for debugging, 0 = off  */
#define DB_CONS       1             /* bit to trace cons */
#define DB_BINOP      2             /* bit to trace binop */
#define DB_MAKEIF     4             /* bit to trace makeif */
#define DB_MAKEPROGN  8             /* bit to trace makeprogn */
#define DB_PARSERES  16             /* bit to trace parseresult */

 int labelnumber = 0;  /* sequential counter for internal label numbers */
 int label_list[100];

   /*  Note: you should add to the above values and insert debugging
       printouts in your routines similar to those that are shown here.     */

TOKEN cons(TOKEN item, TOKEN list)           /* add item to front of list */
  { item->link = list;
    if (DEBUG & DB_CONS)
       { printf("cons\n");
         dbugprinttok(item);
         dbugprinttok(list);
       };
    return item;
  }

TOKEN binop(TOKEN op, TOKEN lhs, TOKEN rhs)        /* reduce binary operator */
  { op->operands = lhs;          /* link operands to operator       */
    lhs->link = rhs;             /* link second operand to first    */
    rhs->link = NULL;            /* terminate operand list          */
    TOKEN op_tok;
    /*======================start of second part=======================*/
    if (lhs->basicdt == REAL && rhs->basicdt == REAL) {
        op->basicdt = REAL;
    }else if(lhs->basicdt == REAL && rhs->basicdt == INTEGER){
        op->basicdt = REAL;
        op_tok = makefloat(rhs);
        lhs->link = op_tok;
    }else if(lhs->basicdt == INTEGER && rhs->basicdt == REAL){
        if(op->whichval == ASSIGNOP){
            op->basicdt = INTEGER;
            op_tok = makefix(rhs);
            lhs->link = op_tok;
        }else{
            op->basicdt = REAL;
            op_tok = makefloat(lhs);
            op_tok->link = rhs;
        }
    }else if(lhs->basicdt == INTEGER && rhs->basicdt == INTEGER){
        op->basicdt = INTEGER;
    }
    /*======================end of second part=======================*/
    if (DEBUG & DB_BINOP)
       { printf("binop\n");
         dbugprinttok(op);
         dbugprinttok(lhs);
         dbugprinttok(rhs);
       };
    return op;
  }

/*======================start of first part=======================*/
TOKEN maketok(int type, int val, TOKEN opd){
    TOKEN tok = talloc();
    tok->tokentype = type;
    tok->whichval = val;
    tok->operands = opd;
    if(DEBUG){
        printf("maketok\n");
        dbugprinttok(opd);
        dbugprinttok(tok);
    }
    return tok;
}


TOKEN copytok(TOKEN tok){
    TOKEN newtok = talloc();
    newtok->tokentype = tok->tokentype;
    newtok->whichval = tok->whichval;
    newtok->operands = tok->operands;
    newtok->link = tok->link;
    newtok->intval = tok->intval;
    newtok->realval = tok->realval;
    newtok->symtype = tok->symtype;
    newtok->symentry = tok->symentry;
    if(tok->stringval[0]!='\0')
        strncpy(newtok->stringval, tok->stringval, 16);
    if(DEBUG){
        printf("copytok\n");
    }
    return newtok;
}

TOKEN makeop(int opnum){
    return maketok(OPERATOR, opnum, NULL);
}
/*======================end of first part=======================*/

TOKEN makeif(TOKEN tok, TOKEN exp, TOKEN thenpart, TOKEN elsepart)
  {  tok->tokentype = OPERATOR;  /* Make it look like an operator   */
     tok->whichval = IFOP;
     if (elsepart != NULL) elsepart->link = NULL;
     thenpart->link = elsepart;
     exp->link = thenpart;
     tok->operands = exp;
     if (DEBUG & DB_MAKEIF)
        { printf("makeif\n");
          dbugprinttok(tok);
          dbugprinttok(exp);
          dbugprinttok(thenpart);
          dbugprinttok(elsepart);
        };
     return tok;
   }

TOKEN makeprogn(TOKEN tok, TOKEN statements)
  {  tok->tokentype = OPERATOR;
     tok->whichval = PROGNOP;
     tok->operands = statements;
     if (DEBUG & DB_MAKEPROGN)
       { printf("makeprogn\n");
         dbugprinttok(tok);
         dbugprinttok(statements);
       };
     return tok;
   }

/*===================================================================
========================start of first part==========================
===================================================================*/
TOKEN makeintc(int num){
    TOKEN tok = maketok(NUMBERTOK, INTEGER, NULL);
    tok->intval = num;
    tok->basicdt = INTEGER;
    if (DEBUG) {
        printf("makeintc\n");
        dbugprinttok(tok);
    }
    return tok;
}

TOKEN makelabel(){
    TOKEN tok, inttok;
    inttok = makeintc(labelnumber);
    tok = maketok(OPERATOR, LABELOP, inttok);
    labelnumber++;
    return tok;
}

TOKEN makegoto(int label){
    if(label<0) printf("invalid makegoto");
    TOKEN tok = maketok(OPERATOR, GOTOOP, makeintc(label));
    if (DEBUG) {
        printf("makegoto\n");
        dbugprinttok(tok);
    }
    return tok;
}

TOKEN makefor(int sign, TOKEN tok, TOKEN asg, TOKEN tokb, TOKEN endexpr,
              TOKEN tokc, TOKEN statement)
{
    TOKEN label_tok, if_tok, op_tok, trace_tok, trace_tok1, trace_tok2, trace_tok3,
        asg_tok, op_tok2, goto_tok, do_tok;
    tok = makeprogn(tok, asg);
    label_tok = makelabel();
    asg->link = label_tok;

    if(sign == 1)
        op_tok = makeop(LEOP);
    else
        op_tok = makeop(GEOP);
    trace_tok1 = copytok(asg->operands);
    trace_tok1->link = endexpr;
    op_tok->operands = trace_tok1;

    do_tok = talloc();
    do_tok = makeprogn(do_tok, statement);

    if_tok = talloc();
    if_tok = makeif(if_tok, op_tok, do_tok, NULL);
    label_tok->link = if_tok;

    trace_tok2 = copytok(trace_tok1);
    trace_tok3 = copytok(trace_tok1);
    asg_tok = makeop(ASSIGNOP);
    if(sign == 1)
        op_tok2 = makeop(PLUSOP);
    else
        op_tok2 = makeop(MINUSOP);
    op_tok2 = binop(op_tok2, trace_tok3, makeintc(1));
    asg_tok = binop(asg_tok, trace_tok2, op_tok2);
    statement->link = asg_tok;

    goto_tok = makegoto(label_tok->operands->intval);
    asg_tok->link = goto_tok;

    return tok;
}

TOKEN makefuncall(TOKEN tok, TOKEN fn, TOKEN args)
{
    if(!strcmp(fn->stringval, "new")){
        tok = makeop(ASSIGNOP);
        TOKEN function = maketok(OPERATOR, FUNCALLOP, fn);
        SYMBOL typesym = args->symtype->datatype;
        
        tok->operands = args;
        args->link = function;
        fn->link = makeintc(typesym->size);
        if(DEBUG){
            printf("makefuncall new\n");
            dbugprinttok(fn);
            dbugprinttok(args);
            dbugprinttok(function);
        }
        return tok;
    }
    tok->tokentype = OPERATOR;
    tok->whichval = FUNCALLOP;
    tok->operands = fn;
    fn->link = args;
    tok->basicdt = args->basicdt;
    if(DEBUG){
        printf("makefuncall\n");
        dbugprinttok(fn);
        dbugprinttok(args);
    }
    return tok;
}

TOKEN makeprogram(TOKEN name, TOKEN args, TOKEN statements)
{
    TOKEN tok, argtok;
    tok = maketok(OPERATOR, PROGRAMOP, name);
    argtok = talloc();
    argtok = makeprogn(argtok, args);
    name->link = argtok;
    argtok->link = statements;
    if(DEBUG){
        printf("makeprogram\n");
        dbugprinttok(name);
        dbugprinttok(args);
        dbugprinttok(statements);
    }
    return tok;
}

TOKEN findtype(TOKEN tok){
    SYMBOL sym;
    //SYMBOL test;
    //test = searchst("integer");
    //printsymbol(test);
    //printf("\n\n%s\n\n\n", tok->stringval);
    printst();
    sym = searchst(tok->stringval);
    tok->symtype = sym;
    if(DEBUG){
        printf("findtype\n");
        dbugprinttok(tok);
        dbugbprinttok(tok);
    }
    return tok;
}

TOKEN findid(TOKEN tok) {
    /* the ID token */
    SYMBOL sym, typ;

    sym = searchst(tok->stringval);

    if(sym->kind == CONSTSYM){
        tok->tokentype = NUMBERTOK;
        if(sym->basicdt == INTEGER){
            tok->basicdt = INTEGER;
            tok->intval = sym->constval.intnum;
        }
        if(sym->basicdt == REAL){
            tok->basicdt = REAL;
            tok->realval = sym->constval.realnum;
        }
        if(DEBUG){
            printf("find id\n");
            dbugprinttok(tok);
        }
        return tok;
    }
    tok->symentry = sym;
    typ = sym->datatype;
    tok->symtype = typ;

    if ( typ->kind == BASICTYPE || typ->kind == POINTERSYM)
        tok->basicdt = typ->basicdt;
    if(DEBUG){
        printf("findid\n");
        dbugprinttok(tok);
    }
    return tok;
}

/* install variables in symbol table */
void instvars(TOKEN idlist, TOKEN typetok)
{
    SYMBOL sym, typesym;
    int align;
    if(DEBUG){
        printf("instvars\n");
        dbugprinttok(idlist);
        dbugprinttok(typetok);
    }
    typesym = typetok->symtype;
    align = alignsize(typesym);
    while ( idlist != NULL ) /* for each id */
    {
        sym = insertsym(idlist->stringval);
        sym->kind = VARSYM;
        sym->offset = /* "next" */
            wordaddress(blockoffs[blocknumber], align);
        sym->size = typesym->size;
        blockoffs[blocknumber] = /* "next" */
            sym->offset + sym->size;
        sym->datatype = typesym;
        sym->basicdt = typesym->basicdt;
        idlist = idlist->link;
    };
}

void insttype(TOKEN typename, TOKEN typetok){
    SYMBOL sym, typesym;
    typesym = typetok->symtype;
    sym = searchins(typename->stringval);
    sym->kind = TYPESYM;
    sym->size = typesym->size;
    sym->datatype = typesym;
    sym->basicdt = typesym->basicdt;
    if(DEBUG){
        printf("inst type\n");
        printsymbol(sym);
    }
}

/*===================================================================
========================end of first part==========================
===================================================================*/

/*===================================================================
========================start of second part=========================
===================================================================*/

TOKEN unaryop(TOKEN op, TOKEN lhs){
    op->operands = lhs;
    lhs->link = NULL;
    if(DEBUG){
        printf("unaryop\n");
        dbugprinttok(op);
        dbugprinttok(lhs);
    }
    return op;
}

void instconst(TOKEN idtok, TOKEN consttok){
    SYMBOL sym = insertsym(idtok->stringval);
    sym->kind = CONSTSYM;
    sym->basicdt = consttok->basicdt;
    
    if(sym->basicdt == INTEGER){
        sym->constval.intnum = consttok->intval;
        sym->size = sizeof(int);
    }else if(sym->basicdt == REAL){
        sym->constval.realnum = consttok->realval;
        sym->size = sizeof(double);
    }    

    if (DEBUG) {
        printf("install const\n");
	dbugprinttok(idtok);
	dbugprinttok(consttok);
	printsymbol(sym);
    }
}

TOKEN makerepeat(TOKEN tok, TOKEN statements, TOKEN tokb, TOKEN expr){
    TOKEN label_tok = makelabel();
    tok = makeprogn(tok, label_tok);
    
    tokb = makeprogn(tokb, statements);
    label_tok->link = tokb;
    
    TOKEN goto_tok = makegoto(label_tok->operands->intval);
    TOKEN finish_tok = maketok(OPERATOR, PROGNOP, NULL);
    finish_tok->link = goto_tok;

    TOKEN if_tok = talloc();
    if_tok = makeif(if_tok, expr, finish_tok, goto_tok);
    
    tokb->link = if_tok;

    if (DEBUG) {
         printf("make repeat\n");
         dbugprinttok(tok);
    }
    return tok; 
}

TOKEN makefix(TOKEN tok){
    TOKEN fix_op;
    if(tok->tokentype == NUMBERTOK) {
        tok->basicdt = INTEGER;
        tok->intval = (int) tok->realval;
        if (DEBUG) {
            printf("make fix num tok\n");
            dbugprinttok(tok);
            dbugprinttok(fix_op);
        }
        return tok;
    }
    fix_op = makeop(FIXOP);
    fix_op->operands = tok;
    if (DEBUG) {
         printf("make fix\n");
         dbugprinttok(tok);
         dbugprinttok(fix_op);
    }
    return fix_op;
}

TOKEN makefloat(TOKEN tok){
    TOKEN float_op;
    if(tok->tokentype == NUMBERTOK) {
        tok->basicdt = REAL;
        tok->realval = (double) tok->intval;
        if (DEBUG) {
            printf("make float num tok\n");
            dbugprinttok(tok);
            dbugprinttok(float_op);
        }
        return tok;
    }
    float_op = makeop(FLOATOP);
    float_op->operands = tok;
    if (DEBUG) {
         printf("make float\n");
         dbugprinttok(tok);
         dbugprinttok(float_op);
    }
    return float_op;
}
/*===================================================================
========================end of second part===========================
===================================================================*/

/*===================================================================
========================start of third part==========================
===================================================================*/

void  instlabel (TOKEN num){
    label_list[labelnumber] = num->intval;
    labelnumber++;
    if (DEBUG) {
        printf("instlabel\n");
        dbugprinttok(num);
        printf("%d\n", labelnumber);
    }
}

TOKEN instfields(TOKEN idlist, TOKEN typetok){
    SYMBOL sym = typetok->symtype;
    TOKEN tok = idlist;
    while(tok != NULL){
        tok->symtype = sym;
        tok = tok->link;
    }
    if (DEBUG) {
        printf("instfields\n");
        dbugprinttok(tok);
        dbugprinttok(typetok);
        printsymbol(sym);
    }
    return idlist;
}

TOKEN nconc(TOKEN lista, TOKEN listb){
    TOKEN tok = lista;
    while(tok->link){
        tok = tok->link;
    }
    tok->link = listb;
    if (DEBUG) {
        printf("nconc\n");
        dbugprinttok(tok);
        dbugprinttok(lista);
        dbugprinttok(listb);
    }
    return tok;
}

int findlabelindex(int labelnum){
    int i;
    for(i=0; i<labelnumber; i++){
        if(label_list[i] == labelnum)
            return i;
    }
    return -1;
}

TOKEN dolabel(TOKEN labeltok, TOKEN tok, TOKEN statement){
    int label_index = findlabelindex(labeltok->intval);
    if(label_index != -1){
        TOKEN numtok = makeintc(label_index);
        labeltok = maketok(OPERATOR, LABELOP, numtok);
        labeltok->link = statement;
        TOKEN ret_tok = maketok(OPERATOR, PROGNOP, labeltok);
        if (DEBUG) {
            printf("dolabel\n");
            dbugprinttok(tok);
            dbugprinttok(labeltok);
        }
        return ret_tok;
    }
    printf("can't find label\n");
    return NULL;
}

TOKEN instenum(TOKEN idlist){
    printf("begin of instenum");
    int size = 0;
    TOKEN tok = idlist;
    while(tok != NULL){
        instconst(tok, makeintc(size));
        size++;
        tok = tok->link;
    }
    TOKEN ret_tok = makesubrange(idlist, 0, size - 1);
    if (DEBUG) {
        printf("instenum\n");
        dbugprinttok(idlist);
        dbugprinttok(ret_tok);
    }
    return ret_tok;
}

TOKEN makesubrange(TOKEN tok, int low, int high){
    SYMBOL sym = symalloc();
    sym->kind = SUBRANGE;
    sym->basicdt = INTEGER;
    sym->lowbound = low;
    sym->highbound = high;
    sym->size = sizeof(int);
    
    tok->symtype = sym;
    if (DEBUG) {
        printf("making subrange\n");
        dbugprinttok(tok);
        printsymbol(sym);
    }
    return tok;
}

TOKEN instdotdot(TOKEN lowtok, TOKEN dottok, TOKEN hightok){
    dottok = makesubrange(dottok, lowtok->intval, hightok->intval);
    if (DEBUG) {
        printf("instdotdot\n");
        dbugprinttok(dottok);
    }
    return dottok;
}

TOKEN instpoint(TOKEN tok, TOKEN typename){
    SYMBOL type_sym = searchins(typename->stringval);
    SYMBOL ptr_sym = symalloc();
    
    ptr_sym->basicdt = POINTER;
    ptr_sym->kind = POINTERSYM;
	ptr_sym->size = basicsizes[POINTER];
    ptr_sym->datatype = type_sym;
    
    tok->symtype = ptr_sym;
    if (DEBUG) {
        printf("instpoint\n");
        dbugprinttok(tok);
        printsymbol(type_sym);
        printsymbol(ptr_sym);
    }
    return tok;
}

TOKEN instarray(TOKEN bounds, TOKEN typetok){
    SYMBOL arrsym = symalloc(); 
    SYMBOL rangesym, typesym;
    TOKEN tok = bounds;
    
    while(tok != NULL){
        rangesym = tok->symtype;
        typesym = typetok->symtype;
        arrsym->kind = ARRAYSYM;
        arrsym->datatype = typesym;
        arrsym->lowbound = rangesym->lowbound;
        arrsym->highbound = rangesym->highbound;
        arrsym->size = ((arrsym->highbound)-(arrsym->lowbound)+1)*(typesym->size);
        typetok->symtype = arrsym;
        tok = tok->link;
    }
    
    if (DEBUG) {
        printf("instarray\n");
        dbugprinttok(typetok);
    }
    return typetok;
}

TOKEN instrec(TOKEN rectok, TOKEN argstok){
    printf("begin of instrec\n");
    SYMBOL sym = symalloc();
    sym->kind = RECORDSYM;
    rectok->symtype = sym;
    TOKEN args = argstok;
    TOKEN args_prev = NULL;
    int size = 0, offs = 0;
    
    while(args != NULL){
        dbugprinttok(args);
        printsymbol(args->symtype);
        size = alignsize(args->symtype);
        sym->datatype = args->symtype;
        dbugprinttok(args);
        SYMBOL newsym = makesym(args->stringval);
        dbugprinttok(args);
        newsym->datatype = args->symtype;
        newsym->offset = wordaddress(offs, size);
        dbugprinttok(args);
        newsym->size = size;
        offs = newsym->offset + size;
        
        if(args_prev){
            args_prev->symtype->link = args->symtype;
        }else{
            sym->link = newsym;
        }
        args_prev = args;
        args = args->link;
        dbugprinttok(args);
    }
    args_prev->symtype->link = NULL;
        
    sym->size = wordaddress(offs, 16);
    if (DEBUG) {
        printf("instrec\n");
        printsymbol(sym);
        dbugprinttok(rectok);
    }
    return rectok;
}

TOKEN dogoto(TOKEN tok, TOKEN labeltok){
    int label_index = findlabelindex(labeltok->intval);
    tok = makegoto(label_index);
    if(DEBUG){
        printf("dogoto");
        dbugprinttok(tok);
    }
    return tok;
}

TOKEN arrayref(TOKEN arr, TOKEN tok, TOKEN subs, TOKEN tokb) {
    int index = 0;
    int offset = 0;
    tok = maketok(OPERATOR, AREFOP, arr);
    TOKEN offs_tok = NULL;
    TOKEN trace = subs;
    SYMBOL arr_sym = arr->symtype;

    while(trace != NULL) {
        int size = arr_sym->datatype->size;

        TOKEN times_op = makeop(TIMESOP);
        TOKEN times_tok = binop(times_op, makeintc(size), trace);
        TOKEN plus_op = makeop(PLUSOP);
        TOKEN plus_tok = binop(plus_op, makeintc(-size * arr_sym->lowbound), times_tok);
        if(offs_tok) {
            TOKEN add_tok = makeop(PLUSOP);
            TOKEN add_offs = binop(add_tok, offs_tok, plus_tok);
            offs_tok = add_offs;
        } else {
            offs_tok = plus_tok;
        }
        arr_sym = arr_sym->datatype;
        trace = trace->link;
    }
    
    while(arr_sym->kind == TYPESYM)
        arr_sym = arr_sym->datatype;
    tok->operands->link = offs_tok;
    tok->symtype = arr_sym;
    return tok;
}

TOKEN dopoint(TOKEN var, TOKEN tok){
    tok->operands = var;
    if(DEBUG){
        printf("do point\n");
        dbugprinttok(tok);
    }
    return tok;
}

TOKEN makearef(TOKEN var, TOKEN off, TOKEN tok){
    tok = makeop(AREFOP);
    tok->operands = var;
    var->link = off;
    if(DEBUG){
        printf("make aref\n");
        dbugprinttok(tok);
    }
    return tok;
}

TOKEN reducedot(TOKEN var, TOKEN dot, TOKEN field){
    SYMBOL sym = var->symentry;
    SYMBOL trace = sym->datatype->datatype;
    int offs = 0;
    while(trace != NULL) {
        if (strcmp(trace->namestring, field->stringval) == 0) {
            offs = trace->offset;
            var->symentry = trace;
            break;
        }
        trace = trace->link;
    }
    dot = makearef(var, makeintc(offs), dot);
    if(DEBUG){
        printf("reduce dot\n");
        dbugprinttok(dot);
    }
}

TOKEN makewhile(TOKEN tok, TOKEN expr, TOKEN tokb, TOKEN statement){
    TOKEN label_tok = makelabel();
    TOKEN goto_tok = makegoto(label_tok->operands->intval);
    TOKEN body_tok = talloc();
    TOKEN if_tok = talloc();
    body_tok = makeprogn(body_tok, statement);
    if_tok = makeif(if_tok, expr, body_tok, NULL);
    tok = makeprogn(tok, label_tok);
    
    label_tok->link = if_tok;
    statement->link = goto_tok;
    
    if(DEBUG){
        printf("make while\n");
        dbugprinttok(tok);
    }
    return tok;
}

/*===================================================================
========================end of third part============================
===================================================================*/

int wordaddress(int n, int wordsize)
  { return ((n + wordsize - 1) / wordsize) * wordsize; }

void yyerror (char const *s)
{
  fprintf (stderr, "%s\n", s);
}

int main(void)          /*  */
  { int res;
    initsyms();
    res = yyparse();
    printstlevel(1);       /* to shorten, change to:  printstlevel(1);  */
    //printf("yyparse result = %8d\n", res);
    if (DEBUG & DB_PARSERES) dbugprinttok(parseresult);
    ppexpr(parseresult);           /* Pretty-print the result tree */
    /* uncomment following to call code generator. */
     /*
    gencode(parseresult, blockoffs[blocknumber], labelnumber);
 */
  }
