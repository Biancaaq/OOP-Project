#include "ContinutAudio.hpp"

using namespace std;


ContinutAudio::ContinutAudio(int durata, const string& titlu, const string& gen) : durata(durata), titlu(titlu), gen(gen) {}

ContinutAudio::~ContinutAudio() {}

int ContinutAudio::getDurata() const {
    return durata;
}

const string& ContinutAudio::getTitlu() const {
    return titlu;
}

const string& ContinutAudio::getGen() const {
    return gen;
}