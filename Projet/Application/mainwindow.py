# -*- coding: utf-8 -*-



#=========================================================
# Imports
#=========================================================
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from GuiClasses import *
from random import randint

#=========================================================
# Manual
#=========================================================
class manual(object):
    def setupUi(self, MainWindowManual):
        MainWindowManual.setObjectName("MainWindowManual")
        MainWindowManual.resize(591, 587)
        MainWindowManual.setIconSize(QtCore.QSize(64, 64))
        self.centralwidget = QtWidgets.QWidget(MainWindowManual)
        self.centralwidget.setObjectName("centralwidget")
        self.label_4 = QtWidgets.QLabel(self.centralwidget)
        self.label_4.setGeometry(QtCore.QRect(40, 190, 31, 31))
        self.label_4.setText("")
        self.label_4.setPixmap(QtGui.QPixmap("../GuiGraphes/icon/make_final.png"))
        self.label_4.setScaledContents(True)
        self.label_4.setObjectName("label_4")
        self.label_5 = QtWidgets.QLabel(self.centralwidget)
        self.label_5.setGeometry(QtCore.QRect(40, 240, 31, 31))
        self.label_5.setText("")
        self.label_5.setPixmap(QtGui.QPixmap("../GuiGraphes/icon/create_transition.png"))
        self.label_5.setScaledContents(True)
        self.label_5.setObjectName("label_5")
        self.label_6 = QtWidgets.QLabel(self.centralwidget)
        self.label_6.setGeometry(QtCore.QRect(30, 290, 31, 31))
        self.label_6.setText("")
        self.label_6.setPixmap(QtGui.QPixmap("../GuiGraphes/icon/delete_state.png"))
        self.label_6.setScaledContents(True)
        self.label_6.setObjectName("label_6")
        self.label_7 = QtWidgets.QLabel(self.centralwidget)
        self.label_7.setGeometry(QtCore.QRect(30, 350, 31, 31))
        self.label_7.setText("")
        self.label_7.setPixmap(QtGui.QPixmap("../GuiGraphes/icon/delete_transition.png"))
        self.label_7.setScaledContents(True)
        self.label_7.setObjectName("label_7")
        self.label_8 = QtWidgets.QLabel(self.centralwidget)
        self.label_8.setGeometry(QtCore.QRect(30, 400, 31, 41))
        self.label_8.setText("")
        self.label_8.setPixmap(QtGui.QPixmap("../GuiGraphes/icon/export.png"))
        self.label_8.setScaledContents(True)
        self.label_8.setObjectName("label_8")
        self.label_9 = QtWidgets.QLabel(self.centralwidget)
        self.label_9.setGeometry(QtCore.QRect(30, 470, 31, 31))
        self.label_9.setText("")
        self.label_9.setPixmap(QtGui.QPixmap("../GuiGraphes/icon/rename.png"))
        self.label_9.setScaledContents(True)
        self.label_9.setObjectName("label_9")
        self.label_10 = QtWidgets.QLabel(self.centralwidget)
        self.label_10.setGeometry(QtCore.QRect(30, 520, 31, 31))
        self.label_10.setText("")
        self.label_10.setPixmap(QtGui.QPixmap("../GuiGraphes/icon/organise.png"))
        self.label_10.setScaledContents(True)
        self.label_10.setObjectName("label_10")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(40, 20, 31, 31))
        self.label.setText("")
        self.label.setPixmap(QtGui.QPixmap("../GuiGraphes/icon/screenshot.png"))
        self.label.setScaledContents(True)
        self.label.setObjectName("label")
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setGeometry(QtCore.QRect(40, 80, 31, 31))
        self.label_2.setText("")
        self.label_2.setPixmap(QtGui.QPixmap("../GuiGraphes/icon/create_state.png"))
        self.label_2.setScaledContents(True)
        self.label_2.setObjectName("label_2")
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setGeometry(QtCore.QRect(10, 130, 61, 31))
        self.label_3.setText("")
        self.label_3.setPixmap(QtGui.QPixmap("../GuiGraphes/icon/make_initial.png"))
        self.label_3.setScaledContents(True)
        self.label_3.setObjectName("label_3")
        self.label_11 = QtWidgets.QLabel(self.centralwidget)
        self.label_11.setGeometry(QtCore.QRect(110, 20, 241, 20))
        self.label_11.setObjectName("label_11")
        self.label_13 = QtWidgets.QLabel(self.centralwidget)
        self.label_13.setGeometry(QtCore.QRect(100, 130, 241, 20))
        self.label_13.setObjectName("label_13")
        self.label_14 = QtWidgets.QLabel(self.centralwidget)
        self.label_14.setGeometry(QtCore.QRect(100, 190, 221, 20))
        self.label_14.setObjectName("label_14")
        self.label_15 = QtWidgets.QLabel(self.centralwidget)
        self.label_15.setGeometry(QtCore.QRect(100, 240, 421, 20))
        self.label_15.setObjectName("label_15")
        self.label_16 = QtWidgets.QLabel(self.centralwidget)
        self.label_16.setGeometry(QtCore.QRect(100, 300, 611, 20))
        self.label_16.setObjectName("label_16")
        self.label_17 = QtWidgets.QLabel(self.centralwidget)
        self.label_17.setGeometry(QtCore.QRect(100, 410, 361, 20))
        self.label_17.setObjectName("label_17")
        self.label_18 = QtWidgets.QLabel(self.centralwidget)
        self.label_18.setGeometry(QtCore.QRect(100, 350, 331, 20))
        self.label_18.setObjectName("label_18")
        self.label_19 = QtWidgets.QLabel(self.centralwidget)
        self.label_19.setGeometry(QtCore.QRect(100, 480, 301, 20))
        self.label_19.setObjectName("label_19")
        self.label_20 = QtWidgets.QLabel(self.centralwidget)
        self.label_20.setGeometry(QtCore.QRect(90, 520, 401, 20))
        self.label_20.setObjectName("label_20")
        self.label_12 = QtWidgets.QLabel(self.centralwidget)
        self.label_12.setGeometry(QtCore.QRect(110, 80, 221, 20))
        self.label_12.setObjectName("label_12")
        self.label_4.raise_()
        self.label_5.raise_()
        self.label_6.raise_()
        self.label_7.raise_()
        self.label_8.raise_()
        self.label_9.raise_()
        self.label_10.raise_()
        self.label.raise_()
        self.label_2.raise_()
        self.label_3.raise_()
        self.label_11.raise_()
        self.label_12.raise_()
        self.label_13.raise_()
        self.label_14.raise_()
        self.label_15.raise_()
        self.label_16.raise_()
        self.label_17.raise_()
        self.label_18.raise_()
        self.label_19.raise_()
        self.label_20.raise_()
        MainWindowManual.setCentralWidget(self.centralwidget)
        self.statusbar = QtWidgets.QStatusBar(MainWindowManual)
        self.statusbar.setObjectName("statusbar")
        MainWindowManual.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindowManual)
        QtCore.QMetaObject.connectSlotsByName(MainWindowManual)

    def retranslateUi(self, MainWindowManual):
        _translate = QtCore.QCoreApplication.translate
        MainWindowManual.setWindowTitle(_translate("MainWindowManual", "Help"))
        self.label_11.setText(_translate("MainWindowManual", "Take a screen shot"))
        self.label_13.setText(_translate("MainWindowManual", "Make a state become initial"))
        self.label_14.setText(_translate("MainWindowManual", "Make a state become final"))
        self.label_15.setText(_translate("MainWindowManual", "Create a new transition between 2 chosen states "))
        self.label_16.setText(_translate("MainWindowManual", "Delete chosen states and all transitions connected to them."))
        self.label_17.setText(_translate("MainWindowManual", "Export graph as a text file"))
        self.label_18.setText(_translate("MainWindowManual", "Delete chosen transitions."))
        self.label_19.setText(_translate("MainWindowManual", "Rename a chosen transition or state"))
        self.label_20.setText(_translate("MainWindowManual", "Re-organise chosen node as a regular polygon"))
        self.label_12.setText(_translate("MainWindowManual", "Add a new state"))

#=========================================================
# Class Ui_MainWindow
#=========================================================
class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(903, 555)
        self.centralWidget = QtWidgets.QWidget(MainWindow)
        self.centralWidget.setObjectName("centralWidget")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.centralWidget)
        self.verticalLayout.setContentsMargins(11, 11, 11, 11)
        self.verticalLayout.setSpacing(6)
        self.verticalLayout.setObjectName("verticalLayout")
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setSpacing(6)
        self.horizontalLayout.setObjectName("horizontalLayout")
        # Graphic Views
        self.graphicsView =GraphWidget()
        self.graphicsView.setObjectName("graphicsView")
        # BUTTON 1 SCREENSHOT
        self.pushButton_1 = QtWidgets.QPushButton(self.centralWidget)
        self.pushButton_1.setIcon(QtGui.QIcon('icon/screenshot.png'))
        self.pushButton_1.setIconSize(QtCore.QSize(32,32))
        self.pushButton_1.setObjectName("pushButton_1")
        self.pushButton_1.clicked.connect(self.ScreenShot)
        self.horizontalLayout.addWidget(self.pushButton_1)
        # BUTTON 2 CREATE STATE
        self.pushButton_2 = QtWidgets.QPushButton(self.centralWidget)
        self.pushButton_2.setIcon(QtGui.QIcon('icon/create_state.png'))
        self.pushButton_2.setIconSize(QtCore.QSize(32,32))
        self.pushButton_2.setObjectName("pushButton_2")
        self.pushButton_2.clicked.connect(self.state)
        self.horizontalLayout.addWidget(self.pushButton_2)

        """
        ERROR : TypeError: connect() failed between clicked(bool) and on_click_2() -- FIXED -- delete @pyslot
        """
        #BUTTON 3 MAKE INITIAL
        self.pushButton_3 = QtWidgets.QPushButton(self.centralWidget)
        self.pushButton_3.setIcon(QtGui.QIcon('icon/make_initial.png'))
        self.pushButton_3.setIconSize(QtCore.QSize(32,32))
        self.pushButton_3.setObjectName("pushButton_3")
        self.pushButton_3.clicked.connect(self.initial)
        self.horizontalLayout.addWidget(self.pushButton_3)
        # BUTTON 4 MAKE FINAL
        self.pushButton_4 = QtWidgets.QPushButton(self.centralWidget)
        self.pushButton_4.setIcon(QtGui.QIcon('icon/make_final.png'))
        self.pushButton_4.setIconSize(QtCore.QSize(32,32))
        self.pushButton_4.setObjectName("pushButton_4")
        self.pushButton_4.clicked.connect(self.final)
        self.horizontalLayout.addWidget(self.pushButton_4)
        # BUTTON 5 CREATR TRANSITION
        self.pushButton_5 = QtWidgets.QPushButton(self.centralWidget)
        self.pushButton_5.setIcon(QtGui.QIcon('icon/create_transition.png'))
        self.pushButton_5.setIconSize(QtCore.QSize(32,32))
        self.pushButton_5.setObjectName("pushButton_5")
        self.pushButton_5.clicked.connect(self.transition)
        self.horizontalLayout.addWidget(self.pushButton_5)
        # BUTTON 6 REMOVE STATE
        self.pushButton_6 = QtWidgets.QPushButton(self.centralWidget)
        self.pushButton_6.setIcon(QtGui.QIcon('icon/delete_state.png'))
        self.pushButton_6.setIconSize(QtCore.QSize(32,32))
        self.pushButton_6.setObjectName("pushButton_6")
        self.pushButton_6.clicked.connect(self.remove)
        self.horizontalLayout.addWidget(self.pushButton_6)
        # BUTTON 7 DELETE TRANSITION
        self.pushButton_7 = QtWidgets.QPushButton(self.centralWidget)
        self.pushButton_7.setIcon(QtGui.QIcon('icon/delete_transition.png'))
        self.pushButton_7.setIconSize(QtCore.QSize(32,32))
        self.pushButton_7.setObjectName("pushButton_7")
        self.pushButton_7.clicked.connect(self.removeEdge)
        self.horizontalLayout.addWidget(self.pushButton_7)
        # BUTTON 8 EXPORT
        self.pushButton_8 = QtWidgets.QPushButton(self.centralWidget)
        self.pushButton_8.setIcon(QtGui.QIcon('icon/export.png'))
        self.pushButton_8.setIconSize(QtCore.QSize(32,32))
        self.pushButton_8.setObjectName("pushButton_8")
        self.pushButton_8.clicked.connect(self.export)
        self.horizontalLayout.addWidget(self.pushButton_8)
        # BUTTON 9 RENAME
        self.pushButton_9 = QtWidgets.QPushButton(self.centralWidget)
        self.pushButton_9.setIcon(QtGui.QIcon('icon/rename.png'))
        self.pushButton_9.setIconSize(QtCore.QSize(32,32))
        self.pushButton_9.setObjectName("pushButton_9")
        self.pushButton_9.clicked.connect(self.rename)
        self.horizontalLayout.addWidget(self.pushButton_9)
        # BUTTON 10 REORGANISE
        self.pushButton_10 = QtWidgets.QPushButton(self.centralWidget)
        self.pushButton_10.setIcon(QtGui.QIcon('icon/organise.png'))
        self.pushButton_10.setIconSize(QtCore.QSize(32,32))
        self.pushButton_10.setObjectName("pushButton_10")
        self.pushButton_10.clicked.connect(self.reorganize)
        self.horizontalLayout.addWidget(self.pushButton_10)
        # BUTTON 11 HELP
        self.pushButton_11 = QtWidgets.QPushButton(self.centralWidget)
        self.pushButton_11.setIcon(QtGui.QIcon('icon/help.png'))
        self.pushButton_11.setIconSize(QtCore.QSize(32,32))
        self.pushButton_11.setObjectName("pushButton_11")
        self.pushButton_11.clicked.connect(self.manual)
        self.horizontalLayout.addWidget(self.pushButton_11)
        # Set vertical layout
        self.verticalLayout.addLayout(self.horizontalLayout)
        # Graphic Scene








        self.verticalLayout.addWidget(self.graphicsView)
        MainWindow.setCentralWidget(self.centralWidget)
        self.menuBar = QtWidgets.QMenuBar(MainWindow)
        self.menuBar.setGeometry(QtCore.QRect(0, 0, 903, 28))

        # Menu Bar
        self.menuBar.setObjectName("menuBar")
        MainWindow.setMenuBar(self.menuBar)
        self.mainToolBar = QtWidgets.QToolBar(MainWindow)
        self.mainToolBar.setObjectName("mainToolBar")
        MainWindow.addToolBar(QtCore.Qt.TopToolBarArea, self.mainToolBar)
        self.statusBar = QtWidgets.QStatusBar(MainWindow)
        self.statusBar.setObjectName("statusBar")
        MainWindow.setStatusBar(self.statusBar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "Graph GUI "))

    #This is functions of layout
    def ScreenShot(self):
        # COMPLETE
        self.graphicsView.scene.exportAsPng()
    def state(self):
        #QApplication.setOverrideCursor(Qt.QtCoressCursor)
        #self.flag_add = 1
        self.graphicsView.scene.create_state()
    def initial(self):
        # COMPLETE
        self.graphicsView.scene.create_initial()
    def final(self):
        # COMPLETE
        self.graphicsView.scene.create_final()
    def transition(self):
        self.graphicsView.scene.create_transition()
    def export(self):
        self.graphicsView.scene.export()
    def remove(self):
        self.graphicsView.scene.delete_selected_states()
        # self.graphicsView.scene.removeItem(self.node10)
    def removeEdge(self):
        self.graphicsView.scene.delete_transition()
        #self.graphicsView.scene.delete_edge_selected()
    def rename(self):
        self.graphicsView.scene.rename()
    def reorganize(self):
        self.graphicsView.scene.reorganize()
    def manual(self):
        # import sys
        ui1 = manual()
        ui1.setupUi(MainWindowManual)
        MainWindowManual.show()
        # @sys.exit(app.exec_())



#=========================================================
# Main
#=========================================================
if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    MainWindowManual = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
