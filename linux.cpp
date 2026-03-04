#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <stdio.h>
#include <iostream>

// Global variables
int questionNum = 1;

float positionx = 0.0f;
float positiony = 0.0f;
float movementspeed = 0.1f;
float rotationangle = 0.0f;
float rotationSpeed = 1.0f;

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
void DrawFloorBrown();
void DrawFloorGreen();
void DrawFlower(float x, float y, float colorR, float colorG, float colorB , float innerColorR, float innerColorG, float innerColorB);
void DrawCloud();
void DrawSemiCircle(float radius);
void DrawOval(float radiusX, float radiusY);
void DrawFan();
void DrawPropeller();

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

void DrawSemiCircle(float radius)
{
    for (int i = 0; i < 180; i += 10)
    {
        float tempX = radius * sin(DegreeToRadian(i));
        float tempY = radius * cos(DegreeToRadian(i));

        glVertex2f(tempX, tempY);
    }
}

void DrawOval(float radiusX, float radiusY)
{
    for (int i = 0; i < 360; i += 10)
    {
        float tempX = radiusX * sin(DegreeToRadian(i));
        float tempY = radiusY * cos(DegreeToRadian(i));

        glVertex2f(tempX, tempY);
    }
}

void DrawFan()
{
    // draw retangle

    //glTranslatef(0.0f, 0.1f, 0.0f); //  
    
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);  // blue
    glVertex2f(-0.01f, -0.5f);
    glVertex2f(-0.01f, 0.5f);
    glVertex2f(0.01f, 0.5f);
    glVertex2f(0.01f, -0.5f);
    glEnd();


    //glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);  // blue
    glVertex2f(-0.01f, -0.5f);
    glVertex2f(-0.01f, 0.5f);
    glVertex2f(0.01f, 0.5f);
    glVertex2f(0.01f, -0.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
    glTranslatef(-0.05f, 0.35f, 0.0f);
    DrawPropeller();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
    glTranslatef(-0.05f, 0.35f, 0.0f);
    DrawPropeller();
    glPopMatrix();

    glPushMatrix();
    glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
    glTranslatef(-0.05f, 0.35f, 0.0f);
    DrawPropeller();
    glPopMatrix();

    glPushMatrix();
    glRotatef(270.0f, 0.0f, 0.0f, 1.0f);
    glTranslatef(-0.05f, 0.35f, 0.0f);
    DrawPropeller();
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);  // white
    DrawCircle(0.05f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);  // red
    DrawCircle(0.025f);
    glEnd();




    //DrawPropeller();




}

void DrawPropeller()
{
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);  // blue
    glVertex2f(-0.05f, -0.15f);
    glVertex2f(-0.05f, 0.15f);
    glVertex2f(0.05f, 0.15f);
    glVertex2f(0.05f, -0.15f);
    glEnd();
}

void DrawFlower(float x, float y, float colorR, float colorG, float colorB , float innerColorR, float innerColorG, float innerColorB)
{   
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    //draw stem
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);  // Green
    glVertex2f(-0.01f, -0.22f);
    glVertex2f(-0.01f, 0.0f);
    glVertex2f(0.01f, 0.0f);
    glVertex2f(0.01f, -0.22f);
    glEnd();

    // draw flower petals
    glPushMatrix();
    glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, 0.065f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(colorR, colorG, colorB);  // Yellow
    DrawOval(0.02f, 0.04f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, 0.065f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(colorR, colorG, colorB);  // Yellow
    DrawOval(0.02f, 0.04f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, 0.065f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(colorR, colorG, colorB);  // Yellow
    DrawOval(0.02f, 0.04f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(135.0f, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, 0.065f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(colorR, colorG, colorB);  // Yellow
    DrawOval(0.02f, 0.04f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, 0.065f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(colorR, colorG, colorB);  // Yellow
    DrawOval(0.02f, 0.04f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(225.0f, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, 0.065f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(colorR, colorG, colorB);  // Yellow
    DrawOval(0.02f, 0.04f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(270.0f, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, 0.065f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(colorR, colorG, colorB);  // Yellow
    DrawOval(0.02f, 0.04f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(315.0f, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, 0.065f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(colorR, colorG, colorB);  // Yellow
    DrawOval(0.02f, 0.04f);
    glEnd();
    glPopMatrix();

    // draw flower center
    glBegin(GL_POLYGON);
    glColor3f(innerColorR, innerColorG, innerColorB);  // Brown
    DrawCircle(0.04);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(colorR, colorG, colorB);  // Yellow
    DrawCircle(0.02);
    glEnd();

    glPopMatrix();

}

void DrawFloorBrown(){

    // draw circle floor
    glPushMatrix();
    glTranslatef(0.8f, -1.2f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.59f, 0.39f, 0.28f);  // brown
    DrawCircle(0.6f);
    glEnd();
    glPopMatrix();

    // draw circle floor
    glPushMatrix();
    glTranslatef(-0.8f, -1.2f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.59f, 0.39f, 0.28f);  // brown
    DrawCircle(0.6f);
    glEnd();
    glPopMatrix();

    // draw circle floor
    glPushMatrix();
    glTranslatef(0.0f, -1.2f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.59f, 0.39f, 0.28f);  // brown
    DrawCircle(0.8f);
    glEnd();
    glPopMatrix();
}

void DrawFloorGreen(){

    // draw circle floor
    glPushMatrix();
    glTranslatef(0.8f, -1.2f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.5f, 0.0f);  // green
    DrawCircle(0.6f);
    glEnd();
    glPopMatrix();

    // draw circle floor
    glPushMatrix();
    glTranslatef(-0.8f, -1.2f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.5f, 0.0f);  // green
    DrawCircle(0.6f);
    glEnd();
    glPopMatrix();

    // draw circle floor
    glPushMatrix();
    glTranslatef(0.0f, -1.2f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.5f, 0.0f);  // green
    DrawCircle(0.8f);
    glEnd();
    glPopMatrix();
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
            case GLFW_KEY_SPACE:
                rotationSpeed *= 0.0f;
                break;
            case GLFW_KEY_A:
                rotationSpeed += 0.1f;
                break;
            case GLFW_KEY_S:
                rotationSpeed -= 0.1f;
                break;
            case GLFW_KEY_Q:
                movementspeed *= -1.0f;
                break;
        }

    }
}

void DrawCloud(){
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    DrawCircle(0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.1f, -0.04f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    DrawCircle(0.06);
    glEnd();

    glPushMatrix();
    glTranslatef(0.06f, 0.00f, 0.0f);
    glScalef(1.7f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    DrawCircle(0.04);
    glEnd();

    glPushMatrix();
    glTranslatef(-0.15f, 0.01f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    DrawCircle(0.08);
    glEnd();

    glPushMatrix();
    glTranslatef(-0.06f, 0.00f, 0.0f);
    glScalef(1.5f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    DrawCircle(0.02);
    glEnd();
    glPopMatrix();
    glPopMatrix();



}



void one()
{
    /* 
    
    Draw the scene 
    
    
    */
    // draw sky
    glLoadIdentity();
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glColor3f(0.6f, 0.6f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glEnd();


    /* 
    Draw the clouds
    */
    glPushMatrix();
    glTranslatef(positionx, positiony, 0.0f);
    glTranslatef(0.0f, 0.5f, 0.0f);
    DrawCloud();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-0.6f+ positionx, 0.8f + positiony, 0.0f);
    glScalef(0.7, 0.7, 0.7);
    DrawCloud();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5f + positionx, 0.7f + positiony, 0.0f);
    glScalef(-0.4, 0.4, 0.7);
    DrawCloud();
    glPopMatrix();



    /* 
    Draw the floor

    */
    DrawFloorBrown();
    // if fan speed more than 5.0f or less than -5.0f move down
    if (rotationSpeed > 5.0f || rotationSpeed < -5.0f)
    {
        positiony -= 0.01f;
    }
    // if reset fan speed to 0.0f set to original position
    if (rotationSpeed == 0.0f)
    {
        positiony = 0.0f;
    }
    glPushMatrix();
    glTranslatef(positionx, positiony, 0.0f);
    DrawFloorGreen();

    /* 
    Draw the flowers
    */
    DrawFlower(-0.65f, -0.65f, 1.0f, 0.9f, 0.0f, 1.0f, 0.0f, 0.0f);// Yellow right flower
    DrawFlower(-0.9f, -0.7f, 1.0f, 0.9f, 0.0f, 1.0f, 0.0f, 0.0f);// Yellow left flower
    DrawFlower(-0.75f, -0.75f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f);// Red left flower
    DrawFlower(-0.5f, -0.7f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f);// Red right flower
    DrawFlower(0.5f, -0.65f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f);// Yellow left flower
    DrawFlower(0.8f, -0.65f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f);// Yellow left flower
    DrawFlower(0.6f, -0.7f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);// Magenta right flower
    DrawFlower(0.9f, -0.7f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);// Magenta right flower
    glPopMatrix();
    /*
    Draw the house
    */
    // draw house body
    glPushMatrix();
    glTranslatef(0.0f, -0.5f, 0.0f);
    glScalef(0.5f, 0.5f, 1.0f);
    glBegin(GL_QUADS);
    glColor3f(0.26f, 0.17f, 0.15f);  // #422c26
    glVertex2f(-0.3f, 0.5f);
    glVertex2f(0.3f, 0.5f);
    glVertex2f(0.8f, -0.5f);
    glVertex2f(-0.8f, -0.5f);
    glEnd();
    glPopMatrix();

    // draw roof
    glPushMatrix();
    glTranslatef(0.0f, -0.099f, 0.0f);
    glScalef(0.3f, 0.3f, 1.0f);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);  // red
    glVertex2f(-0.3f, 0.8f);
    glVertex2f(0.3f, 0.8f);
    glVertex2f(0.9f, -0.5f);
    glVertex2f(-0.9f, -0.5f);
    glEnd();
    glPopMatrix();

    /*
    Draw the fan
    */
    /* make spin */
    if (rotationSpeed > 0.0f || rotationSpeed < 0.0f)
    {
        rotationangle += rotationSpeed;
    }
    
    glPushMatrix();
    glRotatef(rotationangle+rotationSpeed, 0.0f, 0.0f, 1.0f);
    DrawFan();
    glPopMatrix();

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