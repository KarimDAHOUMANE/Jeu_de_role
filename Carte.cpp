#include "Carte.h"

Carte::Carte()
{
    ifstream fichier("map1.txt", ios::in);
    if (fichier)
    {
        char c;
        string l,h;
        getline(fichier,l);
        getline(fichier,h);
        largeur = stoi(l);
        hauteur = stoi(h);
        int i = 0;
        int j = 0;

        while (fichier >> noskipws >> c)
        {
            switch (c)
            {
            case '*':
            {
                Position p = Position(i,j);
                add(new Obstacle(p));
                i++;
                break;
            }
            case ' ':
            {
                i++;
                break;
            }
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            {
                Position p = Position(i,j);
                int n = (int)c - 48;
                add(new ObjetRamassable(p,n));
                i++;
                break;
            }
            case 'G':
            {
                Position p = Position(i,j);
                add(new Guerrier(p, "Akram", EQUIPE1));
                i++;
                break;
            }
            case 'g':
            {
                Position p = Position(i,j);
                add(new Guerrier(p, "Karim", EQUIPE2));
                i++;
                break;
            }
            case '\n':
            {
                i=0;
                j++;
                break;
            }
            default:
                perror("End of file");
            }
        }

        fichier.close();
    }
    else cerr << "Impossible d'ouvrir le fichier";


}

int Carte::getHauteur() const
{
    return hauteur;
}

int Carte::getLargeur() const
{
    return largeur;
}

void Carte::afficher() const
{
    ifstream fichier("map1.txt", ios::in);
    if (fichier)
    {
        string contenu;
        string l,h;
        getline(fichier,l);
        getline(fichier,h);
        while (getline(fichier,contenu))
        {
            cout << contenu<< endl;
        }
        fichier.close();
    }
    else cerr << "Impossible d'ouvrir le fichier";
}

void Carte::add(Element* e)
{
    elements.push_back(e);
}

void Carte::deplacer(Guerrier* g, Direction d)
{
    if (deplacable(*g,d))
    {
        switch(d)
        {
        case HAUT:
        {
            int x = g->getPosition().getX();
            int y = g->getPosition().getY()-1;
            g->setPosition(Position(x,y));
        }
        break;

        case BAS:
        {
            int x = g->getPosition().getX();
            int y = g->getPosition().getY()+1;
            g->setPosition(Position(x,y));
        }
        break;

        case GAUCHE:
        {
            int x = g->getPosition().getX()-1;
            int y = g->getPosition().getY();
            g->setPosition(Position(x,y));
        }
        break;

        case DROITE:
        {
            int x = g->getPosition().getX()+1;
            int y = g->getPosition().getY();
            g->setPosition(Position(x,y));
        }
        break;
        }
    }

}


bool Carte::deplacable(Guerrier g, Direction d)
{
    bool b = true;
    switch(d)
    {
    case HAUT:
    {
        int x = g.getPosition().getX();
        int y = g.getPosition().getY()-1;
        Position p = Position(x,y);
        vector<Element*>::iterator it;
        for(it = elements.begin(); it!=elements.end(); ++it)
        {
            if ((*it)->getPosition() == p)
            {
                b = false;
            }
        }
    }
    break;

    case BAS:
    {
        int x = g.getPosition().getX();
        int y = g.getPosition().getY()+1;
        Position p = Position(x,y);
        vector<Element*>::iterator it;
        for(it = elements.begin(); it!=elements.end(); ++it)
        {
            if ((*it)->getPosition() == p      )
            {
                b = false;
            }
        }
    }
    break;

    case GAUCHE:
    {
        int x = g.getPosition().getX()-1;
        int y = g.getPosition().getY();
        Position p = Position(x,y);
        vector<Element*>::iterator it;
        for(it = elements.begin(); it!=elements.end(); ++it)
        {
            if ((*it)->getPosition() == p      )
            {
                b = false;
            }
        }
    }
    break;

    case DROITE:
    {
        int x = g.getPosition().getX()+1;
        int y = g.getPosition().getY();
        Position p = Position(x,y);
        vector<Element*>::iterator it;
        for(it = elements.begin(); it!=elements.end(); ++it)
        {
            if ((*it)->getPosition() == p      )
            {
                b = false;
            }
        }

    }
    break;
    }
    return b;
}



int Carte::getSize() const
{
    return elements.size();
}


vector<Element*> Carte::getElements() const
{
    return elements;
}


Guerrier* Carte::touche(Guerrier& g, Direction d1, Direction d2, Direction d3, Direction d4)
{
    Position pNord = Position(g.getPosition().getX(), g.getPosition().getY()-1);
    Position pSud = Position(g.getPosition().getX(), g.getPosition().getY()+1);
    Position pEst = Position(g.getPosition().getX()+1, g.getPosition().getY());
    Position pOuest = Position(g.getPosition().getX()-1, g.getPosition().getY());

    vector<Element*>::iterator it;
    for(it = elements.begin(); it!=elements.end(); ++it)
    {
        if ((*it)->getType() == GUERRIER)
        {
            Guerrier* tmp = dynamic_cast<Guerrier*>(*it);
            if (tmp->getPosition() == pNord || tmp->getPosition() == pSud || tmp->getPosition() == pEst || tmp->getPosition() == pOuest)
            {
                if (g.estAdversaire(*tmp))
                {
                    cout << tmp->getNom() << endl;
                    return tmp;
                }
            }
        }
    }
    return NULL;
}


bool Carte::ramassable(Guerrier g, ObjetRamassable* o)
{
    bool b = false;
    if (g.getPosition().getX() + 1 == o->getPosition().getX() && g.getPosition().getY() == o->getPosition().getY())
        b = true;
    if (g.getPosition().getX() - 1 == o->getPosition().getX() && g.getPosition().getY() == o->getPosition().getY())
        b = true;
    if (g.getPosition().getX() == o->getPosition().getX() && g.getPosition().getY() + 1 == o->getPosition().getY())
        b = true;
    if (g.getPosition().getX() == o->getPosition().getX() && g.getPosition().getY() - 1 == o->getPosition().getY())
        b = true;
    return b;
}

void Carte::ramasser(Guerrier& g)
{
    vector<Element*>::iterator it;
    for(it = elements.begin(); it!=elements.end(); ++it)
    {
        if ((*it)->getType() == OBJETRAMASSABLE){
            ObjetRamassable* tmp = dynamic_cast<ObjetRamassable*>(*it);
            if (ramassable(g,tmp)){
                g.setVie(g.getVie()+tmp->getNbPtsVie());
                elements.erase(it);
            }
        }
    }
}


Guerrier* Carte::getGuerrier1(){
    vector<Element*>::iterator it;
    for(it = elements.begin(); it!=elements.end(); ++it)
    {
        if ((*it)->getType() == GUERRIER)
        {
            Guerrier* tmp = dynamic_cast<Guerrier*>(*it);
            if (tmp->getEquipe() == EQUIPE1)
                return tmp;
        }
    }
}

Guerrier* Carte::getGuerrier2(){
    vector<Element*>::iterator it;
    for(it = elements.begin(); it!=elements.end(); ++it)
    {
        if ((*it)->getType() == GUERRIER)
        {
            Guerrier* tmp = dynamic_cast<Guerrier*>(*it);
            if (tmp->getEquipe() == EQUIPE2)
                return tmp;
        }
    }
}

int Carte::nbOR(){
    int i=0;
    vector<Element*>::iterator it;
    for(it = elements.begin(); it!=elements.end(); ++it)
    {
        if ((*it)->getType() == OBJETRAMASSABLE)
        {
            i++;
        }
    }
    return i;
}
