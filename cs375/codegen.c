/* codgen.c       Generate Assembly Code for x86         07 May 18   */

/* Copyright (c) 2018 Gordon S. Novak Jr. and The University of Texas at Austin
    */

/* Starter file for CS 375 Code Generation assignment.           */
/* Written by Gordon S. Novak Jr.                  */

/* This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License (file gpl.text) for more details.
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA. */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "token.h"
#include "symtab.h"
#include "lexan.h"
#include "genasm.h"
#include "codegen.h"
#include "pprint.h"

void genc(TOKEN code);

/* Set DEBUGGEN to 1 for debug printouts of code generation */
#define DEBUGGEN 0

int nextlabel;    /* Next available label number */
int stkframesize;   /* total stack frame size */
int reg_table[32];
int op_reg[3][28];
int jmp_table[28];

/* Top-level entry for code generator.
   pcode    = pointer to code:  (program foo (output) (progn ...))
   varsize  = size of local storage in bytes
   maxlabel = maximum label number used so far
Add this line to the end of your main program:
    gencode(parseresult, blockoffs[blocknumber], labelnumber);
The generated code is printed out; use a text editor to extract it for
your .s file.
         */

void gencode(TOKEN pcode, int varsize, int maxlabel)
  {  TOKEN name, code;
     clearreg();
     set_op_reg();
     name = pcode->operands;
     code = name->link->link;
     nextlabel = maxlabel + 1;
     stkframesize = asmentry(name->stringval,varsize);
     genc(code);
     asmexit(name->stringval);
  }

void set_op_reg(){
    int i, j;
    for(i=0; i<3; i++)
        for(j=0; j<28; j++)
            op_reg[i][j] = -1;
        
    op_reg[INTEGER][PLUSOP] = ADDL;
    op_reg[INTEGER][MINUS] = SUBL;
    op_reg[INTEGER][TIMESOP] = IMULL;
    op_reg[INTEGER][DIVIDEOP] = DIVL;
    op_reg[INTEGER][EQOP] = CMPL;
    op_reg[INTEGER][LEOP] = CMPL;
    op_reg[INTEGER][LTOP] = CMPL;
    op_reg[INTEGER][GEOP] = CMPL;
    op_reg[INTEGER][GTOP] = CMPL;
    op_reg[INTEGER][NEOP] = CMPL;
    op_reg[INTEGER][ANDOP] = ANDL;
    op_reg[INTEGER][OROP] = ORL;
    op_reg[INTEGER][NOTOP] = NEGL;
    
    op_reg[REAL][PLUSOP] = ADDSD;
    op_reg[REAL][MINUS] = SUBSD;
    op_reg[REAL][TIMESOP] = MULSD;
    op_reg[REAL][DIVIDEOP] = DIVSD;
    op_reg[REAL][EQOP] = CMPSD;
    op_reg[REAL][LEOP] = CMPSD;
    op_reg[REAL][LTOP] = CMPSD;
    op_reg[REAL][GEOP] = CMPSD;
    op_reg[REAL][GTOP] = CMPSD;
    op_reg[REAL][NEOP] = CMPSD;
    op_reg[REAL][NOTOP] = NEGSD;
    
    op_reg[2][PLUSOP] = ADDQ;
    op_reg[2][MINUS] = SUBQ;
    op_reg[2][TIMESOP] = IMULQ;
    op_reg[2][EQOP] = CMPQ;
    op_reg[2][LEOP] = CMPQ;
    op_reg[2][LTOP] = CMPQ;
    op_reg[2][GEOP] = CMPQ;
    op_reg[2][GTOP] = CMPQ;
    op_reg[2][NEOP] = CMPQ;
    op_reg[2][ANDOP] = ANDQ;
    op_reg[2][OROP] = ORQ;
    op_reg[2][NOTOP] = NEGQ;
    
    jmp_table[EQOP] = JE;
    jmp_table[NEOP] = JNE;
    jmp_table[LTOP] = JL;
    jmp_table[LEOP] = JLE;
    jmp_table[GTOP] = JG;
    jmp_table[GEOP] = JGE;
}

void clearreg(){
    int i;
    for(i = 0; i < 32; i++){
        reg_table[i] = 0;
    }
}

/* Mark a register unused */
void unused(int reg){
    if(reg < 0 || reg > 31){
        printf("invalid reg number");
        return;
    }
    reg_table[reg] = 0;
}

/* Mark a register used */
void used(int reg){
    if(reg < 0 || reg > 31){
        printf("invalid reg number");
        return;
    }
    reg_table[reg] = 1;
}

/* Trivial version: always returns RBASE + 0 */
/* Get a register.   */
/* Need a type parameter or two versions for INTEGER or REAL */
int getreg(int kind)
  {
    int i;
    if(kind == INTEGER || kind == BOOLETYPE) {
      for(i = RBASE; i <= RMAX; i++) {
        if(reg_table[i] == 0) {
          used(i);
          return i;
        }
      }
    } else if(kind == REAL || kind == STRINGTYPE || kind == POINTER) {
      for(i = FBASE; i <= FMAX; i++) {
        if(reg_table[i] == 0) {
          used(i);
          return i;
        }
      }
    }
    printf("no free register\n");
    return -1;
  }

int genaref(TOKEN code, int storereg){
    int reg, reg2;
    TOKEN base = code->operands;
    TOKEN ofs_tok = base->link;
    int offs;
    //printf("11111111111111111111\n");
    //dbugprinttok(base);
    //dbugprinttok(ofs_tok);

    if(storereg < 0){
        //printf("000000000000000000\n");
        //dbugprinttok(base);
        reg2 = genarith(base);
        offs = ofs_tok->intval;

        switch (code->basicdt) {
          case INTEGER:
            reg = getreg(0);
            asmldr(MOVL, offs, reg2, reg, "^.");
            break;
          case REAL:
            reg = getreg(REAL);
            asmldr(MOVSD, offs, reg2, reg, "^.");
            break;
          case POINTER:
            reg = getreg(0);
            asmldr(MOVQ, offs, reg2, reg, "^.");
            break;
        };
        unused(reg2);
        //printf("00000000000000000111\n");
    }else if(base->tokentype == IDENTIFIERTOK){
        reg2 = genarith(ofs_tok);
        offs = base->symentry->offset - stkframesize;
        switch (code->basicdt) {
          case INTEGER:
            asmop(CLTQ);
            asmstrr(MOVL, storereg, offs, reg2, base->stringval);
            break;
          case REAL:
            asmop(CLTQ);
            asmstrr(MOVSD, storereg, offs, reg2, base->stringval);
            break;
          case POINTER:
            asmop(CLTQ);
            asmstrr(MOVQ, storereg, offs, reg2, base->stringval);
            break;
        };
        unused(reg2);
        return storereg;
    }else if(ofs_tok->tokentype == NUMBERTOK){
        //printf("bbbbbbbbbbbbbbbbbbbbbbb   %d\n", ofs_tok->intval);
        //dbugprinttok(code);
        reg2 = genarith(base);
        switch (code->basicdt) {
          case INTEGER:
            asmstr(MOVL, storereg, ofs_tok->intval, reg2, "^. ");
            break;
          case REAL:
            asmstr(MOVSD, storereg, ofs_tok->intval, reg2, "^. ");
            break;
          case POINTER:
            asmstr(MOVQ, storereg, ofs_tok->intval, reg2, "^. ");
            break;
        };
        unused(reg2);
        return storereg;
    }
//printf("eeeeeeeeeeeeeeeeeeeeeeeeeeee\n");
    return reg;
}

int genfun(TOKEN code){
    TOKEN functok = code->operands;
    TOKEN args = functok->link;
    int reg;
    if(args != NULL){
        reg = genarith(args);
    }
    //printf("%d  %s  \n", reg, functok->stringval);
    //dbugprinttok(args);
    SYMBOL sym = searchst(functok->stringval);
    //printsymbol(sym);
    //printf("%d  \n", sym->datatype->basicdt);
    
    switch(args->basicdt){
        case INTEGER:
            if(reg != EDI) asmrr(MOVL, reg, EDI);
            break;
        case REAL:
            if(reg != XMM0) asmrr(MOVSD, reg, XMM0);
            break;
        case STRINGTYPE:
            if(reg != EDI) asmrr(MOVL, reg, EDI);
            break;
    }

    switch(sym->datatype->basicdt){
        case INTEGER:
            asmcall(functok->stringval);
            unused(reg);
            return EAX;
        case REAL:
            if(reg != XMM0) {
                asmrr(MOVSD,reg,XMM0);
                unused(reg);
                asmcall(functok->stringval);
                used(XMM0);
            } else {
                asmcall(functok->stringval);
                used(XMM0);
            }
            return XMM0;    
    }
    unused(reg);
    asmcall(functok->stringval);
    return RAX;
}

int funcallin(TOKEN code){
    if(code->tokentype == OPERATOR && code->whichval == FUNCALLOP){
        return 1;
    }
    if(code->link != NULL && funcallin(code->link))
        return 1;
    if(code->operands != NULL && funcallin(code->operands))
        return 1;
    return 0;
}

/* Trivial version */
/* Generate code for arithmetic expression, return a register number */
int genarith(TOKEN code){
    int num, reg, reg2, ofs = -1;
    TOKEN lhs, rhs;
    SYMBOL idsym;
    double d;
    if(DEBUGGEN){
        printf("genarith\n");
	    dbugprinttok(code);
    }
    switch ( code->tokentype ){ 
        case NUMBERTOK:
        
            switch (code->basicdt){
                case INTEGER:
                    num = code->intval;
                    reg = getreg(INTEGER);
                    if ( num >= MINIMMEDIATE && num <= MAXIMMEDIATE )
                        asmimmed(MOVL, num, reg);
                    break;
                case REAL:
                    d = code->realval;
                    reg = getreg(REAL);
                    makeflit(d, nextlabel);
                    asmldflit(MOVSD, nextlabel, reg);
                    nextlabel++;
                    break;
                case POINTER:
                    num = code->intval;
                    reg = getreg(INTEGER);
                    asmimmed(MOVQ, num, reg);
                    break;
            }
            break;
            
        case STRINGTOK:
            used(EDI);
            asmlitarg(nextlabel, EDI);
            makeblit(code->stringval, nextlabel);
            nextlabel++;
            break;
            
        case IDENTIFIERTOK:
            idsym = searchst(code->stringval);
            ofs = idsym->offset - stkframesize;
            
            switch (code->basicdt) { 
                case INTEGER:
                    reg = getreg(0);
                    asmld(MOVL, ofs, reg, idsym->namestring);
                    break;
                case REAL:
                    reg = getreg(REAL);
                    asmld(MOVSD, ofs, reg, idsym->namestring);
                    break;
                case POINTER:
                    reg = getreg(0);
                    asmld(MOVQ, ofs, reg, idsym->namestring);
                    break;
            }
            break;
            
        case OPERATOR:
            lhs = code->operands;
            rhs = lhs->link;
            if(code->whichval == FUNCALLOP){
                reg = genfun(code);
            }
            else if(code->whichval == FLOATOP){
                reg2 = genarith(lhs);
                reg = getreg(REAL);
                asmfloat(reg2, reg);
                unused(reg2);
            }
            else if(code->whichval == FIXOP){
                reg2 = genarith(lhs);
                reg = getreg(INTEGER);
                asmfix(reg2, reg);
                unused(reg2);
            }
            else if(code->whichval == AREFOP){
                reg = genaref(code, -1);
            }
            else if(code->whichval == POINTEROP){
                //printf("pointerop\n");
                //dbugprinttok(lhs);
                reg = genarith(lhs);
            }
            else if(code->basicdt == INTEGER || code->basicdt == REAL || 
                    code->basicdt == POINTER){
                int dt = code->basicdt;
                if(dt==POINTER) dt = 2;
                int op = code->whichval;
                reg = genarith(lhs);
                if(rhs == NULL){
                    reg2 = getreg(dt);
                    asmfneg(reg, reg2);
                    reg = reg2;
                    unused(reg2);
                }else if(funcallin(rhs)){
                    asmsttemp(reg);
                    unused(reg);
                    reg2 = genarith(rhs);
                    used(reg);
                    asmldtemp(reg);
                    asmrr(op_reg[dt][op], reg2, reg);
                    unused(reg2);
                }else{
                    reg2 = genarith(rhs);
                    asmrr(op_reg[dt][op], reg2, reg);
                    unused(reg2);
                }
            }
     };

    return reg;
}

/* Generate code for a Statement from an intermediate-code form */
void genc(TOKEN code)
  {  TOKEN tok, lhs, rhs;
     int reg, offs;
     SYMBOL sym;
     if (DEBUGGEN)
       { printf("genc\n");
	 dbugprinttok(code);
       };
     if ( code->tokentype != OPERATOR )
        { printf("Bad code token");
	  dbugprinttok(code);
	};
     switch ( code->whichval )
       { case PROGNOP:
	   tok = code->operands;
	   while ( tok != NULL )
	     {  genc(tok);
		tok = tok->link;
	      };
	   break;
	 case ASSIGNOP:                   /* Trivial version: handles I := e */
	   lhs = code->operands;
	   rhs = lhs->link;
       //dbugprinttok(lhs);
       //dbugbprinttok(lhs);
	   reg = genarith(rhs);              /* generate rhs into a register */
	   
        if(lhs->tokentype == OPERATOR && lhs->whichval == AREFOP){
            //printf("assign aref  %d   %d\n", reg, reg_table[reg]);
            genaref(lhs, reg);
            unused(reg);
        }else{
            //printf("assign   %d\n", lhs->basicdt);
            sym = lhs->symentry;              /* assumes lhs is a simple var  */
	        offs = sym->offset - stkframesize; /* net offset of the var   */
           switch (lhs->basicdt)            /* store value into lhs  */
             { case INTEGER:
                 asmst(MOVL, reg, offs, lhs->stringval);
                 break;
              case REAL:
                 asmst(MOVSD, reg, offs, lhs->stringval);
                 break;
              case POINTER:
                 asmst(MOVQ, reg, offs, lhs->stringval);
                 break;
             };
             unused(reg);
        }
           break;
	 case FUNCALLOP:
       genfun(code);
	   break;
	 case GOTOOP:
       asmjump(JMP, code->operands->intval);
	   break;
	 case LABELOP:
       asmlabel(code->operands->intval);
	   break;
	 case IFOP:
        tok = code->operands;
        lhs = tok->operands;
        rhs = lhs->link;
        TOKEN thenpart = tok->link;
        TOKEN elsepart = thenpart->link;
        int dt = lhs->basicdt;
        int reg2;

        if(dt == POINTER)
            dt = 2;
        //printf("\n\nifop   %d\n", tok->whichval);
        //dbugprinttok(tok->link);
        //dbugprinttok(lhs);
        //dbugprinttok(rhs);

        reg = genarith(lhs);
        reg2 = genarith(rhs);
        asmrr(op_reg[dt][tok->whichval], reg2, reg);
        unused(reg);
        unused(reg2);

        int label1, label2;
        label1 = nextlabel++;
        asmjump(jmp_table[tok->whichval], label1);

        if(elsepart!=NULL){
            genc(elsepart);
        }

        label2 = nextlabel++;
        asmjump(JMP, label2);
        asmlabel(label1);
        //dbugprinttok(lhs);
        genc(thenpart);
        asmlabel(label2);
	   break;
	 };
  }