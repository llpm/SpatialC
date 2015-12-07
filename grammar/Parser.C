/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

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
    _STRING_ = 317,
    _INTEGER_ = 318,
    _DOUBLE_ = 319
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
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

#line 1566 "Parser.C" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 1581 "Parser.C" /* yacc.c:358  */

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
#define YYLAST   329

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  147
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  309

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1523,  1523,  1525,  1526,  1527,  1528,  1530,  1531,  1533,
    1534,  1536,  1537,  1539,  1541,  1542,  1543,  1545,  1546,  1547,
    1548,  1549,  1550,  1551,  1552,  1553,  1554,  1555,  1556,  1558,
    1559,  1561,  1562,  1563,  1565,  1566,  1568,  1569,  1571,  1572,
    1573,  1575,  1576,  1578,  1580,  1581,  1582,  1584,  1585,  1587,
    1588,  1590,  1592,  1593,  1594,  1596,  1597,  1599,  1600,  1601,
    1602,  1603,  1604,  1605,  1606,  1607,  1608,  1610,  1611,  1613,
    1614,  1615,  1616,  1618,  1619,  1621,  1623,  1624,  1626,  1627,
    1629,  1630,  1631,  1633,  1634,  1635,  1636,  1637,  1638,  1639,
    1640,  1641,  1642,  1643,  1644,  1645,  1647,  1648,  1649,  1651,
    1652,  1653,  1655,  1656,  1657,  1658,  1659,  1661,  1662,  1663,
    1665,  1666,  1668,  1669,  1671,  1673,  1675,  1677,  1679,  1681,
    1683,  1685,  1687,  1689,  1690,  1691,  1693,  1695,  1696,  1697,
    1699,  1701,  1702,  1703,  1705,  1706,  1708,  1709,  1710,  1711,
    1712,  1713,  1715,  1716,  1718,  1720,  1721,  1722
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
  "_SYMB_56", "_SYMB_57", "_STRING_", "_INTEGER_", "_DOUBLE_", "$accept",
  "Package", "Def", "ListDef", "MetaParamDecl", "OptionalEqExp",
  "MetaParam", "ListMetaParam", "ModDef", "ListModDef", "ChannelSpecifier",
  "EventName", "EventParam", "ListEventParam", "EventOrCond",
  "EventOrList", "ListEventOrList", "StructDef", "ListStructDef",
  "FuncParam", "ListFuncParam", "OptionalType", "Statement",
  "ListStatement", "PushSubDest", "VarAssignment", "Block", "BlockAttr",
  "ListBlockAttr", "ElseBlock", "Exp15", "Exp12", "Exp11", "Exp9", "Exp8",
  "Exp4", "Exp3", "Exp", "Exp1", "Exp2", "Exp5", "Exp6", "Exp7", "Exp10",
  "Exp13", "Exp14", "ListExp", "PackageName", "ListPackageName",
  "StructLiteralField", "ListStructLiteralField", "IntOrName", "Type",
  "TemplateExp", "TemplateArg", "ListTemplateArg", YY_NULLPTR
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
     315,   316,   317,   318,   319
};
# endif

#define YYPACT_NINF -212

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-212)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -212,    28,   -14,  -212,   -38,   -25,   -38,   -20,  -212,  -212,
      38,    53,    65,    74,    65,   -38,  -212,    48,    88,  -212,
     100,  -212,  -212,  -212,    95,   114,   123,    14,  -212,  -212,
     131,    48,  -212,    67,    67,   133,    91,     8,    94,  -212,
    -212,  -212,   136,   132,    19,  -212,  -212,   106,    48,   160,
     160,    48,    48,    48,    48,    48,    48,   177,   182,  -212,
    -212,  -212,    24,   184,   189,   208,  -212,  -212,    48,    19,
      19,  -212,  -212,  -212,  -212,  -212,  -212,  -212,    -5,    26,
     126,   171,   153,   172,   191,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,   173,   214,    27,   165,   223,  -212,
      79,    84,    86,    92,   148,   150,   174,    19,    63,    -2,
      94,  -212,    31,   226,   231,   229,   187,    19,    19,    19,
      19,    19,    19,    19,    19,    19,    19,    19,    19,    19,
     188,    19,   106,   133,   234,    23,  -212,    16,   248,   249,
     250,   252,   253,   254,   247,   255,  -212,    48,    48,  -212,
    -212,  -212,   199,  -212,    19,  -212,  -212,   104,  -212,  -212,
      26,    26,  -212,  -212,  -212,  -212,   171,   171,  -212,   172,
    -212,   245,   258,   260,  -212,   106,  -212,   256,   257,   259,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
      19,   262,   261,   264,   156,     7,   263,   266,   267,  -212,
      19,  -212,   265,  -212,  -212,  -212,   268,   269,    23,  -212,
     -11,    39,   270,  -212,    48,   273,  -212,    19,   199,  -212,
     272,   207,   106,  -212,  -212,  -212,  -212,  -212,  -212,   274,
      19,   275,   277,   278,    19,   161,  -212,  -212,    19,   116,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,    19,   276,   213,
      19,    48,   224,   282,    19,   228,    19,   271,   284,  -212,
      62,   285,  -212,   283,   286,     7,   287,  -212,   293,  -212,
     288,    19,   294,  -212,  -212,    19,  -212,    19,  -212,  -212,
      -3,   296,  -212,   155,   289,  -212,   297,    19,   237,  -212,
     194,   298,  -212,  -212,    19,  -212,   299,  -212,  -212,    19,
    -212,   300,  -212,   301,  -212,  -212,  -212,   155,  -212
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     2,     1,   127,     0,   127,     0,     8,   126,
     128,     0,     9,     0,     9,   127,     3,    14,     0,     4,
       0,   129,   138,   137,   136,    15,     0,     0,    29,    49,
       0,    14,    10,     0,     0,    12,     0,     0,   145,    16,
     134,   135,     0,     0,     0,    13,     5,     0,     0,    34,
      34,     0,     0,     0,     0,     0,     0,     0,     0,    30,
       6,    50,     0,     0,   146,     0,   140,   141,     0,     0,
     123,    85,    84,    83,    91,    88,    86,    87,   122,   101,
     120,   109,   119,   113,   116,    11,   114,   115,   111,   117,
     118,   106,    98,   121,    31,     0,     0,     0,     0,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     145,   139,     0,     0,   124,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    12,     0,    38,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    47,    52,     0,   143,
     144,   147,   131,    95,   123,    90,    94,     0,    96,    97,
      99,   100,   102,   103,   104,   105,   107,   108,   110,   112,
      32,     0,     0,     0,    35,    44,    41,    39,     0,     0,
      67,    76,    77,    79,    21,    23,    19,    20,    22,    18,
       0,     0,    53,     0,     0,   142,     0,   132,     0,   125,
       0,    92,     0,    26,    17,    43,    45,     0,    38,    78,
       0,    78,     0,    29,    52,     0,    51,     0,   131,    89,
       0,     0,    44,    42,    40,    24,    37,    36,    75,     0,
       0,     0,     0,    55,     0,    72,    68,    61,     0,     0,
      54,    67,   130,   133,    93,    33,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
      78,     0,    65,     0,     0,    56,    74,    66,     0,    69,
       0,     0,     0,    48,    78,     0,    78,     0,    57,    58,
      70,     0,    29,    82,     0,    64,     0,     0,     0,    62,
       0,     0,    78,    60,     0,    73,     0,    71,    27,     0,
      81,     0,    59,     0,    78,    78,    63,    82,    80
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -212,  -212,  -212,  -212,   292,   178,  -212,   238,  -212,  -211,
     -43,   279,  -212,    99,  -212,  -212,    90,  -212,  -212,  -212,
     101,  -212,  -212,    69,  -212,  -212,   -91,  -212,  -212,     6,
    -212,    87,  -212,    78,  -212,   185,  -212,   -44,  -212,  -212,
     190,  -212,  -212,    96,   105,  -212,   162,  -212,    80,  -212,
     102,   290,   -36,  -212,  -212,   209
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     8,     2,    18,    45,    25,    26,    59,    36,
     176,    98,   177,   178,   179,   206,   207,    61,    37,   192,
     193,   252,   236,   211,   257,   278,   237,   183,   137,   293,
      78,    79,    80,    81,    82,    83,    84,   114,    86,    87,
      88,    89,    90,    91,    92,    93,   115,    10,    11,   197,
     198,    42,    27,   150,    64,    65
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      85,    62,   239,    68,    95,    69,   287,   226,   136,   116,
     117,   288,    96,    70,    60,   100,   101,   102,   103,   104,
     105,   180,    33,     9,    68,   113,    69,     4,     3,    33,
     175,    34,   112,     5,    70,     6,    12,    71,    34,    33,
       7,    14,    33,   152,   118,   228,    33,   119,    34,   181,
     227,    34,    15,    72,   148,    34,    73,    16,    71,    74,
      75,    76,    77,   145,    22,   149,    23,   146,   273,    24,
     147,   290,    17,   157,    72,    35,   182,    73,    19,   229,
      74,    75,    76,    77,    94,   108,    13,   171,   133,   172,
     230,   231,   232,    28,    33,    21,   233,    46,   234,    33,
     235,    33,   229,    34,    22,    29,    23,    33,    34,    24,
      34,   194,   195,   230,   231,   232,    34,   200,   225,   233,
     201,   234,   259,   235,    31,    47,    48,    30,    40,    49,
      41,    32,   205,    50,    51,    52,    53,    54,    38,    55,
     138,    56,    44,    57,    58,   139,   212,   140,   120,   121,
      47,    48,    66,   141,    49,    63,   220,    67,    50,    51,
      52,    53,    54,    33,    55,    33,    56,    94,    57,    58,
     254,    33,    34,   242,    34,   255,   256,    97,   194,   205,
      34,   126,   127,   283,   106,   285,   248,   130,   131,   107,
     253,   291,   292,   109,   258,   122,   123,   124,   125,   110,
     298,   300,   128,   261,   166,   167,   264,   160,   161,   142,
     268,   143,   270,   306,   307,   265,   111,   216,   162,   163,
     164,   165,   129,   158,   159,   132,   134,   281,    47,    48,
     135,   284,    49,   286,   153,   144,    50,    51,    52,    53,
      54,   154,    55,   296,    56,   155,    57,    58,   156,   170,
     301,   174,   184,   185,   186,   303,   187,   188,   189,   190,
     196,   202,   203,   191,   204,   209,   208,   213,   245,    39,
     210,   214,   215,   219,   263,   217,   218,   223,   241,   221,
     262,   247,   249,   238,   250,   266,   267,   222,   244,   269,
     251,   271,   272,   274,   276,   275,   277,   279,   297,   282,
     289,   295,   294,   302,   280,   299,    20,   224,   304,   305,
     260,   173,   246,   308,   169,   240,   199,     0,   168,   151,
     243,     0,     0,     0,    43,     0,     0,     0,     0,    99
};

static const yytype_int16 yycheck[] =
{
      44,    37,   213,     5,    47,     7,     9,    18,    99,    14,
      15,    14,    48,    15,     6,    51,    52,    53,    54,    55,
      56,     5,    15,    61,     5,    69,     7,    41,     0,    15,
       7,    24,    68,    47,    15,    49,    61,    39,    24,    15,
      54,    61,    15,    12,    18,     6,    15,    21,    24,    33,
      61,    24,    14,    55,    56,    24,    58,     4,    39,    61,
      62,    63,    64,   107,    56,   109,    58,     4,     6,    61,
       7,   282,     7,   117,    55,    61,    60,    58,     4,    40,
      61,    62,    63,    64,    61,    61,     6,   131,    61,   132,
      51,    52,    53,     5,    15,    15,    57,     6,    59,    15,
      61,    15,    40,    24,    56,     5,    58,    15,    24,    61,
      24,   147,   148,    51,    52,    53,    24,    13,   209,    57,
      16,    59,     6,    61,    10,    34,    35,    32,    61,    38,
      63,     8,   175,    42,    43,    44,    45,    46,     7,    48,
      61,    50,     9,    52,    53,    61,   190,    61,    22,    23,
      34,    35,    16,    61,    38,    61,   200,    25,    42,    43,
      44,    45,    46,    15,    48,    15,    50,    61,    52,    53,
       9,    15,    24,   217,    24,    14,    15,    17,   214,   222,
      24,    28,    29,   274,     7,   276,   230,    14,    15,     7,
     234,    36,    37,     9,   238,    24,    25,    26,    27,    10,
       6,   292,    30,   247,   126,   127,   250,   120,   121,    61,
     254,    61,   256,   304,   305,   251,     8,    61,   122,   123,
     124,   125,    31,   118,   119,    11,    61,   271,    34,    35,
       7,   275,    38,   277,     8,    61,    42,    43,    44,    45,
      46,    10,    48,   287,    50,    16,    52,    53,    61,    61,
     294,    17,     4,     4,     4,   299,     4,     4,     4,    12,
      61,    16,     4,     8,     4,     8,    10,     5,    61,    31,
      11,    10,     8,     6,    61,    12,    10,     8,     5,    14,
       4,     7,     7,    13,     7,    61,     4,    19,    16,    61,
      12,    20,     8,     8,     8,    12,     9,     4,    61,     5,
       4,     4,    13,     4,    16,     7,    14,   208,     8,     8,
     241,   133,   222,   307,   129,   214,   154,    -1,   128,   110,
     218,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    66,    68,     0,    41,    47,    49,    54,    67,    61,
     112,   113,    61,   113,    61,    14,     4,     7,    69,     4,
      69,   113,    56,    58,    61,    71,    72,   117,     5,     5,
      32,    10,     8,    15,    24,    61,    74,    83,     7,    72,
      61,    63,   116,   116,     9,    70,     6,    34,    35,    38,
      42,    43,    44,    45,    46,    48,    50,    52,    53,    73,
       6,    82,   117,    61,   119,   120,    16,    25,     5,     7,
      15,    39,    55,    58,    61,    62,    63,    64,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    61,    75,   117,    17,    76,    76,
     117,   117,   117,   117,   117,   117,     7,     7,    61,     9,
      10,     8,   117,   102,   102,   111,    14,    15,    18,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      14,    15,    11,    61,    61,     7,    91,    93,    61,    61,
      61,    61,    61,    61,    61,   102,     4,     7,    56,   102,
     118,   120,    12,     8,    10,    16,    61,   102,   109,   109,
      96,    96,   108,   108,   108,   108,    98,    98,   105,   100,
      61,   102,    75,    70,    17,     7,    75,    77,    78,    79,
       5,    33,    60,    92,     4,     4,     4,     4,     4,     4,
      12,     8,    84,    85,   117,   117,    61,   114,   115,   111,
      13,    16,    16,     4,     4,    75,    80,    81,    10,     8,
      11,    88,   102,     5,    10,     8,    61,    12,    10,     6,
     102,    14,    19,     8,    78,    91,    18,    61,     6,    40,
      51,    52,    53,    57,    59,    61,    87,    91,    13,    74,
      85,     5,   102,   115,    16,    61,    81,     7,   102,     7,
       7,    12,    86,   102,     9,    14,    15,    89,   102,     6,
      88,   102,     4,    61,   102,   117,    61,     4,   102,    61,
     102,    20,     8,     6,     8,    12,     8,     9,    90,     4,
      16,   102,     5,    91,   102,    91,   102,     9,    14,     4,
      74,    36,    37,    94,    13,     4,   102,    61,     6,     7,
      91,   102,     4,   102,     8,     8,    91,    91,    94
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    67,    67,    67,    68,    68,    69,
      69,    70,    70,    71,    72,    72,    72,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    74,
      74,    75,    75,    75,    76,    76,    77,    77,    78,    78,
      78,    79,    79,    80,    81,    81,    81,    82,    82,    83,
      83,    84,    85,    85,    85,    86,    86,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    88,    88,    89,
      89,    89,    89,    90,    90,    91,    92,    92,    93,    93,
      94,    94,    94,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    96,    96,    96,    97,
      97,    97,    98,    98,    98,    98,    98,    99,    99,    99,
     100,   100,   101,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   111,   111,   112,   113,   113,   113,
     114,   115,   115,   115,   116,   116,   117,   117,   117,   117,
     117,   117,   118,   118,   119,   120,   120,   120
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
       6,     2,     0,     1,     1,     1,     1,     1,     1,     5,
       3,     1,     4,     6,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     3,     1,     0,     1,     3,
       3,     0,     1,     3,     1,     1,     1,     1,     1,     5,
       4,     4,     2,     1,     3,     0,     1,     3
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
#line 1523 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.package_) = new PDefs((yyvsp[0].listdef_)); (yyval.package_)->line_number = yy_mylinenumber; YY_RESULT_Package_= (yyval.package_); }
#line 2884 "Parser.C" /* yacc.c:1646  */
    break;

  case 3:
#line 1525 "spatialc.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-1].listpackagename_)->begin(),(yyvsp[-1].listpackagename_)->end()) ;(yyval.def_) = new DefImport((yyvsp[-1].listpackagename_)); (yyval.def_)->line_number = yy_mylinenumber;  }
#line 2890 "Parser.C" /* yacc.c:1646  */
    break;

  case 4:
#line 1526 "spatialc.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-1].listpackagename_)->begin(),(yyvsp[-1].listpackagename_)->end()) ;(yyval.def_) = new DefPackage((yyvsp[-1].listpackagename_)); (yyval.def_)->line_number = yy_mylinenumber;  }
#line 2896 "Parser.C" /* yacc.c:1646  */
    break;

  case 5:
#line 1527 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.def_) = new DefModule((yyvsp[-4].string_), (yyvsp[-3].metaparamdecl_), (yyvsp[-1].listmoddef_)); (yyval.def_)->line_number = yy_mylinenumber;  }
#line 2902 "Parser.C" /* yacc.c:1646  */
    break;

  case 6:
#line 1528 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.def_) = new DefStruct((yyvsp[-4].string_), (yyvsp[-3].metaparamdecl_), (yyvsp[-1].liststructdef_)); (yyval.def_)->line_number = yy_mylinenumber;  }
#line 2908 "Parser.C" /* yacc.c:1646  */
    break;

  case 7:
#line 1530 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listdef_) = new ListDef();  }
#line 2914 "Parser.C" /* yacc.c:1646  */
    break;

  case 8:
#line 1531 "spatialc.y" /* yacc.c:1646  */
    {  (yyvsp[-1].listdef_)->push_back((yyvsp[0].def_)) ; (yyval.listdef_) = (yyvsp[-1].listdef_) ;  }
#line 2920 "Parser.C" /* yacc.c:1646  */
    break;

  case 9:
#line 1533 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.metaparamdecl_) = new NoParams(); (yyval.metaparamdecl_)->line_number = yy_mylinenumber;  }
#line 2926 "Parser.C" /* yacc.c:1646  */
    break;

  case 10:
#line 1534 "spatialc.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-1].listmetaparam_)->begin(),(yyvsp[-1].listmetaparam_)->end()) ;(yyval.metaparamdecl_) = new SomeParams((yyvsp[-1].listmetaparam_)); (yyval.metaparamdecl_)->line_number = yy_mylinenumber;  }
#line 2932 "Parser.C" /* yacc.c:1646  */
    break;

  case 11:
#line 1536 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.optionaleqexp_) = new EqExp((yyvsp[0].exp_)); (yyval.optionaleqexp_)->line_number = yy_mylinenumber;  }
#line 2938 "Parser.C" /* yacc.c:1646  */
    break;

  case 12:
#line 1537 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.optionaleqexp_) = new NoEqExp(); (yyval.optionaleqexp_)->line_number = yy_mylinenumber;  }
#line 2944 "Parser.C" /* yacc.c:1646  */
    break;

  case 13:
#line 1539 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.metaparam_) = new MetaParam1((yyvsp[-2].type_), (yyvsp[-1].string_), (yyvsp[0].optionaleqexp_)); (yyval.metaparam_)->line_number = yy_mylinenumber;  }
#line 2950 "Parser.C" /* yacc.c:1646  */
    break;

  case 14:
#line 1541 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listmetaparam_) = new ListMetaParam();  }
#line 2956 "Parser.C" /* yacc.c:1646  */
    break;

  case 15:
#line 1542 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listmetaparam_) = new ListMetaParam() ; (yyval.listmetaparam_)->push_back((yyvsp[0].metaparam_));  }
#line 2962 "Parser.C" /* yacc.c:1646  */
    break;

  case 16:
#line 1543 "spatialc.y" /* yacc.c:1646  */
    {  (yyvsp[0].listmetaparam_)->push_back((yyvsp[-2].metaparam_)) ; (yyval.listmetaparam_) = (yyvsp[0].listmetaparam_) ;  }
#line 2968 "Parser.C" /* yacc.c:1646  */
    break;

  case 17:
#line 1545 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.moddef_) = new DefConst((yyvsp[-3].type_), (yyvsp[-2].string_), (yyvsp[-1].optionaleqexp_)); (yyval.moddef_)->line_number = yy_mylinenumber;  }
#line 2974 "Parser.C" /* yacc.c:1646  */
    break;

  case 18:
#line 1546 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.moddef_) = new DefReg((yyvsp[-2].type_), (yyvsp[-1].string_)); (yyval.moddef_)->line_number = yy_mylinenumber;  }
#line 2980 "Parser.C" /* yacc.c:1646  */
    break;

  case 19:
#line 1547 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.moddef_) = new DefMem((yyvsp[-2].type_), (yyvsp[-1].string_)); (yyval.moddef_)->line_number = yy_mylinenumber;  }
#line 2986 "Parser.C" /* yacc.c:1646  */
    break;

  case 20:
#line 1548 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.moddef_) = new DefSubmodule((yyvsp[-2].type_), (yyvsp[-1].string_)); (yyval.moddef_)->line_number = yy_mylinenumber;  }
#line 2992 "Parser.C" /* yacc.c:1646  */
    break;

  case 21:
#line 1549 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.moddef_) = new DefInput((yyvsp[-2].type_), (yyvsp[-1].string_)); (yyval.moddef_)->line_number = yy_mylinenumber;  }
#line 2998 "Parser.C" /* yacc.c:1646  */
    break;

  case 22:
#line 1550 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.moddef_) = new DefOutput((yyvsp[-2].type_), (yyvsp[-1].string_)); (yyval.moddef_)->line_number = yy_mylinenumber;  }
#line 3004 "Parser.C" /* yacc.c:1646  */
    break;

  case 23:
#line 1551 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.moddef_) = new DefInternal((yyvsp[-2].type_), (yyvsp[-1].string_)); (yyval.moddef_)->line_number = yy_mylinenumber;  }
#line 3010 "Parser.C" /* yacc.c:1646  */
    break;

  case 24:
#line 1552 "spatialc.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-2].listeventparam_)->begin(),(yyvsp[-2].listeventparam_)->end()) ;(yyval.moddef_) = new DefEvent((yyvsp[-4].eventname_), (yyvsp[-2].listeventparam_), (yyvsp[0].block_)); (yyval.moddef_)->line_number = yy_mylinenumber;  }
#line 3016 "Parser.C" /* yacc.c:1646  */
    break;

  case 25:
#line 1553 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.moddef_) = new DefInit((yyvsp[-1].eventname_), (yyvsp[0].block_)); (yyval.moddef_)->line_number = yy_mylinenumber;  }
#line 3022 "Parser.C" /* yacc.c:1646  */
    break;

  case 26:
#line 1554 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.moddef_) = new DefConnect((yyvsp[-3].channelspecifier_), (yyvsp[-1].channelspecifier_)); (yyval.moddef_)->line_number = yy_mylinenumber;  }
#line 3028 "Parser.C" /* yacc.c:1646  */
    break;

  case 27:
#line 1555 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.moddef_) = new DefFor((yyvsp[-8].string_), (yyvsp[-6].exp_), (yyvsp[-4].exp_), (yyvsp[-1].listmoddef_)); (yyval.moddef_)->line_number = yy_mylinenumber;  }
#line 3034 "Parser.C" /* yacc.c:1646  */
    break;

  case 28:
#line 1556 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.moddef_) = new DefIf((yyvsp[-4].exp_), (yyvsp[-1].listmoddef_)); (yyval.moddef_)->line_number = yy_mylinenumber;  }
#line 3040 "Parser.C" /* yacc.c:1646  */
    break;

  case 29:
#line 1558 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listmoddef_) = new ListModDef();  }
#line 3046 "Parser.C" /* yacc.c:1646  */
    break;

  case 30:
#line 1559 "spatialc.y" /* yacc.c:1646  */
    {  (yyvsp[-1].listmoddef_)->push_back((yyvsp[0].moddef_)) ; (yyval.listmoddef_) = (yyvsp[-1].listmoddef_) ;  }
#line 3052 "Parser.C" /* yacc.c:1646  */
    break;

  case 31:
#line 1561 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.channelspecifier_) = new SimpleCS((yyvsp[0].string_)); (yyval.channelspecifier_)->line_number = yy_mylinenumber;  }
#line 3058 "Parser.C" /* yacc.c:1646  */
    break;

  case 32:
#line 1562 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.channelspecifier_) = new DotCS((yyvsp[-2].string_), (yyvsp[0].string_)); (yyval.channelspecifier_)->line_number = yy_mylinenumber;  }
#line 3064 "Parser.C" /* yacc.c:1646  */
    break;

  case 33:
#line 1563 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.channelspecifier_) = new ArrayDotCS((yyvsp[-5].string_), (yyvsp[-3].exp_), (yyvsp[0].string_)); (yyval.channelspecifier_)->line_number = yy_mylinenumber;  }
#line 3070 "Parser.C" /* yacc.c:1646  */
    break;

  case 34:
#line 1565 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.eventname_) = new NoEvName(); (yyval.eventname_)->line_number = yy_mylinenumber;  }
#line 3076 "Parser.C" /* yacc.c:1646  */
    break;

  case 35:
#line 1566 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.eventname_) = new EvName((yyvsp[-1].string_)); (yyval.eventname_)->line_number = yy_mylinenumber;  }
#line 3082 "Parser.C" /* yacc.c:1646  */
    break;

  case 36:
#line 1568 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.eventparam_) = new EventParamWithName((yyvsp[-2].eventorcond_), (yyvsp[0].string_)); (yyval.eventparam_)->line_number = yy_mylinenumber;  }
#line 3088 "Parser.C" /* yacc.c:1646  */
    break;

  case 37:
#line 1569 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.eventparam_) = new EventParamNoName((yyvsp[-2].eventorcond_)); (yyval.eventparam_)->line_number = yy_mylinenumber;  }
#line 3094 "Parser.C" /* yacc.c:1646  */
    break;

  case 38:
#line 1571 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listeventparam_) = new ListEventParam();  }
#line 3100 "Parser.C" /* yacc.c:1646  */
    break;

  case 39:
#line 1572 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listeventparam_) = new ListEventParam() ; (yyval.listeventparam_)->push_back((yyvsp[0].eventparam_));  }
#line 3106 "Parser.C" /* yacc.c:1646  */
    break;

  case 40:
#line 1573 "spatialc.y" /* yacc.c:1646  */
    {  (yyvsp[0].listeventparam_)->push_back((yyvsp[-2].eventparam_)) ; (yyval.listeventparam_) = (yyvsp[0].listeventparam_) ;  }
#line 3112 "Parser.C" /* yacc.c:1646  */
    break;

  case 41:
#line 1575 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.eventorcond_) = new CSEventCond((yyvsp[0].channelspecifier_)); (yyval.eventorcond_)->line_number = yy_mylinenumber;  }
#line 3118 "Parser.C" /* yacc.c:1646  */
    break;

  case 42:
#line 1576 "spatialc.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-1].listeventorlist_)->begin(),(yyvsp[-1].listeventorlist_)->end()) ;(yyval.eventorcond_) = new ListEvOr((yyvsp[-1].listeventorlist_)); (yyval.eventorcond_)->line_number = yy_mylinenumber;  }
#line 3124 "Parser.C" /* yacc.c:1646  */
    break;

  case 43:
#line 1578 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.eventorlist_) = new EventOrListChannelSpecifier((yyvsp[0].channelspecifier_)); (yyval.eventorlist_)->line_number = yy_mylinenumber;  }
#line 3130 "Parser.C" /* yacc.c:1646  */
    break;

  case 44:
#line 1580 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listeventorlist_) = new ListEventOrList();  }
#line 3136 "Parser.C" /* yacc.c:1646  */
    break;

  case 45:
#line 1581 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listeventorlist_) = new ListEventOrList() ; (yyval.listeventorlist_)->push_back((yyvsp[0].eventorlist_));  }
#line 3142 "Parser.C" /* yacc.c:1646  */
    break;

  case 46:
#line 1582 "spatialc.y" /* yacc.c:1646  */
    {  (yyvsp[0].listeventorlist_)->push_back((yyvsp[-2].eventorlist_)) ; (yyval.listeventorlist_) = (yyvsp[0].listeventorlist_) ;  }
#line 3148 "Parser.C" /* yacc.c:1646  */
    break;

  case 47:
#line 1584 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.structdef_) = new DefSubstor((yyvsp[-2].type_), (yyvsp[-1].string_)); (yyval.structdef_)->line_number = yy_mylinenumber;  }
#line 3154 "Parser.C" /* yacc.c:1646  */
    break;

  case 48:
#line 1585 "spatialc.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-4].listfuncparam_)->begin(),(yyvsp[-4].listfuncparam_)->end()) ;(yyval.structdef_) = new DefFunction((yyvsp[-7].type_), (yyvsp[-6].string_), (yyvsp[-4].listfuncparam_), (yyvsp[-1].liststatement_)); (yyval.structdef_)->line_number = yy_mylinenumber;  }
#line 3160 "Parser.C" /* yacc.c:1646  */
    break;

  case 49:
#line 1587 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.liststructdef_) = new ListStructDef();  }
#line 3166 "Parser.C" /* yacc.c:1646  */
    break;

  case 50:
#line 1588 "spatialc.y" /* yacc.c:1646  */
    {  (yyvsp[-1].liststructdef_)->push_back((yyvsp[0].structdef_)) ; (yyval.liststructdef_) = (yyvsp[-1].liststructdef_) ;  }
#line 3172 "Parser.C" /* yacc.c:1646  */
    break;

  case 51:
#line 1590 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.funcparam_) = new FuncParam1((yyvsp[-1].type_), (yyvsp[0].string_)); (yyval.funcparam_)->line_number = yy_mylinenumber;  }
#line 3178 "Parser.C" /* yacc.c:1646  */
    break;

  case 52:
#line 1592 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listfuncparam_) = new ListFuncParam();  }
#line 3184 "Parser.C" /* yacc.c:1646  */
    break;

  case 53:
#line 1593 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listfuncparam_) = new ListFuncParam() ; (yyval.listfuncparam_)->push_back((yyvsp[0].funcparam_));  }
#line 3190 "Parser.C" /* yacc.c:1646  */
    break;

  case 54:
#line 1594 "spatialc.y" /* yacc.c:1646  */
    {  (yyvsp[0].listfuncparam_)->push_back((yyvsp[-2].funcparam_)) ; (yyval.listfuncparam_) = (yyvsp[0].listfuncparam_) ;  }
#line 3196 "Parser.C" /* yacc.c:1646  */
    break;

  case 55:
#line 1596 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.optionaltype_) = new NoType(); (yyval.optionaltype_)->line_number = yy_mylinenumber;  }
#line 3202 "Parser.C" /* yacc.c:1646  */
    break;

  case 56:
#line 1597 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.optionaltype_) = new TypeSpec((yyvsp[0].type_)); (yyval.optionaltype_)->line_number = yy_mylinenumber;  }
#line 3208 "Parser.C" /* yacc.c:1646  */
    break;

  case 57:
#line 1599 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.statement_) = new VarStmt((yyvsp[-2].optionaltype_), (yyvsp[-1].string_), (yyvsp[0].varassignment_)); (yyval.statement_)->line_number = yy_mylinenumber;  }
#line 3214 "Parser.C" /* yacc.c:1646  */
    break;

  case 58:
#line 1600 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.statement_) = new AssignStmt((yyvsp[-3].string_), (yyvsp[-1].exp_)); (yyval.statement_)->line_number = yy_mylinenumber;  }
#line 3220 "Parser.C" /* yacc.c:1646  */
    break;

  case 59:
#line 1601 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.statement_) = new AssignArrStmt((yyvsp[-6].string_), (yyvsp[-4].exp_), (yyvsp[-1].exp_)); (yyval.statement_)->line_number = yy_mylinenumber;  }
#line 3226 "Parser.C" /* yacc.c:1646  */
    break;

  case 60:
#line 1602 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.statement_) = new IfStmt((yyvsp[-3].exp_), (yyvsp[-1].block_), (yyvsp[0].elseblock_)); (yyval.statement_)->line_number = yy_mylinenumber;  }
#line 3232 "Parser.C" /* yacc.c:1646  */
    break;

  case 61:
#line 1603 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.statement_) = new BlockStmt((yyvsp[0].block_)); (yyval.statement_)->line_number = yy_mylinenumber;  }
#line 3238 "Parser.C" /* yacc.c:1646  */
    break;

  case 62:
#line 1604 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.statement_) = new PushStmt((yyvsp[-4].string_), (yyvsp[-3].pushsubdest_), (yyvsp[-1].exp_)); (yyval.statement_)->line_number = yy_mylinenumber;  }
#line 3244 "Parser.C" /* yacc.c:1646  */
    break;

  case 63:
#line 1605 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.statement_) = new StaticForStmt((yyvsp[-6].string_), (yyvsp[-4].exp_), (yyvsp[-2].exp_), (yyvsp[0].block_)); (yyval.statement_)->line_number = yy_mylinenumber;  }
#line 3250 "Parser.C" /* yacc.c:1646  */
    break;

  case 64:
#line 1606 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.statement_) = new StaticIfStmt((yyvsp[-2].exp_), (yyvsp[0].block_)); (yyval.statement_)->line_number = yy_mylinenumber;  }
#line 3256 "Parser.C" /* yacc.c:1646  */
    break;

  case 65:
#line 1607 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.statement_) = new ReturnStmt((yyvsp[-1].exp_)); (yyval.statement_)->line_number = yy_mylinenumber;  }
#line 3262 "Parser.C" /* yacc.c:1646  */
    break;

  case 66:
#line 1608 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.statement_) = new WaitUntilStmt((yyvsp[-1].exp_)); (yyval.statement_)->line_number = yy_mylinenumber;  }
#line 3268 "Parser.C" /* yacc.c:1646  */
    break;

  case 67:
#line 1610 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.liststatement_) = new ListStatement();  }
#line 3274 "Parser.C" /* yacc.c:1646  */
    break;

  case 68:
#line 1611 "spatialc.y" /* yacc.c:1646  */
    {  (yyvsp[-1].liststatement_)->push_back((yyvsp[0].statement_)) ; (yyval.liststatement_) = (yyvsp[-1].liststatement_) ;  }
#line 3280 "Parser.C" /* yacc.c:1646  */
    break;

  case 69:
#line 1613 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.pushsubdest_) = new PushSubreg((yyvsp[0].string_)); (yyval.pushsubdest_)->line_number = yy_mylinenumber;  }
#line 3286 "Parser.C" /* yacc.c:1646  */
    break;

  case 70:
#line 1614 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.pushsubdest_) = new PushArray((yyvsp[-1].exp_)); (yyval.pushsubdest_)->line_number = yy_mylinenumber;  }
#line 3292 "Parser.C" /* yacc.c:1646  */
    break;

  case 71:
#line 1615 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.pushsubdest_) = new PushArrayDot((yyvsp[-3].exp_), (yyvsp[0].string_)); (yyval.pushsubdest_)->line_number = yy_mylinenumber;  }
#line 3298 "Parser.C" /* yacc.c:1646  */
    break;

  case 72:
#line 1616 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.pushsubdest_) = new PushReg(); (yyval.pushsubdest_)->line_number = yy_mylinenumber;  }
#line 3304 "Parser.C" /* yacc.c:1646  */
    break;

  case 73:
#line 1618 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.varassignment_) = new VarAssign((yyvsp[-1].exp_)); (yyval.varassignment_)->line_number = yy_mylinenumber;  }
#line 3310 "Parser.C" /* yacc.c:1646  */
    break;

  case 74:
#line 1619 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.varassignment_) = new NoVarAssign(); (yyval.varassignment_)->line_number = yy_mylinenumber;  }
#line 3316 "Parser.C" /* yacc.c:1646  */
    break;

  case 75:
#line 1621 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.block_) = new Block1((yyvsp[-3].listblockattr_), (yyvsp[-1].liststatement_)); (yyval.block_)->line_number = yy_mylinenumber;  }
#line 3322 "Parser.C" /* yacc.c:1646  */
    break;

  case 76:
#line 1623 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.blockattr_) = new BlockAttr_atomic(); (yyval.blockattr_)->line_number = yy_mylinenumber;  }
#line 3328 "Parser.C" /* yacc.c:1646  */
    break;

  case 77:
#line 1624 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.blockattr_) = new BlockAttr_xact(); (yyval.blockattr_)->line_number = yy_mylinenumber;  }
#line 3334 "Parser.C" /* yacc.c:1646  */
    break;

  case 78:
#line 1626 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listblockattr_) = new ListBlockAttr();  }
#line 3340 "Parser.C" /* yacc.c:1646  */
    break;

  case 79:
#line 1627 "spatialc.y" /* yacc.c:1646  */
    {  (yyvsp[-1].listblockattr_)->push_back((yyvsp[0].blockattr_)) ; (yyval.listblockattr_) = (yyvsp[-1].listblockattr_) ;  }
#line 3346 "Parser.C" /* yacc.c:1646  */
    break;

  case 80:
#line 1629 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.elseblock_) = new ElseIf((yyvsp[-3].exp_), (yyvsp[-1].block_), (yyvsp[0].elseblock_)); (yyval.elseblock_)->line_number = yy_mylinenumber;  }
#line 3352 "Parser.C" /* yacc.c:1646  */
    break;

  case 81:
#line 1630 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.elseblock_) = new Else((yyvsp[0].block_)); (yyval.elseblock_)->line_number = yy_mylinenumber;  }
#line 3358 "Parser.C" /* yacc.c:1646  */
    break;

  case 82:
#line 1631 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.elseblock_) = new NoElse(); (yyval.elseblock_)->line_number = yy_mylinenumber;  }
#line 3364 "Parser.C" /* yacc.c:1646  */
    break;

  case 83:
#line 1633 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EVoid(); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3370 "Parser.C" /* yacc.c:1646  */
    break;

  case 84:
#line 1634 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new ETrue(); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3376 "Parser.C" /* yacc.c:1646  */
    break;

  case 85:
#line 1635 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EFalse(); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3382 "Parser.C" /* yacc.c:1646  */
    break;

  case 86:
#line 1636 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EInt((yyvsp[0].int_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3388 "Parser.C" /* yacc.c:1646  */
    break;

  case 87:
#line 1637 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EDouble((yyvsp[0].double_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3394 "Parser.C" /* yacc.c:1646  */
    break;

  case 88:
#line 1638 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EString((yyvsp[0].string_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3400 "Parser.C" /* yacc.c:1646  */
    break;

  case 89:
#line 1639 "spatialc.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-1].liststructliteralfield_)->begin(),(yyvsp[-1].liststructliteralfield_)->end()) ;(yyval.exp_) = new EStructLiteral((yyvsp[-3].type_), (yyvsp[-1].liststructliteralfield_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3406 "Parser.C" /* yacc.c:1646  */
    break;

  case 90:
#line 1640 "spatialc.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-1].listexp_)->begin(),(yyvsp[-1].listexp_)->end()) ;(yyval.exp_) = new EVectorLiteral((yyvsp[-1].listexp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3412 "Parser.C" /* yacc.c:1646  */
    break;

  case 91:
#line 1641 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EId((yyvsp[0].string_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3418 "Parser.C" /* yacc.c:1646  */
    break;

  case 92:
#line 1642 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EArrAcc((yyvsp[-3].exp_), (yyvsp[-1].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3424 "Parser.C" /* yacc.c:1646  */
    break;

  case 93:
#line 1643 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new ESlice((yyvsp[-5].exp_), (yyvsp[-3].exp_), (yyvsp[-1].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3430 "Parser.C" /* yacc.c:1646  */
    break;

  case 94:
#line 1644 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EDot((yyvsp[-2].exp_), (yyvsp[0].string_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3436 "Parser.C" /* yacc.c:1646  */
    break;

  case 95:
#line 1645 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[-1].exp_);  }
#line 3442 "Parser.C" /* yacc.c:1646  */
    break;

  case 96:
#line 1647 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new ETimes((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3448 "Parser.C" /* yacc.c:1646  */
    break;

  case 97:
#line 1648 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EDiv((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3454 "Parser.C" /* yacc.c:1646  */
    break;

  case 98:
#line 1649 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3460 "Parser.C" /* yacc.c:1646  */
    break;

  case 99:
#line 1651 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EPlus((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3466 "Parser.C" /* yacc.c:1646  */
    break;

  case 100:
#line 1652 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EMinus((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3472 "Parser.C" /* yacc.c:1646  */
    break;

  case 101:
#line 1653 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3478 "Parser.C" /* yacc.c:1646  */
    break;

  case 102:
#line 1655 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new ELt((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3484 "Parser.C" /* yacc.c:1646  */
    break;

  case 103:
#line 1656 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EGt((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3490 "Parser.C" /* yacc.c:1646  */
    break;

  case 104:
#line 1657 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new ELtEq((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3496 "Parser.C" /* yacc.c:1646  */
    break;

  case 105:
#line 1658 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EGtEq((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3502 "Parser.C" /* yacc.c:1646  */
    break;

  case 106:
#line 1659 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3508 "Parser.C" /* yacc.c:1646  */
    break;

  case 107:
#line 1661 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EEq((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3514 "Parser.C" /* yacc.c:1646  */
    break;

  case 108:
#line 1662 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new ENEq((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3520 "Parser.C" /* yacc.c:1646  */
    break;

  case 109:
#line 1663 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3526 "Parser.C" /* yacc.c:1646  */
    break;

  case 110:
#line 1665 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EAnd((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3532 "Parser.C" /* yacc.c:1646  */
    break;

  case 111:
#line 1666 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3538 "Parser.C" /* yacc.c:1646  */
    break;

  case 112:
#line 1668 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = new EOr((yyvsp[-2].exp_), (yyvsp[0].exp_)); (yyval.exp_)->line_number = yy_mylinenumber;  }
#line 3544 "Parser.C" /* yacc.c:1646  */
    break;

  case 113:
#line 1669 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3550 "Parser.C" /* yacc.c:1646  */
    break;

  case 114:
#line 1671 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3556 "Parser.C" /* yacc.c:1646  */
    break;

  case 115:
#line 1673 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3562 "Parser.C" /* yacc.c:1646  */
    break;

  case 116:
#line 1675 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3568 "Parser.C" /* yacc.c:1646  */
    break;

  case 117:
#line 1677 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3574 "Parser.C" /* yacc.c:1646  */
    break;

  case 118:
#line 1679 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3580 "Parser.C" /* yacc.c:1646  */
    break;

  case 119:
#line 1681 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3586 "Parser.C" /* yacc.c:1646  */
    break;

  case 120:
#line 1683 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3592 "Parser.C" /* yacc.c:1646  */
    break;

  case 121:
#line 1685 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3598 "Parser.C" /* yacc.c:1646  */
    break;

  case 122:
#line 1687 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.exp_) = (yyvsp[0].exp_);  }
#line 3604 "Parser.C" /* yacc.c:1646  */
    break;

  case 123:
#line 1689 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listexp_) = new ListExp();  }
#line 3610 "Parser.C" /* yacc.c:1646  */
    break;

  case 124:
#line 1690 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listexp_) = new ListExp() ; (yyval.listexp_)->push_back((yyvsp[0].exp_));  }
#line 3616 "Parser.C" /* yacc.c:1646  */
    break;

  case 125:
#line 1691 "spatialc.y" /* yacc.c:1646  */
    {  (yyvsp[0].listexp_)->push_back((yyvsp[-2].exp_)) ; (yyval.listexp_) = (yyvsp[0].listexp_) ;  }
#line 3622 "Parser.C" /* yacc.c:1646  */
    break;

  case 126:
#line 1693 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.packagename_) = new PackageNameId((yyvsp[0].string_)); (yyval.packagename_)->line_number = yy_mylinenumber;  }
#line 3628 "Parser.C" /* yacc.c:1646  */
    break;

  case 127:
#line 1695 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listpackagename_) = new ListPackageName();  }
#line 3634 "Parser.C" /* yacc.c:1646  */
    break;

  case 128:
#line 1696 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listpackagename_) = new ListPackageName() ; (yyval.listpackagename_)->push_back((yyvsp[0].packagename_));  }
#line 3640 "Parser.C" /* yacc.c:1646  */
    break;

  case 129:
#line 1697 "spatialc.y" /* yacc.c:1646  */
    {  (yyvsp[0].listpackagename_)->push_back((yyvsp[-2].packagename_)) ; (yyval.listpackagename_) = (yyvsp[0].listpackagename_) ;  }
#line 3646 "Parser.C" /* yacc.c:1646  */
    break;

  case 130:
#line 1699 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.structliteralfield_) = new StructLiteralField1((yyvsp[-2].string_), (yyvsp[0].exp_)); (yyval.structliteralfield_)->line_number = yy_mylinenumber;  }
#line 3652 "Parser.C" /* yacc.c:1646  */
    break;

  case 131:
#line 1701 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.liststructliteralfield_) = new ListStructLiteralField();  }
#line 3658 "Parser.C" /* yacc.c:1646  */
    break;

  case 132:
#line 1702 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.liststructliteralfield_) = new ListStructLiteralField() ; (yyval.liststructliteralfield_)->push_back((yyvsp[0].structliteralfield_));  }
#line 3664 "Parser.C" /* yacc.c:1646  */
    break;

  case 133:
#line 1703 "spatialc.y" /* yacc.c:1646  */
    {  (yyvsp[0].liststructliteralfield_)->push_back((yyvsp[-2].structliteralfield_)) ; (yyval.liststructliteralfield_) = (yyvsp[0].liststructliteralfield_) ;  }
#line 3670 "Parser.C" /* yacc.c:1646  */
    break;

  case 134:
#line 1705 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.intorname_) = new ConstName((yyvsp[0].string_)); (yyval.intorname_)->line_number = yy_mylinenumber;  }
#line 3676 "Parser.C" /* yacc.c:1646  */
    break;

  case 135:
#line 1706 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.intorname_) = new Int((yyvsp[0].int_)); (yyval.intorname_)->line_number = yy_mylinenumber;  }
#line 3682 "Parser.C" /* yacc.c:1646  */
    break;

  case 136:
#line 1708 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.type_) = new TyName((yyvsp[0].string_)); (yyval.type_)->line_number = yy_mylinenumber;  }
#line 3688 "Parser.C" /* yacc.c:1646  */
    break;

  case 137:
#line 1709 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.type_) = new TyVoid(); (yyval.type_)->line_number = yy_mylinenumber;  }
#line 3694 "Parser.C" /* yacc.c:1646  */
    break;

  case 138:
#line 1710 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.type_) = new TyType(); (yyval.type_)->line_number = yy_mylinenumber;  }
#line 3700 "Parser.C" /* yacc.c:1646  */
    break;

  case 139:
#line 1711 "spatialc.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-1].listtemplatearg_)->begin(),(yyvsp[-1].listtemplatearg_)->end()) ;(yyval.type_) = new TyNameParams((yyvsp[-4].string_), (yyvsp[-1].listtemplatearg_)); (yyval.type_)->line_number = yy_mylinenumber;  }
#line 3706 "Parser.C" /* yacc.c:1646  */
    break;

  case 140:
#line 1712 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.type_) = new TyArray((yyvsp[-3].type_), (yyvsp[-1].intorname_)); (yyval.type_)->line_number = yy_mylinenumber;  }
#line 3712 "Parser.C" /* yacc.c:1646  */
    break;

  case 141:
#line 1713 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.type_) = new TyVector((yyvsp[-3].type_), (yyvsp[-1].intorname_)); (yyval.type_)->line_number = yy_mylinenumber;  }
#line 3718 "Parser.C" /* yacc.c:1646  */
    break;

  case 142:
#line 1715 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.templateexp_) = new TEType((yyvsp[0].type_)); (yyval.templateexp_)->line_number = yy_mylinenumber;  }
#line 3724 "Parser.C" /* yacc.c:1646  */
    break;

  case 143:
#line 1716 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.templateexp_) = new TEConstExp((yyvsp[0].exp_)); (yyval.templateexp_)->line_number = yy_mylinenumber;  }
#line 3730 "Parser.C" /* yacc.c:1646  */
    break;

  case 144:
#line 1718 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.templatearg_) = new TemplateArg1((yyvsp[-2].string_), (yyvsp[0].templateexp_)); (yyval.templatearg_)->line_number = yy_mylinenumber;  }
#line 3736 "Parser.C" /* yacc.c:1646  */
    break;

  case 145:
#line 1720 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listtemplatearg_) = new ListTemplateArg();  }
#line 3742 "Parser.C" /* yacc.c:1646  */
    break;

  case 146:
#line 1721 "spatialc.y" /* yacc.c:1646  */
    {  (yyval.listtemplatearg_) = new ListTemplateArg() ; (yyval.listtemplatearg_)->push_back((yyvsp[0].templatearg_));  }
#line 3748 "Parser.C" /* yacc.c:1646  */
    break;

  case 147:
#line 1722 "spatialc.y" /* yacc.c:1646  */
    {  (yyvsp[0].listtemplatearg_)->push_back((yyvsp[-2].templatearg_)) ; (yyval.listtemplatearg_) = (yyvsp[0].listtemplatearg_) ;  }
#line 3754 "Parser.C" /* yacc.c:1646  */
    break;


#line 3758 "Parser.C" /* yacc.c:1646  */
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
