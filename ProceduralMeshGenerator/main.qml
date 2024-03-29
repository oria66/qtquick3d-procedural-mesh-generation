import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick3D
import QtQuick3D.Helpers

import TerrainGeometryModel

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Scroll")

    View3D{
        id: v3d
        anchors.fill: parent
        camera: camera

        PerspectiveCamera {
            id: camera
            position: Qt.vector3d(0, 300, 200)
            rotation: lookAt(myterrain)
        }

        DirectionalLight {
            position: Qt.vector3d(-500, 500, -100)
            color: Qt.rgba(0.4, 0.2, 0.6, 1.0)
            ambientColor: Qt.rgba(0.1, 0.1, 0.1, 1.0)
        }

        PointLight {
            position: Qt.vector3d(0, 0, 100)
            color: Qt.rgba(0.1, 1.0, 0.1, 1.0)
            ambientColor: Qt.rgba(0.2, 0.2, 0.2, 1.0)
        }

        Model {
            scale: Qt.vector3d(100, 100, 100)
            geometry: GridGeometry {
                id: grid
                horizontalLines: 20
                verticalLines: 20
            }
            materials: [
                DefaultMaterial {
                    lineWidth: 1
                }
            ]
        }

//        Model {
//            source: "#Sphere"
//            scale: Qt.vector3d(1, 1, 1)
//            materials: DefaultMaterial {
//                diffuseColor: "#faee45"
//            }
//        }

        Model {
            id: myterrain
            scale: Qt.vector3d(10, 10, 10)
            geometry: TerrainGeometry {
//                normals: cbNorm.checked
//                normalXY: sliderNorm.value
//                uv: cbUV.checked
//                uvAdjust: sliderUV.value
            }
            materials: DefaultMaterial {
                diffuseColor: "red"
//                opacity: 0.1
            }
        }

        WasdController {
            controlledObject: camera
        }
    }
}
