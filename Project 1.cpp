// Project 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

//All function declarations here
int* readFile(string); // Function that will be called 5 times and will take all of the numbers from the files and create arrays
int* convergeArrays(int*, int*, int*, int*, int*);  //Function that will take all 5 created arrays and converge them into one
void sortConverged(int**); //Function will use the 2D array with all of the data to sort them by the first column in the array
int countInversionsMergeSort(int**, int); //Function will take in an array and count the number of inversions in the array using merge-sort
int** convergedWithKey(int*, int*, int*, int*, int*); //This function will return a 2D array with 10,000 rows and 6 columns
void swap(int*, int*); //Swap function for bubble sort
void printMatrix(int**); //Function for printing the entire 2D array - good for testing purposes.
double computeReliability(int); //Function to compute the reliability of each source
int countInversionsQuickSort(int**, int);  //This function will count the inversions using quick-sort

int main()
{
    //Variable declarations/initializations
	int* source1 = NULL;
	int* source2 = NULL;
	int* source3 = NULL;
	int* source4 = NULL;
	int* source5 = NULL;
	int start = 0;
	int end = 10000;

	//Creating arrays of ints from source files
	source1 = readFile("source1.txt");
	source2 = readFile("source2.txt");
	source3 = readFile("source3.txt");
	source4 = readFile("source4.txt");
	source5 = readFile("source5.txt");

	//Testing for convergedWithKey
	int** conArr = convergedWithKey(source1, source2, source3, source4, source5);

	sortConverged(conArr);

	//Displaying the result of counting inversions using merge-sort
	int source1MergeSort = countInversionsMergeSort(conArr, 1);
	int source2MergeSort = countInversionsMergeSort(conArr, 2);
	int source3MergeSort = countInversionsMergeSort(conArr, 3);
	int source4MergeSort = countInversionsMergeSort(conArr, 4);
	int source5MergeSort = countInversionsMergeSort(conArr, 5);

	cout << "Number of inversions in source 1 using Merge-Sort:  " << source1MergeSort << endl;
	cout << "Number of inversions in source 2 using Merge-Sort:  " << source2MergeSort << endl;
	cout << "Number of inversions in source 3 using Merge-Sort:  " << source3MergeSort << endl;
	cout << "Number of inversions in source 4 using Merge-Sort:  " << source4MergeSort << endl;
	cout << "Number of inversions in source 5 using Merge-Sort:  " << source5MergeSort << endl;

	int averageMergeSort = (source1MergeSort + source2MergeSort + source3MergeSort + source4MergeSort + source5MergeSort) / 5;

	cout << "Average # of inversions using Merge-Sort:  " << averageMergeSort << endl;

	//Now to use quick-sort
	
	int source1QuickSort = countInversionsQuickSort(conArr, 1);
	int source2QuickSort = countInversionsQuickSort(conArr, 2);
	int source3QuickSort = countInversionsQuickSort(conArr, 3);
	int source4QuickSort = countInversionsQuickSort(conArr, 4);
	int source5QuickSort = countInversionsQuickSort(conArr, 5);

	cout << "Number of inversions in source 1 using Quick-Sort:  " << source1QuickSort << endl;
	cout << "Number of inversions in source 2 using Quick-Sort:  " << source2QuickSort << endl;
	cout << "Number of inversions in source 3 using Quick-Sort:  " << source3QuickSort << endl;
	cout << "Number of inversions in source 4 using Quick-Sort:  " << source4QuickSort << endl;
	cout << "Number of inversions in source 5 using Quick-Sort:  " << source5QuickSort << endl;

	int averageQuickSort = (source1QuickSort + source2QuickSort + source3QuickSort + source4QuickSort + source5QuickSort) / 5;

	cout << "Average # of inversions using Quick-Sort:  " << averageQuickSort << endl;
	
	//Now compute the reliability of each source
	double source1Reliability = computeReliability(source1MergeSort);
	double source2Reliability = computeReliability(source2MergeSort);
	double source3Reliability = computeReliability(source3MergeSort);
	double source4Reliability = computeReliability(source4MergeSort);
	double source5Reliability = computeReliability(source5MergeSort);

	cout << "Reliability of source 1 is:  " << source1Reliability << endl;
	cout << "Reliability of source 2 is:  " << source2Reliability << endl;
	cout << "Reliability of source 3 is:  " << source3Reliability << endl;
	cout << "Reliability of source 4 is:  " << source4Reliability << endl;
	cout << "Reliability of source 5 is:  " << source5Reliability << endl;

	//Delete all allocated memory
	delete[] source1;
	delete[] source2;
	delete[] source3;
	delete[] source4;
	delete[] source5;

	delete[] conArr;
}

int* readFile(string fileName)
{
	ifstream myfile;
	string line;
	int numberOfNumbers = 10000;
	int* arr = new int[numberOfNumbers + 1];
	int index = 0;
	//open file
	myfile.open(fileName);
	//read each line of the file and add it to an array
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			arr[index] = stoi(line);
			index++;
		}
		myfile.close();
	}
	myfile.close();

	return arr;
}

int* convergeArrays(int* source1, int* source2, int* source3, int* source4, int* source5)
{
	//Variable declaration/initialization
	int i = 0;
	int length = 50000;
	int* combined = new int[length + 1];

	//Create a loop to loop through every element in each array and add them
	for (int i = 0; i < 10000; i++)
	{
		combined[i] = source1[i] + source2[i] + source3[i] + source4[i] + source5[i];
	}

	return combined;
}

void sortConverged(int** arr)
{
	//Variable Declaration/Initializations
	int rowCount = 10000;
	int colCount = 6;
	int min;
	int i, j, k;

	//This will use a modified version of bubble sort to sort the 2D array by the first column

	for (i = 0; i < rowCount - 1; i++)
	{
		// Last i elements are already in place
		for (j = 0; j < rowCount - i - 1; j++)
		{
			if (arr[j][0] > arr[j + 1][0])
			{
				for (int k = 0; k < colCount; k++)
				{
					swap(&arr[j][k], &arr[j + 1][k]);
				}
			}
		}
	}
}

int countInversionsMergeSort(int** arr, int src)
{
	//Variable Declaration/Initialization
	int rowCount = 10000;
	int inv_count = 0;
	
	//double nested for loops that will go through each column and count the number of inversions
	for (int i = 0; i < rowCount - 1; i++)
		for (int j = i + 1; j < rowCount; j++)
			if (arr[i][src] > arr[j][src])
				inv_count++;

	return inv_count;
}

int** convergedWithKey(int* source1, int* source2, int* source3, int* source4, int* source5)
{
	//Variable Declaration/Initialization
	int rowCount = 10000;
	int colCount = 6;
	int* combinedSource = NULL;
	int* sortedCombined = NULL;

	//Combine the sources into a single array
	combinedSource = convergeArrays(source1, source2, source3, source4, source5);

	//Create a dynamically allocated 2D array with 5 sources and their converged scores
	int** arr = new int*[rowCount + 1];
	for (int i = 0; i < rowCount; ++i)
	{
		arr[i] = new int[colCount + 1];
	}

	//Fill the dynamic 2D array with data
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			if (j == 0)
			{
				arr[i][j] = combinedSource[i];
			}
			else if (j == 1)
			{
				arr[i][j] = source1[i];
			}
			else if (j == 2)
			{
				arr[i][j] = source2[i];
			}
			else if (j == 3)
			{
				arr[i][j] = source3[i];
			}
			else if (j == 4)
			{
				arr[i][j] = source4[i];
			}
			else if (j == 5)
			{
				arr[i][j] = source5[i];
			}

		}
	}

	return arr;
}

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void printMatrix(int** arr)
{
	//Variable Declaration/Initialization
	int rowCount = 10000;
	int colCount = 6;

	//Print Matrix
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			cout << arr[i][j] << "   ";
		}
		cout << endl;
	}
}

double computeReliability(int numInversions)
{
	double reliability = 0;

	//Calculate reliability is 1/numInversions + 1.  Had to add to the power of 10^-8 on bottom in order to change the number into something managable
	reliability = (1 / ((numInversions + 1) * pow(10,-8)));

	//Change the newly managble number to a decimal

	reliability = reliability / 100;

	return reliability;
}

int countInversionsQuickSort(int** arr, int src)
{
	//Variable Declaration/Initialization
	int start = 0;
	int end = 10000;
	int count = 0;
	vector<int> equalTo;
	vector<int> greaterThan;
	vector<int> lessThan;

	//Making the first element the pivot
	int pivot = arr[0][src];
	equalTo.push_back(pivot);

	for (int i = 1; i < end; i++)
	{
		if (arr[i][src] == pivot)
		{
			equalTo.push_back(arr[i][src]);
			count += greaterThan.size();
		}
		else if (arr[i][src] > pivot)
		{
			greaterThan.push_back(arr[i][src]);
		}
		else
		{
			lessThan.push_back(arr[i][src]);
			count += (equalTo.size() + lessThan.size());
		}
	}

	return count;
}
