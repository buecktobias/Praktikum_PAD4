//
// Created by bueck on 02.06.2021.
//

#include "helper_functions.h"
#include "error.h"

double term(Token_stream &ts) // "mal" und "geteilt durch" behandeln
{
    double d2{primary(ts)};
    Token t2{};
    while (true) {
        t2 = ts.get();
        switch (t2.getKind()) {
            case '*':
                d2 *= primary(ts);
                break;
            case '/': {
                double divisor{primary(ts)};
                if (divisor == 0) error("Division durch 0");
                d2 /= divisor;
                break;
            }
            default:
                ts.putback(t2);
                return d2;
        }
    }
}

double expression(Token_stream &ts) // "plus" und "minus" behandeln
{
    double d1{term(ts)};
    Token t1{};
    while (true) {
        t1 = ts.get();
        switch (t1.getKind()) {
            case '+':
                d1 += term(ts);
                break;
            case '-':
                d1 -= term(ts);
                break;
            default:
                ts.putback(t1);
                return d1;
        }
    }
}
double primary(Token_stream &ts) // Zahlen und Klammern behandeln
{
    Token t3{ts.get()};
    switch (t3.getKind()) {
        case '-':
            return - primary(ts);
        case '+':
            return primary(ts);
        case '9':
            return t3.getValue();
        case '(': {
            double d3{expression(ts)};
            if (ts.get().getKind() != ')') error("keine rechte Klammer");
            return d3;
        }
        default:
            error("kein Primary");
            return -1;
    }
}