#include <iostream>
#include <vector>
#include "Skiplist.h"

int main() {
    SkipList<int> list(3); // Максимальный уровень 3
    int choice, value;
    using namespace std;
    setlocale(LC_ALL, "rus");
    do {
        cout << "Menu:\n";
        cout << "1. Ввести элемент\n";
        cout << "2. Поиск по элементу\n";
        cout << "3. Размер листа\n";
        cout << "4. Вывести лист\n";
        cout << "5. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите значение для вставки: ";
            cin >> value;
            list.insert(value);
            break;
        case 2:
           cout << "Введите значение для поиска: ";
           cin >> value;
            if (list.search(value)) {
                cout << "Значение " << value << " найдено)\n";
            }
            else {
                cout << "Значение " << value << " не найдено(.\n";
            }
            break;
        case 3:
            cout << "Размер: " << list.getSize() << std::endl;
            break;
        case 4:
            cout << "Лист: " << list << endl;
            break;
        case 5:
            cout << "\n";
            break;
        default:
            cout << "Такого значения нет.\n";
        }
    } while (choice != 5);

    return 0;
}