/*=========================================================================
 
Program:   openCherry Platform
Language:  C++
Date:      $Date$
Version:   $Revision$
 
Copyright (c) German Cancer Research Center, Division of Medical and
Biological Informatics. All rights reserved.
See MITKCopyright.txt or http://www.mitk.org/copyright.html for details.
 
This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notices for more information.
 
=========================================================================*/

#include "cherryCompositeExpression.h"

#include "Poco/Hash.h"

namespace cherry
{

const intptr_t CompositeExpression::HASH_INITIAL = Poco::Hash<std::string>()("cherry::CompositeExpression");

void CompositeExpression::Add(Expression::Pointer expression)
{
  fExpressions.push_back(expression);
}

void CompositeExpression::GetChildren(std::vector<Expression::Pointer>& children)
{
  children = fExpressions;
}

EvaluationResult CompositeExpression::EvaluateAnd(IEvaluationContext* scope)
{
  if (fExpressions.size() == 0)
    return EvaluationResult::TRUE;
  EvaluationResult result = EvaluationResult::TRUE;
  std::vector<Expression::Pointer>::iterator iter;
  for (iter= fExpressions.begin(); iter != fExpressions.end(); ++iter)
  {
    result = result.And((*iter)->Evaluate(scope));
    // keep iterating even if we have a not loaded found. It can be
    // that we find a false which will result in a better result.
    if (result == EvaluationResult::FALSE)
      return result;
  }
  return result;
}

EvaluationResult CompositeExpression::EvaluateOr(IEvaluationContext* scope)
{
  if (fExpressions.size() == 0)
    return EvaluationResult::TRUE;
  EvaluationResult result = EvaluationResult::FALSE;
  std::vector<Expression::Pointer>::iterator iter;
  for (iter= fExpressions.begin(); iter != fExpressions.end(); ++iter)
  {
    result = result.Or((*iter)->Evaluate(scope));
    if (result == EvaluationResult::TRUE)
      return result;
  }
  return result;
}

void CompositeExpression::CollectExpressionInfo(ExpressionInfo* info)
{
  if (fExpressions.size() == 0)
    return;
  
  std::vector<Expression::Pointer>::iterator iter;
  for (iter= fExpressions.begin(); iter != fExpressions.end(); ++iter)
  {
    (*iter)->CollectExpressionInfo(info);
  }
}

intptr_t CompositeExpression::ComputeHashCode()
{
  return HASH_INITIAL * HASH_FACTOR + this->HashCode(fExpressions);
}

} // namespace cherry
