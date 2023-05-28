#include <iostream>
#include <map>

using namespace std;

struct greater_less {
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) const {
        if (lhs.first > rhs.first) {
            return true;
        }
        else if (lhs.first < rhs.first) {
            return false;
        }
        else {
            return lhs.second < rhs.second;
        }
    }
};

int main() {
    map<pair<int, int>, int, greater_less> M;
    int year, month, client, hours;
    cout << "Enter" << endl;
    while (cin >> year >> month >> client >> hours) {
        if (year <= 2023 && month <= 12 && hours > 0)
        {
            pair<int, int> key = make_pair(year, month);
            if (M.count(key)) {
                M[key]++;
            }
            else {
                M[key] = 1;
            }
        }
        else
        {
            cout << "Wrong Input"<<endl;
            continue;
        }
    }

    for (auto& entry : M) {
        cout << entry.first.first << " " << entry.first.second << " " << entry.second << endl;
    }

    return 0;
}
