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

#ifndef CHERRYEVALUATIONCONTEXT_H_
#define CHERRYEVALUATIONCONTEXT_H_

#include "cherryIEvaluationContext.h"
#include "cherryIVariableResolver.h"

#include "Poco/Any.h"

#include <vector>
#include <map>

namespace cherry {

/**
 * A default implementation of an evaluation context.
 * <p>
 * Clients may instantiate this default context. The class is
 * not intended to be subclassed by clients.
 * </p> 
 * 
 * @since 3.0
 */
class CHERRY_API EvaluationContext : public IEvaluationContext 
{

private:
  IEvaluationContext* fParent;
  ExpressionVariable::Pointer fDefaultVariable;
  std::map<std::string, ExpressionVariable::Pointer> fVariables;
  std::vector<IVariableResolver*> fVariableResolvers;
  bool fAllowPluginActivation;
  
public:
  
  /**
   * Create a new evaluation context with the given parent and default
   * variable.
   * 
   * @param parent the parent context. Can be <code>null</code>.
   * @param defaultVariable the default variable
   */
  EvaluationContext(IEvaluationContext* parent, ExpressionVariable::Pointer defaultVariable);
  
  /**
   * Create a new evaluation context with the given parent and default
   * variable.
   * 
   * @param parent the parent context. Can be <code>null</code>.
   * @param defaultVariable the default variable
   * @param resolvers an array of <code>IVariableResolvers</code> to
   *  resolve additional variables.
   * 
   * @see #resolveVariable(String, Object[])
   */
  EvaluationContext(IEvaluationContext* parent, ExpressionVariable::Pointer defaultVariable, std::vector<IVariableResolver*> resolvers);
  
  
  /**
   * {@inheritDoc}
   */
  IEvaluationContext* GetParent();
  
  /**
   * {@inheritDoc}
   */
  IEvaluationContext* GetRoot();
  
  /**
   * {@inheritDoc}
   */
  ExpressionVariable::Pointer GetDefaultVariable();
  
  /**
   * {@inheritDoc}
   */
  void SetAllowPluginActivation(bool value);
  
  /**
   * {@inheritDoc}
   */
  bool GetAllowPluginActivation();
  
  /**
   * {@inheritDoc}
   */
  void AddVariable(const std::string& name, ExpressionVariable::Pointer value);
  
  /**
   * {@inheritDoc}
   */
  ExpressionVariable::Pointer RemoveVariable(const std::string& name);
  
  /**
   * {@inheritDoc}
   */
  ExpressionVariable::Pointer GetVariable(const std::string& name);
  
  /**
   * {@inheritDoc}
   */
  ExpressionVariable::Pointer ResolveVariable(const std::string& name, std::vector<ExpressionVariable::Pointer>& args);
};

}  // namespace cherry

#endif /*CHERRYEVALUATIONCONTEXT_H_*/
