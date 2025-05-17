#ifndef Ascultator_HPP
#define Ascultator_HPP

#include <vector>
#include <memory>
#include "Profil.hpp"


class ContinutAudio;

class Ascultator : virtual public Profil {
    protected:
    std::vector<std::shared_ptr<ContinutAudio>> istoricAscultari;

    std::vector<ContinutAudio*> melodiiFavorite;
    std::vector<ContinutAudio*> podcasturiFavorite;
    std::vector<ContinutAudio*> audiobookuriFavorite;

    public:
    //destructor pur virtual; fara cuvantul cheie virtual deoarece primeam warning de redundanta
    ~Ascultator() override = 0;

    void asculta(std::shared_ptr<ContinutAudio> continut);
    const std::vector<std::shared_ptr<ContinutAudio>>& getIstoricAscultari() const;
    void afiseazaIstoricAscultari() const;

    void adaugaMelodieFavorita(ContinutAudio* m);
    void adaugaPodcastFavorit(ContinutAudio* p);
    void adaugaAudiobookFavorit(ContinutAudio* a);

    void afiseazaFavorite() const;
    void stergeFavorit(int tip, size_t index);
};

#endif