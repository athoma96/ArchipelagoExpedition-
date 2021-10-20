//
// Author: Allen Thomas
// UIC Spring 2021
// Prof. Mobasheri
//
// Project 6: For this program, you will write a C++ Program to represent an archipelagoexpedition.
//This expedition will use an array of linked lists as its primary storage structure.
//
// Island.h file

class islandQueue : public intList {
  public:
    islandQueue();
    void enQueue(int v1);
    void deQueue();
    int peek();
};

class Stack : public intList {
  public:
    Stack();
    void pushList(int v1);
    void popList();
    int top();
};

class Island {
  private:
    intList islandList;
    bool visit;
    int prevLocation;
  public:
    Island ();
    void addEdge (int v1);
    void deleteEdge (int v1);
    bool checkEdges (int v1);
    void printIsland (int islandNum);
    void Unvisited ();
    void Visited ();
    int numEdges ();
    void islandClear();
    int getIsland (int v1);
    void setPreviousLoc(int v1);
    int getPreviousLoc();
};

