#include "Utilizator.hpp"
#include "Aplicatie.hpp"
#include "Melodie.hpp"
#include "Podcast.hpp"
#include "Audiobook.hpp"

using namespace std;


Utilizator::Utilizator(const string& nume, const string& email) : Profil(nume, email), CreatorContinut(), Ascultator() {}

Utilizator::~Utilizator() = default;

void Utilizator::setAplicatie(Aplicatie* a) {
    aplicatie = a;
}

void Utilizator::adaugaContinut(shared_ptr<ContinutAudio> continut) {
    CreatorContinut::adaugaContinut(continut);

    if (aplicatie) {
        if (auto m = dynamic_pointer_cast<Melodie>(continut)) {
            aplicatie->adaugaMelodieGlobal(m);
        }

        else if (auto p = dynamic_pointer_cast<Podcast>(continut)) {
            aplicatie->adaugaPodcastGlobal(p);
        }

        else if (auto a = dynamic_pointer_cast<Audiobook>(continut)) {
            aplicatie->adaugaAudiobookGlobal(a);
        }
    }
}

void Utilizator::stergeContinutCreat(size_t index) {
    shared_ptr<ContinutAudio> continutSters = continutCreat[index];

    CreatorContinut::stergeContinutCreat(index);

    if (aplicatie) {
        if (auto m = dynamic_pointer_cast<Melodie>(continutSters)) {
            aplicatie->stergeMelodieGlobal(m);
        }

        else if (auto p = dynamic_pointer_cast<Podcast>(continutSters)) {
            aplicatie->stergePodcastGlobal(p);
        }

        else if (auto a = dynamic_pointer_cast<Audiobook>(continutSters)) {
            aplicatie->stergeAudiobookGlobal(a);
        }
    }
}