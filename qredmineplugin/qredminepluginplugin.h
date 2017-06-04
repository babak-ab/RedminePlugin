#pragma once

#include "qredmineplugin_global.h"

#include <extensionsystem/iplugin.h>

namespace QRedminePlugin {
namespace Internal {

class QRedminePluginPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "QRedminePlugin.json")

public:
    QRedminePluginPlugin();
    ~QRedminePluginPlugin();

    bool initialize(const QStringList &arguments, QString *errorString);
    void extensionsInitialized();
    ShutdownFlag aboutToShutdown();

private:
    void triggerAction();
};

} // namespace Internal
} // namespace QRedminePlugin
