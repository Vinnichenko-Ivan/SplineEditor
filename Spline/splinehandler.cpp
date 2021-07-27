#include "splinehandler.h"

SplineHandler::SplineHandler()
{
    updateNames = false;
}

void SplineHandler::addSpline(QColor color, QString name, QString algorithm)
{
    if(algorithm == "liner")
    {
        Spline *buff = new Spline(color, name);
        splines.push_back(buff);
    }
    else if(algorithm ==  "Konchak - Bartles")
    {
        SplineKonchakBartles *buff = new SplineKonchakBartles(color, name);
        splines.push_back(buff);
    }

    updateNames = true;
}

QVector<QString> SplineHandler::getNames()
{
    QVector<QString> buff(splines.size());
    for(size_t i = 0; i < splines.size(); i++)
    {
        buff[i] = splines[i] -> name;
    }
    return buff;
}

bool SplineHandler::getCheckLineFlag(int index)
{
    return splines[index]->line;
}

void SplineHandler::setTestLine(int index, bool flag)
{
    splines[index]->line = flag;
}

void SplineHandler::deleteSpline(int index)
{
    splines.erase(splines.begin() + index);
}
