#include "ArrowShape.hpp"
ArrowShape::ArrowShape(float _shaft_length, float _shaftThickness,float _head_length, float _headWidth,sf::Color _color, bool _center_pivot)
: arrow_color(_color),
  shaft_length(_shaft_length), 
  shaftThickness(_shaftThickness), 
  head_length(_head_length), 
  head_width(_headWidth), 
  scale_factor(1),
  x_component(0),
  y_component(0),
  center_pivot(_center_pivot){
    
    arrow_array.setPrimitiveType(sf::Triangles);
    
    update();
}

void ArrowShape::scale(const float& _scale_factor){
    scale_factor = _scale_factor;
    update();
}

void ArrowShape::update(){
    // this function ends up handling the actual geometry of the arrow/
    // dont bother too much trying to understand where the points go
    // the parameters are the important factors as well as the scale
    // factor

    

    shaftThickness *= scale_factor;
    shaft_length *= scale_factor;
    head_length *= scale_factor;
    head_width *= scale_factor;

    float halfShaft = shaftThickness / 2.f;
    float halfHead = head_width / 2.f;

    arrow_array.clear();
    // Shaft (2 triangles)
    arrow_array.append({ {0.f, -halfShaft}, arrow_color });
    arrow_array.append({ {shaft_length, -halfShaft}, arrow_color });
    arrow_array.append({ {shaft_length, halfShaft}, arrow_color });

    arrow_array.append({ {0.f, -halfShaft}, arrow_color });
    arrow_array.append({ {shaft_length, halfShaft}, arrow_color });
    arrow_array.append({ {0.f, halfShaft}, arrow_color });

    // Head (1 triangle)
    arrow_array.append({ {shaft_length, -halfHead}, arrow_color });
    arrow_array.append({ {shaft_length + head_length, 0.f}, arrow_color });
    arrow_array.append({ {shaft_length, halfHead}, arrow_color });
    
    

    if (center_pivot){
        //sets origin to the middle of the arrow so it can be
        //properly placed and rotated later
        int opacity = magnitudeToOpacity(x_component, y_component);
        setOpacity(opacity);

        float total_length = shaft_length + head_length;
        setOrigin(total_length/2.f, 0);
    }
    else{
        setOpacity(100);
        setOrigin(0,0);
        
    }
}

void ArrowShape::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform(); // Apply transformation
    target.draw(arrow_array, states);
}

int ArrowShape::magnitudeToOpacity(const float& x_comp, const float& y_comp){
    float magnitude = std::sqrt( (x_comp * x_comp) + (y_comp * y_comp));
    int opacity = 100*(1 - pow(2.718f , -.0025 * magnitude));
    return opacity;
}

void ArrowShape::setColor(sf::Color color){
    arrow_color = color;

    for(size_t i = 0; i < arrow_array.getVertexCount(); i++){
        arrow_array[i].color = color;
    }

}

void ArrowShape::setOpacity(const unsigned int& opacity){
    int opacity_val = 1;
    if(opacity > 0){
        opacity_val = 255/ (100/((opacity > 100)? 100: opacity));
    }
    
    setColor(sf::Color{arrow_color.r, arrow_color.g, arrow_color.b, opacity_val});
}



