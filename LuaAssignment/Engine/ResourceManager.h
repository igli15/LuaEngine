//
// Created by Igli milaqi on 30/12/2018.
//

#ifndef LUAASSIGNMENT_RESOURCEMANAGER_H
#define LUAASSIGNMENT_RESOURCEMANAGER_H


#include <map>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"


namespace Engine {
    class ResourceManager {


    private:
        std::map<std::string, sf::Texture *> textureMap;
        std::map<std::string, sf::Font *> fontMap;
        std::map<std::string, sf::SoundBuffer *> soundBufferMap;
        std::map<std::string, sf::Music *> musicMap;

    public:
        void LoadTexture(const std::string &path, const std::string &tag) ;

        void LoadFont(const std::string &path, const std::string &tag) ;

        void LoadSoundBuffer(const std::string &path, const std::string &tag) ;

        void LoadMusic(const std::string &path, const std::string &tag) ;

        sf::Texture *GetTexture(const std::string &tag) ;

        sf::Font *GetFont(const std::string &tag) ;

        sf::SoundBuffer *GetSoundBuffer(const std::string &tag) ;

        sf::Music *GetMusic(const std::string &tag) ;

    };
}


#endif //LUAASSIGNMENT_RESOURCEMANAGER_H
