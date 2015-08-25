#ifndef NODE_H
#define NODE_H

#include <algorithm>

#include "SlideCore.h"

class Node
{
	private:
		SlideCore State;
		SlideCore Parent;
		Direction Action;
		unsigned PathCost;
		unsigned Depth;
		vector<Direction> StepsTaken;
	protected:
		//
	public:
		Node();
		Node(SlideCore,SlideCore);
		SlideCore GetState() const;
		vector<Node> GetChildren();
		void SetAction(Direction);
		void SetDepth(unsigned);
		unsigned GetDepth();
		void SetPathCost(unsigned);
		void DisplayDetail();
		void SetStepsTaken(vector<Direction>);
		vector<Direction> GetStepsTaken();
};

#endif // NODE_H
