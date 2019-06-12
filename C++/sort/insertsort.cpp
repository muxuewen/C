#include <iostream>
#include <list>
using namespace std;

// 简单选择排序
void SimpleChoose(int arr[], int len)
{
	if (len <= 1)
		return;
	for (int i = 0; i < len; ++i)
	{
		int temp = arr[i];
		int k = i;
		for (int j = i + 1; j < len; ++j)
		{
			if (arr[j] < temp)
			{
				temp = arr[j];
				k = j;
			}
		}
		arr[k] = arr[i];
		arr[i] = temp;
	}
}

// 插入排序
void insert(int arr[], int len)
{
	int temp = 0;
	for (int i = 1; i < len; ++i)
	{
		temp = arr[i];
		int j = i;
		while (j > 0 && temp < arr[j - 1])
		{
			arr[j] = arr[j - 1];
			--j;
		}
		arr[j] = temp;
	}

}

// 希尔排序
void shell(int arr[], int len)
{
	int temp = 0;
	int d = len;
	while (d > 1)
	{
		d = d / 3 + 1;
		for (int i = d; i < len; ++i)
		{
			temp = arr[i];
			int j = i;
			while (j > 0 && temp < arr[j-d])
			{
				arr[j] = arr[j - d];
				j -= d;
			}
			arr[j] = temp;
		}
	}
}

// 快速排序
void quick(int arr[], int low, int len)
{
	if (low >= len || len <= 0)
		return;
	int first = low;
	int last = len;
	int temp = arr[low];
	while (first < last)
	{
		while (first < last && arr[last] > temp)
		{
			--last;
		}
		arr[first] = arr[last];
		while (first < last && arr[first] < temp)
		{
			++first;
		}
		arr[last] = arr[first];
	}
	arr[first] = temp;
	quick(arr, low, first - 1);
	quick(arr, first + 1, len);
}

// 冒泡排序
void bubble(int arr[], int len)
{
	int temp = 0;
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len -1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void showarr(int arr[],int len)
{
	for (int i = 0; i < len ; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(void)
{
	int array[10] = { 8, 12, 7, 6, 18, 3, 9, 11, 15, 4 };
	int len = sizeof(array) / sizeof(array[0]);
	int arr[10] = {0};

	// 
	memcpy(arr, array, sizeof(array));
	shell(arr, len);
	showarr(arr, len);

	// 
	memcpy(arr, array, sizeof(array));
	quick(arr, 0, len - 1);
	showarr(arr, len);

	memcpy(arr, array, sizeof(array));
	insert(arr, len);
	showarr(arr, len);
	

	//system("PAUSE");
	getchar();
	return 0;
}
