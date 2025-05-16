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
    ContinutAudio(int durata = 0, std::string titlu = "", std::string gen = "");

    //destructor pur virtual
    virtual ~ContinutAudio() = 0;

    //getteri
    int getDurata() const;
    std::string getTitlu() const;
    std::string getGen() const;

    virtual void afiseazaInfo() const = 0;
};

#endif