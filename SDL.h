#ifndef SDL_H
#define SDL_H
#include <SDL.h>
#include <SDL/SDL_ttf.h>
#include "Carte.h"
#include "InitError.h"
class SDL
{

private:
    SDL_Texture* pTextureImage, *txtrBloc, *txtrObjetRamassable, *txtrGuerrier1, *txtrGuerrier2;

    SDL_Surface *guerrierTab1[4] = {nullptr}, *guerrierTab2[4] = {nullptr};
    SDL_Surface *bloc = nullptr, *objetRamassable = nullptr, *guerrier1 = nullptr, *guerrier2 = nullptr;
    SDL_Rect position, positionJoueur;
    SDL_Event event;
    int tailleBloc = 34;
    Carte carte;
    SDL_Window* pWindow{ nullptr };
    SDL_Renderer* pRenderer{ nullptr };
public:
    SDL(Carte, Uint32 flags = 0);
    virtual ~SDL();
    void draw(vector<Element*> v);
};

#endif // SDL_H


