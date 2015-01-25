#ifndef __MY_DISPLAY_H
#define __MY_DISPLAY_H

#include <SDL2/SDL.h>
#include <string>

class Display
{
public:
    Display(int width, int height, const std::string& title);

    void Update();

    virtual ~Display();

    bool    IsClosed() { return m_isClosed; }

    void    Clear(float red, float green, float blue, float alpha);

private:
    SDL_Window* m_window;
    SDL_GLContext m_glContext;
    bool    m_isClosed;
};

#endif

