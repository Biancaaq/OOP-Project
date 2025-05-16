#ifndef Ascultator_HPP
#define Ascultator_HPP

#include <iostream>
#include <vector>
#include "Profil.hpp"


class ContinutAudio;

class Ascultator : virtual public Profil {
    protected:
    std::vector<ContinutAudio*> istoricAscultari;

    public:
    //destructor pur virtual; fara cuvantul cheie virtual deoarece primeam warning de redundanta
    ~Ascultator() override = 0;

    void asculta(ContinutAudio* continut);
    const std::vector<ContinutAudio*>& getIstoricAscultari() const;
    void afiseazaIstoricAscultari() const;
};

#endif