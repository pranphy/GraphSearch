#include "Node.h"

Node::Node()
{
	//ctor
}

Node::Node(SlideCore Stat, SlideCore Prnt):State(Stat),Parent(Prnt)
{
	PathCost = 0;
	Depth = 0;
	Action = Direction::Up;
}

void Node::SetAction(Direction Act)
{
	Action = Act;
}

void Node::SetDepth(unsigned Deapth)
{
	Depth = Deapth;
}

void Node::SetPathCost(unsigned Cost)
{
	PathCost = Cost;
}

void Node::SetStepsTaken(vector<Direction> Steps)
{
	StepsTaken = Steps;
}

unsigned Node::GetDepth()
{
	return Depth;
}

vector<Direction> Node::GetStepsTaken()
{
	return StepsTaken;
}

void Node::DisplayDetail()
{
	cout<<" State "<<endl<<State<<endl;
	cout<<" Parent "<<endl<<Parent<<endl;
	cout<<" Action "<<Action<<endl;
	cout<<" PathCost "<<PathCost<<endl;
	cout<<" Depth "<<Depth<<endl;
}

vector<Node> Node::GetChildren()
{
	Direction LastAction = Action;
	Direction ReverseAction =
	(
		LastAction == Direction::Up ? Direction::Down :
		(
			LastAction == Direction::Down ? Direction::Up:
			(
				LastAction == Direction::Left ? Direction::Right : Direction::Left
			)
		)
	);

	//cout<<" Action was"<<LastAction<<" and reverse is "<<ReverseAction<<endl;
	vector<Direction> Moves = State.PossibleMoves();
	//cout<<endl<<" Vector was "<<endl;
	//for(auto d:Moves)
	//	cout<<d<<"   "<<endl;

	vector<Direction> RefinedMoves;
	for(auto Move : Moves)
		if(Move != ReverseAction)
			RefinedMoves.push_back(Move);

	RefinedMoves = Moves;

	//cout<<" Moves now "<<endl;
	//for(auto d:RefinedMoves)
	//	cout<<d<<"   "<<endl;

	vector<SlideCore> Children = State.MakeAllMoves();
	vector<Node> ChildNodes;
	ChildNodes.reserve(Moves.size());
	unsigned Counter = 0;
	for(auto Move : RefinedMoves)
	{
		SlideCore Child = State.MakeOneMove(Move);
		vector<Direction> LocalSteps = StepsTaken;
		LocalSteps.push_back(Move);
		Node CurrentNode(Child,State); //Child is CurrentState and State is parent
		CurrentNode.SetAction(Move);
		CurrentNode.SetDepth(Depth+1);
		CurrentNode.SetPathCost(1);
		CurrentNode.SetStepsTaken(LocalSteps);
		ChildNodes.push_back(CurrentNode);
		Counter++;
	}
	return ChildNodes;
}

SlideCore Node::GetState() const
{
	return State;
}
