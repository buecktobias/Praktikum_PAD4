//
// Created by bueck on 01.06.2021.
//

#ifndef PRAKTIKUM_PAD4_TOKEN_H
#define PRAKTIKUM_PAD4_TOKEN_H
#include <iostream>
using namespace std;

class Token // Benutzerdefinierter Typ namens Token.
{
public: // Die folgenden Teile sind direkt zugreifbar.
    char kind; // Tokensymbol, '9' soll fuer Zahl stehen.
    double value; // Wert (nur fuer Zahl-Token).
    void print() const {
        if( kind == '9' ) cout << value << endl;
        else cout << kind << endl;
    }
// Konstruktor, erstelle ein Token aus einem char:
    Token( const char& ch ) : kind{ch}, value{0.0} { /* mache nichts sonst */ }
// Konstruktor, erstelle ein Zahl-Token aus einem double:
    Token( const double& d ) : kind{'9'}, value{d} { /* mache nichts sonst */ }
// Standardkonstruktor, erstelle "das Standardtoken" ohne Vorgabe:
    Token( ) : Token{0.0} { /* mache nichts sonst */ }
};


#endif //PRAKTIKUM_PAD4_TOKEN_H
