#include "scene.h"

#include <GL/glut.h>
#include <math.h>

void init_scene(Scene* scene)
{
}

void draw_scene(const Scene* scene)
{
    draw_origin();
	//draw_triangle();
	//draw_cylinder();
	//draw_cone();
	//draw_sphere();
	//draw_chessboard();
	//draw_cone();
	

	

}



void draw_chessboard()
{
	int rows, cols, i, j, k;
	k = 1;
    rows=8;
    cols=8;

    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            if(k == 1)
            {
                draw_square(i,j,0);
            }
            else
            {
                draw_square(i,j,1);
            }
            k *= -1;
        }

        if(cols % 2 == 0)
        {
            k *= -1;
        }
    }
}

void draw_square(float x1, float y1, int bow)
{
	if(bow == 1) {
	glBegin(GL_QUADS);

	glColor3f(1, 1, 1);
	glVertex3f(x1, y1, 0.0);
	
	glColor3f(1, 1, 1);
	glVertex3f(x1+1, y1, 0.0);
	
	glColor3f(1, 1, 1);
	glVertex3f(x1+1, y1+1, 0.0);
	
	glColor3f(1, 1, 1);
	glVertex3f(x1, y1+1, 0.0);

    glEnd();
	}
	else{
	glBegin(GL_QUADS);

	glColor3f(0, 0, 0);
	glVertex3f(x1, y1, 0.0);
	
	glColor3f(0, 0, 0);
	glVertex3f(x1+1, y1, 0.0);
	
	glColor3f(0, 0, 0);
	glVertex3f(x1+1, y1+1, 0.0);
	
	glColor3f(0, 0, 0);
	glVertex3f(x1, y1+1, 0.0);

    glEnd();
	}
	
}

void draw_triangle()
{
	glBegin(GL_TRIANGLES);

    glColor3f(1, 1, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 1);
    glVertex3f(0, 1, 0);

    glColor3f(1, 0, 1);
    glVertex3f(0, 0, 1);
	
	glEnd();
}

void draw_cylinder()
{
	float x, y, phi, h;
	
	glPushMatrix();
	glBegin(GL_QUAD_STRIP);
		phi = 0.0;
		h = 1.0;
		glColor3f(0, 1, 0);
		while (phi < M_PI) {
			x = cos(2*phi);
			y = sin(2*phi);
			glColor3f(phi/10, 0.2, phi/10);
			glVertex3f(x, y, 0);
			glVertex3f(x, y , h);
			phi += 0.01;
			
		}
		glEnd();
	glPopMatrix();
}

void draw_cylinder_tstrips()
{
	float x, y, phi, h;
	
	glPushMatrix();
	glBegin(GL_TRIANGLE_STRIP);
		phi = 0.0;
		h = 1.0;
		glColor3f(0, 1, 0);
		while (phi < M_PI) {
			x = cos(2*phi);
			y = sin(2*phi);
			glColor3f(phi/10, 0.2, phi/10);
			glVertex3f(x, y, 0);
			glVertex3f(x, y , h);
			phi += 0.01;
			
		}
		glEnd();
	glPopMatrix();
	
}

void draw_cone()
{
float x, y, phi;
	phi = 0.0;
	
	glBegin(GL_TRIANGLE_FAN);
	
	glColor3f(1, 1, 1);
	glVertex3f(0, 0, 1.0);

	
	glColor3f(0, 1, 0);
	while (phi < M_PI+0.02) {
		x = cos(2*phi);
		y = sin(2*phi);
		glVertex3f(x/2, y/2, 0);
		phi += 0.01;		
	}

    glEnd();
}

void draw_sphere()
{
	glPushMatrix();
		
		glColor3f(0.4, 0.4, 0.4);
        glTranslated(0.5,0.5,0.5);
		glRotatef(glutGet(GLUT_ELAPSED_TIME)/10, 0.0, 0.0, 1.0);
        glutSolidSphere(0.2, 10, 4);
    glPopMatrix(); 
}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}
