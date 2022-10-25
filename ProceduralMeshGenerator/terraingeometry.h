#ifndef TERRAINGEOMETRY_H
#define TERRAINGEOMETRY_H

#include <QQuick3DGeometry>
#include <QObject>
#include <QVector3D>
#include <QVector>
#include <QColor>

class TerrainGeometry : public QQuick3DGeometry
{
    Q_OBJECT
    QML_NAMED_ELEMENT(TerrainGeometry)
    Q_PROPERTY(bool uv READ uv WRITE setUV NOTIFY uvChanged)
    Q_PROPERTY(float uvAdjust READ uvAdjust WRITE setUVAdjust NOTIFY uvAdjustChanged)

public:
    TerrainGeometry();
    bool uv() const { return m_hasUV; }
    void setUV(bool enable);

    float uvAdjust() const { return m_uvAdjust; }
    void setUVAdjust(float f);

signals:
    void uvChanged();
    void uvAdjustChanged();

private:
    void updateData();
    void loadCloudTxt();
    void getProperty(QVector<QVector3D> cloud);
    QColor getColor(float altura);

    int height, width ;
    float step,vertex, minZ,maxZ;
    QVector<QVector3D> cloud;
    bool m_hasUV = false;
    float m_uvAdjust = 0.0f;
};



#endif // TERRAINGEOMETRY_H
