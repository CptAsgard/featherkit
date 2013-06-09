#include <framework/glm/glm.hpp>
#include <framework/rendering/renderer2d.h>
#include <framework/rendering/drawable2d.h>
#include <iostream>

namespace windbreeze
{
    void Renderer2D::doStuff()
    {
        glm::vec2 hej(45.0f, 10.0f);
        glm::vec2 hoj(35.0f, 5.0f);

        float angle = glm::radians(90.0f);
        glm::mat2x2 rot(glm::cos(angle), glm::sin(angle), -glm::sin(angle), glm::cos(angle));

        hej = hej + hoj;

        std::cout << "the vector is:\n  [" << hej[0] << ", " << hej[1] << "]\n";
        hej = rot * hej;
        std::cout << "the vector is:\n  [" << hej[0] << ", " << hej[1] << "]\n";
    }

    void Renderer2D::render(const Drawable2D& drawable)
    {
        const std::vector<float>& vertices = drawable.getVerticesTransformed();
        std::cout << "///////////////drawing the drawable!\nIt has " << vertices.size() << " vertices!\n";
        for(uint32_t i = 0; i < vertices.size(); i += 2)
        {
            std::cout << "drawing vertex nr " << i * 0.5 << "\n";
            std::cout << "x position: " << vertices[i] << "\n";
            std::cout << "y position: " << vertices[i + 1] << "\n\n";
        }
        std::cout << "done drawing it!\n\n\n";
    }
}