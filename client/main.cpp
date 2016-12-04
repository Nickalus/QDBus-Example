#include <stdio.h>
#include <QCoreApplication>
#include <QtDBus/QtDBus>
#include <QDebug>

#define SERVICE_NAME "daemon.example"

int Interface(QDBusInterface &, const QString &);
int InterfaceTransmit(QDBusInterface &, const QString &);

int main(int argc, char * argv[])
{
  QCoreApplication app(argc, argv);

  //Check to see if the QDBus can be connected to
  if(!QDBusConnection::sessionBus().isConnected())
  {
    fprintf(stderr, "Cannot connect to the D-Bus session bus.\n");
    exit(1);
  }

  //Access the interface
  QDBusInterface iface(SERVICE_NAME, "/", "", QDBusConnection::sessionBus());

  if(!iface.isValid())
  {
    fprintf(stderr, "Cannot connect to session bus.\n");
    exit(1);
  }
  else
  {
    for(int i = 0; i < 10; i++)
    {
      Interface(iface, "Run");
      Interface(iface, "Suspend");
    }

    for(int i = 0; i < 10; i++)
    {
      QString str = QString::number(i, 10);
      
      InterfaceTransmit(iface, str);
    }
  }

  Interface(iface, "Quit");
}

int Interface(QDBusInterface & interface, const QString & method)
{
  QDBusReply<QString> reply = interface.call(method);

  if(reply.isValid())
  {
    printf("Reply was: %s\n", qPrintable(reply.value()));
    return 0;
  }
  else
  {
    fprintf(stderr, "Call failed: %s\n", qPrintable(reply.error().message()));
    return 1;
  }
}

int InterfaceTransmit(QDBusInterface & interface, const QString & data)
{
  QDBusReply<QString> reply = interface.call("DataTransmit", data);

  if(reply.isValid())
  {
    printf("Reply was: %s\n", qPrintable(reply.value()));
    return 0;
  }
  else
  {
    fprintf(stderr, "Call failed: %s\n", qPrintable(reply.error().message()));
    return 1;
  }
}
