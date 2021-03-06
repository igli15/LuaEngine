cmake_minimum_required(VERSION 3.2)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(SOURCE_FILES Engine/main.cpp Engine/Component.cpp Engine/Component.h TestComponent.cpp TestComponent.h Engine/Scene.cpp Engine/Scene.h Engine/Game.cpp Engine/Game.h Engine/IVector.cpp Engine/IVector.h Engine/Rigidbody.cpp Engine/Rigidbody.h Engine/SceneManager.cpp Engine/SceneManager.h Engine/SpriteRenderer.cpp Engine/SpriteRenderer.h Engine/Collider.cpp Engine/Collider.h Engine/Physics.cpp Engine/Physics.h Engine/Utils.cpp Engine/Utils.h Engine/Text.cpp Engine/Text.h Engine/TextComponent.cpp Engine/TextComponent.h Engine/AudioSource.cpp Engine/AudioSource.h Game/MainGame.cpp Game/MainGame.h Engine/EventType.cpp Engine/EventType.h Engine/EventQueue.cpp Engine/EventQueue.h Game/TestEvent.cpp Game/TestEvent.h Game/MainLevel.cpp Game/MainLevel.h Engine/Sprite.cpp Engine/Sprite.h Game/Card.cpp Game/Card.h Game/Hand.cpp Game/Hand.h Game/Components/CardComponent.cpp Game/Components/CardComponent.h Game/HandSlot.cpp Game/HandSlot.h Game/Player.cpp Game/Player.h Game/Components/PlayerComponent.cpp Game/Components/PlayerComponent.h Game/CardTemplate.cpp Game/CardTemplate.h Game/Components/HandComponent.cpp Game/Components/HandComponent.h Game/Deck.cpp Game/Deck.h Game/Components/DeckComponent.cpp Game/Components/DeckComponent.h Engine/ResourceManager.cpp Engine/ResourceManager.h Engine/LuaProgram.cpp Engine/LuaProgram.h Game/PlayerInfo.cpp Game/PlayerInfo.h Game/Enemy.cpp Game/Enemy.h Game/Components/EnemyComponent.cpp Game/Components/EnemyComponent.h)
add_executable(${ProjectId} ${SOURCE_FILES} Engine/Component.cpp Engine/Component.h Engine/Entity.cpp Engine/Entity.h TestComponent.cpp TestComponent.h Game/MainLevel.cpp Game/MainLevel.h Engine/Sprite.cpp Engine/Sprite.h Game/Card.cpp Game/Card.h Game/Hand.cpp Game/Hand.h Game/Components/CardComponent.cpp Game/Components/CardComponent.h Game/HandSlot.cpp Game/HandSlot.h Game/Player.cpp Game/Player.h Game/Components/PlayerComponent.cpp Game/Components/PlayerComponent.h Game/CardTemplate.cpp Game/CardTemplate.h Game/Components/HandComponent.cpp Game/Components/HandComponent.h Game/Deck.cpp Game/Deck.h Game/Components/DeckComponent.cpp Game/Components/DeckComponent.h Engine/ResourceManager.cpp Engine/ResourceManager.h Engine/LuaProgram.cpp Engine/LuaProgram.h Game/PlayerInfo.cpp Game/PlayerInfo.h Game/Enemy.cpp Game/Enemy.h Game/Components/EnemyComponent.cpp Game/Components/EnemyComponent.h)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${ProjectId} ${SFML_LIBRARIES})
endif()


FIND_PACKAGE(Lua 5.3 REQUIRED)

set(INCLUDE_DIRS ${LUA_INCLUDE_DIR})

add_definitions(-DLUA)

include_directories(${INCLUDE_DIRS})

target_link_libraries(${ProjectId} ${LUA_LIBRARY})



