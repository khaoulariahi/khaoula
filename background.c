
#include "background.h"

void init_ecran(SDL_Surface **screen)
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("Echec d'initialisation de SDL : %s\n", SDL_GetError());
		return ;
	
	}	
	else
		printf("Bonjour le monde, SDL est initialisé avec succès.\n");


	*screen = SDL_SetVideoMode(1464,680,32,SDL_HWSURFACE | SDL_DOUBLEBUF |SDL_RESIZABLE);
	if(*screen==NULL)
	{	
		fprintf(stderr,"echec de la creation de la fenetre:%s\n",SDL_GetError());
		return;
	}
}
void initBack(Background *b)
{

 b->backgroundImg = IMG_Load("Sans-titre---2.png");
    b->camera.x=0;
    b->camera.y=0;
    b->camera.h=720;
    b->camera.w=1464;
	
    b->backgroundPos.x=0;
    b->backgroundPos.y=0;
    b->backgroundPos.h=720;
    b->backgroundPos.w=732;

	b->backgroundPos2.x=0;
	b->backgroundPos2.y=0;
	b->backgroundPos2.h=720;
	b->backgroundPos2.w=732;



if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
	{
		printf("%s", Mix_GetError());
	}

	b->music = Mix_LoadMUS("music.mp3");

	Mix_PlayMusic(b->music, -1);

}
void afficherBack(Background b,SDL_Surface *screen)
{ 
	SDL_BlitSurface(b.backgroundImg,&(b.camera),screen,NULL);

}

/*void afficherBack_partage(Background b,SDL_Surface *screen)
{       SDL_Rect pos={732,0,720,720};
      SDL_BlitSurface(b.backgroundImg,&b.backgroundPos,screen,NULL);
      SDL_BlitSurface(b.backgroundImg,&b.backgroundPos2,screen,&pos);

}*/

void libererbg(Background b)
{
	SDL_FreeSurface(b.backgroundImg);
}


void scrolling_right (Background* b)
{
	if(!b->shift_pressed)
        {
        b->camera.x+=5;
        }
        
        if(b->shift_pressed)
        {
       b->camera.x=b->camera.x+5*(int)b->acceleration;
        }
        
        if (b->camera.x >7500)
        {
            b->camera.x=7500;
        }
}

void scrolling_left(Background* b)
{
	
    	if(!b->shift_pressed)
        {
        b->camera.x-=5;
         printf("%d",b->camera.x);
        }
        
        if(b->shift_pressed)
        {
        b->camera.x=b->camera.x-5*(int)b->acceleration;
        }
        
    if (b->camera.x <= 5)
    {
        b->camera.x = 0;
    }
}
void scrollingdown (Background* b)
{
        b->camera.y+=40;
        if (b->camera.y >=600)
        {
            b->camera.y=600;
        }//9600 1080
}
void scrollingup (Background* b)
{
       b->camera.y-=40;
        if (b->camera.y <=10)
        {
            b->camera.y=10;
        }
}
void initobjet(objet *p){
	int i,j;
    char nom_image[30];//400 355
   
    p->nbr_frame=0;
 
    p->position.x=0;
    p->position.y=0;
    p->position.w=400;
    p->position.h=355;

   
        for ( j = 0; j < 3; j++)
        {   
            sprintf(nom_image,"animation/%d.png",j);
            p->images[j]=IMG_Load(nom_image);
        }
        
    
    
}
void afficherobjet(objet p, SDL_Surface * screen){
    SDL_BlitSurface(p.images[p.nbr_frame],NULL,screen,&p.position);
}
void animerobjet (objet* p)
{
    
  p->nbr_frame++;
    if (p->nbr_frame >= 3)
 p->nbr_frame=0;

}


















