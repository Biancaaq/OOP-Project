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
    //destructor pur virtual; am scos cuvantul cheie virtual deoarece imi dadea warning ca este redundant
    ~CreatorContinut() override= 0;

    void adaugaContinut(ContinutAudio* continut);
    const std::vector<ContinutAudio*>& getContinutCreat() const;
    void afiseazaContinutCreat() const;
};

#endif