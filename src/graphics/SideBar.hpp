#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "DraggableObject.hpp"


class SideBar{

public:
    SideBar(const float& window_height);
    void loadFont(sf::Font& _font);
    void loadPositive(sf::Texture& _texture);
    void loadNegative(sf::Texture& _texture);
    void render(sf::RenderWindow& window);
    void checkClick(const float& mouse_x, const float& mouse_y, std::vector<DraggableObject>& charge_vector);
private:
    sf::Font font;
    sf::RectangleShape background_shape;
    sf::RectangleShape sensor_stage;
    sf::Text Title;
    sf::Text sub_title;
    sf::Text sensor_text;
    sf::Sprite positive_charge;
    sf::Sprite negative_charge;
    sf::Texture pos_texture;
    sf::Texture neg_texture;
    
    


};