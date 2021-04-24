/*
  * Copyright 2010, David W. Drell
  *
  * This is free sample code. Use as you wish, no warranties.
  */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSizePolicy>
#include <QGraphicsLineItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow()),
    scene( new QGraphicsScene()),
    gview( new QGraphicsView ()),
    stateBox( new StateBox()),
    gridLines( NULL )
{
    QColor c (242,251,235); // create the background color

    QBrush brush (c, Qt::SolidPattern);
    scene->setBackgroundBrush(brush);

    /*
    QtCreator generates ui_mainwindow.h, which defines a new class Ui_MainWindow,
    then makes MainWindow inherit Ui_MainWindow. Ui_MainWindow defines the setupUi() method which creates instances of all
    QtCreator objects.
    */
    ui->setupUi(this);

    /*
     I used QtCreator's design surface (right-click on main window area) to add a layout
     to hold the graphics view. This also allows the graphicsview to change size  and expand/contract
     to fill the window area as the user changes the size of the main window frame.
     */
    ui->horizontalLayout->addWidget( gview);

    /* I created a gridLines class to draw a grid to make it interresting and have
       the chance to see layering of objects in action.
       */
    gridLines = new GridLines (this->width(), this->height());
    scene->addItem(gridLines);

    /*
     scene holds the custom QGraphicsItem stateBox
    */
    stateBox->setPos(100,100); // give my sample box a starting position (otherwise it would be at 0,0)
    scene->addItem( stateBox);


    /*
     setSizePolicy, when used with the horizontalLayout widget, allows the grapicsview to expand/contract
     as the user re-sizes the main window.
    */
    gview->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    /*
        add the scene to the QGraphicsView
    */
    gview->setScene(  scene);

    gview->show(); //let the show begin

}

/* re-implement the resizeEvent handler from the QMainWindow base class,
   so I can capture the main window resize events, and pass on the new
   window size to my grid drawing object.
   */
void MainWindow::resizeEvent(QResizeEvent * )
{
    QSize wsize = ui->centralWidget->frameSize();

    if ( gridLines) gridLines->handleWindowSizeChanged(wsize.width(), wsize.height());

    qDebug() << "cw frame height" << wsize.height() << " width: " << wsize.width();
}


MainWindow::~MainWindow()
{
    delete gview;
    delete stateBox;
    delete scene;
    delete ui;
}

