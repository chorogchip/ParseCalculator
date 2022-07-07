#pragma once
#include<iostream>
#include"Utils.h"

class Reader {
private:
    std::istream& istr_;
    char c_;
public:
    Reader(std::istream& input_stream);
    ~Reader();
    char getChar();
    EnumCType getNextType();
    void flushWhiteSpace();
};

