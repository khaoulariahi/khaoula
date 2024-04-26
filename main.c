#include"background1.h"
int main ( int argc, char** argv )
{
Background bk;
objet p;
SDL_Surface *screen;
init_ecran(&screen);
initBack(&bk);
initobjet(&p);
int boucle = 1;
SDL_Event event ;
 bk.walk_right_permission = 1;
    bk.walk_left_permission =1;
    bk.is_running_right = 0;
    bk.is_running_left = 0;
    bk.acceleration=1.0f;
//Mix_Music *music;
while(boucle) 
	{

//
    
        afficherBack(bk,screen);
      //  SDL_Flip(screen);
        //Uint32 current_time = SDL_GetTicks();
       afficherobjet(p,screen);
      animerobjet (&p);


        if (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    SDL_FreeSurface(bk.backgroundImg);
                    SDL_Quit();
                    boucle= 0;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                        boucle=0;
                        break;
                        case SDLK_RIGHT:
                       if (!bk.is_running_left) {
                            
                            bk.is_running_right = 1;
                            }
                            
                            
                            
                            break;
                        case SDLK_LEFT:
                	    if (!bk.is_running_right) {
                	    
                	    bk.is_running_left = 1;
                	    }
                	    
                            break;
                        case SDLK_LSHIFT:
                        	bk.shift_pressed = 1;
                        	//c.start_time = SDL_GetTicks();
                        	bk.acceleration=1.0f;
                            break;
                        case SDLK_DOWN :
                                scrollingdown (&bk);
                            break;
                        case SDLK_UP :
                                scrollingup (&bk);
                            break;
                        default:
                            break;
                    }
                    break;
                case SDL_KEYUP:
                    switch (event.key.keysym.sym) {
                        case SDLK_RIGHT:
                      
                           bk.is_running_right = 0;
                            break;
                        case SDLK_LEFT:
                      
                           bk.is_running_left = 0;
                            break;
                        case SDLK_LSHIFT:
			    bk.shift_pressed = 0;
                            bk.acceleration=1.0f;
                            break;   
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
     
	if(bk.walk_right_permission == 1)
	{
 	if (bk.is_running_right) {
            scrolling_right (&bk);
        }
        }
        if(bk.walk_left_permission == 1)
        {
	if (bk.is_running_left) {
	scrolling_left (&bk);
	}
	}

		SDL_Flip(screen);

}











libererbg(bk);
SDL_Quit();
return 0;

}
