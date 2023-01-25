#pragma once

struct Node
{
    Node* next_ = nullptr;
    Node* prev_ = nullptr;
    int value_;
    Node(int value) : value_(value), next_{nullptr}, prev_{nullptr} {};
};
class LinkedList
{
    public:
        LinkedList() = default;
        ~LinkedList();
        //LinkedList(int elem, Node* prev);

        void insert(const int value);
        void remove(const int index);
        int get(const int index) const;
        void clear();
        int size() const {return size_;};

    private:
        Node* first = nullptr;
        Node* last = nullptr;
        int size_{0};
    
};