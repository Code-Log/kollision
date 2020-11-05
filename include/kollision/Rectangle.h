#ifndef KOLLISION_RECTANGLE_H
#define KOLLISION_RECTANGLE_H

#include "drawable.h"

namespace kollision {

    class Rectangle : public Drawable {

    public:
        virtual void setWidth(const double&) = 0;
        virtual void setHeight(const double&) = 0;

        virtual const double& getWidth() const = 0;
        virtual const double& getHeight() const = 0;

    };

};

#endif //KOLLISION_RECTANGLE_H
