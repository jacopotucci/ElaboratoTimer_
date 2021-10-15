//
// Created by jaxo on 28/09/21.
//

#ifndef ELABORATOTIMER__ORA_H
#define ELABORATOTIMER__ORA_H

#include <string>
#include <ctime>
#include <stdexcept>

class Ora {
public:
    explicit Ora(int s = 10, int m = 10, int o = 10, int v = 0);

    ~Ora() = default;

    int getSecondi() const;

    int getMinuti() const;

    int getOre() const;

    void setSecondi(int secondi);

    void setMinuti(int minuti);

    void setOre(int ore);

    void setVisualizzazione(int v);

    void setOraAttuale();

    std::string oraToString() const; //trasforma l'ora in una stringa da passare al display

    int turnToSecond();

private:
    int secondi, minuti, ore, visualizzazione;
};


#endif //ELABORATOTIMER__ORA_H
