#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    vector<int> v;
    int n;
    cout << "Enter the elements of the array:" << endl;
    while (cin >> n) {
        v.push_back(n);
        if (cin.get() == '\n') {
            break;
        }
    }
    set<int> s(v.begin(), v.end());

    int min_val = *s.begin();
    int max_val = *s.rbegin();

    auto it = s.lower_bound(min_val);
    advance(it, 1);

    auto end_it = s.upper_bound(max_val-1);

    vector<int> result;

    for (; it != end_it; ++it) {
        result.push_back(*it);
    }

    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
