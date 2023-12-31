#ifndef _COMMON_CONSTANTS_HPP_
#define _COMMON_CONSTANTS_HPP_

#include "Utils.hpp"
#include <map>
#include <string>

namespace MatchThree
{
    namespace Controller
    {
        const float DELTA   = 0.01f;
        const float GRAVITY = 70.0f;       // Gravity!! (in a galexy far far away)

        const unsigned int ROW = 16;
        const unsigned int COLUMN = 8;

        const unsigned int MINIMUM_NUMBER_OF_MATCHES = 4;

        enum class GameState
        {
            GameOver,
            Pause,
            Play
        };


        enum class BoardState
        {
            SPWANNING,
            ANIMATING,
            MATCH_CHECKING,
            GRAVITY,
            DEAD
        };

        enum class BlockState
        {
            IDLE,
            FALLING,
            SWAPPING,
            DYING,
            DEAD
        };

        const int WINDOW_WIDTH  = 800;
        const int WINDOW_HEIGHT = 600;
        
        const int BLOCK_SIZE_C = 31;
        const int BLOCK_SIZE_R = 31;

        const int BOARD_POS_C = WINDOW_HEIGHT/2 - 24;
        const int BOARD_POS_R = 73;

        const float FRAME_TIME = 1.0f / 60.0f;

        const char* const DEFAULT_FONT = "res/fonts/waltographUI.ttf";
        const int DEFAULT_FONT_SIZE = 24;
        
        const int FIRST_BLOCK_ID = 1;
        const std::map<int, std::string> block_tid_to_path{
            { 0, "res/textures/background.jpg"},
            { 1, "res/textures/blue.png" },
            { 2, "res/textures/green.png"}, 
            { 3, "res/textures/orange.png"}, 
            { 4, "res/textures/red.png"}, 
        };
    }
}
#endif