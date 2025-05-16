#include <iostream>
#include "Melodie.hpp"

using namespace std;


Melodie::Melodie(int durata, const string& titlu, const string& gen, int anLansare, const string& numeArtist) : ContinutAudio(durata, titlu, gen), anLansare(anLansare), numeArtist(numeArtist) {}

int Melodie::getAnLansare() const {
    return anLansare;
}

const string& Melodie::getNumeArtist() const {
    return numeArtist;
}

void Melodie::afiseazaInfo() const {
    cout << "Melodie: " << titlu << endl;
    cout << "Artist: " << numeArtist << endl;
    cout << "Gen muzical: " << gen << endl;
    cout << "Durata: " << durata << " secunde" << endl;
    cout << "An lansare: " << anLansare << endl;
    cout << endl;
}