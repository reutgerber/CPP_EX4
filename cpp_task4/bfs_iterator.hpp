//reutgerber@gmail.com
#pragma once

#include "node.hpp"
#include <stack>
#include "queue"
#include "dfsiterator.hpp"

template<typename T, int k = 2>
class BfsOrderIterator {
public:
    using value_type = Node<T>;
    using pointer = Node<T>*;
    using reference = Node<T>&;

    //constructor
    BfsOrderIterator<T, k>(Node<T>* root)  {
      
        this->currentNode = nullptr;
            if (root) queue.push(root);
            advance();
        
    }






    BfsOrderIterator operator++() {
        advance();
        return *this;
    }

    BfsOrderIterator operator++(int) {
        BfsOrderIterator tmp = *this;
        advance();
        return tmp;
    }

    reference operator*() {
        return *currentNode;
    }

    pointer operator->() {
        return currentNode;
    }

    bool operator==(const BfsOrderIterator& other) {
     
        return (other.currentNode == this->currentNode && this->queue == other.queue);
    }

    bool operator!=(const BfsOrderIterator<T, k>& other) {
        return !(*this == other);
    }

private:
    std::queue<Node<T>*> queue;
    Node<T>* currentNode;

  


    void advance() {
       
        if (!queue.empty()) {
            this->currentNode = queue.front();
            queue.pop();
            for (auto child : this->currentNode->children) {
                queue.push(child);
            }
        }
        else {
            this->currentNode = nullptr;
        }
    }





};



