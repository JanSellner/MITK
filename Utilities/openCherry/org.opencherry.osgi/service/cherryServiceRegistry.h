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

#ifndef CHERRYSERVICEREGISTRY_H_
#define CHERRYSERVICEREGISTRY_H_

#include "../cherryDll.h"

#include "cherryService.h"

#include "Poco/Mutex.h"

#include <string>
#include <map>

namespace cherry {

class CHERRY_API ServiceRegistry
{
private:
  std::map<const std::string, Service::Pointer> m_ServiceMap;
  
  mutable Poco::Mutex m_Mutex;
  
public:
  
  virtual ~ServiceRegistry();
  
  template<class S>
  typename S::Pointer GetServiceById(const std::string& id);
  
  void RegisterService(const std::string& id, Service::Pointer service);
  void UnRegisterService(const std::string& id);
  void UnRegisterService(Service::ConstPointer service);
};

}  // namespace cherry

#include "cherryServiceRegistry.txx"

#endif /*CHERRYSERVICEREGISTRY_H_*/
