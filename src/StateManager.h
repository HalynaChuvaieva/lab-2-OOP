#pragma once
#include <QString>
#include <QJsonObject>

class StateManager
{
public:
    static QJsonObject packDemo(const QString &alg, const std::vector<int> &data, int step)
    {
        QJsonObject o;
        o["alg"] = alg;
        QJsonArray a;
        for (int v : data)
            a.append(v);
        o["data"] = a;
        o["step"] = step;
        return o;
    }
};