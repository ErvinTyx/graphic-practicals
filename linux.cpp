#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <stdio.h>
#include <iostream>

// Global variables
int questionNum = 1;

float positionx = 0.0f;
float positiony = 0.0f;
float movementspeed = 10.0f;
float rotationangle = 0.0f;
float rotationx = 0.0f;
float rotationy = 0.0f;
float rotationz = 0.0f;
float rotationSpecificField = 0.0f;

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
void drawRectangle();

void drawRectangle()
{
    glBegin(GL_QUADS);

    // Front face
    glColor3f(0.0f, 0.0f, 1.0f); // blue
    glVertex3f(-0.8f, 0.3f, 0.5f);
    glVertex3f(-0.8f,-0.3f, 0.5f);
    glVertex3f( 0.0f,-0.3f, 0.5f);
    glVertex3f( 0.0f, 0.3f, 0.5f);

    // Back face
    glColor3f(0.0f, 1.0f, 1.0f); // Cyan
    glVertex3f(-0.8f, 0.3f, -0.5f);
    glVertex3f(-0.8f,-0.3f, -0.5f);
    glVertex3f( 0.0f,-0.3f, -0.5f);
    glVertex3f( 0.0f, 0.3f, -0.5f);

    // Left face
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex3f(-0.8f, 0.3f, 0.5f);
    glVertex3f(-0.8f,-0.3f, 0.5f);
    glVertex3f(-0.8f,-0.3f,-0.5f);
    glVertex3f(-0.8f, 0.3f,-0.5f);

    // Right face
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex3f(0.0f, 0.3f, 0.5f);
    glVertex3f(0.0f,-0.3f, 0.5f);
    glVertex3f(0.0f,-0.3f,-0.5f);
    glVertex3f(0.0f, 0.3f,-0.5f);

    // Top face
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glVertex3f(-0.8f, 0.3f, 0.5f);
    glVertex3f( 0.0f, 0.3f, 0.5f);
    glVertex3f( 0.0f, 0.3f,-0.5f);
    glVertex3f(-0.8f, 0.3f,-0.5f);

    // Bottom face
    glColor3f(1.0f, 0.0f, 1.0f); // Magenta
    glVertex3f(-0.8f,-0.3f, 0.5f);
    glVertex3f( 0.0f,-0.3f, 0.5f);
    glVertex3f( 0.0f,-0.3f,-0.5f);
    glVertex3f(-0.8f,-0.3f,-0.5f);

    glEnd();
}
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


void reset()
{
    positionx = 0.0f;
    positiony = 0.0f;
    movementspeed = 10.0f;
    rotationangle = 0.0f;
    rotationx = 0.0f;
    rotationy = 0.0f;
    rotationz = 0.0f;
    rotationSpecificField = 0.0f;
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

            case GLFW_KEY_1: questionNum = 1; reset(); break;
            case GLFW_KEY_2: questionNum = 2; reset(); break;
            case GLFW_KEY_3: questionNum = 3; reset(); break;
            case GLFW_KEY_4: questionNum = 4; reset(); break;
            case GLFW_KEY_5: questionNum = 5; reset(); break;
            case GLFW_KEY_6: questionNum = 6; reset(); break;

            case GLFW_KEY_UP:
                positiony += 0.01f;
                break;

            case GLFW_KEY_DOWN:
                positiony -= 0.01f;
                break;

            case GLFW_KEY_LEFT:
                rotationSpecificField -= 10.0f;
                break;

            case GLFW_KEY_RIGHT:
                rotationSpecificField += 10.0f;
                break;

            case GLFW_KEY_O:
                rotationangle += movementspeed;
                std::cout << "Rotation angle: " << rotationangle << std::endl;
                break;

            case GLFW_KEY_P:
                rotationangle -= movementspeed;
                std::cout << "Rotation angle: " << rotationangle << std::endl;
                break;

            // key to rotate x y,z axis
            case GLFW_KEY_X:
                if (questionNum == 1)
                {
                    rotationx = 1.0f;
                    rotationy = 0.0f;
                    rotationz = 0.0f;
                }else
                {
                    if (rotationx == 1.0f)
                    {
                        rotationx = 0.0f;
                    }else
                    {
                        rotationx = 1.0f;
                    }
                }
                std::cout << "Rotation x: " << rotationx << std::endl;
                break;
            case GLFW_KEY_Y:
                if (questionNum == 1)
                {
                    rotationx = 0.0f;
                    rotationy = 1.0f;
                    rotationz = 0.0f;
                }else
                {
                    if (rotationy == 1.0f)
                    {
                        rotationy = 0.0f;
                    }else
                    {
                        rotationy = 1.0f;
                    }
                }
                std::cout << "Rotation y: " << rotationy << std::endl;
                break;
            case GLFW_KEY_Z:
                if (questionNum == 1)
                {
                    rotationx = 0.0f;
                    rotationy = 0.0f;
                    rotationz = 1.0f;
                }else
                {
                    if (rotationz == 1.0f)                    
                    {
                        rotationz = 0.0f;
                    }else
                    {
                        rotationz = 1.0f;
                    }
                }
                std::cout << "Rotation z: " << rotationz << std::endl;
                break;
            case GLFW_KEY_SPACE:
                reset();
                break;
        }

    }
}

void one()
{
    rotationangle += movementspeed;
   // 3D pyramid

    glPushMatrix();
    glRotatef(rotationangle, rotationx, rotationy, rotationz);
    glBegin(GL_LINE_LOOP);
    glColor3f(1,0,0);
    glVertex3f(0.0f,0.5f,0.0f);
    glVertex3f(-0.5f,-0.5f,0.5f);
    glVertex3f(0.5f,-0.5f,0.5f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0,1,0);
    glVertex3f(0.0f,0.5f,0.0f);
    glVertex3f(0.5f,-0.5f,0.5f);
    glVertex3f(0.5f,-0.5f,-0.5f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,1);
    glVertex3f(0.0f,0.5f,0.0f);
    glVertex3f(0.5f,-0.5f,-0.5f);
    glVertex3f(-0.5f,-0.5f,-0.5f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(1,1,0);
    glVertex3f(0.0f,0.5f,0.0f);
    glVertex3f(-0.5f,-0.5f,-0.5f);
    glVertex3f(-0.5f,-0.5f,0.5f);
    glEnd();

    glPopMatrix();


 
}

void two()
{
    glPushMatrix();
    glTranslatef(positionx, positiony, 0.0f);
    glRotatef(rotationangle, rotationx, rotationy, rotationz);
    
    glPushMatrix();
    glRotatef(rotationSpecificField, 0.0f, 0.0f, 1.0f);
    drawRectangle();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-rotationSpecificField, 0.0f, 0.0f, 1.0f);
    glPushMatrix();
    glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
    drawRectangle();
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();

    
}

void three()
{
    
}

void four()
{
    


}

void five()
{
    
}

void six()
{
    
}


void display()
{

    glClearColor(0.3f,0.3f,0.3f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

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