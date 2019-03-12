#ifndef BACKEND_HPP
#define BACKEND_HPP
#include <QObject>
#include <QString>

class BackEnd :public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString words READ words WRITE setWords)
    Q_PROPERTY(bool isw READ isw WRITE setIsw)
    Q_PROPERTY(QString h READ h WRITE setH)
    Q_PROPERTY(QString t READ t WRITE setT)
    Q_PROPERTY(int n READ n WRITE setN)
    Q_PROPERTY(QString file READ file WRITE setFile)

    QString m_words;
    bool m_isw;

    QString m_h;

    QString m_t;

    int m_n;
    QString m_file;

public:
    explicit BackEnd  (QObject *parent = nullptr);

    QString words() const;
    bool isw()const;
    QString h()const;
    QString t()const;
    QString file()const;
    int n()const;
public slots:
    void setWords(QString words);
    void setIsw(bool isw);
    void setH(QString h);
    void setT(QString t);
    void setN(int n);
    void setFile(QString file);
};

#endif // BACKEND_HPP
