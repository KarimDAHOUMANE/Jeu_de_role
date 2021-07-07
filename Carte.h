#ifndef CARTE_H
#define CARTE_H
#include <map>
#include "Element.h"
#include "Position.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "ObjetRamassable.h"
#include "Guerrier.h"
#include "Obstacle.h"
#include "Element.h"



using namespace std;

class Carte
{
private:
    int largeur;
    int hauteur;
    vector<Element*> elements;
public:
    Carte();
    int getHauteur() const;
    int getLargeur() const;
    void add(Element*);
    void afficher() const;
    void deplacer(Guerrier*, Direction);
    bool deplacable(Guerrier, Direction);
    bool ramassable(Guerrier, ObjetRamassable*);
    void ramasser(Guerrier& );
    int getSize() const;
    vector<Element*> getElements() const;
    Guerrier* touche(Guerrier&, Direction = HAUT, Direction = DROITE, Direction = BAS, Direction = GAUCHE);
    Guerrier* getGuerrier1();
    Guerrier* getGuerrier2();
    int nbOR();

protected:

};

#endif // CARTE_H
