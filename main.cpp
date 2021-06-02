#include "Token.h"
#include "Tokenstream.h"
#include "error.h"
#include "helper_functions.h"
#include <stdexcept>

int main() try {
    Token tok{};
    Token_stream ts{}; // Standardkonstruktor?!
    while (cin) {
        cout << "> "; // Prompt
        tok = ts.get();
        if (tok.kind == ';') continue;
        if (tok.kind == 'q') break;
        ts.putback(tok);
        cout << "= " << expression(ts) << endl;
    }
    return 0;
} catch (const std::exception& e) {
    cout << "error!!!";
}