#include <iostream>
#include "CreatorContinut.hpp"
#include "ContinutAudio.hpp"

using namespace std;


CreatorContinut::CreatorContinut(string nume, string email) : Profil(nume, email) {}

CreatorContinut::~CreatorContinut() {}

void CreatorContinut::adaugaContinut(ContinutAudio* continut) {
    if (continut != nullptr) {
        continutCreat.push_back(continut);
    }
}

vector<ContinutAudio*> CreatorContinut::getContinutCreat() const {
    return continutCreat;
}

void CreatorContinut::afiseazaContinutCreat() const {
    cout << nume << " a creat: " << endl;

    if (continutCreat.empty()) {
        cout << "Nu s-a gasit niciun continut creat de utilizatorul " << nume << ".";
    }

    else {
        for (auto* c : continutCreat) {
            if (c) {
                c->afiseazaInfo();
            }
        }
    }
}