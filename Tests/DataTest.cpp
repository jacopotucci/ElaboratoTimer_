//
// Created by jaxo on 28/09/21.
//

#include <gtest/gtest.h>
#include "../Data.h"

TEST(Data, CostruttoreData){
    Data data(10, 10, 2010);
    ASSERT_EQ(10, data.getGiorni());
    ASSERT_EQ(10, data.getMesi());
    ASSERT_EQ(2010, data.getAnni());
}

TEST(Data, CostruttoreDefaultData){
Data data;
ASSERT_EQ(10, data.getGiorni());
ASSERT_EQ(10, data.getMesi());
ASSERT_EQ(2010, data.getAnni());
}

TEST(Data, CostruttoreDataFebbraioBisestile){
    Data data(29, 2, 2000);
    ASSERT_EQ(29, data.getGiorni());
    ASSERT_EQ(2, data.getMesi());
    ASSERT_EQ(2000, data.getAnni());
}

TEST(Data, setGiorno){
    Data data(10, 10, 2010);
    data.setGiorni(31);
    ASSERT_EQ(31, data.getGiorni());
}

TEST(Data, setMese){
    Data data(10, 10, 2010);
    data.setMesi(12);
    ASSERT_EQ(12, data.getMesi());
}

TEST(Data, setAnno){
    Data data(10, 10, 2010);
    data.setAnni(2000);
    ASSERT_EQ(2000, data.getAnni());
}

TEST(Data, setAnnoBisestile){
    Data data(29, 2, 2000);
    data.setAnni(2016);
    ASSERT_EQ(2016, data.getAnni());
}

TEST(Data, eccezioniCostruttoreGiorni){
    ASSERT_THROW(Data data(32, 10, 2010), std::out_of_range);
}

TEST(Data, eccezioniCostruttoreMesi){
    ASSERT_THROW(Data data(10, 13, 2010), std::out_of_range);
}

TEST(Data, eccezioniCostruttoreAnni){
    ASSERT_THROW(Data data(10, 10, -1), std::out_of_range);
}

TEST(Data, eccezioniCostruttoreFebbraioBisestile){
    ASSERT_THROW(Data data(30, 2, 2000), std::out_of_range);
}

TEST(Data, eccezioniCostruttoreFebbraio){
    ASSERT_THROW(Data data(29, 2, 2001), std::out_of_range);
}

TEST(Data, eccezioneSetGiorni){
    Data data(10, 10, 2010);
    ASSERT_THROW(data.setGiorni(32), std::out_of_range);
}

TEST(Data, eccezioneSetMesi){
    Data data(10, 10, 2010);
    ASSERT_THROW(data.setMesi(13), std::out_of_range);
}

TEST(Data, eccezioneSetMesiConControlloGiorni){
    Data data(30, 10, 2010);
    ASSERT_THROW(data.setMesi(2), std::out_of_range); //mese con 28 giorni
}

TEST(Data, eccezioneSetAnni){
    Data data(10, 10, 2010);
    ASSERT_THROW(data.setAnni(-1), std::out_of_range);
}

TEST(Data, eccezioneSetAnniConControlloGiorni){
    Data data(29, 02, 2016); //anno bisestile
    ASSERT_THROW(data.setAnni(2015), std::out_of_range); //anno non bisestile
}

TEST(Data, setDataAttuale){
    std::time_t t = std::time(nullptr);
    std::tm *now = std::localtime(&t);
    Data data;
    data.setDataAttuale();
    ASSERT_EQ(now->tm_mday, data.getGiorni());
    ASSERT_EQ(now->tm_mon + 1, data.getMesi());
    ASSERT_EQ(now->tm_year + 1900, data.getAnni());
}

TEST(Data, dataToString){
    Data data;
    ASSERT_EQ("10 / 10 / 2010", data.toString());
    data.setVisualizzazione(2);
    ASSERT_EQ("10.10.2010", data.toString());
}