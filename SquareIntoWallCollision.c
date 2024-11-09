#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/* width/height of window in pixels, uh idk why i left it as 800 for width but if i put width
instead of 640 as a replacement, it should fit just fine so long as its present for
every single use of it(examples iclude SDL_Window, SDL_Texture, and pixels = [] or whatever) */
#define WIDTH 640
#define HEIGHT 480

int main(int argc, char *argv[])
{
    bool run = false; // used for setup fro quitting and such
    SDL_Event ev;
    SDL_Init(SDL_INIT_EVERYTHING);
    int x = 288;
    int y = 208;
    int sizeOfRectx = 100;
    int sizeOfRecty = 100;
    SDL_Window *window = SDL_CreateWindow("mytism", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_RENDERER_ACCELERATED | SDL_RENDERER_ACCELERATED);
    SDL_Renderer *render = SDL_CreateRenderer(window, -1, 0); // i dont need to say anything
    SDL_Rect rect1 = {x, y, 100, 100};

    while (!run)
    {
        SDL_Event ev;
        SDL_PollEvent(&ev); // polls for event and then if yes it just runs this stuff
        switch (ev.type)
        {
        case SDL_QUIT:
            run = true;
            break;
        case SDL_KEYDOWN:
            switch (ev.key.keysym.sym)
            {
            case SDLK_UP:
                if (rect1.y >= 0)
                {
                    rect1.y -= 10;
                }
                break;
            case SDLK_DOWN:
                if (rect1.y <= (HEIGHT - sizeOfRecty))
                {
                    rect1.y += 10;
                }
                break;
            case SDLK_LEFT:
                if (rect1.x >= 0)
                {
                    rect1.x -= 10;
                }
                break;
            case SDLK_RIGHT:
                if (rect1.x <= (WIDTH - sizeOfRectx))
                {
                    rect1.x += 10;
                }
                break;
            }
            break;
        }

        SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
        SDL_RenderClear(render);
        SDL_SetRenderDrawColor(render, 113, 11, 252, 255);
        SDL_RenderFillRect(render, &rect1);

        SDL_RenderPresent(render);
    }
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
    /* All this does is just clear out the rest, not much else to say here */
    return 0;
}
