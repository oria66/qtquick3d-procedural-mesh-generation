#ifndef GRADIENTTEXTURE_H
#define GRADIENTTEXTURE_H

#include <QQuick3DTextureData>

#include <QtGui/QColor>

class Gradienttexture : public QQuick3DTextureData
{
    Q_OBJECT
    QML_NAMED_ELEMENT(GradientTexture)
public:
    Gradienttexture();
private:
    void updateTexture();
    QByteArray generateTexture();

    static QColor linearInterpolate(const QColor &color1, const QColor &color2, float value);

    int m_height = 256;
    int m_width = 256;
    QColor m_startColor = QColor(QStringLiteral("#d4fc79"));
    QColor m_endColor = QColor(QStringLiteral("#96e6a1"));

};

#endif // GRADIENTTEXTURE_H
