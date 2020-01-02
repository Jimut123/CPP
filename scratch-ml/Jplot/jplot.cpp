#include<bits/stdc++.h>
#include <GL/glx.h>    
#include <GL/gl.h>
#include <GL/glut.h>  // GLUT, includes glu.h and gl.h

class jplot{
    public:
    jplot(const char*,int,int);
    ~jplot();
    void draw_points(float,float);
};

jplot::~jplot()
{
    std::cout<<"Destroyed"<<std::endl;
}

void jplot::draw_points(float x, float y)
{
    // this function draws points
    //glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer
    glBegin(GL_POINTS);
        glVertex2f(x, y);
    glEnd();
}


void render_now() 
{
   glFlush();  // Render now
}

jplot::jplot(const char* name, int height, int width)
{
   // constructor to create window
   glutCreateWindow(name); // Create a window with the given title
   glutDisplayFunc(render_now); // Register display callback handler for window re-paint
   glutInitWindowSize(height, width);   // Set the window's initial width & height
   glutInitWindowPosition(0, 0); // Position the window's initial top-left corner

   // Initialize stuffs
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer


   // Draw a White 1x1 background
   glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
      glColor3f(1.0f, 1.0f, 1.0f); // Red
      glVertex2f(1.0f, 1.0f);    // x, y
      glVertex2f( 1.0f, -1.0f);
      glVertex2f( -1.0f,  -1.0f);
      glVertex2f(-1.0f,  1.0f);
   glEnd();
    


    // glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    //     glColor3f(1.0f, 0.0f, 0.0f); // Red
    //     glVertex2f(1.0f, 1.0f);    // x, y
    //     glVertex2f( 1.0f, 0.0f);
    //     glVertex2f( 0.0f,  0.0f);
        
    // glEnd();

}

int main(int argc, char** argv) {
   glutInit(&argc, argv);                 // Initialize GLUT
   jplot j("Jimut",320,320);
   j.draw_points(0.5,0.5);
   glutMainLoop();           // Enter the infinitely event-processing loop
   return 0;
}