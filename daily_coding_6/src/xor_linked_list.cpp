#include "xor_linked_list.hpp"
#include <iostream>

XorLinkedList::XorLinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}

XorLinkedList::XorLinkedList(XorNode* head) : head_(head), tail_(head), size_(1) {}

XorLinkedList::~XorLinkedList() {}

void XorLinkedList::addElement(XorNode* node)
{
    XorNode* new_tail = new XorNode(node->getNodeValue());
    new_tail->setPrevOrNextNode(tail_);
    tail_->setPrevOrNextNode(new_tail);
    tail_ = new_tail;
    size_++;
}

void XorLinkedList::addElement(const int value)
{
    XorNode* new_node = new XorNode(value);
    this->addElement(new_node);
}

XorNode* XorLinkedList::getNode(const int index) const 
{
    if((size_ == 0) || (index >= size_))
    {
        std::cout << "Bad get node!";
        return nullptr;
    }
    XorNode* prev_node = head_;
    XorNode* next_node = head_->getPrevOrNextNode();
    for(int i = 0; i < index; ++i)
    {
        XorNode* temp = next_node;
        next_node = (XorNode*)((long long)next_node->getPrevOrNextNode() ^ (long long)prev_node);
        prev_node = temp;
    }
    std::cout << "Value at node " << index << " is: " << prev_node->getNodeValue() << std::endl; 
    return prev_node;    
}

int XorLinkedList::getSize() const { return size_; }