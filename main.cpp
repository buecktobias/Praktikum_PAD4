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
        if (tok.getKind() == ';') continue;
        if (tok.getKind() == 'q') break;
        if (tok.getKind() == '?'){
            cout << "Gebe eine Rechnung ein! Du kannst die Operatoren +,-,*,/ und Klammern verwenden"<<
            endl << "Geben Sie ; ein um die Rechnung zu beenden, zum Beenden des Programms q eingeben!";
            continue;
        }
        ts.putback(tok);
        cout << "= " << expression(ts) << endl;
    }
    return 0;
} catch (const std::exception& e) {
    cout << "error!!!";
}