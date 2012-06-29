/*===================================================================

BlueBerry Platform

Copyright (c) German Cancer Research Center,
Division of Medical and Biological Informatics.
All rights reserved.

This software is distributed WITHOUT ANY WARRANTY; without
even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE.

See LICENSE.txt or http://www.mitk.org for details.

===================================================================*/

#include "berryHandlerUtil.h"

#include <berryIEvaluationContext.h>
#include <berryCommandExceptions.h>

#include "berryISources.h"

namespace berry
{

void HandlerUtil::NoVariableFound(ExecutionEvent::Pointer event,
    const QString& name)
{
  throw ExecutionException("No " + name +
                           " found while executing " + event->GetCommand()->GetId());
}

void HandlerUtil::IncorrectTypeFound(ExecutionEvent::Pointer event,
    const QString& name, const QString& expectedType,
    const QString& wrongType)
{
  throw ExecutionException("Incorrect type for "
      + name
      + " found while executing "
      + event->GetCommand()->GetId()
      + ", expected " + expectedType
      + " found " + wrongType);
}

Object::Pointer HandlerUtil::GetVariable(
    ExecutionEvent::Pointer event, const QString& name)
{
  if (IEvaluationContext::ConstPointer evalContext = event->GetApplicationContext().Cast<const IEvaluationContext>())
  {
    Object::Pointer var = evalContext->GetVariable(name);
    return var == IEvaluationContext::UNDEFINED_VARIABLE ? Object::Pointer() : var;
  }
  return Object::Pointer();
}

Object::Pointer HandlerUtil::GetVariableChecked(
    ExecutionEvent::Pointer event, const QString& name)
{
  Object::Pointer o(HandlerUtil::GetVariable(event, name));
  if (o.IsNull())
  {
    HandlerUtil::NoVariableFound(event, name);
  }
  return o;
}

Object::Pointer HandlerUtil::GetVariable(
    Object::Pointer context, const QString& name)
{
  IEvaluationContext::Pointer eval(context.Cast<IEvaluationContext>());
  if (eval.IsNotNull())
  {
    Object::Pointer var = eval->GetVariable(name);
    return var == IEvaluationContext::UNDEFINED_VARIABLE ? Object::Pointer() : var;
  }
  return Object::Pointer(0);
}

HandlerUtil::StringVectorType::Pointer HandlerUtil::GetActiveContexts(
    ExecutionEvent::Pointer event)
{
  Object::Pointer o(HandlerUtil::GetVariable(event,
      ISources::ACTIVE_CONTEXT_NAME()));
  return o.Cast<StringVectorType>();
}

HandlerUtil::StringVectorType::Pointer HandlerUtil::GetActiveContextsChecked(
    ExecutionEvent::Pointer event)
{
  Object::Pointer o(HandlerUtil::GetVariableChecked(event,
      ISources::ACTIVE_CONTEXT_NAME()));
  if (o.Cast<StringVectorType>().IsNull())
  {
    HandlerUtil::IncorrectTypeFound(event, ISources::ACTIVE_CONTEXT_NAME(),
        "StringVectorType", o->GetClassName());
  }
  return o.Cast<StringVectorType>();
}

//IEditorPart::Pointer HandlerUtil::GetActiveEditor(ExecutionEvent::Pointer event)
//{
//  Object::Pointer o(HandlerUtil::GetVariable(event,
//      ISources::ACTIVE_EDITOR_NAME));
//  return o.Cast<IEditorPart>();
//}

//IEditorPart::Pointer HandlerUtil::GetActiveEditorChecked(
//    ExecutionEvent::Pointer event)
//{
//  Object::Pointer o = HandlerUtil::GetVariableChecked(event,
//      ISources::ACTIVE_EDITOR_NAME);
//  if (o.Cast<IEditorPart>().IsNull())
//  {
//    HandlerUtil::IncorrectTypeFound(event, ISources::ACTIVE_EDITOR_NAME,
//        "IEditorPart", o->GetClassName());
//  }
//  return (IEditorPart) o;
//}

ObjectString::Pointer HandlerUtil::GetActiveEditorId(ExecutionEvent::Pointer event)
{
  Object::Pointer o = HandlerUtil::GetVariable(event,
      ISources::ACTIVE_EDITOR_ID_NAME());
  return o.Cast<ObjectString>();
}

ObjectString::Pointer HandlerUtil::GetActiveEditorIdChecked(
    ExecutionEvent::Pointer event)
{
  Object::Pointer o = HandlerUtil::GetVariableChecked(event,
      ISources::ACTIVE_EDITOR_ID_NAME());
  if (o.Cast<ObjectString>().IsNull())
  {
    HandlerUtil::IncorrectTypeFound(event, ISources::ACTIVE_EDITOR_ID_NAME(),
        "QString", o->GetClassName());
  }
  return o.Cast<ObjectString>();
}

IWorkbenchPart::Pointer HandlerUtil::GetActivePart(ExecutionEvent::Pointer event)
{
  Object::Pointer o = HandlerUtil::GetVariable(event,
      ISources::ACTIVE_PART_NAME());
  return o.Cast<IWorkbenchPart>();
}

IWorkbenchPart::Pointer HandlerUtil::GetActivePartChecked(
    ExecutionEvent::Pointer event)
{
  Object::Pointer o = HandlerUtil::GetVariableChecked(event,
      ISources::ACTIVE_PART_NAME());
  if (o.Cast<IWorkbenchPart>().IsNull())
  {
    HandlerUtil::IncorrectTypeFound(event, ISources::ACTIVE_PART_NAME(),
        "IWorkbenchPart", o->GetClassName());
  }
  return o.Cast<IWorkbenchPart>();
}

ObjectString::Pointer HandlerUtil::GetActivePartId(ExecutionEvent::Pointer event)
{
  Object::Pointer o = HandlerUtil::GetVariable(event,
      ISources::ACTIVE_PART_ID_NAME());
  return o.Cast<ObjectString>();
}

ObjectString::Pointer HandlerUtil::GetActivePartIdChecked(
    ExecutionEvent::Pointer event)
{
  Object::Pointer o = HandlerUtil::GetVariableChecked(event,
      ISources::ACTIVE_PART_ID_NAME());
  if (o.Cast<ObjectString>().IsNull())
  {
    HandlerUtil::IncorrectTypeFound(event, ISources::ACTIVE_PART_ID_NAME(),
        "QString", o->GetClassName());
  }
  return o.Cast<ObjectString>();
}

IWorkbenchPartSite::Pointer HandlerUtil::GetActiveSite(
    ExecutionEvent::Pointer event)
{
  Object::Pointer o = HandlerUtil::GetVariable(event,
      ISources::ACTIVE_SITE_NAME());
  return o.Cast<IWorkbenchPartSite>();
}

IWorkbenchPartSite::Pointer HandlerUtil::GetActiveSiteChecked(
    ExecutionEvent::Pointer event)
{
  Object::Pointer o = HandlerUtil::GetVariableChecked(event,
      ISources::ACTIVE_SITE_NAME());
  if (o.Cast<IWorkbenchPartSite>().IsNull())
  {
    HandlerUtil::IncorrectTypeFound(event, ISources::ACTIVE_SITE_NAME(),
        "IWorkbenchSitePart", o->GetClassName());
  }
  return o.Cast<IWorkbenchPartSite>();
}

ISelection::Pointer HandlerUtil::GetCurrentSelection(
    ExecutionEvent::Pointer event)
{
  Object::Pointer o = HandlerUtil::GetVariable(event,
      ISources::ACTIVE_CURRENT_SELECTION_NAME());
  return o.Cast<ISelection>();
}

ISelection::Pointer HandlerUtil::GetCurrentSelectionChecked(
    ExecutionEvent::Pointer event)
{
  Object::Pointer o = HandlerUtil::GetVariableChecked(event,
      ISources::ACTIVE_CURRENT_SELECTION_NAME());
  if (o.Cast<ISelection>().IsNull())
  {
    HandlerUtil::IncorrectTypeFound(event,
        ISources::ACTIVE_CURRENT_SELECTION_NAME(), "ISelection",
        o->GetClassName());
  }
  return o.Cast<ISelection>();
}

HandlerUtil::StringVectorType::Pointer HandlerUtil::GetActiveMenus(
    ExecutionEvent::Pointer event)
{
  Object::Pointer o = HandlerUtil::GetVariable(event,
      ISources::ACTIVE_MENU_NAME());
  return o.Cast<StringVectorType>();
}

HandlerUtil::StringVectorType::Pointer HandlerUtil::GetActiveMenusChecked(
    ExecutionEvent::Pointer event)
{
  Object::Pointer o = HandlerUtil::GetVariableChecked(event,
      ISources::ACTIVE_MENU_NAME());
  if (o.Cast<StringVectorType>().IsNull())
  {
    HandlerUtil::IncorrectTypeFound(event, ISources::ACTIVE_MENU_NAME(),
        "StringVectorType", o->GetClassName());
  }
  return o.Cast<StringVectorType>();
}

ISelection::Pointer HandlerUtil::GetActiveMenuSelection(
    ExecutionEvent::Pointer event)
{
  Object::Pointer o = HandlerUtil::GetVariable(event,
      ISources::ACTIVE_MENU_SELECTION_NAME());
  return o.Cast<ISelection>();
}

ISelection::Pointer HandlerUtil::GetActiveMenuSelectionChecked(
    ExecutionEvent::Pointer event)
{
  Object::Pointer o = HandlerUtil::GetVariableChecked(event,
      ISources::ACTIVE_MENU_SELECTION_NAME());
  if (o.Cast<ISelection>().IsNull())
  {
    HandlerUtil::IncorrectTypeFound(event,
        ISources::ACTIVE_MENU_SELECTION_NAME(), "ISelection", o->GetClassName());
  }
  return o.Cast<ISelection>();
}

IWorkbenchWindow::Pointer HandlerUtil::GetActiveWorkbenchWindow(
    ExecutionEvent::Pointer event)
{
  Object::Pointer o = HandlerUtil::GetVariable(event,
      ISources::ACTIVE_WORKBENCH_WINDOW_NAME());
  return o.Cast<IWorkbenchWindow>();
}

IWorkbenchWindow::Pointer HandlerUtil::GetActiveWorkbenchWindowChecked(
    ExecutionEvent::Pointer event)
{
  Object::Pointer o = HandlerUtil::GetVariableChecked(event,
      ISources::ACTIVE_WORKBENCH_WINDOW_NAME());
  if (o.Cast<IWorkbenchWindow>().IsNull())
  {
    HandlerUtil::IncorrectTypeFound(event,
        ISources::ACTIVE_WORKBENCH_WINDOW_NAME(), "IWorkbenchWindow",
        o->GetClassName());
  }
  return o.Cast<IWorkbenchWindow>();
}

ISelection::Pointer HandlerUtil::GetActiveMenuEditorInput(
    ExecutionEvent::Pointer event)
{
  Object::Pointer o = HandlerUtil::GetVariable(event,
      ISources::ACTIVE_MENU_EDITOR_INPUT_NAME());
  return o.Cast<ISelection>();
}

ISelection::Pointer HandlerUtil::GetActiveMenuEditorInputChecked(
    ExecutionEvent::Pointer event)
{
  Object::Pointer o = HandlerUtil::GetVariableChecked(event,
      ISources::ACTIVE_MENU_EDITOR_INPUT_NAME());
  if (o.Cast<ISelection>().IsNull())
  {
    HandlerUtil::IncorrectTypeFound(event,
        ISources::ACTIVE_MENU_EDITOR_INPUT_NAME(), "ISelection",
        o->GetClassName());
  }
  return o.Cast<ISelection>();
}

ISelection::Pointer HandlerUtil::GetShowInSelection(
    ExecutionEvent::Pointer event)
{
  Object::Pointer o = HandlerUtil::GetVariable(event,
      ISources::SHOW_IN_SELECTION());
  return o.Cast<ISelection>();
}

ISelection::Pointer HandlerUtil::GetShowInSelectionChecked(
    ExecutionEvent::Pointer event)
{
  Object::Pointer o = HandlerUtil::GetVariableChecked(event,
      ISources::SHOW_IN_SELECTION());
  if (o.Cast<ISelection>().IsNull())
  {
    HandlerUtil::IncorrectTypeFound(event, ISources::SHOW_IN_SELECTION(),
        "ISelection", o->GetClassName());
  }
  return o.Cast<ISelection>();
}

Object::Pointer HandlerUtil::GetShowInInput(
    ExecutionEvent::Pointer event)
{
  Object::Pointer var = HandlerUtil::GetVariable(event,
      ISources::SHOW_IN_INPUT());
  //    if (var == IEvaluationContext.UNDEFINED_VARIABLE) {
  //      return null;
  //    }
  return var;
}

Object::Pointer HandlerUtil::GetShowInInputChecked(
    ExecutionEvent::Pointer event)
{
  Object::Pointer var = HandlerUtil::GetVariableChecked(event,
      ISources::SHOW_IN_INPUT());
  //    if (var == IEvaluationContext.UNDEFINED_VARIABLE) {
  //      HandlerUtil::IncorrectTypeFound(event, ISources::SHOW_IN_INPUT, Object.class, var
  //          .getClass());
  //    }
  return var;
}

}
