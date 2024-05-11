#include<iostream>
#include<algorithm>
using namespace std;

int compare(const void* a, const void* b)
{
	const int* x = (int*)a;
	const int* y = (int*)b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;

	return 0;
}

int main() {
	int n;
	int a[51];
	int b[51];

	int sum = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	qsort(a, n, sizeof(int), compare);
	qsort(b, n, sizeof(int), compare);

	int temp = n - 1;

	for (int i = 0; i < n; i++) {
		sum += a[i] * b[n-1-i];
	}

	cout << sum;


	return 0;

}