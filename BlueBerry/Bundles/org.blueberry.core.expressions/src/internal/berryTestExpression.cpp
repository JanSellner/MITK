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

#include "berryTestExpression.h"

#include "berryExpressions.h"
#include "berryExpressionStatus.h"

#include "berryPlatform.h"
#include "berryCoreException.h"

#include <berryObjectString.h>
#include <berryIConfigurationElement.h>

namespace berry {

const QChar TestExpression::PROP_SEP = '.';
const QString TestExpression::ATT_PROPERTY = "property";
const QString TestExpression::ATT_ARGS = "args";
const QString TestExpression::ATT_FORCE_PLUGIN_ACTIVATION = "forcePluginActivation";

TypeExtensionManager TestExpression::fgTypeExtensionManager("propertyTesters");

const uint TestExpression::HASH_INITIAL= qHash("berry::TextExpression");


TestExpression::TestExpression(const IConfigurationElement::Pointer& element)
{
  QString property = element->GetAttribute(ATT_PROPERTY);
  int pos = property.lastIndexOf(PROP_SEP);
  if (pos == -1)
  {
    IStatus::Pointer status(new ExpressionStatus(
                              ExpressionStatus::NO_NAMESPACE_PROVIDED,
                              "The property attribute of the test expression must be qualified by a name space.",
                              BERRY_STATUS_LOC));
    throw CoreException(status);
  }
  fNamespace = property.left(pos);
  fProperty = property.mid(pos + 1);
  fArgs = Expressions::GetArguments(element, ATT_ARGS);
  fExpectedValue = Expressions::ConvertArgument(element->GetAttribute(ATT_VALUE));
  fForcePluginActivation = Expressions::GetOptionalBooleanAttribute(element, ATT_FORCE_PLUGIN_ACTIVATION);
}

TestExpression::TestExpression(Poco::XML::Element* element)
{
  QString property= QString::fromStdString(element->getAttribute(ATT_PROPERTY.toStdString()));
  int pos = property.lastIndexOf(PROP_SEP);
  if (pos == -1)
  {
    IStatus::Pointer status(new ExpressionStatus(
                              ExpressionStatus::NO_NAMESPACE_PROVIDED,
                              "The property attribute of the test expression must be qualified by a name space.",
                              BERRY_STATUS_LOC));
    throw CoreException(status);
  }
  fNamespace = property.left(pos);
  fProperty = property.mid(pos + 1);
  fArgs = Expressions::GetArguments(element, ATT_ARGS);
  std::string value = element->getAttribute(ATT_VALUE.toStdString());
  fExpectedValue = Expressions::ConvertArgument(value.size() > 0 ? QString::fromStdString(value) : QString());
  fForcePluginActivation = Expressions::GetOptionalBooleanAttribute(element, ATT_FORCE_PLUGIN_ACTIVATION);
}

TestExpression::TestExpression(const QString& namespaze, const QString& property,
                               const QList<Object::Pointer>& args, Object::Pointer expectedValue)
  : fNamespace(namespaze), fProperty(property), fArgs(args),
    fExpectedValue(expectedValue), fForcePluginActivation(false)
{
}

TestExpression::TestExpression(const QString &namespaze, const QString &property, const QList<Object::Pointer>& args,
                               Object::Pointer expectedValue, bool forcePluginActivation)
 : fNamespace(namespaze), fProperty(property), fArgs(args),
   fExpectedValue(expectedValue), fForcePluginActivation(forcePluginActivation)
{
}

EvaluationResult::ConstPointer
TestExpression::Evaluate(IEvaluationContext* context) const
{
  Object::Pointer element(context->GetDefaultVariable());
  if (typeid(Platform) == typeid(element.GetPointer()))
  {
    QString str = Platform::GetProperty(fProperty);
    if (str.isEmpty())
    {
      return EvaluationResult::FALSE_EVAL;
    }

    ObjectString::Pointer var = fArgs[0].Cast<ObjectString>();
    if (var)
      return EvaluationResult::ValueOf(static_cast<QString&>(*var) == str);

    return EvaluationResult::FALSE_EVAL;
  }

  Property::Pointer property= fgTypeExtensionManager.GetProperty(element, fNamespace, fProperty, context->GetAllowPluginActivation() && fForcePluginActivation);
  if (!property->IsInstantiated())
    return EvaluationResult::NOT_LOADED;
  return EvaluationResult::ValueOf(property->Test(element, fArgs, fExpectedValue));
}

void
TestExpression::CollectExpressionInfo(ExpressionInfo* info)
{
  info->MarkDefaultVariableAccessed();
  info->AddAccessedPropertyName(fNamespace + PROP_SEP + fProperty);
}

bool
TestExpression::operator==(const Object* object) const
{
  if (const TestExpression* that = dynamic_cast<const TestExpression*>(object))
  {
    return this->fNamespace == that->fNamespace &&
            this->fProperty == that->fProperty &&
            this->fForcePluginActivation == that->fForcePluginActivation &&
            this->Equals(this->fArgs, that->fArgs) &&
            this->fExpectedValue == that->fExpectedValue;
  }
  return false;
}

uint TestExpression::ComputeHashCode()
{
  return HASH_INITIAL * HASH_FACTOR + this->HashCode(fArgs)
  * HASH_FACTOR + fExpectedValue->HashCode()
  * HASH_FACTOR + qHash(fNamespace)
  * HASH_FACTOR + qHash(fProperty)
  * HASH_FACTOR + (fForcePluginActivation ? 1 : 0);
}

QString
TestExpression::ToString() const
{
  QString args("");
  for (unsigned int i= 0; i < fArgs.size(); i++)
  {
    Object::Pointer arg= fArgs[i];
    ObjectString::Pointer strarg = arg.Cast<ObjectString>();
    if (strarg)
    {
      args.append('\'');
      args.append(static_cast<QString&>(*strarg));
      args.append('\'');
    }
    else
    {
      args.append(arg->ToString());
    }
    if (i < fArgs.size() - 1)
    args.append(", ");
  }

  return "<test property=\"" + fProperty +
      (!fArgs.isEmpty() ? "\" args=\"" + args + "\"" : "\"") +
      (!fExpectedValue.IsNull() ? "\" value=\"" + fExpectedValue->ToString() + "\"" : "\"") +
      " plug-in activation: " + (fForcePluginActivation ? "eager" : "lazy") + "/>";
}

//---- testing ---------------------------------------------------

bool
TestExpression::TestGetForcePluginActivation()
{
  return fForcePluginActivation;
}

TypeExtensionManager&
TestExpression::TestGetTypeExtensionManager()
{
  return fgTypeExtensionManager;
}

}
