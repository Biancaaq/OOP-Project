#include <iostream>
#include "Utilizator.hpp"
#include "Melodie.hpp"
#include "Podcast.hpp"
#include "Audiobook.hpp"
#include "Aplicatie.hpp"

using namespace std;

int main() {
    Utilizator u("Bubu", "bubu@rock.com");

    cout << u.getEmail() << endl;
    cout << u.getNume() << endl;
    cout << u.getId() << endl;

    Melodie* m = new Melodie(210, "Still Alive", "Rock", 2023, u.getNume());
    Podcast* p = new Podcast(1800, "Mind Architect", "Psihologie", 17, "Paul Olteanu", "Despre mindset");
    Audiobook* a = new Audiobook(7200, "Micul Print", "Poveste", "Exupery", "Ion Caramitru", "Micul Print");

    cout << m->getTitlu() << endl;
    cout << m->getNumeArtist() << endl;
    cout << m->getAnLansare() << endl;
    cout << m->getDurata() << endl;
    cout << m->getGen() << endl;

    cout << p->getEpisod() << endl;
    cout << p->getGazda() << endl;
    cout << p->getDescriere() << endl;


    cout << a->getAutor() << endl;
    cout << a->getNarator() << endl;
    cout << a->getTitluCarte() << endl;

    u.afiseazaContinutCreat();
    cout << endl << endl;

    u.adaugaContinut(m);
    u.adaugaContinut(p);
    u.adaugaContinut(a);


    u.afiseazaIstoricAscultari();
    cout << endl << endl;

    u.asculta(m);
    u.asculta(a);


    u.afiseazaContinutCreat();
    cout << endl << endl;;


    u.afiseazaIstoricAscultari();
    cout << endl << endl;

    u.setNume("Bianca");
    u.setEmail("Bianca@rock.com");
    u.afiseazaProfil();

    vector<ContinutAudio*> istoric = u.getIstoricAscultari();
    vector<ContinutAudio*> publicat = u.getContinutCreat();

    cout << "Numar ascultari: " << istoric.size() << endl;
    cout << "Numar continut creat: " << publicat.size() << endl;

    delete m;
    delete a;
    delete p;

    Aplicatie apl;

    apl.inregistrareUtilizator("Ana", "ana@maria.com");
    if (apl.autentificare("ana@maria.com")) {
        Utilizator* u1 = apl.getUtilizatorAutentificat();

        Melodie* m1 = new Melodie(100, "test", "Pop", 2020,"Ana");

        u1->adaugaContinut(m1);

        Podcast* p1 = new Podcast(3000, "Tech Talk", "Tehnologie", 1, "Ana", "Podcast despre AI");
        u1->adaugaContinut(p1);

        Audiobook* a1 = new Audiobook(7200, "1984", "Distopie", "George Orwell", "Ana", "1984");
        u1->adaugaContinut(a1);

        for (const auto* mel : apl.getMelodiiGlobale()) {
            mel->afiseazaInfo();
        }

        for (const auto* pod : apl.getPodcasturiGlobale()) {
            pod->afiseazaInfo();
        }

        for (const auto* aud : apl.getAudiobookuriGlobale()) {
            aud->afiseazaInfo();
        }

        cout << u1->getId();

        apl.deconectare();
    }

    apl.inregistrareUtilizator("Ioana", "io@maria.com");
    if (apl.autentificare("io@maria.com")) {
        Utilizator* u2 = apl.getUtilizatorAutentificat();

       cout << u2->getId();
    }

    apl.inregistrareUtilizator("Alex", "i@maria.com");
    if (apl.autentificare("i@maria.com")) {
        Utilizator* u3 = apl.getUtilizatorAutentificat();

        cout << u3->getId();
    }

    Aplicatie apl2;
    apl2.meniuPrincipal();


















    /////////////////////////////////////////////////////////////////////////
    /// Observație: dacă aveți nevoie să citiți date de intrare de la tastatură,
    /// dați exemple de date de intrare folosind fișierul tastatura.txt
    /// Trebuie să aveți în fișierul tastatura.txt suficiente date de intrare
    /// (în formatul impus de voi) astfel încât execuția programului să se încheie.
    /// De asemenea, trebuie să adăugați în acest fișier date de intrare
    /// pentru cât mai multe ramuri de execuție.
    /// Dorim să facem acest lucru pentru a automatiza testarea codului, fără să
    /// mai pierdem timp de fiecare dată să introducem de la zero aceleași date de intrare.
    ///
    /// Pe GitHub Actions (bife), fișierul tastatura.txt este folosit
    /// pentru a simula date introduse de la tastatură.
    /// Bifele verifică dacă programul are erori de compilare, erori de memorie și memory leaks.
    ///
    /// Dacă nu puneți în tastatura.txt suficiente date de intrare, îmi rezerv dreptul să vă
    /// testez codul cu ce date de intrare am chef și să nu pun notă dacă găsesc vreun bug.
    /// Impun această cerință ca să învățați să faceți un demo și să arătați părțile din
    /// program care merg (și să le evitați pe cele care nu merg).
    ///
    /////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// Pentru date citite din fișier, NU folosiți tastatura.txt. Creați-vă voi
    /// alt fișier propriu cu ce alt nume doriți.
    /// Exemplu:
    /// std::ifstream fis("date.txt");
    /// for(int i = 0; i < nr2; ++i)
    ///     fis >> v2[i];
    return 0;
}
