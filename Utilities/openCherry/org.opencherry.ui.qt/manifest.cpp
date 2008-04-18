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

#include "Poco/ClassLibrary.h"

#include "org.opencherry.osgi/cherryIBundleActivator.h"
#include "cherryQtUIPlugin.h"

#include "org.opencherry.ui/cherryIWorkbench.h"
#include "cherryQtWorkbench.h"

#include "org.opencherry.ui/cherryIViewPart.h"
#include "cherryLogView.h"

POCO_BEGIN_MANIFEST(cherry::IBundleActivator)
  POCO_EXPORT_CLASS(cherry::QtUIPlugin)
POCO_END_MANIFEST

POCO_BEGIN_NAMED_MANIFEST(cherryIWorkbench, cherry::IWorkbench)
  POCO_EXPORT_CLASS(cherry::QtWorkbench)
POCO_END_MANIFEST

POCO_BEGIN_NAMED_MANIFEST(cherryIViewPart, cherry::IViewPart)
  POCO_EXPORT_CLASS(cherry::LogView)
POCO_END_MANIFEST
