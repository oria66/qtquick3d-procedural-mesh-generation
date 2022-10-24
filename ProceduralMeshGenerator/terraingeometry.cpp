#include "terraingeometry.h"
#include "QDebug"
#include <QtMath>

TerrainGeometry::TerrainGeometry()
{
    updateData();
}

void TerrainGeometry::updateData()
{
    clear();

    int stride = 3 * sizeof(float);
//    if (m_hasNormals)
//        stride += 3 * sizeof(float);
//    if (m_hasUV)
//        stride += 2 * sizeof(float);

    int index=50;

    int count=index*index*6;

    float step=8;

    QByteArray vertexData(count * stride, Qt::Initialization::Uninitialized);
    float *p = reinterpret_cast<float *>(vertexData.data());

    QByteArray Z(count * stride, Qt::Initialization::Uninitialized);
    float *t = reinterpret_cast<float *>(vertexData.data());

    int contador=0;
    for(int row=0;row<index;row++)
    {
        for(int col=0;col<index;col++)
        {
            float v=sin(col)/100;
            *t++=v;
            contador++;
        }
    }
    qDebug()<<"Cantidad de triangulos: "<<(index-1)*(index-1)*2;
    qDebug()<<"Cantidad de puntos: "<<contador;

    for(int row=0;row<index;row++)
    {
        for(int col=0;col<index;col++)
        {
            int ind=row*index+col;

            int ind1=(row+1)*index+col;

            int ind2=(row+1)*index+(col+1);

            int ind3=row*index+(col+1);

            *p++ = col*step; *p++ = Z[ind]; *p++ = row*step;

            *p++ = col*step; *p++ = Z[ind1]; *p++ = (row+1)*step;

            *p++ = (col+1)*step; *p++ = Z[ind2]; *p++ = (row+1)*step;

            *p++ = col*step; *p++ = Z[ind]; *p++ = row*step;

            *p++ = (col+1)*step; *p++ = Z[ind2]; *p++ = (row+1)*step;

            *p++ = (col+1)*step; *p++ = Z[ind3]; *p++ = row*step;

        }
    }


//    vertexData.clear();




//    int height = 10;
//    int width = 10;

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

//    if (true) {
//        addAttribute(QQuick3DGeometry::Attribute::NormalSemantic,
//                     3 * sizeof(float),
//                     QQuick3DGeometry::Attribute::F32Type);
//    }

//    if (m_hasUV) {
//        addAttribute(QQuick3DGeometry::Attribute::TexCoordSemantic,
//                     m_hasNormals ? 6 * sizeof(float) : 3 * sizeof(float),
//                     QQuick3DGeometry::Attribute::F32Type);
    //    }
}


