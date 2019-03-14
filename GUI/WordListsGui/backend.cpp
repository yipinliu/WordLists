#include "backend.hpp"

#include "WordLists/IO.hpp" //WordLists file
#include "WordLists/algorithm.hpp" //WordLists file

#include <QDebug>
#include <QFile>

#include <list>
using namespace std;
const QString init_words = "Input the words...";
const QString init_h = "Input the head char";
const QString init_t = "Input the tail char";

BackEnd::BackEnd(QObject* parent):QObject (parent){
    reset();
}
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
void BackEnd::reset(){
    m_words = init_words;
    m_isw = true;
    m_h = init_h;
    m_t = init_t;
    m_n = 0;
    m_file = "";
    m_result = "Error Occur!";

    c_raw = nullptr;
    c_file = nullptr;
    c_h = '\0';
    c_t = '\0';

}
void BackEnd::doJob(){
    //printf("here");
    int type = convert();
    if(type != 0) {
        return;
    }
    if(c_file){
        char* tmp;
        int no = fileToStr(&c_file[8],&tmp);
        c_raw = tmp;
        qDebug()<<c_raw;
        qDebug()<<no;
        if(tmp == nullptr){
            return;
        }
    }
    qDebug()<<c_file;
    qDebug()<<c_raw;
    auto wordList = getWords(c_raw);
    list<list<Word*> > results;
    int result_num = 0;
    if(m_n != 0){
        result_num = RequiredNumber(wordList,c_h,c_t,m_n,results);
    }
    else if(m_isw){
        result_num = MostWords(wordList,c_h,c_t,results);
    }
    else {
        result_num = MostCharacters(wordList,c_h,c_t,results);
    }
    if(result_num < 0) return;
    m_result = "";
    m_result.append(QString::number(result_num) + "\n");
    bool needNewLine = m_n != 0 || m_isw;
    for(auto& e : results){
        m_result.append(to_str(e,needNewLine));
    }
    delete c_raw;
    c_raw = nullptr;
    if(c_file) delete c_file;
    c_file = nullptr;
    c_h = '\0';
    c_t = '\0';
    return ;

}
void BackEnd::svFile(){
    QFile output_file(m_path);
    if(!output_file.open(QIODevice::WriteOnly)){
        output_file.close();
    }
    else {
        output_file.write(m_result.toUtf8());
        output_file.close();
    }

}
void strToCharP(const string &str, char** raw){
    qDebug()<<str.length();
    int len = str.length()+1;
    *raw = new char[len];
    char *p = *raw;
    for(auto e: str){
        *p = e;
        p++;
    }
    *p = '\0';
}
int BackEnd::convert(){
    if(m_words == init_words||m_words == "")
        c_raw = nullptr;
    else{
        strToCharP(m_words.toStdString(),&c_raw);
    }
    qDebug()<<m_file;
    if(c_raw&&(m_file != "")) return -1;
    else if(m_file!= ""){
        strToCharP(m_file.toStdString(),&c_file);
    }
    else {
        c_file = nullptr;
    }
    if(m_h != init_h){
        qDebug() << m_h;
        c_h = m_h.toStdString()[0];
    }
    if(m_t != init_t){
        c_t = m_t.toStdString()[0];
    }
    return 0;
}
