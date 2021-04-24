/*
  * Copyright 2010, David W. Drell
  *
  * This is free sample code. Use as you wish, no warranties.
  */

#ifndef GRIDLINES_H
#define GRIDLINES_H
#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>

#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>

class GridLines : public  QGraphicsItem
{

public:
    GridLines(int width, int height);

    public :

    void handleWindowSizeChanged(int w, int h);

    private:

    int _width;
    int _height;
    int _space;

    virtual QRectF boundingRect() const; ///< must be re-implemented in this class to provide the diminsions of the box to the QGraphicsView
    virtual void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); ///< must be re-implemented here to pain the box on the paint-event
    virtual void mouseMoveEvent ( QGraphicsSceneMouseEvent * event );
    virtual void mouseMoveEvent(QGraphicsSceneDragDropEvent *event);
    virtual void mousePressEvent (QGraphicsSceneMouseEvent * event );
    virtual void mousePressEvent(QGraphicsSceneDragDropEvent *event);
};

#endif // GRIDLINES_H
