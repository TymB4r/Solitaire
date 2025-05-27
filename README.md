# Klondike Solitaire (C++ Console)

A C++20 console implementation of Klondike Solitaire with basic features including undo support (up to 3 moves). Built using CMake 3.29+.

## Requirements

- C++20-compatible compiler (e.g. `g++ 11+`, `clang++ 12+`, or MSVC)
- [CMake](https://cmake.org/download/) version 3.29 or newer
- A terminal that supports basic ANSI output

## Build Instructions

1. Clone the repository and enter the directory:

    ```bash
    git clone <repo-url>
    cd Solitaire
    ```

2. Create a build directory and run CMake:

    ```bash
    mkdir build
    cd build
    cmake ..
    ```

3. Build the project:

    ```bash
    cmake --build .
    ```

4. Run the game (from inside the build directory):

    ```bash
    ./Solitaire
    ```

## How to Play

The game is played entirely via text commands in the terminal. Available commands:

- `DRAW`  
  Draw the next card from the stock.

- `MOVE <src> <dst> <count>`  
  Move a card or stack from one location to another.  
  Use the game's printed identifiers (e.g., `W1`, `T3`, `F2`).  
  Click [here](MOVE-FORMAT.md) to see more about the move format

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
    - `GameController.*` — Core gameplay loop and rules
    - `Position.*` — Models card positions (tableau, foundations, etc.)

- `UI/`
    - `Renderer.*` — Responsible for displaying the current UI state

## Notes
- Output is optimized for a standard 80x24 terminal. Resize if formatting is off.