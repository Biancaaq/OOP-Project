#include <iostream>
#include "Aplicatie.hpp"

using namespace std;


Aplicatie::~Aplicatie() {
    for (auto* m : melodiiGlobale) {
        delete m;
    }

    for (auto* p : podcasturiGlobale) {
        delete p;
    }

    for (auto* a : audiobookuriGlobale) {
        delete a;
    }
}

void Aplicatie::inregistrareUtilizator(const string& nume, const string& email) {
    utilizatori.emplace_back(nume, email);
    utilizatori.back().setAplicatie(this);

    cout << "Utilizator creat cu succes." << endl;
}

bool Aplicatie::autentificare(const string& email) {
    for (auto& u : utilizatori) {
        if (u.getEmail() == email) {
            utilizatorAutentificat = &u;

            cout << "Bine ai revenit, " << u.getNume() << "!" << endl;

            return true;
        }
    }

    cout << "Emailul nu a fost gasit." << endl;

    return false;
}

void Aplicatie::deconectare() {
    utilizatorAutentificat = nullptr;
    cout << "Te-ai deconectat." << endl;
}

Utilizator* Aplicatie::getUtilizatorAutentificat() {
    return utilizatorAutentificat;
}


void Aplicatie::adaugaMelodieGlobal(Melodie* m) {
    melodiiGlobale.push_back(m);
}

void Aplicatie::adaugaPodcastGlobal(Podcast* p) {
    podcasturiGlobale.push_back(p);
}

void Aplicatie::adaugaAudiobookGlobal(Audiobook* a) {
    audiobookuriGlobale.push_back(a);
}


const vector<Melodie*>& Aplicatie::getMelodiiGlobale() const {
    return melodiiGlobale;
}

const vector<Podcast*>& Aplicatie::getPodcasturiGlobale() const {
    return podcasturiGlobale;
}

const vector<Audiobook*>& Aplicatie::getAudiobookuriGlobale() const {
    return audiobookuriGlobale;
}