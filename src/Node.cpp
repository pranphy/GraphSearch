#include "Node.h"

Node::Node()
{

	//ctor
}

Node::Node(SlideCore Stat, SlideCore Prnt):State(Stat),Parent(Prnt)
{
	PathCost = 0;
	Depth = 0;
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
	vector<Direction> Moves = State.PossibleMoves();
	vector<SlideCore> Children = State.MakeAllMoves();
	vector<Node> ChildNodes;
	ChildNodes.reserve(Moves.size());
	unsigned Counter = 0;
	for(SlideCore Child : Children)
	{
		Node CurrentNode(Child,State); //Child is CurrentState and State is parent
		CurrentNode.SetAction(Moves.at(Counter));
		CurrentNode.SetDepth(Depth+1);
		CurrentNode.SetPathCost(1);
		Counter++;
		ChildNodes.push_back(CurrentNode);
	}
	return ChildNodes;
}

SlideCore Node::GetState() const
{
	return State;
}
