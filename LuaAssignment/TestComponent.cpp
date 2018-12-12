//
// Created by Igli milaqi on 05/10/2018.
//

#include "TestComponent.h"
#include <iostream>

void TestComponent::Start() {

    Engine::Component::Start();
    std::cout<<"HIIIIII"<<std::endl;
}
