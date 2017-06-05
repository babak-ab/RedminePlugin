#include "check.h"

Check::Check(QObject *parent) : IManager(parent) {}
void Check::checkConnection(QUrl url, QString username, QString password) {
  QUrl Url = QUrl(url.toString() + "/issues.xml");
  request(Url, username, password);
}
void Check::parse(QNetworkReply *reply) {}
