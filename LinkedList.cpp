#include "LinkedList.h"
#include <stdexcept>
#include <iostream>

LinkedList::~LinkedList()
{
    clear();
}

void LinkedList::clear()
{
       Node* head = first;
    while(head && head->next_)
    {
        Node* tmp = head;
        head = head->next_;
        delete tmp;
    }
    first = last = nullptr;
    size_ = 0;
}

void LinkedList::insert(int value)
{
    Node* node = new Node(value);
    if(size_ == 0)
    {
        first = last = node;
        first->next_ = nullptr;
        first->prev_ = nullptr;
        ++size_;
        return;
    }

    Node* current = first;
    while(current->next_)
    {
        current = current->next_;
    }
    node->prev_ = current;
    current->next_ = node;
    last = node;
    ++size_;
}

int LinkedList::get(const int index) const
{
    if(index == 0)
    {
        return first->value_;
    }
    if(index == size_)
    {
        return last->value_;
    }
    Node* current = first;
    int localInd = 0;
    while(localInd != index && current->next_)
    {
        current=current->next_;
        ++localInd;
    }
    if(localInd == index)
    {
        return current->value_;
    }else
    {
        throw std::out_of_range("Index not found");
    }
}

void LinkedList::remove(const int index)
{
    Node* current = first;
    int localInd = 0;
    Node* prev;
    while(localInd != index && current->next_)
    {
        prev = current;
        current=current->next_;
        ++localInd;
    }
    if(localInd == index)
    {
        prev->next_ = current->next_;
        delete current;
    }else
    {
        throw std::out_of_range("Index not found");
    }
}

void LinkedList::reverse()
{
    Node* head = first;
    Node* prev = nullptr;
    while(head)
    {
        Node* tmpNext = head->next_;
        head->next_ = prev;
        prev = head;
        head = tmpNext;
    }
    Node* tmpFirst = first;
    first = last;
    last = tmpFirst;
}