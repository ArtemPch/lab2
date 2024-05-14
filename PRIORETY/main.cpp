#include<iostream>
#include"..//PRIORETY/priorety.h"

using namespace std;


int main() {
    PriorityQueue<int> queue;
    int choice, value, priority;
    setlocale(LC_ALL, "rus");
    do {
        cout << "Меню:\n";
        cout << "1. Добавить элемент\n";
        cout << "2. Получить максимальный элемент\n";
        cout << "3. Удалить максимальный элемент\n";
        cout << "4. Проверить пустоту очереди\n";
        cout << "5. Вывести всю очередь\n";
        cout << "6. Выйти\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите значение для добавления: ";
            cin >> value;
            cout << "Введите приоритет: ";
            cin >> priority;
            queue.push(value, priority);
            break;
        case 2:
            try {
                std::cout << "Максимальный элемент: " << queue.top() << endl;
            }
            catch (const std::out_of_range& e) {
                cerr << e.what() << endl;
            }
            break;
        case 3:
            try {
                queue.pop();
                cout << "Максимальный элемент удален.\n";
            }
            catch (const out_of_range& e) {
                cerr << e.what() << endl;
            }
            break;
        case 4:
            cout << (queue.empty() ? "Очередь пуста.\n" : "Очередь не пуста.\n");
            break;
        case 5:
            cout << "Вся очередь:\n";
            queue.print();
            break;
        case 6:
            cout << "Выход.\n";
            break;
        default:
            cout << "Неверный ввод.\n";
        }
    } while (choice != 6);

    return 0;
}
