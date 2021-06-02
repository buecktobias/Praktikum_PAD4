//
// Created by bueck on 01.06.2021.
//

#ifndef PRAKTIKUM_PAD4_TOKENSTREAM_H
#define PRAKTIKUM_PAD4_TOKENSTREAM_H


#include "Token.h"

class Token_stream {
public:
    Token get(); // Token aus std::cin erzeugen
    void putback(const Token &t) { // Trick: ein Token puffern
        if (full) error("Token buffer is already full");
        buffer = t;
        full = true;
    }

private:
    bool full; // Ist ein Token im Puffer?
    Token buffer; // Trick: Platz, um ein Token zu puffern
};


#endif //PRAKTIKUM_PAD4_TOKENSTREAM_H
