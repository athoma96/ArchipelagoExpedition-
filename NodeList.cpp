//
// Author: Allen Thomas
// UIC Spring 2021
// Prof. Mobasheri
//
// Project 6: For this program, you will write a C++ Program to represent an archipelagoexpedition.
//This expedition will use an array of linked lists as its primary storage structure.
//
// NodeList.cpp file

#include "Header.h"
#include "Island.h"
#include "Archipelago.h"

MyLNode::MyLNode (int v1)
{
  elem = v1;
  next = NULL;
}

MyLNode::MyLNode (string v2)
{
  elem1 = v2;
  next = NULL;
}
  
MyLNode::MyLNode (int v1, MyLNode* n)
{
  elem = v1;
  next = n;
}

MyLNode::MyLNode (string v2, MyLNode* n)
{
  elem1 = v2;
  next = n;
}

int MyLNode::getElem ()
{
  return elem;
}

string MyLNode::getElem1 ()
{
  return elem1;
}

void MyLNode::setNext (MyLNode* n)
{
  next = n;
}

MyLNode* MyLNode::getNext()
{
  return next;
}


intList::intList()
{
  Head = NULL;
}

intList::~intList()
{
  MyLNode* curr = Head;
  MyLNode* prev;
  while (curr != NULL)
  {
    prev = curr;
    curr = curr->getNext();
    delete prev;
  }
    Head = NULL;
}


void intList::insertValue (int v1)
{
   MyLNode* tmp = new MyLNode (v1);

    
   MyLNode* curr = Head;
   MyLNode* prev = NULL;

   while(curr != NULL)
   {
     prev = curr;
     curr = curr->getNext();
   }

   if(prev == NULL)
   {
       Head = tmp;
   }
  else
  {
      prev->setNext(tmp);
  }
}

void intList::deleteValue (int v1)
{
  MyLNode* curr = Head;
  MyLNode* prev = NULL;
  
  while ( ( curr != NULL ) && ( curr->getElem() != v1 ) )
  {
    prev = curr;
    curr = curr->getNext();
  }

  if ( curr == NULL ) // v1 does not exist in list
    return;

  if ( prev == NULL ) // v1 is in first/head node in list
  {
    Head = curr->getNext();
    delete curr;
  }
  else
  {
    prev->setNext( curr->getNext() );
    delete curr;
  }
}

void intList::makeCopy (const intList &p)
{
    Head = NULL;
    copyNode (p.Head);
}

int intList::getListLength()
{
    int length = 0;
    MyLNode* curr = Head;
    
    while (curr != NULL)
    {
        length++;
        curr = curr->getNext();
    }

    return length;
}

int intList:: getNthValue(int n)
{
    MyLNode* curr = Head;
    
    for (int i = 0; i < n; i++)
    {
        curr = curr->getNext();
    }
    
      return curr->getElem();
    
}

bool intList:: checkNode(int val)
{
    if(Head == NULL)
        return FALSE;
    
    MyLNode* curr = Head;
    
    while(curr != NULL)
    {
        if(curr->getElem() == val)
            return TRUE;
        
        curr = curr->getNext();
    }
    
    return FALSE;
}

int intList:: isEmpty()
{
    if(Head == NULL)
        return TRUE;
    else
        return FALSE;
}

void intList:: clear()
{
    while(!isEmpty())
    {
        MyLNode* tmp = Head;
        
        Head = Head->getNext();
        delete tmp;
    }
}


MyLNode* intList::getHd()
{
  return Head;
}

void intList::setHd(MyLNode* tmp)
{
  Head = tmp;
}


strList::strList()
{
  Head = NULL;
}

strList::~strList()
{
  MyLNode* curr = Head;
  MyLNode* prev;
  while (curr != NULL)
  {
    prev = curr;
    curr = curr->getNext();
    delete prev;
  }
    Head = NULL;
}


void strList::insertValue (string v1)
{
   MyLNode* tmp = new MyLNode (v1);

    
   MyLNode* curr = Head;
   MyLNode* prev = NULL;

   while(curr != NULL)
   {
     prev = curr;
     curr = curr->getNext();
   }

   if(prev == NULL)
   {
       Head = tmp;
   }
  else
  {
      prev->setNext(tmp);
  }
}

void strList::deleteValue (string v1)
{
  MyLNode* curr = Head;
  MyLNode* prev = NULL;
  
  while ( ( curr != NULL ) && ( curr->getElem1() != v1 ) )
  {
    prev = curr;
    curr = curr->getNext();
  }

  if ( curr == NULL ) // v1 does not exist in list
    return;

  if ( prev == NULL ) // v1 is in first/head node in list
  {
    Head = curr->getNext();
    delete curr;
  }
  else
  {
    prev->setNext( curr->getNext() );
    delete curr;
  }
}

int strList::getListLength()
{
    int length = 0;
    MyLNode* curr = Head;
    
    while (curr != NULL)
    {
        length++;
        curr = curr->getNext();
    }

    return length;
}

bool strList:: checkNode(string val)
{
    if(Head == NULL)
        return FALSE;
    
    MyLNode* curr = Head;
    
    while(curr != NULL)
    {
        if(curr->getElem1() == val)
            return TRUE;
        
        curr = curr->getNext();
    }
    
    return FALSE;
}

string strList:: getNthValue(int n)
{
    MyLNode* curr = Head;
    
    for (int i = 0; i < n; i++)
    {
        curr = curr->getNext();
    }
    
      return curr->getElem1();
    
}

