#include<bits/stdc++.h>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

vector< pair<int,int> > po;


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);

//    glBegin(GL_POLYGON);
//
//    glVertex2i(120, 120);
//    glVertex2i(20, 40);
//    glVertex2i(60, 50);
//    glVertex2i(80, 60);
//
//    glEnd();
//
//    glBegin(GL_POLYGON);
//
//    glVertex2i(60, 50);
//    glVertex2i(10, 0);
//    glVertex2i(120, 70);
//    glVertex2i(80, 60);
//
//    glEnd();

    glBegin(GL_POLYGON);

    glVertex2i(120, 120);
    glVertex2i(20, 40);
    glVertex2i(60, 50);
    glVertex2i(10, 0);
    glVertex2i(120, 70);
    glVertex2i(80, 60);

    glEnd();


    glFlush();
}
void init(void)
{
    /* select clearing (background) color */
    glClearColor(0.0, 0.0, 0.0, 0.0);
    /* initialize viewing values */
    glPointSize(5);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    ///glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    gluOrtho2D(0.0,600,0.0,400);
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with “hello”
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/

void takeInput()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if(x1 == x2)
    for(int i = y1; i != y2; (i < y2) ? i++ : i--)
    {
        po.push_back( make_pair(x1, i) );
    }
    else if(abs(x1 - x2) >= abs(y1 - y2))
    {
        if(x1 > x2) swap(x1, y1), swap(x2, y2);
        double dy = (y1 - y2), dx = (x1 - x2);
        double m = dy / dx, y = y1;

        for(int i = x1; i <= x2; i++, y += m)
        {
            po.push_back( make_pair(i, y) );
        }

    }
    else
    {
        swap(x1, y1); swap(x2, y2);
        if(x1 > x2) swap(x1, y1), swap(x2, y2);
        double dy = (y1 - y2), dx = (x1 - x2);
        double m = dy / dx, y = y1;

        for(int i = x1; i <= x2; i++, y += m)
        {
            po.push_back( make_pair(y, i) );
        }
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(800, 100);
    glutCreateWindow("hello");
    init();
    ///takeInput();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}

