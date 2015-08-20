#ifndef SLIDECORE_H
#define SLIDECORE_H

#include "PML/MatrixPrakash.h"

enum Direction{Up ,Down,Left,Right};

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
		SlideCore();
		SlideCore(int,int);
		void Move(Direction);
		vector<Direction> PossibleMoves();
		vector<SlideCore> MakeAllMoves();
		bool operator==(SlideCore TestCore);

};

#endif // SLIDECORE_H
