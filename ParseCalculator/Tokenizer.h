#pragma once
#include<iostream>
#include"Utils.h"
#include"Token.h"
#include"Reader.h"

class Tokenizer {
private:
    Reader rd_;
    Token token_;

    int getNumber();

public:
    Tokenizer(std::istream& input_stream);
    ~Tokenizer();

    void startReading();
    void makeToken();
    const Token& getToken() const;
};

