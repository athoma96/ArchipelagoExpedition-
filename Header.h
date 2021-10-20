//
// Author: Allen Thomas
// UIC Spring 2021
// Prof. Mobasheri
//
// Project 6: For this program, you will write a C++ Program to represent an archipelagoexpedition.
//This expedition will use an array of linked lists as its primary storage structure.
//
// Header.h file

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <string.h>
#include <iostream>
#define TRUE 1
#define FALSE 0

using namespace std;

class MyLNode
{
 private:
  int elem;
  string elem1;
  MyLNode* next;
  
 public:
  MyLNode (int v1);
  MyLNode (string v2);
  MyLNode (int v1, MyLNode* n);
  MyLNode (string v2, MyLNode* n);
  
  string getElem1 ();
  int getElem ();
  void setNext (MyLNode* n);
  MyLNode* getNext();
};

class intList {
  private:
    MyLNode* Head;
    
    void copyNode (MyLNode* pNode)
    {
        if (pNode != NULL)
        {
            copyNode(pNode->getNext());
            Head = new MyLNode(pNode->getElem(), Head);
        }
    }
  public:
    intList ();
    ~intList();
    void insertValue (int v1);
    void deleteValue(int v1);
    void makeCopy (const intList &p);
    int getListLength();
    int getNthValue(int n);
    bool checkNode(int val);
    int isEmpty();
    void clear();
    MyLNode* getHd();
    void setHd(MyLNode* tmp);
    
    intList& operator= (const intList& p)
    {
        if (this == &p )   // both operands are the same
        return *this;     //   do nothing, just return

          // Deallocate the existing list
        MyLNode* curr = Head;
        MyLNode* prev;
        while (curr != NULL)
        {
            prev = curr;
            curr = curr->getNext();
            delete curr;
            curr = prev;
        }
          Head = NULL;

          makeCopy(p);       // Do a deep copy

          return *this;       // allow for "cascading assignments":  a = b = c;
    }

};

// List class used to build a linked list with string values
class strList {
  private:
    MyLNode* Head;
  public:
    strList ();
    ~strList();
    void insertValue (string v1);
    void deleteValue(string v1);
    int  getListLength();
    bool checkNode(string val);
    string getNthValue(int n);
    
};
