#pragma once
#include <featherkit/rendering/drawable2d.h>
#include <featherkit/rendering/texture.h>

namespace fea
{
    class TileChunk : public Drawable2D
    {
        public:
            TileChunk(uint32_t width, uint32_t height, uint32_t tileWidth, uint32_t tileHeight);
            void setTexture(const Texture& texture);
            const Texture& getTexture() const;
            void setTileTexCoords(uint32_t x, uint32_t y, const glm::vec2& startCoords, const glm::vec2& endCoords);
            void unsetTileTexCoords(uint32_t x, uint32_t y);
            void fillTexCoords(const glm::vec2& startCoords, const glm::vec2& endCoords);
            void clear();
            virtual RenderInfo getRenderInfo() const override;
        private:
            uint32_t getTileIndex(uint32_t x, uint32_t y);
            glm::uvec2 mGridSize;
            const Texture* mTexture;
            std::vector<float> mTexCoords;
            std::vector<float> mTexCoordsCached;
            std::vector<float> mVerticesCached;
            std::vector<float> mVertexColorsCached;
            std::vector<bool> mTilesSet;
    };
    /** @addtogroup Render2D
     *@{
     *  @class TileChunk
     *@}
     ***
     *  @class TileChunk
     *  @brief Drawable2D representing a part of a tile map. 
     *  
     *  Consists of X times Y tiles with vertices describing the tile quads and texture coordinates describing the texture.
     *
     *  TileChunk instances are generated by the TileMap class and usually never created manually.
     ***
     *  @fn TileChunk::TileChunk(uint32_t width, uint32_t height, uint32_t tileWidth, uint32_t tileHeight)
     *  @brief Construct a TileChunk with a specific grid size and tile size.
     *  @param width Width of the tile grid.
     *  @param height Height of the tile grid.
     *  @param tileWidth Width of a single tile.
     *  @param tileHeight Height of a single tile.
     ***
     *  @fn void TileChunk::setTexture(const Texture& texture)
     *  @brief Set the texture to use.
     *
     *  Typically a texture with many tiles.
     *  @param texture Texture
     ***
     *  @fn const std::string& TileChunk::getTexture() const
     *  @brief Get the texture in use.
     *  @return The texture name.
     ***
     *  @fn void TileChunk::setTileTexCoords(uint32_t x, uint32_t y, const glm::vec2& startCoords, const glm::vec2& endCoords)
     *  @brief Set the texture coordinates of a single tile.
     *  
     *  This is how the tiles are set to different images.
     *  @param x X coordinate of the tile to change.
     *  @param y Y coordinate of the tile to change.
     *  @param startCoords Vector containing the upper left coordinates of the texture rectangle to use to display this tile. Given in percent.
     *  @param endCoords Vector containing the bottom right coordinates of the texture rectangle to use to display this tile. Given in percent.
     ***
     *  @fn void TileChunk::unsetTileTexCoords(uint32_t x, uint32_t y)
     *  @brief Set a tile to be empty.
     *
     *  @param x X coordinate of the tile to unset.
     *  @param y Y coordinate of the tile to unset.
     ***
     *  @fn void TileChunk::fillTexCoords(const glm::vec2& startCoords, const glm::vec2& endCoords)
     *  @brief Set all tiles in the chunk to a specific value.
     *  
     *  @param startCoords Vector containing the upper left coordinates of the texture rectangle to use to display the tiles. Given in percent.
     *  @param endCoords Vector containing the bottom right coordinates of the texture rectangle to use to display the tiles. Given in percent.
     ***
     *  @fn void TileChunk::clear()
     *  @brief Clear the chunk of all tiles.
     ***/
}
