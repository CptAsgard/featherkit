#include <framework/util/rendering/sfml2dbackend.h>
#include <iostream>

namespace windbreeze
{
    void Sfml2DBackend::setup()
    {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glLoadIdentity();
        gluOrtho2D(0.0f, 1366.0f, 768.0f, 0.0f);
    }

    void Sfml2DBackend::destroy()
    {
    }

    void Sfml2DBackend::clear()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Sfml2DBackend::render(RenderData renderData)
    {
        std::vector<float> vertices = renderData.vertices;
        glm::vec2 vertex;
        glm::vec2 halfViewSize = (glm::vec2)(viewport.getSize()) * 0.5f;
        glm::mat2x2 rotation = glm::inverse(viewport.getCamera().getTransformation());

        glBegin(GL_QUADS);
        for(uint32_t i = 0; i < vertices.size(); i += 2)
        {
            vertex = glm::vec2(vertices[i], vertices[i + 1]);
            vertex = rotation * (viewport.getCamera().getZoom() * (vertex - viewport.getCamera().getPosition())) + halfViewSize;
            glVertex2f(vertex.x, vertex.y);
        }
        glEnd();
    }
}
