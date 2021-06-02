//
// Created by bueck on 01.06.2021.
//

#include "Tokenstream.h"
#include "Token.h"
#include <iostream>
#include "error.h"

using namespace std;

Token Token_stream::get() {
    if (full) {
        full = false;
        return buffer;
    }
    char ch{};
    cin >> ch;
    switch (ch) {
        case ';': // Ende eines Rechenausdrucks
        case 'q': // Programmende
        case '?':
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
            return Token{ch}; // jedes Zeichen ist sein eigenes Token
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9': // Zahl als Token
        {
            cin.putback(ch); // std::cin hat auch einen Puffer
            double val{};
            cin >> val;
            return Token{val};
        }
        default:
            error("Token invalid");
    }
}