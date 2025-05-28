# Klondike Solitaire (C++ Console)

A C++ console implementation of Klondike Solitaire with basic features including undo support (up to 3 moves). Built using CMake.

## Requirements

- C++20-compatible compiler (e.g., `g++ 11+`, `clang++ 12+`, or MSVC)
- [CMake](https://cmake.org/download/) version 3.29 or newer
- A terminal that supports basic ANSI output

## Build Instructions

1. Navigate to the project directory (where `CMakeLists.txt` is located):
   ```bash
   cd path/to/your/klondike-solitaire

2. Create a build directory and run CMake:  
   _(Only if the directory does not exist)_
   ```bash
   mkdir build
   ```

3. Run configuration:
   ```bash
   cmake -S . -B build -G "MinGW Makefiles"
   ```

4. Build the project:
   ```bash
   cmake --build build
   ```

5. Run the built executable:
   ```bash
   build/Solitaire.exe
   ```

## How to Play

The game is played entirely via text commands in the terminal. Available commands:

- `DRAW`  
  Draw the next card from the stock.

- `MOVE <src> <dst> [count]`  
  Move a card or stack from one location to another.  
  Use the game's printed identifiers (e.g., `W`, `T3`, `F2`).  
  Click [here](MOVE-FORMAT.md) to see more about the move format.

- `UNDO`  
  Undo the most recent move (up to 3 previous moves are stored).

- `RESTART`  
  Restart the current game from a new shuffle.

- `HELP`  
  Display a brief command guide during gameplay.

- `QUIT`  
  Exit the application.

The game will print the current board state and list available commands after each move.

## Project Structure

- `main.cpp`  
  Entry point and main loop

- `containers/`
    - `Deck.*` — Manages the card deck
    - `Move.*` — Represents individual moves
    - `History.*` — Stores move history for undo functionality

- `logic/`
    - `GameController.*` — Core gameplay rules and execution
    - `Position.*` — Models card positions (tableau, foundations, etc.)

- `UI/`
    - `Renderer.*` — Responsible for displaying the current UI state