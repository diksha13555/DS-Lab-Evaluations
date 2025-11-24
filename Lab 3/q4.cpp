#include <bits/stdc++.h>
using namespace std;

int prec(char c) {
    if (c == '^') return 4;
    if (c == '*' || c == '/') return 3;
    if (c == '+' || c == '-') return 2;
    return 1;
}

bool isRightAssociative(char c) {
    return c == '^';
}

int main() {
    string s;
    if (!getline(cin, s)) return 0;
    string out;
    stack<char> st;
    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (isspace(c)) continue;
        if (isalnum(c)) out.push_back(c);
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                out.push_back(st.top());
                st.pop();
            }
            if (!st.empty() && st.top() == '(') st.pop();
        } else {
            while (!st.empty() && st.top() != '(') {
                char t = st.top();
                int p1 = prec(t);
                int p2 = prec(c);
                if (p1 > p2 || (p1 == p2 && !isRightAssociative(c))) {
                    out.push_back(t);
                    st.pop();
                } else break;
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        if (st.top() != '(' && st.top() != ')') out.push_back(st.top());
        st.pop();
    }
    cout << out << "\n";
    return 0;
}
