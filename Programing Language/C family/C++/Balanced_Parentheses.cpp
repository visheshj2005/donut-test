#include <bits/stdc++.h>
using namespace std;

bool balanced_string(const string &str)
{
    stack<char> st;
    for (char it : str)
    {
        if (it == '{' || it == '[' || it == '(')
        {
            st.push(it);
        }
        else
        {
            if (st.empty())
            {
                cout << "Mismatch found: stack is empty and trying to match " << it << endl;
                return false;
            }
            char top = st.top();
            if ((it == ')' && top == '(') || 
                (it == '}' && top == '{') || 
                (it == ']' && top == '['))
            {
                st.pop();
            }
            else
            {
                cout << "Mismatch found: expected " << (it == ')' ? '(' : it == '}' ? '{' : '[') << ", found " << top << endl;
                return false;
            }
        }
    }
    if (st.empty())
    {
        return true;
    }
    else
    {
        cout << "Mismatch found: stack is not empty at the end" << endl;
        return false;
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(); // Ignore any newline characters after reading the number of test cases
    string str;
    for (int i = 0; i < n; i++)
    {
        getline(cin, str); // Use getline to correctly handle input strings
        if (balanced_string(str))
        {
            cout << "String is balanced\n";
        }
        else
        {
            cout << "String is not balanced\n";
        }
    }
    return 0;
}
