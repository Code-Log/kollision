#ifndef KOLLISION_RENDERER_H
#define KOLLISION_RENDERER_H

#include "drawable.h"

namespace kollision {

    class Renderer {
    public:
        virtual void init() = 0;
        virtual void start() = 0;
        virtual void renderFrame() = 0;
        virtual void addDrawable(Drawable*) = 0;
        virtual void removeDrawable(Drawable*) = 0;

    };

//    Renderer* currentRenderer;
//    void setRenderer(Renderer*);

};

#endif //KOLLISION_RENDERER_H
