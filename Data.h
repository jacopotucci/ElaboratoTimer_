//
// Created by jaxo on 28/09/21.
//

#ifndef ELABORATOTIMER__DATA_H
#define ELABORATOTIMER__DATA_H

#include <string>
#include <ctime>

class Data {
public:
    Data() = default;

    ~Data() = default;

    int getGiorni() const {
        return giorni;
    }

    void setGiorni(int giorni) {
        Data::giorni = giorni;
    }

    int getMesi() const {
        return mesi;
    }

    void setMesi(int mesi) {
        Data::mesi = mesi;
    }

    int getAnni() const {
        return anni;
    }

    void setAnni(int anni) {
        Data::anni = anni;
    }

    void setDataAttuale(); //imposta la data di oggi

    std::string dataToString(); //trasforma la data in una stringa da passare al display

private:
    int giorni, mesi, anni;

};


#endif //ELABORATOTIMER__DATA_H
