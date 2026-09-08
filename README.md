# 🐍 Snake Game

A simple **retro-style Snake Game** written in **C++** using the **Raylib** library.

The goal is to control the snake, eat the food, grow in size, and achieve the highest possible score without hitting the walls or the snake's own tail.

## 🕹️ Controls

| Key                  | Action        |
| -------------------- | ------------- |
| `↑`                  | Move Up       |
| `↓`                  | Move Down     |
| `←`                  | Move Left     |
| `→`                  | Move Right    |
| `ESC` / Close Window | Exit the game |

The snake cannot immediately move in the opposite direction to prevent instant self-collisions.

## 🛠️ Requirements

Before compiling the game, make sure you have:

* **Raylib**
* **Raymath** (included with Raylib)
* The `food.png` image file

The project expects `food.png` to be available in the game's working directory.

## 🔨 Compilation

Compile the game with:

```bash
g++ -o snakeGame snakeGame.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```

Then run it with:

```bash
./snakeGame
```

## 🚀 Possible Improvements

Some ideas for future versions:

* Add a restart key
* Add a start menu
* Add a pause system
* Add sound effects and background music
* Add different difficulty levels
* Add a persistent high-score system
* Add a game-over screen
* Add different food types and bonuses