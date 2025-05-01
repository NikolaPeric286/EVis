#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>



class Button{

public:
    
    Button(const float& x_pos, const float& y_pos, const float& width, const float& height);
    bool onLeftClick(const float& mouse_x, const float& mouse_y );
    void render(sf::RenderWindow& window);
    void loadFont(sf::Font& font);
private:
    sf::RectangleShape button_rect;
    sf::Text button_text;
};