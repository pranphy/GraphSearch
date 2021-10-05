#ifndef SLIDECORE_H
#define SLIDECORE_H

#include <string>
using namespace std;

#include "PML/MatrixPrakash.hpp"

enum Direction{Up ,Down,Left,Right};
//vector<string> DirectionString = {string("Up"),string("Down"),string("Left"),string("Right")};

class SlideCore : public Matrix<int>
{
	private:
		vector<SlideCore> MakeMoves(vector<Direction>);
		//
	public:
		struct ZeroPosition
		{
			int i,j;
			ZeroPosition(int Eye=0,int Jey=0):i(Eye),j(Jey){};
		} EmptyCell;

		//static vector<string> DirectionString =  {string("Up"),string("Down"),string("Left"),string("Right")};
		SlideCore();
		SlideCore(int,int);
		void Move(Direction);
		vector<Direction> PossibleMoves();
		vector<SlideCore> MakeAllMoves();
		SlideCore MakeOneMove(Direction);
		bool operator==(SlideCore TestCore);
		int GetVal(int,int);
};

#endif // SLIDECORE_H
