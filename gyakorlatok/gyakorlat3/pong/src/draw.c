#include "draw.h"
#include "game.h"

#include "GL/glut.h"
#include <stdio.h>
#include <stdlib.h>

void draw_game(Game* game)
{
    float x1, x2, y1, y2;
	int TimeElapsed;
	int bounce_modifier=1+count;
	char buffer1[10]={'\0'};
	char buffer2[10]={'\0'};

    x1 = 0;
    x2 = 50;
    y1 = game->left_pad.position;
    y2 = y1 + game->left_pad.size;
	
	TimeElapsed = glutGet(GLUT_ELAPSED_TIME);
	

    glBegin(GL_QUADS);

    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(x1, y1);

    glColor3f(0.8, 0.2, 0.0);
    glVertex2f(x2, y1);

    glColor3f(1.0, 0.4, 0.0);
    glVertex2f(x2, y2);

    glColor3f(0.9, 0.3, 0.0);
    glVertex2f(x1, y2);

    glEnd();

    x1 = game->width - 50;
    x2 = game->width;
    y1 = game->right_pad.position;
    y2 = y1 + game->right_pad.size;

    glBegin(GL_QUADS);

    glColor3f(0.0, 0.1, 0.0);
    glVertex2f(x1, y1);

    glColor3f(0.0, 0.8, 0.2);
    glVertex2f(x2, y1);

    glColor3f(0.0, 1.0, 0.4);
    glVertex2f(x2, y2);

    glColor3f(0.0, 0.9, 0.2);
    glVertex2f(x1, y2);

    glEnd();

    glPushMatrix();
		glTranslatef(game->ball.x, game->ball.y, 0.0);
		glRotatef(TimeElapsed/6*bounce_modifier, 0.0, 0.0, 1.0);
		glColor3f(0.1, 0.9, 0.8);
		glutSolidSphere(game->ball.radius, 5, 8);
	glPopMatrix();
	
	
	
	sprintf(buffer1, "%d", score_left);
	glRasterPos2f(100, 100);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, buffer1);
	
	
	sprintf(buffer2, "%d", score_right);
	glRasterPos2f(500, 100);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, buffer2);


}
