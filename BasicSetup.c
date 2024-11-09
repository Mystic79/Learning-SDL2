#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/* width/height of window in pixels, uh idk why i left it as 800 for width but if i put width
instead of 640 as a replacement, it should fit just fine so long as its present for 
every single use of it(examples iclude SDL_Window, SDL_Texture, and pixels = [] or whatever) */
#define WIDTH 800
#define HEIGHT 480 

int main(int argc, char* argv[])
{
    bool run = false; // used for setup fro quitting and such
    SDL_Event ev;
    SDL_Init(SDL_INIT_EVERYTHING);
    int x = 200; // this was for smth else
    int y = 208; // this was for smth else
    typedef struct screen {
        SDL_Rect srcrect;
    } Test;
    SDL_Window* window = SDL_CreateWindow("mytism", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640,480, SDL_RENDERER_ACCELERATED | SDL_RENDERER_ACCELERATED);
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0); //i dont need to say anything
    while (!run) {
        SDL_Event ev;
        while (SDL_PollEvent(&ev)) { // polls for event and then if yes it just runs this stuff
            switch (ev.type) {
            case SDL_QUIT:
                run = true;
                break;
            }
        
        }
    }

    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
/* All this does is just clear out the rest, not much else to say here */
    return 0;
}
