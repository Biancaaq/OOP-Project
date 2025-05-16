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
    Profil(std::string nume = "", std::string email = "");

    //destructor pur virtual
    virtual ~Profil() = 0;

    //getteri
    int getId() const;
    std::string getNume() const;
    std::string getEmail() const;

    //setteri
    void setNume(std::string numeNou);
    void setEmail(std::string emailNou);

    void afiseazaProfil() const;
};

#endif