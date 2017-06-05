#include "connectioncheck.h"

ConnectionCheck::ConnectionCheck(QObject *parent) : IBase(parent) {

  manager = new QNetworkAccessManager(this);
  connect(manager, &QNetworkAccessManager::finished, this,
          &ConnectionCheck::sltReplyFinished);
}
void ConnectionCheck::checkConnection(QUrl url, QString usename,
                                      QString password) {
  mUsername = usename;
  mPassword = password;
  mUrl = url;
  QString concatenated = mUsername + ":" + mPassword; // username:password

  QByteArray data = concatenated.toLocal8Bit().toBase64();

  QString headerData = "Basic " + QString::fromLatin1(data);

  QNetworkRequest request = QNetworkRequest(mUrl);

  request.setRawHeader("Authorization", headerData.toLocal8Bit());

  manager->get(request);
}
void ConnectionCheck::parse(QByteArray xml) {}

void ConnectionCheck::sltReplyFinished(QNetworkReply *reply) {

  if (reply->error() != QNetworkReply::NoError) {
    if (reply->error() == QNetworkReply::AuthenticationRequiredError) {
      qDebug() << "AuthenticationRequiredError";
      emit sigReplyError(ReplayError_Authentication);
    }
  } else {
    parse(reply->readAll());
    emit sigReplyOk();
  }
}
