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
    utilizatori.push_back(std::make_unique<Utilizator>(nume, email));
    utilizatori.back()->setAplicatie(this);

    cout << "Utilizator creat cu succes." << endl;
}

bool Aplicatie::autentificare(const string& email) {
    for (auto& u : utilizatori) {
        if (u->getEmail() == email) {
            utilizatorAutentificat = u.get();

            cout << "Bine ai revenit, " << u->getNume() << "!" << endl;

            return true;
        }
    }

    cout << "Emailul nu a fost gasit." << endl;

    return false;
}

void Aplicatie::deconectare() {
    utilizatorAutentificat = nullptr;
    cout << "Te-ai deconectat cu succes." << endl;
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

void Aplicatie::meniuPrincipal() {
    while (true) {
        cout << "~~~ Meniu Principal ~~~" << endl;
        cout << endl;
        cout << endl;
        cout << "1. Inregistrare" << endl;
        cout << "2. Autentificare" << endl;
        cout << "3. Iesire" << endl;
        cout << endl;
        cout << "Selectati o optiune: ";

        int optiune;
        cin >> optiune;
        cin.ignore();

        switch (optiune) {
            case 1: {
                string nume, email;
                cout << "Nume: ";
                getline(cin, nume);
                cout << "Email: ";
                getline(cin, email);
                cout << endl;

                inregistrareUtilizator(nume, email);

                break;
            }

            case 2: {
                string email;
                cout << "Email:";
                getline(cin, email);
                cout << endl;

                if (autentificare(email)) {
                    cout << "Autentificare reusita." << endl;
                    meniuUtilizator();
                }

                else {
                    cout << "Mai incearca!" << endl;
                }

                break;
            }

            case 3: {
                cout << "La revedere!" << endl;

                return;
            }

            default: {
                cout << "Optiune invalida. Incearca inca o data!" << endl;

                break;
            }
        }
    }
}

void Aplicatie::meniuUtilizator() {
    while (true) {
        cout << "~~~ Meniu Utilizator ~~~" << endl;
        cout << endl;
        cout << endl;
        cout << "Utilizator conectat: " << utilizatorAutentificat->getNume() << "Ce doresti sa faci?" << endl;
        cout << endl;
        cout << "1. Rasfoieste" << endl;
        cout << "2. Continut personal" << endl;
        cout << "3. Playlist-uri" << endl;
        cout << "4. Deconectare" << endl;
        cout << endl;
        cout << "Selectati o optiune: ";

        int optiune;
        cin >> optiune;
        cin.ignore();

        switch (optiune) {
            case 1: {
                cout << "momentan nimic";

                break;
            }

            case 2: {
                cout << "momentan nimic";

                break;
            }

            case 3: {
                cout << "momentan nimic";

                break;
            }

            case 4: {
                deconectare();

                return;
            }

            default: {
                cout << "Optiune invalida. Mai incearca inca o data!" << endl;
                
                break;
            }
        }
    }
}