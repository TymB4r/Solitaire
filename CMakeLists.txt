cmake_minimum_required(VERSION 3.29)
project(Solitaire)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Solitaire src/main.cpp
        src/containers/Deck.h
        src/containers/Deck.cpp
        src/containers/Move.h
        src/containers/Move.cpp
        src/containers/History.h
        src/containers/History.cpp
        src/logic/Position.h
        src/logic/Position.cpp
        src/logic/GameController.h
        src/logic/GameController.cpp
        src/UI/Renderer.h
        src/UI/Renderer.cpp
)
