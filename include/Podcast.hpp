#ifndef PODCAST_HPP
#define PODCAST_HPP

#include <iostream>
#include <string>
#include "ContinutAudio.hpp"


class Podcast : public ContinutAudio {
    int episod;
    std::string gazda;
    std::string descriere;

    public:
    //constructor
    Podcast(int durata = 0, std::string titlu = "", std::string gen = "", int episod = 0, std::string gazda = "", std::string descriere = "");

    //getteri
    int getEpisod() const;
    std::string getGazda() const;
    std::string getDescriere() const;

    void afiseazaInfo() const override;
};

#endif