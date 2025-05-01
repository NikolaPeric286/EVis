#include "Button.hpp"



Button::Button(const float& x_pos, const float& y_pos, const float& width, const float& height){
    button_rect.setPosition(x_pos, y_pos);
    button_rect.setSize(sf::Vector2f(width,height));
    button_rect.setFillColor(sf::Color{105, 105, 120,255});
    button_rect.setOutlineColor(sf::Color::Black);
    button_rect.setOutlineThickness(4);

    button_text.setString("RESET");
    button_text.setStyle(sf::Text::Style::Bold);
    button_text.setCharacterSize(15);
    button_text.setPosition(x_pos + 25, y_pos + (height/2) - 10);
}

bool Button::onLeftClick(const float& mouse_x, const float& mouse_y ){
    if (button_rect.getGlobalBounds().contains(mouse_x,mouse_y)){
        return true;
    }
    return false;
}

void Button::loadFont(sf::Font& font){
    button_text.setFont(font);
}

void Button::render(sf::RenderWindow& window){
    window.draw(button_rect);
    window.draw(button_text);

}