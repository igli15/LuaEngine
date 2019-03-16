//
// Created by Igli milaqi on 30/12/2018.
//

#include "ResourceManager.h"
#include <iostream>

sf::Texture* Engine::ResourceManager::LoadTexture(const std::string &path, const std::string &tag)
{
    sf::Texture* texture = new sf::Texture();
    if(!texture->loadFromFile(path))
    {
        //errorHandle
        std::cout<<"Error Loading Texture"<<std::endl;
        texture->loadFromFile("ErrorTexture");
        throw;
    }

    textureMap[tag] = texture;
    return  texture;
}

sf::Font* Engine::ResourceManager::LoadFont(const std::string &path, const std::string &tag)
{
    sf::Font* font = new sf::Font();

    if(!font->loadFromFile(path))
    {
        //errorHandle
        throw;
    }

    fontMap[tag] = font;
    return font;
}

sf::SoundBuffer* Engine::ResourceManager::LoadSoundBuffer(const std::string &path, const std::string &tag)
{
    sf::SoundBuffer* buffer = new sf::SoundBuffer();

    if(!buffer->loadFromFile(path))
    {
        throw;
    }

    soundBufferMap[tag] = buffer;
    return buffer;
}

sf::Music* Engine::ResourceManager::LoadMusic(const std::string &path, const std::string &tag)
{
    sf::Music* music = new sf::Music();

    if(!music->openFromFile(path))
    {
        throw;
    }

    musicMap[tag] = music;
    return music;
}

sf::Texture *Engine::ResourceManager::GetTexture(const std::string &tag)
{
    if(textureMap.find(tag) == textureMap.end())
    {
        std::cout<<"There is no Texture resource with that name!"<<std::endl;

        return GetTexture("ErrorTexture");
    }

    return textureMap[tag];
}

sf::Font *Engine::ResourceManager::GetFont(const std::string &tag)
{
    if(fontMap.find(tag) == fontMap.end())
    {
        std::cout<<"There is no Font resource with that name!"<<std::endl;
        return nullptr ;
    }

    return fontMap[tag];
}

sf::SoundBuffer *Engine::ResourceManager::GetSoundBuffer(const std::string &tag)
{
    if(soundBufferMap.find(tag) == soundBufferMap.end())
    {
        std::cout<<"There is no Sound Buffer resource with that name!"<<std::endl;
        return nullptr ;
    }

    return soundBufferMap[tag];
}

sf::Music *Engine::ResourceManager::GetMusic(const std::string &tag)
{
    if(musicMap.find(tag) == musicMap.end())
    {
        std::cout<<"There is no Music resource with that name!"<<std::endl;
        return nullptr ;
    }

    return musicMap[tag];
}



