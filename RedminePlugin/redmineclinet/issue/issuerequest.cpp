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
    QDomElement project = n.firstChildElement("project");
    QDomElement tracker = n.firstChildElement("tracker");
    QDomElement status = n.firstChildElement("status");
    QDomElement priority = n.firstChildElement("priority");
    QDomElement author = n.firstChildElement("author");
    QDomElement category = n.firstChildElement("category");
    QDomElement start_date = n.firstChildElement("start_date");
    QDomElement due_date = n.firstChildElement("due_date");
    QDomElement done_ratio = n.firstChildElement("done_ratio");

    QDomElement created_on = n.firstChildElement("created_on");
    QDomElement updated_on = n.firstChildElement("updated_on");
//    if (id.isNull() || subject.isNull() || description.isNull() ||
//            project.isNull() || tracker.isNull() || status.isNull() ||
//            priority.isNull() || author.isNull() || category.isNull() ||
//            start_date.isNull() || due_date.isNull() || done_ratio.isNull() ||
//            created_on.isNull() || updated_on.isNull())
//      continue;
    IssueModel::Issue issue;
    issue.id = id.text().toInt();
    issue.subject = subject.text();
    issue.description = description.text();
    issue.author_name = author.attribute("name","-");
    issue.category_name = category.attribute("name","-");
    issue.created_on = created_on.text();
    issue.done_ratio = done_ratio.text().toInt();
    issue.due_date = due_date.text();
    issue.status_name = status.attribute("name","-");
    issue.priority_name = priority.attribute("name","-");
    issue.project_name = project.attribute("name","-");
    issue.start_date =  start_date.text();
    issue.tracker_name = tracker.attribute("name","-");
    issue.updated_on = updated_on.text();

    model->addIssue(issue);
  }
}
