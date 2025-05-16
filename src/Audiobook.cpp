#include <iostream>
#include "Audiobook.hpp"

using namespace std;


Audiobook::Audiobook(int durata, string titlu, string gen, string autor, string narator, string titluCarte) : ContinutAudio(durata, titlu, gen), autor(autor), narator(narator), titluCarte(titluCarte) {}

string Audiobook::getAutor() const {
    return autor;
}

string Audiobook::getNarator() const {
    return narator;
}

string Audiobook::getTitluCarte() const {
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