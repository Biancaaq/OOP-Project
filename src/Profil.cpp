#include <iostream>
#include "Profil.hpp"

using namespace std;


int Profil::idUtilizator = 0;

Profil::Profil(const string& nume, const string& email) : id(++idUtilizator), nume(nume), email(email) {}

Profil::~Profil() {}

int Profil::getId() const {
    return id;
}

const string& Profil::getNume() const {
    return nume;
}

const string& Profil::getEmail() const {
    return email;
}

void Profil::setNume(const string& numeNou) {
    nume = numeNou;
}

void Profil::setEmail(const string& emailNou) {
    email = emailNou;
}

void Profil::afiseazaProfil() const {
  cout << "Profil id: " << id << endl;
  cout << "Nume utilizator: " << nume << endl;
  cout << "Email utilizator: " << email << endl;
}