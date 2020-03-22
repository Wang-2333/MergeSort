#include<iostream>
#define N 8
using namespace std;
int a[N]={ 49,38,65,97,76,13,27,57 };
int temp[N];

void Merge(int begin, int mid, int end) {
	int k = begin, i = begin, j = mid + 1;
	while (i != mid + 1 && j != end + 1) {
		if (a[i] > a[j])
			temp[k++] = a[j++];
		else
			temp[k++] = a[i++];
	}
	int tp = 0;
	while (i != mid + 1) temp[k++] = a[i++];
	while (j != end + 1) temp[k++] = a[j++];
	for (int l = begin; l <= end; l++)
		a[l] = temp[l];

}

void MergeSort(int begin, int end) {
	int mid;
	if (begin < end) {
		mid = (begin + end) / 2;
		MergeSort(begin, mid);
		MergeSort(mid + 1, end);
		Merge(begin, mid, end);
	}
}
int main() {
	MergeSort(0, N-1);
	for (int i = 0; i < N; i++)
		cout << a[i] << ' ';
	return 0;
}