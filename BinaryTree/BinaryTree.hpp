#ifndef BinaryTree_h
#define BinaryTree_h

#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node* leftPtr;
    Node* rightPtr;
};

template <typename T>
class BinaryTree
{
public:
    BinaryTree(T root):root_(newNode(root)){};
    BinaryTree(): root_(nullptr){};
    ~BinaryTree()
    {
        deleteBST(root_);
    }
    
    bool contains(const T target) const
    {
        return contains(root_, target);
    }
    
    void insert(const T data)
    {
        insert(root_, data);
    }
    
    int size() const
    {
        return size(root_);
    }
    
    int maxDepth() const
    {
        return maxDepth(root_);
    }
    
    T minVal() const
    {
        return minVal(root_);
    }
    
    T maxVal() const
    {
        return maxVal(root_);
    }

    void printInInreasingOrder() const
    {
        printInInreasingOrder(root_);
    }
    
	bool isEqual(const BinaryTree& other) const
    {
        return isEqual(root_, other.root_);
    }
    
private:
    Node<T>* root_;
    
    Node<T>* newNode(const T data)
    {
        Node<T>* node = new Node<T>;
        node->data = data;
        node->leftPtr = nullptr;
        node->rightPtr = nullptr;
        return node;
    }
    
    bool contains(const Node<T>* node, const T target) const
    {
        if (node == nullptr)
            return false;
        else if (target == node->data)
            return true;
        else
        {
            if (target < node->data)
                return contains(node->leftPtr, target);
            else
                return contains(node->rightPtr , target);
        }
    }
    
    void insert(Node<T>*& node,const T data)
    {
        if (node == nullptr)
            node = newNode(data);
        else
        {
            if (data < node->data)
                insert(node->leftPtr, data);
            else
                insert(node->rightPtr, data);
        }
    }
    
    int size(const Node<T>* node) const
    {
        if (node == nullptr)
            return 0;
        else
            return size(node->leftPtr) + size(node->rightPtr) + 1;
    }
    
    int maxDepth(const Node<T>* node) const
    {
        if (node == nullptr)
            return 0;
        else
        {
            int leftDepth = maxDepth(node->leftPtr);
            int rightDepth = maxDepth(node->rightPtr);
            if (leftDepth > rightDepth)
                return leftDepth + 1;
            else
                return rightDepth + 1;
        }
    }
    
    T minVal(Node<T>* node) const
    {
        if (node != nullptr)
        {
        	Node<T>* current = node;
            while (current->leftPtr != nullptr)
            	current = current->leftPtr;
        	return current->data;
        }
        else
        	throw std::invalid_argument("Empty Tree");
	}
    
    T maxVal(Node<T>* node) const
    {
        if (node != nullptr)
        {
            Node<T>* current = node;
            while (current->rightPtr != nullptr)
                current = current -> rightPtr;
            return current->data;
        }
        else
            throw std::invalid_argument("Empty Tree");
    }
    
    void printInInreasingOrder(const Node<T>* node) const
    {
        if (!node)
            return;
        else
        {
            printBST(node->leftPtr);
            std::cout << (node->data) << "\n";
            printBST(node->rightPtr);
        }
    }
    
    bool isEqual(const Node<T>* node1,const Node<T>* node2) const
    {
        if (!node1 && !node2)
            return true;
        else if (node1 != nullptr && node2 != nullptr)
        {
            return (node1->data == node2->data && isEqual(node1->leftPtr, node2->leftPtr)
                    && isEqual(node1->rightPtr, node2->rightPtr));
        }
        return false;
    }
    
    void deleteBST(Node<T>* node)
    {
        if (node == nullptr)
            return;
        if (!node)
        {
            deleteBST(node->leftPtr);
        	deleteBST(node->rightPtr);
        	delete node;
            node = nullptr;
        }
    }
};

#endif /* BinaryTree_h */
