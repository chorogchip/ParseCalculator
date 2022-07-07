#include "Reader.h"

Reader::Reader(std::istream& input_stream): istr_(input_stream), c_('\0') {}
Reader::~Reader() {}

char Reader::getChar() {
    char c = c_;
    istr_.read(&c_, 1);
    return c;
}
EnumCType Reader::getNextType() {
    return getType(c_);
}
void Reader::flushWhiteSpace() {
    while (this->getNextType() == EnumCType::WHITESPACE)
        this->getChar();
}