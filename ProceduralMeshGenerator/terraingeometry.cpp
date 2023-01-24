#include "terraingeometry.h"
#include <QColor>

TerrainGeometry::TerrainGeometry()
{
    updateData();
}

void TerrainGeometry::updateData()
{
    clear();

    int size = 4;

    int columns = size + 1;
    int rows = size + 1;
    int step = 10;

    int stride = 3 * sizeof(float);
    stride+=4*sizeof(float);
//    if (m_hasNormals)
//        stride += 3 * sizeof(float);
//    if (m_hasUV)
//        stride += 2 * sizeof(float);

    QByteArray vertexData(columns * rows * 7* stride, Qt::Initialization::Uninitialized);
    float *p = reinterpret_cast<float *>(vertexData.data());



//    for ( int row=0; row<height-1; row++ ) {
//        if ( (row&1)==0 ) { // even rows
//            for ( int col=0; col<width; col++ ) {
//                *p++ = col + row * width;
//                *p++ = col + (row+1) * width;
//            }
//        } else { // odd rows
//            for ( int col=width-1; col>0; col-- ) {
//                *p++ = col + (row+1) * width;
//                *p++ = col - 1 + + row * width;
//            }
//        }
//    }

//    for (int i = 0; i < 10; ++i) {
//        const float x = i;

//        for (int j = 0; j < 10; ++j) {
//            const float z = j;

//            *p++ = x;
//            *p++ = 0.0f;
//            *p++ = z;
//        }
//    }

    for ( int i=0; i<rows-1; i++ )
    {
        for ( int j=0; j<columns-1; j++ )
        {
            *p++ = (float)i; *p++ = 0.0f; *p++ = (float)j;
            QColor r("orange");
            *p++ = r.red();
            *p++ = r.green();
            *p++ = r.blue();
            *p++ = r.alpha();

            *p++ = (float)i; *p++ = 0.0f; *p++ = (float)(j+1);
            QColor r2("orange");
            *p++ = r2.red();
            *p++ = r2.green();
            *p++ = r2.blue();
            *p++ = r2.alpha();

            *p++ = (float)(i+1); *p++ = 0.0f; *p++ = (float)(j+1);
            QColor r3("orange");
            *p++ = r3.red();
            *p++ = r3.green();
            *p++ = r3.blue();
            *p++ = r3.alpha();
        }
    }


//    *p++ = 0.0f; *p++ = 0.0f; *p++ = 0.0f;
//    *p++ = 0.0f; *p++ = 0.0f; *p++ = 5.0f;
//    *p++ = 5.0f; *p++ = 0.0f; *p++ = 5.0f;


//    *p++ = 0.0f; *p++ = 0.0f; *p++ = 0.0f;
//    *p++ = 5.0f; *p++ = 0.0f; *p++ = 5.0f;
//    *p++ = 5.0f; *p++ = 0.0f; *p++ = 0.0f;

    // a triangle, front face = counter-clockwise
//    *p++ = 0.0f; *p++ = 0.0f; *p++ = 0.0f;
//    if (m_hasNormals) {
//        *p++ = m_normalXY; *p++ = m_normalXY; *p++ = 1.0f;
//    }
//    if (m_hasUV) {
//        *p++ = 0.0f + m_uvAdjust; *p++ = 0.0f + m_uvAdjust;
//    }
//    *p++ = 0.0f; *p++ = 0.0f; *p++ = 5.0f;
//    if (m_hasNormals) {
//        *p++ = m_normalXY; *p++ = m_normalXY; *p++ = 1.0f;
//    }
//    if (m_hasUV) {
//        *p++ = 1.0f - m_uvAdjust; *p++ = 0.0f + m_uvAdjust;
//    }
//    *p++ = 5.0f; *p++ = 0.0f; *p++ = 5.0f;
//    if (m_hasNormals) {
//        *p++ = m_normalXY; *p++ = m_normalXY; *p++ = 1.0f;
//    }
//    if (m_hasUV) {
//        *p++ = 1.0f - m_uvAdjust; *p++ = 1.0f - m_uvAdjust;
//    }

    setVertexData(vertexData);
    setStride(stride);

    setPrimitiveType(QQuick3DGeometry::PrimitiveType::Triangles);

    addAttribute(QQuick3DGeometry::Attribute::PositionSemantic,
                 0,
                 QQuick3DGeometry::Attribute::F32Type);

//    if (m_hasNormals) {
//        addAttribute(QQuick3DGeometry::Attribute::NormalSemantic,
//                     3 * sizeof(float),
//                     QQuick3DGeometry::Attribute::F32Type);
//    }

//    if (m_hasUV) {
//        addAttribute(QQuick3DGeometry::Attribute::TexCoordSemantic,
//                     m_hasNormals ? 6 * sizeof(float) : 3 * sizeof(float),
//                     QQuick3DGeometry::Attribute::F32Type);
//    }

    addAttribute(QQuick3DGeometry::Attribute::ColorSemantic,3* sizeof (float),QQuick3DGeometry::Attribute::F32Type);
}
