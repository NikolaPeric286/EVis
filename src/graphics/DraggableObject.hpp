#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>



class DraggableObject : public sf::Sprite{

public:
    DraggableObject(const float& x_pos, const float& y_pos , sf::Texture& _texture);
    void onLeftClickPress(const float& mouse_x, const float& mouse_y);
    void onLeftClickRelease();
    void drag(const float& x, const float& y);
    bool being_dragged;
protected:
private:
    sf::Vector2f last_pos;
    
};