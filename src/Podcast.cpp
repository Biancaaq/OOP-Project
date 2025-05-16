#include <iostream>
#include "Podcast.hpp"

using namespace std;


Podcast::Podcast(int durata, const string& titlu, const string& gen, int episod, const string& gazda, const string& descriere) : ContinutAudio(durata, titlu, gen), episod(episod), gazda(gazda), descriere(descriere) {}

int Podcast::getEpisod() const {
    return episod;
}

const string& Podcast::getGazda() const {
    return gazda;
}

const string& Podcast::getDescriere() const {
    return descriere;
}

void Podcast::afiseazaInfo() const {
    cout << "Podcast: " << titlu << endl;
    cout << "Gazda: " << gazda << endl;
    cout << "Genul podcast-ului: " << gen << endl;
    cout << "Durata episodului: " << durata << endl;
    cout << "Episodul: " << episod << endl;

    if (descriere.empty()) {
        cout << "Acest podcast nu are momentan o descriere." << endl;
    }

    else {
        cout << "Descriere: " << descriere << endl;
    }

    cout << endl;
}
