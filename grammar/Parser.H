#ifndef PARSER_HEADER_FILE
#define PARSER_HEADER_FILE

#include<vector>
#include<string>


class Package;
class Def;
class ListDef;
class MetaParamDecl;
class OptionalEqExp;
class MetaParam;
class ListMetaParam;
class ModDef;
class ListModDef;
class ChannelSpecifier;
class EventName;
class EventParam;
class ListEventParam;
class EventOrCond;
class EventOrList;
class ListEventOrList;
class StructDef;
class ListStructDef;
class FuncParam;
class ListFuncParam;
class OptionalType;
class Statement;
class ListStatement;
class PushSubDest;
class VarAssignment;
class Block;
class BlockAttr;
class ListBlockAttr;
class ElseBlock;
class Exp;
class ListExp;
class PackageName;
class ListPackageName;
class StructLiteralField;
class ListStructLiteralField;
class IntOrName;
class Type;
class TemplateExp;
class TemplateArg;
class ListTemplateArg;

typedef union
{
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
} YYSTYPE;

Package* pPackage(FILE *inp);
Package* pPackage(const char *str);



#define _ERROR_ 258
#define _SYMB_0 259
#define _SYMB_1 260
#define _SYMB_2 261
#define _SYMB_3 262
#define _SYMB_4 263
#define _SYMB_5 264
#define _SYMB_6 265
#define _SYMB_7 266
#define _SYMB_8 267
#define _SYMB_9 268
#define _SYMB_10 269
#define _SYMB_11 270
#define _SYMB_12 271
#define _SYMB_13 272
#define _SYMB_14 273
#define _SYMB_15 274
#define _SYMB_16 275
#define _SYMB_17 276
#define _SYMB_18 277
#define _SYMB_19 278
#define _SYMB_20 279
#define _SYMB_21 280
#define _SYMB_22 281
#define _SYMB_23 282
#define _SYMB_24 283
#define _SYMB_25 284
#define _SYMB_26 285
#define _SYMB_27 286
#define _SYMB_28 287
#define _SYMB_29 288
#define _SYMB_30 289
#define _SYMB_31 290
#define _SYMB_32 291
#define _SYMB_33 292
#define _SYMB_34 293
#define _SYMB_35 294
#define _SYMB_36 295
#define _SYMB_37 296
#define _SYMB_38 297
#define _SYMB_39 298
#define _SYMB_40 299
#define _SYMB_41 300
#define _SYMB_42 301
#define _SYMB_43 302
#define _SYMB_44 303
#define _SYMB_45 304
#define _SYMB_46 305
#define _SYMB_47 306
#define _SYMB_48 307
#define _SYMB_49 308
#define _SYMB_50 309
#define _SYMB_51 310
#define _SYMB_52 311
#define _SYMB_53 312
#define _SYMB_54 313
#define _SYMB_55 314
#define _SYMB_56 315
#define _SYMB_57 316
#define _SYMB_58 317
#define _SYMB_59 318
#define _SYMB_60 319
#define _SYMB_61 320
#define _SYMB_62 321
#define _SYMB_63 322
#define _SYMB_64 323
#define _SYMB_65 324
#define _STRING_ 325
#define _INTEGER_ 326
#define _DOUBLE_ 327

extern YYSTYPE yylval;

#endif
