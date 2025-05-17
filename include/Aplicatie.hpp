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
    std::vector<std::shared_ptr<Melodie>> melodiiGlobale;
    std::vector<std::shared_ptr<Podcast>> podcasturiGlobale;
    std::vector<std::shared_ptr<Audiobook>> audiobookuriGlobale;

    Utilizator* utilizatorAutentificat = nullptr;

    public:
    Aplicatie() = default;
    ~Aplicatie();

    Utilizator* getUtilizatorAutentificat();

    const std::vector<std::shared_ptr<Melodie>>& getMelodiiGlobale() const;
    const std::vector<std::shared_ptr<Podcast>>& getPodcasturiGlobale() const;
    const std::vector<std::shared_ptr<Audiobook>>& getAudiobookuriGlobale() const;

    void stergeMelodieGlobal(const std::shared_ptr<Melodie>& m);
    void stergePodcastGlobal(const std::shared_ptr<Podcast>& p);
    void stergeAudiobookGlobal(const std::shared_ptr<Audiobook>& a);

    void inregistrareUtilizator(const std::string& nume, const std::string& email);
    bool autentificare(const std::string& email);
    void deconectare();

    void adaugaMelodieGlobal(std::shared_ptr<Melodie> m);
    void adaugaPodcastGlobal(std::shared_ptr<Podcast> p);
    void adaugaAudiobookGlobal(std::shared_ptr<Audiobook> a);

    void meniuPrincipal();
    void meniuUtilizator();
    void meniuContinut();
};

#endif