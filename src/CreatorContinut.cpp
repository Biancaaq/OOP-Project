#include <iostream>
#include "CreatorContinut.hpp"
#include "ContinutAudio.hpp"

using namespace std;


CreatorContinut::~CreatorContinut() {}

void CreatorContinut::adaugaContinut(ContinutAudio* continut) {
    if (continut != nullptr) {
        continutCreat.push_back(continut);
    }
}

const vector<ContinutAudio*>& CreatorContinut::getContinutCreat() const {
    return continutCreat;
}

void CreatorContinut::afiseazaContinutCreat() const {
    cout << nume << " a creat: " << endl;

    if (continutCreat.empty()) {
        cout << "Nu s-a gasit niciun continut creat de utilizatorul " << nume << ".";
    }

    else {
        for (const auto* c : continutCreat) {
            if (c) {
                c->afiseazaInfo();
            }
        }
    }
}