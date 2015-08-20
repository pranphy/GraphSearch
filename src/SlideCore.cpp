#include "SlideCore.h"

SlideCore::SlideCore():Matrix()
{

	//ctor
}

SlideCore::SlideCore(int Row,int Col):Matrix(Row,Col),EmptyCell(Row-1,Col-1)
{
	int p = 1;
	for(int i = 0;i<Row;i++)
		for(int j = 0; j< Col; j++)
			(*this)[i][j] = p++;
	(*this)[Row-1][Col-1]  = 0;

}

void SlideCore::Move(Direction D)
{
	switch(D)
	{
	case Direction::Up:
		//cout<<" Up Requested "<<endl;
		if(EmptyCell.i + 1 <= Row-1)
		{
			//cout<<" I passed check for up"<<endl;
			Swap(Data[EmptyCell.i][EmptyCell.j],Data[EmptyCell.i+1][EmptyCell.j]);
			EmptyCell.i++;

		}
		break;
	case Direction::Down:
		//cout<<" down requested "<<endl;
		if(EmptyCell.i - 1 >= 0)
		{
			//cout<<" I passed for down "<<endl;
			Swap(Data[EmptyCell.i][EmptyCell.j],Data[EmptyCell.i-1][EmptyCell.j]);
			EmptyCell.i--;
		}
		break;
	case Direction::Left:
		////cout<<"I left "<<endl;
		if(EmptyCell.j + 1 <= Col-1)
		{
			//cout<<" I passed check for LEft"<<endl;
			Swap(Data[EmptyCell.i][EmptyCell.j],Data[EmptyCell.i][EmptyCell.j+1]);
			EmptyCell.j++;

		}
		break;
	case Direction::Right:
		//cout<<" Right requested "<<endl;
		if(EmptyCell.j - 1 >= 0)
		{
			//cout<<" I passed for right "<<endl;
			Swap(Data[EmptyCell.i][EmptyCell.j],Data[EmptyCell.i][EmptyCell.j-1]);
			EmptyCell.j--;
		}
		break;
	}
}


bool SlideCore::operator==(SlideCore TestCore)
{
	if(Row != TestCore.Row or Col != TestCore.Col)
	{
		return false;
	}
	else
	{
		for(int row =0; row<Row; row++)
			for(int col = 0; col<Col; col++)
				if(Data[row][col] != TestCore[row][col])
					return false;
	}
	return true;
}

vector<Direction> SlideCore::PossibleMoves()
{
	vector<Direction> Moves;
	if(EmptyCell.i == 0)
		Moves.push_back(Direction::Up);
	if(EmptyCell.i > 0 and EmptyCell.i < Row - 1)
	{
		Moves.push_back(Direction::Down);
		Moves.push_back(Direction::Up);
	}
	if(EmptyCell.i == Row - 1)
		Moves.push_back(Direction::Down);

	if(EmptyCell.j == 0)
		Moves.push_back(Direction::Left);
	if(EmptyCell.j > 0 and EmptyCell.j < Col - 1)
	{
		Moves.push_back(Direction::Right);
		Moves.push_back(Direction::Left);
	}
	if(EmptyCell.j == Col - 1)
		Moves.push_back(Direction::Right);
	return Moves;

}


vector<SlideCore> SlideCore::MakeMoves(vector<Direction> Moves)
{
	vector<SlideCore> Children;
	Children.reserve(Moves.size());
	for(auto MoveDirection:Moves)
	{
		SlideCore Current(*this);
		Current.Move(MoveDirection);
		Children.push_back(Current);
	}
	return Children;
}

vector<SlideCore> SlideCore::MakeAllMoves()
{
	vector<Direction> Moves = this->PossibleMoves();
	return this->MakeMoves(Moves);
}

/*
vector<Direction> SlideCore::PossibleMoves()
{
	if(EmptyCell.i == 0)
	{
		if(EmptyCell.j == 0)
		{
			vector<Direction> ReturnValue = {Direction::Up,Direction::Left};
			return ReturnValue;
		}
		else if(EmptyCell.j > 0 and EmptyCell.j < Col-1)
		{
			vector<Direction> ReturnValue = {Direction::Up,Direction::Left, Direction::Down};
			return ReturnValue;
		}
		else if(EmptyCell.j = Col-1)
		{
			vector<Direction> ReturnValue = {Direction::Down,Direction::Left};
			return ReturnValue;
		}
	}
	if(EmptyCell.i >0 and EmptyCell.i < Row - 1)
	{
		if(EmptyCell.j == 0)
		{
			vector<Direction> ReturnValue = {Direction::Up,Direction::Left,Direction::Right};
			return ReturnValue;
		}
		else if(EmptyCell.j >0 and EmptyCell.j < Col-1)
		{
			vector<Direction> ReturnValue = {Direction::Up,Direction::Left,Direction::Right,Direction::Down};
			return ReturnValue;
		}
		else if(EmptyCell.j = Col-1)
		{
			vector<Direction> ReturnValue = {Direction::Right,Direction::Left,Direction::Down};
			return ReturnValue;
		}
	}
	if(EmptyCell.i == Row-1)
	{
		if(EmptyCell.j == 0)
		{
			vector<Direction> ReturnValue = {Direction::Up,Direction::Right};
			return ReturnValue;
		}
		else if(EmptyCell.j >0 and EmptyCell.j < Col-1)
		{
			vector<Direction> ReturnValue = {Direction::Up,Direction::Right,Direction::Down};
			return ReturnValue;
		}
		else if(EmptyCell.j = Col-1)
		{
			vector<Direction> ReturnValue = {Direction::Down,Direction::Right};
			return ReturnValue;
		}
	}
}
*/
