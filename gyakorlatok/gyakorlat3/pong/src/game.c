#include "game.h"

#include <stdio.h>
#include <stdlib.h>

int count = 1;
int score_left=0;
int score_right=0;

void resize_game(Game* game, int width, int height)
{
    game->width = width;
    game->height = height;
    game->left_pad.size = 100;
    game->right_pad.size = 100;
    restart_game(game);
}

void restart_game(Game* game)
{
    float center_x;
    float center_y;

    center_x = game->width / 2;
    center_y = game->height / 2;

    move_pad(&(game->left_pad), center_y, game->height);
    move_pad(&(game->right_pad), center_y, game->height);
    start_ball(&(game->ball), center_x, center_y);
}

void update_game(Game* game, double time)
{
	float y1 = game->left_pad.position;
    float y2 = y1 + game->left_pad.size;
	
	float y3 = game->right_pad.position;
    float y4 = y3 + game->right_pad.size;
	
	float center_x;
    float center_y;

    center_x = game->width / 2;
    center_y = game->height / 2;
	
	
    update_ball(&(game->ball), time);
    if (game->ball.x - game->ball.radius < 50 && game->ball.x >= 50 && game->ball.y + game->ball.radius > y1 && game->ball.y - game->ball.radius < y2  ) {
        game->ball.x = game->ball.radius + 50;
        game->ball.speed_x *= -1;
		count=4;
    }
    if (game->ball.x + game->ball.radius > game->width - 50 && game->ball.x <= game->width - 50 && game->ball.y + game->ball.radius > y3 && game->ball.y - game->ball.radius < y4 ) {
        game->ball.x = game->width - game->ball.radius - 50;
        game->ball.speed_x *= -1;
		count=2;
    }
    if (game->ball.y - game->ball.radius < 0) {
        game->ball.y = game->ball.radius;
        game->ball.speed_y *= -1;
    }
    if (game->ball.y + game->ball.radius > game->height) {
        game->ball.y = game->height - game->ball.radius;
        game->ball.speed_y *= -1;
    }
	if (game->ball.x > game->width + game->ball.radius) {
		 score_left++;
		 move_ball(&(game->ball), center_x,center_y);
		 game->ball.speed_x *= -1;
		 count=1;
	}
	if (game->ball.x < 0 - game->ball.radius) {
		 score_right++;
		 move_ball(&(game->ball), center_x,center_y);
		 game->ball.speed_x *= -1;
		 count=1;
	}
}

void move_left_pad(Game* game, float position)
{
    move_pad(&(game->left_pad), position, game->height);
}

void move_right_pad(Game* game, float position)
{
    move_pad(&(game->right_pad), position, game->height);
}

void change_ball(Game* game, float x, float y)
{
	move_ball(&(game->ball), x, y);
}

void change_ball_radius(Game* game, int radius)
{
	resize_ball(&(game->ball), radius);
}