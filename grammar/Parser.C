/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "spatialc.y" /* yacc.c:339  */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include "Absyn.H"
typedef struct yy_buffer_state *YY_BUFFER_STATE;
int yyparse(void);
int yylex(void);
YY_BUFFER_STATE yy_scan_string(const char *str);
void yy_delete_buffer(YY_BUFFER_STATE buf);
int yy_mylinenumber;
int initialize_lexer(FILE * inp);
int yywrap(void)
{
  return 1;
}
void yyerror(const char *str)
{
  extern char *yytext;
  fprintf(stderr,"error: line %d: %s at %s\n", 
    yy_mylinenumber, str, yytext);
}



static Package* YY_RESULT_Package_ = 0;
Package* pPackage(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Package_;
  }
}
Package* pPackage(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Package_;
  }
}

static Def* YY_RESULT_Def_ = 0;
Def* pDef(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Def_;
  }
}
Def* pDef(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Def_;
  }
}

static ListDef* YY_RESULT_ListDef_ = 0;
ListDef* pListDef(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListDef_;
  }
}
ListDef* pListDef(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListDef_;
  }
}

static MetaParamDecl* YY_RESULT_MetaParamDecl_ = 0;
MetaParamDecl* pMetaParamDecl(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_MetaParamDecl_;
  }
}
MetaParamDecl* pMetaParamDecl(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_MetaParamDecl_;
  }
}

static OptionalEqExp* YY_RESULT_OptionalEqExp_ = 0;
OptionalEqExp* pOptionalEqExp(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_OptionalEqExp_;
  }
}
OptionalEqExp* pOptionalEqExp(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_OptionalEqExp_;
  }
}

static MetaParam* YY_RESULT_MetaParam_ = 0;
MetaParam* pMetaParam(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_MetaParam_;
  }
}
MetaParam* pMetaParam(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_MetaParam_;
  }
}

static ListMetaParam* YY_RESULT_ListMetaParam_ = 0;
ListMetaParam* pListMetaParam(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListMetaParam_;
  }
}
ListMetaParam* pListMetaParam(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListMetaParam_;
  }
}

static ModDef* YY_RESULT_ModDef_ = 0;
ModDef* pModDef(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ModDef_;
  }
}
ModDef* pModDef(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ModDef_;
  }
}

static ListModDef* YY_RESULT_ListModDef_ = 0;
ListModDef* pListModDef(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListModDef_;
  }
}
ListModDef* pListModDef(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListModDef_;
  }
}

static ChannelSpecifier* YY_RESULT_ChannelSpecifier_ = 0;
ChannelSpecifier* pChannelSpecifier(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ChannelSpecifier_;
  }
}
ChannelSpecifier* pChannelSpecifier(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ChannelSpecifier_;
  }
}

static EventName* YY_RESULT_EventName_ = 0;
EventName* pEventName(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_EventName_;
  }
}
EventName* pEventName(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_EventName_;
  }
}

static EventParam* YY_RESULT_EventParam_ = 0;
EventParam* pEventParam(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_EventParam_;
  }
}
EventParam* pEventParam(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_EventParam_;
  }
}

static ListEventParam* YY_RESULT_ListEventParam_ = 0;
ListEventParam* pListEventParam(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListEventParam_;
  }
}
ListEventParam* pListEventParam(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListEventParam_;
  }
}

static EventOrCond* YY_RESULT_EventOrCond_ = 0;
EventOrCond* pEventOrCond(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_EventOrCond_;
  }
}
EventOrCond* pEventOrCond(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_EventOrCond_;
  }
}

static EventOrList* YY_RESULT_EventOrList_ = 0;
EventOrList* pEventOrList(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_EventOrList_;
  }
}
EventOrList* pEventOrList(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_EventOrList_;
  }
}

static ListEventOrList* YY_RESULT_ListEventOrList_ = 0;
ListEventOrList* pListEventOrList(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListEventOrList_;
  }
}
ListEventOrList* pListEventOrList(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListEventOrList_;
  }
}

static StructDef* YY_RESULT_StructDef_ = 0;
StructDef* pStructDef(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_StructDef_;
  }
}
StructDef* pStructDef(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_StructDef_;
  }
}

static ListStructDef* YY_RESULT_ListStructDef_ = 0;
ListStructDef* pListStructDef(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListStructDef_;
  }
}
ListStructDef* pListStructDef(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListStructDef_;
  }
}

static FuncParam* YY_RESULT_FuncParam_ = 0;
FuncParam* pFuncParam(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_FuncParam_;
  }
}
FuncParam* pFuncParam(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_FuncParam_;
  }
}

static ListFuncParam* YY_RESULT_ListFuncParam_ = 0;
ListFuncParam* pListFuncParam(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListFuncParam_;
  }
}
ListFuncParam* pListFuncParam(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListFuncParam_;
  }
}

static OptionalType* YY_RESULT_OptionalType_ = 0;
OptionalType* pOptionalType(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_OptionalType_;
  }
}
OptionalType* pOptionalType(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_OptionalType_;
  }
}

static Statement* YY_RESULT_Statement_ = 0;
Statement* pStatement(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Statement_;
  }
}
Statement* pStatement(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Statement_;
  }
}

static ListStatement* YY_RESULT_ListStatement_ = 0;
ListStatement* pListStatement(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListStatement_;
  }
}
ListStatement* pListStatement(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListStatement_;
  }
}

static PushSubDest* YY_RESULT_PushSubDest_ = 0;
PushSubDest* pPushSubDest(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_PushSubDest_;
  }
}
PushSubDest* pPushSubDest(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_PushSubDest_;
  }
}

static VarAssignment* YY_RESULT_VarAssignment_ = 0;
VarAssignment* pVarAssignment(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_VarAssignment_;
  }
}
VarAssignment* pVarAssignment(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_VarAssignment_;
  }
}

static Block* YY_RESULT_Block_ = 0;
Block* pBlock(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Block_;
  }
}
Block* pBlock(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Block_;
  }
}

static BlockAttr* YY_RESULT_BlockAttr_ = 0;
BlockAttr* pBlockAttr(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_BlockAttr_;
  }
}
BlockAttr* pBlockAttr(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_BlockAttr_;
  }
}

static ListBlockAttr* YY_RESULT_ListBlockAttr_ = 0;
ListBlockAttr* pListBlockAttr(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListBlockAttr_;
  }
}
ListBlockAttr* pListBlockAttr(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListBlockAttr_;
  }
}

static ElseBlock* YY_RESULT_ElseBlock_ = 0;
ElseBlock* pElseBlock(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ElseBlock_;
  }
}
ElseBlock* pElseBlock(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ElseBlock_;
  }
}

static Exp* YY_RESULT_Exp_ = 0;
Exp* pExp(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}
Exp* pExp(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}

static ListExp* YY_RESULT_ListExp_ = 0;
ListExp* pListExp(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListExp_;
  }
}
ListExp* pListExp(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListExp_;
  }
}

static PackageName* YY_RESULT_PackageName_ = 0;
PackageName* pPackageName(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_PackageName_;
  }
}
PackageName* pPackageName(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_PackageName_;
  }
}

static ListPackageName* YY_RESULT_ListPackageName_ = 0;
ListPackageName* pListPackageName(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListPackageName_;
  }
}
ListPackageName* pListPackageName(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListPackageName_;
  }
}

static StructLiteralField* YY_RESULT_StructLiteralField_ = 0;
StructLiteralField* pStructLiteralField(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_StructLiteralField_;
  }
}
StructLiteralField* pStructLiteralField(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_StructLiteralField_;
  }
}

static ListStructLiteralField* YY_RESULT_ListStructLiteralField_ = 0;
ListStructLiteralField* pListStructLiteralField(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListStructLiteralField_;
  }
}
ListStructLiteralField* pListStructLiteralField(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListStructLiteralField_;
  }
}

static IntOrName* YY_RESULT_IntOrName_ = 0;
IntOrName* pIntOrName(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_IntOrName_;
  }
}
IntOrName* pIntOrName(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_IntOrName_;
  }
}

static Type* YY_RESULT_Type_ = 0;
Type* pType(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Type_;
  }
}
Type* pType(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Type_;
  }
}

static TemplateExp* YY_RESULT_TemplateExp_ = 0;
TemplateExp* pTemplateExp(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_TemplateExp_;
  }
}
TemplateExp* pTemplateExp(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_TemplateExp_;
  }
}

static TemplateArg* YY_RESULT_TemplateArg_ = 0;
TemplateArg* pTemplateArg(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_TemplateArg_;
  }
}
TemplateArg* pTemplateArg(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_TemplateArg_;
  }
}

static ListTemplateArg* YY_RESULT_ListTemplateArg_ = 0;
ListTemplateArg* pListTemplateArg(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListTemplateArg_;
  }
}
ListTemplateArg* pListTemplateArg(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListTemplateArg_;
  }
}




#line 1417 "Parser.C" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    _ERROR_ = 258,
    _SYMB_0 = 259,
    _SYMB_1 = 260,
    _SYMB_2 = 261,
    _SYMB_3 = 262,
    _SYMB_4 = 263,
    _SYMB_5 = 264,
    _SYMB_6 = 265,
    _SYMB_7 = 266,
    _SYMB_8 = 267,
    _SYMB_9 = 268,
    _SYMB_10 = 269,
    _SYMB_11 = 270,
    _SYMB_12 = 271,
    _SYMB_13 = 272,
    _SYMB_14 = 273,
    _SYMB_15 = 274,
    _SYMB_16 = 275,
    _SYMB_17 = 276,
    _SYMB_18 = 277,
    _SYMB_19 = 278,
    _SYMB_20 = 279,
    _SYMB_21 = 280,
    _SYMB_22 = 281,
    _SYMB_23 = 282,
    _SYMB_24 = 283,
    _SYMB_25 = 284,
    _SYMB_26 = 285,
    _SYMB_27 = 286,
    _SYMB_28 = 287,
    _SYMB_29 = 288,
    _SYMB_30 = 289,
    _SYMB_31 = 290,
    _SYMB_32 = 291,
    _SYMB_33 = 292,
    _SYMB_34 = 293,
    _SYMB_35 = 294,
    _SYMB_36 = 295,
    _SYMB_37 = 296,
    _SYMB_38 = 297,
    _SYMB_39 = 298,
    _SYMB_40 = 299,
    _SYMB_41 = 300,
    _SYMB_42 = 301,
    _SYMB_43 = 302,
    _SYMB_44 = 303,
    _SYMB_45 = 304,
    _SYMB_46 = 305,
    _SYMB_47 = 306,
    _SYMB_48 = 307,
    _SYMB_49 = 308,
    _SYMB_50 = 309,
    _SYMB_51 = 310,
    _SYMB_52 = 311,
    _SYMB_53 = 312,
    _SYMB_54 = 313,
    _SYMB_55 = 314,
    _SYMB_56 = 315,
    _SYMB_57 = 316,
    _SYMB_58 = 317,
    _SYMB_59 = 318,
    _SYMB_60 = 319,
    _SYMB_61 = 320,
    _SYMB_62 = 321,
    _SYMB_63 = 322,
    _SYMB_64 = 323,
    _SYMB_65 = 324,
    _STRING_ = 325,
    _INTEGER_ = 326,
    _DOUBLE_ = 327
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 1354 "spatialc.y" /* yacc.c:355  */

  int int_;
  char char_;
  double double_;
  char* string_;
  Package* package_;
  Def* def_;
  ListDef* listdef_;
  MetaParamDecl* metaparamdecl_;
  OptionalEqExp* optionaleqexp_;
  MetaParam* metaparam_;
  ListMetaParam* listmetaparam_;
  ModDef* moddef_;
  ListModDef* listmoddef_;
  ChannelSpecifier* channelspecifier_;
  EventName* eventname_;
  EventParam* eventparam_;
  ListEventParam* listeventparam_;
  EventOrCond* eventorcond_;
  EventOrList* eventorlist_;
  ListEventOrList* listeventorlist_;
  StructDef* structdef_;
  ListStructDef* liststructdef_;
  FuncParam* funcparam_;
  ListFuncParam* listfuncparam_;
  OptionalType* optionaltype_;
  Statement* statement_;
  ListStatement* liststatement_;
  PushSubDest* pushsubdest_;
  VarAssignment* varassignment_;
  Block* block_;
  BlockAttr* blockattr_;
  ListBlockAttr* listblockattr_;
  ElseBlock* elseblock_;
  Exp* exp_;
  ListExp* listexp_;
  PackageName* packagename_;
  ListPackageName* listpackagename_;
  StructLiteralField* structliteralfield_;
  ListStructLiteralField* liststructliteralfield_;
  IntOrName* intorname_;
  Type* type_;
  TemplateExp* templateexp_;
  TemplateArg* templatearg_;
  ListTemplateArg* listtemplatearg_;

#line 1574 "Parser.C" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 1591 "Parser.C" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   354

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  156
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  326

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   327

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1531,  1531,  1533,  1534,  1535,  1536,  1538,  1539,  1541,
    1542,  1544,  1545,  1547,  1549,  1550,  1551,  1553,  1554,  1555,
    1556,  1557,  1558,  1559,  1560,  1561,  1562,  1563,  1564,  1566,
    1567,  1569,  1570,  1571,  1573,  1574,  1576,  1577,  1579,  1580,
    1581,  1583,  1584,  1586,  1588,  1589,  1590,  1592,  1593,  1595,
    1596,  1598,  1600,  1601,  1602,  1604,  1605,  1607,  1608,  1609,
    1610,  1611,  1612,  1613,  1614,  1615,  1616,  1618,  1619,  1621,
    1622,  1623,  1624,  1626,  1627,  1629,  1631,  1632,  1634,  1635,
    1637,  1638,  1639,  1641,  1642,  1643,  1644,  1645,  1646,  1647,
    1648,  1649,  1650,  1651,  1652,  1653,  1654,  1656,  1657,  1659,
    1660,  1661,  1662,  1663,  1664,  1665,  1666,  1668,  1669,  1670,
    1672,  1673,  1674,  1676,  1677,  1678,  1679,  1680,  1682,  1683,
    1684,  1686,  1687,  1689,  1690,  1692,  1694,  1696,  1698,  1700,
    1702,  1704,  1706,  1707,  1708,  1710,  1712,  1713,  1714,  1716,
    1718,  1719,  1720,  1722,  1723,  1725,  1726,  1727,  1728,  1729,
    1730,  1732,  1733,  1735,  1737,  1738,  1739
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_ERROR_", "_SYMB_0", "_SYMB_1",
  "_SYMB_2", "_SYMB_3", "_SYMB_4", "_SYMB_5", "_SYMB_6", "_SYMB_7",
  "_SYMB_8", "_SYMB_9", "_SYMB_10", "_SYMB_11", "_SYMB_12", "_SYMB_13",
  "_SYMB_14", "_SYMB_15", "_SYMB_16", "_SYMB_17", "_SYMB_18", "_SYMB_19",
  "_SYMB_20", "_SYMB_21", "_SYMB_22", "_SYMB_23", "_SYMB_24", "_SYMB_25",
  "_SYMB_26", "_SYMB_27", "_SYMB_28", "_SYMB_29", "_SYMB_30", "_SYMB_31",
  "_SYMB_32", "_SYMB_33", "_SYMB_34", "_SYMB_35", "_SYMB_36", "_SYMB_37",
  "_SYMB_38", "_SYMB_39", "_SYMB_40", "_SYMB_41", "_SYMB_42", "_SYMB_43",
  "_SYMB_44", "_SYMB_45", "_SYMB_46", "_SYMB_47", "_SYMB_48", "_SYMB_49",
  "_SYMB_50", "_SYMB_51", "_SYMB_52", "_SYMB_53", "_SYMB_54", "_SYMB_55",
  "_SYMB_56", "_SYMB_57", "_SYMB_58", "_SYMB_59", "_SYMB_60", "_SYMB_61",
  "_SYMB_62", "_SYMB_63", "_SYMB_64", "_SYMB_65", "_STRING_", "_INTEGER_",
  "_DOUBLE_", "$accept", "Package", "Def", "ListDef", "MetaParamDecl",
  "OptionalEqExp", "MetaParam", "ListMetaParam", "ModDef", "ListModDef",
  "ChannelSpecifier", "EventName", "EventParam", "ListEventParam",
  "EventOrCond", "EventOrList", "ListEventOrList", "StructDef",
  "ListStructDef", "FuncParam", "ListFuncParam", "OptionalType",
  "Statement", "ListStatement", "PushSubDest", "VarAssignment", "Block",
  "BlockAttr", "ListBlockAttr", "ElseBlock", "Exp15", "Exp14", "Exp13",
  "Exp12", "Exp11", "Exp9", "Exp8", "Exp4", "Exp3", "Exp", "Exp1", "Exp2",
  "Exp5", "Exp6", "Exp7", "Exp10", "ListExp", "PackageName",
  "ListPackageName", "StructLiteralField", "ListStructLiteralField",
  "IntOrName", "Type", "TemplateExp", "TemplateArg", "ListTemplateArg", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327
};
# endif

#define YYPACT_NINF -229

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-229)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -229,    44,    77,  -229,   -12,     7,   -12,    24,  -229,  -229,
      80,    64,    94,   107,    94,   -12,  -229,   104,   113,  -229,
     119,  -229,  -229,  -229,    91,   122,   131,    -9,  -229,  -229,
     130,   104,  -229,   -20,   -20,   132,   204,     1,    75,  -229,
    -229,  -229,   143,   115,    34,  -229,  -229,    96,   104,   154,
     154,   104,   104,   104,   104,   104,   104,   138,   178,  -229,
    -229,  -229,    -5,   184,   196,   192,  -229,  -229,   104,    34,
      34,    45,  -229,  -229,  -229,  -229,  -229,  -229,  -229,  -229,
     105,  -229,   129,    29,   128,   150,   156,   185,   177,  -229,
    -229,  -229,  -229,  -229,  -229,  -229,   190,   210,     9,   158,
     221,  -229,    15,    27,    30,    58,    59,    78,   163,    34,
     194,    16,    75,  -229,    23,   225,   226,   218,   105,   167,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
     169,    34,    96,   132,   222,     4,  -229,     3,   234,   236,
     237,   238,   239,   243,   240,   250,  -229,   104,   104,  -229,
    -229,  -229,   200,  -229,    34,  -229,  -229,   186,  -229,  -229,
    -229,  -229,  -229,  -229,  -229,   129,   129,    29,    29,  -229,
    -229,  -229,  -229,   150,   150,  -229,   185,  -229,   246,   266,
     267,  -229,    96,  -229,   268,   272,   271,  -229,  -229,  -229,
    -229,  -229,  -229,  -229,  -229,  -229,  -229,    34,   280,   278,
     281,    97,    -2,   279,   282,   287,  -229,    34,  -229,   285,
    -229,  -229,  -229,   284,   293,     4,  -229,   -15,    76,   294,
    -229,   104,   301,  -229,    34,   200,  -229,   292,   241,    96,
    -229,  -229,  -229,  -229,  -229,  -229,   303,    34,   304,   305,
     302,    34,    19,  -229,  -229,    34,   224,  -229,  -229,  -229,
    -229,  -229,  -229,  -229,    34,   309,   247,    34,   104,   248,
     313,    34,   251,    34,   298,   312,  -229,   102,   314,  -229,
     311,   316,    -2,   317,  -229,   321,  -229,   315,    34,   322,
    -229,  -229,    34,  -229,    34,  -229,  -229,     0,   324,  -229,
     165,   308,  -229,   325,    34,   262,  -229,   245,   326,  -229,
    -229,    34,  -229,   328,  -229,  -229,    34,  -229,   327,  -229,
     329,  -229,  -229,  -229,   165,  -229
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     2,     1,   136,     0,   136,     0,     8,   135,
     137,     0,     9,     0,     9,   136,     3,    14,     0,     4,
       0,   138,   147,   146,   145,    15,     0,     0,    29,    49,
       0,    14,    10,     0,     0,    12,     0,     0,   154,    16,
     143,   144,     0,     0,     0,    13,     5,     0,     0,    34,
      34,     0,     0,     0,     0,     0,     0,     0,     0,    30,
       6,    50,     0,     0,   155,     0,   149,   150,     0,     0,
     132,     0,    85,    84,    83,    92,    87,    89,    86,    88,
      98,   106,   109,   112,   131,   120,   130,   124,   127,    11,
     125,   126,   122,   128,   129,   117,    31,     0,     0,     0,
       0,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   154,   148,     0,     0,   133,     0,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    12,     0,    38,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    47,    52,     0,   152,
     153,   156,   140,    96,   132,    91,    95,     0,   100,    99,
     101,   102,   103,   104,   105,   107,   108,   110,   111,   113,
     114,   115,   116,   118,   119,   121,   123,    32,     0,     0,
       0,    35,    44,    41,    39,     0,     0,    67,    76,    77,
      79,    21,    23,    19,    20,    22,    18,     0,     0,    53,
       0,     0,   151,     0,   141,     0,   134,     0,    93,     0,
      26,    17,    43,    45,     0,    38,    78,     0,    78,     0,
      29,    52,     0,    51,     0,   140,    90,     0,     0,    44,
      42,    40,    24,    37,    36,    75,     0,     0,     0,     0,
      55,     0,    72,    68,    61,     0,     0,    54,    67,   139,
     142,    94,    33,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,    78,     0,    65,
       0,     0,    56,    74,    66,     0,    69,     0,     0,     0,
      48,    78,     0,    78,     0,    57,    58,    70,     0,    29,
      82,     0,    64,     0,     0,     0,    62,     0,     0,    78,
      60,     0,    73,     0,    71,    27,     0,    81,     0,    59,
       0,    78,    78,    63,    82,    80
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -229,  -229,  -229,  -229,   320,   193,  -229,   307,  -229,  -228,
     -42,   289,  -229,   116,  -229,  -229,   101,  -229,  -229,  -229,
     111,  -229,  -229,    87,  -229,  -229,   -97,  -229,  -229,    20,
     275,    53,    85,    86,  -229,    82,  -229,   208,  -229,   -44,
    -229,  -229,   205,  -229,  -229,    54,   187,  -229,    21,  -229,
     114,   318,   -36,  -229,  -229,   242
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     8,     2,    18,    45,    25,    26,    59,    36,
     193,   100,   194,   195,   196,   223,   224,    61,    37,   209,
     210,   269,   253,   228,   274,   295,   254,   200,   147,   310,
      80,    81,    82,    83,    84,    85,    86,    87,    88,   116,
      90,    91,    92,    93,    94,    95,   117,    10,    11,   214,
     215,    42,    27,   160,    64,    65
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      89,    62,   256,   243,   146,    97,    33,    60,   197,   304,
      33,   192,    98,    33,   305,   102,   103,   104,   105,   106,
     107,    68,    34,    69,    33,   115,    34,    13,   271,    34,
      33,    70,   114,   272,   273,   162,    21,    71,    33,    68,
      34,    69,    33,   198,     3,    33,    34,   128,    40,    70,
      68,    41,    69,   244,    34,    71,     9,   129,    34,    35,
      70,    34,    72,   110,    22,   155,    23,   159,    16,    24,
     199,   307,    96,    33,    33,    12,   167,   143,    73,   158,
      72,    74,   245,   148,    75,    76,    77,    78,    79,    34,
      34,    72,    14,    33,    15,   149,    73,   188,   150,    74,
     189,    17,    75,    76,    77,    78,    79,    73,   290,    34,
      74,    19,    33,    75,    76,    77,    78,    79,    28,   119,
     120,   211,   212,   246,    29,     4,   151,   152,    34,   242,
      30,     5,    31,     6,   247,   248,   249,    38,     7,    32,
     250,    44,   251,    63,   252,   108,   153,    67,   121,   246,
     222,   122,   123,   124,   125,   126,   127,   130,   131,    66,
     247,   248,   249,   229,    96,   233,   250,    22,   251,    23,
     252,    99,    24,   237,   168,   169,   170,   171,   172,   173,
     174,   132,   133,   134,   135,   109,   179,   180,   181,   182,
     259,   136,   137,   111,   300,   211,   302,   222,   156,   217,
     113,   157,   218,   265,   140,   141,   112,   270,   308,   309,
      46,   275,   317,   175,   176,   139,   177,   178,   183,   184,
     278,   142,   138,   281,   323,   324,   144,   285,   145,   287,
     276,   154,   282,   163,   165,   166,   164,   187,   201,   191,
     202,   203,   204,   205,   298,    47,    48,   206,   301,    49,
     303,   315,   207,    50,    51,    52,    53,    54,   208,    55,
     313,    56,   219,    57,    58,    47,    48,   318,   213,    49,
     220,   221,   320,    50,    51,    52,    53,    54,   225,    55,
     226,    56,   227,    57,    58,   230,    47,    48,   231,   232,
      49,   234,   235,   236,    50,    51,    52,    53,    54,   238,
      55,   240,    56,   239,    57,    58,   258,   255,   261,   262,
     264,   266,   267,   279,   268,   280,   283,   284,   288,   286,
     289,   311,   291,   292,   293,   296,   294,   299,   306,   312,
     314,   297,   319,   316,    20,   321,   190,   322,    39,   101,
     263,   241,   257,   185,   325,   277,   118,   186,     0,   260,
       0,   216,    43,     0,   161
};

static const yytype_int16 yycheck[] =
{
      44,    37,   230,    18,   101,    47,    15,     6,     5,     9,
      15,     7,    48,    15,    14,    51,    52,    53,    54,    55,
      56,     5,    31,     7,    15,    69,    31,     6,     9,    31,
      15,    15,    68,    14,    15,    12,    15,    21,    15,     5,
      31,     7,    15,    40,     0,    15,    31,    18,    68,    15,
       5,    71,     7,    68,    31,    21,    68,    28,    31,    68,
      15,    31,    46,    68,    63,   109,    65,   111,     4,    68,
      67,   299,    68,    15,    15,    68,   120,    68,    62,    63,
      46,    65,     6,    68,    68,    69,    70,    71,    72,    31,
      31,    46,    68,    15,    14,    68,    62,   141,    68,    65,
     142,     7,    68,    69,    70,    71,    72,    62,     6,    31,
      65,     4,    15,    68,    69,    70,    71,    72,     5,    14,
      15,   157,   158,    47,     5,    48,    68,    68,    31,   226,
      39,    54,    10,    56,    58,    59,    60,     7,    61,     8,
      64,     9,    66,    68,    68,     7,    68,    32,    19,    47,
     192,    22,    23,    24,    25,    26,    27,    29,    30,    16,
      58,    59,    60,   207,    68,    68,    64,    63,    66,    65,
      68,    17,    68,   217,   121,   122,   123,   124,   125,   126,
     127,    31,    32,    33,    34,     7,   132,   133,   134,   135,
     234,    35,    36,     9,   291,   231,   293,   239,     4,    13,
       8,     7,    16,   247,    14,    15,    10,   251,    43,    44,
       6,   255,   309,   128,   129,    38,   130,   131,   136,   137,
     264,    11,    37,   267,   321,   322,    68,   271,     7,   273,
       6,    68,   268,     8,    16,    68,    10,    68,     4,    17,
       4,     4,     4,     4,   288,    41,    42,     4,   292,    45,
     294,     6,    12,    49,    50,    51,    52,    53,     8,    55,
     304,    57,    16,    59,    60,    41,    42,   311,    68,    45,
       4,     4,   316,    49,    50,    51,    52,    53,    10,    55,
       8,    57,    11,    59,    60,     5,    41,    42,    10,     8,
      45,    12,    10,     6,    49,    50,    51,    52,    53,    14,
      55,     8,    57,    19,    59,    60,     5,    13,    16,    68,
       7,     7,     7,     4,    12,    68,    68,     4,    20,    68,
       8,    13,     8,    12,     8,     4,     9,     5,     4,     4,
      68,    16,     4,     7,    14,     8,   143,     8,    31,    50,
     239,   225,   231,   138,   324,   258,    71,   139,    -1,   235,
      -1,   164,    34,    -1,   112
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    74,    76,     0,    48,    54,    56,    61,    75,    68,
     120,   121,    68,   121,    68,    14,     4,     7,    77,     4,
      77,   121,    63,    65,    68,    79,    80,   125,     5,     5,
      39,    10,     8,    15,    31,    68,    82,    91,     7,    80,
      68,    71,   124,   124,     9,    78,     6,    41,    42,    45,
      49,    50,    51,    52,    53,    55,    57,    59,    60,    81,
       6,    90,   125,    68,   127,   128,    16,    32,     5,     7,
      15,    21,    46,    62,    65,    68,    69,    70,    71,    72,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    68,    83,   125,    17,
      84,    84,   125,   125,   125,   125,   125,   125,     7,     7,
      68,     9,    10,     8,   125,   112,   112,   119,   103,    14,
      15,    19,    22,    23,    24,    25,    26,    27,    18,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      14,    15,    11,    68,    68,     7,    99,   101,    68,    68,
      68,    68,    68,    68,    68,   112,     4,     7,    63,   112,
     126,   128,    12,     8,    10,    16,    68,   112,   104,   104,
     104,   104,   104,   104,   104,   105,   105,   106,   106,   118,
     118,   118,   118,   108,   108,   115,   110,    68,   112,    83,
      78,    17,     7,    83,    85,    86,    87,     5,    40,    67,
     100,     4,     4,     4,     4,     4,     4,    12,     8,    92,
      93,   125,   125,    68,   122,   123,   119,    13,    16,    16,
       4,     4,    83,    88,    89,    10,     8,    11,    96,   112,
       5,    10,     8,    68,    12,    10,     6,   112,    14,    19,
       8,    86,    99,    18,    68,     6,    47,    58,    59,    60,
      64,    66,    68,    95,    99,    13,    82,    93,     5,   112,
     123,    16,    68,    89,     7,   112,     7,     7,    12,    94,
     112,     9,    14,    15,    97,   112,     6,    96,   112,     4,
      68,   112,   125,    68,     4,   112,    68,   112,    20,     8,
       6,     8,    12,     8,     9,    98,     4,    16,   112,     5,
      99,   112,    99,   112,     9,    14,     4,    82,    43,    44,
     102,    13,     4,   112,    68,     6,     7,    99,   112,     4,
     112,     8,     8,    99,    99,   102
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    73,    74,    75,    75,    75,    75,    76,    76,    77,
      77,    78,    78,    79,    80,    80,    80,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    82,
      82,    83,    83,    83,    84,    84,    85,    85,    86,    86,
      86,    87,    87,    88,    89,    89,    89,    90,    90,    91,
      91,    92,    93,    93,    93,    94,    94,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    96,    96,    97,
      97,    97,    97,    98,    98,    99,   100,   100,   101,   101,
     102,   102,   102,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   104,   104,   105,
     105,   105,   105,   105,   105,   105,   105,   106,   106,   106,
     107,   107,   107,   108,   108,   108,   108,   108,   109,   109,
     109,   110,   110,   111,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   119,   119,   120,   121,   121,   121,   122,
     123,   123,   123,   124,   124,   125,   125,   125,   125,   125,
     125,   126,   126,   127,   128,   128,   128
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     3,     6,     6,     0,     2,     0,
       3,     2,     0,     3,     0,     1,     3,     5,     4,     4,
       4,     4,     4,     4,     6,     3,     5,    11,     7,     0,
       2,     1,     3,     6,     0,     3,     3,     3,     0,     1,
       3,     1,     3,     1,     0,     1,     3,     3,     8,     0,
       2,     2,     0,     1,     3,     0,     2,     4,     4,     7,
       6,     1,     5,     9,     5,     3,     3,     0,     2,     2,
       3,     5,     0,     3,     0,     4,     1,     1,     0,     2,
       6,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       5,     3,     1,     4,     6,     3,     3,     2,     1,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     3,     1,     0,     1,     3,     3,
       0,     1,     3,     1,     1,     1,     1,     1,     5,     4,
       4,     2,     1,     3,     0,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 1531 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.package_) = new PDefs((yyvsp[0].listdef_)); (yyval.package_)->line_number = yy_mylinenumber; YY_RESULT_Package_= (yyval.package_); }
#line 2912 "Parser.C" /* yacc.c:1646  */
    break;

  case 3:
#line 1533 "spatialc.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-1].listpackagename_)->begin(),(yyvsp[-1].listpackagename_)->end()) ;(yyval.def_) = new DefImport((yyvsp[-1].listpackagename_)); (yyval.def_)->line_number = yy_mylinenumber;  }
#line 2918 "Parser.C" /* yacc.c:1646  */
    break;

  case 4:
#line 1534 "spatialc.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-1].listpackagename_)->begin(),(yyvsp[-1].listpackagename_)->end()) ;(yyval.def_) = new DefPackage((yyvsp[-1].listpackagename_)); (yyval.def_)->line_number = yy_mylinenumber;  }
#line 2924 "Parser.C" /* yacc.c:1646  */
    break;

  case 5:
#line 1535 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.def_) = new DefModule((yyvsp[-4].string_), (yyvsp[-3].metaparamdecl_), (yyvsp[-1].listmoddef_)); (yyval.def_)->line_number = yy_mylinenumber;  }
#line 2930 "Parser.C" /* yacc.c:1646  */
    break;

  case 6:
#line 1536 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.def_) = new DefStruct((yyvsp[-4].string_), (yyvsp[-3].metaparamdecl_), (yyvsp[-1].liststructdef_)); (yyval.def_)->line_number = yy_mylinenumber;  }
#line 2936 "Parser.C" /* yacc.c:1646  */
    break;

  case 7:
#line 1538 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listdef_) = new ListDef();  }
#line 2942 "Parser.C" /* yacc.c:1646  */
    break;

  case 8:
#line 1539 "spatialc.y" /* yacc.c:1646  */
    {  (yyvsp[-1].listdef_)->push_back((yyvsp[0].def_)) ; (yyval.listdef_) = (yyvsp[-1].listdef_) ;  }
#line 2948 "Parser.C" /* yacc.c:1646  */
    break;

  case 9:
#line 1541 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.metaparamdecl_) = new NoParams(); (yyval.metaparamdecl_)->line_number = yy_mylinenumber;  }
#line 2954 "Parser.C" /* yacc.c:1646  */
    break;

  case 10:
#line 1542 "spatialc.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-1].listmetaparam_)->begin(),(yyvsp[-1].listmetaparam_)->end()) ;(yyval.metaparamdecl_) = new SomeParams((yyvsp[-1].listmetaparam_)); (yyval.metaparamdecl_)->line_number = yy_mylinenumber;  }
#line 2960 "Parser.C" /* yacc.c:1646  */
    break;

  case 11:
#line 1544 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.optionaleqexp_) = new EqExp((yyvsp[0].exp_)); (yyval.optionaleqexp_)->line_number = yy_mylinenumber;  }
#line 2966 "Parser.C" /* yacc.c:1646  */
    break;

  case 12:
#line 1545 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.optionaleqexp_) = new NoEqExp(); (yyval.optionaleqexp_)->line_number = yy_mylinenumber;  }
#line 2972 "Parser.C" /* yacc.c:1646  */
    break;

  case 13:
#line 1547 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.metaparam_) = new MetaParam1((yyvsp[-2].type_), (yyvsp[-1].string_), (yyvsp[0].optionaleqexp_)); (yyval.metaparam_)->line_number = yy_mylinenumber;  }
#line 2978 "Parser.C" /* yacc.c:1646  */
    break;

  case 14:
#line 1549 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listmetaparam_) = new ListMetaParam();  }
#line 2984 "Parser.C" /* yacc.c:1646  */
    break;

  case 15:
#line 1550 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listmetaparam_) = new ListMetaParam() ; (yyval.listmetaparam_)->push_back((yyvsp[0].metaparam_));  }
#line 2990 "Parser.C" /* yacc.c:1646  */
    break;

  case 16:
#line 1551 "spatialc.y" /* yacc.c:1646  */
    {  (yyvsp[0].listmetaparam_)->push_back((yyvsp[-2].metaparam_)) ; (yyval.listmetaparam_) = (yyvsp[0].listmetaparam_) ;  }
#line 2996 "Parser.C" /* yacc.c:1646  */
    break;

  case 17:
#line 1553 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.moddef_) = new DefConst((yyvsp[-3].type_), (yyvsp[-2].string_), (yyvsp[-1].optionaleqexp_)); (yyval.moddef_)->line_number = yy_mylinenumber;  }
#line 3002 "Parser.C" /* yacc.c:1646  */
    break;

  case 18:
#line 1554 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.moddef_) = new DefReg((yyvsp[-2].type_), (yyvsp[-1].string_)); (yyval.moddef_)->line_number = yy_mylinenumber;  }
#line 3008 "Parser.C" /* yacc.c:1646  */
    break;

  case 19:
#line 1555 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.moddef_) = new DefMem((yyvsp[-2].type_), (yyvsp[-1].string_)); (yyval.moddef_)->line_number = yy_mylinenumber;  }
#line 3014 "Parser.C" /* yacc.c:1646  */
    break;

  case 20:
#line 1556 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.moddef_) = new DefSubmodule((yyvsp[-2].type_), (yyvsp[-1].string_)); (yyval.moddef_)->line_number = yy_mylinenumber;  }
#line 3020 "Parser.C" /* yacc.c:1646  */
    break;

  case 21:
#line 1557 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.moddef_) = new DefInput((yyvsp[-2].type_), (yyvsp[-1].string_)); (yyval.moddef_)->line_number = yy_mylinenumber;  }
#line 3026 "Parser.C" /* yacc.c:1646  */
    break;

  case 22:
#line 1558 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.moddef_) = new DefOutput((yyvsp[-2].type_), (yyvsp[-1].string_)); (yyval.moddef_)->line_number = yy_mylinenumber;  }
#line 3032 "Parser.C" /* yacc.c:1646  */
    break;

  case 23:
#line 1559 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.moddef_) = new DefInternal((yyvsp[-2].type_), (yyvsp[-1].string_)); (yyval.moddef_)->line_number = yy_mylinenumber;  }
#line 3038 "Parser.C" /* yacc.c:1646  */
    break;

  case 24:
#line 1560 "spatialc.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-2].listeventparam_)->begin(),(yyvsp[-2].listeventparam_)->end()) ;(yyval.moddef_) = new DefEvent((yyvsp[-4].eventname_), (yyvsp[-2].listeventparam_), (yyvsp[0].block_)); (yyval.moddef_)->line_number = yy_mylinenumber;  }
#line 3044 "Parser.C" /* yacc.c:1646  */
    break;

  case 25:
#line 1561 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.moddef_) = new DefInit((yyvsp[-1].eventname_), (yyvsp[0].block_)); (yyval.moddef_)->line_number = yy_mylinenumber;  }
#line 3050 "Parser.C" /* yacc.c:1646  */
    break;

  case 26:
#line 1562 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.moddef_) = new DefConnect((yyvsp[-3].channelspecifier_), (yyvsp[-1].channelspecifier_)); (yyval.moddef_)->line_number = yy_mylinenumber;  }
#line 3056 "Parser.C" /* yacc.c:1646  */
    break;

  case 27:
#line 1563 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.moddef_) = new DefFor((yyvsp[-8].string_), (yyvsp[-6].exp_), (yyvsp[-4].exp_), (yyvsp[-1].listmoddef_)); (yyval.moddef_)->line_number = yy_mylinenumber;  }
#line 3062 "Parser.C" /* yacc.c:1646  */
    break;

  case 28:
#line 1564 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.moddef_) = new DefIf((yyvsp[-4].exp_), (yyvsp[-1].listmoddef_)); (yyval.moddef_)->line_number = yy_mylinenumber;  }
#line 3068 "Parser.C" /* yacc.c:1646  */
    break;

  case 29:
#line 1566 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listmoddef_) = new ListModDef();  }
#line 3074 "Parser.C" /* yacc.c:1646  */
    break;

  case 30:
#line 1567 "spatialc.y" /* yacc.c:1646  */
    {  (yyvsp[-1].listmoddef_)->push_back((yyvsp[0].moddef_)) ; (yyval.listmoddef_) = (yyvsp[-1].listmoddef_) ;  }
#line 3080 "Parser.C" /* yacc.c:1646  */
    break;

  case 31:
#line 1569 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.channelspecifier_) = new SimpleCS((yyvsp[0].string_)); (yyval.channelspecifier_)->line_number = yy_mylinenumber;  }
#line 3086 "Parser.C" /* yacc.c:1646  */
    break;

  case 32:
#line 1570 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.channelspecifier_) = new DotCS((yyvsp[-2].string_), (yyvsp[0].string_)); (yyval.channelspecifier_)->line_number = yy_mylinenumber;  }
#line 3092 "Parser.C" /* yacc.c:1646  */
    break;

  case 33:
#line 1571 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.channelspecifier_) = new ArrayDotCS((yyvsp[-5].string_), (yyvsp[-3].exp_), (yyvsp[0].string_)); (yyval.channelspecifier_)->line_number = yy_mylinenumber;  }
#line 3098 "Parser.C" /* yacc.c:1646  */
    break;

  case 34:
#line 1573 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.eventname_) = new NoEvName(); (yyval.eventname_)->line_number = yy_mylinenumber;  }
#line 3104 "Parser.C" /* yacc.c:1646  */
    break;

  case 35:
#line 1574 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.eventname_) = new EvName((yyvsp[-1].string_)); (yyval.eventname_)->line_number = yy_mylinenumber;  }
#line 3110 "Parser.C" /* yacc.c:1646  */
    break;

  case 36:
#line 1576 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.eventparam_) = new EventParamWithName((yyvsp[-2].eventorcond_), (yyvsp[0].string_)); (yyval.eventparam_)->line_number = yy_mylinenumber;  }
#line 3116 "Parser.C" /* yacc.c:1646  */
    break;

  case 37:
#line 1577 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.eventparam_) = new EventParamNoName((yyvsp[-2].eventorcond_)); (yyval.eventparam_)->line_number = yy_mylinenumber;  }
#line 3122 "Parser.C" /* yacc.c:1646  */
    break;

  case 38:
#line 1579 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listeventparam_) = new ListEventParam();  }
#line 3128 "Parser.C" /* yacc.c:1646  */
    break;

  case 39:
#line 1580 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listeventparam_) = new ListEventParam() ; (yyval.listeventparam_)->push_back((yyvsp[0].eventparam_));  }
#line 3134 "Parser.C" /* yacc.c:1646  */
    break;

  case 40:
#line 1581 "spatialc.y" /* yacc.c:1646  */
    {  (yyvsp[0].listeventparam_)->push_back((yyvsp[-2].eventparam_)) ; (yyval.listeventparam_) = (yyvsp[0].listeventparam_) ;  }
#line 3140 "Parser.C" /* yacc.c:1646  */
    break;

  case 41:
#line 1583 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.eventorcond_) = new CSEventCond((yyvsp[0].channelspecifier_)); (yyval.eventorcond_)->line_number = yy_mylinenumber;  }
#line 3146 "Parser.C" /* yacc.c:1646  */
    break;

  case 42:
#line 1584 "spatialc.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-1].listeventorlist_)->begin(),(yyvsp[-1].listeventorlist_)->end()) ;(yyval.eventorcond_) = new ListEvOr((yyvsp[-1].listeventorlist_)); (yyval.eventorcond_)->line_number = yy_mylinenumber;  }
#line 3152 "Parser.C" /* yacc.c:1646  */
    break;

  case 43:
#line 1586 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.eventorlist_) = new EventOrListChannelSpecifier((yyvsp[0].channelspecifier_)); (yyval.eventorlist_)->line_number = yy_mylinenumber;  }
#line 3158 "Parser.C" /* yacc.c:1646  */
    break;

  case 44:
#line 1588 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listeventorlist_) = new ListEventOrList();  }
#line 3164 "Parser.C" /* yacc.c:1646  */
    break;

  case 45:
#line 1589 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listeventorlist_) = new ListEventOrList() ; (yyval.listeventorlist_)->push_back((yyvsp[0].eventorlist_));  }
#line 3170 "Parser.C" /* yacc.c:1646  */
    break;

  case 46:
#line 1590 "spatialc.y" /* yacc.c:1646  */
    {  (yyvsp[0].listeventorlist_)->push_back((yyvsp[-2].eventorlist_)) ; (yyval.listeventorlist_) = (yyvsp[0].listeventorlist_) ;  }
#line 3176 "Parser.C" /* yacc.c:1646  */
    break;

  case 47:
#line 1592 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.structdef_) = new DefSubstor((yyvsp[-2].type_), (yyvsp[-1].string_)); (yyval.structdef_)->line_number = yy_mylinenumber;  }
#line 3182 "Parser.C" /* yacc.c:1646  */
    break;

  case 48:
#line 1593 "spatialc.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-4].listfuncparam_)->begin(),(yyvsp[-4].listfuncparam_)->end()) ;(yyval.structdef_) = new DefFunction((yyvsp[-7].type_), (yyvsp[-6].string_), (yyvsp[-4].listfuncparam_), (yyvsp[-1].liststatement_)); (yyval.structdef_)->line_number = yy_mylinenumber;  }
#line 3188 "Parser.C" /* yacc.c:1646  */
    break;

  case 49:
#line 1595 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.liststructdef_) = new ListStructDef();  }
#line 3194 "Parser.C" /* yacc.c:1646  */
    break;

  case 50:
#line 1596 "spatialc.y" /* yacc.c:1646  */
    {  (yyvsp[-1].liststructdef_)->push_back((yyvsp[0].structdef_)) ; (yyval.liststructdef_) = (yyvsp[-1].liststructdef_) ;  }
#line 3200 "Parser.C" /* yacc.c:1646  */
    break;

  case 51:
#line 1598 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.funcparam_) = new FuncParam1((yyvsp[-1].type_), (yyvsp[0].string_)); (yyval.funcparam_)->line_number = yy_mylinenumber;  }
#line 3206 "Parser.C" /* yacc.c:1646  */
    break;

  case 52:
#line 1600 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listfuncparam_) = new ListFuncParam();  }
#line 3212 "Parser.C" /* yacc.c:1646  */
    break;

  case 53:
#line 1601 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listfuncparam_) = new ListFuncParam() ; (yyval.listfuncparam_)->push_back((yyvsp[0].funcparam_));  }
#line 3218 "Parser.C" /* yacc.c:1646  */
    break;

  case 54:
#line 1602 "spatialc.y" /* yacc.c:1646  */
    {  (yyvsp[0].listfuncparam_)->push_back((yyvsp[-2].funcparam_)) ; (yyval.listfuncparam_) = (yyvsp[0].listfuncparam_) ;  }
#line 3224 "Parser.C" /* yacc.c:1646  */
    break;

  case 55:
#line 1604 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.optionaltype_) = new NoType(); (yyval.optionaltype_)->line_number = yy_mylinenumber;  }
#line 3230 "Parser.C" /* yacc.c:1646  */
    break;

  case 56:
#line 1605 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.optionaltype_) = new TypeSpec((yyvsp[0].type_)); (yyval.optionaltype_)->line_number = yy_mylinenumber;  }
#line 3236 "Parser.C" /* yacc.c:1646  */
    break;

  case 57:
#line 1607 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.statement_) = new VarStmt((yyvsp[-2].optionaltype_), (yyvsp[-1].string_), (yyvsp[0].varassignment_)); (yyval.statement_)->line_number = yy_mylinenumber;  }
#line 3242 "Parser.C" /* yacc.c:1646  */
    break;

  case 58:
#line 1608 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.statement_) = new AssignStmt((yyvsp[-3].string_), (yyvsp[-1].exp_)); (yyval.statement_)->line_number = yy_mylinenumber;  }
#line 3248 "Parser.C" /* yacc.c:1646  */
    break;

  case 59:
#line 1609 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.statement_) = new AssignArrStmt((yyvsp[-6].string_), (yyvsp[-4].exp_), (yyvsp[-1].exp_)); (yyval.statement_)->line_number = yy_mylinenumber;  }
#line 3254 "Parser.C" /* yacc.c:1646  */
    break;

  case 60:
#line 1610 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.statement_) = new IfStmt((yyvsp[-3].exp_), (yyvsp[-1].block_), (yyvsp[0].elseblock_)); (yyval.statement_)->line_number = yy_mylinenumber;  }
#line 3260 "Parser.C" /* yacc.c:1646  */
    break;

  case 61:
#line 1611 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.statement_) = new BlockStmt((yyvsp[0].block_)); (yyval.statement_)->line_number = yy_mylinenumber;  }
#line 3266 "Parser.C" /* yacc.c:1646  */
    break;

  case 62:
#line 1612 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.statement_) = new PushStmt((yyvsp[-4].string_), (yyvsp[-3].pushsubdest_), (yyvsp[-1].exp_)); (yyval.statement_)->line_number = yy_mylinenumber;  }
#line 3272 "Parser.C" /* yacc.c:1646  */
    break;

  case 63:
#line 1613 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.statement_) = new StaticForStmt((yyvsp[-6].string_), (yyvsp[-4].exp_), (yyvsp[-2].exp_), (yyvsp[0].block_)); (yyval.statement_)->line_number = yy_mylinenumber;  }
#line 3278 "Parser.C" /* yacc.c:1646  */
    break;

  case 64:
#line 1614 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.statement_) = new StaticIfStmt((yyvsp[-2].exp_), (yyvsp[0].block_)); (yyval.statement_)->line_number = yy_mylinenumber;  }
#line 3284 "Parser.C" /* yacc.c:1646  */
    break;

  case 65:
#line 1615 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.statement_) = new ReturnStmt((yyvsp[-1].exp_)); (yyval.statement_)->line_number = yy_mylinenumber;  }
#line 3290 "Parser.C" /* yacc.c:1646  */
    break;

  case 66:
#line 1616 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.statement_) = new WaitUntilStmt((yyvsp[-1].exp_)); (yyval.statement_)->line_number = yy_mylinenumber;  }
#line 3296 "Parser.C" /* yacc.c:1646  */
    break;

  case 67:
#line 1618 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.liststatement_) = new ListStatement();  }
#line 3302 "Parser.C" /* yacc.c:1646  */
    break;

  case 68:
#line 1619 "spatialc.y" /* yacc.c:1646  */
    {  (yyvsp[-1].liststatement_)->push_back((yyvsp[0].statement_)) ; (yyval.liststatement_) = (yyvsp[-1].liststatement_) ;  }
#line 3308 "Parser.C" /* yacc.c:1646  */
    break;

  case 69:
#line 1621 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.pushsubdest_) = new PushSubreg((yyvsp[0].string_)); (yyval.pushsubdest_)->line_number = yy_mylinenumber;  }
#line 3314 "Parser.C" /* yacc.c:1646  */
    break;

  case 70:
#line 1622 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.pushsubdest_) = new PushArray((yyvsp[-1].exp_)); (yyval.pushsubdest_)->line_number = yy_mylinenumber;  }
#line 3320 "Parser.C" /* yacc.c:1646  */
    break;

  case 71:
#line 1623 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.pushsubdest_) = new PushArrayDot((yyvsp[-3].exp_), (yyvsp[0].string_)); (yyval.pushsubdest_)->line_number = yy_mylinenumber;  }
#line 3326 "Parser.C" /* yacc.c:1646  */
    break;

  case 72:
#line 1624 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.pushsubdest_) = new PushReg(); (yyval.pushsubdest_)->line_number = yy_mylinenumber;  }
#line 3332 "Parser.C" /* yacc.c:1646  */
    break;

  case 73:
#line 1626 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.varassignment_) = new VarAssign((yyvsp[-1].exp_)); (yyval.varassignment_)->line_number = yy_mylinenumber;  }
#line 3338 "Parser.C" /* yacc.c:1646  */
    break;

  case 74:
#line 1627 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.varassignment_) = new NoVarAssign(); (yyval.varassignment_)->line_number = yy_mylinenumber;  }
#line 3344 "Parser.C" /* yacc.c:1646  */
    break;

  case 75:
#line 1629 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.block_) = new Block1((yyvsp[-3].listblockattr_), (yyvsp[-1].liststatement_)); (yyval.block_)->line_number = yy_mylinenumber;  }
#line 3350 "Parser.C" /* yacc.c:1646  */
    break;

  case 76:
#line 1631 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.blockattr_) = new BlockAttr_atomic(); (yyval.blockattr_)->line_number = yy_mylinenumber;  }
#line 3356 "Parser.C" /* yacc.c:1646  */
    break;

  case 77:
#line 1632 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.blockattr_) = new BlockAttr_xact(); (yyval.blockattr_)->line_number = yy_mylinenumber;  }
#line 3362 "Parser.C" /* yacc.c:1646  */
    break;

  case 78:
#line 1634 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listblockattr_) = new ListBlockAttr();  }
#line 3368 "Parser.C" /* yacc.c:1646  */
    break;

  case 79:
#line 1635 "spatialc.y" /* yacc.c:1646  */
    {  (yyvsp[-1].listblockattr_)->push_back((yyvsp[0].blockattr_)) ; (yyval.listblockattr_) = (yyvsp[-1].listblockattr_) ;  }
#line 3374 "Parser.C" /* yacc.c:1646  */
    break;

  case 80:
#line 1637 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.elseblock_) = new ElseIf((yyvsp[-3].exp_), (yyvsp[-1].block_), (yyvsp[0].elseblock_)); (yyval.elseblock_)->line_number = yy_mylinenumber;  }
#line 3380 "Parser.C" /* yacc.c:1646  */
    break;

  case 81:
#line 1638 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.elseblock_) = new Else((yyvsp[0].block_)); (yyval.elseblock_)->line_number = yy_mylinenumber;  }
#line 3386 "Parser.C" /* yacc.c:1646  */
    break;

  case 82:
#line 1639 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.elseblock_) = new NoElse(); (yyval.elseblock_)->line_number = yy_mylinenumber;  }
#line 3392 "Parser.C" /* yacc.c:1646  */
    break;

  case 83:
#line 1641 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EVoid(); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3398 "Parser.C" /* yacc.c:1646  */
    break;

  case 84:
#line 1642 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new ETrue(); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3404 "Parser.C" /* yacc.c:1646  */
    break;

  case 85:
#line 1643 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EFalse(); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3410 "Parser.C" /* yacc.c:1646  */
    break;

  case 86:
#line 1644 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EInt((yyvsp[0].int_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3416 "Parser.C" /* yacc.c:1646  */
    break;

  case 87:
#line 1645 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EHex((yyvsp[0].string_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3422 "Parser.C" /* yacc.c:1646  */
    break;

  case 88:
#line 1646 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EDouble((yyvsp[0].double_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3428 "Parser.C" /* yacc.c:1646  */
    break;

  case 89:
#line 1647 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EString((yyvsp[0].string_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3434 "Parser.C" /* yacc.c:1646  */
    break;

  case 90:
#line 1648 "spatialc.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-1].liststructliteralfield_)->begin(),(yyvsp[-1].liststructliteralfield_)->end()) ;(yyval.exp_) = new EStructLiteral((yyvsp[-3].type_), (yyvsp[-1].liststructliteralfield_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3440 "Parser.C" /* yacc.c:1646  */
    break;

  case 91:
#line 1649 "spatialc.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-1].listexp_)->begin(),(yyvsp[-1].listexp_)->end()) ;(yyval.exp_) = new EVectorLiteral((yyvsp[-1].listexp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3446 "Parser.C" /* yacc.c:1646  */
    break;

  case 92:
#line 1650 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EId((yyvsp[0].string_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3452 "Parser.C" /* yacc.c:1646  */
    break;

  case 93:
#line 1651 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EArrAcc((yyvsp[-3].exp_), (yyvsp[-1].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3458 "Parser.C" /* yacc.c:1646  */
    break;

  case 94:
#line 1652 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new ESlice((yyvsp[-5].exp_), (yyvsp[-3].exp_), (yyvsp[-1].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3464 "Parser.C" /* yacc.c:1646  */
    break;

  case 95:
#line 1653 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EDot((yyvsp[-2].exp_), (yyvsp[0].string_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3470 "Parser.C" /* yacc.c:1646  */
    break;

  case 96:
#line 1654 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[-1].exp_);  }
#line 3476 "Parser.C" /* yacc.c:1646  */
    break;

  case 97:
#line 1656 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new ENeg((yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3482 "Parser.C" /* yacc.c:1646  */
    break;

  case 98:
#line 1657 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3488 "Parser.C" /* yacc.c:1646  */
    break;

  case 99:
#line 1659 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EAndB((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3494 "Parser.C" /* yacc.c:1646  */
    break;

  case 100:
#line 1660 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EOrB((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3500 "Parser.C" /* yacc.c:1646  */
    break;

  case 101:
#line 1661 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EXOR((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3506 "Parser.C" /* yacc.c:1646  */
    break;

  case 102:
#line 1662 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EShR((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3512 "Parser.C" /* yacc.c:1646  */
    break;

  case 103:
#line 1663 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EShL((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3518 "Parser.C" /* yacc.c:1646  */
    break;

  case 104:
#line 1664 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new ERotR((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3524 "Parser.C" /* yacc.c:1646  */
    break;

  case 105:
#line 1665 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new ERotL((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3530 "Parser.C" /* yacc.c:1646  */
    break;

  case 106:
#line 1666 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3536 "Parser.C" /* yacc.c:1646  */
    break;

  case 107:
#line 1668 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new ETimes((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3542 "Parser.C" /* yacc.c:1646  */
    break;

  case 108:
#line 1669 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EDiv((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3548 "Parser.C" /* yacc.c:1646  */
    break;

  case 109:
#line 1670 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3554 "Parser.C" /* yacc.c:1646  */
    break;

  case 110:
#line 1672 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EPlus((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3560 "Parser.C" /* yacc.c:1646  */
    break;

  case 111:
#line 1673 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EMinus((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3566 "Parser.C" /* yacc.c:1646  */
    break;

  case 112:
#line 1674 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3572 "Parser.C" /* yacc.c:1646  */
    break;

  case 113:
#line 1676 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new ELt((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3578 "Parser.C" /* yacc.c:1646  */
    break;

  case 114:
#line 1677 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EGt((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3584 "Parser.C" /* yacc.c:1646  */
    break;

  case 115:
#line 1678 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new ELtEq((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3590 "Parser.C" /* yacc.c:1646  */
    break;

  case 116:
#line 1679 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EGtEq((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3596 "Parser.C" /* yacc.c:1646  */
    break;

  case 117:
#line 1680 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3602 "Parser.C" /* yacc.c:1646  */
    break;

  case 118:
#line 1682 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EEq((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3608 "Parser.C" /* yacc.c:1646  */
    break;

  case 119:
#line 1683 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new ENEq((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3614 "Parser.C" /* yacc.c:1646  */
    break;

  case 120:
#line 1684 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3620 "Parser.C" /* yacc.c:1646  */
    break;

  case 121:
#line 1686 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EAnd((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3626 "Parser.C" /* yacc.c:1646  */
    break;

  case 122:
#line 1687 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3632 "Parser.C" /* yacc.c:1646  */
    break;

  case 123:
#line 1689 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EOr((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3638 "Parser.C" /* yacc.c:1646  */
    break;

  case 124:
#line 1690 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3644 "Parser.C" /* yacc.c:1646  */
    break;

  case 125:
#line 1692 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3650 "Parser.C" /* yacc.c:1646  */
    break;

  case 126:
#line 1694 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3656 "Parser.C" /* yacc.c:1646  */
    break;

  case 127:
#line 1696 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3662 "Parser.C" /* yacc.c:1646  */
    break;

  case 128:
#line 1698 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3668 "Parser.C" /* yacc.c:1646  */
    break;

  case 129:
#line 1700 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3674 "Parser.C" /* yacc.c:1646  */
    break;

  case 130:
#line 1702 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3680 "Parser.C" /* yacc.c:1646  */
    break;

  case 131:
#line 1704 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3686 "Parser.C" /* yacc.c:1646  */
    break;

  case 132:
#line 1706 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listexp_) = new ListExp();  }
#line 3692 "Parser.C" /* yacc.c:1646  */
    break;

  case 133:
#line 1707 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listexp_) = new ListExp() ; (yyval.listexp_)->push_back((yyvsp[0].exp_));  }
#line 3698 "Parser.C" /* yacc.c:1646  */
    break;

  case 134:
#line 1708 "spatialc.y" /* yacc.c:1646  */
    {  (yyvsp[0].listexp_)->push_back((yyvsp[-2].exp_)) ; (yyval.listexp_) = (yyvsp[0].listexp_) ;  }
#line 3704 "Parser.C" /* yacc.c:1646  */
    break;

  case 135:
#line 1710 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.packagename_) = new PackageNameId((yyvsp[0].string_)); (yyval.packagename_)->line_number = yy_mylinenumber;  }
#line 3710 "Parser.C" /* yacc.c:1646  */
    break;

  case 136:
#line 1712 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listpackagename_) = new ListPackageName();  }
#line 3716 "Parser.C" /* yacc.c:1646  */
    break;

  case 137:
#line 1713 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listpackagename_) = new ListPackageName() ; (yyval.listpackagename_)->push_back((yyvsp[0].packagename_));  }
#line 3722 "Parser.C" /* yacc.c:1646  */
    break;

  case 138:
#line 1714 "spatialc.y" /* yacc.c:1646  */
    {  (yyvsp[0].listpackagename_)->push_back((yyvsp[-2].packagename_)) ; (yyval.listpackagename_) = (yyvsp[0].listpackagename_) ;  }
#line 3728 "Parser.C" /* yacc.c:1646  */
    break;

  case 139:
#line 1716 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.structliteralfield_) = new StructLiteralField1((yyvsp[-2].string_), (yyvsp[0].exp_)); (yyval.structliteralfield_)->line_number = yy_mylinenumber;  }
#line 3734 "Parser.C" /* yacc.c:1646  */
    break;

  case 140:
#line 1718 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.liststructliteralfield_) = new ListStructLiteralField();  }
#line 3740 "Parser.C" /* yacc.c:1646  */
    break;

  case 141:
#line 1719 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.liststructliteralfield_) = new ListStructLiteralField() ; (yyval.liststructliteralfield_)->push_back((yyvsp[0].structliteralfield_));  }
#line 3746 "Parser.C" /* yacc.c:1646  */
    break;

  case 142:
#line 1720 "spatialc.y" /* yacc.c:1646  */
    {  (yyvsp[0].liststructliteralfield_)->push_back((yyvsp[-2].structliteralfield_)) ; (yyval.liststructliteralfield_) = (yyvsp[0].liststructliteralfield_) ;  }
#line 3752 "Parser.C" /* yacc.c:1646  */
    break;

  case 143:
#line 1722 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.intorname_) = new ConstName((yyvsp[0].string_)); (yyval.intorname_)->line_number = yy_mylinenumber;  }
#line 3758 "Parser.C" /* yacc.c:1646  */
    break;

  case 144:
#line 1723 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.intorname_) = new Int((yyvsp[0].int_)); (yyval.intorname_)->line_number = yy_mylinenumber;  }
#line 3764 "Parser.C" /* yacc.c:1646  */
    break;

  case 145:
#line 1725 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.type_) = new TyName((yyvsp[0].string_)); (yyval.type_)->line_number = yy_mylinenumber;  }
#line 3770 "Parser.C" /* yacc.c:1646  */
    break;

  case 146:
#line 1726 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.type_) = new TyVoid(); (yyval.type_)->line_number = yy_mylinenumber;  }
#line 3776 "Parser.C" /* yacc.c:1646  */
    break;

  case 147:
#line 1727 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.type_) = new TyType(); (yyval.type_)->line_number = yy_mylinenumber;  }
#line 3782 "Parser.C" /* yacc.c:1646  */
    break;

  case 148:
#line 1728 "spatialc.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-1].listtemplatearg_)->begin(),(yyvsp[-1].listtemplatearg_)->end()) ;(yyval.type_) = new TyNameParams((yyvsp[-4].string_), (yyvsp[-1].listtemplatearg_)); (yyval.type_)->line_number = yy_mylinenumber;  }
#line 3788 "Parser.C" /* yacc.c:1646  */
    break;

  case 149:
#line 1729 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.type_) = new TyArray((yyvsp[-3].type_), (yyvsp[-1].intorname_)); (yyval.type_)->line_number = yy_mylinenumber;  }
#line 3794 "Parser.C" /* yacc.c:1646  */
    break;

  case 150:
#line 1730 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.type_) = new TyVector((yyvsp[-3].type_), (yyvsp[-1].intorname_)); (yyval.type_)->line_number = yy_mylinenumber;  }
#line 3800 "Parser.C" /* yacc.c:1646  */
    break;

  case 151:
#line 1732 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.templateexp_) = new TEType((yyvsp[0].type_)); (yyval.templateexp_)->line_number = yy_mylinenumber;  }
#line 3806 "Parser.C" /* yacc.c:1646  */
    break;

  case 152:
#line 1733 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.templateexp_) = new TEConstExp((yyvsp[0].exp_)); (yyval.templateexp_)->line_number = yy_mylinenumber;  }
#line 3812 "Parser.C" /* yacc.c:1646  */
    break;

  case 153:
#line 1735 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.templatearg_) = new TemplateArg1((yyvsp[-2].string_), (yyvsp[0].templateexp_)); (yyval.templatearg_)->line_number = yy_mylinenumber;  }
#line 3818 "Parser.C" /* yacc.c:1646  */
    break;

  case 154:
#line 1737 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listtemplatearg_) = new ListTemplateArg();  }
#line 3824 "Parser.C" /* yacc.c:1646  */
    break;

  case 155:
#line 1738 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listtemplatearg_) = new ListTemplateArg() ; (yyval.listtemplatearg_)->push_back((yyvsp[0].templatearg_));  }
#line 3830 "Parser.C" /* yacc.c:1646  */
    break;

  case 156:
#line 1739 "spatialc.y" /* yacc.c:1646  */
    {  (yyvsp[0].listtemplatearg_)->push_back((yyvsp[-2].templatearg_)) ; (yyval.listtemplatearg_) = (yyvsp[0].listtemplatearg_) ;  }
#line 3836 "Parser.C" /* yacc.c:1646  */
    break;


#line 3840 "Parser.C" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
