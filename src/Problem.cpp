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

bool Problem::Solve()
{
	Node RootNode(InitialState,InitialState);
	vector<Node> RootChildren = RootNode.GetChildren();
	Sequence.PutChildren(RootChildren);
	unsigned Counter = 0;//,p;
	while(Counter < 99999)
	{
		if(Sequence.empty()){
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
				string Dir[] = {"UP","Down","Left","Right"};
				for(auto St : SolutionSteps)
					cout<<Dir[St]<<" then "<<endl;
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
	return true;
}

