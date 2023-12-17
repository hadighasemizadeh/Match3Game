#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "Entity.hpp"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <memory>
#include <vector>

namespace MatchThree 
{
    namespace View
    {       
        using std::shared_ptr;

        class Renderer
        {
        private:
            SDL_Window*                 m_window;
            SDL_Renderer*               m_renderer;
            TTF_Font*                   m_font;
            std::vector<SDL_Texture*>	m_textures;

            void validateTexture(unsigned int t_id) const;

         public:
             Renderer();
             ~Renderer();

             void drawBackground(unsigned int texture_id);
             void drawFilledRectangle(Model::vector2D pos, int w, int h);
            
	         void drawText(const char *text, Model::vector2D pos, SDL_Color color={ 255, 255, 255, 225 });

             void drawTexture(unsigned int texture_id, Model::vector2D pos);
             void drawTextureCentered(unsigned int texture_id, Model::vector2D pos, int w, int h, double scale = 1.0);

             void drawButton(std::string btn_text, Model::vector2D pos, int w, int h);

             void present();

	         void setClipRect(Model::vector2D pos, int w, int h);
             void setColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

             void clear();
             void resetClipRect();
        };
    } 
}
#endif