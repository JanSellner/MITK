/*============================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center (DKFZ)
All rights reserved.

Use of this source code is governed by a 3-clause BSD license that can be
found in the LICENSE file.

============================================================================*/

#ifndef QMITKSEGMENTATIONPREFERENCEPAGE_H
#define QMITKSEGMENTATIONPREFERENCEPAGE_H

#include "org_mitk_gui_qt_segmentation_Export.h"

#include <berryIPreferences.h>
#include <berryIQtPreferencePage.h>

class QCheckBox;
class QRadioButton;
class QDoubleSpinBox;
class QLineEdit;
class QToolButton;

class MITK_QT_SEGMENTATION QmitkSegmentationPreferencePage : public QObject, public berry::IQtPreferencePage
{
  Q_OBJECT
  Q_INTERFACES(berry::IPreferencePage)

public:

  QmitkSegmentationPreferencePage();
  ~QmitkSegmentationPreferencePage() override;

  void Init(berry::IWorkbench::Pointer workbench) override;

  void CreateQtControl(QWidget* widget) override;

  QWidget* GetQtControl() const override;

  bool PerformOk() override;

  void PerformCancel() override;

  void Update() override;

protected Q_SLOTS:

  void OnSmoothingCheckboxChecked(int);
  void OnLabelsetPresetButtonClicked();

protected:

  QWidget* m_MainControl;
  QCheckBox* m_SlimViewCheckBox;
  QRadioButton* m_RadioOutline;
  QRadioButton* m_RadioOverlay;
  QCheckBox* m_SelectionModeCheckBox;
  QCheckBox* m_SmoothingCheckBox;
  QDoubleSpinBox* m_SmoothingSpinBox;
  QDoubleSpinBox* m_DecimationSpinBox;
  QDoubleSpinBox* m_ClosingSpinBox;
  QLineEdit* m_LabelsetPresetLineEdit;
  QToolButton* m_LabelsetPresetToolButton;

  bool m_Initializing;

  berry::IPreferences::Pointer m_SegmentationPreferencesNode;
};

#endif // QMITKSEGMENTATIONPREFERENCEPAGE_H
