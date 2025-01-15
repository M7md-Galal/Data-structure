/*Mohamed Galal*/
#include <iostream>
#include <cmath>
#include <array>
#include <algorithm>
#include<vector>
using namespace std;

class DynamicArray
{
private:
	int* data;
	int size;
	int capacity;

public:

	//Constructor
	DynamicArray(int _capacity) : size(0)
	{
		capacity = _capacity;
		data = new int[_capacity];
	}
	//Destructor
	~DynamicArray()
	{
		delete[]data;
	}
	//Get Size
	int getsize()
	{
		return size;
	}
	//Get Capacity
	int getcapacity()
	{
		return capacity;
	}
	//Set Elements in Array
	void setElement(int index, int value)
	{
		if (index >= capacity)
		{
			cout << "Index out of range";
		}
		if (index >= size)
		{
			size = index + 1;
		}
		data[index] = value;
	}
	//Get Elements of Array
	int getElemnent(int index)
	{
		if (index >= capacity)
		{
			cout << "Index out of range";
		}
		return data[index];
	}
	//Resize Array
	void resizeArray(int newCapacity)
	{
		int* newData = new int[newCapacity];
		int newSize = min(size, newCapacity);
		for (int i = 0; i < newSize; i++)
		{
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
		size = newSize;
		capacity = newCapacity;
	}
	//Insert Element End Array
	void insertEnd(int value)
	{
		if (size == capacity)
		{
			resizeArray(2 * capacity);
		}
		data[size++] = value;
	}
	//Insert Element Front Array
	void insertFront(int value)
	{
		if (size == capacity)
		{
			resizeArray(2 * capacity);
		}
		// Shift Elements to the Right
		for (int i = size; i > 0; i--)
		{
			data[size] = data[i - 1];
		}
		data[0] = value;
		//size++;
	}
	//Remove End Array
	void removeEnd()
	{
		if (size > 0)
		{
			size--;
		}
	}
	//Reomve Front
	void removeFront()
	{
		if (size > 0)
		{
			for (int i = 0; i < size; i++)
			{
				data[i] = data[i + 1];
			}
			size--;
		}
	}
	//Insert element at a specified Index
	void insertIndex(int index, int value)
	{
		if (index > size || index < 0)
		{
			cout << "Index out of range";
		}
		if (size == capacity)
		{
			resizeArray(2 * capacity);
		}
		//Shift elements to the right
		for (int i = size; i > index; i--)
		{
			data[i] = data[i - 1];
		}
		data[index] = value;
		size++;
	}
	//Remove element from specified Index
	void RemoveIndex(int index)
	{
		if (index > size || index < 0)
		{
			cout << "Index out of range";
		}
		for (int i = index; i < size - 1; i++)
		{
			data[i] = data[i + 1];
		}
		size--;
	}

};

int main()
{
	DynamicArray arr(5);

	for (int i = 0; i < arr.getcapacity(); i++)
	{
		arr.setElement(i, i * 2);
	}
	cout << "List of Array\n";
	for (int i = 0; i < arr.getsize(); i++)
	{
		cout << arr.getElemnent(i) << " ";
	}
	
	/*cout << "\nResize Array\n";
	arr.resizeArray(10);
	for (int i = 0; i < arr.getsize(); i++)
	{
		cout << arr.getElemnent(i) << " ";
	}

	cout << "\nInsert End\n";
	arr.insertEnd(66);
	for (int i = 0; i < arr.getsize(); i++)
	{
		cout << arr.getElemnent(i) << " ";
	}

	cout << "\nInsert Front\n";
	arr.insertFront(77);
	for (int i = 0; i < arr.getsize(); i++)
	{
		cout << arr.getElemnent(i) << " ";
	}
	
	cout << "\n Remove End\n";
	arr.removeEnd();
	for (int i = 0; i < arr.getsize(); i++)
	{
		cout << arr.getElemnent(i) << " ";
	}
	

	cout << "\nRemove Front\n";
	arr.removeFront();
	for (int i = 0; i < arr.getsize(); i++)
	{
		cout << arr.getElemnent(i) << " ";
	}*/
	
	cout << "\n Insert Index\n";
	arr.insertIndex(2, 678);
	for (int i = 0; i < arr.getsize(); i++)
	{
		cout << arr.getElemnent(i) << " ";
	}

	/*cout << "\nRemove Index\n";
	arr.RemoveIndex(5);
	for (int i = 0; i < arr.getsize(); i++)
	{
		cout << arr.getElemnent(i) << " ";
	}*/
}