#include "Sensor.hpp"



Sensor::Sensor(const float& x_pos, const float& y_pos) : ArrowShape(20,5,10,10, sf::Color::Yellow, false), being_dragged(false), is_new(true){
    setPosition(x_pos, y_pos);
    last_pos = getPosition();
    
}

void Sensor::updateSensor(std::vector<DraggableObject>& charge_vector){
    // the code here is very messy but pretty much the same principles as the
    // update function in ArrowShape
    // The arrow system could probably be redone to allow this to inherit from the arrow
    // and also DraggableObject
    // 

    
    getXComp() = 0;
    getYComp() = 0;
    for(auto it_charge = charge_vector.begin(); it_charge != charge_vector.end(); it_charge++){
                
        long double x_distance = getPosition().x - it_charge->getPosition().x;
        long double y_distance = getPosition().y - it_charge->getPosition().y;
        
        // this applies a scaling factor to the distances
        // this is mostly to make the difference in opacity 
        // noticable and look good
        x_distance*=.00000003;
        y_distance*=.00000003;
        
        long double distance = std::sqrt( std::pow(x_distance,2) +std::pow(y_distance,2) );
        
        long double angle = std::atan2(y_distance, x_distance);
        
        if(it_charge->positive){
            getXComp() += computeEMag(distance) * std::cos(angle);
            getYComp() += computeEMag(distance) * std::sin(angle);
        }
        else{
            getXComp() -= computeEMag(distance) * std::cos(angle);
            getYComp() -= computeEMag(distance) * std::sin(angle);
        }

        
    
    }
    long double magnitude = std::sqrt( std::pow(getXComp(),2)+ std::pow(getYComp(), 2));
    
    setLength(magnitude/2);
    long double angle_rad = atan2( getYComp(), getXComp());
    setRotation(angle_rad * (180.0 / M_PI));
}


long double Sensor::computeEMag(const long double& distance){
    return (k * q)/(distance*distance);
}


void Sensor::onLeftClickPress(const float& mouse_x, const float& mouse_y){
    float x = getPosition().x;
    float y = getPosition().y;
    if(mouse_x > x -25 && mouse_x < x +25 && mouse_y > y-25 && mouse_y < y +25){
        being_dragged = true;
    }
}   

void Sensor::drag(const float& x, const float& y){
    float x_change = x - last_pos.x;
    float y_change = y - last_pos.y;

    setPosition(getPosition().x + x_change, getPosition().y + y_change);
    last_pos = sf::Vector2f(x,y);
}

void Sensor::onLeftClickRelease(){
    being_dragged = false;
    is_new = false;
}

void Sensor::reset(){
    setPosition(105,390);
    is_new = true;
    being_dragged = false;
    setRotation(0);
    setLength(20);
    update();
    last_pos = getPosition();
}