cmake_minimum_required(VERSION 3.29)
project(Solitaire)

set(CMAKE_CXX_STANDARD 20)

add_executable(Solitaire src/main.cpp
        src/Deck.h
        src/Deck.cpp
        src/Position.cpp
        src/Position.h
        src/Move.cpp
        src/Move.h)
