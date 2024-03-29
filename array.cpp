#include <iostream>
#include "array.h"

Array::Array() : size(0), expandStep(1), data(nullptr), curr(0)
{
}

Array::Array(int size, int expandStep)
{
	if (size <= 0)
	{
		this->size = 0;
		this->data = nullptr;
	}
	else
	{
		this->size = size;
		this->data = new int[size];
		if (this->data == nullptr)
		{
			this->size = 0;
			this->data = nullptr;
		}
	}
	if (expandStep < 1)
		this->expandStep = 1;
	else
		this->expandStep = expandStep;
	curr = 0;
}

Array::~Array()
{
	if (data != nullptr)
		delete[] data;
	data = nullptr;
	size = 0;
	expandStep = 0;
	curr = 0;
}

void Array::showElements() const
{
	for (int i = 0; i < curr; i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}

void Array::expandArray(int size)
{
	if (size < 1)
		return;
	int* temp = new int[this->size + size];
	for (int i = 0; i < curr; i++)
	{
		temp[i] = data[i];
	}
	if (data != nullptr)
		delete[] data;
	this->size += size;
	data = temp;
}

int Array::getSize() const
{
	return size;
}

int Array::getElemSize() const
{
	return curr;
}

void Array::setValue(int value)
{
	if (curr >= size)
		expandArray(expandStep);
	data[curr] = value;
	curr++;
}

void Array::setArray(int* arr, int arrSize)
{
	while (curr + arrSize >= size)
		expandArray(expandStep);
	for (int i = 0; i < arrSize; i++)
	{
		data[curr] = arr[i];
		curr++;
	}
}