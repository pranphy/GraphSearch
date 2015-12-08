#include "DisplayCanvas.h"

const long DisplayCanvas::ID_DisplayCanvas = wxNewId();
const long DisplayCanvas::ID_SecondTimer = wxNewId();



BEGIN_EVENT_TABLE(DisplayCanvas,wxGLCanvas)
    EVT_PAINT(DisplayCanvas::OnPaint)
    EVT_KEY_DOWN(DisplayCanvas::OnKeyPress)
    EVT_TIMER(ID_SecondTimer,DisplayCanvas::OnSolveAutomatic)
END_EVENT_TABLE()


DisplayCanvas::DisplayCanvas(wxWindow*Parent):
    wxGLCanvas(Parent, ID_DisplayCanvas,  wxDefaultPosition, wxSize(150,100), 0, wxT("GLCanvas"))
{
    int argc = 1;
    char* argv[1] = { wxString((wxTheApp->argv)[0]).char_str() };
    glutInit(&argc,argv);
    Initialize();
    SecondTimer = new wxTimer(this,ID_SecondTimer);
    ImagePath = string("./res/images/DK");
}

void DisplayCanvas::Initialize()
{
	SetCurrent();
	glEnable(GL_DEPTH_TEST);
    LoadAllImages();

	SlideCore Goal(4,4);
    SlideCore Initial(Goal);
	CurrentState = Initial;

	ScrambleCurrentState();

	EightProblem.SetGoalState(Goal);
	//EightProblem.SetInitialState(Initial);
	//EightProblem.Solve();
	Solution = EightProblem.GetSolution();
	MaxSteps = Solution.size();
	//CurrentState = Initial;
	//LoadAllImages();
	//ShuffleCards();
}

void DisplayCanvas::ScrambleCurrentState()
{
	//CurrentState = SlideCore(4,4);
	//vector<Direction> Steps = {Right,Down,Right,Down,Left,Down,Right};
	//vector<Direction> Steps = {Right,Down,Left,Down,Right,Down,Left,Up,Right,Up};
	vector<Direction> Steps = {Right,Down,Right,Down,Left,Down,Right};
	for(Direction Dir:Steps)
		CurrentState.Move(Dir);
	EightProblem.SetInitialState(CurrentState);
}


void DisplayCanvas::OnPaint(wxPaintEvent& WXUNUSED(event))
{
	SetCurrent();
	static bool OneTime = false;
	if(OneTime == false)
	{
		LoadAllImages();
		OneTime = true;
	}
    glClearColor(1.0f,1.0f,1.0f,0);
    glClear(GL_COLOR_BUFFER_BIT);
    DrawTriangle();
    Render();

    glFlush();
    SwapBuffers();
    if(Finished)
	{
		wxMessageBox(wxT("Finished Solving"),wxT("Completed"));
		Finished = false;
	}
}

void DisplayCanvas::Analyze()
{
	wxMessageBox(
		wxT(" \
			Analyzing the problem\n \
			to solve using Search algorithm \
		"),
		wxT("\
			Generating Solution\
		")
	);
	EightProblem.ClearSequence();
	//EightProblem.DisplayInfo();
	EightProblem.Solve();
	Solution = EightProblem.GetSolution();
	MaxSteps = Solution.size();
	StepCounter = 0;
}

void DisplayCanvas::OnKeyPress(wxKeyEvent& event)
{
    int Key = event.GetUnicodeKey();
    if(Key == 13)
    {
    	SolveAutomatic();

    }
    else if(Key == '1')
	{
		Analyze();
	}

    switch(event.GetKeyCode())
    {
    case WXK_LEFT:
		CurrentState.Move(Direction::Left);
        break;
    case WXK_RIGHT:
		CurrentState.Move(Direction::Right);
        break;
    case WXK_UP:
    	CurrentState.Move(Direction::Up);
        break;
    case WXK_DOWN:
		CurrentState.Move(Direction::Down);
    default:
    	Finished = false;
        break;

    }

    EightProblem.SetInitialState(CurrentState);

    wxPaintEvent Dummy = wxPaintEvent();
    OnPaint(Dummy);
}


void DisplayCanvas::DrawTriangle()
{
    glPushMatrix();

    glViewport(0, 0, (GLint)GetSize().x, (GLint)GetSize().y);
    glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLES);
        glColor3ub((GLubyte)255,(GLubyte)0,(GLubyte)0);
        glVertex3f(0.0f,0.5f,0.0f);
        // Green on the right bottom corner
        glColor3ub((GLubyte)0,(GLubyte)255,(GLubyte)0);
        glVertex3f(0.50f,-0.90f,0.0f);
        // Blue on the left bottom corner
        glColor3ub((GLubyte)0,(GLubyte)0,(GLubyte)255);
        glVertex3f(-0.50f, -0.9000f, -0.0f);
    glEnd();
    glColor3ub((GLubyte)255,(GLubyte)255,(GLubyte)255); //reset white color.
    glPopMatrix();
}



void DisplayCanvas::DisplayIt(SlideCore Kernal)
{
    float InitialX=-0.7,InitialY=0.7;
	static float y=InitialY;
	static float x=InitialX;
	//glColor3f(0,1,1);
	glLoadIdentity();
	glTranslatef(0,0,-0.5);
	//glRectf(InitialX,InitialY,x,y);
	y=InitialY;
	x=InitialX;

	for(int i=0;i<Kernal.Row;i++)
	{
		x=InitialX;
		for(int j=0;j<Kernal.Col;j++)
		{
			int Current=Kernal.GetVal(i,j);
			if(Current)
			{
				DrawOne(x,y,Textures[Current-1]);
			}
			x += BLOCK_LENGTH - 0.001;
		}
		y -= BLOCK_WIDTH - 0.001;
	}
}

void DisplayCanvas::LoadAllImages()
{
   string ImageRoot = ImagePath;
    for(int i=0;i<15;i++)
    {
    	ostringstream ImageName;
    	ImageName<<ImageRoot<<"/CC"<<i+1<<".png";
        Textures[i]=LoadImageFile(ImageName.str());
    }
}

void DisplayCanvas::Render()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
    DisplayIt(CurrentState);


}

void DisplayCanvas::DrawOne(float PositionX, float PositionY, GLuint ImageTexture)
{
	glLoadIdentity();
    glTranslatef(PositionX,PositionY,-0.3);
    glBindTexture(GL_TEXTURE_2D,ImageTexture);
    glEnable(GL_TEXTURE_2D);
    float factor=1;
    float IMAGE_LENGTH=BLOCK_LENGTH;
    float IMAGE_BREADTH=BLOCK_WIDTH;
	//glColor3f(1,1,0);

	glBegin(GL_QUADS);
        glTexCoord3f(1.0f,0.0f,0.0f);           glVertex3f(factor*IMAGE_BREADTH/2,-factor*IMAGE_LENGTH/2,0);
        glTexCoord3f(1.0f,1.0f,0.0f);           glVertex3f(factor*IMAGE_BREADTH/2,factor*IMAGE_LENGTH/2,0);
        glTexCoord3f(0.0f,1.0f,0.0f);           glVertex3f(-factor*IMAGE_BREADTH/2,factor*IMAGE_LENGTH/2,0);
        glTexCoord3f(0.0f,0.0f,0.0f);           glVertex3f(-factor*IMAGE_BREADTH/2,-factor*IMAGE_LENGTH/2,0);
    glEnd();
}

void DisplayCanvas::StartDrawing(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void DisplayCanvas::ChangeSize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 0.2, 200.0);
}

void DisplayCanvas::SolveStepWise()
{
		//Call this in a second;
	if(StepCounter < MaxSteps)
		CurrentState.Move(Solution.at(StepCounter++));
	if(StepCounter == MaxSteps)
	{
		Finished = true;
		SecondTimer->Stop();
		//wxMessageBox(wxT("Finished Solving"),wxT("Completed"));
	}
	wxPaintEvent Dummy = wxPaintEvent();
    OnPaint(Dummy);

}

void DisplayCanvas::SolveAutomatic()
{
	SecondTimer->Start(1000);
}

void DisplayCanvas::OnSolveAutomatic(wxTimerEvent& event)
{
	SolveStepWise();
}

void DisplayCanvas::TimerFunc(int value)
{
    glutPostRedisplay();
    //glutTimerFunc(10, TimerFunc, 0);
}

void DisplayCanvas::SetImagePath(string Path)
{
	ImagePath = Path;
}

GLuint DisplayCanvas::LoadImageFile(string FileName)
{
	//wxImage* img = new wxImage(wxString::FromUTF8(FileName.c_str()));
	wxImage* img = new wxImage(wxString::FromUTF8(FileName.c_str()));

	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	GLubyte *bitmapData=img->GetData();
	GLubyte *alphaData=img->GetAlpha();

	int bytesPerPixel = img->HasAlpha() ?  4 : 3;
	int imageWidth = img->GetWidth();
	int imageHeight = img->GetHeight();

	int imageSize = imageWidth * imageHeight * bytesPerPixel;
	GLubyte *imageData=new GLubyte[imageSize];

	int rev_val=imageHeight-1;

	for(int y=0; y<imageHeight; y++)
	{
		for(int x=0; x<imageWidth; x++)
		{
			imageData[(x+y*imageWidth)*bytesPerPixel+0]=
					bitmapData[( x+(rev_val-y)*imageWidth)*3];

			imageData[(x+y*imageWidth)*bytesPerPixel+1]=
					bitmapData[( x+(rev_val-y)*imageWidth)*3 + 1];

			imageData[(x+y*imageWidth)*bytesPerPixel+2]=
					bitmapData[( x+(rev_val-y)*imageWidth)*3 + 2];

			if(bytesPerPixel==4) imageData[(x+y*imageWidth)*bytesPerPixel+3]=
					alphaData[ x+(rev_val-y)*imageWidth ];
		}
	}

	glTexImage2D(GL_TEXTURE_2D,
					0,
					bytesPerPixel,
					imageWidth,
					imageHeight,
					0,
					img->HasAlpha() ?  GL_RGBA : GL_RGB,
					GL_UNSIGNED_BYTE,
					imageData);

	delete[] imageData;
	wxDELETE(img);

	return texture;
}
