#include "gradienttexture.h"
#include <QtCore/QSize>
#include <QtGui/QGradient>
Gradienttexture::Gradienttexture()
{
    updateTexture();
}

void Gradienttexture::updateTexture()
{
    setSize(QSize(m_width, m_height));
    setFormat(QQuick3DTextureData::RGBA8);
    setHasTransparency(false);
    setTextureData(generateTexture());
}

QByteArray Gradienttexture::generateTexture()
{
    QByteArray imageData;
    // Create a horizontal gradient between startColor and endColor

    // Create a single scanline and reuse that data for each
    QByteArray gradientScanline;
    gradientScanline.resize(m_width * 4); // RGBA8

    for (int x = 0; x < m_width; ++x) {
        QColor color = linearInterpolate(m_startColor, m_endColor, x / float(m_width));
        int offset = x * 4;
        gradientScanline.data()[offset + 0] = char(color.red());
        gradientScanline.data()[offset + 1] = char(color.green());
        gradientScanline.data()[offset + 2] = char(color.blue());
        gradientScanline.data()[offset + 3] = char(255);
    }

    for (int y = 0; y < m_height; ++y)
        imageData += gradientScanline;

    return imageData;
}

QColor Gradienttexture::linearInterpolate(const QColor &color1, const QColor &color2, float value)
{
    QColor output;

    output.setRedF(color1.redF() + (value * (color2.redF() - color1.redF())));
    output.setGreenF(color1.greenF() + (value * (color2.greenF() - color1.greenF())));
    output.setBlueF(color1.blueF() + (value * (color2.blueF() - color1.blueF())));

    return output;
}
