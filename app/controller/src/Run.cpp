
#define SDL_MAIN_HANDLED
#include "Run.hpp"
#include "NewGame.hpp"

#include <iostream>

#include <SDL.h>
#include <memory>

namespace MatchThree 
{
    namespace Controller
    {
        void Run()
        {
            // Create a new game for hard coded player name
            // I do not know for now how big this going to be, so I will make unique ptr
            std::unique_ptr<NewGame> new_game(std::make_unique<NewGame> ("Player1"));

            // Game main loop
            while (true)
            {
                unsigned int current_time = SDL_GetTicks();
                        
                try
                {
                    // TUDO: Handle possible excptions
                    // Update game
                    if (!new_game->update(current_time))
                        return;
                }
                catch (const std::exception&)
                {
                    std::cout << "Exception!!\n";
                }


                // To have a fixed update
                int time = SDL_GetTicks() - current_time;
                if (time < 0)
                    continue;

                int sleepTime = static_cast<int>((FRAME_TIME - time));
                if (sleepTime > 0)
                    SDL_Delay(sleepTime);
            }
        }
    } 
}