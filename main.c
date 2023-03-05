#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "image.h"
#include "music.h"
#include "text.h"



int main (int argc, char ** argv){

    //Variables Declaration

    SDL_Surface *screen;
    Image IMAGE, IMAGE_BUTTON_PLAY, IMAGE_BUTTON_PLAY_DOWN, IMAGE_BUTTON_OPTION, IMAGE_BUTTON_OPTION_DOWN, IMAGE_BUTTON_ABOUT, IMAGE_BUTTON_ABOUT_DOWN, IMAGE_BUTTON_EXIT, IMAGE_BUTTON_EXIT_DOWN,IMAGE_SUPPORT_MENU;
    Mix_Music *music;
   //  mix_Chunk *mus;
    texte txte;
    SDL_Event event;
    bool check=true;

    //Initialization of SDL

    if((SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)==-1){
       printf("Get error: %s",SDL_GetError());
       return -1; }

    //SDL Display Setting
    screen=SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEADTH,32,SDL_SWSURFACE |SDL_DOUBLEBUF);

    /*Initialization*/

   initializer_imageBack(&IMAGE);
   initializer_imageBUTTON_PLAY(&IMAGE_BUTTON_PLAY);
   initializer_imageBUTTON_PLAY_DOWN(&IMAGE_BUTTON_PLAY_DOWN);
   initializer_imageBUTTON_OPTION(&IMAGE_BUTTON_OPTION);
   initializer_imageBUTTON_OPTION_DOWN(&IMAGE_BUTTON_OPTION_DOWN);
   initializer_imgeBUTTON_ABOUT(&IMAGE_BUTTON_ABOUT);
   initializer_imgeBUTTON_ABOUT_DOWN(&IMAGE_BUTTON_ABOUT_DOWN);
   initializer_imageBUTTON_EXIT(&IMAGE_BUTTON_EXIT);
   initializer_imageBUTTON_EXIT_DOWN(&IMAGE_BUTTON_EXIT_DOWN);
   initializer_audio(music);
   initializer_texte(&txte);
   
    /*Gameloop (Menu loop)*/

    while(check){
    
   //Affichage

    display_image(screen,IMAGE);
    display_image_b(screen,IMAGE_BUTTON_PLAY);
    display_image_b(screen,IMAGE_BUTTON_OPTION);
    display_image_b(screen,IMAGE_BUTTON_ABOUT);
    display_image_b(screen,IMAGE_BUTTON_EXIT);
    display_texte(screen,txte);
 
    //INPUT

    SDL_PollEvent(&event);

	    switch(event.type)
	    {
     case   SDL_MOUSEMOTION:
	    if(event.type == SDL_MOUSEMOTION){
                if(event.motion.y<=260 && event.motion.y>=220 && event.motion.x<=550 && event.motion.x>=400){
	        SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,127,0,255));
	        display_image(screen,IMAGE);
		display_image_b(screen,IMAGE_BUTTON_PLAY_DOWN);
		display_image_b(screen,IMAGE_BUTTON_OPTION);
		display_image_b(screen,IMAGE_BUTTON_EXIT);
	        display_image_b(screen,IMAGE_BUTTON_ABOUT);
	        display_texte(screen,txte);
	        SDL_Flip(screen);}
	       	else if(event.motion.y<=500 & event.motion.y>=620 && event.motion.x<=550 && event.motion.x>=400){
                SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,127,0,255));
                display_image(screen,IMAGE);
		display_image_b(screen,IMAGE_BUTTON_OPTION_DOWN);
                display_image_b(screen,IMAGE_BUTTON_PLAY);
                display_image_b(screen,IMAGE_BUTTON_EXIT);
	        display_image_b(screen,IMAGE_BUTTON_ABOUT);
	        display_texte(screen,txte);
		SDL_Flip(screen);}
		else if (event.motion.y<=380 && event.motion.y>=450 && event.motion.x<=380 && event.motion.x>=450){
		display_image_b(screen,IMAGE_BUTTON_ABOUT_DOWN);
		SDL_Flip(screen);}
		else if(event.motion.y<=480 && event.motion.y>=550 && event.motion.x<=380 && event.motion.x>=450){
		display_image_b(screen,IMAGE_BUTTON_EXIT_DOWN);
		SDL_Flip(screen);}
              }
	    break;
     case SDL_MOUSEBUTTONDOWN:
	    if(event.button.button==SDL_BUTTON_LEFT 
	    && (event.motion.y<=300 && event.motion.y>=250
	    && event.motion.x<=423 && event.motion.x>=213))
	    check=false;
	    break;
     case       SDL_QUIT:
	    check=false;
	    break;


	    }
       


     SDL_Flip(screen);//Screen Update

    }
          

          
     //Cleaning Up RAM

     CleanUp_image(IMAGE);
     CleanUp_image(IMAGE_BUTTON_PLAY);
     CleanUp_image(IMAGE_BUTTON_PLAY_DOWN);
     CleanUp_image(IMAGE_BUTTON_OPTION);
     CleanUp_image(IMAGE_BUTTON_OPTION_DOWN);
     CleanUp_image(IMAGE_BUTTON_ABOUT);
     CleanUp_image(IMAGE_BUTTON_ABOUT_DOWN);
     CleanUp_image(IMAGE_BUTTON_EXIT);
     CleanUp_image(IMAGE_BUTTON_EXIT_DOWN);
     cleanUp_text(txte);
   
     //SHUTDOWN SDL

     SDL_Quit();

     return 0;
	 
    
}


            


           
