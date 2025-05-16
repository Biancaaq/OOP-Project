#include "Utilizator.hpp"
#include "Aplicatie.hpp"
#include "Melodie.hpp"
#include "Podcast.hpp"
#include "Audiobook.hpp"

using namespace std;


Utilizator::Utilizator(const string& nume, const string& email) : Profil(nume, email), CreatorContinut(), Ascultator() {}

Utilizator::~Utilizator() {
    continutCreat.clear();
}

void Utilizator::setAplicatie(Aplicatie* a) {
    aplicatie = a;
}

void Utilizator::adaugaContinut(ContinutAudio* continut) {
    CreatorContinut::adaugaContinut(continut);

    if (aplicatie) {
        if (auto* m = dynamic_cast<Melodie*>(continut)) {
            aplicatie->adaugaMelodieGlobal(m);
        }

        else if (auto* p = dynamic_cast<Podcast*>(continut)) {
            aplicatie->adaugaPodcastGlobal(p);
        }

        else if (auto* a = dynamic_cast<Audiobook*>(continut)) {
            aplicatie->adaugaAudiobookGlobal(a);
        }
    }
}