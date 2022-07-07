#pragma once


constexpr bool isWhiteSpace(char c) {
    return c == ' ' || c == '\t' || c == '\r';
}
constexpr bool isDigit(char c) {
    return '0' <= c && c <= '9';
}
constexpr bool isOperation(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}
enum class EnumCType {
    NONE,
    WHITESPACE,
    DIGIT,
    OPERATION,
    END,
};
constexpr EnumCType getType(char c) {
    if (c == '\n') return EnumCType::END;
    else if (isWhiteSpace(c)) return EnumCType::WHITESPACE;
    else if (isDigit(c)) return EnumCType::DIGIT;
    else if (isOperation(c)) return EnumCType::OPERATION;
    else return EnumCType::OPERATION;
}