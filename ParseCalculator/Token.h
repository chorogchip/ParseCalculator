#pragma once
enum class EnumTokenType {
    NUMBER,
    OPERATION,
};
struct Token {
    int val;
    EnumTokenType type;
    Token(int value): val(value), type(EnumTokenType::NUMBER) {}
    Token(char op): val(op), type(EnumTokenType::OPERATION) {}
    Token(const Token& t): val(t.val), type(t.type) {}
    bool operator==(const Token& t) const {
        return type == t.type && val == t.val;
    }
};

