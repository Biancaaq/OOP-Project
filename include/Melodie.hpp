#ifndef MELODIE_HPP
#define MELODIE_HPP

#include <iostream>
#include <string>
#include "ContinutAudio.hpp"


class Melodie : public ContinutAudio {
    int anLansare;
    std::string numeArtist;
    std::string versuri;

    public:
    //constructor
    explicit Melodie(int durata = 0, const std::string& titlu = "", const std::string& gen = "", int anLansare = 0, const std::string& numeArtist = "");

    //getteri
    int getAnLansare() const;
    const std::string& getNumeArtist() const;

    void afiseazaInfo() const override;
};

#endif