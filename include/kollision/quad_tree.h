#ifndef KOLLISION_QUAD_TREE_H
#define KOLLISION_QUAD_TREE_H

#include <clstl/vector.h>
#include "rectangle_shape.h"
#include "shape.h"

namespace kollision {

    class QuadTree {
        clstl::vector<QuadTree> m_Nodes;
        RectangleShape m_Area;
        clstl::vector<Shape*> m_Shapes;
        unsigned int m_Limit;

    protected:
        void divide();

    public:
        QuadTree() = default;
        QuadTree(unsigned int, const RectangleShape&);
        ~QuadTree();

        clstl::vector<Shape*>& getShapes();

        clstl::vector<Shape*> query(const RectangleShape&);
        void insert(Shape*);

    };

}

#endif