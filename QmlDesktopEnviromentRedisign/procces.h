

#include <QProcess>
#include <QVariant>
#include <QDebug>


class Procces:public QProcess
{
    Q_OBJECT
public:
   Procces(QObject *parent = nullptr);

   Q_INVOKABLE void start(const QString &program, const QVariantList &arguments={});
   Q_INVOKABLE QByteArray readAll();
};


