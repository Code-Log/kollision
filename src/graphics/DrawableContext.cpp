#include "DrawableContext.h"

namespace kollision {

    DrawableContext::DrawableContext() : m_Drawables(10) { }

    DrawableContext& DrawableContext::getInstance() {
        static auto* instance = new DrawableContext();

        if (instance == nullptr)
            instance = new DrawableContext();
        return *instance;
    }

    clstl::vector<Drawable*>& DrawableContext::getDrawables() { return m_Drawables; }
    void DrawableContext::addDrawable(Drawable* drawable) { m_Drawables.push_back(drawable); }
    void DrawableContext::removeDrawable(Drawable *drawable) {
        for (unsigned int i = m_Drawables.size() - 1; i >= 0; i--) {
            if (m_Drawables[i] == drawable) {
                m_Drawables.erase(i, 1);
            }
        }
    }

}