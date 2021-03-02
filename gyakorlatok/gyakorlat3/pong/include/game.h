#ifndef GAME_H
#define GAME_H

#include "ball.h"
#include "pad.h"

/**
 * Game state representation
 */
typedef struct Game
{
    Ball ball;
    Pad left_pad;
    Pad right_pad;
    int width;
    int height;
} Game;

extern int count;
extern int score_left;
extern int score_right;

/**
 * Resize the game and update positions.
 */
void resize_game(Game* game, int width, int height);

/**
 * Restart the game.
 */
void restart_game(Game* game);

/**
 * Update the state of the game.
 * @param time elapsed time in seconds
 */
void update_game(Game* game, double time);

/**
 * Move the left pad to the given position.
 */
void move_left_pad(Game* game, float position);

/**
 * Move the right pad to the given position.
 */
void move_right_pad(Game* game, float position);

/**
 * Places the ball on the given coordinates.
 */
void change_ball(Game* game, float x, float y);

/**
 * Sets the radius of the ball to the given integer.
 */
void change_ball_radius(Game* game, int radius);


#endif /* GAME_H */
