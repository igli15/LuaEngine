//
// Created by Igli milaqi on 22/10/2018.
//

#include "AudioSource.h"

void Engine::AudioSource::PlayOneShotSound(const std::string& soundTag)
{
    m_soundMap[soundTag]->setVolume(m_volume);
    m_soundMap[soundTag]->play();
}

void Engine::AudioSource::PlayMusic()
{
    m_music->setVolume(m_volume);
    m_music->play();
}

void Engine::AudioSource::PauseMusic()
{
    m_music->pause();
}

void Engine::AudioSource::StopMusic()
{
    m_music->stop();
}

Engine::AudioSource::AudioSource()
{
    m_music = new sf::Music();
}

Engine::AudioSource::~AudioSource()
{
    for (int i = 0 ; i  < m_soundVector.size(); ++i)
    {
        delete m_soundVector[i];
        m_soundVector.erase(m_soundVector.begin() + i);
    }

    delete m_music;
    m_music = nullptr;
}


void Engine::AudioSource::LoadSound(const std::string &filename,const std::string &soundTag)
{
    sf::SoundBuffer* buffer = new sf::SoundBuffer();
    buffer->loadFromFile(filename);
    m_soundVector.push_back(buffer);

    sf::Sound* s = new sf::Sound();

    s->setBuffer(*buffer);
    m_soundMap.insert({soundTag,s});
}

void Engine::AudioSource::LoadMusic(const std::string& filename)
{
    m_music->openFromFile(filename);
}

void Engine::AudioSource::SetVolume(const float &volume)
{
    m_volume = volume;
}

