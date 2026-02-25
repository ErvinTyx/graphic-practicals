#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <stdio.h>

// Global variables
int questionNum = 1;

float positionx = 0.0f;
float positiony = 0.0f;
float automovex = 0.0f;
float automovey = 0.0f;
float autoscale = 1.0f;
float movementspeed = 0.1f;
float rotationangle = 0.0f;
float red = 1.0f;
float green = 1.0f;
float blue = 1.0f;


// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void display();
float DegreeToRadian(float degree);
void DrawCircle(float radius);
void one();
void two();
void three();
void four();
void setRed();
void setGreen();
void setBlue();
void resetColor();
void resetPosition();
void resetRotation();
void DrawStar(float radius, float positionx, float positiony, float rotationangle);

void DrawStar(float radius, float positionx = 0.0f, float positiony = 0.0f, float rotationangle = 0.0f, float red = 1.0f, float green = 1.0f, float blue = 0.0f){
    // draw star
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(red, green, blue);
    glVertex2f(positionx, positiony);  // center of star
    for (int i = 0; i < 360; i += 72)
    {
        float tempX, tempY;
        tempX = positionx + radius * sin(DegreeToRadian(i + rotationangle));
        tempY = positiony + radius * cos(DegreeToRadian(i + rotationangle));
        glVertex2f(tempX, tempY);

        tempX = positionx + radius/2.0f * sin(DegreeToRadian(i + 36 + rotationangle));  // offset by 36 degrees for star points
        tempY = positiony + radius/2.0f * cos(DegreeToRadian(i + 36 + rotationangle));
        glVertex2f(tempX, tempY);
    }
    glVertex2f(positionx + radius * sin(DegreeToRadian(0 + rotationangle)), positiony + radius * cos(DegreeToRadian(0 + rotationangle)));  // close fan
    glEnd();
}

void resetRotation()
{
    rotationangle = 0.0f;
}


void resetPosition()
{
    positionx = 0.0f;
    positiony = 0.0f;
}

void setRed()
{
    red = 1.0f;
    green = 0.0f;
    blue = 0.0f;
}

void setGreen()
{
    red = 0.0f;
    green = 1.0f;
    blue = 0.0f;
}

void setBlue()
{
    red = 0.0f;
    green = 0.0f;
    blue = 1.0f;
}

void resetColor()
{
    red = 1.0f;
    green = 1.0f;
    blue = 1.0f;
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
            case GLFW_KEY_R:
                setRed();
                break;
            case GLFW_KEY_G:
                setGreen();
                break;
            case GLFW_KEY_B:
                setBlue();
                break;
            case GLFW_KEY_SPACE:
                resetColor();
                resetPosition();
                resetRotation();
                break;
        }

    }
}

void one()
{
    glLoadIdentity();

    glTranslatef(positionx, positiony,0);
    glRotatef(rotationangle,0,0,1);


    glBegin(GL_POLYGON);
    glColor3f(red,green,blue); //white
    glVertex2f(-0.5f,0.5f);
    glVertex2f(-0.5f,-0.5f);
    glVertex2f(0.5f,-0.5f);
    glVertex2f(0.5f,0.5f);
    glEnd();

}

void two()
{
    // make the star bounce around the screen by using positionx and positiony automatically updated in the key callback function

    automovex += movementspeed * 0.5f; // move right
    automovey += movementspeed * 0.3f; // move up
    autoscale += movementspeed * 0.2f; // scale up
    rotationangle += movementspeed * 50.0f; // rotate
    
    DrawStar(.5f * autoscale, automovex, automovey, rotationangle, red, green, blue=0.0f);
     // bounce back when hitting the edges of the screen
    if (automovex > 0.8f || automovex < -0.8f)
    {
        movementspeed *= -1;
        // make yellow color increment change when bouncing
        float delta = 0.5f;
        if (red > delta)
        {
            red -= delta;
            green -= delta;
        }
        else
        {
            red += delta;
            green += delta;
        }
    }
}

void three()
{
    // Create an OpenGL point which moving anti-clockwise using glTransform and glRotation.
    static float angle = 0.0f;
    angle += 1.0f; // Increment angle by 1 degree each frame
    float radius = 0.5f;
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // red point
    glVertex2f(radius, 0.0f);
    glEnd();
    glPopMatrix();
}

void four()
{
    // Create an expendable red box which will expend it size automatically and shrink back when hitting the edges.
    static float scale = 0.1f;
    scale += 0.01f; // Increase scale over time
    if (scale > 1.0f) scale = 0.1f; // Reset scale when it exceeds 1.0f
    glPushMatrix();
    glScalef(scale, scale, 1.0f);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // red color
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(0.5f, -0.5f);
    glEnd();
    glPopMatrix();
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