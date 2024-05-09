#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main()
{
	int n;
	int m;
	int num;
	int left, right;
	int temp = 0;
	cin >> n >> m;
	deque<int> q;
	for (int i = 1; i <= n; i++) {
		q.push_back(i);
	}

	while (m--) {
		int num;
		cin >> num;

		for (int i = 0; i < q.size(); i++) {

			if (q[i] == num) {
				left = i;
				right = q.size() - i;
				break;

			}
		}

		if (left <= right) {
			while (1) {
				if (q.front() == num)
					break;

				q.push_back(q.front());
				q.pop_front();
				temp++;

			}
			q.pop_front();
		}

		else {
			temp++;
			while (1) {
				if (q.back() == num)
					break;

				q.push_front(q.back());
				q.pop_back();
				temp++;

			}
			q.pop_back();
		}
	}

	cout << temp;

	return 0;
}