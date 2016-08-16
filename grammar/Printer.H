#ifndef PRINTER_HEADER
#define PRINTER_HEADER

#include "Absyn.H"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* Certain applications may improve performance by changing the buffer size */
#define BUFFER_INITIAL 2000
/* You may wish to change _L_PAREN or _R_PAREN */
#define _L_PAREN '('
#define _R_PAREN ')'

class PrintAbsyn : public Visitor
{
 protected:
  int _n_, _i_;
  /* The following are simple heuristics for rendering terminals */
  /* You may wish to change them */
  void render(Char c);
  void render(String s);
void render(char *s);
  void indent(void);
  void backup(void);
 public:
  PrintAbsyn(void);
  ~PrintAbsyn(void);
  char *print(Visitable *v);

  void visitPackage(Package *p); /* abstract class */
  void visitPDefs(PDefs *p);
  void visitDef(Def *p); /* abstract class */
  void visitDefImport(DefImport *p);
  void visitDefPackage(DefPackage *p);
  void visitDefModule(DefModule *p);
  void visitDefStruct(DefStruct *p);
  void visitListDef(ListDef *p);
  void visitMetaParamDecl(MetaParamDecl *p); /* abstract class */
  void visitNoParams(NoParams *p);
  void visitSomeParams(SomeParams *p);
  void visitOptionalEqExp(OptionalEqExp *p); /* abstract class */
  void visitEqExp(EqExp *p);
  void visitNoEqExp(NoEqExp *p);
  void visitMetaParam(MetaParam *p); /* abstract class */
  void visitMetaParam1(MetaParam1 *p);
  void visitListMetaParam(ListMetaParam *p);
  void visitModDef(ModDef *p); /* abstract class */
  void visitDefConst(DefConst *p);
  void visitDefReg(DefReg *p);
  void visitDefMem(DefMem *p);
  void visitDefSubmodule(DefSubmodule *p);
  void visitDefInput(DefInput *p);
  void visitDefOutput(DefOutput *p);
  void visitDefInternal(DefInternal *p);
  void visitDefEvent(DefEvent *p);
  void visitDefInit(DefInit *p);
  void visitDefConnect(DefConnect *p);
  void visitDefFor(DefFor *p);
  void visitDefIf(DefIf *p);
  void visitListModDef(ListModDef *p);
  void visitChannelSpecifier(ChannelSpecifier *p); /* abstract class */
  void visitSimpleCS(SimpleCS *p);
  void visitDotCS(DotCS *p);
  void visitArrayDotCS(ArrayDotCS *p);
  void visitEventName(EventName *p); /* abstract class */
  void visitNoEvName(NoEvName *p);
  void visitEvName(EvName *p);
  void visitEventParam(EventParam *p); /* abstract class */
  void visitEventParamWithName(EventParamWithName *p);
  void visitEventParamNoName(EventParamNoName *p);
  void visitListEventParam(ListEventParam *p);
  void visitEventOrCond(EventOrCond *p); /* abstract class */
  void visitCSEventCond(CSEventCond *p);
  void visitListEvOr(ListEvOr *p);
  void visitEventOrList(EventOrList *p); /* abstract class */
  void visitEventOrListChannelSpecifier(EventOrListChannelSpecifier *p);
  void visitListEventOrList(ListEventOrList *p);
  void visitStructDef(StructDef *p); /* abstract class */
  void visitDefSubstor(DefSubstor *p);
  void visitDefFunction(DefFunction *p);
  void visitListStructDef(ListStructDef *p);
  void visitFuncParam(FuncParam *p); /* abstract class */
  void visitFuncParam1(FuncParam1 *p);
  void visitListFuncParam(ListFuncParam *p);
  void visitOptionalType(OptionalType *p); /* abstract class */
  void visitNoType(NoType *p);
  void visitTypeSpec(TypeSpec *p);
  void visitStatement(Statement *p); /* abstract class */
  void visitVarStmt(VarStmt *p);
  void visitAssignStmt(AssignStmt *p);
  void visitAssignArrStmt(AssignArrStmt *p);
  void visitIfStmt(IfStmt *p);
  void visitBlockStmt(BlockStmt *p);
  void visitPushStmt(PushStmt *p);
  void visitStaticForStmt(StaticForStmt *p);
  void visitStaticIfStmt(StaticIfStmt *p);
  void visitReturnStmt(ReturnStmt *p);
  void visitWaitUntilStmt(WaitUntilStmt *p);
  void visitListStatement(ListStatement *p);
  void visitPushSubDest(PushSubDest *p); /* abstract class */
  void visitPushSubreg(PushSubreg *p);
  void visitPushArray(PushArray *p);
  void visitPushArrayDot(PushArrayDot *p);
  void visitPushReg(PushReg *p);
  void visitVarAssignment(VarAssignment *p); /* abstract class */
  void visitVarAssign(VarAssign *p);
  void visitNoVarAssign(NoVarAssign *p);
  void visitBlock(Block *p); /* abstract class */
  void visitBlock1(Block1 *p);
  void visitBlockAttr(BlockAttr *p); /* abstract class */
  void visitBlockAttr_atomic(BlockAttr_atomic *p);
  void visitBlockAttr_xact(BlockAttr_xact *p);
  void visitListBlockAttr(ListBlockAttr *p);
  void visitElseBlock(ElseBlock *p); /* abstract class */
  void visitElseIf(ElseIf *p);
  void visitElse(Else *p);
  void visitNoElse(NoElse *p);
  void visitExp(Exp *p); /* abstract class */
  void visitEVoid(EVoid *p);
  void visitETrue(ETrue *p);
  void visitEFalse(EFalse *p);
  void visitEInt(EInt *p);
  void visitEHex(EHex *p);
  void visitEDouble(EDouble *p);
  void visitEString(EString *p);
  void visitEStructLiteral(EStructLiteral *p);
  void visitEVectorLiteral(EVectorLiteral *p);
  void visitEId(EId *p);
  void visitEArrAcc(EArrAcc *p);
  void visitESlice(ESlice *p);
  void visitEDot(EDot *p);
  void visitENeg(ENeg *p);
  void visitEAndB(EAndB *p);
  void visitEOrB(EOrB *p);
  void visitEXOR(EXOR *p);
  void visitEShR(EShR *p);
  void visitEShL(EShL *p);
  void visitERotR(ERotR *p);
  void visitERotL(ERotL *p);
  void visitETimes(ETimes *p);
  void visitEDiv(EDiv *p);
  void visitEPlus(EPlus *p);
  void visitEMinus(EMinus *p);
  void visitELt(ELt *p);
  void visitEGt(EGt *p);
  void visitELtEq(ELtEq *p);
  void visitEGtEq(EGtEq *p);
  void visitEEq(EEq *p);
  void visitENEq(ENEq *p);
  void visitEAnd(EAnd *p);
  void visitEOr(EOr *p);
  void visitListExp(ListExp *p);
  void visitPackageName(PackageName *p); /* abstract class */
  void visitPackageNameId(PackageNameId *p);
  void visitListPackageName(ListPackageName *p);
  void visitStructLiteralField(StructLiteralField *p); /* abstract class */
  void visitStructLiteralField1(StructLiteralField1 *p);
  void visitListStructLiteralField(ListStructLiteralField *p);
  void visitIntOrName(IntOrName *p); /* abstract class */
  void visitConstName(ConstName *p);
  void visitInt(Int *p);
  void visitType(Type *p); /* abstract class */
  void visitTyName(TyName *p);
  void visitTyVoid(TyVoid *p);
  void visitTyType(TyType *p);
  void visitTyNameParams(TyNameParams *p);
  void visitTyArray(TyArray *p);
  void visitTyVector(TyVector *p);
  void visitTemplateExp(TemplateExp *p); /* abstract class */
  void visitTEType(TEType *p);
  void visitTEConstExp(TEConstExp *p);
  void visitTemplateArg(TemplateArg *p); /* abstract class */
  void visitTemplateArg1(TemplateArg1 *p);
  void visitListTemplateArg(ListTemplateArg *p);

  void visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  void visitString(String s);
  void visitIdent(String s);
  void visitId(String s);
  void visitHexInteger(String s);
 protected:
  void inline bufAppend(const char *s)
  {
    int len = strlen(s);
    while (cur_ + len > buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    for(int n = 0; n < len; n++)
    {
      buf_[cur_ + n] = s[n];
    }
    cur_ += len;
    buf_[cur_] = 0;
  }

  void inline bufAppend(const char c)
  {
    if (cur_ == buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    buf_[cur_] = c;
    cur_++;
    buf_[cur_] = 0;
  }

  void inline bufAppend(String str)
  {
    const char *s = str.c_str();
    bufAppend(s);
  }
  void inline bufReset(void)
  {
    cur_ = 0;
    buf_size = BUFFER_INITIAL;
    resizeBuffer();
    memset(buf_, 0, buf_size);
  }

  void inline resizeBuffer(void)
  {
    char *temp = (char *) malloc(buf_size);
    if (!temp)
    {
      fprintf(stderr, "Error: Out of memory while attempting to grow buffer!\n");
      exit(1);
    }
    if (buf_)
    {
      strcpy(temp, buf_);
      free(buf_);
    }
    buf_ = temp;
  }
  char *buf_;
  int cur_, buf_size;
};



class ShowAbsyn : public Visitor
{
 public:
  ShowAbsyn(void);
  ~ShowAbsyn(void);
  char *show(Visitable *v);

  void visitPackage(Package *p); /* abstract class */
  void visitPDefs(PDefs *p);
  void visitDef(Def *p); /* abstract class */
  void visitDefImport(DefImport *p);
  void visitDefPackage(DefPackage *p);
  void visitDefModule(DefModule *p);
  void visitDefStruct(DefStruct *p);
  void visitListDef(ListDef *p);
  void visitMetaParamDecl(MetaParamDecl *p); /* abstract class */
  void visitNoParams(NoParams *p);
  void visitSomeParams(SomeParams *p);
  void visitOptionalEqExp(OptionalEqExp *p); /* abstract class */
  void visitEqExp(EqExp *p);
  void visitNoEqExp(NoEqExp *p);
  void visitMetaParam(MetaParam *p); /* abstract class */
  void visitMetaParam1(MetaParam1 *p);
  void visitListMetaParam(ListMetaParam *p);
  void visitModDef(ModDef *p); /* abstract class */
  void visitDefConst(DefConst *p);
  void visitDefReg(DefReg *p);
  void visitDefMem(DefMem *p);
  void visitDefSubmodule(DefSubmodule *p);
  void visitDefInput(DefInput *p);
  void visitDefOutput(DefOutput *p);
  void visitDefInternal(DefInternal *p);
  void visitDefEvent(DefEvent *p);
  void visitDefInit(DefInit *p);
  void visitDefConnect(DefConnect *p);
  void visitDefFor(DefFor *p);
  void visitDefIf(DefIf *p);
  void visitListModDef(ListModDef *p);
  void visitChannelSpecifier(ChannelSpecifier *p); /* abstract class */
  void visitSimpleCS(SimpleCS *p);
  void visitDotCS(DotCS *p);
  void visitArrayDotCS(ArrayDotCS *p);
  void visitEventName(EventName *p); /* abstract class */
  void visitNoEvName(NoEvName *p);
  void visitEvName(EvName *p);
  void visitEventParam(EventParam *p); /* abstract class */
  void visitEventParamWithName(EventParamWithName *p);
  void visitEventParamNoName(EventParamNoName *p);
  void visitListEventParam(ListEventParam *p);
  void visitEventOrCond(EventOrCond *p); /* abstract class */
  void visitCSEventCond(CSEventCond *p);
  void visitListEvOr(ListEvOr *p);
  void visitEventOrList(EventOrList *p); /* abstract class */
  void visitEventOrListChannelSpecifier(EventOrListChannelSpecifier *p);
  void visitListEventOrList(ListEventOrList *p);
  void visitStructDef(StructDef *p); /* abstract class */
  void visitDefSubstor(DefSubstor *p);
  void visitDefFunction(DefFunction *p);
  void visitListStructDef(ListStructDef *p);
  void visitFuncParam(FuncParam *p); /* abstract class */
  void visitFuncParam1(FuncParam1 *p);
  void visitListFuncParam(ListFuncParam *p);
  void visitOptionalType(OptionalType *p); /* abstract class */
  void visitNoType(NoType *p);
  void visitTypeSpec(TypeSpec *p);
  void visitStatement(Statement *p); /* abstract class */
  void visitVarStmt(VarStmt *p);
  void visitAssignStmt(AssignStmt *p);
  void visitAssignArrStmt(AssignArrStmt *p);
  void visitIfStmt(IfStmt *p);
  void visitBlockStmt(BlockStmt *p);
  void visitPushStmt(PushStmt *p);
  void visitStaticForStmt(StaticForStmt *p);
  void visitStaticIfStmt(StaticIfStmt *p);
  void visitReturnStmt(ReturnStmt *p);
  void visitWaitUntilStmt(WaitUntilStmt *p);
  void visitListStatement(ListStatement *p);
  void visitPushSubDest(PushSubDest *p); /* abstract class */
  void visitPushSubreg(PushSubreg *p);
  void visitPushArray(PushArray *p);
  void visitPushArrayDot(PushArrayDot *p);
  void visitPushReg(PushReg *p);
  void visitVarAssignment(VarAssignment *p); /* abstract class */
  void visitVarAssign(VarAssign *p);
  void visitNoVarAssign(NoVarAssign *p);
  void visitBlock(Block *p); /* abstract class */
  void visitBlock1(Block1 *p);
  void visitBlockAttr(BlockAttr *p); /* abstract class */
  void visitBlockAttr_atomic(BlockAttr_atomic *p);
  void visitBlockAttr_xact(BlockAttr_xact *p);
  void visitListBlockAttr(ListBlockAttr *p);
  void visitElseBlock(ElseBlock *p); /* abstract class */
  void visitElseIf(ElseIf *p);
  void visitElse(Else *p);
  void visitNoElse(NoElse *p);
  void visitExp(Exp *p); /* abstract class */
  void visitEVoid(EVoid *p);
  void visitETrue(ETrue *p);
  void visitEFalse(EFalse *p);
  void visitEInt(EInt *p);
  void visitEHex(EHex *p);
  void visitEDouble(EDouble *p);
  void visitEString(EString *p);
  void visitEStructLiteral(EStructLiteral *p);
  void visitEVectorLiteral(EVectorLiteral *p);
  void visitEId(EId *p);
  void visitEArrAcc(EArrAcc *p);
  void visitESlice(ESlice *p);
  void visitEDot(EDot *p);
  void visitENeg(ENeg *p);
  void visitEAndB(EAndB *p);
  void visitEOrB(EOrB *p);
  void visitEXOR(EXOR *p);
  void visitEShR(EShR *p);
  void visitEShL(EShL *p);
  void visitERotR(ERotR *p);
  void visitERotL(ERotL *p);
  void visitETimes(ETimes *p);
  void visitEDiv(EDiv *p);
  void visitEPlus(EPlus *p);
  void visitEMinus(EMinus *p);
  void visitELt(ELt *p);
  void visitEGt(EGt *p);
  void visitELtEq(ELtEq *p);
  void visitEGtEq(EGtEq *p);
  void visitEEq(EEq *p);
  void visitENEq(ENEq *p);
  void visitEAnd(EAnd *p);
  void visitEOr(EOr *p);
  void visitListExp(ListExp *p);
  void visitPackageName(PackageName *p); /* abstract class */
  void visitPackageNameId(PackageNameId *p);
  void visitListPackageName(ListPackageName *p);
  void visitStructLiteralField(StructLiteralField *p); /* abstract class */
  void visitStructLiteralField1(StructLiteralField1 *p);
  void visitListStructLiteralField(ListStructLiteralField *p);
  void visitIntOrName(IntOrName *p); /* abstract class */
  void visitConstName(ConstName *p);
  void visitInt(Int *p);
  void visitType(Type *p); /* abstract class */
  void visitTyName(TyName *p);
  void visitTyVoid(TyVoid *p);
  void visitTyType(TyType *p);
  void visitTyNameParams(TyNameParams *p);
  void visitTyArray(TyArray *p);
  void visitTyVector(TyVector *p);
  void visitTemplateExp(TemplateExp *p); /* abstract class */
  void visitTEType(TEType *p);
  void visitTEConstExp(TEConstExp *p);
  void visitTemplateArg(TemplateArg *p); /* abstract class */
  void visitTemplateArg1(TemplateArg1 *p);
  void visitListTemplateArg(ListTemplateArg *p);

  void visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  void visitString(String s);
  void visitIdent(String s);
  void visitId(String s);
  void visitHexInteger(String s);
 protected:
  void inline bufAppend(const char *s)
  {
    int len = strlen(s);
    while (cur_ + len > buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    for(int n = 0; n < len; n++)
    {
      buf_[cur_ + n] = s[n];
    }
    cur_ += len;
    buf_[cur_] = 0;
  }

  void inline bufAppend(const char c)
  {
    if (cur_ == buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    buf_[cur_] = c;
    cur_++;
    buf_[cur_] = 0;
  }

  void inline bufAppend(String str)
  {
    const char *s = str.c_str();
    bufAppend(s);
  }
  void inline bufReset(void)
  {
    cur_ = 0;
    buf_size = BUFFER_INITIAL;
    resizeBuffer();
    memset(buf_, 0, buf_size);
  }

  void inline resizeBuffer(void)
  {
    char *temp = (char *) malloc(buf_size);
    if (!temp)
    {
      fprintf(stderr, "Error: Out of memory while attempting to grow buffer!\n");
      exit(1);
    }
    if (buf_)
    {
      strcpy(temp, buf_);
      free(buf_);
    }
    buf_ = temp;
  }
  char *buf_;
  int cur_, buf_size;
};




#endif

