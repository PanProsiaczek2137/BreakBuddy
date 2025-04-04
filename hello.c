#include <SDL3/SDL_main.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_log.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

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

    int grabed = 0;
    int grabed2 = 0;
    int moving1 = 0;
    int moving2 = 0;

    SDL_FRect rect3_1;  // Deklaracja PRZED pętlą
    rect3_1.x = 25 + moving1;
    rect3_1.y = (500 / 1.25 - 5);
    rect3_1.h = 13;
    rect3_1.w = 13;

    SDL_FRect rect4_1;  // Deklaracja PRZED pętlą
    rect4_1.x = (moving2 - 6) + 20;
    rect4_1.y = 50; //(500 / 1.25 - 5);
    rect4_1.h = 13;
    rect4_1.w = 13;

    int mousePosX = 0;
    int mousePosY = 0;

    int workTime = 20;
    int breakTime = 10;

    while (run){


        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);


        int window_width, window_height;
        SDL_GetWindowSize(window, &window_width, &window_height);

        SDL_FRect rect;
        rect.x = 0;
        rect.y = (window_height / 2) - 2;
        rect.h = 5;
        rect.w = window_width;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
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



        
        SDL_FRect rect2;
        rect2.x = (window_width / 2) - 2;
        rect2.y = window_height / 2;
        rect2.h = window_height / 2;
        rect2.w = 5;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &rect2);




        SDL_FRect rect3;
        rect3.x = 25;
        rect3.y = window_height / 1.25;
        rect3.h = 3;
        rect3.w = (window_width  / 2) - 50;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &rect3);

        if(moving1 > 25 && moving1 < 350){
            rect3_1.x = moving1 - 6;
        }
        rect3_1.y = (window_height / 1.25 - 5);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &rect3_1);


        SDL_SetRenderScale(renderer, 2.5f, 2.5f);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        char workToString[10];
        sprintf(workToString, "%d", workTime);
        char text2[500] = "praca: ";
        strcat(text2, workToString);
        strcat(text2, "min");
        SDL_RenderDebugText(renderer, 25, window_height / 4, text2);
        SDL_SetRenderScale(renderer, 1.0f, 1.0f);



        

        SDL_FRect rect4;
        rect4.x = (window_width  / 2) + 25;
        rect4.y = window_height / 1.25;
        rect4.h = 3;
        rect4.w = (window_width  / 2) - 50;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &rect4);

        //if(moving2 > 25 && moving2 < 350){
            rect4_1.x = (moving2 - 6) + 20;
        //}
        //rect4_1.y = (window_height / 1.25 - 5);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &rect3_1);

        SDL_SetRenderScale(renderer, 2.5f, 2.5f);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        char breakeToString[10];
        sprintf(breakeToString, "%d", breakTime);
        char text3[500] = "przerwa: ";
        strcat(text3, breakeToString);
        strcat(text3, "min");
        SDL_RenderDebugText(renderer, (window_width / 4)-15 , window_height / 4, text3);
        SDL_SetRenderScale(renderer, 1.0f, 1.0f);






        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                run = 0;
                //SDL_HideWindow(window);
            }

            if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
                int mx = event.button.x;
                int my = event.button.y;

                //mousePosX = mx;
                //mousePosY = my;
        
                if (mx >= rect3_1.x && mx <= rect3_1.x + rect3_1.w &&
                    my >= rect3_1.y && my <= rect3_1.y + rect3_1.h) {
                    grabed = 1;
                    SDL_Log("grabed");
                }

                if (mx >= rect4_1.x && mx <= rect4_1.x + rect4_1.w &&
                    my >= rect4_1.y && my <= rect4_1.y + rect4_1.h) {
                    grabed2 = 1;
                    SDL_Log("grabed2");
                }
            }


            if (event.type == SDL_EVENT_MOUSE_MOTION && grabed) {
                // ograniczenie zakresu
                if (event.motion.x < 25)
                    moving1 = 25;
                else if (event.motion.x > 350)
                    moving1 = 350;
                else
                    moving1 = event.motion.x;
            
                workTime = ((moving1 - 25) / 325.0) * 100 + 20;
            }
            //if (event.type == SDL_EVENT_MOUSE_MOTION && grabed2) {
                // ograniczenie zakresu
                //if (event.motion.x < 25)
                    //moving2 = 25;
                //else if (event.motion.x > 350)
                    //moving2 = 350;
                //else
                    //moving2 = event.motion.x;
            
                //breakTime = ((moving2 - 25) / 325.0) * 100 + 20;
            //}

            
            if (event.type == SDL_EVENT_MOUSE_BUTTON_UP) {
                grabed = 0;
                grabed2 = 0;
                SDL_Log("UNgrabed!!!");
            }

        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
    
}