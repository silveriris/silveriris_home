#include <bits/stdc++.h>
using namespace std;

template<typename T>
void mymemcpy(T* dst, T* src, T n)
{
	void* d = dst;
	for (int i = 0; i < n; i++)
	{
		*dst = *src;
		dst++;
		src++;
	}
}
int main()
{
	int src[5] = { 1,2,3,4,5 };
	int dst[5];
	mymemcpy(dst, src,static_cast<int>(sizeof(src)/sizeof(*src)));
	for (auto var : dst)
		cout << var;
	return 0;
}
