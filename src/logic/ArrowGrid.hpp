#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "ArrowShape.hpp"
#include "DraggableObject.hpp"


//singleton class
class ArrowGrid{

public:
    ArrowGrid(const ArrowGrid&) = delete;
    ArrowGrid operator=(ArrowGrid&) = delete;

    static ArrowGrid& getInstance(){
        static ArrowGrid arrowGrid_instance = ArrowGrid();
        return arrowGrid_instance;
    }
    //initalises grid of arrows
    void build(const sf::FloatRect& space_rect, const float& spacing);
    //upates arrow values based off of charges
    void update(std::vector<DraggableObject>& charge_vector);
    //renders grid of arrows
    void renderGrid(sf::RenderWindow& window);
private:
    ArrowGrid(){}
    // constants
    const unsigned long long int k = 8987500000;
    const  long double q = .000000000000000000160217;


    long double computeEMag(const long double& distance);
    std::vector<std::vector<ArrowShape>> arrow_vector;

};
