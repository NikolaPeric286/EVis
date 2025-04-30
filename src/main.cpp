#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ArrowShape.hpp"

int main(){

    

    sf::RenderWindow mainWindow(sf::VideoMode(20*32,20*32 + 100), "test", sf::Style::Close);
    mainWindow.setFramerateLimit(60);
    mainWindow.clear(sf::Color::White);

    ArrowShape test_arrow(200, 20, 50, 50, sf::Color::Red);
  
    test_arrow.setPosition(250,250);
    
    int rotation;
    
    while (mainWindow.isOpen()){
        sf::Event event;
        while (mainWindow.pollEvent(event)){

            
            if (event.type == sf::Event::Closed){
                mainWindow.close();
                
            }
        }
        rotation = (rotation >=360)? 0: rotation + 1; 
        test_arrow.setRotation(rotation);

        

        mainWindow.clear();
        mainWindow.draw(test_arrow);
        mainWindow.display();
    }



    return EXIT_SUCCESS;
}