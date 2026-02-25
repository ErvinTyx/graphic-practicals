
#include <Windows.h> // 1. importing library of code allow us to talk to window OS (microsoft provided API to create window)
#include <gl/GL.h>   // 2. talk to your graphic card bacause concern about the speed 
#include <math.h>

#pragma comment (lib, "OpenGL32.lib") // only works for windows based to link additonal library 

#define WINDOW_TITLE "Practical" // use it as window name, giving compiler know the preprocessor, preprocessor is intruction to compiler before you do any thing
#define CLASS_NAME "Game Window Class" // use it as window class

// Global system varaible
int questionNum = 1;


float positionx = 0.0f;
float positiony = 0.0f;
float movementspeed = 0.1f;
float rotationangle = 0.0f;


LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		switch (wParam) {
		case VK_ESCAPE: {
			PostQuitMessage(0);
			break;
		}
		case 0x31: {
			questionNum = 1;
			break;
		}
		case 0x32: {
			questionNum = 2;
			break;
		}
		case 0x33: {
			questionNum = 3;
			break;
		}
		case 0x34: {
			questionNum = 4;
			break;
		}
		case 0x35: {
			questionNum = 5;
			break;
		}
		case 0x36: {
			questionNum = 6;
			break;
		}
		case VK_UP: {
			positiony += movementspeed;
			break;
		}
		case VK_DOWN: {
			positiony -= movementspeed;
			break;
		}case VK_LEFT: {
			positionx -= movementspeed;
			break;
		}
		case VK_RIGHT: {
			positionx += movementspeed;
			break;
		}
		case 0x4F: {
			rotationangle += movementspeed;
			break;
		}
		case 	0x50: {
			rotationangle -= movementspeed;
			break;
		}
		}
		break;

	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//--------------------------------------------------------------------

bool initPixelFormat(HDC hdc) // HDC = handle to display context (like a pointer, you can grab it)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 0;

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	// choose pixel format returns the number most similar pixel format available
	int n = ChoosePixelFormat(hdc, &pfd);

	// set pixel format returns whether it sucessfully set the pixel format
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//--------------------------------------------------------------------

float DegreeToRadian(float degree) {
	return degree * 3.142 / 180;
};

float DrawCircle(float radius) {
	float tempX;
	float tempY;
	for (int i = 0; i < 360; i += 10)
	{
		tempX = radius * sin(DegreeToRadian(i));
		tempY = radius * cos(DegreeToRadian(i));
		glVertex2f(tempX, tempY);
	}
	return radius;
}

void display()
{

	//--------------------------------
	//	OpenGL drawing
	//--------------------------------
	glClearColor(0.3f, 0.3f, 0.3f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	//glLineWidth(5);
	//glPointSize(10)

	switch (questionNum) {
	case 1: {
		glLoadIdentity();
		glTranslatef(positionx, positiony, 0.0f);
		glRotatef(rotationangle, 0.0f, 0.0f, 1.0f);

		glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 1.0f);  //white
		glVertex2f(-0.8f, 0.5f);
		glVertex2f(-0.8f, 0.0f);
		glVertex2f(0.8f, 0.0f);
		glVertex2f(0.8f, 0.5f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.0f, 0.0f, 0.0f);  //black
		glVertex2f(-0.8f, 0.0f);
		glVertex2f(-0.8f, -0.5f);
		glVertex2f(0.8f, -0.5f);
		glVertex2f(0.8f, 0.0f);
		glEnd();
		break;
	}
	case 2: {
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
		break;
	}
	case 3: {
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
		break;
	}
	case 4: {
		

		glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 0.0f, 1.0f);  //blue
		glVertex2f(-0.7f, 0.5f);
		glVertex2f(0.0f, 0.1f);
		glVertex2f(0.7f, 0.5f);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 0.0f, 1.0f);  //blue
		glVertex2f(-0.8f, 0.4f);
		glVertex2f(-0.1f, 0.0f);
		glVertex2f(-0.8f, -0.4f);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 0.0f, 1.0f);  //blue
		glVertex2f(-0.7f, -0.5f);
		glVertex2f(0.0f, -0.1f);
		glVertex2f(0.7f, -0.5f);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 0.0f, 1.0f);  //blue
		glVertex2f(0.8f, 0.4f);
		glVertex2f(0.1f, 0.0f);
		glVertex2f(0.8f, -0.4f);
		glEnd();
		break;
	}
	case 5: {
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
		break;
	}
	case 6: {
		glBegin(GL_POLYGON);
		glColor3f(1.0f, 1.0f, 0.0f);  //yellow
		DrawCircle(0.5);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.0f, 0.0f, 0.0f);  //black
		glVertex2f(-0.18f, 0.25f);
		glVertex2f(-0.18f, 0.18f);
		glVertex2f(-0.12f, 0.18f);
		glVertex2f(-0.12f, 0.25f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.0f, 0.0f, 0.0f);  //black
		glVertex2f(0.12f, 0.25f);
		glVertex2f(0.12f, 0.18f);
		glVertex2f(0.18f, 0.18f);
		glVertex2f(0.18f, 0.25f);
		glEnd();

		glBegin(GL_LINE_STRIP);
		glColor3f(1.0f, 0.0f, 0.0f);  //red
		glLineWidth(100.0f);
		for (int i = 90; i <= 270; i += 5) {
			float tempX = 0.25f * sin(DegreeToRadian(i));
			float tempY = 0.25f * cos(DegreeToRadian(i)) - 0.05f;
			glVertex2f(tempX, tempY);
		}
		glEnd();
		break;
	}
	}
	//--------------------------------
	//	End of OpenGL drawing
	//--------------------------------
}
//--------------------------------------------------------------------

// Entry point - all program must have one 
// The OS is that one will call the main function
// 1st parameter = ID number to the window (microsoft will provide the ID)  
// 2nd parameter = HINSTANCE prevInstance (no longer use already but still there)
// 3rd parameter = Long pointer to a string = command line parameter
// 4th parameter = nothing special no need to change 
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE prevInstance, LPSTR cmdLineParam, int nCmdShow)
{
	WNDCLASSEX wc;																		// Data Structure to store our window class description 
	ZeroMemory(&wc, sizeof(WNDCLASSEX));												// filled in zero inside because, dont know what you need

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);											// hInst or GetModuleHandle(NULL)
	wc.lpfnWndProc = WindowProcedure;												// Long pointer to a function = windows procedure function 
	wc.lpszClassName = CLASS_NAME;													// Long pointer to zero terminated string = class name
	wc.style = CS_HREDRAW | CS_VREDRAW;												// redraw thing form window when resize it 

	if (!RegisterClassEx(&wc)) return false;										//create window

	HWND hWnd = CreateWindow(CLASS_NAME, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 800,										//Get square window
		NULL, NULL, wc.hInstance, NULL);

	//--------------------------------
	//	Initialize window for OpenGL
	//--------------------------------

	HDC hdc = GetDC(hWnd);

	//	initialize pixel format for the window
	initPixelFormat(hdc);

	//	get an openGL context
	HGLRC hglrc = wglCreateContext(hdc);

	//	make context current
	if (!wglMakeCurrent(hdc, hglrc)) return false;

	//--------------------------------
	//	End initialization
	//--------------------------------

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (true) // infinite loop
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		display();

		SwapBuffers(hdc);
	}

	UnregisterClass(CLASS_NAME, wc.hInstance);       // clean up and shut down the programme

	return true;
}

//--------------------------------------------------------------------