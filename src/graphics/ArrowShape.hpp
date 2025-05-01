#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <cmath>


class ArrowShape : public sf::Drawable, public sf::Transformable{

public:
    ArrowShape(float shaft_length = 100.f, float shaftThickness = 20.f, float head_length = 40.f, float headWidth = 40.f, sf::Color color = sf::Color::Green, bool _center_pivot = true);
    
    // updates arrow points based off of current parameters
    void update();
    // sets color of arrow
    void setColor(sf::Color color);
    // scales arrow by given factor
    void scale(const float& scale_factor);

    void setOpacity(const unsigned int& opacity);

    long double& getXComp(){return x_component;}
    long double& getYComp(){return y_component;}
    
protected:
    float shaft_length;
private:
    bool center_pivot;
    sf::Color arrow_color;
    sf::VertexArray arrow_array;
    
    float shaftThickness;
    float head_length;
    float head_width;
    float scale_factor;
    

    // E vector components
    long double x_component;
    long double y_component;

    int magnitudeToOpacity(const float& x_comp, const float& y_comp);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
};