#ifndef TERRAINGEOMETRY_H
#define TERRAINGEOMETRY_H

#include <QQuick3DGeometry>
#include <QObject>

class TerrainGeometry : public QQuick3DGeometry
{
    Q_OBJECT
    QML_NAMED_ELEMENT(TerrainGeometry)

public:
    TerrainGeometry();

private:
    void updateData();
};

#endif // TERRAINGEOMETRY_H
