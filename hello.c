#include <SDL3/SDL_main.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_log.h>
#include <string.h>
#include <stdio.h>

int main(){
    SDL_Window *window;
    SDL_Renderer *renderer;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("test", 750, 500, NULL);
    SDL_SetHint(SDL_HINT_RENDER_DRIVER, "software");
    //SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    //SDL_ShowWindow(window);
    renderer = SDL_CreateRenderer(window, NULL);

    /*
    int window_width, window_height;
    SDL_GetWindowSize(window, &window_width, &window_height);
    int window_x, window_y;
    SDL_GetWindowPosition(window, &window_x, &window_y);
    */
    //SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "SDL initialized successfully! %d", window_height);

    int run = 1;
    SDL_Event event;
    while (run){
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                run = 0;
                //SDL_HideWindow(window);
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        SDL_FRect rect;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        int window_width, window_height;
        SDL_GetWindowSize(window, &window_width, &window_height);
        rect.x = 0;
        rect.y = (window_height / 2) - 2;
        rect.h = 5;
        rect.w = window_width;
        SDL_RenderFillRect(renderer, &rect);

        int testTime = 2137;

        char timeToString[10];
        sprintf(timeToString, "%d", testTime);

        char text[500] = "komunikat za: ";
        strcat(text, timeToString);
        float scale = 4.0f;
        int text_width = 8 * SDL_strlen(text);  
        SDL_SetRenderScale(renderer, scale, scale);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderDebugText(renderer, (window_width / (2 * scale)) - (text_width / 2), (window_height / (4 * scale)), text);
        SDL_SetRenderScale(renderer, 1.0f, 1.0f);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
    
}