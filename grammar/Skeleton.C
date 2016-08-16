/*** BNFC-Generated Visitor Design Pattern Skeleton. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "Skeleton.H"



void Skeleton::visitPackage(Package *t) {} //abstract class
void Skeleton::visitDef(Def *t) {} //abstract class
void Skeleton::visitMetaParamDecl(MetaParamDecl *t) {} //abstract class
void Skeleton::visitOptionalEqExp(OptionalEqExp *t) {} //abstract class
void Skeleton::visitMetaParam(MetaParam *t) {} //abstract class
void Skeleton::visitModDef(ModDef *t) {} //abstract class
void Skeleton::visitChannelSpecifier(ChannelSpecifier *t) {} //abstract class
void Skeleton::visitEventName(EventName *t) {} //abstract class
void Skeleton::visitEventParam(EventParam *t) {} //abstract class
void Skeleton::visitEventOrCond(EventOrCond *t) {} //abstract class
void Skeleton::visitEventOrList(EventOrList *t) {} //abstract class
void Skeleton::visitStructDef(StructDef *t) {} //abstract class
void Skeleton::visitFuncParam(FuncParam *t) {} //abstract class
void Skeleton::visitOptionalType(OptionalType *t) {} //abstract class
void Skeleton::visitStatement(Statement *t) {} //abstract class
void Skeleton::visitPushSubDest(PushSubDest *t) {} //abstract class
void Skeleton::visitVarAssignment(VarAssignment *t) {} //abstract class
void Skeleton::visitBlock(Block *t) {} //abstract class
void Skeleton::visitBlockAttr(BlockAttr *t) {} //abstract class
void Skeleton::visitElseBlock(ElseBlock *t) {} //abstract class
void Skeleton::visitExp(Exp *t) {} //abstract class
void Skeleton::visitPackageName(PackageName *t) {} //abstract class
void Skeleton::visitStructLiteralField(StructLiteralField *t) {} //abstract class
void Skeleton::visitIntOrName(IntOrName *t) {} //abstract class
void Skeleton::visitType(Type *t) {} //abstract class
void Skeleton::visitTemplateExp(TemplateExp *t) {} //abstract class
void Skeleton::visitTemplateArg(TemplateArg *t) {} //abstract class

void Skeleton::visitPDefs(PDefs *p_defs)
{
  /* Code For PDefs Goes Here */

  p_defs->listdef_->accept(this);

}

void Skeleton::visitDefImport(DefImport *def_import)
{
  /* Code For DefImport Goes Here */

  def_import->listpackagename_->accept(this);

}

void Skeleton::visitDefPackage(DefPackage *def_package)
{
  /* Code For DefPackage Goes Here */

  def_package->listpackagename_->accept(this);

}

void Skeleton::visitDefModule(DefModule *def_module)
{
  /* Code For DefModule Goes Here */

  visitId(def_module->id_);
  def_module->metaparamdecl_->accept(this);
  def_module->listmoddef_->accept(this);

}

void Skeleton::visitDefStruct(DefStruct *def_struct)
{
  /* Code For DefStruct Goes Here */

  visitId(def_struct->id_);
  def_struct->metaparamdecl_->accept(this);
  def_struct->liststructdef_->accept(this);

}

void Skeleton::visitNoParams(NoParams *no_params)
{
  /* Code For NoParams Goes Here */


}

void Skeleton::visitSomeParams(SomeParams *some_params)
{
  /* Code For SomeParams Goes Here */

  some_params->listmetaparam_->accept(this);

}

void Skeleton::visitEqExp(EqExp *eq_exp)
{
  /* Code For EqExp Goes Here */

  eq_exp->exp_->accept(this);

}

void Skeleton::visitNoEqExp(NoEqExp *no_eq_exp)
{
  /* Code For NoEqExp Goes Here */


}

void Skeleton::visitMetaParam1(MetaParam1 *meta_param)
{
  /* Code For MetaParam1 Goes Here */

  meta_param->type_->accept(this);
  visitId(meta_param->id_);
  meta_param->optionaleqexp_->accept(this);

}

void Skeleton::visitDefConst(DefConst *def_const)
{
  /* Code For DefConst Goes Here */

  def_const->type_->accept(this);
  visitId(def_const->id_);
  def_const->optionaleqexp_->accept(this);

}

void Skeleton::visitDefReg(DefReg *def_reg)
{
  /* Code For DefReg Goes Here */

  def_reg->type_->accept(this);
  visitId(def_reg->id_);

}

void Skeleton::visitDefMem(DefMem *def_mem)
{
  /* Code For DefMem Goes Here */

  def_mem->type_->accept(this);
  visitId(def_mem->id_);

}

void Skeleton::visitDefSubmodule(DefSubmodule *def_submodule)
{
  /* Code For DefSubmodule Goes Here */

  def_submodule->type_->accept(this);
  visitId(def_submodule->id_);

}

void Skeleton::visitDefInput(DefInput *def_input)
{
  /* Code For DefInput Goes Here */

  def_input->type_->accept(this);
  visitId(def_input->id_);

}

void Skeleton::visitDefOutput(DefOutput *def_output)
{
  /* Code For DefOutput Goes Here */

  def_output->type_->accept(this);
  visitId(def_output->id_);

}

void Skeleton::visitDefInternal(DefInternal *def_internal)
{
  /* Code For DefInternal Goes Here */

  def_internal->type_->accept(this);
  visitId(def_internal->id_);

}

void Skeleton::visitDefEvent(DefEvent *def_event)
{
  /* Code For DefEvent Goes Here */

  def_event->eventname_->accept(this);
  def_event->listeventparam_->accept(this);
  def_event->block_->accept(this);

}

void Skeleton::visitDefInit(DefInit *def_init)
{
  /* Code For DefInit Goes Here */

  def_init->eventname_->accept(this);
  def_init->block_->accept(this);

}

void Skeleton::visitDefConnect(DefConnect *def_connect)
{
  /* Code For DefConnect Goes Here */

  def_connect->channelspecifier_1->accept(this);
  def_connect->channelspecifier_2->accept(this);

}

void Skeleton::visitDefFor(DefFor *def_for)
{
  /* Code For DefFor Goes Here */

  visitId(def_for->id_);
  def_for->exp_1->accept(this);
  def_for->exp_2->accept(this);
  def_for->listmoddef_->accept(this);

}

void Skeleton::visitDefIf(DefIf *def_if)
{
  /* Code For DefIf Goes Here */

  def_if->exp_->accept(this);
  def_if->listmoddef_->accept(this);

}

void Skeleton::visitSimpleCS(SimpleCS *simple_cs)
{
  /* Code For SimpleCS Goes Here */

  visitId(simple_cs->id_);

}

void Skeleton::visitDotCS(DotCS *dot_cs)
{
  /* Code For DotCS Goes Here */

  visitId(dot_cs->id_1);
  visitId(dot_cs->id_2);

}

void Skeleton::visitArrayDotCS(ArrayDotCS *array_dot_cs)
{
  /* Code For ArrayDotCS Goes Here */

  visitId(array_dot_cs->id_1);
  array_dot_cs->exp_->accept(this);
  visitId(array_dot_cs->id_2);

}

void Skeleton::visitNoEvName(NoEvName *no_ev_name)
{
  /* Code For NoEvName Goes Here */


}

void Skeleton::visitEvName(EvName *ev_name)
{
  /* Code For EvName Goes Here */

  visitId(ev_name->id_);

}

void Skeleton::visitEventParamWithName(EventParamWithName *event_param_with_name)
{
  /* Code For EventParamWithName Goes Here */

  event_param_with_name->eventorcond_->accept(this);
  visitId(event_param_with_name->id_);

}

void Skeleton::visitEventParamNoName(EventParamNoName *event_param_no_name)
{
  /* Code For EventParamNoName Goes Here */

  event_param_no_name->eventorcond_->accept(this);

}

void Skeleton::visitCSEventCond(CSEventCond *cs_event_cond)
{
  /* Code For CSEventCond Goes Here */

  cs_event_cond->channelspecifier_->accept(this);

}

void Skeleton::visitListEvOr(ListEvOr *list_ev_or)
{
  /* Code For ListEvOr Goes Here */

  list_ev_or->listeventorlist_->accept(this);

}

void Skeleton::visitEventOrListChannelSpecifier(EventOrListChannelSpecifier *event_or_list_channel_specifier)
{
  /* Code For EventOrListChannelSpecifier Goes Here */

  event_or_list_channel_specifier->channelspecifier_->accept(this);

}

void Skeleton::visitDefSubstor(DefSubstor *def_substor)
{
  /* Code For DefSubstor Goes Here */

  def_substor->type_->accept(this);
  visitId(def_substor->id_);

}

void Skeleton::visitDefFunction(DefFunction *def_function)
{
  /* Code For DefFunction Goes Here */

  def_function->type_->accept(this);
  visitId(def_function->id_);
  def_function->listfuncparam_->accept(this);
  def_function->liststatement_->accept(this);

}

void Skeleton::visitFuncParam1(FuncParam1 *func_param)
{
  /* Code For FuncParam1 Goes Here */

  func_param->type_->accept(this);
  visitId(func_param->id_);

}

void Skeleton::visitNoType(NoType *no_type)
{
  /* Code For NoType Goes Here */


}

void Skeleton::visitTypeSpec(TypeSpec *type_spec)
{
  /* Code For TypeSpec Goes Here */

  type_spec->type_->accept(this);

}

void Skeleton::visitVarStmt(VarStmt *var_stmt)
{
  /* Code For VarStmt Goes Here */

  var_stmt->optionaltype_->accept(this);
  visitId(var_stmt->id_);
  var_stmt->varassignment_->accept(this);

}

void Skeleton::visitAssignStmt(AssignStmt *assign_stmt)
{
  /* Code For AssignStmt Goes Here */

  visitId(assign_stmt->id_);
  assign_stmt->exp_->accept(this);

}

void Skeleton::visitAssignArrStmt(AssignArrStmt *assign_arr_stmt)
{
  /* Code For AssignArrStmt Goes Here */

  visitId(assign_arr_stmt->id_);
  assign_arr_stmt->exp_1->accept(this);
  assign_arr_stmt->exp_2->accept(this);

}

void Skeleton::visitIfStmt(IfStmt *if_stmt)
{
  /* Code For IfStmt Goes Here */

  if_stmt->exp_->accept(this);
  if_stmt->block_->accept(this);
  if_stmt->elseblock_->accept(this);

}

void Skeleton::visitBlockStmt(BlockStmt *block_stmt)
{
  /* Code For BlockStmt Goes Here */

  block_stmt->block_->accept(this);

}

void Skeleton::visitPushStmt(PushStmt *push_stmt)
{
  /* Code For PushStmt Goes Here */

  visitId(push_stmt->id_);
  push_stmt->pushsubdest_->accept(this);
  push_stmt->exp_->accept(this);

}

void Skeleton::visitStaticForStmt(StaticForStmt *static_for_stmt)
{
  /* Code For StaticForStmt Goes Here */

  visitId(static_for_stmt->id_);
  static_for_stmt->exp_1->accept(this);
  static_for_stmt->exp_2->accept(this);
  static_for_stmt->block_->accept(this);

}

void Skeleton::visitStaticIfStmt(StaticIfStmt *static_if_stmt)
{
  /* Code For StaticIfStmt Goes Here */

  static_if_stmt->exp_->accept(this);
  static_if_stmt->block_->accept(this);

}

void Skeleton::visitReturnStmt(ReturnStmt *return_stmt)
{
  /* Code For ReturnStmt Goes Here */

  return_stmt->exp_->accept(this);

}

void Skeleton::visitWaitUntilStmt(WaitUntilStmt *wait_until_stmt)
{
  /* Code For WaitUntilStmt Goes Here */

  wait_until_stmt->exp_->accept(this);

}

void Skeleton::visitPushSubreg(PushSubreg *push_subreg)
{
  /* Code For PushSubreg Goes Here */

  visitId(push_subreg->id_);

}

void Skeleton::visitPushArray(PushArray *push_array)
{
  /* Code For PushArray Goes Here */

  push_array->exp_->accept(this);

}

void Skeleton::visitPushArrayDot(PushArrayDot *push_array_dot)
{
  /* Code For PushArrayDot Goes Here */

  push_array_dot->exp_->accept(this);
  visitId(push_array_dot->id_);

}

void Skeleton::visitPushReg(PushReg *push_reg)
{
  /* Code For PushReg Goes Here */


}

void Skeleton::visitVarAssign(VarAssign *var_assign)
{
  /* Code For VarAssign Goes Here */

  var_assign->exp_->accept(this);

}

void Skeleton::visitNoVarAssign(NoVarAssign *no_var_assign)
{
  /* Code For NoVarAssign Goes Here */


}

void Skeleton::visitBlock1(Block1 *block)
{
  /* Code For Block1 Goes Here */

  block->listblockattr_->accept(this);
  block->liststatement_->accept(this);

}

void Skeleton::visitBlockAttr_atomic(BlockAttr_atomic *block_attr_atomic)
{
  /* Code For BlockAttr_atomic Goes Here */


}

void Skeleton::visitBlockAttr_xact(BlockAttr_xact *block_attr_xact)
{
  /* Code For BlockAttr_xact Goes Here */


}

void Skeleton::visitElseIf(ElseIf *else_if)
{
  /* Code For ElseIf Goes Here */

  else_if->exp_->accept(this);
  else_if->block_->accept(this);
  else_if->elseblock_->accept(this);

}

void Skeleton::visitElse(Else *else_)
{
  /* Code For Else Goes Here */

  else_->block_->accept(this);

}

void Skeleton::visitNoElse(NoElse *no_else)
{
  /* Code For NoElse Goes Here */


}

void Skeleton::visitEVoid(EVoid *e_void)
{
  /* Code For EVoid Goes Here */


}

void Skeleton::visitETrue(ETrue *e_true)
{
  /* Code For ETrue Goes Here */


}

void Skeleton::visitEFalse(EFalse *e_false)
{
  /* Code For EFalse Goes Here */


}

void Skeleton::visitEInt(EInt *e_int)
{
  /* Code For EInt Goes Here */

  visitInteger(e_int->integer_);

}

void Skeleton::visitEHex(EHex *e_hex)
{
  /* Code For EHex Goes Here */

  visitHexInteger(e_hex->hexinteger_);

}

void Skeleton::visitEDouble(EDouble *e_double)
{
  /* Code For EDouble Goes Here */

  visitDouble(e_double->double_);

}

void Skeleton::visitEString(EString *e_string)
{
  /* Code For EString Goes Here */

  visitString(e_string->string_);

}

void Skeleton::visitEStructLiteral(EStructLiteral *e_struct_literal)
{
  /* Code For EStructLiteral Goes Here */

  e_struct_literal->type_->accept(this);
  e_struct_literal->liststructliteralfield_->accept(this);

}

void Skeleton::visitEVectorLiteral(EVectorLiteral *e_vector_literal)
{
  /* Code For EVectorLiteral Goes Here */

  e_vector_literal->listexp_->accept(this);

}

void Skeleton::visitEId(EId *e_id)
{
  /* Code For EId Goes Here */

  visitId(e_id->id_);

}

void Skeleton::visitEArrAcc(EArrAcc *e_arr_acc)
{
  /* Code For EArrAcc Goes Here */

  e_arr_acc->exp_1->accept(this);
  e_arr_acc->exp_2->accept(this);

}

void Skeleton::visitESlice(ESlice *e_slice)
{
  /* Code For ESlice Goes Here */

  e_slice->exp_1->accept(this);
  e_slice->exp_2->accept(this);
  e_slice->exp_3->accept(this);

}

void Skeleton::visitEDot(EDot *e_dot)
{
  /* Code For EDot Goes Here */

  e_dot->exp_->accept(this);
  visitId(e_dot->id_);

}

void Skeleton::visitENeg(ENeg *e_neg)
{
  /* Code For ENeg Goes Here */

  e_neg->exp_->accept(this);

}

void Skeleton::visitEAndB(EAndB *e_and_b)
{
  /* Code For EAndB Goes Here */

  e_and_b->exp_1->accept(this);
  e_and_b->exp_2->accept(this);

}

void Skeleton::visitEOrB(EOrB *e_or_b)
{
  /* Code For EOrB Goes Here */

  e_or_b->exp_1->accept(this);
  e_or_b->exp_2->accept(this);

}

void Skeleton::visitEXOR(EXOR *exor)
{
  /* Code For EXOR Goes Here */

  exor->exp_1->accept(this);
  exor->exp_2->accept(this);

}

void Skeleton::visitEShR(EShR *e_sh_r)
{
  /* Code For EShR Goes Here */

  e_sh_r->exp_1->accept(this);
  e_sh_r->exp_2->accept(this);

}

void Skeleton::visitEShL(EShL *e_sh_l)
{
  /* Code For EShL Goes Here */

  e_sh_l->exp_1->accept(this);
  e_sh_l->exp_2->accept(this);

}

void Skeleton::visitERotR(ERotR *e_rot_r)
{
  /* Code For ERotR Goes Here */

  e_rot_r->exp_1->accept(this);
  e_rot_r->exp_2->accept(this);

}

void Skeleton::visitERotL(ERotL *e_rot_l)
{
  /* Code For ERotL Goes Here */

  e_rot_l->exp_1->accept(this);
  e_rot_l->exp_2->accept(this);

}

void Skeleton::visitETimes(ETimes *e_times)
{
  /* Code For ETimes Goes Here */

  e_times->exp_1->accept(this);
  e_times->exp_2->accept(this);

}

void Skeleton::visitEDiv(EDiv *e_div)
{
  /* Code For EDiv Goes Here */

  e_div->exp_1->accept(this);
  e_div->exp_2->accept(this);

}

void Skeleton::visitEPlus(EPlus *e_plus)
{
  /* Code For EPlus Goes Here */

  e_plus->exp_1->accept(this);
  e_plus->exp_2->accept(this);

}

void Skeleton::visitEMinus(EMinus *e_minus)
{
  /* Code For EMinus Goes Here */

  e_minus->exp_1->accept(this);
  e_minus->exp_2->accept(this);

}

void Skeleton::visitELt(ELt *e_lt)
{
  /* Code For ELt Goes Here */

  e_lt->exp_1->accept(this);
  e_lt->exp_2->accept(this);

}

void Skeleton::visitEGt(EGt *e_gt)
{
  /* Code For EGt Goes Here */

  e_gt->exp_1->accept(this);
  e_gt->exp_2->accept(this);

}

void Skeleton::visitELtEq(ELtEq *e_lt_eq)
{
  /* Code For ELtEq Goes Here */

  e_lt_eq->exp_1->accept(this);
  e_lt_eq->exp_2->accept(this);

}

void Skeleton::visitEGtEq(EGtEq *e_gt_eq)
{
  /* Code For EGtEq Goes Here */

  e_gt_eq->exp_1->accept(this);
  e_gt_eq->exp_2->accept(this);

}

void Skeleton::visitEEq(EEq *e_eq)
{
  /* Code For EEq Goes Here */

  e_eq->exp_1->accept(this);
  e_eq->exp_2->accept(this);

}

void Skeleton::visitENEq(ENEq *en_eq)
{
  /* Code For ENEq Goes Here */

  en_eq->exp_1->accept(this);
  en_eq->exp_2->accept(this);

}

void Skeleton::visitEAnd(EAnd *e_and)
{
  /* Code For EAnd Goes Here */

  e_and->exp_1->accept(this);
  e_and->exp_2->accept(this);

}

void Skeleton::visitEOr(EOr *e_or)
{
  /* Code For EOr Goes Here */

  e_or->exp_1->accept(this);
  e_or->exp_2->accept(this);

}

void Skeleton::visitPackageNameId(PackageNameId *package_name_id)
{
  /* Code For PackageNameId Goes Here */

  visitId(package_name_id->id_);

}

void Skeleton::visitStructLiteralField1(StructLiteralField1 *struct_literal_field)
{
  /* Code For StructLiteralField1 Goes Here */

  visitId(struct_literal_field->id_);
  struct_literal_field->exp_->accept(this);

}

void Skeleton::visitConstName(ConstName *const_name)
{
  /* Code For ConstName Goes Here */

  visitId(const_name->id_);

}

void Skeleton::visitInt(Int *int_)
{
  /* Code For Int Goes Here */

  visitInteger(int_->integer_);

}

void Skeleton::visitTyName(TyName *ty_name)
{
  /* Code For TyName Goes Here */

  visitId(ty_name->id_);

}

void Skeleton::visitTyVoid(TyVoid *ty_void)
{
  /* Code For TyVoid Goes Here */


}

void Skeleton::visitTyType(TyType *ty_type)
{
  /* Code For TyType Goes Here */


}

void Skeleton::visitTyNameParams(TyNameParams *ty_name_params)
{
  /* Code For TyNameParams Goes Here */

  visitId(ty_name_params->id_);
  ty_name_params->listtemplatearg_->accept(this);

}

void Skeleton::visitTyArray(TyArray *ty_array)
{
  /* Code For TyArray Goes Here */

  ty_array->type_->accept(this);
  ty_array->intorname_->accept(this);

}

void Skeleton::visitTyVector(TyVector *ty_vector)
{
  /* Code For TyVector Goes Here */

  ty_vector->type_->accept(this);
  ty_vector->intorname_->accept(this);

}

void Skeleton::visitTEType(TEType *te_type)
{
  /* Code For TEType Goes Here */

  te_type->type_->accept(this);

}

void Skeleton::visitTEConstExp(TEConstExp *te_const_exp)
{
  /* Code For TEConstExp Goes Here */

  te_const_exp->exp_->accept(this);

}

void Skeleton::visitTemplateArg1(TemplateArg1 *template_arg)
{
  /* Code For TemplateArg1 Goes Here */

  visitId(template_arg->id_);
  template_arg->templateexp_->accept(this);

}


void Skeleton::visitListDef(ListDef *list_def)
{
  for (ListDef::iterator i = list_def->begin() ; i != list_def->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListMetaParam(ListMetaParam *list_meta_param)
{
  for (ListMetaParam::iterator i = list_meta_param->begin() ; i != list_meta_param->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListModDef(ListModDef *list_mod_def)
{
  for (ListModDef::iterator i = list_mod_def->begin() ; i != list_mod_def->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListEventParam(ListEventParam *list_event_param)
{
  for (ListEventParam::iterator i = list_event_param->begin() ; i != list_event_param->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListEventOrList(ListEventOrList *list_event_or_list)
{
  for (ListEventOrList::iterator i = list_event_or_list->begin() ; i != list_event_or_list->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListStructDef(ListStructDef *list_struct_def)
{
  for (ListStructDef::iterator i = list_struct_def->begin() ; i != list_struct_def->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListFuncParam(ListFuncParam *list_func_param)
{
  for (ListFuncParam::iterator i = list_func_param->begin() ; i != list_func_param->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListStatement(ListStatement *list_statement)
{
  for (ListStatement::iterator i = list_statement->begin() ; i != list_statement->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListBlockAttr(ListBlockAttr *list_block_attr)
{
  for (ListBlockAttr::iterator i = list_block_attr->begin() ; i != list_block_attr->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListExp(ListExp *list_exp)
{
  for (ListExp::iterator i = list_exp->begin() ; i != list_exp->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListPackageName(ListPackageName *list_package_name)
{
  for (ListPackageName::iterator i = list_package_name->begin() ; i != list_package_name->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListStructLiteralField(ListStructLiteralField *list_struct_literal_field)
{
  for (ListStructLiteralField::iterator i = list_struct_literal_field->begin() ; i != list_struct_literal_field->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListTemplateArg(ListTemplateArg *list_template_arg)
{
  for (ListTemplateArg::iterator i = list_template_arg->begin() ; i != list_template_arg->end() ; ++i)
  {
    (*i)->accept(this);
  }
}


void Skeleton::visitId(Id x)
{
  /* Code for Id Goes Here */
}

void Skeleton::visitHexInteger(HexInteger x)
{
  /* Code for HexInteger Goes Here */
}

void Skeleton::visitInteger(Integer x)
{
  /* Code for Integer Goes Here */
}

void Skeleton::visitChar(Char x)
{
  /* Code for Char Goes Here */
}

void Skeleton::visitDouble(Double x)
{
  /* Code for Double Goes Here */
}

void Skeleton::visitString(String x)
{
  /* Code for String Goes Here */
}

void Skeleton::visitIdent(Ident x)
{
  /* Code for Ident Goes Here */
}



