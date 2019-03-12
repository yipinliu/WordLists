#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "backend.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    app.setOrganizationName("Software Enginner Group");
    app.setOrganizationDomain("http://localhost:8080");
    app.setApplicationName("Amazing Application");

    qmlRegisterType<BackEnd>("libbackend",1,0,"BackEnd");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    engine.rootContext()->setContextProperty("dirPath",QGuiApplication::applicationDirPath());
    return app.exec();
}
