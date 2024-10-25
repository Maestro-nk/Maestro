#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

inline void addToFront(Node** head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

inline void removeFromFront(Node** head) {
    if (*head != nullptr) {
        Node* temp = *head;
        *head = (*head)->next;
        delete temp;
    }
}

inline void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "null" << endl;
}

inline void addToEnd(Node** head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    if (*head == nullptr) {
        newNode->next = nullptr;
        *head = newNode;
    }
    else {
        Node* current = *head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = nullptr;
    }
}

inline void removeFromEnd(Node** head) {
    Node* temp = *head;
    if (*head == nullptr) {
        return;
    }
    if ((*head)->next == nullptr) {
        delete* head;
        *head = nullptr;
    }
    else {
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
}

inline Node* searchElement(Node* head, int value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            cout << "The value was found" << endl;
            return temp;
        }
        temp = temp->next;
    }
    cerr << "Error: Value not found" << endl;
    return nullptr;
}

inline void reverseList(Node** head) {
    Node* prev = nullptr;
    Node* current = *head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

inline void sortList(Node** head) {
    if (*head == nullptr) return;
    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr;
    do {
        swapped = false;
        ptr1 = *head;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swap(ptr1->data, ptr1->next->data);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

struct TwoWayNode {
    int data;
    TwoWayNode* next;
    TwoWayNode* prev;
};

inline void clearList(Node** head) {
    Node* current = *head;
    Node* next;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
    *head = nullptr;
}

inline void toTwoWayList(Node** head) {
    if (*head == nullptr) return;
    Node* current = *head;
    TwoWayNode* newHead = new TwoWayNode;
    TwoWayNode* newTail = newHead;
    newHead->data = current->data;
    newHead->prev = nullptr;
    current = current->next;
    while (current != nullptr) {
        TwoWayNode* newNode = new TwoWayNode;
        newNode->data = current->data;
        newNode->prev = newTail;
        newTail->next = newNode;
        newTail = newNode;
        current = current->next;
    }
    newTail->next = newHead;
    newHead->prev = newTail;
    clearList(head);
    *head = (Node*)newHead;
}

int main() {
    Node* head = nullptr;

    // Добавление элементов в начало списка
    addToFront(&head, 10);
    addToFront(&head, 20);
    addToFront(&head, 30);
    cout << "List after adding elements to the front: ";
    printList(head);

    // Добавление элементов в конец списка
    addToEnd(&head, 40);
    addToEnd(&head, 50);
    cout << "List after adding elements to the end: ";
    printList(head);

    // Удаление элемента из начала списка
    removeFromFront(&head);
    cout << "List after removing an element from the front: ";
    printList(head);

    // Удаление элемента из конца списка
    removeFromEnd(&head);
    cout << "List after removing an element from the end: ";
    printList(head);

    // Поиск элемента по значению
    Node* foundNode = searchElement(head, 20);
    if (foundNode != nullptr) {
        cout << "Element 20 found in the list." << endl;
    }
    else {
        cout << "Element 20 not found in the list." << endl;
    }

    // Разворот списка
    reverseList(&head);
    cout << "List after reversing: ";
    printList(head);

    // Сортировка списка
    sortList(&head);
    cout << "List after sorting: ";
    printList(head);

    // Очистка списка
    clearList(&head);
    cout << "List after clearing: ";
    printList(head);

    // Преобразование в двусвязный круговой список
    Node* headTwoWay = nullptr;
    addToFront(&headTwoWay, 10);
    addToFront(&headTwoWay, 20);
    addToFront(&headTwoWay, 30);
    toTwoWayList(&headTwoWay);
    cout << "Two-way circular linked list created and original list cleared." << endl;

    return 0;
}