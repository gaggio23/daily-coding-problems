#include "xor_node.hpp"

XorNode::XorNode() : value_(0), prev_next_(nullptr) {}

XorNode::XorNode(const int value) : value_(value), prev_next_(nullptr) {}

XorNode::~XorNode() {}

void XorNode::setNodeValue(const int value) { value_ = value; }

int XorNode::getNodeValue() const { return value_; }

void XorNode::setPrevOrNextNode(const XorNode* prev_next_node) { prev_next_ =  (XorNode*)((long long)prev_next_ ^ (long long)prev_next_node); }

XorNode* XorNode::getPrevOrNextNode() const { return prev_next_; }