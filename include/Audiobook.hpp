#ifndef AUDIOBOOK_HPP
#define AUDIOBOOK_HPP

#include <iostream>
#include <string>
#include "ContinutAudio.hpp"


class Audiobook : public ContinutAudio {
    std::string autor;
    std::string narator;
    std::string titluCarte;

    public:
    //constructor
    Audiobook(int durata = 0, std::string titlu = "", std::string gen = "", std::string autor = "", std::string narator = "", std::string titluCarte = "");

    //getteri
    std::string getAutor() const;
    std::string getNarator() const;
    std::string getTitluCarte() const;

    void afiseazaInfo() const override;
};

#endif