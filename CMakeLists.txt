cmake_minimum_required(VERSION 3.29)
project(Solitaire)

set(CMAKE_CXX_STANDARD 20)

add_executable(Solitaire src/main.cpp
        src/containers/Deck.h
        src/containers/Deck.cpp
        src/logic/PositionLogic.cpp
        src/logic/Position.h
        src/logic/GameController.cpp
        src/logic/GameController.h
        src/UI/Renderer.cpp
        src/UI/Renderer.h
        src/containers/Move.cpp
        src/containers/Move.h
        src/containers/History.cpp
        src/containers/History.h
)
