# Game 2048 (C)

![Language](https://img.shields.io/badge/Language-C-blue)
![Platform](https://img.shields.io/badge/Platform-Ubuntu-lightgrey)
![License](https://img.shields.io/badge/License-MIT-yellow)

The project was written in C on a Ubuntu environment.  
I developed the full logic for the 2048 game, including tile movement, merging, random generation, and user input handling directly in the terminal.

## Features
- Undo support  
- Automatic end-game detection  
- Modular and efficient logic  

## Build & Run
```bash
gcc -o 2048 main.c board.c utils.c  
./2048
