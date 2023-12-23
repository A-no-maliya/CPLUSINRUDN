#include <iostream>
#include <vector>

using namespace std;

//Объявление класса Node, представляющего узел стека. В данном случае узел содержит целочисленное значение "key"
class Node {
public:
    int key;
};

//Объявление класса Stack, представляющего стек. Стек представлен вектором в экземпляре класса Node. 
//Определены конструктор по умолчанию и деструктор.
class Stack {
private:
    vector<Node> stack;

public:
    Stack() {}

    ~Stack() {}

 // пуст ли стек
    bool isEmpty() {
        return stack.empty();
    }

 // Вектор не может быть переполнен
    bool isFull() {
        return false; // Вектор не может быть переполнен
    }

//копирует содержимое текущего стека в другой стек, переданный как параметр
    void copyTo(Stack& newStack) {
        newStack.stack = stack;
    }

//добавляет новый элемент со значением k в вершину стека.Создается новый узел 
//Node с указанным значением и добавляется вектору stack с помощью функции push_back()
    void push(int k) {
        Node newNode;
        newNode.key = k;
        stack.push_back(newNode);
    }

//удаляет элемент из вершины стека. Если стек не пуст, то последний элемент 
//(вершина стека) извлекается с помощью функции back() и удаляется с помощью 
//функции pop_back(). Значение удаленного элемента выводится на консоль.
    void pop() {
        if (!isEmpty()) {
            Node poppedNode = stack.back();
            stack.pop_back();
            cout << "Popped element: " << poppedNode.key << endl;
        }
    }

//полностью очищает стек путем удаления всех элементов с помощью функции clear().
    void remove() {
        stack.clear();
    }

//выводит содержимое стека на консоль. Если стек пуст, выводится сообщение 
//"Stack is empty". В противном случае, выводятся элементы стека, начиная 
//с последнего добавленного элемента, используя цикл for.
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

//выводит текущую длину стека (количество элементов) на консоль, используя функцию size() вектора stack.
    void length() {
        cout << "Stack length: " << stack.size() << endl;
    }

//инвертирует порядок элементов в стеке с помощью функции reverse(). Это позволяет изменить порядок 
//элементов таким образом, что последний элемент становится первым, а первый - последним.
    void invert() {
        reverse(stack.begin(), stack.end());
    }

 //добавляет элементы из другого стека otherStack в конец текущего стека с помощью 
 //функции insert().Функция принимает в качестве параметра итераторы, указывающие 
 //на начало и конец вектора otherStack, и вставляет его элементы в конец вектора stack.
    void append(Stack& otherStack) {
        stack.insert(stack.end(), otherStack.stack.begin(), otherStack.stack.end());
    }

/*удаляет повторяющиеся элементы из стека
Создается новый вектор newStack для хранения 
уникальных элементов.Затем происходит проход по каждому элементу вектора stack.
Если элемент уже присутствует в newStack, то duplicateFound устанавливается в true, 
и проход к следующему элементу.Если duplicateFound остается false, элемент 
добавляется в newStack.На выходе новый вектор newStack присваивается вектору 
stack, чтобы заменить его содержимое.*/
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