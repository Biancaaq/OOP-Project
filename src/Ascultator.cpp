#include <iostream>
#include <memory>
#include "Ascultator.hpp"
#include "ContinutAudio.hpp"

using namespace std;


Ascultator::~Ascultator() {}

void Ascultator::asculta(shared_ptr<ContinutAudio> continut) {
    if (continut != nullptr) {
        istoricAscultari.push_back(continut);
    }
}

const vector<shared_ptr<ContinutAudio>>& Ascultator::getIstoricAscultari() const {
    return istoricAscultari;
}

void Ascultator::afiseazaIstoricAscultari() const {
    cout << "Istoricul ascultarilor pentru " << nume << ": " << endl;

    if (istoricAscultari.empty()) {
        cout << nume << " nu a ascultat nimic momentan!";
    }

    else {
        for (const auto& c : istoricAscultari) {
            if (c) {
                c->afiseazaInfo();
            }
        }
    }
}

void Ascultator::adaugaMelodieFavorita(ContinutAudio* m) {
    melodiiFavorite.push_back(m);
}

void Ascultator::adaugaPodcastFavorit(ContinutAudio* p) {
    podcasturiFavorite.push_back(p);
}

void Ascultator::adaugaAudiobookFavorit(ContinutAudio* a) {
    audiobookuriFavorite.push_back(a);
}

void Ascultator::afiseazaFavorite() const {
    cout << "Melodii favorite:" << endl;
    for (size_t i = 0; i < melodiiFavorite.size(); ++i) {
        cout << i << ". ";
        melodiiFavorite[i]->afiseazaInfo();
    }

    cout << endl;
    cout << "Podcasturi favorite:" << endl;
    for (size_t i = 0; i < podcasturiFavorite.size(); ++i) {
        cout << i << ". ";
        podcasturiFavorite[i]->afiseazaInfo();
    }

    cout << endl;
    cout << "Audiobookuri favorite:" << endl;
    for (size_t i = 0; i < audiobookuriFavorite.size(); ++i) {
        cout << i << ". ";
        audiobookuriFavorite[i]->afiseazaInfo();
    }
}

void Ascultator::stergeFavorit(int tip, size_t index) {
    switch (tip) {
        case 1: {
            if (index < melodiiFavorite.size()) {
                melodiiFavorite.erase(melodiiFavorite.begin() + index);
            }

            break;
        }

        case 2: {
            if (index < podcasturiFavorite.size()) {
                podcasturiFavorite.erase(podcasturiFavorite.begin() + index);
            }

            break;
        }

        case 3: {
            if (index < audiobookuriFavorite.size()) {
                audiobookuriFavorite.erase(audiobookuriFavorite.begin() + index);
            }

            break;
        }
    }
}