#include "DCLL.h"

int main() {
    myDCLL list;
    int choice, value, position, size;

    while (true) {
        cout << "\n--- Doubly Circular Linked List Menu ---\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Delete from Head\n";
        cout << "4. Delete from Tail\n";
        cout << "5. Delete from Any Position\n";
        cout << "6. Search for a Value\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the number of elements to insert at head: ";
            cin >> size;
            for (int i = 0; i < size; i++) {
                cout << "Enter value to insert at head " << i + 1 << ": ";
                cin >> value;
                list.insertAtHead(value);
            }
            break;

        case 2:
            cout << "Enter the number of elements to insert at tail: ";
            cin >> size;
            for (int i = 0; i < size; i++) {
                cout << "Enter value to insert at tail " << i + 1 << ": ";
                cin >> value;
                list.insertAtTail(value);
            }
            break;

        case 3:
            list.deleteFromHead();
            cout << "Deleted from head.\n";
            break;

        case 4:
            list.deleteFromTail();
            cout << "Deleted from tail.\n";
            break;

        case 5:
            cout << "Enter position to delete: ";
            cin >> position;
            list.deleteFromAnyPosition(position);
            break;

        case 6:
            cout << "Enter value to search: ";
            cin >> value;
            if (list.search(value)) {
                cout << "Value found in the list.\n";
            }
            else {
                cout << "Value not found in the list.\n";
            }
            break;

        case 7:
            cout << "Current List: ";
            list.display();
            break;

        case 8:
            cout << "Exiting program.\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}