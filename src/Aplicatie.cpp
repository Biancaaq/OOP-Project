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


void Aplicatie::stergeMelodieGlobal(const shared_ptr<Melodie>& m) {
    for (auto i = melodiiGlobale.begin(); i != melodiiGlobale.end(); ++i) {
        if (*i == m) {
            melodiiGlobale.erase(i);

            break;
        }
    }
}

void Aplicatie::stergePodcastGlobal(const shared_ptr<Podcast>& p) {
    for (auto i = podcasturiGlobale.begin(); i != podcasturiGlobale.end(); ++i) {
        if (*i == p) {
            podcasturiGlobale.erase(i);

            break;
        }
    }
}

void Aplicatie::stergeAudiobookGlobal(const shared_ptr<Audiobook>& a) {
    for (auto i = audiobookuriGlobale.begin(); i != audiobookuriGlobale.end(); ++i) {
        if (*i == a) {
            audiobookuriGlobale.erase(i);

            break;
        }
    }
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
                meniuRasfoire();

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
                cout << "4. Inapoi" << endl;
                cout << "Selecteaza o optiune: ";
                cout << endl;

                int tip;
                cin >> tip;
                cin.ignore();

                shared_ptr<ContinutAudio> continutNou;
                int durata;
                string titlu, gen;

                if (tip == 1) {
                    int an;
                    string artist = utilizatorAutentificat->getNume();

                    cout << "Titlul melodiei: ";
                    getline(cin, titlu);
                    cout << "Genul melodiei: ";
                    getline(cin, gen);
                    cout << "Durata in secunde a melodiei: ";
                    cin >> durata;
                    cin.ignore();
                    cout << "Anul lansarii melodiei: ";
                    cin >> an;
                    cin.ignore();

                    continutNou = make_shared<Melodie>(durata, titlu, gen, an, artist);
                }

                else if (tip == 2) {
                    int episod;
                    string descriere, gazda = utilizatorAutentificat->getNume();

                    cout << "Titlul podcastului: ";
                    getline(cin, titlu);
                    cout << "Genul podcastului: ";
                    getline(cin, gen);
                    cout << "Durata in secunde a podcastului: ";
                    cin >> durata;
                    cin.ignore();
                    cout << "Episodul: ";
                    cin >> episod;
                    cin.ignore();
                    cout << "Descrierea podcastului: ";
                    getline(cin, descriere);

                    continutNou = make_shared<Podcast>(durata, titlu, gen, episod, gazda, descriere);
                }

                else if (tip == 3) {
                    string autor, titluCarte, narator = utilizatorAutentificat->getNume();

                    cout << "Titlul audiobookului: ";
                    getline(cin, titlu);
                    cout << "Genul audiobookului: ";
                    getline(cin, gen);
                    cout << "Durata in secunde a audiobookului: ";
                    cin >> durata;
                    cin.ignore();
                    cout << "Autorul cartii: ";
                    getline(cin, autor);
                    cout << "Titlul cartii: ";
                    getline(cin, titluCarte);

                    continutNou = make_shared<Audiobook>(durata, titlu, gen, autor, narator, titluCarte);
                }

                else if (tip == 4) {
                    break;
                }

                else {
                    cout << "Optiune invalida." << endl;

                    break;
                }

                utilizatorAutentificat->adaugaContinut(continutNou);

                cout << "Continut incarcat cu succes!" << endl;

                break;
            }

            case 2: {
                const auto& continutCreat = utilizatorAutentificat->getContinutCreat();

                if (continutCreat.empty()) {
                    cout << "Nu ai creat niciun continut pana acum." << endl;

                    break;
                }

                cout << "Continutul creat:" << endl << endl;

                for (size_t i = 0; i < continutCreat.size(); ++i) {
                    cout << "[" << i << "] ";

                    if (continutCreat[i]) {
                        continutCreat[i]->afiseazaInfo();
                    }

                    cout << endl;
                }

                cout << "Selecteaza indexul continutului pe care doresti sa il stergi sau '-1' daca doresti sa anulezi stergerea: " << endl << endl;

                int index;
                cin >> index;
                cin.ignore();

                if (index == -1) {
                    cout << "Stergerea a fost anulata." << endl;

                    break;
                }

                if (index < 0 || static_cast<size_t>(index) >= continutCreat.size()) {
                    cout << "Index invalid. Mai incearca." << endl;

                    break;
                }

                utilizatorAutentificat->stergeContinutCreat(index);

                cout << "Continutul a fost sters cu succes!" << endl;

                break;
            }

            case 3: {
                utilizatorAutentificat->afiseazaContinutCreat();

                break;
            }

            case 4: {
                return;
            }

            default: {
                cout << "Optiune invalida. Incearca din nou" << endl;

                break;
            }
        }
    }
}

void Aplicatie::meniuRasfoire() {
    while (true) {
        cout << "Iata tot continutul incarcat pe platforma pana in acest moment: " << endl;

        cout << "Melodii: " << endl << endl;
        for (size_t i = 0; i < melodiiGlobale.size(); ++i) {
            cout << i << ". ";
            melodiiGlobale[i]->afiseazaInfo();
        }

        cout << "Podcasturi: " << endl << endl;
        for (size_t i = 0; i < podcasturiGlobale.size(); ++i) {
            std::cout << i << ". ";
            podcasturiGlobale[i]->afiseazaInfo();
        }

        cout << "Audiobookuri: " << endl << endl;
        for (size_t i = 0; i < audiobookuriGlobale.size(); ++i) {
            std::cout << i << ". ";
            audiobookuriGlobale[i]->afiseazaInfo();
        }

        cout << endl;
        cout << "Pentru a adauga un continut la favorite, introdu tipul (1 = melodie, 2 = podcast, 3 = audiobook) si indexul." << endl;
        cout << "Apasa -1 pentru a te intoarce la meniul principal." << endl << endl;

        int tip, index;
        cin >> tip;
        cin.ignore();
        cin >> index;
        cin.ignore();

        if (tip == -1) {
            break;
        }

        if (tip == 1 && index >= 0 && index < static_cast<int>(melodiiGlobale.size())) {
            cout << "Melodie adaugata la favorite." << endl;
        }

        else if (tip == 2 && index >= 0 && index < static_cast<int>(podcasturiGlobale.size())) {
            cout << "Podcast adaugat la favorite." << endl;
        }

        else if (tip == 3 && index >= 0 && index < static_cast<int>(audiobookuriGlobale.size())) {
            cout << "Audiobook adaugat la favorite." << endl;
        }

        else {
            cout << "Index sau tip invalid!" << endl;
        }
    }

}