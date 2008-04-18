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

#include "cherryEvaluationResult.h"

#include "Poco/Exception.h"

namespace cherry {

const int EvaluationResult::FALSE_VALUE= 0;
const int EvaluationResult::TRUE_VALUE= 1;
const int EvaluationResult::NOT_LOADED_VALUE= 2;

const EvaluationResult EvaluationResult::FALSE(EvaluationResult::FALSE_VALUE);
const EvaluationResult EvaluationResult::TRUE(EvaluationResult::TRUE_VALUE);
const EvaluationResult EvaluationResult::NOT_LOADED(NOT_LOADED_VALUE);

bool EvaluationResult::operator==(const EvaluationResult& result)
{
  return this->fValue == result.fValue;
}

bool EvaluationResult::operator!=(const EvaluationResult& result)
{
  return this->fValue != result.fValue;
}

const EvaluationResult EvaluationResult::AND[3][3] = {
    //                    FALSE                      TRUE                  NOT_LOADED
    /* FALSE   */ { EvaluationResult::FALSE, EvaluationResult::FALSE, EvaluationResult::FALSE   },
    /* TRUE    */ { EvaluationResult::FALSE, EvaluationResult::TRUE,  EvaluationResult::NOT_LOADED  },
    /* PNL     */ { EvaluationResult::FALSE, EvaluationResult::NOT_LOADED, EvaluationResult::NOT_LOADED  }
};

const EvaluationResult EvaluationResult::OR[3][3] = {
    //                      FALSE                   TRUE                  NOT_LOADED
    /* FALSE   */ { EvaluationResult::FALSE, EvaluationResult::TRUE, EvaluationResult::NOT_LOADED  },
    /* TRUE    */ { EvaluationResult::TRUE,  EvaluationResult::TRUE, EvaluationResult::TRUE    },
    /* PNL     */ { EvaluationResult::NOT_LOADED, EvaluationResult::TRUE,   EvaluationResult::NOT_LOADED  }
};

const EvaluationResult EvaluationResult::NOT[3] = {
    //    FALSE                        TRUE                  NOT_LOADED
    EvaluationResult::TRUE, EvaluationResult::FALSE, EvaluationResult::NOT_LOADED
};


EvaluationResult::EvaluationResult(int value)
{
  fValue= value;
}

EvaluationResult 
EvaluationResult::And(EvaluationResult other) 
{
  return AND[fValue][other.fValue];
}

EvaluationResult 
EvaluationResult::Or(EvaluationResult other) 
{
  return OR[fValue][other.fValue];
}


EvaluationResult 
EvaluationResult::Not() 
{
  return NOT[fValue];
}

EvaluationResult 
EvaluationResult::ValueOf(bool b) 
{
  return b ? TRUE : FALSE;
}


std::string
EvaluationResult::ToString() 
{
  switch (fValue) {
  case 0:
    return "false";
  case 1:
    return "true";
  case 2:
    return "not_loaded";
  default:
    throw Poco::AssertionViolationException();
  }
}

}  // namespace cherry
