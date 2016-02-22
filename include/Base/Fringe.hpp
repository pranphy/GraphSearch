
template<typename T>
void Fringe<T>::PutChildren(vector<T> Children)
{
	for(auto Child:Children)
	{
		this->push(Child);
	}
}
