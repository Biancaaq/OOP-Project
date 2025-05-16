#include <iostream>
#include "Profil.hpp"

using namespace std;


int Profil::idUtilizator = 0;

Profil::Profil(string nume, string email) : id(++idUtilizator), nume(nume), email(email) {}

Profil::~Profil() {}

int Profil::getId() const {
    return id;
}

string Profil::getNume() const {
    return nume;
}

string Profil::getEmail() const {
    return email;
}

void Profil::setNume(string numeNou) {
    nume = numeNou;
}

void Profil::setEmail(string emailNou) {
    email = emailNou;
}

void Profil::afiseazaProfil() const {
  cout << "Profil id: " << id << endl;
  cout << "Nume utilizator: " << nume << endl;
  cout << "Email utilizator: " << email << endl;
}