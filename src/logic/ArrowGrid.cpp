#include "ArrowGrid.hpp"


void ArrowGrid::update(std::vector<DraggableObject>& charge_vector){
    // This function loops over every arrow and then every charge, 
    // applying the electric field from that charge onto its 
    // vector components

    for(auto it_arrow_y = arrow_vector.begin(); it_arrow_y != arrow_vector.end(); it_arrow_y++){
        
        for(auto it_arrow_x = it_arrow_y->begin() ; it_arrow_x != it_arrow_y->end(); it_arrow_x++){
            it_arrow_x->getXComp() = 0;
            it_arrow_x->getYComp() = 0;
            for(auto it_charge = charge_vector.begin(); it_charge != charge_vector.end(); it_charge++){
                
                long double x_distance = it_arrow_x->getPosition().x -it_charge->getPosition().x;
                long double y_distance = it_arrow_x->getPosition().y - it_charge->getPosition().y;
                
                // this applies a scaling factor to the distances
                // this is mostly to make the difference in opacity 
                // noticable and look good
                x_distance*=.00000003;
                y_distance*=.00000003;
                
                long double distance = std::sqrt( std::pow(x_distance,2) +std::pow(y_distance,2) );
                
                long double angle = std::atan2(y_distance, x_distance);
                
                if(it_charge->positive){
                    it_arrow_x->getXComp() += computeEMag(distance) * std::cos(angle);
                    it_arrow_x->getYComp() += computeEMag(distance) * std::sin(angle);
                }
                else{
                    it_arrow_x->getXComp() -= computeEMag(distance) * std::cos(angle);
                    it_arrow_x->getYComp() -= computeEMag(distance) * std::sin(angle);
                }

                
            
            }
        }
    }

    
}

void ArrowGrid::renderGrid(sf::RenderWindow& window){
    // draws every arrow with the appropriate
    // opacity and direction
    for(auto it_arrow_y = arrow_vector.begin(); it_arrow_y != arrow_vector.end(); it_arrow_y++){
            
        for(auto it_arrow_x = it_arrow_y->begin() ; it_arrow_x != it_arrow_y->end(); it_arrow_x++){
            it_arrow_x->update();
            long double angle_rad = atan2( it_arrow_x->getYComp(), it_arrow_x->getXComp());
            it_arrow_x->setRotation(angle_rad * (180.0 / M_PI));
            window.draw(*it_arrow_x);
        }
    }
}

void ArrowGrid::build(const sf::FloatRect& space_rect, const float& spacing){
    float start_x = space_rect.getPosition().x;
    float start_y = space_rect.getPosition().y;
    float end_x = space_rect.width + start_x;
    float end_y = space_rect.height + start_y;

    int top_padding = 10;
    int bottom_padding = 10;
    int left_padding = 10;
    int right_padding = 10;

    std::vector<ArrowShape> temp_vector;
    for(int y = top_padding; y < end_y-bottom_padding; y+=spacing ){
        temp_vector.clear();
        
        for(int x = left_padding ; x < end_x-right_padding; x+=spacing){
            temp_vector.emplace_back(20,5,10,15, sf::Color{255,255,255,0});
            temp_vector.back().setPosition(start_x + x, start_y + y);
        }
        arrow_vector.push_back(temp_vector);
    }

}


long double ArrowGrid::computeEMag(const long double& distance){
    return (k * q)/(distance*distance);
}
