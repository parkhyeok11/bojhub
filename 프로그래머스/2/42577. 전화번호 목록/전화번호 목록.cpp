#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    string temp;
    int vs=phone_book.size();
    sort(phone_book.begin(),phone_book.end());
    for (int i = 0; i < vs; i++) {
        temp=phone_book[i];
        for (int j = i; j < i+2; j++) {
            if(j>=vs) break;
            if(i==j) continue;
            if(temp.size()>phone_book[j].size()) continue;
            if (temp == phone_book[j].substr(0, temp.size())) {
                answer = false;
                break;
            }
        }
        if (answer == false) break;
        temp = phone_book[i];
    }
    return answer;
}