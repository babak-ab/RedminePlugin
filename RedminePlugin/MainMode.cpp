#include "MainMode.h"
namespace Redmine {

MainMode::MainMode(QWidget *widget) {
  setWidget(widget);
  setDisplayName(tr("Redmine"));
  setIcon(QIcon(":/images/redmine_.png"));
  setPriority(0);
}
}
