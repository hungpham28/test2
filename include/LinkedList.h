#include <iostream>
#include <string>
using namespace std;
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
template <typename T>
class Node
{
public:
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node<T>(T d);
    virtual ~Node();
    void insert_back(Node<T>& ptr);
    void remove();
    void operator+(Node<T>& ptr);

};

template <typename T>
class LinkedList
{
public:
    LinkedList<T>();
    virtual ~LinkedList<T>();
    void push_back(T new_data);
    void push_front(T new_data);
    void pop_back();
    void pop_front();
    void remove(const T& );
    void update(const T& );
    void insertAt();
    void removeAt();
    void updateAt();
    void reset();
    LinkedList<T>& sorting(bool cmp(const T& ,const T& ));
    T getAt();
    string toString();
    template<typename O>
    friend ofstream& operator<<(ofstream&, const LinkedList<O>& );
    Node<T>* begin();
    Node<T>* end();
    int getLength();
private:
    Node<T>* head;
    Node<T>* tail;
    int length;
};
#include"../src/LinkedList.hpp"
#endif // LINKEDLIST_H
