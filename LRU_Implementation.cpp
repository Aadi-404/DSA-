#include <bits/stdc++.h>
using namespace std;

class LRU
{
public:
    class Node
    {
    public:
        int key;
        int value;
        Node *next;
        Node *prev;
        Node(int key_, int value_)
        {
            key = key_;
            value = value_;
            prev = NULL;
            next = NULL;
        }
    };
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node *> m;

    LRU(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(int key_,int value_){
        Node* temp = new Node(key_,value_);
        head->next->prev = temp;
        temp ->next = head ->next;
        head->next = temp;
        temp ->prev = head;
    }

    void deleteNode(Node* ToDelete){
        Node* delprev = ToDelete->prev;
        Node* delnext = ToDelete->next;
        delnext->prev = delprev;
        delprev->next = delnext;
        delete(ToDelete);

    }
    int get(int key_)
    {
        if (m.find(key_) != m.end())
        {
            Node *resNode = m[key_];
            int resValue = resNode->value;
            m.erase(key_);
            deleteNode(resNode);
            addNode(key_, resValue);
            m[key_] = head->next;
            return resValue;
        }
        return -1;
    }
    void put(int key_, int value_)
    {
        if (m.find(key_) != m.end())
        {
            Node *Existing_key = m[key_];
            m.erase(key_);
            deleteNode(Existing_key);
        }
        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(key_, value_);
        m[key_] = head->next;
    }
};

main(){
    int a[5][2]= {{2,2},{1,1},{4,4},{3,3},{5,5}};
    LRU pages(3);
    pages.put(1,1);
    pages.put(2,2);
    cout<<pages.get(1)<<endl;
    pages.put(3,3);
    cout<<pages.get(2)<<endl;
    pages.put(4,4);
    pages.put(5,5);

    cout<<pages.get(4)<<endl;
    cout<<pages.get(3)<<endl;
    
}