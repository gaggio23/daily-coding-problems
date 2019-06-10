/*
This problem was asked by Google.

An XOR linked list is a more memory efficient doubly linked list. 
Instead of each node holding next and prev fields, it holds a field named both, which is an XOR of the next node and the previous node. 
Implement an XOR linked list; it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.
*/

#include "xor_linked_list.hpp"

int main()
{
    XorNode* head = new XorNode(7);
    XorLinkedList* list = new XorLinkedList(head);
    list->addElement(14);
    list->addElement(21);
    list->addElement(36);
    for(int i = 0; i < list->getSize(); ++i)
    {
        list->getNode(i);
    }
    return 0;
}