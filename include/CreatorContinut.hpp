#ifndef CREATORCONTINUT_HPP
#define CREATORCONTINUT_HPP

#include <iostream>
#include <vector>
#include "Profil.hpp"


class ContinutAudio;

class CreatorContinut : virtual public Profil {
    protected:
    std::vector<ContinutAudio*> continutCreat;

    public:
    //constructor
    CreatorContinut(std::string nume = "", std::string email = "");

    //destructor pur virtual
    virtual ~CreatorContinut() = 0;

    void adaugaContinut(ContinutAudio* continut);
    std::vector<ContinutAudio*> getContinutCreat() const;
    void afiseazaContinutCreat() const;
};

#endif