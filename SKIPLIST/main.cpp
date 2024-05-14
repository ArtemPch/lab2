#include <iostream>
#include <vector>
#include "Skiplist.h"

int main() {
    SkipList<int> list(3); // ������������ ������� 3
    int choice, value;
    using namespace std;
    setlocale(LC_ALL, "rus");
    do {
        cout << "Menu:\n";
        cout << "1. ������ �������\n";
        cout << "2. ����� �� ��������\n";
        cout << "3. ������ �����\n";
        cout << "4. ������� ����\n";
        cout << "5. �����\n";
        cout << "��� �����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "������� �������� ��� �������: ";
            cin >> value;
            list.insert(value);
            break;
        case 2:
           cout << "������� �������� ��� ������: ";
           cin >> value;
            if (list.search(value)) {
                cout << "�������� " << value << " �������)\n";
            }
            else {
                cout << "�������� " << value << " �� �������(.\n";
            }
            break;
        case 3:
            cout << "������: " << list.getSize() << std::endl;
            break;
        case 4:
            cout << "����: " << list << endl;
            break;
        case 5:
            cout << "\n";
            break;
        default:
            cout << "������ �������� ���.\n";
        }
    } while (choice != 5);

    return 0;
}