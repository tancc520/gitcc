#include <iostream>
#include <string>
using namespace std;

int main() {
    int m;
    cin >> m;

    while (m--) {
        string s;
        cin >> s;

        int n = s.size();          // 位数
        long long sum = 0;

        for (char c : s) {         // 逐位求 n 次方
            long long d = c - '0';  //ASCII码相减得int数
            long long p = 1;
            for (int i = 0; i < n; i++) p *= d;
            sum += p;
        }

        cout << (sum == stoll(s) ? 'T' : 'F') << endl;
    }

    return 0;
}
