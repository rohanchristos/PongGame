#include<raylib.h>
#include<iostream>
using namespace std;
Color purple = Color{128,0,128,255};
Color dark_purple = Color{ 153,50,204,255 };
Color light_purple = Color{ 186,85,211,255 };
Color pink= Color{ 252,128,165,255 };


int player_score = 0;
int cpu_score = 0;
class Ball {
public:
	float x, y;
	int speed_x, speed_y;
	int radius;

	void draw() {
		DrawCircle(x, y, radius, pink);
	}

	void update() {
		x += speed_x;
		y += speed_y;

		if (y + radius >= GetScreenHeight() || y - radius <= 0) {
			speed_y *= -1;
		}
		if (x + radius >= GetScreenWidth()) {
			cpu_score++;
			resetball();
		}
			
		if( x - radius <= 0) {
			player_score++;
			resetball();
			
		}
	}

	void resetball() {
		x = GetScreenWidth() / 2;
		y = GetScreenHeight() / 2;
		int speed_choices[2] = { -1,1 };
		speed_x *= speed_choices[GetRandomValue(0, 1)];

		speed_y *= speed_choices[GetRandomValue(0, 1)];

	}

};
class paddle {
protected:
	void limitmovement() {
		if (y <= 0) {
			y = 0;

		}
		if (y + height >= GetScreenHeight()) {
			y = GetScreenHeight() - height;

		}
	 }
public:
	float x, y;
	float width, height;
	int speed;
	void draw() {
		DrawRectangleRounded(Rectangle{ x,y,width,height }, 0.8, 0, WHITE);
		

	}
	void update() {
		if (IsKeyDown(KEY_UP)) {
			y = y - speed;
		}
		if (IsKeyDown(KEY_DOWN)) {
			y = y + speed;
		}
		limitmovement();
	}
	 
};
class cpu_paddle :public paddle {
public:
	void update(int ball_y) {
		if (y + height / 2 > ball_y) {
			y = y - speed;
		}
		if (y + height / 2 <= ball_y) {
			y = y + speed;
		}
		limitmovement();
	}

};
Ball ball;
paddle Player_1;
cpu_paddle cpu;
int main(void) {
	const int width = 1280;
	const int height = 800;
	InitWindow(width, height, "pong splash!");
	SetTargetFPS(60);
	ball.x = width / 2;
	ball.y = height / 2;
	ball.radius = 20;
	ball.speed_x = 7;
	ball.speed_y = 7;
	Player_1.width = 25;
	Player_1.height = 120;
	Player_1.x = width-Player_1.width-10;
	Player_1.y = height / 2 - Player_1.height/2;
	Player_1.speed = 6;
	cpu.width = 25;
	cpu.height = 120;
	cpu.x = 10;
	cpu.y = height / 2 - cpu.height / 2;
	cpu.speed = 6;

   
	while (WindowShouldClose() == false) {
		BeginDrawing();
		//updating
		ball.update();
		Player_1.update();
		cpu.update(ball.y);
		//checking collison
		if (CheckCollisionCircleRec(Vector2{ball.x,ball.y}, ball.radius, Rectangle{Player_1.x,Player_1.y,Player_1.width,Player_1.height})) {
			ball.speed_x *= -1;

		}
		if(CheckCollisionCircleRec(Vector2{ ball.x,ball.y }, ball.radius, Rectangle{ cpu.x,cpu.y,cpu.width,cpu.height })) {
			ball.speed_x *= -1;

		}

		//drawing
		ClearBackground(purple);
		DrawRectangle(width / 2, 0, width / 2, height, dark_purple);
		DrawCircle(width / 2, height / 2, 150, light_purple);

		DrawLine(width / 2, 0, width / 2, 800, WHITE);
		ball.draw();
		Player_1.draw();
		cpu.draw();
		DrawText(TextFormat("%i", cpu_score), width / 4 - 20, 20, 80, WHITE);
		DrawText(TextFormat("%i", player_score),3*width / 4 - 20, 20, 80, WHITE);
	
		EndDrawing();
		
	}

	CloseWindow();
	return 0;
}