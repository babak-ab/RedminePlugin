#include "issuerequest.h"

IssueRequest::IssueRequest(QObject *parent) : IBase(parent) {
  manager = new QNetworkAccessManager(this);
  connect(manager, &QNetworkAccessManager::finished, this,
          &IssueRequest::sltReplyFinished);
  model = new IssueModel(this);
}
void IssueRequest::getIssue(QUrl url, QString usename, QString password) {
  mUsername = usename;
  mPassword = password;
  mUrl = url;
  QString concatenated = mUsername + ":" + mPassword; // username:password

  QByteArray data = concatenated.toLocal8Bit().toBase64();

  QString headerData = "Basic " + data;

  QNetworkRequest request = QNetworkRequest(mUrl);

  request.setRawHeader("Authorization", headerData.toLocal8Bit());

  manager->get(request);
}

IssueModel *IssueRequest::getModel() const { return model; }

void IssueRequest::sltReplyFinished(QNetworkReply *reply) {

  if (reply->error() != QNetworkReply::NoError) {
    if (reply->error() == QNetworkReply::AuthenticationRequiredError) {
      qDebug() << "AuthenticationRequiredError";
      emit sigReplyError(ConnectionError_Authentication);
    }
  } else {
    parse(reply->readAll());
    emit sigRecvResponse();
  }
}
void IssueRequest::parse(QByteArray xml) {

  QDomDocument doc;
  doc.setContent(xml, false);

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
