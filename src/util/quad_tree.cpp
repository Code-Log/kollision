#include "quad_tree.h"

namespace kollision {

    QuadTree::QuadTree(const clstl::vector<Shape*>& shapes, unsigned int limit)
        : m_Shapes(shapes), m_Nodes(4), m_Limit(limit) {}
    QuadTree::~QuadTree() {}

    void QuadTree::divide() {}

    void QuadTree::insert(Shape* shape) {

        m_Shapes.push_back(shape);

        if (m_Shapes.size() >= m_Limit) {
            divide();
        }

    }

    clstl::vector<Shape*> QuadTree::query(const RectangleShape&) { return {}; }

}