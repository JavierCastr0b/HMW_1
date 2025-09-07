#include <iostream>
#include <stdexcept>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int v) : val(v), next(nullptr) {}
};

class ForwardList {
private:
    ListNode* head = nullptr;
    int n = 0;

public:
    ForwardList() = default;
    ~ForwardList() { clear(); }

    bool empty() const {
        if (head == nullptr) {
            return true;
        }else {
            return false;
        }
    }

    int size() const {
        int num = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            num++;
            temp = temp->next;
        }
        return num;
    }

    void push_front(int x) {
        ListNode* newNode = new ListNode(x);
        newNode -> next = head;
        head = newNode;
        n++;
    }

    int T_front() const {
        if (head != nullptr) {
            return head -> val;
        } else {
            throw runtime_error("lista vacia");
        }

    }

    void push_back(int x) {
        ListNode* newNode = new ListNode(x);
        if (head == nullptr) {
            head = newNode;
        } else {
            ListNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;

        }
        n++;

    }

    int T_back() const {
        if (head == nullptr) {
            throw runtime_error("lista vacia");
        }
        ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->val;

    }

    int pop_front() {
        if (head == nullptr) {
            throw runtime_error("lista vacia");
        }
        int val = head -> val;
        ListNode* temp = head;
        head = head -> next;
        delete temp;
        n--;
        return val;
    }

    int pop_back() {
        if (head == nullptr) {
            throw runtime_error("lista vacia");
        }
        if (head->next == nullptr) {
            int val = head->val;
            delete head;
            head = nullptr;
            n--;
            return val;
        }
        ListNode* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        int val = temp->next->val;
        delete temp->next;
        temp->next = nullptr;
        n--;
        return val;
    }

    int operator[](int i) const {
        if (i< 0 || i >= n) {
            throw runtime_error("indice fuera de rango");
        }

        ListNode* temp = head;
        for (int j = 0; j < i; j++) {
            temp = temp->next;
        }
        return temp->val;
    }

    void clear() {
        while (head) {
            ListNode* temp = head;
            head = head -> next;
            delete temp;
        }
        n = 0;
    }

    void reverse() {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        while (curr != nullptr) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void sort() {
        if (!head || !head->next) return;

        ListNode* head2 = nullptr;
        ListNode* curr  = head;

        while (curr) {
            ListNode* next = curr->next;
            if (!head2 || curr->val < head2->val) {
                curr->next = head2;
                head2 = curr;
            } else {
                ListNode* p = head2;
                while (p->next && p->next->val <= curr->val) {
                    p = p->next;
                }
                curr->next = p->next;
                p->next = curr;
            }

            curr = next;
        }

        head = head2;
    }
};



