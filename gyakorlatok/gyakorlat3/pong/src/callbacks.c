#include "callbacks.h"
#include "draw.h"

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    draw_game(&game);

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height)
{
    resize_game(&game, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -200, 200);
    glViewport(0, 0, width, height);
}

void motion(int x, int y)
{
    move_right_pad(&game, y);
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    float position;
	int radius;

    position = game.left_pad.position;
	radius = game.ball.radius;
	
    switch (key) {
    case 'w':
        position -= 10;
		move_left_pad(&game, position);
        break;
    case 's':
        position += 10;
		move_left_pad(&game, position);
        break;
	case 'o':
		if(radius > 20) {
			radius -= 10;
			change_ball_radius(&game, radius);
		}
		break;
	case 'p':
		if(radius < 80) {
			radius += 10;
			change_ball_radius(&game, radius);
		}
		break;
    }
    

    glutPostRedisplay();
}

void idle()
{
    static int last_frame_time = 0;
    int current_time;
    double elapsed_time;
   
    current_time = glutGet(GLUT_ELAPSED_TIME);
    elapsed_time = (double)(current_time - last_frame_time) / 1000;
    last_frame_time = current_time;

    update_game(&game, elapsed_time);
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		change_ball(&game, (float)(x), (float)(y));
	}
	glutPostRedisplay();
}




















