#ifndef FRINGE_H
#define FRINGE_H
#include<stack>
#include<queue>
#include<vector>

#include "Node.h"

template<typename T>
class Fringe : public std::queue<T>
{
	private:
		//

	protected:
		//
	public:
		void PutChildren(std::vector<T>);
};

#include "Fringe.hpp"
//
#endif // FRINGE_H
