#pragma once
template <class T>
class List 
{
	int maxSize;
	int listSize;
	T* m_data;
public:
	List(int size)
	{
		maxSize = size;
		listSize = 0;
		m_data = new T[maxSize];
	}
	~List() { 
		delete[] m_data;
	}
	void clear()
	{
		delete[] m_data;
		listSize = 0;
		m_data = new T[maxSize];
	}
	void insert(const T& it, int pos)
	{
		//if (listSize == maxSize) doubleSize();

	//	for (int i = listSize; i > pos; i--)
	//	{
	//		m_data[i] = m_data[i - 1];
	//	}
		m_data[pos] = it;
		//listsize++;
	}
	void append(const T& it)
	{
		if (listSize == maxSize) doubleSize();
		m_data[listSize++] = it;
	}
	int length() const { return listSize; }
	
	const T& at(int pos) const {
		if (pos > listSize) {
			//throw exception
		}
		return m_data[pos];
	}
private:
	void doubleSize()
	{
		int newListSize = maxSize * 2;
		T * new_data = new T[newListSize];
		memcpy(new_data, m_data, maxSize * sizeof(T));
		delete[] m_data;
		m_data = new_data;
		maxSize = newListSize;
	}
};

