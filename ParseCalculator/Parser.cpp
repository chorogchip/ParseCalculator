#include "Parser.h"

Parser::Parser(std::istream& input_stream, std::ostream& output_stream):
    rd_(input_stream), ostr_(output_stream), token_(0) {
}
Parser::~Parser() {}

int Parser::getNumber() {
    int res = 0;
    while (rd_.getNextType() == EnumCType::DIGIT) {
        res *= 10;
        res += rd_.getChar() - '0';
    } 
    return res;
}
void Parser::getToken() {
    rd_.flushWhiteSpace();

    if (rd_.getNextType() == EnumCType::END)
        token_ = Token('\n');
    else if (rd_.getNextType() == EnumCType::DIGIT)
        token_ = Token(this->getNumber());
    else if (rd_.getNextType() == EnumCType::OPERATION)
        token_ = Token(rd_.getChar());
    else token_ = Token(rd_.getChar());  // etc : (, ), ..
}
int Parser::expr() {
    int res = term();
    while (token_ == Token('+')) {
        getToken();
        res += term();
    }
    return res;
}
int Parser::term() {
    int res = factor();
    while (token_ == Token('*')) {
        getToken();
        res *= factor();
    }
    return res;
}
int Parser::factor() {
    int res = 0;
    if (token_ == Token('(')) {
        getToken();
        res = expr();
        getToken();  // ')'
    } else if (token_.type == EnumTokenType::NUMBER) {
        res = token_.val;
        getToken();
    }
    return res;
}

void Parser::parse() {
    rd_.getChar();
    getToken();
    int res = expr();
    ostr_ << ">> " << res << std::endl;
}