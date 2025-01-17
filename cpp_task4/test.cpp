// reutgerber@gmail.com
// provides main();
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include <stack>
#include "complex.hpp"
#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp"
#include <string>

// בדיקת איטרטור Pre-Order בעץ בינארי
TEST_CASE("test binary tree preorder iterator") {
    cout << "test binary tree preorder iterator" << endl;
    Tree<double, 2> tree; // עץ בינארי שמכיל מספרים עשרוניים (double).
    Node<double>* root_node = new Node<double>(1.1);
    tree.add_root(root_node);
    Node<double>* n1 = new Node<double>(1.2);
    Node<double>* n2 = new Node<double>(1.3);
    Node<double>* n3 = new Node<double>(1.4);
    Node<double>* n4 = new Node<double>(1.5);
    Node<double>* n5 = new Node<double>(1.6);

    // הוספת תתי צמתים לעץ
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    vector<double> expected = { 1.1, 1.2, 1.4, 1.5, 1.3, 1.6 };
    vector<double> actual;

    // איטרציה על העץ בסדר Pre-Order ואיסוף התוצאות
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it)
    {
        actual.push_back(it->get_value());
    }

    // בדיקה שהתוצאה המתקבלת שווה לתוצאה הצפויה
    CHECK(expected == actual); 
}

// בדיקת איטרטור Post-Order בעץ בינארי
TEST_CASE("test binary tree postorder iterator") {
    cout << "test binary tree postorder iterator" << endl;
    Tree<double, 2> tree; // עץ בינארי שמכיל מספרים עשרוניים (double).
    Node<double>* root_node = new Node<double>(1.1);
    tree.add_root(root_node);
    Node<double>* n1 = new Node<double>(1.2);
    Node<double>* n2 = new Node<double>(1.3);
    Node<double>* n3 = new Node<double>(1.4);
    Node<double>* n4 = new Node<double>(1.5);
    Node<double>* n5 = new Node<double>(1.6);

    // הוספת תתי צמתים לעץ
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    vector<double> expected = { 1.4, 1.5, 1.2, 1.6, 1.3, 1.1 };
    vector<double> actual;

    // איטרציה על העץ בסדר Post-Order ואיסוף התוצאות
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it)
    {
        actual.push_back(it->get_value());
    }

    // בדיקה שהתוצאה המתקבלת שווה לתוצאה הצפויה
    CHECK(expected == actual);
}

// בדיקת איטרטור In-Order בעץ בינארי
TEST_CASE("test binary tree inorder iterator") {
    cout << "test binary tree inorder iterator" << endl;
    Tree<double, 2> tree; // עץ בינארי שמכיל מספרים עשרוניים (double).
    Node<double>* root_node = new Node<double>(1.1);
    tree.add_root(root_node);
    Node<double>* n1 = new Node<double>(1.2);
    Node<double>* n2 = new Node<double>(1.3);
    Node<double>* n3 = new Node<double>(1.4);
    Node<double>* n4 = new Node<double>(1.5);
    Node<double>* n5 = new Node<double>(1.6);

    // הוספת תתי צמתים לעץ
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    vector<double> expected = { 1.4, 1.2, 1.5, 1.1, 1.6, 1.3 };
    vector<double> actual;

    // איטרציה על העץ בסדר In-Order ואיסוף התוצאות
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it)
    {
        actual.push_back(it->get_value());
    }

    // בדיקה שהתוצאה המתקבלת שווה לתוצאה הצפויה
    CHECK(expected == actual); 
}

// בדיקת איטרטור BFS בעץ בינארי
TEST_CASE("test binary tree bfs iterator") {
    cout << "test binary tree bfs iterator" << endl;
    Tree<double, 2> tree; // עץ בינארי שמכיל מספרים עשרוניים (double).
    Node<double>* root_node = new Node<double>(1.1);
    tree.add_root(root_node);
    Node<double>* n1 = new Node<double>(1.2);
    Node<double>* n2 = new Node<double>(1.3);
    Node<double>* n3 = new Node<double>(1.4);
    Node<double>* n4 = new Node<double>(1.5);
    Node<double>* n5 = new Node<double>(1.6);

    // הוספת תתי צמתים לעץ
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    vector<double> expected = { 1.1, 1.2, 1.3, 1.4, 1.5, 1.6 };
    vector<double> actual;

    // איטרציה על העץ בסדר BFS ואיסוף התוצאות
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it)
    {
        actual.push_back(it->get_value());
    }

    // בדיקה שהתוצאה המתקבלת שווה לתוצאה הצפויה
    CHECK(expected == actual);
}

// בדיקת איטרטור BFS בעץ בינארי באמצעות לולאת auto
TEST_CASE("test binary tree auto loop bfs iterator") {
    cout << "test binary tree auto loop bfs iterator" << endl;
    Tree<double, 2> tree; // עץ בינארי שמכיל מספרים עשרוניים (double).
    Node<double>* root_node = new Node<double>(1.1);
    tree.add_root(root_node);
    Node<double>* n1 = new Node<double>(1.2);
    Node<double>* n2 = new Node<double>(1.3);
    Node<double>* n3 = new Node<double>(1.4);
    Node<double>* n4 = new Node<double>(1.5);
    Node<double>* n5 = new Node<double>(1.6);

    // הוספת תתי צמתים לעץ
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    vector<double> expected = { 1.1, 1.2, 1.3, 1.4, 1.5, 1.6 };
    vector<double> actual;

    // איטרציה על העץ בסדר BFS ואיסוף התוצאות באמצעות לולאת auto
    for (auto node : tree)
    {
         actual.push_back(node.get_value());
    }

    // בדיקה שהתוצאה המתקבלת שווה לתוצאה הצפויה
    CHECK(expected == actual);
}

// בדיקת איטרטור בערימת מינימום בינארית
TEST_CASE("test minimum binary heap iterator") {
    cout << "test minimum binary heap iterator" << endl;
    Tree<double, 2> tree; // עץ בינארי שמכיל מספרים עשרוניים (double).
    Node<double>* root_node = new Node<double>(1.1);
    tree.add_root(root_node);
    Node<double>* n1 = new Node<double>(1.2);
    Node<double>* n2 = new Node<double>(1.3);
    Node<double>* n3 = new Node<double>(1.4);
    Node<double>* n4 = new Node<double>(1.5);
    Node<double>* n5 = new Node<double>(1.6);

    // הוספת תתי צמתים לעץ
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    vector<double> expected = { 1.1, 1.2, 1.3,1.4, 1.5, 1.6 };
    vector<double> actual;

    tree.myHeap();

    // איטרציה על הערימה הבינארית ואיסוף התוצאות
    for (auto it = tree.begin_heap(); it != tree.end_heap(); ++it)
    {
        actual.push_back(*it);
    }

    // בדיקה שהתוצאה המתקבלת שווה לתוצאה הצפויה
    CHECK(expected == actual);
}

// בדיקת איטרטור Pre-Order בעץ עם שלושה ילדים לכל צומת
TEST_CASE("test three_ary_tree preorder iterator") {
    cout << "test three_ary_tree preorder iterator" << endl;
    Node<double>* root_node = new Node<double>(1.1);
    Node<double>* n1 = new Node<double>(1.2);
    Node<double>* n2 = new Node<double>(1.3);
    Node<double>* n3 = new Node<double>(1.4);
    Node<double>* n4 = new Node<double>(1.5);
    Node<double>* n5 = new Node<double>(1.6);

    Tree<double, 3> three_ary_tree; // עץ עם שלושה ילדים לכל צומת.
    three_ary_tree.add_root(root_node);
    three_ary_tree.add_sub_node(root_node, n1);
    three_ary_tree.add_sub_node(root_node, n2);
    three_ary_tree.add_sub_node(root_node, n3);
    three_ary_tree.add_sub_node(n1, n4);
    three_ary_tree.add_sub_node(n2, n5);

    vector<double> expected = { 1.1, 1.2, 1.5, 1.3, 1.6, 1.4 };
    vector<double> actual;

    // איטרציה על העץ בסדר Pre-Order ואיסוף התוצאות
    for (auto it = three_ary_tree.begin_pre_order(); it != three_ary_tree.end_pre_order(); ++it)
    {
        actual.push_back(it->get_value());
    }
    CHECK(expected == actual);
}

// בדיקת איטרטור DFS בעץ עם שלושה ילדים לכל צומת
TEST_CASE("test three_ary_tree dfsiterator iterator") {
    cout << "test three_ary_tree dfsiterator iterator" << endl;
    Node<double>* root_node = new Node<double>(1.1);
    Node<double>* n1 = new Node<double>(1.2);
    Node<double>* n2 = new Node<double>(1.3);
    Node<double>* n3 = new Node<double>(1.4);
    Node<double>* n4 = new Node<double>(1.5);
    Node<double>* n5 = new Node<double>(1.6);

    Tree<double, 3> three_ary_tree; // עץ עם שלושה ילדים לכל צומת.
    three_ary_tree.add_root(root_node);
    three_ary_tree.add_sub_node(root_node, n1);
    three_ary_tree.add_sub_node(root_node, n2);
    three_ary_tree.add_sub_node(root_node, n3);
    three_ary_tree.add_sub_node(n1, n4);
    three_ary_tree.add_sub_node(n2, n5);

    vector<double> expected = { 1.1, 1.2, 1.5, 1.3, 1.6, 1.4 };
    vector<double> actual;

    // איטרציה על העץ בסדר DFS ואיסוף התוצאות
    for (auto it = three_ary_tree.begin_dfs_order(); it != three_ary_tree.end_dfs_order(); ++it)
    {
        actual.push_back(it->get_value());
    }
    CHECK(expected == actual);
}

// בדיקת איטרטור Pre-Order בעץ בינארי שמכיל אובייקטים מסוג Complex<double>
TEST_CASE("test Complex preorder iterator") {
    cout << "test Complex preorder iterator" << endl;
    Complex<double> croot(1.1, 1.1);
    Complex<double> c1(1.2, 1.2);
    Complex<double> c2(1.3, 1.3);
    Complex<double> c3(1.4, 1.4);
    Complex<double> c4(1.5, 1.5);
    Complex<double> c5(1.6, 1.6);

    Node<Complex<double>>* c_root_node = new Node<Complex<double>>(croot);
    Node<Complex<double>>* c1_node = new Node<Complex<double>>(c1);
    Node<Complex<double>>* c2_node = new Node<Complex<double>>(c2);
    Node<Complex<double>>* c3_node = new Node<Complex<double>>(c3);
    Node<Complex<double>>* c4_node = new Node<Complex<double>>(c4);
    Node<Complex<double>>* c5_node = new Node<Complex<double>>(c5);

    Tree<Complex<double>, 2> Complex_tree;
    Complex_tree.add_root(c_root_node);
    Complex_tree.add_sub_node(c_root_node, c1_node);
    Complex_tree.add_sub_node(c_root_node, c2_node);
    Complex_tree.add_sub_node(c1_node, c3_node);
    Complex_tree.add_sub_node(c1_node, c4_node);
    Complex_tree.add_sub_node(c2_node, c5_node);

    vector<Complex<double>> expected = { croot, c1, c3, c4, c2, c5 };
    vector<Complex<double>> actual;

    // איטרציה על העץ בסדר Pre-Order ואיסוף התוצאות
    for (auto it = Complex_tree.begin_pre_order(); it != Complex_tree.end_pre_order(); ++it)
    {
        actual.push_back(it->get_value());
    }
    CHECK(expected == actual);
}

// בדיקת איטרטור Pre-Order בעץ בינארי שמכיל מחרוזות (string)
TEST_CASE("test string binary tree preorder iterator") {
    cout << "test string binary tree preorder iterator" << endl;
    Tree<string, 2> tree; // עץ בינארי שמכיל מחרוזות.
    Node<string>* root_node = new Node<string>("all");
    tree.add_root(root_node);
    Node<string>* n1 = new Node<string>("you");
    Node<string>* n2 = new Node<string>("need");
    Node<string>* n3 = new Node<string>("is");
    Node<string>* n4 = new Node<string>("love");
    Node<string>* n5 = new Node<string>("hello");

    // הוספת תתי צמתים לעץ
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    vector<string> expected = { "all", "you", "is", "love", "need", "hello" };
    vector<string> actual;

    // איטרציה על העץ בסדר Pre-Order ואיסוף התוצאות
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it)
    {
        actual.push_back(it->get_value());
    }

    // בדיקה שהתוצאה המתקבלת שווה לתוצאה הצפויה
    CHECK(expected == actual);
}
