#include "datamodeltest.h"

#include <datamodel.h>
#include <QDebug>
#include <QEventLoop>
#include <QtTest>

DataModelTest::DataModelTest(QObject *parent) : QObject(parent)
{

}

void DataModelTest::test_info()
{
    QEventLoop loop;

    DataModel model;
    connect(&model, &DataModel::populated, &loop, &QEventLoop::quit);
    model.populate(":/xml/DVC02339 - 0_00_00_07.dv.xml");

    loop.exec();

    auto frame = -1;
    auto oddValue = -0.0f;
    auto evenValue = -0.0f;

    model.getVideoInfo(89517, 0, frame, oddValue, evenValue);
    qDebug() << "closest frame: " << frame;
    QCOMPARE(frame, 89500);

    model.getVideoInfo(189500, 0, frame, oddValue, evenValue);
    qDebug() << "closest frame: " << frame;
    QCOMPARE(frame, 89500);

    model.getVideoInfo(89500, 0, frame, oddValue, evenValue);
    qDebug() << "closest frame: " << frame;
    QCOMPARE(frame, 89500);

    model.getVideoInfo(89499, 0, frame, oddValue, evenValue);
    qDebug() << "closest frame: " << frame;
    QCOMPARE(frame, 89499);

    model.getVideoInfo(89491, 0, frame, oddValue, evenValue);
    qDebug() << "closest frame: " << frame;
    QCOMPARE(frame, 89491);

    model.getVideoInfo(89490, 0, frame, oddValue, evenValue);
    qDebug() << "closest frame: " << frame;
    QCOMPARE(frame, 89491);

    model.getVideoInfo(89429, 0, frame, oddValue, evenValue);
    qDebug() << "closest frame: " << frame;
    QCOMPARE(frame, 89424);
}
