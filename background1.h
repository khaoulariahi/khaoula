#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL_mixer.h>


typedef struct {
	SDL_Surface *backgroundImg;
        SDL_Rect camera, backgroundPos, backgroundPos2;
Mix_Music *music;
int shift_pressed;
int walk_right_permission;
	int walk_left_permission;
	int is_running_right;
	int is_running_left;
	float acceleration;

}Background;
typedef struct {
SDL_Surface *images[3];
SDL_Rect position;
int nbr_frame;
}objet;
        

void init_ecran(SDL_Surface **screen);
void initBack(Background *b);
void afficherBack(Background b,SDL_Surface *screen);
//void afficherBack_partage(Background b,SDL_Surface *screen);
void libererbg(Background b);
void scrolling_right (Background* b);
void scrolling_left(Background* b);
void scrollingdown (Background* b);
void scrollingup (Background* b);
void initobjet(objet *p);
