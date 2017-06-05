#include "projectrequest.h"

#include <QDomDocument>

ProjectRequest::ProjectRequest(QObject *parent) : IManager(parent) {
  model = new ProjectModel(this);
}
void ProjectRequest::getProject(QUrl url, QString usename, QString password) {
  QUrl Url = QUrl(url.toString() + "/projects.xml");
  request(Url, usename, password);
}

ProjectModel *ProjectRequest::getModel() const { return model; }

void ProjectRequest::parse(QNetworkReply *reply) {

  QByteArray xml = reply->readAll();
  QDomDocument doc;
  doc.setContent(xml, false);

  QDomNodeList projects = doc.elementsByTagName("project");
  for (int i = 0; i < projects.size(); i++) {
    QDomNode n = projects.item(i);
    QDomElement id = n.firstChildElement("id");
    QDomElement name = n.firstChildElement("name");
    if (id.isNull() || name.isNull())
      continue;
    ProjectModel::Project project;
    project.id = id.text().toInt();
    project.name = name.text();
    model->addProject(project);
  }
}
