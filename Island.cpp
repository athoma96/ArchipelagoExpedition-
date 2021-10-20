//
// Author: Allen Thomas
// UIC Spring 2021
// Prof. Mobasheri
//
// Project 6: For this program, you will write a C++ Program to represent an archipelagoexpedition.
//This expedition will use an array of linked lists as its primary storage structure.
//
// Island.cpp file

#include "Header.h"
#include "Island.h"
#include "Archipelago.h"

islandQueue::islandQueue()
{
  setHd(NULL);
}

void islandQueue::enQueue(int v1)
{
  insertValue(v1);
}

void islandQueue::deQueue()
{
  if(getHd() != NULL)
  {
    MyLNode* tmp = getHd();
    setHd(getHd()->getNext());
    delete tmp;
  }
}

int islandQueue::peek()
{
  if(!isEmpty())
  {
    return getHd()->getElem();
  }
  return -1;
}



Stack::Stack()
{
  setHd(NULL);
}

void Stack::pushList(int v1)
{
  MyLNode* tmp = new MyLNode(v1);
  if (getHd() == NULL)
      setHd(tmp);
  else
  {
    tmp->setNext(getHd());
    setHd(tmp);
  }
}

void Stack::popList()
{
  if (!isEmpty())
  {
    MyLNode* tmp = getHd();
    setHd(getHd()->getNext());
    delete tmp;
  }
}

int Stack::top()
{
  if (!isEmpty())
    return (getHd()->getElem());
  
  return -1;
}



Island::Island ()
{
    visit = FALSE;
}

void Island::addEdge(int v1)  //  inserts an edge between the islands
{
    islandList.insertValue(v1);
}

void Island::deleteEdge(int v1)  // deletes an edge between the islands
{
    islandList.deleteValue(v1);
}

bool Island::checkEdges(int v1)  // checks if there is an edge between islands
{
    return islandList.checkNode(v1);
}

void Island::printIsland(int islandNum) //prints the island list
{
    printf("%d --> ", islandNum);
    int k = 0;
    
    while(k  < islandList.getListLength())
    {
        printf(" %d ", islandList.getNthValue(k));
        k++;
    }
}

void Island::Unvisited () //marks the island unvisited
{
  visit = false;
}


void Island::Visited () //marks the island visited
{
  visit = true;
}

void Island::islandClear ()
{
    return islandList.clear();
}

int Island::numEdges ()   // checks the number of edges between the islands
{
  return islandList.getListLength();
}

int Island::getIsland (int v1) {
  return islandList.getNthValue(v1);
}

void Island::setPreviousLoc (int v1)
{
  prevLocation = v1;
}

int Island::getPreviousLoc ()
{
  return prevLocation;
}

