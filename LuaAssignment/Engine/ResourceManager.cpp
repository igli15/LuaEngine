//
// Created by Igli milaqi on 30/12/2018.
//

#include "ResourceManager.h"
#include <iostream>

void Engine::ResourceManager::LoadTexture(const std::string &path, const std::string &tag)
{
    sf::Texture* texture = new sf::Texture();
    if(!texture->loadFromFile(path))
    {
        //errorHandle
        std::cout<<"Error Loading Texture"<<std::endl;
        return;
    }

    textureMap[tag] = texture;
}

void Engine::ResourceManager::LoadFont(const std::string &path, const std::string &tag)
{
    sf::Font* font = new sf::Font();

    if(!font->loadFromFile(path))
    {
        //errorHandle
        return;
    }

    fontMap[tag] = font;
}

void Engine::ResourceManager::LoadSoundBuffer(const std::string &path, const std::string &tag)
{
    sf::SoundBuffer* buffer = new sf::SoundBuffer();

    if(!buffer->loadFromFile(path))
    {
        return;
    }

    soundBufferMap[tag] = buffer;
}

void Engine::ResourceManager::LoadMusic(const std::string &path, const std::string &tag)
{
    sf::Music* music = new sf::Music();

    if(!music->openFromFile(path))
    {
        return;
    }

    musicMap[tag] = music;
}

sf::Texture *Engine::ResourceManager::GetTexture(const std::string &tag)
{
    if(textureMap.find(tag) == textureMap.end())
    {
        std::cout<<"There is no Texture resource with that name!"<<std::endl;
        return nullptr ;
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



