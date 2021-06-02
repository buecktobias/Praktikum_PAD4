//
// Created by bueck on 02.06.2021.
//

#ifndef PRAKTIKUM_PAD4_HELPER_FUNCTIONS_H
#define PRAKTIKUM_PAD4_HELPER_FUNCTIONS_H
#include "Tokenstream.h"
#include "Token.h"
double term(Token_stream &ts);
double expression(Token_stream &ts); // "plus" und "minus" behandeln
double primary(Token_stream &ts); // Zahlen und Klammern behandeln

#endif //PRAKTIKUM_PAD4_HELPER_FUNCTIONS_H
