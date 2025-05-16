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
    explicit Audiobook(int durata = 0, const std::string& titlu = "", const std::string& gen = "", const std::string& autor = "", const std::string& narator = "", const std::string& titluCarte = "");

    //getteri
    const std::string& getAutor() const;
    const std::string& getNarator() const;
    const std::string& getTitluCarte() const;

    void afiseazaInfo() const override;
};

#endif