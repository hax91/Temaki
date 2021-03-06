import QtQuick 2.12
import QtQuick.Layouts 1.13
import QtQuick.Controls 2.14

import "qrc:/layouts" as Layouts
import "qrc:/pages" as Pages
import "qrc:/editors" as CreateProject
import "qrc:/components/" as Components

Page {
    property string screenName: "Board"
    id: homeScreen
    visible: true

    Components.InfoDialog {
        id: infoDialog
        title: "Info"
        description: "Please select a project"
    }

    /* Header */
    Layouts.Header {
        id: header
    }

    /* Sidebar */
    Layouts.Sidebar{
        id: sidebar
    }

    /* Body */
    Layouts.Body{
        id: bodyStackView
    }

    /* on project ID change: get project tasks, members and labels*/
    Connections {
        target: project
        function onIdChanged() {
            task.getForProjectByStatus(project.id)
            user.getProjectMembers(project.id)
            label.getProjectLabels(project.id)
        }
    }
}
