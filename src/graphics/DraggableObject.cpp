#include "DraggableObject.hpp"


DraggableObject::DraggableObject(const float& x_pos, const float& y_pos, sf::Texture& _texture):
being_dragged(false){
    setTexture(_texture);
    sf::FloatRect local_rect = getLocalBounds();
    
    setOrigin(local_rect.width/2.f , local_rect.height/2.f);
    setPosition(x_pos, y_pos);
   
    
    last_pos = getPosition();
    
    
}

void DraggableObject::onLeftClickPress(const float& mouse_x, const float& mouse_y){
    sf::FloatRect bounds_rect = getGlobalBounds();
    if (bounds_rect.contains(mouse_x, mouse_y)){
        std::cout << "object clicked\n";
        being_dragged = true;
    }
}   

void DraggableObject::drag(const float& x, const float& y){
    float x_change = x - last_pos.x;
    float y_change = y - last_pos.y;

    setPosition(getPosition().x + x_change, getPosition().y + y_change);
    last_pos = sf::Vector2f(x,y);
}

void DraggableObject::onLeftClickRelease(){
    being_dragged = false;
}
