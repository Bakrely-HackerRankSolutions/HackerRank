//https://www.hackerrank.com/challenges/abstract-classes-polymorphism/problem
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected:
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
class LRUCache : public Cache{
    
    public:
    LRUCache(int cap){
        cp = cap;
        head = NULL;
        tail = NULL;
    };
    
    void set(int key,int value){
        map<int,Node*>::iterator it = mp.find(key);
        if (it != mp.end()){
            //Cache Hit
            it->second->value = value;
            //if key is first element of cache
            if(it->second->prev == NULL) return;
            //Disjonct and if element is at the end reassign tail
            it->second->prev->next = it->second->next;
            if(it->second->next == NULL) {
                tail = it->second->prev;
            }else{
                it->second->next->prev = it->second->prev;
            }
            
            //Append
            head->prev = it->second;
            it->second->next = head;
            it->second->prev = NULL;
            head = it->second;
        }
        else{
            //Cache Miss
            Node* new_Node = new Node(key,value);
            //If Cache full make room
            if(mp.size() == cp)
            {
                int keytodelete = tail->key; //save key in the node at the tail to delete in the map
                Node* temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                free(temp); //Handle Garbage
                mp.erase(keytodelete);
            }
            
            mp.insert(pair<int,Node*>(key,new_Node));
            if(head == NULL){
                head = new_Node;
                tail = new_Node;
                return;
            }
            head->prev = new_Node;
            new_Node->next = head;
            head = new_Node;
            
        }
        

    };
    int get(int key){
        map<int,Node*>::iterator it = mp.find(key);
        if (it != mp.end())return it->second->value;
        else return -1;

    };
};
int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      }
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}

