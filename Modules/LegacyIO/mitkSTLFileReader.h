/*============================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center (DKFZ)
All rights reserved.

Use of this source code is governed by a 3-clause BSD license that can be
found in the LICENSE file.

============================================================================*/
#ifndef STLFileReader_H_HEADER_INCLUDED
#define STLFileReader_H_HEADER_INCLUDED

#include "mitkSurfaceSource.h"
#include <MitkLegacyIOExports.h>

namespace mitk
{
  //##Documentation
  //## @brief Reader to read files in stl-format
  //## @ingroup MitkLegacyIOModule
  //## @deprecatedSince{2014_10} Use mitk::IOUtils or mitk::FileReaderRegistry instead.
  class MITKLEGACYIO_EXPORT STLFileReader : public SurfaceSource
  {
  public:
    mitkClassMacro(STLFileReader, SurfaceSource);

    /** Method for creation through the object factory. */
    itkFactorylessNewMacro(Self) itkCloneMacro(Self)

      itkSetStringMacro(FileName);
    itkGetStringMacro(FileName);

    itkSetStringMacro(FilePrefix);
    itkGetStringMacro(FilePrefix);

    itkSetStringMacro(FilePattern);
    itkGetStringMacro(FilePattern);

    static bool CanReadFile(const std::string filename, const std::string filePrefix, const std::string filePattern);

  protected:
    void GenerateData() override;

    STLFileReader();

    ~STLFileReader() override;

    std::string m_FileName, m_FilePrefix, m_FilePattern;
  };

} // namespace mitk

#endif /* STLFileReader_H_HEADER_INCLUDED */
