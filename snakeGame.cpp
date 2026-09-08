#include <iostream>
#include <deque>
#include <raylib.h>
#include <raymath.h>

const Color green = {173, 204, 96, 255};
const Color darkGreen = {43, 51, 24, 255};

const int offset = 75;
const int cellSize = 30;
const int numberCell = 25;

const int maxScore = numberCell * numberCell;

double lastUpdateTime = 0.0;

bool EventTriggered( double interval ) {
	double currentTime = GetTime();
	if ( currentTime - lastUpdateTime >= interval ) {
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

bool ElementInDeque( const Vector2 element, const std::deque<Vector2> deque ) {
	for( unsigned int i=0; i < deque.size(); i++ ) {
		if( Vector2Equals(deque[i], element) )
			return true;
	}
	return false;
}

struct 	Snake {
	std::deque<Vector2> body = { Vector2(7, 6), Vector2(6, 6), Vector2(5, 6) };
	Vector2 direction = { 1, 0 };
	bool addSegment = false;

	void Draw() {
		for( unsigned i = 0; i < body.size(); i++) {
			Rectangle segment = Rectangle{ offset+ body[i].x* cellSize, offset+  body[i].y* cellSize, cellSize, cellSize};
			DrawRectangleRounded( segment, 0.5, 6, darkGreen );
		}
	}

	void Update() {
		body.push_front(Vector2Add(body[0], direction));
		if( addSegment == false ) {
			body.pop_back();
		} else {
			addSegment = false;
		}
	}

	void Reset() {
		body = { Vector2(7, 6), Vector2(6, 6), Vector2(5, 6) };
		direction = {1, 0};
	}
};

struct 	Food {
	Vector2 position;
	Texture2D texture;

	Food( const std::deque<Vector2> &snakeBody ) {
		Image image = LoadImage("food.png");
		texture = LoadTextureFromImage( image );
		UnloadImage( image );
		position = GenerateRandomPos(snakeBody);
	}

	~Food() {
		UnloadTexture( texture );
	}

	void Draw() {
		DrawTexture( texture, offset + position.x * cellSize, offset + position.y * cellSize, darkGreen );
	}

	Vector2 	GenerateRandomCell() {
		float posX = GetRandomValue(0, numberCell - 1);
		float posY = GetRandomValue(0, numberCell - 1);
		return Vector2{ posX, posY };
	}

	Vector2 	GenerateRandomPos( const std::deque<Vector2> &snakeBody ) {
		Vector2 pos = GenerateRandomCell();
		while( ElementInDeque(pos, snakeBody) ) {
			pos = GenerateRandomCell();
		}
		return pos;
	}
};

class 	Game {
public:
	Snake snake = Snake();
	Food  food  = Food(snake.body);
	int score = 0;
	bool running = true;
	bool win = false;

	void Update() {
		if( running ) {
			snake.Update();
			CheckCollisionFood();
			CheckCollisionWithEdges();
			CheckCollisionWithTails();
		}

		if( score == maxScore ) {
			running = false;
			win = true;
		}
	}

	void Draw() {
		food.Draw();
		snake.Draw();
	}

	void CheckCollisionFood() {
		if( Vector2Equals(snake.body[0], food.position) ) {
			food.position = food.GenerateRandomPos( snake.body );
			snake.addSegment = true;
			score++;
		}
	}

	void CheckCollisionWithEdges() {
		if( snake.body[0].x >= numberCell || snake.body[0].x < 0 )
			GameOver();
		if( snake.body[0].y >= numberCell || snake.body[0].y < 0 )
			GameOver();
	}

	void CheckCollisionWithTails() {
		for( auto el = snake.body.begin()+1; el != snake.body.end(); el++ ) {
			if( Vector2Equals(*el, snake.body[0]) ) {
				GameOver();
				break;
			}
		}
	}

	void GameOver() {
		snake.Reset();
		food.position = food.GenerateRandomPos(snake.body);
		running = false;
		score = 0;
	}

};

int 	main(void)
{
	InitWindow(offset*2 + cellSize*numberCell, offset*2 + cellSize*numberCell, "Snake Game");
	SetTargetFPS(60);

	Game game = Game();

	while( WindowShouldClose() == false ) {
		BeginDrawing();
		ClearBackground( green );

		if( EventTriggered(0.2) )
			game.Update();

		if( IsKeyPressed(KEY_UP) && game.snake.direction.y != 1 ){
			game.running = true;
			game.snake.direction = {0, -1};
		}
		if( IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1 ){
			game.running = true;
			game.snake.direction = {0, 1};
		}
		if( IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1 ){
			game.running = true;
			game.snake.direction = {1, 0};
		}
		if( IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1 ){
			game.running = true;
			game.snake.direction = {-1, 0};
		}

		game.Draw();
		DrawText("Retro Snake", offset - 5, 30, 40, darkGreen);
		DrawText(TextFormat("%i", game.score), offset - 5, offset + cellSize*numberCell + 10, 40, darkGreen);
		DrawRectangleLinesEx( Rectangle{offset-5, offset-5, cellSize*numberCell+10, cellSize*numberCell+10}, 5, darkGreen);

		if( game.win ) {
			DrawText("You WIN", offset + (cellSize * numberCell)/2-50*3.5, offset + (cellSize * numberCell)/2-40*3.5, 100, green);
		}
		EndDrawing();
	}
	
	CloseWindow();
	return (0);
}