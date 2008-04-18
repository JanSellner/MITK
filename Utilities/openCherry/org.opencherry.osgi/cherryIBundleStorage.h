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

#ifndef CHERRYIBUNDLESTORAGE_H_
#define CHERRYIBUNDLESTORAGE_H_

#include "cherryMacros.h"

#include "Poco/Path.h"

#include <vector>


namespace cherry {

struct CHERRY_API IBundleStorage : public Object
{
  cherryClassMacro(IBundleStorage);
  
  virtual std::istream* GetResource(const std::string& path) const = 0;
  virtual void List(const std::string& path, std::vector<std::string>& files) const = 0;
  virtual Poco::Path GetPath() const = 0;
  
  virtual ~IBundleStorage() {};
};

} // namespace cherry

#endif /*CHERRYIBUNDLESTORAGE_H_*/
