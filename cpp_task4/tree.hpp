// reutgerber@gmail.com
#ifndef TREE_HPP
#define TREE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include "node.hpp"
#include "PreOrderiterator.hpp"
#include "PostOrderIterator.hpp"
#include "in_order_iterator.hpp"
#include "bfs_iterator.hpp"
#include "heap_iterator.hpp"
#include "dfsiterator.hpp"

// תבנית מחלקה Tree המייצגת עץ כללי עם מספר ילדים מקסימלי k (ברירת מחדל 2)
template <typename T, int k = 2>
class Tree {
    Node<T> *root; // מצביע לשורש העץ

public:
    // פונקציה לציור צומת בודד
    void drawNode(sf::RenderWindow &window, Node<T> *node, float x, float y, float parentX, float parentY, int level, float horizontalSpacing, float verticalSpacing) {
        if (!node) return;

        // ציור הצומת (עיגול)
        sf::CircleShape shape(20); // רדיוס של 20 יחידות
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(x - shape.getRadius(), y - shape.getRadius());
        window.draw(shape);

        // ציור קו מההורה לצומת הנוכחי
        if (level != 0) {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(parentX, parentY + 20)),
                sf::Vertex(sf::Vector2f(x, y))
            };
            window.draw(line, 2, sf::Lines);
        }

        // המרת ערך הצומת למחרוזת ויצירת אובייקט טקסט
        sf::Text text;
        sf::Font font;
        font.loadFromFile("arial.ttf"); // טעינת הפונט
        text.setFont(font); // הגדרת הפונט
        text.setString(std::to_string(node->data)); // הנחה שהערך ניתן להמרה למחרוזת
        text.setCharacterSize(15); // הגדרת גודל הטקסט
        text.setFillColor(sf::Color::Red); // הגדרת צבע הטקסט
        text.setPosition(x - 10, y - 10); // מיקום הטקסט קרוב לצומת

        window.draw(text); // ציור הטקסט

        // חישוב מיקומים וציור ילדים
        float childX = x - (node->children.size() - 1) * horizontalSpacing / 2.0f;
        for (auto child : node->children) {
            drawNode(window, child, childX, y + verticalSpacing, x, y, level + 1, horizontalSpacing / 2, verticalSpacing);
            childX += horizontalSpacing;
        }
    }

    // פונקציה להגדרת חלון SFML וציירת העץ
    void drawTree(Node<T> *root) {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization");

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            float startY = 50; // התחלת ציור מלמעלה של החלון
            drawNode(window, root, 400, startY, 0, 0, 0, 200, 100);
            window.display();
        }
    }

    // הוספת שורש לעץ
    void add_root(Node<T> *root) {
        this->root = root;
    }

    // קונסטרוקטור
    Tree() : root(nullptr), deleted(false) {}

    // דסטרוקטור
    ~Tree() {
        if (!deleted)
            DeleteAll();
    }

    // פונקציה למחיקת כל הצמתים בעץ
    void DeleteAll() {
        deleteTree(root);
        deleted = true;
    }

    
   

    //get the parent of node
    int parent(int i) { return (i-1)/2; } 
  
    // to get index of left child of node at index i 
    int left(int i) { return (2*i + 1); } 
  
    // to get index of right child of node at index i 
    int right(int i) { return (2*i + 2); } 

   
     
     // Inserts a new key 'k' 
    void insertKey(T data,int i) 
    { 
    
  
    // First insert the new key at the end 
    
    min_heap.push_back(data); 
  
    // Fix the min heap property if it is violated 
    while (i != 0 && min_heap[parent(i)] > min_heap[i]) 
    { 
        cout<<"swap ("<<i<<","<<parent(i)<<") val ("<<min_heap[i]<<","<<min_heap[parent(i)]<<")"<<endl;
       swap(min_heap[i], min_heap[parent(i)]); 
       i = parent(i); 
    } 
} 

// פונקציה ליצירת ערימת מינימום מכל הצמתים בעץ
    void myHeap()
    {
        int i=0;
         for (auto node : *this) {
            {
            cout<<"heap in "<<node.get_value()<<endl;
            insertKey(node.get_value(),i);
            i++;
            }
        }

    }

    // איטרטור לסריקת עץ בסדר DFS
    DfsOrderIterator<T> begin_dfs_order() {
        return DfsOrderIterator<T>(root);
    }

    DfsOrderIterator<T> end_dfs_order() {
        return DfsOrderIterator<T>(nullptr);
    }

    // איטרטור לסריקת עץ בסדר Pre-Order
    PreOrderIterator<T> begin_pre_order() {
        return PreOrderIterator<T>(root);
    }

    PreOrderIterator<T> end_pre_order() {
        return PreOrderIterator<T>(nullptr);
    }

    // איטרטור לסריקת עץ בסדר Post-Order
    PostOrderIterator<T, k> begin_post_order() {
        return PostOrderIterator<T, k>(root);
    }

    PostOrderIterator<T, k> end_post_order() {
        return PostOrderIterator<T, k>(nullptr);
    }

    // איטרטור לסריקת עץ בסדר In-Order
    InOrderIterator<T, k> begin_in_order() {
        return InOrderIterator<T, k>(root);
    }

    InOrderIterator<T, k> end_in_order() {
        return InOrderIterator<T, k>(nullptr);
    }

    // איטרטור לסריקת עץ בסדר BFS
    BfsOrderIterator<T, k> begin_bfs_scan() {
        return BfsOrderIterator<T, k>(root);
    }

    BfsOrderIterator<T, k> end_bfs_scan() {
        return BfsOrderIterator<T, k>(nullptr);
    }

    // ברירת מחדל לסריקת עץ בסדר BFS
    BfsOrderIterator<T, k> begin() {
        return BfsOrderIterator<T, k>(root);
    }

    BfsOrderIterator<T, k> end() {
        return BfsOrderIterator<T, k>(nullptr);
    }

    // איטרטור לערימת מינימום
    HeapIterator<T> begin_heap() {
        return HeapIterator<T>(0, min_heap);
    }

    HeapIterator<T> end_heap() {
        return HeapIterator<T>(min_heap.size(), min_heap);
    }

    // הוספת תת-צומת לצומת הורה
    void add_sub_node(Node<T> *parent, Node<T> *child) {
        parent->add_child(child, k);
    }

private:
    bool deleted; // משתנה לבדיקה אם העץ נמחק
    std::vector<T> min_heap; // ערימת מינימום


    // פונקציה לבדיקת התאמה בערימת מינימום
    bool check(int parentIndex, int newIndex, std::vector<T> &v) {
        if (parentIndex < 0)
            return false;
        if (v[parentIndex] > v[newIndex]) {
            std::swap(v[parentIndex], v[newIndex]);
            check(parentIndex - 1, parentIndex, v);
            return true;
        }
        return false;
    }

    // פונקציה להוספת ערך לערימת מינימום
    void add_to_heap(T val, std::vector<T> &v) {
        v.push_back(val);
        bool ret = check(v.size() - 2, v.size() - 1, v);
    }

    // פונקציה רקורסיבית למחיקת כל הצמתים בעץ
    void deleteTree(Node<T> *node) {
        if (node) {
            for (auto child : node->children) {
                deleteTree(child);
            }
            delete node;
        }
    }
};

#endif // TREE_HPP
