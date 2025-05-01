#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "ArrowShape.hpp"
#include "DraggableObject.hpp"



class ArrowGrid{

public:
    ArrowGrid(const ArrowGrid&) = delete;
    ArrowGrid operator=(ArrowGrid&) = delete;

    static ArrowGrid& getInstance(){
        static ArrowGrid arrowGrid_instance = ArrowGrid();
        return arrowGrid_instance;
    }
    void build(const sf::FloatRect& space_rect, const float& spacing);
    void update(std::vector<DraggableObject>& charge_vector);

    void renderGrid(sf::RenderWindow& window);
private:
    ArrowGrid(){}
    
    const long int k = 8987500000;
    const long double q = .000000000000000000160217;
    long double computeEMag(const long double& distance);
    std::vector<std::vector<ArrowShape>> arrow_vector;

};
