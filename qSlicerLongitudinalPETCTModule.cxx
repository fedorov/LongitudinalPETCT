/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

// Qt includes
#include <QtPlugin>
#include <QFileInfo>
#include <QScopedPointer>

// ExtensionTemplate Logic includes
#include <vtkSlicerLongitudinalPETCTLogic.h>

// ExtensionTemplate includes
#include "qSlicerLongitudinalPETCTModule.h"

// SlicerQT includes
#include <qSlicerModuleManager.h>
#include <qSlicerScriptedLoadableModuleWidget.h>
#include <qSlicerUtils.h>
#include <vtkSlicerConfigure.h>

//-----------------------------------------------------------------------------
Q_EXPORT_PLUGIN2(qSlicerLongitudinalPETCTModule, qSlicerLongitudinalPETCTModule);

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_ExtensionTemplate
class qSlicerLongitudinalPETCTModulePrivate
{
public:
  qSlicerLongitudinalPETCTModulePrivate();
};

//-----------------------------------------------------------------------------
// qSlicerLongitudinalPETCTModulePrivate methods

//-----------------------------------------------------------------------------
qSlicerLongitudinalPETCTModulePrivate::qSlicerLongitudinalPETCTModulePrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerLongitudinalPETCTModule methods

//-----------------------------------------------------------------------------
qSlicerLongitudinalPETCTModule::qSlicerLongitudinalPETCTModule(QObject* _parent)
  : Superclass(_parent)
  , d_ptr(new qSlicerLongitudinalPETCTModulePrivate)
{
}

//-----------------------------------------------------------------------------
qSlicerLongitudinalPETCTModule::~qSlicerLongitudinalPETCTModule()
{
}

//-----------------------------------------------------------------------------
QString qSlicerLongitudinalPETCTModule::helpText()const
{
  return "This is a loadable module bundled in an extension";
}

//-----------------------------------------------------------------------------
QString qSlicerLongitudinalPETCTModule::acknowledgementText()const
{
  return "This work was was partially funded by NIH grant 3P41RR013218-12S1";
}

//-----------------------------------------------------------------------------
QStringList qSlicerLongitudinalPETCTModule::contributors()const
{
  QStringList moduleContributors;
  moduleContributors << QString("Jean-Christophe Fillion-Robin (Kitware)");
  return moduleContributors;
}

//-----------------------------------------------------------------------------
QIcon qSlicerLongitudinalPETCTModule::icon()const
{
  return QIcon(":/Resources/Icons/LongitudinalPETCT.png");
}

//-----------------------------------------------------------------------------
QStringList qSlicerLongitudinalPETCTModule::categories() const
{
  return QStringList() << "Work in Progress";
}

//-----------------------------------------------------------------------------
QStringList qSlicerLongitudinalPETCTModule::dependencies() const
{
  return QStringList();
}

//-----------------------------------------------------------------------------
void qSlicerLongitudinalPETCTModule::setup()
{
  this->Superclass::setup();
}

//-----------------------------------------------------------------------------
qSlicerAbstractModuleRepresentation * qSlicerLongitudinalPETCTModule::createWidgetRepresentation()
{
  QString pythonPath = qSlicerUtils::pathWithoutIntDir(
              QFileInfo(this->path()).path(), Slicer_QTLOADABLEMODULES_LIB_DIR);

  QScopedPointer<qSlicerScriptedLoadableModuleWidget> widget(new qSlicerScriptedLoadableModuleWidget);
  QString classNameToLoad = "qSlicerLongitudinalPETCTModuleWidget";
  bool ret = widget->setPythonSource(
        pythonPath + "/Python/" + classNameToLoad + ".py", classNameToLoad);
  if (!ret)
    {
    return 0;
    }
  return widget.take();
}

//-----------------------------------------------------------------------------
vtkMRMLAbstractLogic* qSlicerLongitudinalPETCTModule::createLogic()
{
  vtkSlicerLongitudinalPETCTLogic* logic = vtkSlicerLongitudinalPETCTLogic::New();
  logic->Initialize(); // need to initialize because vtkNewMacro doesn't take care of that

  return logic;
}