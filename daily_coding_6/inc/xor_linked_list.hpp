#ifndef XOR_LINKED_LIST
#define XOR_LINKED_LIST

#include "xor_node.hpp"

class XorLinkedList
{
public:
    XorLinkedList();
    explicit XorLinkedList(XorNode* head);
    ~XorLinkedList();

    void addElement(XorNode* node);
    void addElement(const int value);
    XorNode* getNode(const int index) const;
    int getSize() const;

private:
    XorNode* head_;
    XorNode* tail_;
    int size_;   
};

#endif // XOR_LINKED_LIST