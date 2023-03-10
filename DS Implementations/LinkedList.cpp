#include<iostream>
using namespace std;

struct Node* head = NULL;
struct Node* tail = NULL;

int llLength = 0;

struct Node {
    int data;
    struct Node* next;
};

void append(int ele) {
    Node* new_node = new Node;
    new_node->data = ele;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }

    llLength++;
}

void push(int ele) {
    Node* new_node = new Node;
    new_node->data = ele;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }

    llLength++;
}

void insert(int ele, int pos) {
    Node* new_node = new Node;
    new_node->data = ele;

    pos -= 2;
    Node* ptr = head;
    while (pos--) {
        ptr = ptr->next;
    }
    
    new_node->next = ptr->next;
    ptr->next = new_node;

    llLength++;
}

void truncate() {
    if (head == tail) {
        head = tail = NULL;

        llLength--;

        return;
    }

    // SAME IS DONE BELOW
    int localLength = llLength - 2;

    Node* ptr = head;
    while (localLength--) {
        ptr = ptr->next;
    }

    ptr->next = NULL;

    // Node* ptr = head;
    // while (ptr->next->next != NULL) {
    //     ptr = ptr->next;
    // }

    // ptr->next = NULL;

    llLength--;
}

void pop() {
    if (head == tail) {
        head = tail = NULL;

        llLength--;

        return;
    }

    // Node* ptr = head->next;
    // head = ptr;
    head = head->next;

    llLength--;
}

void remove(int pos) {
    if (head == tail) {
        head = tail = NULL;

        llLength--;

        return;
    }

    pos -= 2;

    // Node* ptr1 = head;
    Node* ptr = head;
    while (pos--) {
        ptr = ptr->next;
        // ptr1 = ptr1->next;
    }

    // 1
    // Node* ptr2 = ptr1->next;
    // Node* ptr3 = ptr2->next;
    
    // 2
    // Node* ptr2 = ptr1->next->next;

    ptr->next = ptr->next->next;

    llLength--;
}

void replace(int ele, int pos) {
    Node* ptr = head;

    pos -= 1;
    while (pos--) {
        ptr = ptr->next;
    }

    ptr->data = ele;
}

void search(int ele) {
    if (llLength == 0) {
        cout << "\nNo elements in the Linked List to search!" << endl;
        return;
    }

    int pos = 1;

    Node* ptr = head;
    while (ptr != NULL) {
        if (ptr->data == ele) {
            cout << "\nElement is found at position: " << pos << endl;
            return;
        }

        ptr = ptr->next;
        pos++;
    }

    cout << "\nNo element found!" << endl;
}

void displayLL() {
    if (llLength == 0) {
        cout << "\nNo elements in the Linked List to diaplay!" << endl;
        return;
    }

    Node* ptr = head;

    cout << "\nThe elements in Linked List are: ";
    while (ptr != NULL) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}
 
int main() {

    int i = 0;
    while (i != 11) {
        cout << "\nWhat operation do you want to perform?\n1. Create a linked list\n2. Insert element (at end)\n3. Insert element (at beginning)\n4. Insert element (in between)\n5. Delete element (from end)\n6. Delete element (from beginning)\n7. Delete element (from between)\n8. Search an element\n9. Replace element\n10. Display linked list\n11. Exit\nChoice: ";
        cin >> i;

        switch(i) {
            case 1:
                int n;
                cout << "\nHow many elements do you want to add? ";
                cin >> n;

                int num;
                for (int i = 0; i < n; i++) {
                    cout << "Enter element " << i << ": ";
                    cin >> num;
                    append(num);
                }
                
                displayLL();

                continue;
            
            case 2:
                cout << "\nEnter the element to be inserted: ";
                cin >> num;

                append(num);
                displayLL();

                continue;

            case 3:
                cout << "\nEnter the element to be inserted: ";
                cin >> num;

                push(num);
                displayLL();
                
                continue;

            case 4:
                int ele, pos;
                cout << "\nEnter the element and position seperated by space: ";
                cin >> ele >> pos;

                while (pos > llLength) {
                    cout << "\nPosition greater than size of Linked List! Cannot enter element";
                    cout << "\nRe-enter position: ";
                    cin >> pos;
                }

                while (pos <= 0) {
                    cout << "\nPosition cannot be less than 1";
                    cout << "\nRe-enter position: ";
                    cin >> pos;
                }

                insert(ele, pos);
                displayLL();

                continue;
            
            case 5:
                truncate();
                displayLL();
                continue;
            
            case 6:
                pop();
                displayLL();
                continue;

            case 7:
                cout << "\nEnter the element index's to be deleted: ";
                cin >> pos;

                while (pos > llLength) {
                    cout << "\nPosition greater than size of Linked List! Cannot enter element";
                    cout << "\nRe-enter position: ";
                    cin >> pos;
                }

                while (pos <= 0) {
                    cout << "\nPosition cannot be less than 1";
                    cout << "\nRe-enter position: ";
                    cin >> pos;
                }

                remove(pos);
                displayLL();

                continue;
            
            case 8:
                cout << "\nEnter the element to be searched: ";
                cin >> num;

                while (num > INT_MAX || num < INT_MIN) {
                    cout << "\nOnly 32-bit integers are allowed";
                    cout << "\nRe-enter element: ";
                    cin >> num;
                }

                search(num);

                continue;

            case 9:
                if (llLength == 0) {
                    cout << "No element in Linked List to replace";
                } else {
                    cout << "\nEnter the element and position seperated by space: ";
                    cin >> ele >> pos;

                    while (pos > llLength) {
                    cout << "\nPosition greater than size of Linked List! Cannot enter element";
                    cout << "\nRe-enter position: ";
                    cin >> pos;
                    }

                    while (pos <= 0) {
                        cout << "\nPosition cannot be less than 1";
                        cout << "\nRe-enter position: ";
                        cin >> pos;
                    }

                    replace(ele, pos);
                    displayLL();
                }

                continue;
            
            case 10:
                displayLL();
                continue;
            
            case 11:
                cout << "\nExited successfully";
                break;
        }

    }
    
    return 0;
}