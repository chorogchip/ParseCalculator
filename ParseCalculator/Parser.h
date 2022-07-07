#pragma once
#include<iostream>
#include"Utils.h"
#include"Token.h"
#include"Tokenizer.h"


class Parser {
private:
    Tokenizer tk_;
    std::ostream& ostr_;

    int expr();
    int term();
    int factor();
    
public:
    Parser(std::istream& input_stream, std::ostream& output_stream);
    ~Parser();

    void parse();
};

