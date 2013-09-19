#include <featherkit/rendering/repeatedquad.h>

namespace fea
{
    RepeatedQuad::RepeatedQuad() : AnimatedQuad() 
    {
        tileSize = getSize();
    }

    RepeatedQuad::RepeatedQuad(float w, float h) : AnimatedQuad(w, h) 
    {
        tileSize = getSize();
    }

    RepeatedQuad::RepeatedQuad(const glm::vec2& size) : AnimatedQuad(size)
    {
        tileSize = getSize();
    }

    void RepeatedQuad::setTileSize(float w, float h)
    {
        tileSize = glm::vec2(w, h);
    }

    void RepeatedQuad::setTileSize(const glm::vec2& size)
    {
        tileSize = size;
    }

    const glm::vec2& RepeatedQuad::getTileSize()
    {
        return tileSize;
    }
    
    void RepeatedQuad::setScrollSpeed(float xSpeed, float ySpeed) //FIX
    {
        scrollSpeed = glm::vec2(xSpeed, ySpeed);
    }
    
    void RepeatedQuad::setScrollSpeed(const glm::vec2& speed)
    {
        scrollSpeed = speed;
    }

    const glm::vec2& RepeatedQuad::getScrollSpeed() const
    {
        return scrollSpeed;
    }

    RenderInfo RepeatedQuad::getRenderInfo() const
    {
        RenderInfo temp = AnimatedQuad::getRenderInfo();
        std::hash<std::string> stringHasher;

        temp.vertexAttributes.push_back(VertexAttribute(stringHasher("texcoords"), 0, &texCoords[0]));

        return temp;
    }
    
    /*
    void RepeatedQuad::getRenderData(RenderData& renderData, uint32_t time) const
    {
        AnimatedQuad::getRenderData(renderData, time);

        //glm::vec2 texMax = getSize() / tileSize;
        //float texMaxX = texMax.x;
        //float texMaxY = texMax.y;

        \*
        renderData.texCoords =  {0.0f, 0.0f,
                                 0.0f, texMaxY,
                                 texMaxX, texMaxY,
                                 texMaxX, 0.0f};*\

        renderData.textureScroll = scrollSpeed * (float)time;

        glm::vec2 hej = getSize() / tileSize;
        for(uint32_t i = 0; i < 12; i += 2)
        {
            glm::vec2 newCoords = glm::vec2(renderData.texCoords[i], renderData.texCoords[i+1]) * hej;
            renderData.texCoords[i] = newCoords.x;
            renderData.texCoords[i+1] = newCoords.y;
        }
        //currentScroll = currentScroll + scrollSpeed; must be done later
    }*/
}
