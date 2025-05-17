#ifndef UTILIZATOR_HPP
#define UTILIZATOR_HPP

#include <string>
#include <memory>
#include "CreatorContinut.hpp"
#include "Ascultator.hpp"


class Aplicatie;

class Utilizator : public CreatorContinut, public Ascultator {
    Aplicatie *aplicatie = nullptr;

    public:
    //constructor
    explicit Utilizator(const std::string& nume = "", const std::string& email = "");

    //destructor
    ~Utilizator() override;

    void setAplicatie(Aplicatie* a);

    void adaugaContinut(std::shared_ptr<ContinutAudio> continut) override;
    void stergeContinutCreat(size_t index) override;
};

#endif