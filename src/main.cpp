#include <iostream>
#include <cstdlib>
#include <stack>

#include "PML/MatrixPrakash.h"
#include "SlideCore.h"
#include "Fringe.h"
#include "Node.h"
#include "Problem.h"

using namespace std;

int main()
{
	cout<<" Hello World !"<<endl;
	SlideCore Initial(3,3);
	SlideCore Goal(Initial);
	Goal.Move(Direction::Down);
	Goal.Move(Direction::Down);
	Goal.Move(Direction::Right);
	Problem EightProblem(Initial,Goal);
	EightProblem.DisplayInfo();
	EightProblem.Solve();
	return 0;
}
