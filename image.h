#ifndef IMAGE_H
#define IMAGE_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#define SCREEN_WIDTH 1000
#define SCREEN_HEADTH 900

typedef struct{
  char *url;
  SDL_Rect pos_img_affichage;
  SDL_Rect pos_img_display;
  SDL_Surface *img;
}Image;
 

    //Headers for initialisation

void initializer_imageBack(Image *imge);
void initializer_imageMenuBoard(Image *imgeB); 
void initializer_imageBUTTON_PLAY(Image *imgbtn);
void initializer_imageBUTTON_PLAY_DOWN(Image *imgbtn);
void initializer_imageBUTTON_OPTION(Image *imgbtn);
void initializer_imageBUTTON_OPTION_DOWN(Image *imgbtn);
void initializer_imgeBUTTON_ABOUT(Image *imgbtn);
void initializer_imgeBUTTON_ABOUT_DOWN(Image *imgbtn);
void initializer_imageBUTTON_EXIT(Image *imgbtn);
void initializer_imageBUTTON_EXIT_DOWN(Image *imgbtn);

  //Header for samples per display

void display_image(SDL_Surface *screen,Image imge);
void display_image_b(SDL_Surface *screen,Image imge);

 //Header for screen cleaning

void CleanUp_image (Image imge);         

#endif
