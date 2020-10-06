#ifndef KOLLISION_DRAWABLECONTEXT_H
#define KOLLISION_DRAWABLECONTEXT_H
#pragma once

#include "drawable.h"
#include <clstl/vector.h>

namespace kollision {
    class DrawableContext {

    private:
        clstl::vector<Drawable*> m_Drawables;
        DrawableContext();
    public:

        static DrawableContext& getInstance();

        clstl::vector<Drawable*>& getDrawables();

        void addDrawable(Drawable* drawable);
        void removeDrawable(Drawable* drawable);

    };
}


#endif //KOLLISION_DRAWABLECONTEXT_H
