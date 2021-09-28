#include "procces.h"

Procces::Procces(QObject *parent)
        : QProcess(parent) {
}


 void Procces::start(const QString &program, const QVariantList &arguments) {
      QStringList args;


      // qDebug() << "Running" << program;
      // convert QVariantList from QML to QStringList for QProcess

      for (int i = 0; i < arguments.length(); i++)
          args << arguments[i].toString();

      QProcess::startDetached(program);
     // QProcess::start(program, args);

  }

 QByteArray Procces::readAll() {
     return QProcess::readAll();
 }
