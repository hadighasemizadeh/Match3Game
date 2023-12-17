#include "View.hpp"
#include <sstream>

namespace MatchThree 
{
    namespace View
    {
        View::View(const GameLogic& game_logic): m_game_logic(game_logic),
                                                 m_renderer(std::make_unique<Renderer>())
        {}

        void View::gameOverView()
        {
            m_renderer->setColor(0, 0, 0, 230);

            int y = static_cast<int>(Controller::WINDOW_HEIGHT / 8);

            m_renderer->drawFilledRectangle( vector2D(0, y),
                                             Controller::WINDOW_WIDTH,
                                             static_cast<int>(Controller::WINDOW_HEIGHT / 2));

            m_renderer->drawText("GAME OVER!", 
                                vector2D(static_cast<int>(Controller::WINDOW_WIDTH / 2)-100,
                                         static_cast<int>(2*y)),
                                { 255, 155, 0, 225 });
        }

        void View::playView()
        {
            Block selected_block;
            // draw all blocks
            for (const auto& c_blocks : m_game_logic.m_board->getGrids())
            {
                for (const auto& block : c_blocks)
                {
                    if (!block.empty())
                    {
                        m_renderer->drawTexture(block.getBlockID(), block.getScreenCurrentPosition());
                    }
                }
            }

            m_renderer->drawText("Score", vector2D(30, 80));
            m_renderer->drawText(std::to_string(m_game_logic.getPlayerInfo().score).c_str(), vector2D(55, 120));
        }

        void View::update(const GameState game_state)
        {
            m_renderer->clear();
            m_renderer->drawBackground(0);
            
            switch (game_state)
            {
                case GameState::GameOver:
                    gameOverView();
                    break;
                case GameState::Play:
                    playView();
                    break;
                default:
                    break;
            }
            m_renderer->present();
        }
    }
}