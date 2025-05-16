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
    explicit Podcast(int durata = 0, const std::string& titlu = "", const std::string& gen = "", int episod = 0, const std::string& gazda = "", const std::string& descriere = "");

    //getteri
    int getEpisod() const;
    const std::string& getGazda() const;
    const std::string& getDescriere() const;

    void afiseazaInfo() const override;
};

#endif