#ifndef DISPLAYCANVAS_H
#define DISPLAYCANVAS_H

#include <wx/glcanvas.h>
#include <wx/wx.h>
#include <wx/msgdlg.h>
#include <GL/glut.h>
#include <string>
#include <sstream>
#include<vector>
#include <stack>
#include <queue>

#include "SlideCore.h"
#include "Fringe.h"
#include "Node.h"
#include "Problem.h"

using namespace std;

class DisplayCanvas : public wxGLCanvas
{
public:
	DisplayCanvas(wxWindow*);

	void OnPaint       (wxPaintEvent&);
	void DrawTriangle  ();
	void DrawCube      ();


	void DrawBoundary();
	void WhenKeyIsPressed(unsigned char,int,int);
	void WhenSpecialKeysPressed(int,int,int);
	void TimerFunc(int);
	void ControlWithMouse(int,int,int,int);
	void StartDrawing();
	void ChangeSize(int,int);
	void Render();
	void Initialize();

	void LoadAllImages();
	GLuint LoadPhoto(char*);
	void DisplayIt(SlideCore);
	void DrawOne(float,float,GLuint);

	void SolveStepWise();


protected:
	DECLARE_EVENT_TABLE()
private:

	float BLOCK_LENGTH = 0.47;
	float BLOCK_WIDTH  = 0.47;


	float WindowHeight=680, WindowWidth=680;
    GLuint Textures[15];

	SlideCore CurrentState;
	Problem EightProblem;
	vector<Direction> Solution;
	int MaxSteps = 0, StepCounter = 0;


	static const long ID_DisplayCanvas;
	void OnKeyPress(wxKeyEvent&);
	GLuint LoadImageFile(string);
	void DisplaySinglePhoto(float,float,GLuint);
};

#endif // DISPLAYCANVAS_H
