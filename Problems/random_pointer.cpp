
// How to compile
// g++ -O3 random_pointer.cpp -o random_pointer.o

#include <iostream>
#include <vector>
#include <assert.h>


using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }

    ~Node() {
      if (next) delete next;
    }

    static void printNull() {
      cout << "[]" << endl;
    }

    void print() {
      Node* current = this;
      while (current)
      {
        if (current->random) {
          cout << "[" << current->val << " " << current->random->val;
        } else {
          cout << "[" << current->val << " " << current->random;  
        } 
        cout << "]" << endl;
        current = current->next;
      }
      cout << endl;
    }
};

class Solution {
public:
  Node* copyRandomList(Node* head) {
    if (!head) return NULL;

    // interweaved list
    Node* current = head;
    Node* aux;
    while (current)
    {
      aux = current->next; // saves old next value
      Node* newNode = new Node(current->val); // create a new node
      current->next = newNode; // assign new node as new next value
      newNode->next = aux;  // put the old next value after the newNode
      current = aux; // set current to the old next value
    }
    // head->print();

    // connecting randoms
    current = head;
    while (current)
    {
      if (current->random)
        current->next->random = current->random->next;
      current = current->next->next;
    }
    // head->print();
    
    // disconnecting dummy nodes
    current = head->next;
    aux = head;
    head = current;
    while (current)
    {
      aux->next = current->next;
      aux = current->next;
      if (current->next) {
        current->next = current->next->next;
        current = current->next;
      } else
      {
        current = NULL;
      }
    }
    // head->print();
  
    return head;
  }
};

int main(int argc, char *argv[]) 
{

  Solution s;

  vector<size_t> values = {7, 13, 11, 10, 1};
  vector<Node*> linkedList;
  
  for (size_t value : values) 
    linkedList.emplace_back(new Node(value));

  // random list
  for(size_t i, l = linkedList.size(); i < l; ++i)
  {
    Node* n = linkedList.at(i);

    switch (n->val)
    {
    case 7:
      n->next = linkedList.at(1);   // node 13
      break;
    case 13:
      n->next = linkedList.at(2);   // node 11
      n->random = linkedList.at(0); // node 7
      break;
    case 11:
      n->next = linkedList.at(3);   // node 10
      n->random = linkedList.at(4); // node 7
      break;
    case 10:
      n->next = linkedList.at(4);   // node 1
      n->random = linkedList.at(2); // node 11
      break;
    case 1:
      n->random = linkedList.at(0); // node 7
      break;
    default:
      break;
    }
    // cout << n->val << endl;
  }

  Node* head = linkedList.at(0);  // node 7
  head->print();
  Node* result = s.copyRandomList(head);
  result->print();
  if (head) {
    assert(head != result);
    delete head;
  }

  {
    Solution s;
    Node* head = NULL;
    Node* result = s.copyRandomList(head);
    head->print();
    result->print();
    if (head) {
      assert(head != result);
      delete head;
    }
  }
  return 0;
}


// USEFUL LINKS
// https://leetcode.com/problems/copy-list-with-random-pointer/