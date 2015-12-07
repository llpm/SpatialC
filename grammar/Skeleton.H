#ifndef SKELETON_HEADER
#define SKELETON_HEADER
/* You might want to change the above name. */

#include "Absyn.H"


class Skeleton : public Visitor
{
public:
  void visitPackage(Package *p);
  void visitDef(Def *p);
  void visitMetaParamDecl(MetaParamDecl *p);
  void visitOptionalEqExp(OptionalEqExp *p);
  void visitMetaParam(MetaParam *p);
  void visitModDef(ModDef *p);
  void visitChannelSpecifier(ChannelSpecifier *p);
  void visitEventName(EventName *p);
  void visitEventParam(EventParam *p);
  void visitEventOrCond(EventOrCond *p);
  void visitEventOrList(EventOrList *p);
  void visitStructDef(StructDef *p);
  void visitFuncParam(FuncParam *p);
  void visitOptionalType(OptionalType *p);
  void visitStatement(Statement *p);
  void visitPushSubDest(PushSubDest *p);
  void visitVarAssignment(VarAssignment *p);
  void visitBlock(Block *p);
  void visitBlockAttr(BlockAttr *p);
  void visitElseBlock(ElseBlock *p);
  void visitExp(Exp *p);
  void visitPackageName(PackageName *p);
  void visitStructLiteralField(StructLiteralField *p);
  void visitIntOrName(IntOrName *p);
  void visitType(Type *p);
  void visitTemplateExp(TemplateExp *p);
  void visitTemplateArg(TemplateArg *p);
  void visitPDefs(PDefs *p);
  void visitDefImport(DefImport *p);
  void visitDefPackage(DefPackage *p);
  void visitDefModule(DefModule *p);
  void visitDefStruct(DefStruct *p);
  void visitNoParams(NoParams *p);
  void visitSomeParams(SomeParams *p);
  void visitEqExp(EqExp *p);
  void visitNoEqExp(NoEqExp *p);
  void visitMetaParam1(MetaParam1 *p);
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
  void visitSimpleCS(SimpleCS *p);
  void visitDotCS(DotCS *p);
  void visitArrayDotCS(ArrayDotCS *p);
  void visitNoEvName(NoEvName *p);
  void visitEvName(EvName *p);
  void visitEventParamWithName(EventParamWithName *p);
  void visitEventParamNoName(EventParamNoName *p);
  void visitCSEventCond(CSEventCond *p);
  void visitListEvOr(ListEvOr *p);
  void visitEventOrListChannelSpecifier(EventOrListChannelSpecifier *p);
  void visitDefSubstor(DefSubstor *p);
  void visitDefFunction(DefFunction *p);
  void visitFuncParam1(FuncParam1 *p);
  void visitNoType(NoType *p);
  void visitTypeSpec(TypeSpec *p);
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
  void visitPushSubreg(PushSubreg *p);
  void visitPushArray(PushArray *p);
  void visitPushArrayDot(PushArrayDot *p);
  void visitPushReg(PushReg *p);
  void visitVarAssign(VarAssign *p);
  void visitNoVarAssign(NoVarAssign *p);
  void visitBlock1(Block1 *p);
  void visitBlockAttr_atomic(BlockAttr_atomic *p);
  void visitBlockAttr_xact(BlockAttr_xact *p);
  void visitElseIf(ElseIf *p);
  void visitElse(Else *p);
  void visitNoElse(NoElse *p);
  void visitEVoid(EVoid *p);
  void visitETrue(ETrue *p);
  void visitEFalse(EFalse *p);
  void visitEInt(EInt *p);
  void visitEDouble(EDouble *p);
  void visitEString(EString *p);
  void visitEStructLiteral(EStructLiteral *p);
  void visitEVectorLiteral(EVectorLiteral *p);
  void visitEId(EId *p);
  void visitEArrAcc(EArrAcc *p);
  void visitESlice(ESlice *p);
  void visitEDot(EDot *p);
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
  void visitPackageNameId(PackageNameId *p);
  void visitStructLiteralField1(StructLiteralField1 *p);
  void visitConstName(ConstName *p);
  void visitInt(Int *p);
  void visitTyName(TyName *p);
  void visitTyVoid(TyVoid *p);
  void visitTyType(TyType *p);
  void visitTyNameParams(TyNameParams *p);
  void visitTyArray(TyArray *p);
  void visitTyVector(TyVector *p);
  void visitTEType(TEType *p);
  void visitTEConstExp(TEConstExp *p);
  void visitTemplateArg1(TemplateArg1 *p);
  void visitListDef(ListDef *p);
  void visitListMetaParam(ListMetaParam *p);
  void visitListModDef(ListModDef *p);
  void visitListEventParam(ListEventParam *p);
  void visitListEventOrList(ListEventOrList *p);
  void visitListStructDef(ListStructDef *p);
  void visitListFuncParam(ListFuncParam *p);
  void visitListStatement(ListStatement *p);
  void visitListBlockAttr(ListBlockAttr *p);
  void visitListExp(ListExp *p);
  void visitListPackageName(ListPackageName *p);
  void visitListStructLiteralField(ListStructLiteralField *p);
  void visitListTemplateArg(ListTemplateArg *p);

  void visit"Id"("Id" x);
  void visit"Integer"("Integer" x);
  void visit"Char"("Char" x);
  void visit"Double"("Double" x);
  void visit"String"("String" x);
  void visit"Ident"("Ident" x);

};


#endif
