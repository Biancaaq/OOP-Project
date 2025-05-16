#include <iostream>
#include "Audiobook.hpp"

using namespace std;


Audiobook::Audiobook(int durata, const string& titlu, const string& gen, const string& autor, const string& narator, const string& titluCarte) : ContinutAudio(durata, titlu, gen), autor(autor), narator(narator), titluCarte(titluCarte) {}

const string& Audiobook::getAutor() const {
    return autor;
}

const string& Audiobook::getNarator() const {
    return narator;
}

const string& Audiobook::getTitluCarte() const {
    return titluCarte;
}

void Audiobook::afiseazaInfo() const {
    cout << "Audiobook: " << titlu << endl;
    cout << "Carte: " << titluCarte << endl;
    cout << "Autor: " << autor << endl;
    cout << "Narator: " << narator << endl;
    cout << "Genul cartii: " << gen << endl;
    cout << "Durata povestii: " << durata << endl;
    cout << endl;
}