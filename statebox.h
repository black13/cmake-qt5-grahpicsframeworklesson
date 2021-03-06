/*
  * Copyright 2010, David W. Drell
  *
  * This is free sample code. Use as you wish, no warranties.
  */

#ifndef STATEBOX_H
#define STATEBOX_H

#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>
#include <QColor>
#include <QPainter>
#include <QPen>
#include <QPointF>



/**
  * \class StateBox
  *  This is short example/demonstration of creating a custom QGraphicsItem.
  *  Example usage of a custom QGraphicsItem in a QGraphicsScene with examples of mouse hover events.
  *
  *  My goal was to create a simpe box, in the shape of a UML State/Class box, with a title
  *  area seprated from a main arear below by line.
  *
  *  This sample class inherits from QGraphicsItem, and must reimplement boundingRect() and paint()
  *  from the base class.
  *
  *  To learn about handling mouse events in a QGraphicsScene, I wanted my box to turn red when the mouse moves inside, and black
  *  when the mouse moves out. I also allow the user to drag the box around the scene.
  */

class StateBox : public QGraphicsItem
{
public:
    StateBox();
    QGraphicsTextItem _text;    ///< sample text to go in the title area.

    void setGridSpace(int space);

    protected:

    virtual QRectF boundingRect() const; ///< must be re-implemented in this class to provide the diminsions of the box to the QGraphicsView
    virtual void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); ///< must be re-implemented here to pain the box on the paint-event
    virtual void hoverEnterEvent ( QGraphicsSceneHoverEvent * event ); ///< must be re-implemented to handle mouse hover enter events
    virtual void hoverLeaveEvent ( QGraphicsSceneHoverEvent * event ); ///< must be re-implemented to handle mouse hover leave events
    virtual void mouseMoveEvent ( QGraphicsSceneMouseEvent * event );
    virtual void mouseMoveEvent(QGraphicsSceneDragDropEvent *event);
    virtual void mousePressEvent (QGraphicsSceneMouseEvent * event );
    virtual void mousePressEvent(QGraphicsSceneDragDropEvent *event);
    virtual void mouseReleaseEvent (QGraphicsSceneMouseEvent * event );
    QColor  _outterborderColor; ///< the hover event handlers will toggle this between red and black
    QPen    _outterborderPen; ///< the pen is used to paint the red/black border
    QPointF _location;
    QPointF _dragStart;
    int     _gridSpace;
    qreal   _width;
    qreal   _height;
};

#endif // STATEBOX_H
