#include <iostream>
#include "Ascultator.hpp"
#include "ContinutAudio.hpp"

using namespace std;


Ascultator::Ascultator(string nume, string email) : Profil(nume, email){}

Ascultator::~Ascultator() {}

void Ascultator::asculta(ContinutAudio* continut) {
    if (continut != nullptr) {
        istoricAscultari.push_back(continut);
    }
}

vector<ContinutAudio*> Ascultator::getIstoricAscultari() const {
    return istoricAscultari;
}

void Ascultator::afiseazaIstoricAscultari() const {
    cout << "Istoricul ascultarilor pentru " << nume << ": " << endl;

    if (istoricAscultari.empty()) {
        cout << nume << " nu a ascultat nimic momentan!";
    }

    else {
        for (auto* c : istoricAscultari) {
            if (c) {
                c->afiseazaInfo();
            }
        }
    }
}
