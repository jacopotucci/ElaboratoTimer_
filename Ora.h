//
// Created by jaxo on 28/09/21.
//

#ifndef ELABORATOTIMER__ORA_H
#define ELABORATOTIMER__ORA_H

#include <string>
#include <ctime>

class Ora {
public:
    explicit Ora(int s = 0, int m = 0, int o = 0) : secondi(s), minuti(m), ore(o) {}

    ~Ora() = default;

    int getSecondi() const {
        return secondi;
    }

    void setSecondi(int secondi) {
        Ora::secondi = secondi;
    }

    int getMinuti() const {
        return minuti;
    }

    void setMinuti(int minuti) {
        Ora::minuti = minuti;
    }

    int getOre() const {
        return ore;
    }

    void setOre(int ore) {
        Ora::ore = ore;
    }

    void setOraAttuale();

    std::string oraToString(); //trasforma l'ora in una stringa da passare al display

private:
    int secondi, minuti, ore;
};


#endif //ELABORATOTIMER__ORA_H
