#include "redmineplugin.h"
#include "MainMode.h"
#include "Settings.h"
#include "mainwindow.h"
#include "redmineconstants.h"

#include <QAction>
#include <QCoreApplication>
#include <QDebug>
#include <QLocale>
#include <QMainWindow>
#include <QMenu>
#include <QMessageBox>
#include <QTranslator>
#include <QtCore/QLibraryInfo>
#include <QtCore/QtPlugin>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/coreconstants.h>
#include <coreplugin/dialogs/ioptionspage.h>
#include <coreplugin/icontext.h>
#include <coreplugin/icore.h>
#include <coreplugin/imode.h>

namespace Redmine {
namespace Internal {

RedminePlugin::RedminePlugin() {
  // Create your members
}

RedminePlugin::~RedminePlugin() {
  // Unregister objects from the plugin manager's object pool
  // Delete members
}

bool RedminePlugin::initialize(const QStringList &arguments,
                               QString *errorString) {
  // Register objects in the plugin manager's object pool
  // Load settings
  // Add actions to menus
  // Connect to other plugins' signals
  // In the initialize function, a plugin can be sure that the plugins it
  // depends on have initialized their members.

  Q_UNUSED(arguments)
  Q_UNUSED(errorString)

  Settings::instance()->setParent(this);

  addAutoReleasedObject(Settings::instance());


  MainWindow *mainWindow = new MainWindow();

  Core::IMode *mainMode = new MainMode(mainWindow);
  addAutoReleasedObject(mainMode);

  return true;
}

void RedminePlugin::extensionsInitialized() {
  // Retrieve objects from the plugin manager's object pool
  // In the extensionsInitialized function, a plugin can be sure that all
  // plugins that depend on it are completely initialized.
}

ExtensionSystem::IPlugin::ShutdownFlag RedminePlugin::aboutToShutdown() {
  // Save settings
  // Disconnect from signals that are not needed during shutdown
  // Hide UI (if you add UI that is not in the main window directly)
  return SynchronousShutdown;
}

void RedminePlugin::triggerAction() {
  //  QMessageBox::information(Core::ICore::mainWindow(), tr("Action
  //  Triggered"),
  //                           tr("This is an action from Redmine."));
}

} // namespace Internal
} // namespace Redmine
