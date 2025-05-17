#include <iostream>
#include "Aplicatie.hpp"

using namespace std;


Aplicatie::~Aplicatie() = default;

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


void Aplicatie::adaugaMelodieGlobal(shared_ptr<Melodie> m) {
    melodiiGlobale.push_back(m);
}

void Aplicatie::adaugaPodcastGlobal(shared_ptr<Podcast> p) {
    podcasturiGlobale.push_back(p);
}

void Aplicatie::adaugaAudiobookGlobal(shared_ptr<Audiobook> a) {
    audiobookuriGlobale.push_back(a);
}


const vector<shared_ptr<Melodie>>& Aplicatie::getMelodiiGlobale() const {
    return melodiiGlobale;
}

const vector<std::shared_ptr<Podcast>>& Aplicatie::getPodcasturiGlobale() const {
    return podcasturiGlobale;
}

const vector<shared_ptr<Audiobook>>& Aplicatie::getAudiobookuriGlobale() const {
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
        cout << "Selecteaza o optiune: ";

        int optiune;
        cin >> optiune;
        cin.ignore();

        switch (optiune) {
            case 1: {
                cout << "momentan nimic";

                break;
            }

            case 2: {
                meniuContinut();

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

void Aplicatie::meniuContinut() {
    while (true) {
        cout << "~~~ Continut Personal ~~~" << endl;
        cout << endl;
        cout << endl;
        cout << "1. Incarca continut" << endl;
        cout << "2. Sterge continut" << endl;
        cout << "3. Vizualizeaza continutul creat" << endl;
        cout << "4. Inapoi" << endl;
        cout << endl;
        cout << "Selecteaza o optiune: ";

        int opt;
        cin >> opt;
        cin.ignore();

        switch (opt) {
            case 1: {
                cout << "Ce tip de continut doresti sa adaugi?" << endl;
                cout << endl;
                cout << endl;
                cout << "1. Melodie" << endl;
                cout << "2. Podcast" << endl;
                cout << "3. Audiobook" << endl;
                cout << "Selecteaza o optiune: ";
                cout << endl;

                int tip;
                cin >> tip;
                cin.ignore();

                // shared_ptr<ContinutAudio> continutNou;
                // int durata;
                // string titlu, gen;
                //
                // if (tip == 1) {
                //     int an;
                //     string artist = utilizatorAutentificat->getNume();
                //
                //     cout << "Titlu: ";
                //     getline(cin, titlu);
                //     cout << "Gen: ";
                //     getline(cin, gen);
                //     cout << "Durata: ";
                //     cin >> durata;
                //     cin.ignore();
                //     cout << "An lansare: ";
                //     cin >> an;
                //     cin.ignore();
                //
                //     continutNou = make_shared<Melodie>(durata, titlu, gen, an, artist);
                // }
                //
                // else if (tip == 2) {
                //     int episod;
                //     string descriere, gazda = utilizatorAutentificat->getNume();
                // }
            }
        }
    }
}