#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>


class ArrowShape : public sf::Drawable, public sf::Transformable{

public:
    ArrowShape(float shaft_length = 100.f, float shaftThickness = 20.f, float head_length = 40.f, float headWidth = 40.f, sf::Color color = sf::Color::Green);
    
    // updates arrow points based off of current parameters
    void update();
    // sets color of arrow
    void setColor(sf::Color color);
    // scales arrow by given factor
    void scale(const float& scale_factor);

protected:

private:
    sf::Color arrow_color;
    sf::VertexArray arrow_array;
    float shaft_length;
    float shaftThickness;
    float head_length;
    float headWidth;
    float scale_factor;
    sf::Color color;


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
};