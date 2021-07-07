#include "SDL.h"
#include "Carte.h"


SDL::SDL(Carte carte, Uint32 flags) : carte(carte)
{
    if ( SDL_Init( flags ) != 0 )
        throw InitError();

    if ( SDL_CreateWindowAndRenderer( carte.getHauteur()*tailleBloc, carte.getLargeur()*tailleBloc+50, SDL_WINDOW_SHOWN, &pWindow, &pRenderer ) != 0 )
    {
        SDL_Quit();
        throw InitError();
    }
    SDL_SetWindowTitle(pWindow, "Warrior Strike");
    bool isOpen = true;

    while (isOpen)
    {
        bloc = SDL_LoadBMP("bloc.bmp");
        objetRamassable = SDL_LoadBMP("objet_ramassable.bmp");
        guerrierTab1[BAS] = SDL_LoadBMP("g1_bas.bmp");
        guerrierTab1[GAUCHE] = SDL_LoadBMP("g1_gauche.bmp");
        guerrierTab1[HAUT] = SDL_LoadBMP("g1_haut.bmp");
        guerrierTab1[DROITE] = SDL_LoadBMP("g1_droite.bmp");
        guerrierTab2[BAS] = SDL_LoadBMP("g2_bas.bmp");
        guerrierTab2[GAUCHE] = SDL_LoadBMP("g2_gauche.bmp");
        guerrierTab2[HAUT] = SDL_LoadBMP("g2_haut.bmp");
        guerrierTab2[DROITE] = SDL_LoadBMP("g2_droite.bmp");
        guerrier1 = guerrierTab1[BAS];
        guerrier2 = guerrierTab2[DROITE];
        SDL_SetRenderDrawColor(pRenderer, 245, 245, 220, 255);
        SDL_RenderClear(pRenderer);


        while (SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_QUIT:
                isOpen = false;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    isOpen = false;
                    break;
                case SDLK_UP:{
                    guerrier1 = guerrierTab1[HAUT];
                    carte.deplacer(carte.getGuerrier1(), HAUT);
                    cout << "X : "<<carte.getGuerrier1()->getPosition().getX() << endl;
                    cout << "Y : "<<carte.getGuerrier1()->getPosition().getY() << endl;
                    draw(carte.getElements());
                }
                    break;
                case SDLK_DOWN:
                    guerrier1 = guerrierTab1[BAS];
                    carte.deplacer(carte.getGuerrier1(), BAS);
                    cout << "X : "<<carte.getGuerrier1()->getPosition().getX() << endl;
                    cout << "Y : "<<carte.getGuerrier1()->getPosition().getY() << endl;
                    draw(carte.getElements());
                    break;
                case SDLK_RIGHT:
                    guerrier1 = guerrierTab1[DROITE];
                    carte.deplacer(carte.getGuerrier1(), DROITE);
                    cout << "X : "<<carte.getGuerrier1()->getPosition().getX() << endl;
                    cout << "Y : "<<carte.getGuerrier1()->getPosition().getY() << endl;
                    draw(carte.getElements());
                    break;
                case SDLK_LEFT:
                    guerrier1 = guerrierTab1[GAUCHE];
                    carte.deplacer(carte.getGuerrier1(), GAUCHE);
                    cout << "X : "<<carte.getGuerrier1()->getPosition().getX() << endl;
                    cout << "Y : "<<carte.getGuerrier1()->getPosition().getY() << endl;
                    draw(carte.getElements());
                    break;
                case SDLK_e:
                    carte.ramasser(*carte.getGuerrier1());
                    draw(carte.getElements());
                    break;
                }
                break;
            }
        }
    }
}

SDL::~SDL()
{
    SDL_DestroyWindow( pWindow );
    SDL_DestroyRenderer( pRenderer );
    SDL_Quit();
}

void SDL::draw(vector<Element*> v){
    SDL_Rect rectangle, SrcR, DestR;

    txtrObjetRamassable = SDL_CreateTextureFromSurface(pRenderer, objetRamassable);
    SDL_FreeSurface(objetRamassable);
    txtrBloc = SDL_CreateTextureFromSurface(pRenderer, bloc);
    SDL_FreeSurface(bloc);
    txtrGuerrier1 = SDL_CreateTextureFromSurface(pRenderer, guerrier1);
    SDL_FreeSurface(guerrier1);
    txtrGuerrier2 = SDL_CreateTextureFromSurface(pRenderer, guerrier2);
    SDL_FreeSurface(guerrier2);
    vector<Element*>::iterator it;
    for(auto it = v.begin(); it!=v.end(); ++it)
    {
        if ((*it)->getType() == GUERRIER)
        {
            Guerrier* tmp = dynamic_cast<Guerrier*>(*it);
            if (tmp->getEquipe() == EQUIPE1) {
            //Guerrier* tmp1 = dynamic_cast<Guerrier*>(*it);
            SrcR.x = 0;
            SrcR.y = 0;
            SrcR.h = tailleBloc;
            SrcR.w = tailleBloc;
            DestR.x = tmp->getPosition().getX()*tailleBloc;
            DestR.y = tmp->getPosition().getY()*tailleBloc;
            DestR.h = tailleBloc;
            DestR.w = tailleBloc;
            SDL_RenderCopy(pRenderer, txtrGuerrier1, &SrcR, &DestR);
            }
            if ((tmp)->getEquipe() == EQUIPE2) {
            //Guerrier* tmp1 = dynamic_cast<Guerrier*>(*it);
            SrcR.x = 0;
            SrcR.y = 0;
            SrcR.h = tailleBloc;
            SrcR.w = tailleBloc;
            DestR.x = tmp->getPosition().getX()*tailleBloc;
            DestR.y = tmp->getPosition().getY()*tailleBloc;
            DestR.h = tailleBloc;
            DestR.w = tailleBloc;
            SDL_RenderCopy(pRenderer, txtrGuerrier2, &SrcR, &DestR);
            }
        }
        if ((*it)->getType() == OBSTACLE)
        {
            Obstacle* tmp = dynamic_cast<Obstacle*>(*it);
            SrcR.x = 0;
            SrcR.y = 0;
            SrcR.h = tailleBloc;
            SrcR.w = tailleBloc;
            DestR.x = tmp->getPosition().getX()*tailleBloc;
            DestR.y = tmp->getPosition().getY()*tailleBloc;
            DestR.h = tailleBloc;
            DestR.w = tailleBloc;
            SDL_RenderCopy(pRenderer, txtrBloc, &SrcR, &DestR);

        }
        if ((*it)->getType() == OBJETRAMASSABLE)
        {
            ObjetRamassable* tmp = dynamic_cast<ObjetRamassable*>(*it);
            SrcR.x = 0;
            SrcR.y = 0;
            SrcR.h = tailleBloc;
            SrcR.w = tailleBloc;
            DestR.x = tmp->getPosition().getX()*tailleBloc;
            DestR.y = tmp->getPosition().getY()*tailleBloc;
            DestR.h = tailleBloc;
            DestR.w = tailleBloc;
            SDL_RenderCopy(pRenderer, txtrObjetRamassable, &SrcR, &DestR);
            SDL_RenderPresent(pRenderer);
        }
    }
    SDL_RenderPresent(pRenderer);
}
