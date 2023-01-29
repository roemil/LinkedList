#include "LinkedList.h"
#include <stdexcept>
#include <iostream>

namespace{
    void isIndexInBounds(const int index, const int listSize)
    {
        if(index > listSize || index < 0)
        {
            throw std::out_of_range("Index not found");
        }
    }
}

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

void LinkedList::append(const int value)
{
    if(size_ == 0)
    {
        createFirstNode(value);
        return;
    }

    Node* node = new Node(value);

    node->prev_ = last;
    last->next_ = node;
    last = node;

    ++size_;
}

void LinkedList::insert(int index, const int value)
{
    isIndexInBounds(index, size_+1); // +1 since we might want to insert at the end of the list
    Node* node = new Node(value);
    if(index == 0)
    {
        node->next_ = first;
        first->prev_ = node;
        first = node;
        return;
    }
    if(index == size_)
    {
        append(value);
        return;
    }

    Node* current = first;
    while(index && current)
    {
        --index;
        current = current->next_;
    }
    assert(index == 0);
    Node* next = current->next_;
    Node* prev = current;
    node->next_ = next;
    node->prev_ = current;
    current->next_->prev_ = node;
    current->next_ = node;
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