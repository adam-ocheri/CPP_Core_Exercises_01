#include <iostream>

int PassByValue(int Number)
{
	Number = Number * Number;
	return Number;
}

int& PassByReference(int& Number)
{
	Number = Number * Number;
	return Number;
}

void InitializePointer(int* ptr, int value)
{
	ptr = new int(value);

}
int* CreateNewPointer(int value)
{
	int* ptr = new int(value);
	return ptr;
}

//  ____________________________________________________________________________________________________________________________________________

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

//  ____________________________________________________________________________________________________________________________________________

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
	int ArrayLength = 8;

	int* MyDynamicArray = new int[ArrayLength]; // [0, 0, 0, 0, 0, 0, 0, 0] ["Maor"]
	int* CurrentIndex = MyDynamicArray;


	while (CurrentIndex < MyDynamicArray + ArrayLength)
	{
		*CurrentIndex = i * 64;
		std::cout << "LOG: the pointer's address: " << CurrentIndex << std::endl;
		std::cout << "LOG: the pointer's value: " << *CurrentIndex << std::endl;
		++CurrentIndex;
		++i;
	}

	delete[] MyDynamicArray; // cleanup
}

int* CreateDynamicArray(int maxLength)
{
	int* arrayPtr = new int[maxLength];

	return arrayPtr;
}

int* IncreaseDynamicArraySize(int* arrayPtr, int currentSize, int resizeFactor)
{
	int i = 0;

	int newSize = currentSize + resizeFactor;
	int* newArrayPtr = new int[newSize]; //creating a new array with the requested size

	//copy items
	for (i = 0; i < currentSize; i++)
	{
		newArrayPtr[i] = arrayPtr[i];
	}

	// clean `arrayPtr`
	delete arrayPtr;

	// steal the pointer
	arrayPtr = newArrayPtr;
	newArrayPtr = nullptr;

	return arrayPtr;
}

//  ____________________________________________________________________________________________________________________________________________












int main()
{

	//PassByValue - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
	//int A = 42;
	//int B = PassByValue(A);
	//std::cout << A << "\n" << B << std::endl;
	/*
		A == B ?
	*/

	//PassByReference - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
	//int X = 42;
	//int& Y = PassByReference(X);
	//Y += 6;
	//std::cout << X << " " << Y << " " << std::endl;
	/*
		X == Y ?
		int Z = Y; Z == X ?
	*/
	//int Z = Y;
	//Z += 5;

	//BasicPointers - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
	//BasicPointers();
	//int* myPtr;
	//InitializePointer(myPtr, 42);
	//int* myNewPtr = CreateNewPointer(42);
	//...
	// after a lot of code and stuff....
	//delete myPtr;
	//delete myNewPtr;

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
	//StaticArray();
	/*
		int CreateStaticArray(int maxLength)
		{
			int myArray[maxLength] = { 4, 2 };		// WTAPWT
		}
	*/

	//DynamicArray();
	int* myDynamicArray = IncreaseDynamicArraySize(8);
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

