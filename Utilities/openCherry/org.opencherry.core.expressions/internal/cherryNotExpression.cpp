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

#include "cherryNotExpression.h"

#include "Poco/Exception.h"

namespace cherry {

const intptr_t NotExpression::HASH_INITIAL = Poco::Hash<std::string>()("cherry::NotExpression");

NotExpression::NotExpression(Expression::Pointer expression)
{
  if (expression.IsNull())
    throw Poco::AssertionViolationException("expression must not be null");
  
  fExpression= expression;
}

EvaluationResult
NotExpression::Evaluate(IEvaluationContext* context)
{
  return fExpression->Evaluate(context).Not();
}

void
NotExpression::CollectExpressionInfo(ExpressionInfo* info)
{
  fExpression->CollectExpressionInfo(info);
}

bool
NotExpression::operator==(Expression& object)
{
  try {
    NotExpression& that = dynamic_cast<NotExpression&>(object);
    return this->fExpression == that.fExpression;
  }
  catch (std::bad_cast)
  {
    return false;
  }  
}

intptr_t
NotExpression::ComputeHashCode()
{
  return HASH_INITIAL * HASH_FACTOR + fExpression->HashCode();
}

}
