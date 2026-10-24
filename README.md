# Retro Snake

A classic **Snake game developed in C++ using the raylib library**, inspired by retro games. Control the snake, eat food to grow, and try to achieve the highest score without hitting the walls or your own tail!

## Overview

Retro Snake offers simple, nostalgic gameplay featuring a game grid, retro colors, and progression based on collecting food.

## Technologies Used

- **C++** — programming language.
- **raylib** — graphics library for 2D rendering, keyboard input, and time management.
- **raymath** — mathematical functions and vector operations.
- **STL** — uses `std::deque` to manage the snake's body.

## Prerequisites

Before compiling the project, make sure you have:

- A C++ compiler compatible with C++11 or later.
- The [raylib](https://www.raylib.com/) library installed and configured.
- The appropriate build tools for your operating system.

## 🚀 Installation and Compilation

### 1. Clone the repository

```bash
git clone https://github.com/MamadouSouare/retro-snakeGame.git
cd retro-snakeGame
```
### 2. Install raylib

Download and install raylib by following the official instructions:
[https://github.com/raysan5/raylib](https://github.com/raysan5/raylib)
Make sure your compiler can find the raylib header files and library.

### 3. Compile the game

Using `g++` on a Linux system where raylib is properly installed:

```bash
g++ main.cpp -o retro-snakeGame -std=c++11 -lraylib -lm 
```
Depending on your operating system and raylib installation, the linking options may differ.

### 4. Run the game

On Linux:

```bash
./retro-snake
```

On Windows, after compiling with the appropriate configuration for your environment:

```bash
retro-snake.exe
```

## Controls

| Key | Action |
| --- | --- |
| ↑ Up Arrow | Move the snake up |
| ↓ Down Arrow | Move the snake down |
| → Right Arrow | Move the snake right |
| ← Left Arrow | Move the snake left |
| Close window | Quit the game |

The snake moves automatically approximately every 0.2 seconds. Press an arrow key to change direction and resume playing after a collision.

## Game Rules

1. Control the snake using the arrow keys.
2. Eat food to earn one point and grow longer.
3. Avoid the edges of the grid.
4. Do not collide with your own body.
5. Try to achieve the maximum score of **625 points**, corresponding to the 25 × 25 grid.

A collision resets the snake and the score. You can then resume the game by pressing an arrow key.

## Code Structure

The program is organized around three main components:

### `Snake`

Manages the snake and its behavior:

- Stores the body in a `std::deque<Vector2>`.
- Renders the segments.
- Moves the snake.
- Adds segments after eating food.
- Resets its position and direction.

### `Food`

Manages the food:

- Loads the `food.png` texture.
- Generates a random position on the grid.
- Ensures the food does not spawn on the snake's body.
- Renders the food and releases the texture.

### `Game`

Manages the overall game logic:

- Updates the game state.
- Handles the score.
- Detects collisions with the walls and the snake's tail.
- Resets the game after a loss.
- Detects victory.

The main loop initializes the raylib window, processes keyboard input, updates the game, and draws the elements on the screen.

## Planned Improvements

- Gradually increase the snake's speed.
- Add a title screen and a game-over screen.
- Display the high score.
- Add retro sound effects and music.
- Implement pause and resume using the spacebar.
- Save the high score.
- Support restarting the game using a dedicated key.

**Have fun, and happy food hunting! 🐍**
