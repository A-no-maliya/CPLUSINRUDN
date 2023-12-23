#include <iostream>
#include <vector>

using namespace std;

//���������� ������ Node, ��������������� ���� �����. � ������ ������ ���� �������� ������������� �������� "key"
class Node {
public:
    int key;
};

//���������� ������ Stack, ��������������� ����. ���� ����������� �������� � ���������� ������ Node. 
//���������� ����������� �� ��������� � ����������.
class Stack {
private:
    vector<Node> stack;

public:
    Stack() {}

    ~Stack() {}

 // ���� �� ����
    bool isEmpty() {
        return stack.empty();
    }

 // ������ �� ����� ���� ����������
    bool isFull() {
        return false; // ������ �� ����� ���� ����������
    }

//�������� ���������� �������� ����� � ������ ����, ���������� ��� ��������
    void copyTo(Stack& newStack) {
        newStack.stack = stack;
    }

//��������� ����� ������� �� ��������� k � ������� �����.��������� ����� ���� 
//Node � ��������� ��������� � ����������� ������� stack � ������� ������� push_back()
    void push(int k) {
        Node newNode;
        newNode.key = k;
        stack.push_back(newNode);
    }

//������� ������� �� ������� �����. ���� ���� �� ����, �� ��������� ������� 
//(������� �����) ����������� � ������� ������� back() � ��������� � ������� 
//������� pop_back(). �������� ���������� �������� ��������� �� �������.
    void pop() {
        if (!isEmpty()) {
            Node poppedNode = stack.back();
            stack.pop_back();
            cout << "Popped element: " << poppedNode.key << endl;
        }
    }

//��������� ������� ���� ����� �������� ���� ��������� � ������� ������� clear().
    void remove() {
        stack.clear();
    }

//������� ���������� ����� �� �������. ���� ���� ����, ��������� ��������� 
//"Stack is empty". � ��������� ������, ��������� �������� �����, ������� 
//� ���������� ������������ ��������, ��������� ���� for.
    void print() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        }
        else {
            cout << "Stack elements:" << endl;
            for (int i = stack.size() - 1; i >= 0; i--) {
                cout << stack[i].key << endl;
            }
        }
    }

//������� ������� ����� ����� (���������� ���������) �� �������, ��������� ������� size() ������� stack.
    void length() {
        cout << "Stack length: " << stack.size() << endl;
    }

//����������� ������� ��������� � ����� � ������� ������� reverse(). ��� ��������� �������� ������� 
//��������� ����� �������, ��� ��������� ������� ���������� ������, � ������ - ���������.
    void invert() {
        reverse(stack.begin(), stack.end());
    }

 //��������� �������� �� ������� ����� otherStack � ����� �������� ����� � ������� 
 //������� insert().������� ��������� � �������� ��������� ���������, ����������� 
 //�� ������ � ����� ������� otherStack, � ��������� ��� �������� � ����� ������� stack.
    void append(Stack& otherStack) {
        stack.insert(stack.end(), otherStack.stack.begin(), otherStack.stack.end());
    }

/*������� ������������� �������� �� �����
��������� ����� ������ newStack ��� �������� 
���������� ���������.����� ���������� ������ �� ������� �������� ������� stack.
���� ������� ��� ������������ � newStack, �� duplicateFound ��������������� � true, 
� ������ � ���������� ��������.���� duplicateFound �������� false, ������� 
����������� � newStack.�� ������ ����� ������ newStack ������������� ������� 
stack, ����� �������� ��� ����������.*/
    void removeDuplicates() {
        vector<Node> newStack;
        for (Node node : stack) {
            bool duplicateFound = false;
            for (Node newNode : newStack) {
                if (node.key == newNode.key) {
                    duplicateFound = true;
                    break;
                }
            }
            if (!duplicateFound) {
                newStack.push_back(node);
            }
        }
        stack = newStack;
    }
};

int main() {
    Stack stack;
    int choice;

    do {
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Remove\n";
        cout << "4. Print\n";
        cout << "5. Length\n";
        cout << "6. Invert\n";
        cout << "7. Append\n";
        cout << "8. Remove Duplicates\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int element;
            cout << "Enter the element to push: ";
            cin >> element;
            stack.push(element);
            break;
        }
        case 2:
            stack.pop();
            break;
        case 3:
            stack.remove();
            break;
        case 4:
            stack.print();
            break;
        case 5:
            stack.length();
            break;
        case 6:
            stack.invert();
            break;
        case 7: {
            Stack otherStack;
            int element;
            cout << "Enter the number of elements to append: ";
            cin >> element;
            for (int i = 0; i < element; i++) {
                int value;
                cout << "Enter element " << (i + 1) << ": ";
                cin >> value;
                otherStack.push(value);
            }
            stack.append(otherStack);
            break;
        }
        case 8:
            stack.removeDuplicates();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
        cout << endl;

    } while (choice != 0);

    return 0;
}