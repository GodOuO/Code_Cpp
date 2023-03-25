#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
    int n;
    while (cin >> n) {
        vector<vector<int>>a(n, vector<int>(2, 0));
        for (int i = 0; i < n; i++) {
            cin >> a[i][0] >> a[i][1];
        }
        string odr;
        cin >> odr;
        int len = odr.size() - 2;
        int sum = 0;
        while (len >= 0) {
            if (odr[len] == '(') {
                sum += a[odr[len + 1] - 'A'][0] * a[odr[len + 1] - 'A'][1] * a[odr[len + 2] -
                        'A'][1];
                a[odr[len + 1] - 'A'][1] = a[odr[len + 2] - 'A'][1];
                odr.erase(len + 2, 2);
                odr.erase(len, 1);
            }
            --len;
        }
        cout << sum << endl;
    }
}