#include "backend.hpp"
BackEnd::BackEnd(QObject* parent):QObject (parent){}
QString BackEnd::words() const
{
    return m_words;
}
bool BackEnd::isw()const{
    return m_isw;
}
QString BackEnd::h()const{
    return m_h;
}
QString BackEnd::t()const{
    return m_t;
}
QString BackEnd::file()const{
    return m_file;
}
int BackEnd::n()const{
    return m_n;
}
void BackEnd::setWords(QString words)
{
    m_words = words;
}
void BackEnd::setIsw(bool isw)
{
    m_isw = isw;
}
void BackEnd::setH(QString h)
{
    m_h = h;
}
void BackEnd::setT(QString t)
{
    m_t = t;
}
void BackEnd::setN(int n)
{
    m_n = n;
}
void BackEnd::setFile(QString file){
    m_file = file;
}
