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
	SlideCore Goal(4,4);
	SlideCore Initial(Goal);
	Initial.Move(Direction::Down);
	Initial.Move(Direction::Down);
	Initial.Move(Direction::Right);
	Initial.Move(Direction::Right);
	Initial.Move(Direction::Right);
	Initial.Move(Direction::Up);

	Problem EightProblem(Initial,Goal);
	EightProblem.DisplayInfo();
	EightProblem.Solve();
	return 0;
}
