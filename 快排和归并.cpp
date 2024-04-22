#include<bits/stdc++.h>
using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
int paritition(int low, int high, int* a)
{
	int i = low, j = high, pivot = a[low];
	while (i < j)
	{
		while (i<j && a[j]>pivot)
		{
			j--;
		}
		if (i < j)
		{
			swap(a[i++], a[j]);
		}
		while (i < j && a[i] <= pivot)
		{
			i++;
		}
		if (i < j)
		{
			swap(a[i], a[j--]);
		}
	}
	return i;
}
void quicksort(int low, int high, int* a)
{
	int mid;
	if (low<high)
	{
		mid = paritition(low, high, a);
		quicksort(low, mid-1, a);
		quicksort(mid + 1, high, a);
	}
}

int b[100] = { 0 };

void merge(int low, int mid,int high, int* a)
{
	int i, j, k;
	for (k = low; k <= high; k++)
		b[k] = a[k];
	for ( i = low,j=mid+1,k=i; i <= mid&&j<=high; k++)
	{
		if (b[i]<=b[j])
		{
			a[k] = b[i++];
		}
		else
		{
			a[k] = b[j++];
		}
	}
	while (i <= mid) a[k++] = b[i++];
	while (j <= high) a[k++] = b[j++];
}
void mergesort(int low, int high, int* a)
{

	if (low < high)
	{
		int mid = (low + high) / 2;
		mergesort(low, mid, a);
		mergesort(mid + 1, high, a);
		merge(low, mid, high, a);
	}
}
int main()
{
	int a[20] = { 0 };
	for (int i = 0; i < 20; i++)
	{
		a[i] = (rand() % 20 + 1);
	}
	quicksort(0, 19, a);
	for (int var : a)
		cout << var<<" ";
	return 0;
}