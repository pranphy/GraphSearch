#ifndef NODE_H
#define NODE_H

#include "SlideCore.h"

class Node
{
	private:
		SlideCore State;
		SlideCore Parent;
		Direction Action;
		unsigned PathCost;
		unsigned Depth;
	protected:
		//
	public:
		Node();
		Node(SlideCore,SlideCore);
		SlideCore GetState() const;
		vector<Node> GetChildren();
		void SetAction(Direction);
		void SetDepth(unsigned);
		void SetPathCost(unsigned);
		void DisplayDetail();
};

#endif // NODE_H
