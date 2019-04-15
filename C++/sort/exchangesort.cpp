#include <iostream>
#include <list>
using namespace std;

void bubbling(int arr[],int len)
{
	if (len <= 1)
		return;
	for (int i = 0; i < len - 1; ++i)
	{
		int flag = 0;
		for (int j = 0; j < len - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				flag = 1;
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		if (0 == flag)
			break;
	}
}

void Quick(int arr[],int low, int len)
{
	if (low > len || len < 1)
		return;

	int first, last, temp;
	first = low;
	last = len;
	temp = arr[low];
	while (first < last)
	{
		while (first < last && arr[last] >= temp)
		{
			--last;
		}
		arr[first] = arr[last];
		while (first < last && arr[first] <= temp)
		{
			++first;
		}
		arr[last] = arr[first];
	}
	arr[first] = temp;
	Quick(arr, low, first - 1);
	Quick(arr, first + 1, len);

}


void showarr(int arr[],int len)
{
	for (int i = 0; i < len - 1; i++)
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

	// Ã°ÅÝ
	memcpy(arr, array, sizeof(array));
	bubbling(arr, len);
	showarr(arr, len);

	// ¿ìÅÅ
	memcpy(arr, array, sizeof(array));
	Quick(arr, 0, len - 1);
	showarr(arr, len);
	

	//system("PAUSE");
	getchar();
	return 0;
}