/*============================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center (DKFZ)
All rights reserved.

Use of this source code is governed by a 3-clause BSD license that can be
found in the LICENSE file.

============================================================================*/

#ifndef MEANRESIDENCETIMEDESCRIPTIONPARAMETER_H
#define MEANRESIDENCETIMEDESCRIPTIONPARAMETER_H


#include "mitkCurveDescriptionParameterBase.h"

namespace  mitk
{

  /** Description parameter that computes the area under the curve */
    class MITKPHARMACOKINETICS_EXPORT MeanResidenceTimeDescriptionParameter : public mitk::CurveDescriptionParameterBase
    {
    public:
        typedef mitk::MeanResidenceTimeDescriptionParameter Self;
        typedef CurveDescriptionParameterBase Superclass;
        typedef itk::SmartPointer< Self >                            Pointer;
        typedef itk::SmartPointer< const Self >                      ConstPointer;

        itkFactorylessNewMacro(Self);
        itkCloneMacro(Self);
        DescriptionParameterNamesType GetDescriptionParameterName() const override;

    protected:
        static const std::string PARAMETER_NAME;

        MeanResidenceTimeDescriptionParameter();
        ~MeanResidenceTimeDescriptionParameter() override;

        DescriptionParameterResultsType ComputeCurveDescriptionParameter(const CurveType& curve, const CurveGridType& grid) const override;

    };
}
#endif // MEANRESIDENCETIMEDESCRIPTIONPARAMETER_H
