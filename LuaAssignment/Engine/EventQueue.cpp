//
// Created by Igli milaqi on 13/12/2018.
//

#include "EventQueue.h"
#include <typeinfo>
#include <typeindex>


void Engine::EventQueue::HandleEvents()
{
    for (int i = m_eventTypes.size() - 1 ; i >= 0 ; i--)
    {
        auto handlerVec = m_eventMap.find(std::type_index(typeid(*(m_eventTypes[i]))));

        if(handlerVec == m_eventMap.end())
        {
            continue;
        }

        auto vec = handlerVec->second;

        for (unsigned int j = 0; j < vec->size() ; j++)
        {
            (*vec)[j]();
        }

    }

    m_eventTypes.clear();
}
