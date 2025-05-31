# Klondike Solitaire (C++ Console)

A C++ console implementation of Klondike Solitaire with basic features including undo support (up to 3 moves). Built using CMake.

## Requirements

- A C++20-compatible compiler (for example, `g++` version 11 or newer, `clang++` version 12 or newer, or Microsoft Visual C++)
- `mingw32-make.exe` (recommended to install via [MSYS2](https://www.msys2.org/); typically located in the `./ucrt64/bin` directory)
- [CMake](https://cmake.org/download/) version 3.29 or later
- A terminal that supports basic ANSI escape codes for colored output

## How to Play

The game is played entirely via text commands in the terminal. Available commands:

- `DRAW` or `D`  
  Draw the next card from the stock and move it to waste.

- `MOVE <src> <dst> [count]` or `M <src> <dst> [count]`  
  Move a card or stack from one location to another.  
  Use the game's stack identifiers (e.g., `W`, `T3`, `F2`).  
  Click [here](MOVE-FORMAT.md) to see more about the move format.

- `UNDO`  
  Undo the most recent move (up to 3 moves).

- `RESTART`  
  Restart the current game from a new shuffle.

- `HELP`  
  Display a brief command guide during gameplay.

- `QUIT`  
  Exit the application.  

## Build Instructions

1. Navigate to the project directory (where `CMakeLists.txt` is located):
   ```bash
   cd path/to/your/Solitaire
   ```

2. Run build.bat script in cmd and build the project
    ```bash
    build.bat
   ```

3. Run the built executable:
   ```bash
   build/Solitaire.exe
   ```

## Project Structure

- `main.cpp` — Entry point and main loop

- `containers/`
    - `Deck.*` — Manages the card deck
    - `Move.*` — Represents individual moves
    - `History.*` — Stores move history for undo functionality

- `logic/`
    - `GameController.*` — Core gameplay rules and execution
    - `Position.*` — Models card positions (tableau, foundations, etc.)

- `UI/`
    - `Renderer.*` — Responsible for displaying the current UI state