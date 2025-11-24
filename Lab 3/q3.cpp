#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') st.push(c);
        else {
            if (st.empty()) {
                cout << "Not Balanced";
                return 0;
            }
            if ((c == ')' && st.top() != '(') ||
                (c == '}' && st.top() != '{') ||
                (c == ']' && st.top() != '[')) {
                cout << "Not Balanced";
                return 0;
            }
            st.pop();
        }
    }

    if (st.empty()) cout << "Balanced";
    else cout << "Not Balanced";
}
