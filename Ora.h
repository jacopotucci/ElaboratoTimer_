//
// Created by jaxo on 28/09/21.
//

#ifndef ELABORATOTIMER__ORA_H
#define ELABORATOTIMER__ORA_H

#include <string>
#include <ctime>

class Ora {
public:
    explicit Ora(int s = 0, int m = 0, int o = 0, int v = 0) : secondi(s), minuti(m), ore(o), visualizzazione(v) {}

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

    void setVisualizzazione(int visualizzazione) {
        Ora::visualizzazione = visualizzazione;
    }

    void setOraAttuale();

    std::string oraToString() const; //trasforma l'ora in una stringa da passare al display

    int turnToSecond();

private:
    int secondi, minuti, ore, visualizzazione;
};


#endif //ELABORATOTIMER__ORA_H
