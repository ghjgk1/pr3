// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList
{
private: 
    Node* list = nullptr;
    Node* head = nullptr;
    Node* tail = nullptr;

    void find_head() {
        Node* current = tail;
        while (current->prev != nullptr) {
            current = current->prev;
        }
        head = current;
    }

    void find_tail() {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        tail = current;
    }

public:
	void push_front(int data) {
        if (list == nullptr) {
            list = new Node { data, nullptr, nullptr };
            tail = list;
            head = list;
        }
        else {
            Node* current = list;
            while (current->prev != nullptr) {
                current = current->prev;
            }
            current->prev = new Node{ data, current, nullptr };
            current->prev->next = current;
            head = current->prev;
            if (tail == nullptr) tail = list;
        }
	}

    void push_back(int data) {
        if (list == nullptr) {
            list = new Node{ data, nullptr, nullptr };
            tail = list;
            head = list;
        }
        else {
            Node* current = list;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node{ data, nullptr, current };
            current->next->prev = current;
            tail = current->next;
            if (head == nullptr) head = list;
        }
    }

    void pop_front() {
        if (list == nullptr) {
            std::cout << "Пустой лист" << std::endl;
            tail = nullptr;
            head = nullptr;
        }
        else {
            if (tail != head) {
                Node* current = head->next;
                if (list->prev == nullptr && list->next == nullptr) {
                    list = NULL;
                }
                else {
                    if (current->prev == list) {
                        list = current;
                    }
                    current->prev = nullptr;
                    head = current;
                }
            }
            else {
                list = tail = head = nullptr;
            }
        }
    }

    void pop_back() {
        if (list == nullptr) {
            std::cout << "Пустой лист" << std::endl;
            tail = nullptr;
            head = nullptr;
        }
        else {
            if (tail != head) {
                Node* current = tail->prev;
                if (list->prev == nullptr && list->next == nullptr) {
                    list = NULL;
                }
                else {
                    if (current->next == list) {
                        list = current;
                    }
                    current->next = nullptr;
                    tail = current;
                }
            }
            else {
                list = tail = head = nullptr;
            }
        }
    }

    void display() {
        if (list == nullptr) {
            std::cout << "Пустой лист" << std::endl;
            tail = nullptr;
            head = nullptr;
        }
        else {
            Node* current = head;
            while (current != nullptr) {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }

    void sort() {
        if (list == nullptr) {
            std::cout << "Пустой лист" << std::endl;
            tail = nullptr;
            head = nullptr;
        }
        else {
            Node* current = head->next;
            Node* end = nullptr;
            while (current != end) {
                if (current->data < current->prev->data) {
                    int data = current->prev->data;
                    current->prev->data = current->data;
                    current->data = data;
                }
                if (current->next == end) {
                    end = current;
                    current = head;
                }
                current = current->next;
            }
        }
    }


    
    void remove_duplicates() {
        if (list == nullptr) {
            std::cout << "Пустой лист" << std::endl;
            tail = nullptr;
            head = nullptr;
        }
        else {
            Node* current = head;
            while (current != nullptr) {
                Node* temp = current;
                while (temp->next != nullptr) {
                    if (temp->next->data == current->data) {
                        if (temp->next == list) {
                            list = temp;
                        }
                        Node* duplicate = temp->next;
                        temp->next = temp->next->next;

                        if (temp->next != nullptr)
                            temp->next->prev = temp;

                        delete duplicate;
                    }
                    else {
                        temp = temp->next;
                    }
                }
                current = current->next;
            }
        }
        find_tail();
    }
};


int main()
{
    DoublyLinkedList list;
    setlocale(LC_ALL, "");
    while (true) {
        std::cout << "Добавить элемент в начало. Нажмите 0" << std::endl;
        std::cout << "Добавить элемент в конец.  Нажмите 1" << std::endl;
        std::cout << "Удалить элемент с начала. Нажмите 2" << std::endl;
        std::cout << "Удалить элемент с конца. Нажмите 3" << std::endl;
        std::cout << "Отобразить список. Нажмите 4" << std::endl;
        std::cout << "Сортировать список. Нажмите 5" << std::endl;
        std::cout << "Удалить дубликаты. Нажмите 6" << std::endl;
        std::cout << "Выйти. Нажмите 7" << std::endl;
        int number;
        std::cin >> number;
        if (number == 0) {
            std::cout << "Введите число" << std::endl;
            std::cin >> number;
            list.push_front(number);
        }
        else if (number == 1) {
            std::cout << "Введите число" << std::endl;
            std::cin >> number;
            list.push_back(number);
        }
        else if (number == 2) {
            list.pop_front();
        }
        else if (number == 3) {
            list.pop_back();
        }
        else if (number == 4) {
            list.display();
        }
        else if (number == 5) {
            list.sort();
        }
        else if (number == 6) {
            list.remove_duplicates();
        }
        else if (number == 7) {
            break;
        }
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
