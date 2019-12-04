/*============================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center (DKFZ)
All rights reserved.

Use of this source code is governed by a 3-clause BSD license that can be
found in the LICENSE file.

============================================================================*/

#ifndef IMAGECHANNELSELECTOR_H_HEADER_INCLUDED_C1E4F4E7
#define IMAGECHANNELSELECTOR_H_HEADER_INCLUDED_C1E4F4E7

#include "mitkSubImageSelector.h"
#include <MitkCoreExports.h>

namespace mitk
{
  //##Documentation
  //## @brief Provides access to a channel of the input image
  //##
  //## If the input is generated by a ProcessObject, only the required data is
  //## requested.
  //## @ingroup Process
  class MITKCORE_EXPORT ImageChannelSelector : public SubImageSelector
  {
  public:
    mitkClassMacro(ImageChannelSelector, SubImageSelector);

    itkFactorylessNewMacro(Self) itkCloneMacro(Self)

      itkGetConstMacro(ChannelNr, int);
    itkSetMacro(ChannelNr, int);

  protected:
    ImageChannelSelector();

    ~ImageChannelSelector() override;

    void GenerateOutputInformation() override;

    void GenerateInputRequestedRegion() override;

    void GenerateData() override;

    int m_ChannelNr;
  };

} // namespace mitk

#endif /* IMAGECHANNELSELECTOR_H_HEADER_INCLUDED_C1E4F4E7 */
