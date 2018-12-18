//
// Created by Igli milaqi on 13/12/2018.
//

#ifndef LUAASSIGNMENT_EVENTQUEUE_H
#define LUAASSIGNMENT_EVENTQUEUE_H


#include <vector>
#include <map>
#include <typeinfo>
#include <typeindex>
#include <iostream>
#include <unordered_map>
#include "EventType.h"

namespace Engine {
    class EventQueue {

    private:

        std::vector<EventType *> m_eventTypes;
        std::map< std::type_index, std::vector<std::function<void()>> *> m_eventMap;

    public:
        void HandleEvents();

        template<typename T>
        void QueueEventType() {
            T *eventType = new T();

            m_eventTypes.push_back(eventType);
        }

        template<typename T>
        void RegisterEvent(const std::function<void()> &functionToAdd)
        {
            auto it = m_eventMap.find(std::type_index(typeid(T)));

            if (it != m_eventMap.end())
            {
                it->second->push_back(functionToAdd);
            } else
                {
                auto vec = new std::vector<std::function<void()>>();
                vec->push_back(functionToAdd);
                m_eventMap[std::type_index(typeid(T))] = vec;
            }

        }
    };
}


#endif //LUAASSIGNMENT_EVENTQUEUE_H
