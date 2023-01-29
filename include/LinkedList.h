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
        LinkedList(const int value);
        ~LinkedList();
        //LinkedList(int elem, Node* prev);

        void append(const int value);
        void insert(int index, const int value);
        void remove(int index);
        void reverse();
        int get(int index) const;
        void clear();
        int size() const {return size_;};

    private:
        Node* first = nullptr;
        Node* last = nullptr;
        int size_{0};

        void createFirstNode(const int value);
    
};