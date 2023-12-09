#include <iostream>

int PassByValue(int Number)
{
	Number = Number * Number;
	return Number;
}

int PassByReference(int& Number)
{
	Number = Number * Number;
	return Number;
}

void BasicPointers()
{
	std::cout << "<-| Basic Pointers |->" << std::endl;

	int MyNumber = 777;
	int* MyNumberPtr = new int; // one memory block reserved
	*MyNumberPtr = MyNumber;

	std::cout << "LOG: the pointer's address:" << MyNumberPtr << std::endl;
	std::cout << "LOG: the pointer's value:" << *MyNumberPtr << std::endl;

	delete MyNumberPtr; // cleanup

}

void StaticArray()
{
	std::cout << "<-| Arrays VS Pointers - Static Array |->" << std::endl;

	int MyStaticArray[] = { 8, 16, 32, 64 };

	for (int i = 0; i < 4; ++i)
	{
		std::cout << "LOG: index: " << i << " | value is: " << MyStaticArray[i] << std::endl;
	}

}

void DynamicArray()
{
	std::cout << "<-| Arrays VS Pointers - Dynamic Array |->" << std::endl;

	int i = 0; // loop counter!
	int* MyDynamicArray = new int[8]; // eight adjacent memory blocks reserved
	int* CurrentIndex = MyDynamicArray;
	while (CurrentIndex < MyDynamicArray + 8)
	{
		*CurrentIndex = i * 64;
		std::cout << "LOG: the pointer's address:" << CurrentIndex << std::endl;
		std::cout << "LOG: the pointer's value:" << *CurrentIndex << std::endl;
		++CurrentIndex;
		++i;
	}

	delete[] MyDynamicArray; // cleanup
}

int main()
{
	
	//PassByValue - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
	int A = 42;
	int B = PassByValue(A);
	/*  
		A == B ?
	*/

	//PassByReference - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
	int X = 42;
	int Y = PassByReference(X);
	/*
		X == Y ?
		int Z = Y; Z == X ?
	*/

	//BasicPointers - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
	BasicPointers();
	/*
		void InitializePointer(int* ptr, int value)
		{
			// ...?
		}

		int* CreateNewPointer(int value)
		{
			int* ptr = // ... ?
			// ...?
			return ptr;
		}
	*/

	//ArraysVsPointers - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
	StaticArray();
	/*
		int CreateStaticArray(int maxLength)
		{
			int myArray[maxLength] = { 4, 2 };		// WTAPWT
		}
	*/

	DynamicArray();
	/*
		int* CreateDynamicArray(int maxLength)
		{
			int* arrayPtr = // ... ?
			// ...?
			return arrayPtr;
		}

		int* ResizeDynamicArray(int* arrayPtr, int currentSize, int newSize)
		{
			// ...?
			return arrayPtr;
		}
	*/
	std::cout << "MDL1 - FINISH" << std::endl;
	return 0;
}

