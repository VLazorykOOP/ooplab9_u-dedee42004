#include <iostream>
#include <list>
#include <deque>
#include <algorithm>

using namespace std;
int main() {
    // Вводим список L
    cout << "Enter the elements of list L separated by a space : ";
    list<int> L;
    int n;
    while (cin >> n) {
        L.push_back(n);
        if (cin.get() == '\n') {
            break;
        }
    }

    // Ввод дека D
    cout << "Enter the elements of deque D separated by a space : ";
    deque<int> D;
    while (cin >> n) {
        D.push_back(n);
        if (cin.get() == '\n') {
            break;
        }
    }
    if (D.size() % 2 == 0)
    {
        // Ищем первое вхождение последовательности элементов списка L в дек D, начиная с его второй половины
        auto it = search(D.begin() + D.size() / 2, D.end(), L.rbegin(), L.rend());
        if (it != D.end()) {
            // Если последовательность найдена, дублируем её в обратном порядке в деке D
            deque<int> dublicate(L.rbegin(), L.rend());
            D.insert(it, dublicate.begin(), dublicate.end());
        }
    }

    // Выводим итоговое состояние дека D
    cout << "Result deque D: ";
    for (auto elem : D) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
