#include "MapColliderManager.hpp"
#include "SFML/Graphics/Rect.hpp"

bool MapCollider::EntityWithTilemapCollision() {
    sf::FloatRect entityBounds = entity.getEntityBounds();

    sf::Vector2f pos = entityBounds.position;
    sf::Vector2f size = entityBounds.size;

    int left   = static_cast<int>(pos.x) / 16;
    int right  = static_cast<int>(pos.x + size.x) / 16;
    int top    = static_cast<int>(pos.y) / 16;
    int bottom = static_cast<int>(pos.y + size.y) / 16;

    left = std::max(0, left);
    top = std::max(0, top);
    right = std::min(39, right);
    bottom = std::min(29, bottom);

    for (int x = left; x <= right; ++x) {
        for (int y = top; y <= bottom; ++y) {
            tileLayer tileMask = tilemap.getMask(x, y);
            EntityCollisionLayer asLayer = static_cast<EntityCollisionLayer>(tileMask);

            std::vector<EntityCollisionLayer> maskList = entity.getMask();

            if (std::find(maskList.begin(), maskList.end(), asLayer) != maskList.end()) {
                sf::FloatRect tileBounds(sf::Vector2f(x * 16.f, y * 16.f), sf::Vector2f(16.f, 16.f));

                if (entityBounds.findIntersection(tileBounds)) {
                    return true; // 💥 collision!
                }
            }
        }
    }

    return false; // no collision
}

