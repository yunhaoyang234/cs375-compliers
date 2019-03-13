/* lex1.c         14 Feb 01; 31 May 12; 11 Jan 18       */

/* This file contains code stubs for the lexical analyzer.
   Rename this file to be lexanc.c and fill in the stubs.    */

/* Copyright (c) 2018 Gordon S. Novak Jr. and
   The University of Texas at Austin. */

/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <limits.h>
#include "token.h"
#include "lexan.h"

char* operators[] = {"+", "-", "*", "/", ":=", "=", "<>", "<",
	"<=", ">=", ">", "^", ".", "and", "or", "not",
	"div", "mod", "in" };
	
char* delimiters[] = { ",", ";", ":", "(", ")", "[", "]", ".."};

char* reserved[] = {"array", "begin", "case", "const", "do",
	"downto", "else", "end", "file", "for", 
	"function", "goto", "if", "label", "nil", 
	"of", "packed", "procedure", "program", "record",
	"repeat", "set", "then", "to", "type", "until",
	"var", "while", "with"};

/* This file will work as given with an input file consisting only
   of integers separated by blanks:
   make lex1
   lex1
   12345 123    345  357
   */

/* Skip blanks and whitespace.  Expand this function to skip comments too. */
void skipblanks ()
{
	int c;
	while ((c = peekchar()) != EOF ){
		if (c == ' ' || c == '\n' || c == '\t') {
			getchar();
		}//skip comments 
		else if (c == '{' ||(c == '(' && peek2char() == '*')){
			getchar();
			if(c=='('){
				getchar();
			}
			while ((c = peekchar()) != EOF && (c != '}')
					&& !(c == '*' && peek2char() == ')')){
				getchar();
			}
			if(c=='*' && peek2char() == ')'){
				getchar();
			}
			getchar();
		} else {
			break;
		}
	}
}



/* Get identifiers and reserved words */
TOKEN identifier (TOKEN tok)
{
    int c, count = 0, reserve = 0;
    
    while((c= peekchar()) != EOF && count < 15 && 
			(CHARCLASS[c] == NUMERIC || CHARCLASS[c] == ALPHA)) {
        // can only be letter or number
        tok->tokenval.tokenstring[count] = c;
        getchar();
        count++;
        // if more than 15, skip
        if (count == 15) {
            while (c = peekchar() != EOF
                       && (CHARCLASS[c] == ALPHA || CHARCLASS[c] == NUMERIC)) {
                getchar();
                c = peekchar();
            }
        }
    }
    tok->tokenval.tokenstring[count] = '\0';

    //check if reserved, 29 reserved words
    for(c = 1; c <= 29; c++){
        if(!strcmp(tok->tokenval.tokenstring, reserved[c-1])){
            reserve = 1;
            tok->tokenval.which = c;
            tok->tokentype = RESERVED;
            break;
        }
    }

    if(!reserve)
        tok->tokentype = IDENTIFIERTOK;

    return tok;
}


TOKEN getstring (TOKEN tok) {
	int c, d, count = 0, done;

	//skip '
	c = peekchar();
	if (c == '\'') {
		getchar();
	}
	
	while (count<15 && (c = peekchar()) != EOF && (d = peek2char()) != EOF) {
		//case of '
		if (c == '\'' && d == '\'') {
			getchar();
			//getchar();
			tok->tokenval.tokenstring[count] = '\'';
			//count++;
		}
		//end of string
		else if (c == '\'' && d != '\'') {
			getchar();
			tok->tokentype = STRINGTOK;
			tok->tokenval.tokenstring[count] = '\0';
			return tok;
		}
		else {
			tok->tokenval.tokenstring[count] = c;
		}
		getchar();
		count++;
	}
	
	//skip chars after 15
	done = 0;
	while (!done) {
		// skip '
		c = peekchar();
		d = peek2char();
		if (c == '\'' && d == '\'') {
			getchar();
			getchar();
		}
		//end of string
		else if (c == '\'' && d != '\'') {
			getchar();
			done = 1;
		}
		else{
			getchar();
		}
	}
	
	tok->tokentype = STRINGTOK;
	tok->tokenval.tokenstring[15] = '\0';
	return tok;
}

TOKEN special (TOKEN tok)
{
    int c = peekchar(), d, i, isop = 0, length = 0;
    
    if(c != EOF && CHARCLASS[c] == SPECIAL){
        tok->tokenval.tokenstring[0] = c;
        length++;
        getchar();
    }
    // these can combined with another to form a new symbol
    if(c == '.' || c == ':' || c == '<' || c == '>'){
        d = peekchar();
        if(d!=EOF && CHARCLASS[d] == SPECIAL){
            getchar();
            tok->tokenval.tokenstring[1] = d;
            length++;
        }
    }

	tok->tokenval.tokenstring[length] = '\0';
    // check it's operator or delimiter
    for (i = 0; i<19; i++){
        if(!strcmp(tok->tokenval.tokenstring, operators[i])){
            isop = 1;
            tok->tokentype = OPERATOR;
            tok->tokenval.which = i+1;
            break;
        }
    }
        
    for(int i = 0; i<8; i++){
		//printf("%s  %s\n",tok->tokenval.tokenstring, operators[i]);
		if(!strcmp(tok->tokenval.tokenstring, delimiters[i])){
			tok->tokenval.which = i+1;
			tok->tokentype = DELIMITER;
			break;
		}
    }
    return tok;
}

/* Get and convert unsigned numbers of all types. */
TOKEN number (TOKEN tok)
{
    long num = 0;
    double decimal = 0, exponent = 0, real;
    int exp_sign = 1, c, charval = 0, isreal = 0;
    //integer part
    while ((c = peekchar()) != EOF && CHARCLASS[c] == NUMERIC){
        c = getchar();
        charval = (c - '0');
        if(num <= INT_MAX){
			num = num * 10 + charval;
		}else{
			decimal++;
		}
    }

    // deal with decimal point
    if(peekchar() == '.' && (c = peek2char()) != EOF && CHARCLASS[c] == NUMERIC){
		isreal = 1;
        getchar();
        while((c = peekchar()) != EOF && CHARCLASS[c] == NUMERIC){
			c = getchar();
            //printf("%c\n",c);
            charval = (c - '0');
            if(num <= INT_MAX){
				num = num * 10 + charval;
				decimal--;
			}
        }
    }

    // deal with exponent
    if(((c = peekchar()) == 'e' || c == 'E') && peek2char() != EOF){
		isreal = 1;
        getchar(); // skip e/E
        c = peekchar(); // get the next one, either +/- or number
        // if c is + or a number
        if(c=='+'){
            getchar(); //skip +
        } else if (c=='-'){
            getchar(); //skip -
            exp_sign = -1;
        }
        while ((c=peekchar())!= EOF && CHARCLASS[c] == NUMERIC){
            getchar();
            charval = (c - '0');
            exponent = exponent * 10 + charval;
        }
        exponent *= exp_sign;
    }
    
    // done with reading the number
    // int or real
    exponent += decimal;
    isreal = (exponent < 0) || isreal;

    //set token
    tok->tokentype = NUMBERTOK;
    if(isreal){
        tok->basicdt = REAL;
        real = num * pow(10, exponent);
        if(real>FLT_MAX || real< FLT_MIN){
            printf("Floating number out of range\n");
            tok->realval = 0;
            return tok;
        }
        tok->realval = real;
    }else{
        tok->basicdt = INTEGER;
        tok->intval = num;
        num *= pow(10, exponent);
        if(num > INT_MAX){
            printf("Integer number out of range\n");
            //printf("%d\n", num);
            while(num>INT_MAX) num /= 10;
            tok->intval = num;
            return tok;
        }
        tok->intval = num;
    }

    return (tok);
}
