#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

bool isBalanced(const string& input) {
    vector<char> st;
    for (char c : input) {
        if (c == '(' || c == '[' || c == '{') {
            st.push_back(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) return false;
            char top = st.back();
            st.pop_back();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    while (true) {
        cout << "������ ����� � �������: ";
        string input;
        getline(cin, input);

        if (isBalanced(input)) {
            cout << "���������\n";
            break;
        }
        else {
            cout << "�������, ������ �� ���\n";
        }
    }
    return 0;
}
