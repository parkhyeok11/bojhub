#include<string>
#include<iostream>
#include<stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
        if (i == 0 && s[i] == ')') return false;
        if (s[i] == '(') {
            st.push(s[i]);
        }

        if (s[i] == ')') {
            if (st.empty() == true) return false;
            else st.pop();
        }
    }
    if (st.empty() == false) return false;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}