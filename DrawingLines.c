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
    bool leftMouseButtonDown = false; // starts as false so it doesnt draw pixels everywhere
    bool drawing = false;
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;
    int* arr = NULL;
    int size;
    typedef struct Line {
        int x1;
        int x2;
        int y1;
        int y2;
    } ooga;
    SDL_Init(SDL_INIT_EVERYTHING);
    int x = 200; // this was for smth else
    int y = 208; // this was for smth else
    int lines[10][4];
    int index = 0;
    SDL_Window* window = SDL_CreateWindow("mytism", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640,480, SDL_RENDERER_ACCELERATED | SDL_RENDERER_ACCELERATED);
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0); //i dont need to say anything
    SDL_Texture* texture = SDL_CreateTexture(render, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STATIC, 640, 480); //creates texture of pixel, ABGR8888 = format for color
    Uint32* pixels; // im 99% sure this declares its existence
    pixels = (Uint32*)malloc(sizeof(Uint32) * 640 * 480);
    memset(pixels, 255, 640 * 480 * sizeof(Uint32)); // sets screen to color, 255 refers to black to white

    while (!run) {
        SDL_UpdateTexture(texture, NULL, pixels, 640 * sizeof(Uint32)); //self explanatory
        SDL_Event ev;
        SDL_Rect dstrect = { x, y, 50, 50 };
        
        while (SDL_PollEvent(&ev)) { // polls for event and then if yes it just runs this stuff
            switch (ev.type) {
            case SDL_QUIT:
                run = true;
                break;
            case SDL_MOUSEBUTTONUP:
                switch(ev.button.button) {
                    case SDL_BUTTON_LEFT:
                        drawing = false;
                        lines[index][0] = x1;
                        lines[index][1] = y1;
                        lines[index][2] = x2;
                        lines[index][3] = y2;
                        index++;
                        break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch(ev.button.button) {
                    case SDL_BUTTON_LEFT:
                        x1 = ev.motion.x;
                        y1 = ev.motion.y;
                        x2 = ev.motion.x;
                        y2 = ev.motion.y;
                        drawing = true;
                    break;
                }
            break;
            case SDL_MOUSEMOTION:
                if (drawing) {
                    x2 = ev.motion.x;
                    y2 = ev.motion.y;
                }
                break;
            }
        SDL_RenderClear(render);
        SDL_RenderCopy(render, texture, NULL, NULL);
        SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
        SDL_RenderDrawLine(render, x1, y1, x2, y2);
        for (int i = 0; i < index; i++) SDL_RenderDrawLine(render, lines[i][0], lines[i][1], lines[i][2], lines[i][3]);
        SDL_RenderPresent(render);
        }
    }
    free(arr);
    free(pixels);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
/* All this does is just clear out the rest, not much else to say here */
    return 0;
}