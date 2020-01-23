#include <iostream>
#include <string>

using namespace std;
#ifndef LL_H
#define LL_H

template<class T>
class Node {
public:
    Node(const T &data);
    T& GetData();
    void SetData(const T &data);
    Node<T>* GetNext();
    void SetNext(Node<T> *next);

private:
    T m_data;
    Node<T>* m_next;
};

template<class T>
Node<T>::Node(const T &data) {
    m_data = data;
    m_next = nullptr;
}

template<class T>
T &Node<T>::GetData() {
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

template <class T>
class Iterator{
public:
    Iterator(Node<T>* NodePoint);
    void operator++();
    void operator++(int);
    bool End();
    T operator*();

private:
    Node<T>* CURR;
};

template<class T>
Iterator<T>::Iterator(Node<T> *NodePoint) {
    CURR = NodePoint;
}

template<class T>
bool Iterator<T>::End() {
    return CURR != nullptr;
}

template<class T>
void Iterator<T>::operator++() {
    CURR = CURR->GetNext();
}

template<class T>
void Iterator<T>::operator++(int) {
    CURR = CURR->GetNext();
}

template<class T>
T Iterator<T>::operator*() {
    return CURR->GetData();
}

template <class T>
class LL{
public:
        LL();
        ~LL();
        void PushFront(const T &data);
        void Push(const T &data);
        void Clear();
        Iterator<T> begin();
        int GetSize();
        void Display();

private:
        Node<T>* head;
        int size;
    };

template<class T>
LL<T>::LL() {
    head = nullptr;
    size = 0;
}

template<class T>
LL<T>::~LL() {
    Clear();
}

template<class T>
void LL<T>::PushFront(const T &data) {
    Node<T>* newNode = new Node<T>(data);

    if (head == nullptr){
        head = newNode;
        newNode->SetNext(nullptr);
    } else {
        Node<T>* CurHead = head;
        head = newNode;
        newNode->SetNext(CurHead);
    }
}

template<class T>
void LL<T>::Push(const T &data) {
    Node<T> *newNode = new Node<T>(data);
    if (head == nullptr){
        head = newNode;
        newNode->SetNext(nullptr);

        size++;
    } else {
        Node<T> *CURR = head;
        while (CURR->GetNext() != nullptr){
            CURR = CURR->GetNext();
        }
        CURR->SetNext(newNode);
        size++;
    }
}

template<class T>
void LL<T>::Clear() {
    if (head != nullptr){
        Node<T> *last = head;
        Node<T> *cur = head->GetNext();
        while (cur != nullptr){
            delete last;
            last = cur;
            cur = cur ->GetNext();
            size--;
        }
        delete last;
        cur = nullptr;
        last = nullptr;
        head = nullptr;
    }
}

template<class T>
Iterator<T> LL<T>::begin() {
    return Iterator<T>(head);
}

template<class T>
int LL<T>::GetSize() {
    return size;
}

template<class T>
void LL<T>::Display() {
    cout << "START--";
    for (Iterator<T> I = begin(); I.End(); I++){
        cout << *I << "--";
    }
    cout << "END" << endl;
}

#endif