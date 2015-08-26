#include "Problem.h"

Problem::Problem()
{
	//ctor
}

Problem::Problem(SlideCore Begin, SlideCore End):InitialState(Begin),GoalState(End){}

bool Problem::IsGoal(Node& TestNode)
{
	SlideCore CurrentState = TestNode.GetState();
	return GoalState == CurrentState;
}


void Problem::DisplayInfo()
{
	cout<<" My initial State is "<<endl<<InitialState<<endl;
	cout<<" I am trying to reach "<<endl<<GoalState<<endl;
}

vector<Direction> Problem::GetSolution()
{
	return SolutionSteps;
}

void Problem::SetInitialState(SlideCore Init)
{
	InitialState = Init;
	SolutionSteps.clear();
	//To clear the sequence.
	ClearSequence();
}

void Problem::ClearSequence()
{
	while(!Sequence.empty())
		Sequence.pop();
}

void Problem::SetGoalState(SlideCore Fin)
{
	GoalState = Fin;
}

bool Problem::Solve()
{
	cout<<" Somebody requested me to solve the puzzle "<<endl;
	Node RootNode(InitialState,InitialState);
	vector<Node> RootChildren = RootNode.GetChildren();
	Sequence.PutChildren(RootChildren);
	unsigned Counter = 0;//,p;
	while(Counter < 999999)
	{
		if(Sequence.empty())
		{
			cout<<" No Solution "<<endl;
			return false;
		}
		else
		{
			Node CurrentNode = Sequence.front(); Sequence.pop();
			//cout<<" Current Node "<<endl;
			//CurrentNode.DisplayDetail();
			//cin>>p;
			if(IsGoal(CurrentNode))
			{
				cout<<" Solution Found "<<endl;
				SolutionSteps = CurrentNode.GetStepsTaken();
				//string Dir[] = {"UP","Down","Left","Right"};
				//SlideCore Current = InitialState;
//				for(auto St : SolutionSteps)
//				{
//					Current.Move(St);
//					cout<<Dir[St]<<" then "<<endl;
//					cout<<Current<<endl;
//				}
//				cout<<" Depath is "<<CurrentNode.GetDepth()<<endl;
				return true;
			}

			else
			{
				vector<Node> Children = CurrentNode.GetChildren();
				Sequence.PutChildren(Children);
			}
		}
		Counter++;
		//cout<<" Fringe size "<<Sequence.size()<<endl;
	}
	cout<<" Steps exceeded "<<endl;
	return true;
}

