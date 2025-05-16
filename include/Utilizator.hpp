#ifndef UTILIZATOR_HPP
#define UTILIZATOR_HPP

#include <iostream>
#include "CreatorContinut.hpp"
#include "Ascultator.hpp"


class Utilizator : public CreatorContinut, public Ascultator {
    public:
    //constructor
    explicit Utilizator(const std::string& nume = "", const std::string& email = "");

    //destructor
    ~Utilizator() override;
};

#endif