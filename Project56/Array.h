#pragma once
#include <iostream>
using namespace std;

template<class T>
class Array {
	T** arr;
	int str;
	int stolb;
public:
	Array();
	Array(int str, int stolb);
	Array(const Array<T>& obj);
	~Array();
	void Print() const;
	void Random();
	T** Add(T add);
	T** Substract(T min);
	T** Multiply(T mul);
	T** Divide(T divide);
	T Max()const;
	T Min()const;
	Array& operator=(const Array& obj2) {
		if (this == &obj2) {
			return *this;
		}
		if (arr != nullptr) {
			for (int i = 0; i < str; i++)
			{
				delete[]arr[i];
			}
			delete[]arr;
		}

		this->str = obj2.str;
		this->stolb = obj2.stolb;
		arr = new T * [str];
		for (int i = 0; i < str; i++)
		{
			arr[i] = new T[stolb];
		}

		for (int i = 0; i < str; i++)
		{
			for (int j = 0; j < stolb; j++)
			{
				arr[i][j] = obj2.arr[i][j];
			}
		}

		return *this;

	}
};

template<class T>
Array<T>::Array() //Default constructor
{
	arr = nullptr;
	str = 0;
	stolb = 0;
}

template<class T>
Array<T>::Array(int str, int stolb) //Contstructor via parametrs
{
	this->str = str;
	this->stolb = stolb;
	arr = new T*[str];
	for (int i = 0; i < str; i++)
	{
		arr[i] = new T[stolb];
	}
}

template<class T>
Array<T>::Array(const Array<T>& obj) //Copy constructor
{
	str = obj.str;
	stolb = obj.stolb;
	arr = new T * [str];
	for (int i = 0; i < str; i++)
	{
		arr[i] = new T[stolb];
	}

	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			arr[i][j] = obj.arr[i][j];
		}
	}
} 

template<class T>
Array<T>::~Array()
{
	for (int i = 0; i < str; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
}

template<class T>
void Array<T>::Print()const
{
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

template<class T>
void Array<T>::Random()
{
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			arr[i][j] = rand() % 100 * 1.6;
		}
	}
}

template<class T>
T** Array<T>::Add(T add)
{
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			arr[i][j] += add;
		}
	}
	return arr;
}

template<class T>
T** Array<T>::Substract(T min)
{
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			arr[i][j] -= min;
		}
	}
	return arr;
}

template<class T>
T** Array<T>::Multiply(T mul)
{
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			arr[i][j] *= mul;
		}
	}
	return arr;
}

template<class T>
T** Array<T>::Divide(T divide)
{
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			arr[i][j] /= divide;
		}
	}
	return arr;
}

template<class T>
T Array<T>::Max()const
{
	T max = 0;
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			if (arr[i][j] > max)
				max = arr[i][j];
		}
	}
	
	return max;
}

template<class T>
T Array<T>::Min()const
{
	T min = arr[0][0];
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			if (min > arr[i][j])
				min = arr[i][j];
		}
	}

	return min;
}



