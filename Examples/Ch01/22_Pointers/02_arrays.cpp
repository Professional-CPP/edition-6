int main()
{
	int arraySize{ 8 };
	int* myVariableSizedArray{ new int[arraySize] };
	myVariableSizedArray[3] = 2;
	delete[] myVariableSizedArray;
	myVariableSizedArray = nullptr;
}
