#ifndef XOR_NODE
#define XOR_NODE

class XorNode
{
public:
    XorNode();
    explicit XorNode(const int value);
    ~XorNode();
    
    void setNodeValue(const int value);
    int getNodeValue() const;
    void setPrevOrNextNode(const XorNode* prev_next_node);
    XorNode* getPrevOrNextNode() const;

private:
    int value_;
    XorNode* prev_next_;
};

#endif // XOR_NODE