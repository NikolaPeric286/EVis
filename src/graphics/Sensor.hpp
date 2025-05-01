#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "DraggableObject.hpp"
#include "ArrowShape.hpp"


class Sensor :public ArrowShape{

public:
    Sensor(const float& x_pos, const float& y_pos);
    void updateSensor(std::vector<DraggableObject>& charge_vector) ;
    void onLeftClickPress(const float& mouse_x, const float& mouse_y);
    void onLeftClickRelease();
    void drag(const float& x, const float& y);
    void setLength(const float& _length) { shaft_length = _length;} 
    void reset();
    bool being_dragged;
    bool is_new;
private:
    sf::Vector2f last_pos;
    const unsigned long long int k = 8987500000;
    const long double q = .000000000000000000160217;
    long double computeEMag(const long double& distance);
};