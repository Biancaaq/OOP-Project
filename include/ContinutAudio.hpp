#ifndef CONTINUTAUDIO_HPP
#define CONTINUTAUDIO_HPP

#include <iostream>
#include <string>


class ContinutAudio {
    protected:
    int durata;
    std::string titlu;
    std::string gen;

    public:
    //constructor
    ContinutAudio(int durata = 0, const std::string& titlu = "", const std::string& gen = "");

    //destructor pur virtual
    virtual ~ContinutAudio() = 0;

    //getteri
    int getDurata() const;
    const std::string& getTitlu() const;
    const std::string& getGen() const;

    virtual void afiseazaInfo() const = 0;
};

#endif