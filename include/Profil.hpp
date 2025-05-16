#ifndef PROFIL_HPP
#define PROFIL_HPP

#include <iostream>
#include <string>


class Profil {
    protected:
    static int idUtilizator;
    int id;
    std::string nume;
    std::string email;

    public:
    //constructor
    Profil(const std::string& nume = "", const std::string& email = "");

    //destructor pur virtual
    virtual ~Profil() = 0;

    //getteri
    int getId() const;
    const std::string& getNume() const;
    const std::string& getEmail() const;

    //setteri
    void setNume(const std::string& numeNou);
    void setEmail(const std::string& emailNou);

    void afiseazaProfil() const;
};

#endif