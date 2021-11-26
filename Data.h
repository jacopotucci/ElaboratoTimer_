//
// Created by jaxo on 28/09/21.
//

#ifndef ELABORATOTIMER__DATA_H
#define ELABORATOTIMER__DATA_H

#include <string>
#include <ctime>
#include <stdexcept>

class Data {
public:
    explicit Data(int g = 10, int m = 10, int a = 2010, int v = 0);

    ~Data() = default;

    int getGiorni() const;

    int getMesi() const;

    int getAnni() const;

    int getVisualizazzione() const;

    void setGiorni(int g);

    void setMesi(int m);

    void setAnni(int a);

    void setVisualizzazione(int v);

    void setDataAttuale(); //imposta la data di oggi

    std::string giornoEMeseAttualeToString() const;

    std::string dataToString() const; //trasforma la data in una stringa da passare al display

private:
    int giorni, mesi, anni, visualizzazione;

    void controlloGiorno(int g = 10);

};


#endif //ELABORATOTIMER__DATA_H
