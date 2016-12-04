#include <QCoreApplication>
#include <QtDBus/QtDBus>

#include <stdio.h>
#include <stdlib.h>

#include "Daemon.hpp"
#include "common.h"

int main(int argc, char * argv[])
{
  QCoreApplication app(argc, argv);

  //Check to see if the QDBus can be connected to
  if(!QDBusConnection::sessionBus().isConnected())
  {
    fprintf(stderr, "Cannot connect to the D-Bus session bus.\n");
    exit(1);
  }

  //Register our service name so that a client can use it
  if(!QDBusConnection::sessionBus().registerService(SERVICE_NAME))
  {
    fprintf(stderr, "%s\n", qPrintable(QDBusConnection::sessionBus().lastError().message()));
    exit(1);
  }

  Daemon daemon;

  //Register all slots so that we can access them from another application
  QDBusConnection::sessionBus().registerObject(OBJECT_PATH, INTERFACE, &daemon, QDBusConnection::ExportAllSlots);

  app.exec();
}
