#include <iostream>
#include "Melodie.hpp"

using namespace std;


Melodie::Melodie(int durata, string titlu, string gen, int anLansare, string numeArtist) : ContinutAudio(durata, titlu, gen), anLansare(anLansare), numeArtist(numeArtist) {}

int Melodie::getAnLansare() const {
    return anLansare;
}

string Melodie::getNumeArtist() const {
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