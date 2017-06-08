#include <QSettings>
#include <coreplugin/icore.h>

#include "Settings.h"
#include "coreplugin/settingsdatabase.h"
#include "redmineconstants.h"
#include "redmineplugin.h"

Settings *Settings::_instance = 0;

Settings::Settings(QObject *parent) : IOptionsPage(parent) {
    setDisplayCategory(tr("Redmine"));
    setCategoryIcon(categoryIcon());
    setCategory(category());
    setDisplayName(tr("General"));
    settingsWidget = Q_NULLPTR;
    _instance = this;
    if (QSettings *settings = Core::ICore::instance()->settings()) {
        settings->beginGroup(QString::fromLatin1("Redmine.Settings"));
        _settingConnection.name = settings->value(QLatin1String("Name")).toString();
        _settingConnection.server = settings->value(QLatin1String("Server")).toString();
        _settingConnection.user = settings->value(QLatin1String("User")).toString();
        _settingConnection.savePassword = settings->value(QLatin1String("SavePassword")).toInt();
        _settingConnection.password = settings->value(QLatin1String("Password")).toString();


        _issueColumnStatus.author = settings->value("IssueAuthorColumn").toBool();
        _issueColumnStatus.category = settings->value("IssueCategoryColumn").toBool();
        _issueColumnStatus.created_on = settings->value("IssueCreatedOnColumn").toBool();
        _issueColumnStatus.description =  settings->value("IssueDescriptionColumn").toBool();
        _issueColumnStatus.done_ratio = settings->value("IssueDoneRatioColumn").toBool();
        _issueColumnStatus.due_date =  settings->value("IssueDueDateColumn").toBool();
        _issueColumnStatus.status =  settings->value("IssueIssueStatusColumn").toBool();
        _issueColumnStatus.priority =  settings->value("IssuePriorityColumn").toBool();
        _issueColumnStatus.project =  settings->value("IssueProjectColumn").toBool();
        _issueColumnStatus.start_date =  settings->value("IssueStartDateColumn").toBool();
        _issueColumnStatus.subject =  settings->value("IssueSubjectColumn").toBool();
        _issueColumnStatus.tracker = settings->value("IssueTrackerColumn").toBool();
        _issueColumnStatus.updated_on = settings->value("IssueUpdatedOnColumn").toBool();

        settings->endGroup();
    }

}

Settings::~Settings() {}

Settings *Settings::instance() {
    if (_instance == 0) {
        _instance = new Settings(0);
    }
    return _instance;
}

QString Settings::id() const { return QLatin1String("Redmine.Settings"); }

QString Settings::displayName() const { return tr("Redmine"); }

Core::Id Settings::category() const {
    return Core::Id(Constants::SETTINGS_CATEGORY_REDMINE);
}

QString Settings::displayCategory() const { return tr("Redmine"); }

QString Settings::categoryIcon() const {
    return QLatin1String(":/images/remone_red.png");
}

QWidget *Settings::createPage(QWidget *parent) {
    this->settingsWidget = new SettingsWidget(parent);
    this->settingsWidget->setSettingConnection(_settingConnection);
    this->settingsWidget->setIssueColumnStatus(_issueColumnStatus);
    return this->settingsWidget;
}

void Settings::apply() {

    this->_settingConnection = this->settingsWidget->settingConnection();
    this->_issueColumnStatus  = this->settingsWidget->getIssueColumnStatus();
    if (QSettings *settings = Core::ICore::instance()->settings()) {
        settings->beginGroup(QLatin1String("Redmine.Settings"));
        settings->setValue(QLatin1String("Name"), this->_settingConnection.name);
        settings->setValue(QLatin1String("Server"),
                           this->_settingConnection.server.toString());
        settings->setValue(QLatin1String("User"), this->_settingConnection.user);
        settings->setValue(QLatin1String("SavePassword"),
                           this->_settingConnection.savePassword);
        settings->setValue(QLatin1String("Password"),
                           this->_settingConnection.password);

        settings->setValue("IssueAuthorColumn",_issueColumnStatus.author);
        settings->setValue("IssueCategoryColumn",_issueColumnStatus.category);
        settings->setValue("IssueCreatedOnColumn",_issueColumnStatus.created_on);
        settings->setValue("IssueDescriptionColumn",_issueColumnStatus.description);
        settings->setValue("IssueDoneRatioColumn",_issueColumnStatus.done_ratio);
        settings->setValue("IssueDueDateColumn",_issueColumnStatus.due_date);
        settings->setValue("IssueIssueStatusColumn",_issueColumnStatus.status);
        settings->setValue("IssuePriorityColumn",_issueColumnStatus.priority);
        settings->setValue("IssueProjectColumn",_issueColumnStatus.project);
        settings->setValue("IssueStartDateColumn",_issueColumnStatus.start_date);
        settings->setValue("IssueSubjectColumn",_issueColumnStatus.subject);
        settings->setValue("IssueTrackerColumn",_issueColumnStatus.tracker);
        settings->setValue("IssueUpdatedOnColumn",_issueColumnStatus.updated_on);
        settings->endGroup();
    }
    Q_EMIT sigSettingChanged();
}

void Settings::finish() {
    if(settingsWidget != Q_NULLPTR)
    {
        delete settingsWidget;
        settingsWidget = Q_NULLPTR;
    }
}

void Settings::setMainWindowSplitterSizes(QByteArray sizes) {
    if (QSettings *settings = Core::ICore::instance()->settings()) {
        settings->beginGroup(QLatin1String(Constants::SETTINGS_CATEGORY_REDMINE));
        settings->setValue(QLatin1String("MainWindowSplitterSizes"), sizes);
        settings->endGroup();
    }
}

QByteArray Settings::mainWindowSplitterSizes() {
    QByteArray sizes;
    if (QSettings *settings = Core::ICore::instance()->settings()) {
        settings->beginGroup(QLatin1String(Constants::SETTINGS_CATEGORY_REDMINE));
        sizes =
                settings->value(QLatin1String("MainWindowSplitterSizes")).toByteArray();
        settings->endGroup();
    }
    return sizes;
}

IssueColumnStatus Settings::issueColumnStatus() const
{
    return _issueColumnStatus;
}

SettingConnection Settings::settingConnection() const {
    return _settingConnection;
}

void Settings::setSettingConnection(
        const SettingConnection &settingConnection) {
    _settingConnection = settingConnection;
    // this->settingsWidget->setSe
}

QWidget *Settings::widget() { return createPage(0); }
