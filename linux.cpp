#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <stdio.h>

// Global variables
int questionNum = 1;

float positionx = 0.0f;
float positiony = 0.0f;
float movementspeed = 0.1f;
float rotationangle = 0.0f;

// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void display();
float DegreeToRadian(float degree);
void DrawCircle(float radius);
void one();
void two();
void three();
void four();
void five();
void six();

// Convert degree to radian
float DegreeToRadian(float degree)
{
    return degree * 3.142f / 180.0f;
}


// Draw circle
void DrawCircle(float radius)
{
    for (int i = 0; i < 360; i += 10)
    {
        float tempX = radius * sin(DegreeToRadian(i));
        float tempY = radius * cos(DegreeToRadian(i));

        glVertex2f(tempX, tempY);
    }
}



// Keyboard input
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS || action == GLFW_REPEAT)
    {

        switch(key)
        {
            case GLFW_KEY_ESCAPE:
                glfwSetWindowShouldClose(window, 1);
                break;

            case GLFW_KEY_1: questionNum = 1; break;
            case GLFW_KEY_2: questionNum = 2; break;
            case GLFW_KEY_3: questionNum = 3; break;
            case GLFW_KEY_4: questionNum = 4; break;
            case GLFW_KEY_5: questionNum = 5; break;
            case GLFW_KEY_6: questionNum = 6; break;

            case GLFW_KEY_UP:
                positiony += movementspeed;
                break;

            case GLFW_KEY_DOWN:
                positiony -= movementspeed;
                break;

            case GLFW_KEY_LEFT:
                positionx -= movementspeed;
                break;

            case GLFW_KEY_RIGHT:
                positionx += movementspeed;
                break;

            case GLFW_KEY_O:
                rotationangle += movementspeed;
                break;

            case GLFW_KEY_P:
                rotationangle -= movementspeed;
                break;
        }

    }
}

void one()
{
    glLoadIdentity();

    glTranslatef(positionx, positiony,0);
    glRotatef(rotationangle,0,0,1);


    glBegin(GL_QUADS);

    glColor3f(1,1,1);

    glVertex2f(-0.8f,0.5f);
    glVertex2f(-0.8f,0);
    glVertex2f(0.8f,0);
    glVertex2f(0.8f,0.5f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3f(0,0,0);

    glVertex2f(-0.8f,0);
    glVertex2f(-0.8f,-0.5f);
    glVertex2f(0.8f,-0.5f);
    glVertex2f(0.8f,0);

    glEnd();
}

void two()
{
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);  //yellow
    glVertex2f(-0.8f, 0.5f);
    glVertex2f(-0.8f, -0.5f);
    glVertex2f(0.8f, -0.5f);
    glVertex2f(0.8f, 0.5f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);  //red
    glVertex2f(-0.8f, 0.5f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.0f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);  //black
    glVertex2f(-0.8f, 0.5f);
    glVertex2f(-0.8f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glEnd();
}

void three()
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);  // white center
    glVertex2f(0.0f, 0.0f);

    glColor3f(0.65f, 0.65f, 0.65f);  // light grey edges
    glVertex2f(-0.8f, 0.5f);
    glVertex2f(-0.8f, -0.5f);
    glVertex2f(0.8f, -0.5f);
    glVertex2f(0.8f, 0.5f);

    glVertex2f(-0.8f, 0.5f);  // close fan
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);  //red
    glVertex2f(-0.1f, 0.5f);
    glVertex2f(-0.1f, -0.5f);
    glVertex2f(0.1f, -0.5f);
    glVertex2f(0.1f, 0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);  //red
    glVertex2f(-0.8f, 0.1f);
    glVertex2f(-0.8f, -0.1f);
    glVertex2f(0.8f, -0.1f);
    glVertex2f(0.8f, 0.1f);
    glEnd();
}

void four()
{
    // draw rectangle
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);  //blue
    glVertex2f(-0.8f, 0.5f);
    glVertex2f(-0.8f, -0.5f);
    glVertex2f(0.8f, -0.5f);
    glVertex2f(0.8f, 0.5f);
    glEnd();

    // draw polygon top left to bottom right
    glBegin(GL_POLYGON); 
    glColor3f(1.0f, 1.0f,1.0f);  //white
    glVertex2f(-0.8f, 0.5f);
    glVertex2f(-0.7f, 0.5f);
    glVertex2f(0.8f, -0.4f);
    glVertex2f(0.8f, -0.5f);
    glVertex2f(0.7f,-0.5f);
    glVertex2f(-0.8f, 0.4f);
    glEnd();

    // draw polygon top right to bottom left
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);  //white
    glVertex2f(0.8f, 0.5f);
    glVertex2f(0.7f, 0.5f);
    glVertex2f(-0.8f, -0.4f);
    glVertex2f(-0.8f, -0.5f);
    glVertex2f(-0.7f, -0.5f);
    glVertex2f(0.8f, 0.4f);
    glEnd();


}

void five()
{
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);  //white
    glVertex2f(-0.8f, 0.5f);
    glVertex2f(-0.8f, -0.5f);
    glVertex2f(0.8f, -0.5f);
    glVertex2f(0.8f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);  //red
    DrawCircle(0.2);
    glEnd();
}

void six()
{
    // draw vomit emoji
    // draw face
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);  //yellow
    DrawCircle(0.5);
    glEnd();

    // draw mouth
    // Top Left — Red
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.2f, -0.1f);

    // Bottom Left — Orange/Red
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(-0.2f, -0.5f);

    // Bottom Right — Violet
    glColor3f(0.5f, 0.0f, 1.0f);
    glVertex2f(0.2f, -0.5f);

    // Top Right — Blue/Violet
    glColor3f(0.3f, 0.0f, 1.0f);
    glVertex2f(0.2f, -0.1f);

    glEnd();

    // draw right eyes
    glBegin(GL_POLYGON);
    glColor3f(0.8863f, 0.6157f, 0.1765f);  // #E29D2D
    for (int i = 0; i < 360; i += 10)
    {
        float tempX = 0.1f * sin(DegreeToRadian(i)) + 0.2f;
        float tempY = 0.1f * cos(DegreeToRadian(i)) + 0.2f;

        glVertex2f(tempX, tempY);
    }
    glEnd();

    // draw left eye
    glBegin(GL_POLYGON);
    glColor3f(0.8863f, 0.6157f, 0.1765f);  // #E29D2D
    for (int i = 0; i < 360; i += 10)
    {
        float tempX = 0.1f * sin(DegreeToRadian(i)) + -0.2f;
        float tempY = 0.1f * cos(DegreeToRadian(i)) + 0.2f;

        glVertex2f(tempX, tempY);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);  // white
    for (int i = 0; i < 360; i += 10)
    {
        float tempX = 0.05f * sin(DegreeToRadian(i)) + -0.2f;
        float tempY = 0.05f * cos(DegreeToRadian(i)) + 0.2f;

        glVertex2f(tempX, tempY);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);  // white
    for (int i = 0; i < 360; i += 10)
    {
        float tempX = 0.05f * sin(DegreeToRadian(i)) + 0.2f;
        float tempY = 0.05f * cos(DegreeToRadian(i)) + 0.2f;

        glVertex2f(tempX, tempY);
    }
    glEnd();



    // draw rectangle hat
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);  //black
    glVertex2f(-0.3f, 0.7f);
    glVertex2f(0.3f, 0.7f);
    glVertex2f(0.3f, 0.5f);
    glVertex2f(-0.3f, 0.5f);
    glEnd();

    // draw rectangle hat
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);  //black
    glVertex2f(-0.3f, 0.5f);
    glVertex2f(0.3f, 0.5f);
    glVertex2f(0.6f, 0.35f);
    glVertex2f(-0.6f, 0.35f);
    glEnd();

    // draw nose
    glBegin(GL_TRIANGLES);
    glColor3f(0.8863f, 0.6157f, 0.1765f);  // #E29D2D
    glVertex2f(0.0f, 0.1f);
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(0.03f, 0.0f);
    glEnd();

    
}


void display()
{

    glClearColor(0.3f,0.3f,0.3f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    switch(questionNum)
    {

        case 1:
            one();
        break;
        case 2:
            two();
        break;
        case 3:
            three();
        break;
        case 4:
            four();
        break;


        case 5:

            five();    
        break;



        case 6:

            six();

        break;


    }

}




int main()
{


    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800,800,"Practical",NULL,NULL);


    glfwMakeContextCurrent(window);


    gladLoadGL(glfwGetProcAddress);


    glfwSetKeyCallback(window,key_callback);



    while(!glfwWindowShouldClose(window))
    {

        display();

        glfwSwapBuffers(window);

        glfwPollEvents();

    }



    glfwTerminate();

}