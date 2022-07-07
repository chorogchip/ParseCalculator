#include "Parser.h"

Parser::Parser(std::istream& input_stream, std::ostream& output_stream):
    tk_(input_stream), ostr_(output_stream) {
}
Parser::~Parser() {}

int Parser::expr() {
    int res = term();
    while (true)
        if (tk_.getToken() == Token('+')) {
            tk_.makeToken();
            res += term();
        } else if (tk_.getToken() == Token('-')) {
            tk_.makeToken();
            res -= term();
        } else break;
    return res;
}
int Parser::term() {
    int res = factor();
    while (true)
        if (tk_.getToken() == Token('*')) {
            tk_.makeToken();
            res *= factor();
        } else if (tk_.getToken() == Token('/')) {
            tk_.makeToken();
            res /= factor();
        } else if (tk_.getToken() == Token('%')) {
            tk_.makeToken();
            res %= factor();
        } else break;
    return res;
}
int Parser::factor() {
    int res = 0;
    if (tk_.getToken() == Token('(')) {
        tk_.makeToken();
        res = expr();
        tk_.makeToken();  // ')'
    } else if (tk_.getToken().type == EnumTokenType::NUMBER) {
        res = tk_.getToken().val;
        tk_.makeToken();
    }
    return res;
}

void Parser::parse() {
    tk_.startReading();
    tk_.makeToken();
    int res = expr();
    ostr_ << ">> " << res << std::endl;
}