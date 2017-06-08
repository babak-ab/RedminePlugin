#include "imanager.h"

IManager::IManager(QObject *parent) : QObject(parent) {

  manager = new QNetworkAccessManager(this);
  connect(manager, &QNetworkAccessManager::finished, this,
          &IManager::sltReplyFinished);
}
void IManager::sltReplyFinished(QNetworkReply *reply) {

  if (reply->error() != QNetworkReply::NoError) {
        emit sigReplyError(reply->errorString());

  } else {
    parse(reply);
    emit sigReplyOk();
  }
}

void IManager::request(QUrl url, QString username, QString password) {
  QString concatenated = username + ":" + password; // username:password

  QByteArray data = concatenated.toLocal8Bit().toBase64();

  QString headerData = "Basic " + QString::fromLatin1(data);

  QNetworkRequest request = QNetworkRequest(url);

  request.setRawHeader("Authorization", headerData.toLocal8Bit());

  manager->get(request);
}
