#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "ArrowShape.hpp"
#include "DraggableObject.hpp"
#include "SideBar.hpp"
#include "ArrowGrid.hpp"
#include "AssetManager.hpp"
#include "Sensor.hpp"
#include "Button.hpp"



int main(){
   
    //Loads files, textures and fonts
    FileManager::getInstance().loadFiles();


    //initialises window
    sf::RenderWindow mainWindow(sf::VideoMode(1000,800), "Electric Field Visualizer", sf::Style::Close);
    mainWindow.setFramerateLimit(60);
    mainWindow.clear(sf::Color::White);

    
    //initialises side bar
    SideBar side_bar(mainWindow.getSize().y);
    side_bar.loadFont(FileManager::getInstance().getFont());
    side_bar.loadNegative(*FileManager::getInstance().getTexture("negative"));
    side_bar.loadPositive(*FileManager::getInstance().getTexture("positive"));
    
    //initialises reset button
    Button resetButton(70,450,100,50);
    resetButton.loadFont(FileManager::getInstance().getFont());
    

    //this vector keeps track of all the chargers/
    //on the plane
    std::vector<DraggableObject> charge_vector;
    DraggableObject* dragged_object = nullptr;

    //initalises the test charge arrow
    Sensor test_charge(105,390);
    
    //initialises grid of arrows
    ArrowGrid::getInstance().build(sf::FloatRect(250,0,mainWindow.getSize().x - 250, mainWindow.getSize().y), 50);
    
    while (mainWindow.isOpen()){

        sf::Event event;
        while (mainWindow.pollEvent(event)){

            
            if (event.type == sf::Event::Closed){
                std::cout << "Window Closing\n";
                FileManager::getInstance().clear(); // deletes textures
                mainWindow.close();
                return EXIT_SUCCESS;
            }
            else if (event.type == sf::Event::MouseButtonPressed){

                if (event.mouseButton.button == sf::Mouse::Left){
                    
                    // checks click for charges on the side bar, adds a new charge if user
                    // picks one up
                    side_bar.checkClick(event.mouseButton.x, event.mouseButton.y, charge_vector);

                    // checks all charges if they where pressed and sets them to be 
                    // dragged if they are
                    for(auto it = charge_vector.begin(); it != charge_vector.end(); it++){
                        it->onLeftClickPress(event.mouseButton.x, event.mouseButton.y);
                        if(it->being_dragged){
                            dragged_object = &(*it);
                            goto click_break;
                        }
                    }
                    //checks click for test charge
                    test_charge.onLeftClickPress(event.mouseButton.x, event.mouseButton.y);
                    
                    // reset button activation
                    if(resetButton.onLeftClick(event.mouseButton.x, event.mouseButton.y)){
                        charge_vector.clear();
                        test_charge.reset();
                    }

                    

                    
                    click_break:
                }
            }
            // releases dragged objects
            else if(event.type == sf::Event::MouseButtonReleased){
                if(event.mouseButton.button == sf::Mouse::Left){
                    if(event.mouseButton.button == sf::Mouse::Left){
                        if(dragged_object != nullptr){
                            dragged_object->onLeftClickRelease();
                            dragged_object = nullptr;
                        }
                        if(test_charge.being_dragged){
                            test_charge.onLeftClickRelease();
                        }
                    }
                }
            }
        }

        
        if(dragged_object!= nullptr && dragged_object->being_dragged){
            dragged_object->drag(sf::Mouse::getPosition(mainWindow).x, sf::Mouse::getPosition(mainWindow).y);
        }

        if(test_charge.being_dragged ){
            test_charge.drag(sf::Mouse::getPosition(mainWindow).x, sf::Mouse::getPosition(mainWindow).y);
        }
        
        // checks if any charge is out side of the plane,
        // removes it if it is
        for(size_t i = 0; i < charge_vector.size(); i++){
            float x = charge_vector.at(i).getPosition().x;
            float y = charge_vector.at(i).getPosition().y;
            if(!charge_vector.at(i).being_dragged && (x < 250 || x+5 > mainWindow.getSize().x || y < 0 || y+5 > mainWindow.getSize().y)){
                charge_vector.erase(charge_vector.begin() + i);
            }
        }

        
        mainWindow.clear(sf::Color{47, 44, 48, 255});
        
        // if the test charge has already been picked up at least once/
        // it is activated to respond to the field
        if(!test_charge.is_new){
            test_charge.updateSensor(charge_vector);
            test_charge.update();
            mainWindow.draw(test_charge);
        }
        
        side_bar.render(mainWindow);
        resetButton.render(mainWindow);
        ArrowGrid::getInstance().update(charge_vector);
        ArrowGrid::getInstance().renderGrid(mainWindow);
        
        for(auto it = charge_vector.begin(); it != charge_vector.end(); it++){
            mainWindow.draw(*it);
        }
        
        //draws test charge over side bar if it is new
        if(test_charge.is_new){    
            mainWindow.draw(test_charge);
        }

        // resets test charge back to its spot if it goes out of bounds
        if(!test_charge.is_new && !test_charge.being_dragged ){
            float x = test_charge.getPosition().x;
            float y = test_charge.getPosition().y;
            if(x < 250 || x > mainWindow.getSize().x || y < 0 || y > mainWindow.getSize().y){
                test_charge.reset();
            }
        }
        
        
        
        mainWindow.display();
    }



    return EXIT_SUCCESS;
}


