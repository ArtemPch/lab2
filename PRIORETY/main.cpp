#include<iostream>
#include"..//PRIORETY/priorety.h"

using namespace std;


int main() {
    PriorityQueue<int> queue;
    int choice, value, priority;
    setlocale(LC_ALL, "rus");
    do {
        cout << "����:\n";
        cout << "1. �������� �������\n";
        cout << "2. �������� ������������ �������\n";
        cout << "3. ������� ������������ �������\n";
        cout << "4. ��������� ������� �������\n";
        cout << "5. ������� ��� �������\n";
        cout << "6. �����\n";
        cout << "��� �����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "������� �������� ��� ����������: ";
            cin >> value;
            cout << "������� ���������: ";
            cin >> priority;
            queue.push(value, priority);
            break;
        case 2:
            try {
                std::cout << "������������ �������: " << queue.top() << endl;
            }
            catch (const std::out_of_range& e) {
                cerr << e.what() << endl;
            }
            break;
        case 3:
            try {
                queue.pop();
                cout << "������������ ������� ������.\n";
            }
            catch (const out_of_range& e) {
                cerr << e.what() << endl;
            }
            break;
        case 4:
            cout << (queue.empty() ? "������� �����.\n" : "������� �� �����.\n");
            break;
        case 5:
            cout << "��� �������:\n";
            queue.print();
            break;
        case 6:
            cout << "�����.\n";
            break;
        default:
            cout << "�������� ����.\n";
        }
    } while (choice != 6);

    return 0;
}
