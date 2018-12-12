//
// Created by Igli milaqi on 22/10/2018.
//

#ifndef SMFLPROJECT_AUDIOSOURCE_H
#define SMFLPROJECT_AUDIOSOURCE_H

#include "Component.h"
#include <SFML/Audio.hpp>
#include <map>


namespace Engine {
    class AudioSource : public Engine::Component {

    private:
        sf::Music *m_music;
        std::map<std::string,sf::Sound*> m_soundMap;
        std::vector<sf::SoundBuffer*> m_soundVector;
        float m_volume = 100;                           //default full volume

    public:
        AudioSource();
        ~AudioSource() override;
        void PlayOneShotSound(const std::string& soundTag);

        void LoadMusic(const std::string& filename);

        void SetVolume(const float& volume);

        void PlayMusic();

        void PauseMusic();

        void StopMusic();

        void LoadSound(const std::string& filename,const std::string& soundTag);
    };
}


#endif //SMFLPROJECT_AUDIOSOURCE_H
