#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n, m;
    int cnt = 0;
    string s;
    map<string, int> ma;
    map<string, int>::iterator iter;

    cin >> n >> m;

    for (int i = 0; i < n + m; i++) {
        cin >> s;
        ma[s]++;
        if (ma[s] == 2) cnt++;
    }

    cout << cnt<<"\n";

    for (iter = ma.begin(); iter != ma.end(); iter++)
        if (iter->second == 2)
            cout << iter->first << "\n";
}