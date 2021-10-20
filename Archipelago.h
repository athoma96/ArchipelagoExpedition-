//
// Author: Allen Thomas
// UIC Spring 2021
// Prof. Mobasheri
//
// Project 6: For this program, you will write a C++ Program to represent an archipelagoexpedition.
//This expedition will use an array of linked lists as its primary storage structure.
//
// Archipelago.h file


class ArchipelagoExpedition
{
 private:
   // Create the Data Members for the Archipelago Network here
    Island* darr;
    int islandSize;
    strList fileLL;
    
    Stack breadthFirstSearch (int x, int y)
    {
        Stack pathList;
        islandQueue IQ;
        int currentIsland;
        
        for(int i = 0; i < islandSize + 1; i++)
        {
            darr[i].setPreviousLoc(-1);  //mark all islandsas unvisited
        }
       
        IQ.clear();   // set the list IslandQueue to be empty
        IQ.enQueue(x);  //add x to the end of the IslandQueue
        
        if (bfs(y, IQ) == FALSE)
        {
            printf("You can NOT get from island %d to island %d\n", x, y);
            pathList.clear();
            return pathList;
        }
        else
        {
            printf("You can get from island %d to island %d\n", x, y);
            pathList.clear();
            currentIsland = y;
            pathList.pushList(currentIsland);
            do
            {
                currentIsland = darr[currentIsland].getPreviousLoc();
                pathList.pushList(currentIsland);
            }
            while(currentIsland != x);
            IQ.clear();
            return pathList;
        }
    }
    
    bool bfs(int b, islandQueue& IQ)
    {
        int a,c;
        while(!IQ.isEmpty())
        {
            a = IQ.peek();
            IQ.deQueue();
            
            for(int i = 0; i < darr[a].numEdges(); i++)
            {
                c = darr[a].getIsland(i);
                
                if(darr[c].getPreviousLoc() == -1)
                {
                    darr[c].setPreviousLoc(a);
                    
                    if(c == b)
                        return TRUE;
                    
                    IQ.enQueue(c);
                }
            }
        }
        
        return FALSE;
    }
  
 public:
    
    ArchipelagoExpedition();
    ~ArchipelagoExpedition();
    void processCommandLoop (FILE* inFile);
    void showCommands();
    void doTravel();
    void doResize();
    void doInsert();
    void doDelete();
    void doList();
    void doFile();
    void doClear ();
  
 };
