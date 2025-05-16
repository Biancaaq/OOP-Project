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
    //destructor pur virtual
    virtual ~Ascultator() = 0;

    void asculta(ContinutAudio* continut);
    std::vector<ContinutAudio*> getIstoricAscultari() const;
    void afiseazaIstoricAscultari() const;
};

#endif