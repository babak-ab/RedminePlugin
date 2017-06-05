#include "issuerequest.h"

IssueRequest::IssueRequest(QObject *parent) : IManager(parent) {
  model = new IssueModel(this);
}
void IssueRequest::getIssue(QUrl url, QString usename, QString password) {
  QUrl Url = QUrl(url.toString() + "/issues.xml");
  request(Url, usename, password);
}
void IssueRequest::getIssue(QUrl url, QString usename, QString password,
                            int projectId) {
  QUrl Url = QUrl(url.toString() +
                  "/issues.xml?project_id=" + QString::number(projectId));
  request(Url, usename, password);
}
IssueModel *IssueRequest::getModel() const { return model; }

void IssueRequest::parse(QNetworkReply *reply) {
  QByteArray xml = reply->readAll();
  QDomDocument doc;
  doc.setContent(xml, false);

  model->clear();
  QDomNodeList issues = doc.elementsByTagName("issue");
  for (int i = 0; i < issues.size(); i++) {
    QDomNode n = issues.item(i);
    QDomElement id = n.firstChildElement("id");
    QDomElement subject = n.firstChildElement("subject");
    QDomElement description = n.firstChildElement("description");
    if (id.isNull() || subject.isNull() || description.isNull())
      continue;
    IssueModel::Issue issue;
    issue.id = id.text().toInt();
    issue.subject = subject.text();
    issue.description = description.text();

    model->addIssue(issue);
  }
}
