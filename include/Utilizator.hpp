#ifndef UTILIZATOR_HPP
#define UTILIZATOR_HPP

#include <iostream>
#include <string>
#include "CreatorContinut.hpp"
#include "Ascultator.hpp"


class Aplicatie;

class Utilizator : public CreatorContinut, public Ascultator {
    Aplicatie *aplicatie = nullptr;

    public:
    //constructor
    explicit Utilizator(const std::string& nume = "", const std::string& email = "");

    //destructor
    ~Utilizator() override;

    void setAplicatie(Aplicatie* a);

    void adaugaContinut(ContinutAudio* continut) override;
};

#endif