#include "splinedisplay.h"

SplineDisplay::SplineDisplay(SplineHandler* handlerIn, QWidget *parent) : QWidget(parent)
{

    handler = handlerIn;
    layout = new QGridLayout(this);
    scene = new QGraphicsScene(this);
//    QPen pen(Qt::green);//Просто выбираем цвет для карандашика
//    scene->addLine(0,0,10000,10000,pen);//x
//    scene->addLine(90,0,90,180,pen);//y
    view = new QGraphicsView(scene, this);
    view -> show();
    layout -> addWidget(view);
    setLayout(layout);
    this -> setMinimumSize(600,600);
    updater = new QTimer(this);
    connect(updater, &QTimer::timeout, this, &SplineDisplay::repaint);
    updater->start(100);
    view -> setInteractive(true);
    view -> setRenderHint(QPainter::Antialiasing);
    //this -> saveGeometry()
//    QPalette p(palette());
//    p.setColor(QPalette::Background, Qt::black);
//    setAutoFillBackground(true);
//    setPalette(p);

}

void SplineDisplay::repaint()
{
    //view->fitInView(std::max(scene->itemsBoundingRect(),QRectF(0,0,300,300)),Qt::KeepAspectRatio);
    //view->fitInView(scene->itemsBoundingRect(),Qt::KeepAspectRatio);
    scene -> clear();
    QPen cord(Qt::black);
    //scene -> addLine(-10000, 0, 10000, 0, cord);
    //scene -> addLine(0, -10000, 0, 10000, cord);
    for(auto &n : handler -> splines)
    {
        QPen pen(n -> color);
        if(n -> knotVisible)
        {
            for(auto &knot : n -> knots)
            {
               scene -> addEllipse(knot -> x - 2, -(knot -> y + 2), 5, 5, pen);
            }
        }
        if(n -> line)
        {
            for(size_t i = 1; i < n -> knots.size(); i++)
            {
                scene -> addLine(n -> knots[i - 1] -> x, -(n -> knots[i - 1] -> y), n -> knots[i] -> x, -(n -> knots[i] -> y), pen);
            }
        }
        QVector<QPointF> temp = n -> getPoints();
        for(int i = 1; i < temp.size(); i++)//Qvector работает с int, а не t size. был Waring
        {
            scene -> addLine(QLineF(temp[i - 1], temp[i]), pen);
        }
    }
}

void SplineDisplay::scale()
{
    view->fitInView(scene->itemsBoundingRect(),Qt::KeepAspectRatio);
}
