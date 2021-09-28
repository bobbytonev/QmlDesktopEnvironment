
#include <QQuickImageProvider>

#include <QIcon>
#include <QDebug>

class ImageProvider : public QQuickImageProvider {
public:
    ImageProvider()
        : QQuickImageProvider(QQuickImageProvider::Pixmap) {


}
    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) {
	 QIcon icon = QIcon::fromTheme(id,QIcon::fromTheme("firefox"));
	

	

    if (requestedSize.isValid())
        return icon.pixmap(requestedSize);

    return icon.pixmap(32, 32);
	}
};