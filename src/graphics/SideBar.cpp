#include "SideBar.hpp"



SideBar::SideBar(const float& window_height){
    

    background_shape.setPosition(0,0);
    background_shape.setFillColor(sf::Color::White);
    background_shape.setOutlineColor(sf::Color::Black);
    background_shape.setOutlineThickness(5);
    background_shape.setSize(sf::Vector2f(250, window_height));

    sensor_stage.setPosition(80,375);
    sensor_stage.setFillColor(sf::Color::Black);
    sensor_stage.setOutlineColor(sf::Color::Red);
    sensor_stage.setOutlineThickness(3);
    sensor_stage.setSize(sf::Vector2f(80, 30));

    Title.setString("Electric Field\n  Visualizer");
    Title.setCharacterSize(20);
    Title.setStyle(sf::Text::Bold);
    Title.setPosition(30, 30);
    Title.setFillColor(sf::Color::Black);
    
    sub_title.setString("Positive \t Negative");
    sub_title.setCharacterSize(10);
    sub_title.setStyle(sf::Text::Bold);
    sub_title.setPosition(40, 150);
    sub_title.setFillColor(sf::Color::Black);

    sensor_text.setString("Test Charge");
    sensor_text.setCharacterSize(10);
    sensor_text.setStyle(sf::Text::Bold);
    sensor_text.setPosition(80, 350);
    sensor_text.setFillColor(sf::Color::Black);

    positive_charge.setScale(.05f, .05f);
    negative_charge.setScale(.05f, .05f);
    positive_charge.setPosition(45, 200);
    negative_charge.setPosition(140, 200);

}

void SideBar::checkClick(const float& mouse_x, const float& mouse_y, std::vector<DraggableObject>& charge_vector){
    if (positive_charge.getGlobalBounds().contains(mouse_x, mouse_y)){
        charge_vector.emplace_back(45,200, pos_texture);
        charge_vector.back().setScale(.05f, .05f);
        charge_vector.back().positive = true;
        charge_vector.back().being_dragged = true;
    }
    if (negative_charge.getGlobalBounds().contains(mouse_x, mouse_y)){
        charge_vector.emplace_back(45,200, neg_texture);
        charge_vector.back().setScale(.05f, .05f);
        charge_vector.back().positive = false;
        charge_vector.back().being_dragged = true;
    }
}

void SideBar::render(sf::RenderWindow& window){
    window.draw(background_shape);
    
    window.draw(Title);
    window.draw(sub_title);
    window.draw(positive_charge);
    window.draw(negative_charge);
    window.draw(sensor_text);
    window.draw(sensor_stage);
}

void SideBar::loadFont(sf::Font& _font){
    font = _font;
    Title.setFont(font);
    sub_title.setFont(font);
    sensor_text.setFont(font);
}

void SideBar::loadPositive(sf::Texture& _texture){
    positive_charge.setTexture(_texture);
    pos_texture = _texture;
}
void SideBar::loadNegative(sf::Texture& _texture){
    negative_charge.setTexture(_texture);
    neg_texture = _texture;
}


