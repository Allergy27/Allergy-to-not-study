#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int s, f;
        char c;
        cin >> s >> c >> f;
        if (s == 0) s = 12;

        if (1 <= s && s < 12) {
            if (f <= 9 && (s != 10 && s != 11 && s != 12))
                cout << 0 << s << ":" << 0 << f << " AM" << endl;
            else if ((s == 10 || s == 11 || s == 12) && f <= 9)
                cout << s << ":" << 0 << f << " AM" << endl;
            else if ((s == 10 || s == 11 || s == 12) && f > 9)
                cout << s << ":" << f << " AM" << endl;
            else
                cout << 0 << s << ":" << f << " AM" << endl;
        } else if (s == 12) {
            if (f < 9)
                cout << s << ":" << 0 << f << " PM" << endl;
            else
                cout << s << ":" << f << " AM" << endl;

        } else {
            s = s - 12;
            if (f <= 9 && (s != 10 && s != 11 && s != 12))
                cout << 0 << s << ":" << 0 << f << " PM" << endl;
            else if ((s == 10 || s == 11 || s == 12) && f <= 9)
                cout << s << ":" << f << 0 << " PM" << endl;
            else if ((s == 10 || s == 11 || s == 12) && f > 9)
                cout << s << ":" << f << " PM" << endl;
            else
                cout << 0 << s << ":" << f << " PM" << endl;
        }
    }
    return 0;
}
