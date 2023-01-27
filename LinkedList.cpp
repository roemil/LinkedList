#include "LinkedList.h"
#include <stdexcept>

LinkedList::~LinkedList()
{
    Node* head = first;
    while(head && head->next_)
    {
        Node* tmp = head;
        head = head->next_;
        delete tmp;
    }
    first = nullptr;
}

void LinkedList::insert(int value)
{
    Node* node = new Node(value);
    if(size_ == 0)
    {
        first = node;
        first->next_ = nullptr;
        first->prev_ = nullptr;
        ++size_;
        return;
    }

    Node* head = first;
    while(head->next_)
    {
        head = head->next_;
    }

    head->next_ = node;
    ++size_;
}

int LinkedList::get(const int index) const
{
    Node* head = first;
    int localInd = 0;
    while(localInd != index && head->next_)
    {
        head=head->next_;
        ++localInd;
    }
    if(localInd == index)
    {
        return head->value_;
    }else
    {
        throw std::out_of_range("Index not found");
    }
}

void LinkedList::remove(const int index)
{
    Node* head = first;
    int localInd = 0;
    Node* prev;
    while(localInd != index && head->next_)
    {
        prev = head;
        head=head->next_;
        ++localInd;
    }
    if(localInd == index)
    {
        prev->next_ = head->next_;
        delete head;
    }else
    {
        throw std::out_of_range("Index not found");
    }
}