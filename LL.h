#include <iostream>

using namespace std;
#ifndef LL_H
#define LL_H

template<class T>
class Node {
public:
    Node(const T &data); // Constructor
    T &GatData();
    void SetData(const T &data);
    Node<T> *GetNext();
    void SetNext(Node<T> *next);
private:
    T m_data; //data
    Node<T> *m_next; //next node
};

template<class T>
Node<T>::Node(const T &data) {
    m_data = data;
    m_next = nullptr;
}

template<class T>
T &Node<T>::GatData() {
    return m_data;
}

template<class T>
void Node<T>::SetData(const T &data) {
    m_data = data;
}

template<class T>
Node<T> *Node<T>::GetNext() {
    return m_next;
}

template<class T>
void Node<T>::SetNext(Node<T> *next) {
    m_next = next;
}

template<class T>
class LL {
public:
    LL(); //New list with head set to null
    ~LL(); //Destructor
    void Push(const T&); //Adds to the end
    void PushMid(const T&); //Adds to the middle
    void Pop(); //Removes last item
    T Retrieve(int i); //Retrieves item at index
    void Remove(int i); //Removes Item at index


private:
    Node<T> *m_head;
    int m_size;
};

#endif