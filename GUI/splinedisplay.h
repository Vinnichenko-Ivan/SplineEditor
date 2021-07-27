#ifndef SPLINEDISPLAY_H
#define SPLINEDISPLAY_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGridLayout>
#include <QTimer>
#include <QLineF>
#include <Spline/splinehandler.h>


class SplineDisplay : public QWidget
{
    Q_OBJECT
private:
    SplineHandler* handler;
public:
    explicit SplineDisplay(SplineHandler* handlerIn, QWidget *parent = nullptr);
    QGraphicsScene *scene;
    QGridLayout *layout;
    QGraphicsView *view;
    QTimer *updater;

signals:

private slots:
    void repaint();
};

#endif // SPLINEDISPLAY_H
