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
		if (pos > listSize) { // Throw Exception 
		}
		for (int i = listSize; i > pos; i--)
		{
			m_data[i] = m_data[i - 1];
		}
		m_data[pos] = it;
		listsize++;
	}
	void append(const T& it)
	{
		m_data[listSize++] = it;
	}
	int length() const { return listSize; }
	
	const T& at(int pos) const {
		if (pos > listSize) {
			//throw exception
		}
		return m_data[pos];
	}
};

