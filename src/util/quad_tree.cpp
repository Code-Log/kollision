#include "../../include/kollision/quad_tree.h"

namespace kollision {

    QuadTree::QuadTree(unsigned int limit, const RectangleShape& area)
        : m_Shapes(limit), m_Nodes(4), m_Limit(limit), m_Area(area) {}

    QuadTree::~QuadTree() {}

    clstl::vector<Shape*>& QuadTree::getShapes() { return m_Shapes; }

    void QuadTree::divide() {

        RectangleShape nw(
                m_Area.getWidth() / 2.0f,
                m_Area.getHeight() / 2.0f,
                m_Area.getPosition()
        );

        RectangleShape ne(
                m_Area.getWidth() / 2.0f,
                m_Area.getHeight() / 2.0f,
                m_Area.getPosition() + glm::vec2(m_Area.getWidth() / 2.0f, 0)
        );

        RectangleShape sw(
                m_Area.getWidth() / 2.0f,
                m_Area.getHeight() / 2.0f,
                m_Area.getPosition() + glm::vec2(0, m_Area.getHeight() / 2.0f)
        );

        RectangleShape se(
                m_Area.getWidth() / 2.0f,
                m_Area.getHeight() / 2.0f,
                m_Area.getPosition() + glm::vec2(m_Area.getWidth() / 2.0f, m_Area.getHeight() / 2.0f)
        );

        m_Nodes.push_back(QuadTree(m_Limit, nw));
        m_Nodes.push_back(QuadTree(m_Limit, ne));
        m_Nodes.push_back(QuadTree(m_Limit, sw));
        m_Nodes.push_back(QuadTree(m_Limit, se));

    }

    void QuadTree::insert(Shape* shape) {

        if (m_Shapes.size() >= m_Limit) {

            if (m_Nodes.size() == 0)
                divide();

            for (int i = 0; i < m_Nodes.size(); i++) {
                m_Nodes[i].insert(shape);
                for (int j = 0; j < m_Shapes.size(); j++)
                    m_Nodes[i].insert(m_Shapes[j]);
            }

        } else {
            if (m_Area.contains(shape->getMiddle()))
                m_Shapes.push_back(shape);
        }

    }

    clstl::vector<Shape*> QuadTree::query(const RectangleShape& qRect) {

        if (!qRect.intersects(&this->m_Area))
            return clstl::vector<Shape*>();

        clstl::vector<Shape*> result(m_Shapes.size());

        if (m_Nodes.size() == 0) {

            for (int i = 0; i < m_Shapes.size(); i++) {

                if (qRect.contains(m_Shapes[i]->getMiddle()))
                    result.push_back(m_Shapes[i]);

            }

        } else {

            for (int i = 0; i < 4; i++) {

                clstl::vector<Shape*> temp = m_Nodes[i].query(qRect);
                for (int j = 0; j < temp.size(); j++)
                    result.push_back(temp[j]);

            }

        }

        return result;

    }

}