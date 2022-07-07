#include "Tokenizer.h"

Tokenizer::Tokenizer(std::istream& input_stream): rd_(input_stream), token_(0) {}
Tokenizer::~Tokenizer() {}

void Tokenizer::startReading() {
    rd_.getChar();
}
int Tokenizer::getNumber() {
    int res = 0;
    while (rd_.getNextType() == EnumCType::DIGIT) {
        res *= 10;
        res += rd_.getChar() - '0';
    }
    return res;
}
void Tokenizer::makeToken() {
    rd_.flushWhiteSpace();

    if (rd_.getNextType() == EnumCType::END)
        token_ = Token('\n');
    else if (rd_.getNextType() == EnumCType::DIGIT)
        token_ = Token(this->getNumber());
    else if (rd_.getNextType() == EnumCType::OPERATION)
        token_ = Token(rd_.getChar());
    else token_ = Token(rd_.getChar());  // etc : (, ), ..
}


const Token& Tokenizer::getToken() const {
    return token_;
}