#include <iostream>
#include "Utilizator.hpp"
#include "ContinutAudio.hpp"

using namespace std;


Utilizator::Utilizator(string nume, string email) : Profil(nume, email), CreatorContinut(), Ascultator() {}

Utilizator::~Utilizator() {
    for (auto* continut : continutCreat) {
        delete continut;
    }

    continutCreat.clear();
}
