#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <unordered_map>
#include <string>
#include <fstream>

// singleton class
class FileManager{

public:
    //setup for singleton
    FileManager(const FileManager&) = delete;
    FileManager operator=(FileManager& ) = delete;
    static FileManager& getInstance(){
        static FileManager AssetManager_instance = FileManager();
        return AssetManager_instance;
    }
    // -------------------
    void clear();
    void loadFiles(); 
    sf::Texture* getTexture(std::string&& key);
    sf::Font& getFont() { return font;}

private:
    std::string image_dir;
    std::unordered_map<std::string, sf::Texture> texture_map;
    sf::Font font;


    FileManager() : image_dir("assets/images/") { }
};