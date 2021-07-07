#include "Game.h"

Game::Game()
{
    Carte carte;
    try
    {
        SDL sdl(carte, SDL_INIT_VIDEO | SDL_INIT_TIMER );
        //   sdl.draw();
    }
    catch ( const InitError & err )
    {
        std::cerr << "Error while initializing SDL:  "
                  << err.what()
                  << std::endl;
    }
}


/*#include <iostream>
#include "Carte.h"

using namespace std;

int main()
{

    Carte c;
    vector<Element*> v = c.getElements();
    for (int i=0; i<v.size(); i++){
            if (v[i]->getType() == GUERRIER){
                Guerrier* tmp = dynamic_cast<Guerrier*>(v[i]);
                if (tmp->getNom() == "Akram"){
                        c.touche(*tmp,HAUT,BAS,GAUCHE,DROITE);
//                        cout << "HAUT " << c.deplacable(*tmp,HAUT)<<endl;
//                        cout << "BAS " << c.deplacable(*tmp,BAS)<<endl;
//                        cout << "GAUCHE " << c.deplacable(*tmp,GAUCHE)<<endl;
//                        cout << "DROITE " << c.deplacable(*tmp,DROITE)<<endl;
//
//
//                        cout << "X = " << tmp->getPosition().getX() << endl;
//                        cout << "Y = " << tmp->getPosition().getY() << endl;
//                        c.deplacer(*tmp, BAS);
//                        cout << "X = " << tmp->getPosition().getX() << endl;
//                        cout << "Y = " << tmp->getPosition().getY() << endl;
                }
            }
    }



    return 0;
}*/
