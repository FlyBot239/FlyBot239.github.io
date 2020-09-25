#include <iostream>
#include <string>

using namespace std;

class Stack {
private:
    struct Node {
        int Value;
        Node* Next;

        Node(int NewValue, Node* NextNode) {
            Value = NewValue;
            Next = NextNode;
        }
    };

    Node* head_ = nullptr;
    int size_ = 0;

public:
    void Push(int PushValue);
    int Pop();
    int Back() const;
    int Size() const;
    void Clear();
};


void Stack::Push(int PushValue) {
    head_ = new Node(PushValue, head_);
    size_++;
}

int Stack::Pop() {
    int Value = head_->Value;
    Node* Next = head_->Next;
    delete head_;
    head_ = Next;
    size_--;
    return Value;
}

int Stack::Back() const {
    return head_->Value;
}

int Stack::Size() const {
    return size_;
}

void Stack::Clear() {
    while(size_  > 0) {
        Node* next_node = head_->Next;
        delete head_;
        head_ = next_node;
        size_--;
    }
}

int main() {
    Stack a;
    string s;

    while(true) {
        cin >> s;
        if(s == "push") {
            int n;
            cin >> n;
            a.Push(n);
            cout << "ok" << endl;
        } else if(s == "pop") {
            if(a.Size() > 0) {
                cout << a.Pop() << endl;
            } else {
                cout << "error" << endl;
            }
        } else if(s == "back") {
            if (a.Size() > 0) {
                cout << a.Back() << endl;
            } else {
                cout << "error" << endl;
            }
        } else if(s == "size") {
            cout << a.Size() << endl;
        } else if(s == "clear") {
            a.Clear();
            cout << "ok" << endl;
        } else if(s == "exit") {
            cout << "bye";
            break;
        }
    }
}