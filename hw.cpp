// emreyo - 23 - HW2
#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <windows.h>

using namespace std;

void merge(int a[], int leftIndex, int middleIndex, int rightIndex)
{
	int h, i, j, b[50], k;
	h = leftIndex;
	i = leftIndex;
	j = middleIndex + 1;

	while((h <= middleIndex) && (j <= rightIndex))
	{
		if(a[h] <=a [j])
		{
			b[i] = a[h];
			h++;
		}

		else
		{
			b[i] = a[j];
			j++;
		}
		
		i++;
	}

	if(h > middleIndex)
	{
		for(k=j; k<=rightIndex; k++)
		{
			b[i] = a[k];
			i++;
		}
	}

	else
	{
		for(k=h; k<=middleIndex; k++)
		{
			b[i] = a[k];
			i++;
		}
	}

	for(k=leftIndex; k<=rightIndex; k++)
		a[k] = b[k];
}

void mergesortFunc(int array[], int leftIndex, int rightIndex)
{
	int middleIndex;

	if(leftIndex < rightIndex)
	{
		middleIndex = (leftIndex+rightIndex) / 2;
		mergesortFunc(array, leftIndex, middleIndex);
		mergesortFunc(array, middleIndex+1, rightIndex);
		merge(array, leftIndex, middleIndex, rightIndex);
	}
}

void qsort(int arr[], int left, int right)
{
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}

	if (left < j)
		qsort(arr, left, j);
	if (i < right)
		qsort(arr, i, right);
}

void inssortFunc(int array[], int length)
{
	int key, i;
	
	for(int j=1; j<length; j++)
	{
		key = array[j];
		i = j-1;

		while(array[i]>key && i>=0)
		{
			array[i+1] = array[i];
			i--;
		}
		array[i+1] = key;
	}
}

int main()
{
	long ts, te;
	char choice;

	int *array, length;
	char code;
	bool quit = false;

	do
	{
		cout << "Enter the length of the array: ";
		cin >> length;

		array = new int[length];

		//filling the array with random number
		srand(unsigned(time(0)));

		for(int i=0; i<length; i++)
			array[i] = (rand() % length) + 1;

		cout << "Which algorithm you want to use (i for insertion sort, m for merge sort, q for qsort): ";
		cin >> code;

		switch(code)
		{
			case 'i':
				cout << "insertion sort" << endl << endl;
				ts = GetTickCount();
				inssortFunc(array, length);
				te = GetTickCount();
				break;
			case 'm':
				cout << "merge sort" << endl << endl;
				ts = GetTickCount();
				mergesortFunc(array, 0, length);
				te = GetTickCount();
				break;
			case 'q':
				cout << "quick sort" << endl << endl;
				ts = GetTickCount();
				qsort(array, 0, length);
				te = GetTickCount();
				break;
			default:
				cout << "wrong input" << endl << endl;
		}

	cout << "Sorted array: ";

	for(int i=0; i<length; i++)
		cout << array[i] << ' ';

	cout << " (sorted in " << te - ts << " miliseconds) " << endl;

	cout << " For Quit Press 'q' " << endl;
	cin >> choice;

	if(choice='q')
		quit = true;

	}while(quit!=false);

	getchar();
	getchar();

	return 0;
}
