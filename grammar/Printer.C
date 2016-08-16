/*** BNFC-Generated Pretty Printer and Abstract Syntax Viewer ***/

#include <string>
#include "Printer.H"
#define INDENT_WIDTH 2


//You may wish to change render
void PrintAbsyn::render(Char c)
{
  if (c == '{')
  {
     bufAppend('\n');
     indent();
     bufAppend(c);
     _n_ = _n_ + INDENT_WIDTH;
     bufAppend('\n');
     indent();
  }
  else if (c == '(' || c == '[')
     bufAppend(c);
  else if (c == ')' || c == ']')
  {
     backup();
     bufAppend(c);
  }
  else if (c == '}')
  {
     int t;
     _n_ = _n_ - INDENT_WIDTH;
     for (t=0; t<INDENT_WIDTH; t++) {
       backup();
     }
     bufAppend(c);
     bufAppend('\n');
     indent();
  }
  else if (c == ',')
  {
     backup();
     bufAppend(c);
     bufAppend(' ');
  }
  else if (c == ';')
  {
     backup();
     bufAppend(c);
     bufAppend('\n');
     indent();
  }
  else if (c == 0) return;
  else
  {
     bufAppend(' ');
     bufAppend(c);
     bufAppend(' ');
  }
}

void PrintAbsyn::render(String s_)
{
  const char *s = s_.c_str() ;
  if(strlen(s) > 0)
  {
    bufAppend(s);
    bufAppend(' ');
  }
}
void PrintAbsyn::render(char *s)
{
  if(strlen(s) > 0)
  {
    bufAppend(s);
    bufAppend(' ');
  }
}

void PrintAbsyn::indent()
{
  int n = _n_;
  while (n > 0)
  {
    bufAppend(' ');
    n--;
  }
}

void PrintAbsyn::backup()
{
  if (buf_[cur_ - 1] == ' ')
  {
    buf_[cur_ - 1] = 0;
    cur_--;
  }
}

PrintAbsyn::PrintAbsyn(void)
{
  _i_ = 0; _n_ = 0;
  buf_ = 0;
  bufReset();
}

PrintAbsyn::~PrintAbsyn(void)
{
}

char *PrintAbsyn::print(Visitable *v)
{
  _i_ = 0; _n_ = 0;
  bufReset();
  v->accept(this);
  return buf_;
}

void PrintAbsyn::visitPackage(Package *p) {} //abstract class

void PrintAbsyn::visitPDefs(PDefs *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  if(p->listdef_) {_i_ = 0; p->listdef_->accept(this);}

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDef(Def *p) {} //abstract class

void PrintAbsyn::visitDefImport(DefImport *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("import");
  if(p->listpackagename_) {_i_ = 0; p->listpackagename_->accept(this);}
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDefPackage(DefPackage *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("package");
  if(p->listpackagename_) {_i_ = 0; p->listpackagename_->accept(this);}
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDefModule(DefModule *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("module");
  visitIdent(p->id_);
  _i_ = 0; p->metaparamdecl_->accept(this);
  render('{');
  if(p->listmoddef_) {_i_ = 0; p->listmoddef_->accept(this);}
  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDefStruct(DefStruct *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("struct");
  visitIdent(p->id_);
  _i_ = 0; p->metaparamdecl_->accept(this);
  render('{');
  if(p->liststructdef_) {_i_ = 0; p->liststructdef_->accept(this);}
  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListDef(ListDef *listdef)
{
  for (ListDef::const_iterator i = listdef->begin() ; i != listdef->end() ; ++i)
  {
    (*i)->accept(this);
    render("");
  }
}void PrintAbsyn::visitMetaParamDecl(MetaParamDecl *p) {} //abstract class

void PrintAbsyn::visitNoParams(NoParams *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);


  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSomeParams(SomeParams *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('(');
  if(p->listmetaparam_) {_i_ = 0; p->listmetaparam_->accept(this);}
  render(')');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOptionalEqExp(OptionalEqExp *p) {} //abstract class

void PrintAbsyn::visitEqExp(EqExp *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('=');
  _i_ = 0; p->exp_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitNoEqExp(NoEqExp *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);


  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitMetaParam(MetaParam *p) {} //abstract class

void PrintAbsyn::visitMetaParam1(MetaParam1 *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->type_->accept(this);
  visitIdent(p->id_);
  _i_ = 0; p->optionaleqexp_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListMetaParam(ListMetaParam *listmetaparam)
{
  for (ListMetaParam::const_iterator i = listmetaparam->begin() ; i != listmetaparam->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listmetaparam->end() - 1) render(',');
  }
}void PrintAbsyn::visitModDef(ModDef *p) {} //abstract class

void PrintAbsyn::visitDefConst(DefConst *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("const");
  _i_ = 0; p->type_->accept(this);
  visitIdent(p->id_);
  _i_ = 0; p->optionaleqexp_->accept(this);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDefReg(DefReg *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("reg");
  _i_ = 0; p->type_->accept(this);
  visitIdent(p->id_);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDefMem(DefMem *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("mem");
  _i_ = 0; p->type_->accept(this);
  visitIdent(p->id_);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDefSubmodule(DefSubmodule *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("mod");
  _i_ = 0; p->type_->accept(this);
  visitIdent(p->id_);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDefInput(DefInput *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("input");
  _i_ = 0; p->type_->accept(this);
  visitIdent(p->id_);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDefOutput(DefOutput *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("output");
  _i_ = 0; p->type_->accept(this);
  visitIdent(p->id_);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDefInternal(DefInternal *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("internal");
  _i_ = 0; p->type_->accept(this);
  visitIdent(p->id_);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDefEvent(DefEvent *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("event");
  _i_ = 0; p->eventname_->accept(this);
  render('(');
  if(p->listeventparam_) {_i_ = 0; p->listeventparam_->accept(this);}
  render(')');
  _i_ = 0; p->block_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDefInit(DefInit *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("init");
  _i_ = 0; p->eventname_->accept(this);
  _i_ = 0; p->block_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDefConnect(DefConnect *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("connect");
  _i_ = 0; p->channelspecifier_1->accept(this);
  render("->");
  _i_ = 0; p->channelspecifier_2->accept(this);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDefFor(DefFor *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("static_for");
  render('(');
  visitIdent(p->id_);
  render(':');
  _i_ = 0; p->exp_1->accept(this);
  render("..");
  _i_ = 0; p->exp_2->accept(this);
  render(')');
  render('{');
  if(p->listmoddef_) {_i_ = 0; p->listmoddef_->accept(this);}
  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDefIf(DefIf *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("static_if");
  render('(');
  _i_ = 0; p->exp_->accept(this);
  render(')');
  render('{');
  if(p->listmoddef_) {_i_ = 0; p->listmoddef_->accept(this);}
  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListModDef(ListModDef *listmoddef)
{
  for (ListModDef::const_iterator i = listmoddef->begin() ; i != listmoddef->end() ; ++i)
  {
    (*i)->accept(this);
    render("");
  }
}void PrintAbsyn::visitChannelSpecifier(ChannelSpecifier *p) {} //abstract class

void PrintAbsyn::visitSimpleCS(SimpleCS *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->id_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDotCS(DotCS *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->id_1);
  render('.');
  visitIdent(p->id_2);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitArrayDotCS(ArrayDotCS *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->id_1);
  render('[');
  _i_ = 0; p->exp_->accept(this);
  render(']');
  render('.');
  visitIdent(p->id_2);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEventName(EventName *p) {} //abstract class

void PrintAbsyn::visitNoEvName(NoEvName *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);


  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEvName(EvName *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('"');
  visitIdent(p->id_);
  render('"');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEventParam(EventParam *p) {} //abstract class

void PrintAbsyn::visitEventParamWithName(EventParamWithName *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->eventorcond_->accept(this);
  render("->");
  visitIdent(p->id_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEventParamNoName(EventParamNoName *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->eventorcond_->accept(this);
  render("->");
  render('*');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListEventParam(ListEventParam *listeventparam)
{
  for (ListEventParam::const_iterator i = listeventparam->begin() ; i != listeventparam->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listeventparam->end() - 1) render(',');
  }
}void PrintAbsyn::visitEventOrCond(EventOrCond *p) {} //abstract class

void PrintAbsyn::visitCSEventCond(CSEventCond *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->channelspecifier_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListEvOr(ListEvOr *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('(');
  if(p->listeventorlist_) {_i_ = 0; p->listeventorlist_->accept(this);}
  render(')');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEventOrList(EventOrList *p) {} //abstract class

void PrintAbsyn::visitEventOrListChannelSpecifier(EventOrListChannelSpecifier *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->channelspecifier_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListEventOrList(ListEventOrList *listeventorlist)
{
  for (ListEventOrList::const_iterator i = listeventorlist->begin() ; i != listeventorlist->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listeventorlist->end() - 1) render('|');
  }
}void PrintAbsyn::visitStructDef(StructDef *p) {} //abstract class

void PrintAbsyn::visitDefSubstor(DefSubstor *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->type_->accept(this);
  visitIdent(p->id_);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDefFunction(DefFunction *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->type_->accept(this);
  visitIdent(p->id_);
  render('(');
  if(p->listfuncparam_) {_i_ = 0; p->listfuncparam_->accept(this);}
  render(')');
  render('{');
  if(p->liststatement_) {_i_ = 0; p->liststatement_->accept(this);}
  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListStructDef(ListStructDef *liststructdef)
{
  for (ListStructDef::const_iterator i = liststructdef->begin() ; i != liststructdef->end() ; ++i)
  {
    (*i)->accept(this);
    render("");
  }
}void PrintAbsyn::visitFuncParam(FuncParam *p) {} //abstract class

void PrintAbsyn::visitFuncParam1(FuncParam1 *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->type_->accept(this);
  visitIdent(p->id_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListFuncParam(ListFuncParam *listfuncparam)
{
  for (ListFuncParam::const_iterator i = listfuncparam->begin() ; i != listfuncparam->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listfuncparam->end() - 1) render(',');
  }
}void PrintAbsyn::visitOptionalType(OptionalType *p) {} //abstract class

void PrintAbsyn::visitNoType(NoType *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);


  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTypeSpec(TypeSpec *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render(':');
  _i_ = 0; p->type_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStatement(Statement *p) {} //abstract class

void PrintAbsyn::visitVarStmt(VarStmt *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("var");
  _i_ = 0; p->optionaltype_->accept(this);
  visitIdent(p->id_);
  _i_ = 0; p->varassignment_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitAssignStmt(AssignStmt *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->id_);
  render('=');
  _i_ = 0; p->exp_->accept(this);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitAssignArrStmt(AssignArrStmt *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->id_);
  render('[');
  _i_ = 0; p->exp_1->accept(this);
  render(']');
  render('=');
  _i_ = 0; p->exp_2->accept(this);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitIfStmt(IfStmt *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("if");
  render('(');
  _i_ = 0; p->exp_->accept(this);
  render(')');
  _i_ = 0; p->block_->accept(this);
  _i_ = 0; p->elseblock_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitBlockStmt(BlockStmt *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->block_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitPushStmt(PushStmt *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->id_);
  _i_ = 0; p->pushsubdest_->accept(this);
  render("<-");
  _i_ = 0; p->exp_->accept(this);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStaticForStmt(StaticForStmt *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("static_for");
  render('(');
  visitIdent(p->id_);
  render(':');
  _i_ = 0; p->exp_1->accept(this);
  render("..");
  _i_ = 0; p->exp_2->accept(this);
  render(')');
  _i_ = 0; p->block_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStaticIfStmt(StaticIfStmt *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("static_if");
  render('(');
  _i_ = 0; p->exp_->accept(this);
  render(')');
  _i_ = 0; p->block_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitReturnStmt(ReturnStmt *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("return");
  _i_ = 0; p->exp_->accept(this);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitWaitUntilStmt(WaitUntilStmt *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("wait_until");
  _i_ = 0; p->exp_->accept(this);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListStatement(ListStatement *liststatement)
{
  for (ListStatement::const_iterator i = liststatement->begin() ; i != liststatement->end() ; ++i)
  {
    (*i)->accept(this);
    render("");
  }
}void PrintAbsyn::visitPushSubDest(PushSubDest *p) {} //abstract class

void PrintAbsyn::visitPushSubreg(PushSubreg *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('.');
  visitIdent(p->id_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitPushArray(PushArray *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('[');
  _i_ = 0; p->exp_->accept(this);
  render(']');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitPushArrayDot(PushArrayDot *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('[');
  _i_ = 0; p->exp_->accept(this);
  render(']');
  render('.');
  visitIdent(p->id_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitPushReg(PushReg *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);


  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitVarAssignment(VarAssignment *p) {} //abstract class

void PrintAbsyn::visitVarAssign(VarAssign *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('=');
  _i_ = 0; p->exp_->accept(this);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitNoVarAssign(NoVarAssign *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);


  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitBlock(Block *p) {} //abstract class

void PrintAbsyn::visitBlock1(Block1 *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  if(p->listblockattr_) {_i_ = 0; p->listblockattr_->accept(this);}
  render('{');
  if(p->liststatement_) {_i_ = 0; p->liststatement_->accept(this);}
  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitBlockAttr(BlockAttr *p) {} //abstract class

void PrintAbsyn::visitBlockAttr_atomic(BlockAttr_atomic *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("atomic");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitBlockAttr_xact(BlockAttr_xact *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("xact");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListBlockAttr(ListBlockAttr *listblockattr)
{
  for (ListBlockAttr::const_iterator i = listblockattr->begin() ; i != listblockattr->end() ; ++i)
  {
    (*i)->accept(this);
    render("");
  }
}void PrintAbsyn::visitElseBlock(ElseBlock *p) {} //abstract class

void PrintAbsyn::visitElseIf(ElseIf *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("elif");
  render('(');
  _i_ = 0; p->exp_->accept(this);
  render(')');
  _i_ = 0; p->block_->accept(this);
  _i_ = 0; p->elseblock_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitElse(Else *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("else");
  _i_ = 0; p->block_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitNoElse(NoElse *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);


  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitExp(Exp *p) {} //abstract class

void PrintAbsyn::visitEVoid(EVoid *p)
{
  int oldi = _i_;
  if (oldi > 15) render(_L_PAREN);

  render("void");

  if (oldi > 15) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitETrue(ETrue *p)
{
  int oldi = _i_;
  if (oldi > 15) render(_L_PAREN);

  render("true");

  if (oldi > 15) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEFalse(EFalse *p)
{
  int oldi = _i_;
  if (oldi > 15) render(_L_PAREN);

  render("false");

  if (oldi > 15) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEInt(EInt *p)
{
  int oldi = _i_;
  if (oldi > 15) render(_L_PAREN);

  visitInteger(p->integer_);

  if (oldi > 15) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEHex(EHex *p)
{
  int oldi = _i_;
  if (oldi > 15) render(_L_PAREN);

  visitIdent(p->hexinteger_);

  if (oldi > 15) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEDouble(EDouble *p)
{
  int oldi = _i_;
  if (oldi > 15) render(_L_PAREN);

  visitDouble(p->double_);

  if (oldi > 15) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEString(EString *p)
{
  int oldi = _i_;
  if (oldi > 15) render(_L_PAREN);

  visitString(p->string_);

  if (oldi > 15) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEStructLiteral(EStructLiteral *p)
{
  int oldi = _i_;
  if (oldi > 15) render(_L_PAREN);

  render('{');
  _i_ = 0; p->type_->accept(this);
  render(':');
  if(p->liststructliteralfield_) {_i_ = 0; p->liststructliteralfield_->accept(this);}
  render('}');

  if (oldi > 15) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEVectorLiteral(EVectorLiteral *p)
{
  int oldi = _i_;
  if (oldi > 15) render(_L_PAREN);

  render('[');
  if(p->listexp_) {_i_ = 0; p->listexp_->accept(this);}
  render(']');

  if (oldi > 15) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEId(EId *p)
{
  int oldi = _i_;
  if (oldi > 15) render(_L_PAREN);

  visitIdent(p->id_);

  if (oldi > 15) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEArrAcc(EArrAcc *p)
{
  int oldi = _i_;
  if (oldi > 15) render(_L_PAREN);

  _i_ = 15; p->exp_1->accept(this);
  render('[');
  _i_ = 0; p->exp_2->accept(this);
  render(']');

  if (oldi > 15) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitESlice(ESlice *p)
{
  int oldi = _i_;
  if (oldi > 15) render(_L_PAREN);

  _i_ = 15; p->exp_1->accept(this);
  render('[');
  _i_ = 0; p->exp_2->accept(this);
  render("..");
  _i_ = 0; p->exp_3->accept(this);
  render(']');

  if (oldi > 15) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEDot(EDot *p)
{
  int oldi = _i_;
  if (oldi > 15) render(_L_PAREN);

  _i_ = 15; p->exp_->accept(this);
  render('.');
  visitIdent(p->id_);

  if (oldi > 15) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitENeg(ENeg *p)
{
  int oldi = _i_;
  if (oldi > 14) render(_L_PAREN);

  render('~');
  _i_ = 15; p->exp_->accept(this);

  if (oldi > 14) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEAndB(EAndB *p)
{
  int oldi = _i_;
  if (oldi > 13) render(_L_PAREN);

  _i_ = 13; p->exp_1->accept(this);
  render('&');
  _i_ = 14; p->exp_2->accept(this);

  if (oldi > 13) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEOrB(EOrB *p)
{
  int oldi = _i_;
  if (oldi > 13) render(_L_PAREN);

  _i_ = 13; p->exp_1->accept(this);
  render('|');
  _i_ = 14; p->exp_2->accept(this);

  if (oldi > 13) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEXOR(EXOR *p)
{
  int oldi = _i_;
  if (oldi > 13) render(_L_PAREN);

  _i_ = 13; p->exp_1->accept(this);
  render('^');
  _i_ = 14; p->exp_2->accept(this);

  if (oldi > 13) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEShR(EShR *p)
{
  int oldi = _i_;
  if (oldi > 13) render(_L_PAREN);

  _i_ = 13; p->exp_1->accept(this);
  render(">>");
  _i_ = 14; p->exp_2->accept(this);

  if (oldi > 13) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEShL(EShL *p)
{
  int oldi = _i_;
  if (oldi > 13) render(_L_PAREN);

  _i_ = 13; p->exp_1->accept(this);
  render("<<");
  _i_ = 14; p->exp_2->accept(this);

  if (oldi > 13) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitERotR(ERotR *p)
{
  int oldi = _i_;
  if (oldi > 13) render(_L_PAREN);

  _i_ = 13; p->exp_1->accept(this);
  render(">>>");
  _i_ = 14; p->exp_2->accept(this);

  if (oldi > 13) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitERotL(ERotL *p)
{
  int oldi = _i_;
  if (oldi > 13) render(_L_PAREN);

  _i_ = 13; p->exp_1->accept(this);
  render("<<<");
  _i_ = 14; p->exp_2->accept(this);

  if (oldi > 13) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitETimes(ETimes *p)
{
  int oldi = _i_;
  if (oldi > 12) render(_L_PAREN);

  _i_ = 12; p->exp_1->accept(this);
  render('*');
  _i_ = 13; p->exp_2->accept(this);

  if (oldi > 12) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEDiv(EDiv *p)
{
  int oldi = _i_;
  if (oldi > 12) render(_L_PAREN);

  _i_ = 12; p->exp_1->accept(this);
  render('/');
  _i_ = 13; p->exp_2->accept(this);

  if (oldi > 12) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEPlus(EPlus *p)
{
  int oldi = _i_;
  if (oldi > 11) render(_L_PAREN);

  _i_ = 11; p->exp_1->accept(this);
  render('+');
  _i_ = 12; p->exp_2->accept(this);

  if (oldi > 11) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEMinus(EMinus *p)
{
  int oldi = _i_;
  if (oldi > 11) render(_L_PAREN);

  _i_ = 11; p->exp_1->accept(this);
  render('-');
  _i_ = 12; p->exp_2->accept(this);

  if (oldi > 11) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitELt(ELt *p)
{
  int oldi = _i_;
  if (oldi > 9) render(_L_PAREN);

  _i_ = 9; p->exp_1->accept(this);
  render('<');
  _i_ = 10; p->exp_2->accept(this);

  if (oldi > 9) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEGt(EGt *p)
{
  int oldi = _i_;
  if (oldi > 9) render(_L_PAREN);

  _i_ = 9; p->exp_1->accept(this);
  render('>');
  _i_ = 10; p->exp_2->accept(this);

  if (oldi > 9) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitELtEq(ELtEq *p)
{
  int oldi = _i_;
  if (oldi > 9) render(_L_PAREN);

  _i_ = 9; p->exp_1->accept(this);
  render("<=");
  _i_ = 10; p->exp_2->accept(this);

  if (oldi > 9) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEGtEq(EGtEq *p)
{
  int oldi = _i_;
  if (oldi > 9) render(_L_PAREN);

  _i_ = 9; p->exp_1->accept(this);
  render(">=");
  _i_ = 10; p->exp_2->accept(this);

  if (oldi > 9) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEEq(EEq *p)
{
  int oldi = _i_;
  if (oldi > 8) render(_L_PAREN);

  _i_ = 8; p->exp_1->accept(this);
  render("==");
  _i_ = 9; p->exp_2->accept(this);

  if (oldi > 8) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitENEq(ENEq *p)
{
  int oldi = _i_;
  if (oldi > 8) render(_L_PAREN);

  _i_ = 8; p->exp_1->accept(this);
  render("!=");
  _i_ = 9; p->exp_2->accept(this);

  if (oldi > 8) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEAnd(EAnd *p)
{
  int oldi = _i_;
  if (oldi > 4) render(_L_PAREN);

  _i_ = 4; p->exp_1->accept(this);
  render("&&");
  _i_ = 5; p->exp_2->accept(this);

  if (oldi > 4) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEOr(EOr *p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  _i_ = 3; p->exp_1->accept(this);
  render("||");
  _i_ = 4; p->exp_2->accept(this);

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListExp(ListExp *listexp)
{
  for (ListExp::const_iterator i = listexp->begin() ; i != listexp->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listexp->end() - 1) render(',');
  }
}void PrintAbsyn::visitPackageName(PackageName *p) {} //abstract class

void PrintAbsyn::visitPackageNameId(PackageNameId *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->id_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListPackageName(ListPackageName *listpackagename)
{
  for (ListPackageName::const_iterator i = listpackagename->begin() ; i != listpackagename->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listpackagename->end() - 1) render('.');
  }
}void PrintAbsyn::visitStructLiteralField(StructLiteralField *p) {} //abstract class

void PrintAbsyn::visitStructLiteralField1(StructLiteralField1 *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->id_);
  render(':');
  _i_ = 0; p->exp_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListStructLiteralField(ListStructLiteralField *liststructliteralfield)
{
  for (ListStructLiteralField::const_iterator i = liststructliteralfield->begin() ; i != liststructliteralfield->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != liststructliteralfield->end() - 1) render(',');
  }
}void PrintAbsyn::visitIntOrName(IntOrName *p) {} //abstract class

void PrintAbsyn::visitConstName(ConstName *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->id_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitInt(Int *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitInteger(p->integer_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitType(Type *p) {} //abstract class

void PrintAbsyn::visitTyName(TyName *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->id_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTyVoid(TyVoid *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("void");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTyType(TyType *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("type");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTyNameParams(TyNameParams *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->id_);
  render('!');
  render('(');
  if(p->listtemplatearg_) {_i_ = 0; p->listtemplatearg_->accept(this);}
  render(')');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTyArray(TyArray *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->type_->accept(this);
  render('[');
  _i_ = 0; p->intorname_->accept(this);
  render(']');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTyVector(TyVector *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->type_->accept(this);
  render('<');
  _i_ = 0; p->intorname_->accept(this);
  render('>');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTemplateExp(TemplateExp *p) {} //abstract class

void PrintAbsyn::visitTEType(TEType *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("type");
  _i_ = 0; p->type_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTEConstExp(TEConstExp *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->exp_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTemplateArg(TemplateArg *p) {} //abstract class

void PrintAbsyn::visitTemplateArg1(TemplateArg1 *p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->id_);
  render('=');
  _i_ = 0; p->templateexp_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListTemplateArg(ListTemplateArg *listtemplatearg)
{
  for (ListTemplateArg::const_iterator i = listtemplatearg->begin() ; i != listtemplatearg->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listtemplatearg->end() - 1) render(',');
  }
}void PrintAbsyn::visitInteger(Integer i)
{
  char tmp[16];
  sprintf(tmp, "%d", i);
  bufAppend(tmp);
}

void PrintAbsyn::visitDouble(Double d)
{
  char tmp[16];
  sprintf(tmp, "%g", d);
  bufAppend(tmp);
}

void PrintAbsyn::visitChar(Char c)
{
  bufAppend('\'');
  bufAppend(c);
  bufAppend('\'');
}

void PrintAbsyn::visitString(String s)
{
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}

void PrintAbsyn::visitIdent(String s)
{
  render(s);
}

void PrintAbsyn::visitId(String s)
{
  render(s);
}


void PrintAbsyn::visitHexInteger(String s)
{
  render(s);
}


ShowAbsyn::ShowAbsyn(void)
{
  buf_ = 0;
  bufReset();
}

ShowAbsyn::~ShowAbsyn(void)
{
}

char *ShowAbsyn::show(Visitable *v)
{
  bufReset();
  v->accept(this);
  return buf_;
}

void ShowAbsyn::visitPackage(Package *p) {} //abstract class

void ShowAbsyn::visitPDefs(PDefs *p)
{
  bufAppend('(');
  bufAppend("PDefs");
  bufAppend(' ');
  bufAppend('[');
  if (p->listdef_)  p->listdef_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitDef(Def *p) {} //abstract class

void ShowAbsyn::visitDefImport(DefImport *p)
{
  bufAppend('(');
  bufAppend("DefImport");
  bufAppend(' ');
  bufAppend('[');
  if (p->listpackagename_)  p->listpackagename_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitDefPackage(DefPackage *p)
{
  bufAppend('(');
  bufAppend("DefPackage");
  bufAppend(' ');
  bufAppend('[');
  if (p->listpackagename_)  p->listpackagename_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitDefModule(DefModule *p)
{
  bufAppend('(');
  bufAppend("DefModule");
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(' ');
  bufAppend('[');
  if (p->metaparamdecl_)  p->metaparamdecl_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->listmoddef_)  p->listmoddef_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitDefStruct(DefStruct *p)
{
  bufAppend('(');
  bufAppend("DefStruct");
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(' ');
  bufAppend('[');
  if (p->metaparamdecl_)  p->metaparamdecl_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->liststructdef_)  p->liststructdef_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitListDef(ListDef *listdef)
{
  for (ListDef::const_iterator i = listdef->begin() ; i != listdef->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listdef->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitMetaParamDecl(MetaParamDecl *p) {} //abstract class

void ShowAbsyn::visitNoParams(NoParams *p)
{
  bufAppend("NoParams");
}
void ShowAbsyn::visitSomeParams(SomeParams *p)
{
  bufAppend('(');
  bufAppend("SomeParams");
  bufAppend(' ');
  bufAppend('[');
  if (p->listmetaparam_)  p->listmetaparam_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitOptionalEqExp(OptionalEqExp *p) {} //abstract class

void ShowAbsyn::visitEqExp(EqExp *p)
{
  bufAppend('(');
  bufAppend("EqExp");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitNoEqExp(NoEqExp *p)
{
  bufAppend("NoEqExp");
}
void ShowAbsyn::visitMetaParam(MetaParam *p) {} //abstract class

void ShowAbsyn::visitMetaParam1(MetaParam1 *p)
{
  bufAppend('(');
  bufAppend("MetaParam1");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(' ');
  bufAppend('[');
  if (p->optionaleqexp_)  p->optionaleqexp_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitListMetaParam(ListMetaParam *listmetaparam)
{
  for (ListMetaParam::const_iterator i = listmetaparam->begin() ; i != listmetaparam->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listmetaparam->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitModDef(ModDef *p) {} //abstract class

void ShowAbsyn::visitDefConst(DefConst *p)
{
  bufAppend('(');
  bufAppend("DefConst");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(' ');
  bufAppend('[');
  if (p->optionaleqexp_)  p->optionaleqexp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitDefReg(DefReg *p)
{
  bufAppend('(');
  bufAppend("DefReg");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitDefMem(DefMem *p)
{
  bufAppend('(');
  bufAppend("DefMem");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitDefSubmodule(DefSubmodule *p)
{
  bufAppend('(');
  bufAppend("DefSubmodule");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitDefInput(DefInput *p)
{
  bufAppend('(');
  bufAppend("DefInput");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitDefOutput(DefOutput *p)
{
  bufAppend('(');
  bufAppend("DefOutput");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitDefInternal(DefInternal *p)
{
  bufAppend('(');
  bufAppend("DefInternal");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitDefEvent(DefEvent *p)
{
  bufAppend('(');
  bufAppend("DefEvent");
  bufAppend(' ');
  bufAppend('[');
  if (p->eventname_)  p->eventname_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->listeventparam_)  p->listeventparam_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->block_)  p->block_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitDefInit(DefInit *p)
{
  bufAppend('(');
  bufAppend("DefInit");
  bufAppend(' ');
  bufAppend('[');
  if (p->eventname_)  p->eventname_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->block_)  p->block_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitDefConnect(DefConnect *p)
{
  bufAppend('(');
  bufAppend("DefConnect");
  bufAppend(' ');
  p->channelspecifier_1->accept(this);
  bufAppend(' ');
  p->channelspecifier_2->accept(this);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitDefFor(DefFor *p)
{
  bufAppend('(');
  bufAppend("DefFor");
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(' ');
  bufAppend('[');
  if (p->listmoddef_)  p->listmoddef_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitDefIf(DefIf *p)
{
  bufAppend('(');
  bufAppend("DefIf");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->listmoddef_)  p->listmoddef_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitListModDef(ListModDef *listmoddef)
{
  for (ListModDef::const_iterator i = listmoddef->begin() ; i != listmoddef->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listmoddef->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitChannelSpecifier(ChannelSpecifier *p) {} //abstract class

void ShowAbsyn::visitSimpleCS(SimpleCS *p)
{
  bufAppend('(');
  bufAppend("SimpleCS");
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(')');
}
void ShowAbsyn::visitDotCS(DotCS *p)
{
  bufAppend('(');
  bufAppend("DotCS");
  bufAppend(' ');
  visitIdent(p->id_1);
  bufAppend(' ');
  visitIdent(p->id_2);
  bufAppend(')');
}
void ShowAbsyn::visitArrayDotCS(ArrayDotCS *p)
{
  bufAppend('(');
  bufAppend("ArrayDotCS");
  bufAppend(' ');
  visitIdent(p->id_1);
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->id_2);
  bufAppend(')');
}
void ShowAbsyn::visitEventName(EventName *p) {} //abstract class

void ShowAbsyn::visitNoEvName(NoEvName *p)
{
  bufAppend("NoEvName");
}
void ShowAbsyn::visitEvName(EvName *p)
{
  bufAppend('(');
  bufAppend("EvName");
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEventParam(EventParam *p) {} //abstract class

void ShowAbsyn::visitEventParamWithName(EventParamWithName *p)
{
  bufAppend('(');
  bufAppend("EventParamWithName");
  bufAppend(' ');
  bufAppend('[');
  if (p->eventorcond_)  p->eventorcond_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(')');
}
void ShowAbsyn::visitEventParamNoName(EventParamNoName *p)
{
  bufAppend('(');
  bufAppend("EventParamNoName");
  bufAppend(' ');
  bufAppend('[');
  if (p->eventorcond_)  p->eventorcond_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitListEventParam(ListEventParam *listeventparam)
{
  for (ListEventParam::const_iterator i = listeventparam->begin() ; i != listeventparam->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listeventparam->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitEventOrCond(EventOrCond *p) {} //abstract class

void ShowAbsyn::visitCSEventCond(CSEventCond *p)
{
  bufAppend('(');
  bufAppend("CSEventCond");
  bufAppend(' ');
  bufAppend('[');
  if (p->channelspecifier_)  p->channelspecifier_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitListEvOr(ListEvOr *p)
{
  bufAppend('(');
  bufAppend("ListEvOr");
  bufAppend(' ');
  bufAppend('[');
  if (p->listeventorlist_)  p->listeventorlist_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEventOrList(EventOrList *p) {} //abstract class

void ShowAbsyn::visitEventOrListChannelSpecifier(EventOrListChannelSpecifier *p)
{
  bufAppend('(');
  bufAppend("EventOrListChannelSpecifier");
  bufAppend(' ');
  bufAppend('[');
  if (p->channelspecifier_)  p->channelspecifier_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitListEventOrList(ListEventOrList *listeventorlist)
{
  for (ListEventOrList::const_iterator i = listeventorlist->begin() ; i != listeventorlist->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listeventorlist->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitStructDef(StructDef *p) {} //abstract class

void ShowAbsyn::visitDefSubstor(DefSubstor *p)
{
  bufAppend('(');
  bufAppend("DefSubstor");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitDefFunction(DefFunction *p)
{
  bufAppend('(');
  bufAppend("DefFunction");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(' ');
  bufAppend('[');
  if (p->listfuncparam_)  p->listfuncparam_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->liststatement_)  p->liststatement_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitListStructDef(ListStructDef *liststructdef)
{
  for (ListStructDef::const_iterator i = liststructdef->begin() ; i != liststructdef->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != liststructdef->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitFuncParam(FuncParam *p) {} //abstract class

void ShowAbsyn::visitFuncParam1(FuncParam1 *p)
{
  bufAppend('(');
  bufAppend("FuncParam1");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(')');
}
void ShowAbsyn::visitListFuncParam(ListFuncParam *listfuncparam)
{
  for (ListFuncParam::const_iterator i = listfuncparam->begin() ; i != listfuncparam->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listfuncparam->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitOptionalType(OptionalType *p) {} //abstract class

void ShowAbsyn::visitNoType(NoType *p)
{
  bufAppend("NoType");
}
void ShowAbsyn::visitTypeSpec(TypeSpec *p)
{
  bufAppend('(');
  bufAppend("TypeSpec");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitStatement(Statement *p) {} //abstract class

void ShowAbsyn::visitVarStmt(VarStmt *p)
{
  bufAppend('(');
  bufAppend("VarStmt");
  bufAppend(' ');
  bufAppend('[');
  if (p->optionaltype_)  p->optionaltype_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(' ');
  bufAppend('[');
  if (p->varassignment_)  p->varassignment_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitAssignStmt(AssignStmt *p)
{
  bufAppend('(');
  bufAppend("AssignStmt");
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitAssignArrStmt(AssignArrStmt *p)
{
  bufAppend('(');
  bufAppend("AssignArrStmt");
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitIfStmt(IfStmt *p)
{
  bufAppend('(');
  bufAppend("IfStmt");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->block_)  p->block_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->elseblock_)  p->elseblock_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitBlockStmt(BlockStmt *p)
{
  bufAppend('(');
  bufAppend("BlockStmt");
  bufAppend(' ');
  bufAppend('[');
  if (p->block_)  p->block_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitPushStmt(PushStmt *p)
{
  bufAppend('(');
  bufAppend("PushStmt");
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(' ');
  bufAppend('[');
  if (p->pushsubdest_)  p->pushsubdest_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitStaticForStmt(StaticForStmt *p)
{
  bufAppend('(');
  bufAppend("StaticForStmt");
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(' ');
  bufAppend('[');
  if (p->block_)  p->block_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitStaticIfStmt(StaticIfStmt *p)
{
  bufAppend('(');
  bufAppend("StaticIfStmt");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->block_)  p->block_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitReturnStmt(ReturnStmt *p)
{
  bufAppend('(');
  bufAppend("ReturnStmt");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitWaitUntilStmt(WaitUntilStmt *p)
{
  bufAppend('(');
  bufAppend("WaitUntilStmt");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitListStatement(ListStatement *liststatement)
{
  for (ListStatement::const_iterator i = liststatement->begin() ; i != liststatement->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != liststatement->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitPushSubDest(PushSubDest *p) {} //abstract class

void ShowAbsyn::visitPushSubreg(PushSubreg *p)
{
  bufAppend('(');
  bufAppend("PushSubreg");
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(')');
}
void ShowAbsyn::visitPushArray(PushArray *p)
{
  bufAppend('(');
  bufAppend("PushArray");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitPushArrayDot(PushArrayDot *p)
{
  bufAppend('(');
  bufAppend("PushArrayDot");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(')');
}
void ShowAbsyn::visitPushReg(PushReg *p)
{
  bufAppend("PushReg");
}
void ShowAbsyn::visitVarAssignment(VarAssignment *p) {} //abstract class

void ShowAbsyn::visitVarAssign(VarAssign *p)
{
  bufAppend('(');
  bufAppend("VarAssign");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitNoVarAssign(NoVarAssign *p)
{
  bufAppend("NoVarAssign");
}
void ShowAbsyn::visitBlock(Block *p) {} //abstract class

void ShowAbsyn::visitBlock1(Block1 *p)
{
  bufAppend('(');
  bufAppend("Block1");
  bufAppend(' ');
  bufAppend('[');
  if (p->listblockattr_)  p->listblockattr_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->liststatement_)  p->liststatement_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitBlockAttr(BlockAttr *p) {} //abstract class

void ShowAbsyn::visitBlockAttr_atomic(BlockAttr_atomic *p)
{
  bufAppend("BlockAttr_atomic");
}
void ShowAbsyn::visitBlockAttr_xact(BlockAttr_xact *p)
{
  bufAppend("BlockAttr_xact");
}
void ShowAbsyn::visitListBlockAttr(ListBlockAttr *listblockattr)
{
  for (ListBlockAttr::const_iterator i = listblockattr->begin() ; i != listblockattr->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listblockattr->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitElseBlock(ElseBlock *p) {} //abstract class

void ShowAbsyn::visitElseIf(ElseIf *p)
{
  bufAppend('(');
  bufAppend("ElseIf");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->block_)  p->block_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->elseblock_)  p->elseblock_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitElse(Else *p)
{
  bufAppend('(');
  bufAppend("Else");
  bufAppend(' ');
  bufAppend('[');
  if (p->block_)  p->block_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitNoElse(NoElse *p)
{
  bufAppend("NoElse");
}
void ShowAbsyn::visitExp(Exp *p) {} //abstract class

void ShowAbsyn::visitEVoid(EVoid *p)
{
  bufAppend("EVoid");
}
void ShowAbsyn::visitETrue(ETrue *p)
{
  bufAppend("ETrue");
}
void ShowAbsyn::visitEFalse(EFalse *p)
{
  bufAppend("EFalse");
}
void ShowAbsyn::visitEInt(EInt *p)
{
  bufAppend('(');
  bufAppend("EInt");
  bufAppend(' ');
  visitInteger(p->integer_);
  bufAppend(')');
}
void ShowAbsyn::visitEHex(EHex *p)
{
  bufAppend('(');
  bufAppend("EHex");
  bufAppend(' ');
  visitIdent(p->hexinteger_);
  bufAppend(')');
}
void ShowAbsyn::visitEDouble(EDouble *p)
{
  bufAppend('(');
  bufAppend("EDouble");
  bufAppend(' ');
  visitDouble(p->double_);
  bufAppend(')');
}
void ShowAbsyn::visitEString(EString *p)
{
  bufAppend('(');
  bufAppend("EString");
  bufAppend(' ');
  visitString(p->string_);
  bufAppend(')');
}
void ShowAbsyn::visitEStructLiteral(EStructLiteral *p)
{
  bufAppend('(');
  bufAppend("EStructLiteral");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->liststructliteralfield_)  p->liststructliteralfield_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEVectorLiteral(EVectorLiteral *p)
{
  bufAppend('(');
  bufAppend("EVectorLiteral");
  bufAppend(' ');
  bufAppend('[');
  if (p->listexp_)  p->listexp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEId(EId *p)
{
  bufAppend('(');
  bufAppend("EId");
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(')');
}
void ShowAbsyn::visitEArrAcc(EArrAcc *p)
{
  bufAppend('(');
  bufAppend("EArrAcc");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitESlice(ESlice *p)
{
  bufAppend('(');
  bufAppend("ESlice");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(' ');
  p->exp_3->accept(this);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEDot(EDot *p)
{
  bufAppend('(');
  bufAppend("EDot");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(')');
}
void ShowAbsyn::visitENeg(ENeg *p)
{
  bufAppend('(');
  bufAppend("ENeg");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEAndB(EAndB *p)
{
  bufAppend('(');
  bufAppend("EAndB");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEOrB(EOrB *p)
{
  bufAppend('(');
  bufAppend("EOrB");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEXOR(EXOR *p)
{
  bufAppend('(');
  bufAppend("EXOR");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEShR(EShR *p)
{
  bufAppend('(');
  bufAppend("EShR");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEShL(EShL *p)
{
  bufAppend('(');
  bufAppend("EShL");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitERotR(ERotR *p)
{
  bufAppend('(');
  bufAppend("ERotR");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitERotL(ERotL *p)
{
  bufAppend('(');
  bufAppend("ERotL");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitETimes(ETimes *p)
{
  bufAppend('(');
  bufAppend("ETimes");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEDiv(EDiv *p)
{
  bufAppend('(');
  bufAppend("EDiv");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEPlus(EPlus *p)
{
  bufAppend('(');
  bufAppend("EPlus");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEMinus(EMinus *p)
{
  bufAppend('(');
  bufAppend("EMinus");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitELt(ELt *p)
{
  bufAppend('(');
  bufAppend("ELt");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEGt(EGt *p)
{
  bufAppend('(');
  bufAppend("EGt");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitELtEq(ELtEq *p)
{
  bufAppend('(');
  bufAppend("ELtEq");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEGtEq(EGtEq *p)
{
  bufAppend('(');
  bufAppend("EGtEq");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEEq(EEq *p)
{
  bufAppend('(');
  bufAppend("EEq");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitENEq(ENEq *p)
{
  bufAppend('(');
  bufAppend("ENEq");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEAnd(EAnd *p)
{
  bufAppend('(');
  bufAppend("EAnd");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEOr(EOr *p)
{
  bufAppend('(');
  bufAppend("EOr");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitListExp(ListExp *listexp)
{
  for (ListExp::const_iterator i = listexp->begin() ; i != listexp->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listexp->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitPackageName(PackageName *p) {} //abstract class

void ShowAbsyn::visitPackageNameId(PackageNameId *p)
{
  bufAppend('(');
  bufAppend("PackageNameId");
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(')');
}
void ShowAbsyn::visitListPackageName(ListPackageName *listpackagename)
{
  for (ListPackageName::const_iterator i = listpackagename->begin() ; i != listpackagename->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listpackagename->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitStructLiteralField(StructLiteralField *p) {} //abstract class

void ShowAbsyn::visitStructLiteralField1(StructLiteralField1 *p)
{
  bufAppend('(');
  bufAppend("StructLiteralField1");
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitListStructLiteralField(ListStructLiteralField *liststructliteralfield)
{
  for (ListStructLiteralField::const_iterator i = liststructliteralfield->begin() ; i != liststructliteralfield->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != liststructliteralfield->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitIntOrName(IntOrName *p) {} //abstract class

void ShowAbsyn::visitConstName(ConstName *p)
{
  bufAppend('(');
  bufAppend("ConstName");
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(')');
}
void ShowAbsyn::visitInt(Int *p)
{
  bufAppend('(');
  bufAppend("Int");
  bufAppend(' ');
  visitInteger(p->integer_);
  bufAppend(')');
}
void ShowAbsyn::visitType(Type *p) {} //abstract class

void ShowAbsyn::visitTyName(TyName *p)
{
  bufAppend('(');
  bufAppend("TyName");
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(')');
}
void ShowAbsyn::visitTyVoid(TyVoid *p)
{
  bufAppend("TyVoid");
}
void ShowAbsyn::visitTyType(TyType *p)
{
  bufAppend("TyType");
}
void ShowAbsyn::visitTyNameParams(TyNameParams *p)
{
  bufAppend('(');
  bufAppend("TyNameParams");
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(' ');
  bufAppend('[');
  if (p->listtemplatearg_)  p->listtemplatearg_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitTyArray(TyArray *p)
{
  bufAppend('(');
  bufAppend("TyArray");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->intorname_)  p->intorname_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitTyVector(TyVector *p)
{
  bufAppend('(');
  bufAppend("TyVector");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->intorname_)  p->intorname_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitTemplateExp(TemplateExp *p) {} //abstract class

void ShowAbsyn::visitTEType(TEType *p)
{
  bufAppend('(');
  bufAppend("TEType");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitTEConstExp(TEConstExp *p)
{
  bufAppend('(');
  bufAppend("TEConstExp");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitTemplateArg(TemplateArg *p) {} //abstract class

void ShowAbsyn::visitTemplateArg1(TemplateArg1 *p)
{
  bufAppend('(');
  bufAppend("TemplateArg1");
  bufAppend(' ');
  visitIdent(p->id_);
  bufAppend(' ');
  bufAppend('[');
  if (p->templateexp_)  p->templateexp_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitListTemplateArg(ListTemplateArg *listtemplatearg)
{
  for (ListTemplateArg::const_iterator i = listtemplatearg->begin() ; i != listtemplatearg->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listtemplatearg->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitInteger(Integer i)
{
  char tmp[16];
  sprintf(tmp, "%d", i);
  bufAppend(tmp);
}
void ShowAbsyn::visitDouble(Double d)
{
  char tmp[16];
  sprintf(tmp, "%g", d);
  bufAppend(tmp);
}
void ShowAbsyn::visitChar(Char c)
{
  bufAppend('\'');
  bufAppend(c);
  bufAppend('\'');
}
void ShowAbsyn::visitString(String s)
{
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}
void ShowAbsyn::visitIdent(String s)
{
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}

void ShowAbsyn::visitId(String s)
{
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}


void ShowAbsyn::visitHexInteger(String s)
{
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}



