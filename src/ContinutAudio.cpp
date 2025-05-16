#include <iostream>
#include "ContinutAudio.hpp"

using namespace std;


ContinutAudio::ContinutAudio(int durata, string titlu, string gen) : durata(durata), titlu(titlu), gen(gen) {}

ContinutAudio::~ContinutAudio() {}

int ContinutAudio::getDurata() const {
    return durata;
}

string ContinutAudio::getTitlu() const {
    return titlu;
}

string ContinutAudio::getGen() const {
    return gen;
}