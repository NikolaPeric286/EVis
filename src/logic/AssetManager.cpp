#include "AssetManager.hpp"


sf::Texture* FileManager::getTexture(std::string&& key){

    sf::Texture* texture_ptr = nullptr;

    if(texture_map.find(key) != texture_map.end()){
        texture_ptr = &texture_map[key];
    }
    else {
        texture_ptr = nullptr;
    }

    return texture_ptr;
    
}

void FileManager::loadFiles(){

    // image_dir -> ../src/assets/images/

    sf::Texture temp_texture;


    if(temp_texture.loadFromFile(image_dir + "negative.png") ){
        std::cout << "Loaded negative.png\n";
        texture_map["negative"] = temp_texture;
    }
    else{
        std::cout << "ERROR --- Failed to load negative.png\n";
    }
    if(temp_texture.loadFromFile(image_dir + "positive.png") ){
        std::cout << "Loaded positive.png\n";
        texture_map["positive"] = temp_texture;
    }
    else{
        std::cout << "ERROR --- Failed to load positive.png\n";
    }

    if(font.loadFromFile("assets/font.ttf") ){
        std::cout << "Loaded font.ttf\n";
    }
    else{
        std::cout << "ERROR --- Failed to load font.ttf\n";
    }

   


}

void FileManager::clear(){
    std::cout << "Clearing Assets\n";
    texture_map.clear();
    font.~Font();
}