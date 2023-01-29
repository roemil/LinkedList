#include "LinkedList.h"
#include <stdexcept>
#include <iostream>

LinkedList::LinkedList(const int value)
{
    createFirstNode(value);
}

void LinkedList::createFirstNode(const int value)
{
    Node* node = new Node(value);
    assert(size_ == 0);
    first = last = node;
    first->next_ = nullptr;
    first->prev_ = nullptr;
    ++size_;
}

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
    if(size_ == 0)
    {
        createFirstNode(value);
        return;
    }

    Node* node = new Node(value);
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

namespace{
    void isIndexInBounds(const int index, const int listSize)
    {
        if(index > listSize || index < 0)
        {
            throw std::out_of_range("Index not found");
        }
    }
}

int LinkedList::get(int index) const
{
    isIndexInBounds(index, size_);
    if(index == 0)
    {
        return first->value_;
    }
    if(index == size_)
    {
        return last->value_;
    }
    Node* current = first;
    while(index && current->next_)
    {
        current=current->next_;
        --index;
    }
    return current->value_;
}

void LinkedList::remove(int index)
{
    isIndexInBounds(index, size_);
    Node* current = first;
    Node* prev;
    while(index && current->next_)
    {
        prev = current;
        current=current->next_;
        --index;
    }
    prev->next_ = current->next_;
    delete current;
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