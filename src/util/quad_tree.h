#ifndef KOLLISION_QUAD_TREE_H
#define KOLLISION_QUAD_TREE_H

#include <clstl/vector.h>
#include "../shape/rectangle_shape.h"
#include "../shape/shape.h"

namespace kollision {

    class QuadTree {
        clstl::vector<QuadTree> m_Nodes;
        clstl::vector<Shape*> m_Shapes;
        unsigned int m_Limit;

    protected:
        void divide();

    public:

        QuadTree(const clstl::vector<Shape*>&, unsigned int);
        ~QuadTree();

        clstl::vector<Shape*> query(const RectangleShape&);
        void insert(Shape*);

    };

}

#endif