#include "ArrowShape.hpp"
ArrowShape::ArrowShape(float _shaft_length, float _shaftThickness,float _head_length, float _headWidth,sf::Color _color)
: arrow_color(_color),
  shaft_length(_shaft_length), 
  shaftThickness(_shaftThickness), 
  head_length(_head_length), 
  headWidth(_headWidth), 
  color(_color),
  scale_factor(1){
    
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
    headWidth *= scale_factor;

    float halfShaft = shaftThickness / 2.f;
    float halfHead = headWidth / 2.f;

    arrow_array.clear();
    // Shaft (2 triangles)
    arrow_array.append({ {0.f, -halfShaft}, color });
    arrow_array.append({ {shaft_length, -halfShaft}, color });
    arrow_array.append({ {shaft_length, halfShaft}, color });

    arrow_array.append({ {0.f, -halfShaft}, color });
    arrow_array.append({ {shaft_length, halfShaft}, color });
    arrow_array.append({ {0.f, halfShaft}, color });

    // Head (1 triangle)
    arrow_array.append({ {shaft_length, -halfHead}, color });
    arrow_array.append({ {shaft_length + head_length, 0.f}, color });
    arrow_array.append({ {shaft_length, halfHead}, color });

    //sets origin to the middle of the arrow so it can be
    //properly placed and rotated later
    float total_length = shaft_length + head_length;
    setOrigin(total_length/2.f, 0);
}

void ArrowShape::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform(); // Apply transformation
    target.draw(arrow_array, states);
}

void ArrowShape::setColor(sf::Color color){
    arrow_color = color;

    for(size_t i = 0; i < arrow_array.getVertexCount(); i++){
        arrow_array[i].color = color;
    }

}



