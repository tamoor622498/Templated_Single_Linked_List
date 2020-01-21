#include <iostream>
#include <string>

using namespace std;
#ifndef LL_H
#define LL_H

template<class T>
class Node {
public:
    Node(const T &data); // Constructor
    T &GetData();
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
    void Display(); //Displays the list
    T* Begin(); //Start of list
    T* End(); //Returns null

private:
    Node<T> *m_head;
    int m_size;
};

template<class T>
LL<T>::LL() {
    m_head = nullptr;
    m_size = 0;
}

template<class T>
LL<T>::~LL() {
    if (m_head != nullptr){
        Node<T> *last = m_head;
        Node<T> *cur = m_head->GetNext();
        while (cur != nullptr){
            delete last;
            last = cur;
            cur = cur ->GetNext();
            m_size--;
        }
        delete last;
        cur = nullptr;
        last = nullptr;
        m_head = nullptr;
    }
}

template<class T>
void LL<T>::Push(const T &data) {
    Node<T> *newNode = new Node<T>(data);
    if (m_head == nullptr){
        m_head = newNode;
        //newNode->SetNext(nullptr);
        //delete newNode;
        m_size++;
    } else {
        Node<T> *CURR = m_head;
        while (CURR->GetNext() != nullptr){
            CURR = CURR->GetNext();
        }
        CURR->SetNext(newNode);
        m_size++;
    }
}

template<class T>
void LL<T>::PushMid(const T &) {

}

template<class T>
void LL<T>::Pop() {

}

template<class T>
T LL<T>::Retrieve(int i) {
    return nullptr;
}

template<class T>
void LL<T>::Remove(int i) {

}

template<class T>
T *LL<T>::Begin() {
    return m_head;
}

template<class T>
T *LL<T>::End() {
    return nullptr;
}

template<class T>
void LL<T>::Display() {
    cout << "START--";
    for (Node<T> *CURR = m_head; CURR != nullptr; CURR = CURR->GetNext()) {
        cout << CURR->GetData() << "--";
    }
    cout << "END" << endl;
}

#endif