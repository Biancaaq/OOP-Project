#ifndef APLICATIE_HPP
#define APLICATIE_HPP

#include <vector>
#include <string>
#include <memory>
#include "Utilizator.hpp"
#include "Melodie.hpp"
#include "Podcast.hpp"
#include "Audiobook.hpp"


class Aplicatie {
    std::vector<std::unique_ptr<Utilizator>> utilizatori;
    std::vector<Melodie*> melodiiGlobale;
    std::vector<Podcast*> podcasturiGlobale;
    std::vector<Audiobook*> audiobookuriGlobale;

    Utilizator* utilizatorAutentificat = nullptr;

    public:
    Aplicatie() = default;
    ~Aplicatie();

    Utilizator* getUtilizatorAutentificat();

    const std::vector<Melodie*>& getMelodiiGlobale() const;
    const std::vector<Podcast*>& getPodcasturiGlobale() const;
    const std::vector<Audiobook*>& getAudiobookuriGlobale() const;

    void inregistrareUtilizator(const std::string& nume, const std::string& email);
    bool autentificare(const std::string& email);
    void deconectare();

    void adaugaMelodieGlobal(Melodie* m);
    void adaugaPodcastGlobal(Podcast* p);
    void adaugaAudiobookGlobal(Audiobook* a);

    void meniuPrincipal();
    void meniuUtilizator();
};

#endif