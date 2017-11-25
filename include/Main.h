#ifndef __MAIN__
#define __MAIN__

#define BUFFER_OFFSET( offset )   ((GLvoid*) (offset))

const Vec4 red =    {1.f, 0.f, 0.f, 1.f};
const Vec4 darkred = {.5f, 0.f, 0.f, 1.f};
const Vec4 green =  {0.f, 1.f, 0.f, 1.f};
const Vec4 darkgreen =  {0.f, 0.5f, 0.f, 1.f};
const Vec4 blue =   {0.f, 0.f, 1.f, 1.f};
const Vec4 darkblue =   {0.f, 0.f, .5f, 1.f};
const Vec4 cgray =  {.3f, .3f, .3f, 1.f};
const Vec4 yellow = {1.f, 1.f, 0.f, 1.f};
const Vec4 darkyellow = {.5f, .5f, 0.f, 1.f};
const Vec4 purple = {1.f, 0.f, 1.f, 1.f};
const Vec4 darkpurple = {.5f, 0.f, .5f, 1.f};
const Vec4 cyan =   {0.f, 1.f, 1.f, 1.f};
const Vec4 darkcyan =   {0.f, .5f, .5f, 1.f};
const Vec4 black =   {0.f, .0f, .0f, 1.f};
const Vec4 white =   {1.f, 1.f, 1.f, 1.f};
const Vec4 redAmb = {.15,0,0,1};
const Vec4 blueAmb = {0,0,.15,1};
const Vec4 yellowAmb = {.15,.15,0,1};
const Vec4 purpleAmb = {.15,0,.15,1};
const Vec4 cyanAmb = {0,.15,.15,1};


void idle_func();
void keyboard(unsigned char key, int mousex, int mousey);

#endif
