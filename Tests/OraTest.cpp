//
// Created by jaxo on 15/10/21.
//

#include <gtest/gtest.h>
#include "../Ora.h"

TEST(Ora, CostruttoreOra){
    Ora ora(10, 10, 10);
    ASSERT_EQ(10, ora.getSecondi());
    ASSERT_EQ(10, ora.getMinuti());
    ASSERT_EQ(10, ora.getOre());
}

TEST(Ora, CostruttoreDefaultOra){
    Ora ora;
    ASSERT_EQ(10, ora.getSecondi());
    ASSERT_EQ(10, ora.getMinuti());
    ASSERT_EQ(10, ora.getOre());
}

TEST(Ora, setSecondi){
    Ora ora(10, 10, 10);
    ora.setSecondi(60);
    ASSERT_EQ(60, ora.getSecondi());
}

TEST(Ora, setMinuti){
    Ora ora(10, 10, 10);
    ora.setMinuti(60);
    ASSERT_EQ(60, ora.getMinuti());
}

TEST(Ora, setOre){
    Ora ora(10, 10, 10);
    ora.setOre(24);
    ASSERT_EQ(24, ora.getOre());
}

TEST(Ora, eccezioniCostruttoreSecondi){
    ASSERT_THROW(Ora ora(61, 10, 10), std::out_of_range);
}

TEST(Ora, eccezioniCostruttoreMinuti){
    ASSERT_THROW(Ora ora(10, 61, 10), std::out_of_range);
}

TEST(Ora, eccezioniCostruttoreOre){
    ASSERT_THROW(Ora ora(10, 10, 25), std::out_of_range);
}

TEST(Ora, eccezioneSetSecondi){
    Ora ora(10, 10, 10);
    ASSERT_THROW(ora.setSecondi(61), std::out_of_range);
}

TEST(Ora, eccezioneSetMinuti){
    Ora ora(10, 10, 10);
    ASSERT_THROW(ora.setMinuti(61), std::out_of_range);
}

TEST(Ora, eccezioneSetOre){
    Ora ora(10, 10, 10);
    ASSERT_THROW(ora.setOre(25), std::out_of_range);
}

TEST(Ora, setOraAttuale){
    std::time_t t = std::time(nullptr);
    std::tm *now = std::localtime(&t);
    Ora ora;
    ora.setOraAttuale();
    ASSERT_EQ(now->tm_sec, ora.getSecondi());
    ASSERT_EQ(now->tm_min, ora.getMinuti());
    ASSERT_EQ(now->tm_hour, ora.getOre());
}

TEST(Ora, OraToString){
    Ora ora;
    ASSERT_EQ("10.10", ora.toString());
    ora.setVisualizzazione(1);
    ASSERT_EQ("10:10:10", ora.toString());
    ora.setVisualizzazione(2);
    ASSERT_EQ("10 ore 10 min 10 sec", ora.toString());
}