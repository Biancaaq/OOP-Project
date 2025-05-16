#ifndef CREATORCONTINUT_HPP
#define CREATORCONTINUT_HPP

#include <vector>
#include "Profil.hpp"


class ContinutAudio;

class CreatorContinut : virtual public Profil {
    protected:
    std::vector<ContinutAudio*> continutCreat;

    public:
    //destructor pur virtual; am scos cuvantul cheie virtual deoarece imi dadea warning ca este redundant
    ~CreatorContinut() override= 0;

    const std::vector<ContinutAudio*>& getContinutCreat() const;

    virtual void adaugaContinut(ContinutAudio* continut);
    void afiseazaContinutCreat() const;
};

#endif