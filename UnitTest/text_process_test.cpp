#include "gtest/gtest.h"
#include "interface.hpp"
#include <iostream>
#include <fstream>
using namespace std;


TEST(text_process,nullptr_exception){
    try{
        char *p = nullptr;
        p = text_process(nullptr);
    }
    catch(const invalid_argument &e){
        cout<<e.what()<<endl;
        return;
    }
    FAIL();
}
TEST(text_process,non_file_exception){
    try{
        char *p = nullptr;
        p = text_process("not_exist_file*.txt");
    }
    catch(const invalid_argument &e){
        cout<<e.what()<<endl;
        return;
    }
    FAIL();
}
TEST(text_process, empty_file){
    try{
        char* file = "test_file.txt";
        ofstream of(file);
        of.close();
        char *p = nullptr;
        p = text_process(file);
    }
    catch(const invalid_argument &e){
        cout<<e.what()<<endl;
        return;
    }
    FAIL();
}