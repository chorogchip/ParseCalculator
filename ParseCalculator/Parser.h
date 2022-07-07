#pragma once
#include<iostream>
#include"Utils.h"
#include"Token.h"
#include"Reader.h"


class Parser {
private:
    Reader rd_;
    std::ostream& ostr_;
    Token token_;

    int getNumber();
    void getToken();
    int expr();
    int term();
    int factor();
    
public:
    Parser(std::istream& input_stream, std::ostream& output_stream);
    ~Parser();
    void parse();
};

