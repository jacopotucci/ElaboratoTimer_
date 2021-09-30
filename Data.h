//
// Created by jaxo on 28/09/21.
//

#ifndef ELABORATOTIMER__DATA_H
#define ELABORATOTIMER__DATA_H

#include <string>
#include <ctime>

class Data {
public:
    explicit Data(int g = 0, int m = 0, int a = 0, int v = 0) : giorni(g), mesi(m), anni(a), visualizzazione(v) {}

    ~Data() = default;

    int getGiorni() const {
        return giorni;
    }

    void setGiorni(int g) {
        Data::giorni = g;
    }

    int getMesi() const {
        return mesi;
    }

    void setMesi(int m) {
        Data::mesi = m;
    }

    int getAnni() const {
        return anni;
    }

    void setAnni(int a) {
        Data::anni = a;
    }

    void setDataAttuale(); //imposta la data di oggi

    std::string dataToString() const; //trasforma la data in una stringa da passare al display

private:
    int giorni, mesi, anni, visualizzazione;

};


#endif //ELABORATOTIMER__DATA_H
