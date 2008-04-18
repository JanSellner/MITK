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

#ifndef __CHERRY_MACROS_H__
#define __CHERRY_MACROS_H__

#include "cherryObject.h"
#include "cherrySmartPointer.h"
  
#define cherryClassMacro(className) \
  typedef className       Self; \
  typedef SmartPointer<Self> Pointer; \
  typedef SmartPointer<const Self>  ConstPointer; \
  virtual const char* GetNameOfClass() const \
  { return #className; }\
  

#define cherryNewMacro(x) \
static Pointer New(void) \
{ \
  Pointer smartPtr = new x; \
  return smartPtr; \
} \

#endif /*__CHERRY_MACROS_H__*/
