#ifndef PROBLEM_H
#define PROBLEM_H

#include "SlideCore.h"
#include "Fringe.h"
#include "Node.h"

class Problem
{
	private:
		SlideCore InitialState;
		SlideCore GoalState;
		Fringe<Node> Sequence;
		vector<Direction> SolutionSteps;
	public:
		Problem();
		Problem(SlideCore,SlideCore);
		//void Advance();
		bool IsGoal(Node&);
		bool Solve();
		void DisplayInfo();
		vector<Direction> GetSolution();
		void SetInitialState(SlideCore);
		void SetGoalState(SlideCore);
		void ClearSequence();
};

#endif // PROBLEM_H
