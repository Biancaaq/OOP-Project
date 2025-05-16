#ifndef UTILIZATOR_HPP
#define UTILIZATOR_HPP

#include <iostream>
#include "CreatorContinut.hpp"
#include "Ascultator.hpp"


class Utilizator : public CreatorContinut, public Ascultator {
    public:
    //constructor
    Utilizator(std::string nume = "", std::string email = "");

    //destructor
    ~Utilizator();
};

#endif