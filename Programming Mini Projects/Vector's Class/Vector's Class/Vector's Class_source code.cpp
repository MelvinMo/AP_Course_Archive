#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

template <class T>
class vectorClass {

private:

	T* arr;
	int capacity, current;

public:

	vectorClass()
	{
		arr = new T[1];
		capacity = 1;
		current = 0;
	}

	vectorClass(const vectorClass &other) :arr(NULL), current(0), capacity(0)
	{
		arr = new T[other.capacity()];
		std::copy(arr, &other[0], sizeof(T)*other.size());
		current = other.current;
		capacity = other.capacity;
	}
 
	void push_back(T data)
	{
		if (current == capacity)
		{
			T* temp = new T[2 * capacity];
			for (int i = 0; i < capacity; i++)
			{
				temp[i] = arr[i];
			}
			delete[] arr;
			capacity *= 2;
			arr = temp;
		}
		arr[current] = data;
		current++;
	}

	void push_front(T data)
	{
        current++;
		for (int i = current - 1; i > 0; i--)
        {
			arr[i] = arr[i - 1];
        }
		if (0 == capacity)
			push_back(data);
		else
        arr[0]=data;
	}

	void insert(int index, T data)
	{
		if (index == capacity)
			push_back(data);
		else
			arr[index - 1] = data;
		current++;
	}

	void pop()
	{
		current--;
	}

	void Delete(int index)
	{
		if (index < current)
		{
			for (int i = index; i <= current - 1; i++)
			{
				arr[i] = arr[i + 1];
			}
			arr[current - 1] = {};
		}
		current--;
		cout << "Deleted!" << endl;
	}

	int search(T data)
	{
		for (int i = 0; i < current; i++)
		{
			if (arr[i] == data)
			{
				return i + 1;
			}
			else if (i == current - 1)
				return -1;
		}
	}

	int size()
	{
		return current;
	}

	void print()
	{
		for (int i = 0; i < current; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	//A Main To Test Vector Class Simulator!
	vectorClass<int> v;
	cout << "Amirmahdi Mokhtari's Vector class simulator!" << endl << endl;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.insert(5, 50);
	v.push_front(0);
	cout << "Vector size : " << v.size() << endl;
	cout << "Vector elements : ";
	v.print();
	cout << "Result of serach data 1 : ";
	cout << v.search(1) << endl;
	cout << "Result of serach data 20 : ";
	cout << v.search(20) << endl;
	cout << "Delete element at 1st index : ";
	v.Delete(0);
	cout << "Vector size : " << v.size() << endl;
	cout << "Vector elements : ";
	v.print();
	v.pop();
	cout << "After deleting last element" << endl;
	cout << "Vector size : " << v.size() << endl;
	cout << "Vector elements : ";
	v.print();
	cout << "Result of serach data 0 : ";
	cout << v.search(0) << endl;
	cout << "Result of serach data 30 : ";
	cout << v.search(30) << endl;
	cout << "Delete element at 3rd index : ";
	v.Delete(2);
	cout << "Vector size : " << v.size() << endl;
	cout << "Vector elements : ";
	v.print();
	return 0;
}