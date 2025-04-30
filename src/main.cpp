#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ArrowShape.hpp"
#include "DraggableObject.hpp"

int main(){

    

    sf::RenderWindow mainWindow(sf::VideoMode(20*32,20*32 + 100), "test", sf::Style::Close);
    mainWindow.setFramerateLimit(60);
    mainWindow.clear(sf::Color::White);

    ArrowShape test_arrow(200, 20, 50, 50, sf::Color::Red);
  
    test_arrow.setPosition(250,250);
    
    sf::Texture test_texture;
    if (!test_texture.loadFromFile("/home/nikolaperic/vscodeProjectFolders/EVis/src/assets/images/mine.png")){
        std::cout << "ERROR!\n";
    }

    std::cout << "Texture size: " << test_texture.getSize().x << " x " << test_texture.getSize().y << "\n";
    DraggableObject test_object(100, 100 ,test_texture);
   
    mainWindow.draw(test_object);
    // test_object.setTexture(test_texture);
    int rotation;
    
    while (mainWindow.isOpen()){
        sf::Event event;
        while (mainWindow.pollEvent(event)){

            
            if (event.type == sf::Event::Closed){
                mainWindow.close();
                
            }
            if (event.type == sf::Event::MouseButtonPressed){

                if (event.mouseButton.button == sf::Mouse::Left){
                    test_object.onLeftClickPress(event.mouseButton.x, event.mouseButton.y);
                }
            }
            if(event.type == sf::Event::MouseButtonReleased){
                if(event.mouseButton.button == sf::Mouse::Left){
                    test_object.onLeftClickRelease();
                }
            }
        }


        if( test_object.being_dragged){
            test_object.drag(sf::Mouse::getPosition(mainWindow).x, sf::Mouse::getPosition(mainWindow).y);
        }


        rotation = (rotation >=360)? 0: rotation + 1; 
        test_arrow.setRotation(rotation);

        mainWindow.clear(sf::Color::White);
        mainWindow.draw(test_object);
        
        mainWindow.draw(test_arrow);
        mainWindow.display();
    }



    return EXIT_SUCCESS;
}