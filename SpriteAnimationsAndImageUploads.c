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
    SDL_Surface* image = IMG_Load("porpolfull.png");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(render, image);
    SDL_SetRenderDrawColor(render, 255, 126, 111, 255);
    SDL_RenderClear(render);
    while (!run) {
        SDL_Event ev;
        Uint32 ticks = SDL_GetTicks();
        int seconds = ticks / 100;
        int sprite = (seconds % 5);
        if (sprite < 3) {
            SDL_Rect srcrect = {(sprite) * 32, 0, 32, 32};
            SDL_Rect dsrect = {240, 240, 128, 128};
            SDL_RenderCopy(render, texture, &srcrect, &dsrect);
            SDL_RenderPresent(render);
            SDL_RenderClear(render);
        } else if (sprite == 3) {
            SDL_Rect srcrect = {0, 32, 32, 32};
            SDL_Rect dsrect = {240, 240, 128, 128};
            SDL_RenderCopy(render, texture, &srcrect, &dsrect);
            SDL_RenderPresent(render);
            SDL_RenderClear(render);
        } else if (sprite == 4) {
            SDL_Rect srcrect = {32, 32, 32, 32};
            SDL_Rect dsrect = {240, 240, 128, 128};
            SDL_RenderCopy(render, texture, &srcrect, &dsrect);
            SDL_RenderPresent(render);
            SDL_RenderClear(render);
        }
        while (SDL_PollEvent(&ev)) { // polls for event and then if yes it just runs this stuff
            switch (ev.type) {
            case SDL_QUIT:
                run = true;
                break;
            }
        
        }
    }
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
/* All this does is just clear out the rest, not much else to say here */
    return 0;
}