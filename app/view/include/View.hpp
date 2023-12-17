#ifndef _VIEW_HPP_
#define _VIEW_HPP_

#include "Utils.hpp"
#include "Renderer.hpp"
#include "Vector2D.hpp"
#include "GameLogic.hpp"

#include <memory>

using namespace MatchThree::Model;

namespace MatchThree 
{
    namespace View
    {   
        class Renderer;

        class View
        {
         private:
             const GameLogic&               m_game_logic;
             std::unique_ptr<Renderer>      m_renderer;

        public:
             View(const GameLogic& game_logic);

             void gameOverView();
             void playView();

             void update(const GameState game_state);
        };
    }
}
#endif