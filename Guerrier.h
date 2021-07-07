#ifndef GUERRIER_H
#define GUERRIER_H
#include "Element.h"

enum Equipe { EQUIPE1, EQUIPE2 };


class Guerrier : public Element
{
private:
    int ptsVie;
    string nom;
    Equipe equipe;
    int capAttack;
    int capDefense;
    ElemType type;
public:
    Guerrier(Position, string, Equipe);
    virtual ~Guerrier();
    void setVie(int ptsVie);
    int getVie();
    Equipe getEquipe() const;
    string getNom() const;
    int getCapAttack() const;
    void setCapAttack(int);
    int getCapDefense() const;
    void setCapDefense(int);
    void attack(Guerrier&);
    bool estAdversaire(Guerrier);
    virtual ElemType getType() const;

protected:

};

#endif // GUERRIER_H

