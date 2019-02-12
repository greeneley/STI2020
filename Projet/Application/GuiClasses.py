#=========================================================
# Imports
#=========================================================
import sys
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *
import math
from random import randint

#=========================================================
# Class State
#=========================================================
class State(QGraphicsItem):
    """
    Class that defines states in automata
    """

    def __init__(self, graphWidget, val):
        super(State, self).__init__()
        self.TransitionList = []
        self.newPosition = QtCore.QPointF()
        self.setFlag(QGraphicsItem.ItemIsMovable)
        self.setFlag(QGraphicsItem.ItemSendsGeometryChanges)
        self.setFlag(QGraphicsItem.ItemIsSelectable)
        self.setCursor(Qt.OpenHandCursor)
        self.selected = False
        self.initial = False
        self.final = False
        self.val = val
        self.arrowSize = 5.0

    def addTransition(self, Transition):
        """
        Add a transition in TransitionList d'un node.
        """
        self.TransitionList.append(Transition)
        Transition.adjust()

    def Transitions(self):
        return self.TransitionList

    def move_state(self, newPosX, newPosY):
        if self.newPosition == self.pos():
            return False
        self.setPos(newPosX, newPosY)
        return True

    def boundingRect(self):
        #Return bounding rectangle of each state
        modifiable = 2.0
        return QtCore.QRectF(-10 - modifiable, -10 - modifiable, 23 + modifiable,
                23 + modifiable)

    def shape(self):
        """
        Define shape for node
        """
        path = QtGui.QPainterPath()
        path.addEllipse(-10, -10, 25, 25)
        return path

    def paint(self, painter, option, widget):
        """
        Set color for States , change color when select and deselect state

        """
        if self.selected :
            # In this case, we choose as right click
            self.setSelected(0)
            # if the state is seleted paint it orange
            # Set pen to black
            painter.setPen(Qt.black)
            painter.setBrush(QColor(223,50, 0, 255))
            # paint the initial state orange when selected and keep the arrow. Description for drawing arrow is explained in method Transition.paint()
            if self.initial:
                arrow = QPointF(-10, 0)
                line = QLineF(-30, 0, -10,0)
                angle = math.acos(line.dx() / line.length())
                if line.dy() >= 0:
                    angle = math.pi * 2 - angle
                destArrowP1 = arrow + QtCore.QPointF(math.sin(angle - math.pi / 3) * self.arrowSize,
                                                          math.cos(angle - math.pi / 3) * self.arrowSize)
                destArrowP2 = arrow + QtCore.QPointF(math.sin(angle - math.pi + math.pi / 3) * self.arrowSize,
                                                          math.cos(angle - math.pi + math.pi / 3) * self.arrowSize)
                painter.drawPolygon(QPolygonF([line.p2(), destArrowP1, destArrowP2 ]))
                painter.setPen(Qt.black)
                painter.drawLine(-10, 0, -30, 0)
                # paint the final state orange when selected, keep the outside circle
            elif self.final:
                painter.drawEllipse(QtCore.QRectF(-25 / 2.0, -25 / 2.0, 25, 25)) # draw the state initial
        elif self.isSelected():
            # In this case, we choose as left click or choose mouse area by left click
            # pain it green when selected
            painter.setPen(Qt.black)
            painter.setBrush(Qt.green)
            if self.initial:
                arrow = QPointF(-10, 0)
                line = QLineF(-30, 0, -10,0)
                angle = math.acos(line.dx() / line.length())
                if line.dy() >= 0:
                    angle = math.pi * 2 - angle
                destArrowP1 = arrow + QtCore.QPointF(math.sin(angle - math.pi / 3) * self.arrowSize,
                                                          math.cos(angle - math.pi / 3) * self.arrowSize)
                destArrowP2 = arrow + QtCore.QPointF(math.sin(angle - math.pi + math.pi / 3) * self.arrowSize,
                                                          math.cos(angle - math.pi + math.pi / 3) * self.arrowSize)
                painter.drawPolygon(QPolygonF([line.p2(), destArrowP1, destArrowP2 ]))
                painter.setPen(Qt.black)
                painter.drawLine(-10, 0, -30, 0)
            elif self.final:
                painter.drawEllipse(QtCore.QRectF(-25 / 2.0, -25 / 2.0, 25, 25)) # draw the state initial
        # draw the initial state (when we create or unselected)
        elif self.initial:
                arrow = QPointF(-10, 0)
                line = QLineF(-30, 0, -10,0)
                angle = math.acos(line.dx() / line.length())
                if line.dy() >= 0:
                    angle = math.pi * 2 - angle
                destArrowP1 = arrow + QtCore.QPointF(math.sin(angle - math.pi / 3) * self.arrowSize,
                                                             math.cos(angle - math.pi / 3) * self.arrowSize)
                destArrowP2 = arrow + QtCore.QPointF(math.sin(angle - math.pi + math.pi / 3) * self.arrowSize,
                                                              math.cos(angle - math.pi + math.pi / 3) * self.arrowSize)
                painter.drawPolygon(QPolygonF([line.p2(), destArrowP1, destArrowP2 ]))
                painter.setPen(Qt.black)
                painter.drawLine(-10, 0, -30, 0)
        # draw the final state (when we create or unselected)
        elif self.final:
            painter.drawEllipse(QtCore.QRectF(-25 / 2.0, -25 / 2.0, 25, 25));
        else:
            # draw the normal state (when we create or unselected)
            painter.setPen(Qt.black)
            painter.setBrush(Qt.white)
        painter.drawEllipse(QtCore.QRectF(-20 / 2.0, -20 / 2.0, 20, 20));
        painter.drawText(QtCore.QRect(-10, -10, 20, 20), QtCore.Qt.AlignCenter, self.val)
        self.update()

    def itemChange(self, change, value):
        """
        Return new State when we change its positions, make the arrow follows the state
        """
        if change == QGraphicsItem.ItemPositionHasChanged:
            for Transition in self.TransitionList:
                Transition.adjust()

        return super(State, self).itemChange(change, value)


#=========================================================
# Class Transition
#=========================================================
class Transition(QGraphicsItem):
    """
    Class defines transitions of automata.
    """
    def __init__(self, sourceState, destState, val):
        super(Transition, self).__init__()
        self.arrowSize = 5.0
        self.sourcePoint = QPointF()  # Define source point
        self.destPoint = QPointF()    # Define destination point
        self.setAcceptedMouseButtons(Qt.NoButton)
        self.setFlag(QGraphicsItem.ItemIsSelectable)
        self.source = sourceState
        self.dest = destState
        self.source.addTransition(self)
        self.dest.addTransition(self)
        self.val = val
        self.adjust()
        self.selected = False

    def setSourceState(self, state):
        self.source = state
        self.adjust()

    def setDestState(self, state):
        self.dest = state
        self.adjust()

    def adjust(self):
        """
        Adjust the lines and arrows when we move states in the scene
        """
        if not self.source or not self.dest:
            return
        """
        mapfromItem: Maps the a point which is in item's coordinate system, to this item's coordinate system, and returns the mapped coordinate.
        If coordinate x of destination point > coordinate x de source point, reduce the x coordinate of source state et dest state 3, create a line between theese two points mapped.
        If not, raise the x coordinate the x coordinate of source state et dest state 3, create a line between theese two points mapped.
        This part of code has been done to avoid that 2 lines coincide.
        """
        if ( self.destPoint.x() - self.sourcePoint.x() > 0 ):
            line = QLineF(self.mapFromItem(self.source, 0, -3),
                self.mapFromItem(self.dest, 0, -3))
        else:
            line = QLineF(self.mapFromItem(self.source, 0, 3),
                self.mapFromItem(self.dest, 0, 3))

        length = line.length()
        # Detect when a geometry has changed its position
        self.prepareGeometryChange()


        if length > 20.0: # why 20, because the radius of the circle is 12.5, and the side of bounding rectangle of a circle is 25.
            stateOffset = QtCore.QPointF((line.dx() * 10) / length,
                    (line.dy() * 10) / length)

            self.sourcePoint = line.p1() + stateOffset
            self.destPoint = line.p2() - stateOffset
        else:
            # If the lenght of line is too small, we can ignore them and set destPoint and sourcePoint as an unique point
            self.sourcePoint = line.p1()
            self.destPoint = line.p1()
    def boundingRect(self):
        """
        Return bounding rectangle of a transition -- the zone that we can click on to choose transition
        """
        if not self.source or not self.dest:
            return QRectF()
        # define width of pen
        penWidth = 1.0
        extra = (penWidth + self.arrowSize) / 2.0

        return QRectF(self.sourcePoint,
                QSizeF(self.destPoint.x() - self.sourcePoint.x(),
                        self.destPoint.y() - self.sourcePoint.y())).normalized().adjusted(-extra, -extra, extra, extra)

    def paint(self, painter, option, widget):
        """
        Draw the transition on scene, change the color of transition when we select it
        """
        if not self.source or not self.dest:
            return
        # Define the line between sourcePoint and destination Point
        line = QLineF(self.sourcePoint, self.destPoint)
        if line.length() == 0.0:
            return
        if self.selected:
            # if the transition is choosen then paint it blue.
            # Q Roundjoin: A circular arc between the two lines is filled.
            # Q.RoundCap : a rounded line end.
            painter.setPen(QPen(Qt.blue, 1,Qt.SolidLine,
                    Qt.RoundCap,Qt.RoundJoin))
        else:   # else paint it black as causual.
            painter.setPen(QPen(Qt.black, 1,Qt.SolidLine,
                    Qt.RoundCap,Qt.RoundJoin))
        # draw the line on scene using drawLine
        painter.drawLine(line)
        """
        This section is implemented to draw the head of the arrow. We utilise degree in radial unit here.
        An arrow is in fact a regular triangle , with a vertex is the destPoint.
        Notice that in pyQT5, Ox has the same direction normaly, but the positive direction of Oy is from top to bottom (inverse the real life)
        """
        # Draw the arrows if there's enough room.
        # line.dx() Returns the horizontal component of the line's vector.
        # line.length() return the length of the line
        # Define angle of a line: the angle is the cosin (unit : radial ) of the ratio of line.dx and line.length()
        angle = math.acos(line.dx() / line.length())
        # line.dy() Returns the horizontal component of the line's vector. If line.dy > 0 we take 2.pi -angle (in this case the new angle will be > 1*pi -- 180o)
        # so the head of arrow can be surrounded the circle.
        # the angle is the angle of a vector withthe direction of the arrow (source -> dest) - line Ox), the value of angle is 0*pi -> 2*pi as we rotate the line in the positive direction - counter-clockwise.
        if line.dy() >= 0:
            angle = math.pi * 2 - angle
        # This section is to find 2 other vertices of triangle arrow. We find the point by adding a0 vector to destPoint (QPointF can be used as a vector)
        # Exemple: for the point destArrowP1 of triangle (the left-bottom vertex of the triangle) This vector has the length = arrowSize and is defined as:
        #   dx : arrowSize * sin(angle - pi/3)
        #   dy : arrowSize * cos(angle - pi/3)
        destArrowP1 = self.destPoint + QtCore.QPointF(math.sin(angle - math.pi / 3) * self.arrowSize,
                                                     math.cos(angle - math.pi / 3) * self.arrowSize)
        destArrowP2 = self.destPoint + QtCore.QPointF(math.sin(angle - math.pi + math.pi / 3) * self.arrowSize,
                                                      math.cos(angle - math.pi + math.pi / 3) * self.arrowSize)
        painter.setBrush(Qt.black)
        painter.drawPolygon(QPolygonF([line.p2(), destArrowP1, destArrowP2]))
        self.midx = (self.sourcePoint.x() + self.destPoint.x())/2
        self.midy = (self.sourcePoint.y() + self.destPoint.y())/2
        if ( self.destPoint.x() - self.sourcePoint.x() > 0 ):
            painter.drawText(self.midx - 10, self.midy - 10  , self.val) # draw weight
        else:
            painter.drawText(self.midx -10, self.midy  +20  , self.val) # draw weight
        self.update()
#=========================================================
# Class self-Transition
#=========================================================
class selfTransition(Transition):
    """
    Class defines transitions of automata.
    """
    Type = QGraphicsItem.UserType + 2
    def __init__(self,State,trans_val):
        Transition.__init__(self,State,State,trans_val)

    def boundingRect(self):
        """
        Return bounding rectangle of a transition -- the zone that we can click on to choose transition
        """
        if not self.source or not self.dest:
            return QRectF()

        penWidth = 1.0
        extra = (penWidth + self.arrowSize) / 2.0

        return QRectF(self.sourcePoint,
                QSizeF(self.destPoint.x() + self.sourcePoint.x() - 100,
                        self.destPoint.y() - self.sourcePoint.y()- 100 )).normalized().adjusted(-extra, -extra, extra, extra)
    def paint(self, painter, option, widget):
        """
        Draw the transition on scene, change the color of transition when we select it
        """
        if not self.source or not self.dest:
            return
        # Draw the line itself.
        path = QPainterPath()
        path.moveTo(self.sourcePoint.x(), self.sourcePoint.y())
        path.cubicTo(self.sourcePoint.x(), self.sourcePoint.y()-100, self.sourcePoint.x()-100, self.sourcePoint.y(), self.sourcePoint.x(), self.sourcePoint.y())
        # draw the curve
        self.midx = (self.sourcePoint.x() + self.destPoint.x()-100)/2
        self.midy = (self.sourcePoint.y()-100 + self.destPoint.y())/2

        # change color when self-transision is selected or not.
        if not self.selected:
            painter.setPen(QPen(Qt.black, 1,Qt.SolidLine,
                    Qt.RoundCap,Qt.RoundJoin))
        else:
            painter.setPen(QPen(Qt.blue, 1,Qt.SolidLine,
                    Qt.RoundCap,Qt.RoundJoin))
        painter.drawPath(path)
        painter.drawText(self.midx,self.midy,self.val)
        self.update()


#=========================================================
# Class Scene
#=========================================================
class Scene(QGraphicsScene):
    def __init__(self):
        super(QGraphicsScene, self).__init__()
        self.state_selected = []
        self.trans_selected = []
        self.states_list = []
        self.InvalidInMsg = QMessageBox()
        self.InvalidInMsg.setStandardButtons(QMessageBox.Ok)
        self.InvalidInMsg.setWindowTitle('Invalid input alert!')


    def deselect_states(self):
        """
        Deselect all states
        """
        for state in self.state_selected:
            state.selected = False
        self.state_selected = []

    def deselect_transitions(self):
        """
        Deselect all transitions
        """
        for trans in self.trans_selected:
            trans.selected = False
        self.trans_selected = []
    def keyPressEvent(self, event):
        """
        if delete pressed
        remove edge between selected nodes
        """
        if event.key() == QtCore.Qt.Key_Delete:
            self.delete_selected_states()

    def mouseDoubleClickEvent(self,event):
        """
        Rename with double mouse click
        """
        self.select_elements(event)
        self.rename()

    def mousePressEvent(self, event):
        """
        Click right button to chose items
        Click mid button to rename item chosen ( only 1 item chosen can be renamed)
        """

        if event.button() == QtCore.Qt.RightButton:
            self.select_elements(event)
            return
        if event.button() == QtCore.Qt.MidButton:
            self.rename()
            return
        QtWidgets.QGraphicsScene.mousePressEvent(self, event)

    def create_state(self):
        """
        Create new state , random place it on scene, add to states_list
        """
        state = State(self,"")
        self.addItem(state)
        state.setPos(randint(-50, 50), randint(-50, 50))
        self.states_list.append(state)
        self.update()
    def create_initial(self):
        """
        Make chosen states  initials
        """
        for state in self.state_selected:
            state.final = False
            state.initial = True
        self.deselect_states()
        self.update()
    def create_final(self):
        """
        Make chosen states  finals
        """
        for state in self.state_selected:
            state.initial = False
            state.final = True
        self.deselect_states()
        self.update()

    def select_elements(self, event):
        """
        Change color and status of chosen items. Add to list state_selected or trans_selected
        """
        element  = self.itemAt(event.scenePos(), QtGui.QTransform()) # get item clicked on at this position in scene
        # if it is a state,and not chosen yet, choose it add to state_selected,  if it is already chosen we deselect it and remove from state_selected
        if isinstance(element,State):
            if element.selected == False:
                element.selected = True
                self.state_selected.append(element)
            else:
                element.selected = False
                self.state_selected.remove(element)
        # if it is a transition or self-transition,and not chosen yet, choose it add to trans_selected,  if it is already chosen we deselect it and remove from trans_selected
        if isinstance(element,Transition) or isinstance(element,selfTransition) :
            if element.selected == False:
                element.selected = True
                self.trans_selected.append(element)
            else:
                element.selected = False
                self.trans_selected.remove(element)
        self.update()

    def create_transition(self):
        """
        Create transition between 2 chosen state. The first chosen one is source, the second is destination
        We can choose one state to create a transition towards itself.
        """
        trans_val, ok = QtWidgets.QInputDialog.getText(QtWidgets.QMainWindow(), 'Create Transition',
            'Enter Transition Name:')
        if ok:
            # If 2 states are chosen, create a transition with a name between these.
            if len(self.state_selected)== 2:
                # Check if between 2 states there is already a transition
                for trans in self.items():
                    if isinstance(trans,Transition):
                        if trans.source == self.state_selected[0] and trans.dest == self.state_selected[1]:
                            self.InvalidInMsg.setText('Transition already exists')
                            self.InvalidInMsg.exec_()
                            self.deselect_states()
                            return
                # If there isn't, we create a new transition
                self.addItem(Transition(self.state_selected[0],self.state_selected[1], trans_val))
                self.deselect_states()
                self.update()
            elif len(self.state_selected) == 1:
                # if only 1 state is chosen, we create a self-transition of that state
                self.addItem(selfTransition(self.state_selected[0],trans_val))
                self.deselect_states()
                self.update()
            else:
                # if we choose > 2 transition, we can not create a transition
                self.InvalidInMsg.setText('Must select 2 states to create transition')
                self.InvalidInMsg.exec_()

    def delete_selected_states(self):
        """
        Delete chosen state and all transitions connect to it.
        """
        for state in self.state_selected: # for each of the selected states
            for i in range(len(state.TransitionList)):
                self.removeItem(state.TransitionList[i])
            self.removeItem(state)
        for state in self.selectedItems():
            # check on all selected items, if there are states then delete them.
            if isinstance(state,State):
                for i in range(len(state.TransitionList)):
                    self.removeItem(state.TransitionList[i])
                self.removeItem(state)
                state.setSelected(0)
        self.state_selected = []
        self.update()

    def delete_transition(self):
        """
        Delete chosen transitions.
        """
        # Firstly, on delete the transition in TransitionList of source state and dest state
        for transition in self.trans_selected:
            source = transition.source
            dest = transition.dest
            for trans in source.TransitionList:
                if trans == transition:
                    source.TransitionList.remove(transition)
            for trans in dest.TransitionList:
                if trans == transition:
                    dest.TransitionList.remove(transition)
            # then remove item from scene.
            self.removeItem(transition)
            #self.trans_list.remove(state)
        for transition in self.selectedItems():
            # check on all selected items, if there are states then delete them.
            if isinstance(transition,Transition) or isinstance(transition,selfTransition):
                self.removeItem(transition)
                transition.setSelected(0)
        self.trans_selected = []
        self.update()
    def exportAsPng(self):
        """
        Do a screenshot and export as a PNG picture file.
        """
        pixmap = QtGui.QImage(self.width(), self.height(),QtGui.QImage.Format_ARGB32_Premultiplied )
        painter = QtGui.QPainter()
        painter.begin(pixmap)
        painter.setRenderHint(QtGui.QPainter.Antialiasing, True)
        self.render(painter)
        painter.end()
        pixmap.save("Graph", "PNG")
        msgBox = QMessageBox()
        msgBox.setStandardButtons(QMessageBox.Ok)
        msgBox.setWindowTitle('message box')
        msgBox.setText('screenshot written in the file')
        msgBox.exec_()
        return

    def export(self):
        """
        Export the graph as a text file:
        Exemple:
            States:
            q3 (-74.99999999999997 , 129.9038105676658)
            q2 (150.0 , 0.0)
            q1 (-75.00000000000007 , -129.90381056766574)


            Transitions:
            q2,b,q3
            q1,a,q2


            Initials:
            q1

            Finals:
        q3
        """
        state = str()
        trans = str()
        initial = str()
        final = str()
        autoNomination = 1 # used to give number(name) on state that was exported without name
        for i in self.items():
            if isinstance(i, State):
                if i.val == "":
                    state += "{} ({} , {})\n".format(autoNomination, i.pos().x(), i.pos().y())
                    name = autoNomination
                    autoNomination += 1
                else:
                    state += "{} ({} , {})\n".format(i.val, i.pos().x(), i.pos().y())
                    name = i.val
                if i.final:
                    final += "{} ".format(name)
                elif i.initial:
                    initial += "{} ".format(name)
            elif isinstance(i, Transition):
                trans += "{},{},{}\n".format(i.source.val, i.val, i.dest.val)
        with open("graph.txt",'w') as f:
            info = "\n\nStates: \n{}\n\nTransitions: \n{}\n\nInitials: \n{}\n\nFinals: \n{}\n\n".format(state, trans, initial, final)
            f.write(str(info))
        f.close()
        msgBox = QMessageBox()
        msgBox.setStandardButtons(QMessageBox.Ok)
        msgBox.setWindowTitle('message box')
        msgBox.setText('data written in the file')
        msgBox.exec_()
        return

    def rename(self):
        new_val, ok = QtWidgets.QInputDialog.getText(QtWidgets.QMainWindow(), 'Rename state',
            'Enter new name of state or transition:')
        if ok:
            # if the entered champ is empty, we push an Invalid message
            if new_val == "":
                self.InvalidInMsg.setText('A state or transition must have a new name!')
                self.InvalidInMsg.exec_()
            else:
                # We only allow one transition or one state can be renamed each time
                if len(self.trans_selected) == 1:
                    for transition in self.trans_selected:
                        # Delete the transition and create a new one with new name
                        if type(transition) == Transition:
                            self.removeItem(transition)
                            self.addItem(Transition(self.trans_selected[0].source,self.trans_selected[0].dest, new_val))
                            self.trans_selected.clear()
                            self.deselect_transitions()
                            self.update()
                        else:
                            self.removeItem(transition)
                            self.addItem(selfTransition(self.trans_selected[0].source, new_val))
                            self.trans_selected.clear()
                            self.deselect_transitions()
                            self.update()
                elif len(self.state_selected) == 1:
                    flag = True
                    for state in self.state_selected:
                         # Delete the state and create a new one with new name
                        for item in self.items():
                            if isinstance(item,State):
                                if item.val == new_val:
                                    flag = False
                        if flag:
                            state.val=new_val
                            state.setPos(state.pos().x(),state.pos().y())
                            self.deselect_states()
                            self.state_selected.clear()
                            self.update()
                        else:
                            self.InvalidInMsg.setText('A state with this name exist')
                            self.InvalidInMsg.exec_()

                # If we choose plus than 2 items, we push an InvalidMsg
                else:
                    self.InvalidInMsg.setText('Only 1 state !')
                    self.InvalidInMsg.exec_()


    def reorganize(self,radius=150, s=0):
        """
        Reorganise chosen state as a form of a regular polygon
        """
        deplace = 800
        stateselected=[]
        for state in self.selectedItems():
            if isinstance(state,State):
                stateselected.append(state)

        if len(stateselected) > 0:
            ''' then calcul geometric form '''
            w = 360 / len(stateselected)
            for i in range(len(stateselected)):
                t = w * i + deplace
                x = radius * math.cos(math.radians(t))
                y = radius * math.sin(math.radians(t))
                stateselected[i].move_state(x, y)
        elif len(self.state_selected) > 0:
            ''' then calcul geometric form '''
            w = 360 / len(self.state_selected)
            for i in range(len(self.state_selected)):
                t = w * i + deplace
                x = radius * math.cos(math.radians(t))
                y = radius * math.sin(math.radians(t))
                self.state_selected[i].move_state(x, y)
        self.deselect_states()
        for i in stateselected:
            i.setSelected(0)
        stateselected = []

#=========================================================
# Class GraphWidget
#=========================================================
class GraphWidget(QGraphicsView):
    """
    Graph Widget definition
    """
    def __init__(self):
        super(GraphWidget, self).__init__()

        self.scene = Scene()
        self.scene.setItemIndexMethod(QGraphicsScene.NoIndex)
        #scene.setSceneRect(-200, -200, 400, 400)
        self.setScene(self.scene)
        self.setCacheMode(QGraphicsView.CacheBackground)
        self.setViewportUpdateMode(QGraphicsView.BoundingRectViewportUpdate)
        self.setRenderHint(QPainter.Antialiasing)
        self.setTransformationAnchor(QGraphicsView.AnchorUnderMouse)
        self.setResizeAnchor(QGraphicsView.AnchorViewCenter)
        self.setDragMode(QGraphicsView.RubberBandDrag)


    def wheelEvent(self, event):
        """
        We can zoom in/ zoom out the GraphicsView by using wheelButton of the mouse.
        """
        self.zoomView(math.pow(2.0, -event.angleDelta().y() / 200.0))
    def zoomView(self, zoomFactor):
        """
        Scale with the factor calculated.
        """
        factor = self.transform().scale(zoomFactor, zoomFactor).mapRect(QRectF(0, 0, 1, 1)).width()
        if factor < 0.09 or factor > 50:
            return
        self.scale(zoomFactor, zoomFactor)
