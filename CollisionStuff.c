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

int main(int argc, char *argv[])
{
    bool run = false; // used for setup fro quitting and such
    SDL_Event ev;
    SDL_Init(SDL_INIT_EVERYTHING);
    int x = 288;
    int y = 208;
    SDL_Window *window = SDL_CreateWindow("mytism", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_RENDERER_ACCELERATED | SDL_RENDERER_ACCELERATED);
    SDL_Renderer *render = SDL_CreateRenderer(window, -1, 0); // i dont need to say anything
    SDL_Rect rect1 = {x, y, 100, 100};
    SDL_Rect rect2 = {50, 50, 100, 80};

    while (!run)
    {
        SDL_bool boomBoom = SDL_HasIntersection(&rect1, &rect2);
        SDL_Event ev;
        SDL_PollEvent(&ev); // polls for event and then if yes it just runs this stuff
        switch (ev.type)
        {
        case SDL_QUIT:
            run = true;
            break;
        case SDL_KEYDOWN:
            if (!boomBoom)
            {
                switch (ev.key.keysym.sym)
                {
                case SDLK_UP:
                    rect1.y -= 10;
                    break;
                case SDLK_DOWN:
                    rect1.y += 10;
                    break;
                case SDLK_LEFT:
                    rect1.x -= 10;
                    break;
                case SDLK_RIGHT:
                    rect1.x += 10;
                    break;
                }
            }
            else
            {
                rect1.x = 288;
                rect1.y = 208;
            }
            break;
        }

        SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
        SDL_RenderClear(render);
        if (boomBoom)
        {
            SDL_SetRenderDrawColor(render, 113, 11, 252, 255);
        }
        else
        {
            SDL_SetRenderDrawColor(render, 255, 0, 255, 255);
        }
        SDL_RenderFillRect(render, &rect1);

        if (boomBoom)
        {
            SDL_SetRenderDrawColor(render, 113, 11, 252, 255);
        }
        else
        {
            SDL_SetRenderDrawColor(render, 0, 255, 255, 255);
        }
        SDL_RenderFillRect(render, &rect2);

        SDL_RenderPresent(render);
    }
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
    /* All this does is just clear out the rest, not much else to say here */
    return 0;
}
