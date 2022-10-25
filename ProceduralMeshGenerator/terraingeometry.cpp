#include "terraingeometry.h"
#include "QDebug"
#include <QtMath>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QVector3D>
#include <QVector>

TerrainGeometry::TerrainGeometry()
{
    updateData();
}

void TerrainGeometry::setUV(bool enable)
{
    if (m_hasUV == enable)
        return;

    m_hasUV = enable;
    emit uvChanged();
    updateData();
    update();
}

void TerrainGeometry::setUVAdjust(float f)
{
    if (m_uvAdjust == f)
        return;

    m_uvAdjust = f;
    emit uvAdjustChanged();
    updateData();
    update();
}

void TerrainGeometry::updateData()
{
    clear();

    int stride = 3 * sizeof(float);
    //    if (m_hasNormals)
    //        stride += 3 * sizeof(float);
    //    if (m_hasUV)
    //        stride += 2 * sizeof(float);
    stride+=4*sizeof(float);

    loadCloudTxt();


    QByteArray vertexData(vertex * stride, Qt::Initialization::Uninitialized);
    float *p = reinterpret_cast<float *>(vertexData.data());



    for(int col=0;col<height;col++)
    {
        for(int row=0;row<width;row++)
        {
            int ind,ind1,ind2,ind3;
            ind=col*height+row;
            ind1=(col+1)*height+row;
            ind2=(col+1)*height+(row+1);
            ind3=col*height+row+1;



            //            QVector3D point1=cloud.at(row*+);
            //***** un punto
            *p++ = cloud.at(ind).x(); *p++ = cloud.at(ind).z(); *p++ = cloud.at(ind).y();

            QColor r=getColor(cloud.at(ind).z());

            *p++ = r.red(); *p++ = r.green(); *p++ = r.blue(); *p++ =r.alpha();



            //***** un punto
            *p++ = cloud.at(ind1).x(); *p++ = cloud.at(ind1).z(); *p++ = cloud.at(ind1).y();

            r=getColor(cloud.at(ind1).z());

            *p++ = r.red(); *p++ = r.green(); *p++ = r.blue(); *p++ =r.alpha();
            //

            *p++ = cloud.at(ind2).x(); *p++ = cloud.at(ind2).z(); *p++ = cloud.at(ind2).y();

            r=getColor(cloud.at(ind2).z());

            *p++ = r.red(); *p++ = r.green(); *p++ = r.blue(); *p++ =r.alpha();
            //

            *p++ = cloud.at(ind).x(); *p++ = cloud.at(ind).z(); *p++ = cloud.at(ind).y();

            r=getColor(cloud.at(ind).z());

            *p++ = r.red(); *p++ = r.green(); *p++ = r.blue(); *p++ =r.alpha();
            //

            *p++ = cloud.at(ind2).x(); *p++ = cloud.at(ind2).z(); *p++ = cloud.at(ind2).y();

            r=getColor(cloud.at(ind2).z());

            *p++ = r.red(); *p++ = r.green(); *p++ = r.blue(); *p++ =r.alpha();
            //

            *p++ = cloud.at(ind3).x(); *p++ = cloud.at(ind3).z(); *p++ = cloud.at(ind3).y();

            r=getColor(cloud.at(ind3).z());

            *p++ = r.red(); *p++ = r.green(); *p++ = r.blue(); *p++ =r.alpha();


            //            *p++ = col*step; *p++ = 0; *p++ = row*step;

            //            *p++ = col*step; *p++ = 0; *p++ = (row+1)*step;

            //            *p++ = (col+1)*step; *p++ = 0; *p++ = (row+1)*step;

            //            *p++ = col*step; *p++ = 0; *p++ = row*step;

            //            *p++ = (col+1)*step; *p++ = 0; *p++ = (row+1)*step;

            //            *p++ = (col+1)*step; *p++ = 0; *p++ = row*step;

        }
    }
    qDebug()<<"creado los triangulos";


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

    setPrimitiveType(QQuick3DGeometry::PrimitiveType::Points);

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
//                     3 * sizeof(float),
//                     QQuick3DGeometry::Attribute::F32Type);
//    }
    addAttribute(QQuick3DGeometry::Attribute::ColorSemantic,3* sizeof (float),QQuick3DGeometry::Attribute::F32Type);
}

void TerrainGeometry::loadCloudTxt()
{
    QString path="/home/magdiel/stock.txt";



    QFile file(path);

    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"No se pudo cargar el fichero de la nube de punto";
        exit(1);
    }

    QString line;

    QString delimitador="\t";

    QTextStream stream(&file);

    cloud.clear();
    cloud.squeeze();

    do {

        //line=stream.readLine();
        if(line.isEmpty()) continue;
        if(line.contains("//")) continue;
        QStringList list = line.split(delimitador);
        cloud.append(QVector3D(list.at(0).toFloat(),list.at(1).toDouble(),list.at(2).toDouble()));

    } while (stream.readLineInto(&line));

    getProperty(cloud);

}

void TerrainGeometry::getProperty(QVector<QVector3D> cloud)
{
    unsigned count = cloud.count();
    QVector3D min_Corner,max_Corner;
    min_Corner=max_Corner=cloud.at(0);
    for(unsigned i = 0;i < count; i++)
    {
        if(min_Corner.x() > cloud.at(i).x())
        {
            min_Corner.setX(cloud.at(i).x());
        }
        if(min_Corner.y() > cloud.at(i).y())
        {
            min_Corner.setY(cloud.at(i).y());
        }
        if(min_Corner.z() > cloud.at(i).z())
        {
            min_Corner.setZ(cloud.at(i).z());
        }
        if(max_Corner.x()<cloud.at(i).x())
            max_Corner.setX(cloud.at(i).x());

        if(max_Corner.y()<cloud.at(i).y())
        {
            max_Corner.setY(cloud.at(i).y());
        }
        if(!(cloud.at(i).z()==0))
        {
            if(max_Corner.z()<cloud.at(i).z())
            {
                max_Corner.setZ(cloud.at(i).z());
            }
        }

    }
    step=0.1;
    height=qRound((max_Corner.y()-min_Corner.y())/step);
    width=qRound((max_Corner.x()-min_Corner.x())/step);
    vertex=height*width*6;
    minZ=min_Corner.z();
    maxZ=max_Corner.z();
}

QColor TerrainGeometry::getColor(float altura)
{
    int total=maxZ-minZ;

    int incre=total/4;

    if(altura<(incre+minZ))
        return Qt::GlobalColor::blue;
    else if(altura>(incre+minZ)&&altura<(2*incre+minZ))
        return Qt::GlobalColor::green;
    else if(altura>(2*incre+minZ)&&altura<(3*incre+minZ))
        return Qt::GlobalColor::yellow;
    else
        return Qt::GlobalColor::red;
}


