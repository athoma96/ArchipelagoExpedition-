//
// Author: Allen Thomas
// UIC Spring 2021
// Prof. Mobasheri
//
// Project 6: For this program, you will write a C++ Program to represent an archipelagoexpedition.
//This expedition will use an array of linked lists as its primary storage structure.
//
// Archipelago.cpp file


#include "Header.h"
#include "Island.h"
#include "Archipelago.h"

// Use a constructor to initialize the Data Members for your expedition
ArchipelagoExpedition::ArchipelagoExpedition()
{
    islandSize = 10;
    darr = new Island[islandSize + 1];
}

ArchipelagoExpedition::~ArchipelagoExpedition()
{
    delete[] darr;
    islandSize = 0;
    
}

 
 
// The main loop for reading in input
void ArchipelagoExpedition::processCommandLoop (FILE* inFile)
{
 char  buffer[300];
 char* input;

 input = fgets ( buffer, 300, inFile );   // get a line of input
   
 // loop until all lines are read from the input
 while (input != NULL)
 {
   // process each line of input using the strtok functions
   char* command;
   command = strtok (input , " \n\t");

   printf ("*%s*\n", command);
   
   if ( command == NULL )
     printf ("Blank Line\n");

   else if ( strcmp (command, "q") == 0)
   {
       this->~ArchipelagoExpedition();
       exit(1);
   }
     
    
   else if ( strcmp (command, "?") == 0)
     showCommands();
    
   else if ( strcmp (command, "t") == 0)
     doTravel();
    
   else if ( strcmp (command, "r") == 0)
     doResize();

   else if ( strcmp (command, "i") == 0)
     doInsert();

   else if ( strcmp (command, "d") == 0)
     doDelete();

   else if ( strcmp (command, "l") == 0)
     doList();

   else if ( strcmp (command, "f") == 0)
     doFile();

   else if ( strcmp (command, "#") == 0)
     ;
    
   else
     printf ("Command is not known: %s\n", command);
    
   input = fgets ( buffer, 300, inFile );   // get the next line of input

 }
}

void ArchipelagoExpedition::showCommands()
{
  printf ("The commands for this project are:\n");
  printf ("  q \n");
  printf ("  ? \n");
  printf ("  # \n");
  printf ("  t <int1> <int2> \n");
  printf ("  r <int> \n");
  printf ("  i <int1> <int2> \n");
  printf ("  d <int1> <int2> \n");
  printf ("  l \n");
  printf ("  f <filename> \n");
}

//display shortest path from island<int1>to island<int2>in one or more ferry rides.
void ArchipelagoExpedition::doTravel()
{
  int val1 = 0;
  int val2 = 0;

  // get an integer value from the input
  char* next = strtok (NULL, " \n\t");
 
  if ( next == NULL )
  {
    printf ("Integer value expected\n");
    return;
  }
  val1 = atoi ( next );
  if ( val1 == 0 && strcmp (next, "0") != 0)
  {
    printf ("Integer value expected\n");
    return;
  }
  
  // get another integer value from the input
  next = strtok (NULL, " \n\t");

 
  if ( next == NULL )
  {
    printf ("Integer value expected\n");
    return;
  }
  val2 = atoi ( next );
  if ( val2 == 0 && strcmp (next, "0") != 0)
  {
    printf ("Integer value expected\n");
    return;
  }
  
  if (val1 <= islandSize && val2 <= islandSize)
  {
      printf ("Performing the Travel Command from %d to %d\n",val1, val2);
      Stack I = breadthFirstSearch(val1, val2);  // calls the breadthfirstsearch function
      
      //If the list returned by breathFirstSearch ( ) is not empty
      if (!I.isEmpty())
      {
          //it needs to print out the path (from start to finish) contained in that list
          MyLNode* path = I.getHd();
          printf("shortest path from %d to %d: %d", val1, val2, path->getElem());
          path = path->getNext();
          while (path != NULL)
          {
              printf(" - %d", path->getElem());
              path = path->getNext();
          }
         
          printf("\n");
       }
  }
  else
  {
      printf("Invalid value for island\n");
  }
    
}

//emove all values from the archipelagoexpeditionand resize the array to contain the number of
//islands as indicated by the given integer value.  The value of the integer must be greater than
//zero.  The islandswill be numbered from 1 to the given integer value.Be sure to deallocate all
//unused memory as part of this command.

void ArchipelagoExpedition::doResize()
{
   int val1 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \n\t");
   
   if ( next == NULL )
   {
       printf ("Integer value expected\n");
       return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
      printf ("Integer value expected\n");
      return;
   }
  
  printf ("Performing the Resize Command with %d\n", val1 );
  
  for(int i = 0; i < islandSize; i++)
  {
      darr[i].islandClear();
  }
 
  delete[] darr;
  islandSize = val1;
  darr = new Island[islandSize + 1];
  

}

//insert the edge to indicate a ferry ride from island <int1>to island <int2>.
void ArchipelagoExpedition::doInsert()
{
    int val1 = 0;
    int val2 = 0;

    // get an integer value from the input
    char* next = strtok (NULL, " \n\t");
   
    if ( next == NULL )
    {
      printf ("Integer value expected\n");
      return;
    }
    val1 = atoi ( next );
    if ( val1 == 0 && strcmp (next, "0") != 0)
    {
      printf ("Integer value expected\n");
      return;
    }
    
    // get another integer value from the input
    next = strtok (NULL, " \n\t");

   
    if ( next == NULL )
    {
      printf ("Integer value expected\n");
      return;
    }
    val2 = atoi ( next );
    if ( val2 == 0 && strcmp (next, "0") != 0)
    {
      printf ("Integer value expected\n");
      return;
    }
    
    if(val1 == val2)
    {
        printf("Can not add ferry ride to self \n");
        return;
    }
    if (val1 <= islandSize && val2 <= islandSize)
    {
        if(darr[val1].checkEdges(val2))
        {
            printf ("Performing the Insert Command for %d\n", val1);
            printf("Ferry ride already added!\n");
            return;
        }
        else
        {
            printf ("Performing the Insert Command for %d\n", val1);
            darr[val1].addEdge(val2);
        }
            
    }
    else
    {
        printf ("Invalid value for island\n");
    }
    
    
}

//delete the edge that indicates a ferry ride from island<int1>to island <int2>.
void ArchipelagoExpedition::doDelete()
{
    int val1 = 0;
    int val2 = 0;

    // get an integer value from the input
    char* next = strtok (NULL, " \n\t");
   
    if ( next == NULL )
    {
      printf ("Integer value expected\n");
      return;
    }
    val1 = atoi ( next );
    if ( val1 == 0 && strcmp (next, "0") != 0)
    {
      printf ("Integer value expected\n");
      return;
    }
    
    // get another integer value from the input
    next = strtok (NULL, " \n\t");

   
    if ( next == NULL )
    {
      printf ("Integer value expected\n");
      return;
    }
    val2 = atoi ( next );
    if ( val2 == 0 && strcmp (next, "0") != 0)
    {
      printf ("Integer value expected\n");
      return;
    }
    
    if (val1 <= islandSize && val2 <= islandSize)
    {
        if(darr[val1].checkEdges(val2))
        {
            printf ("Performing the Delete Command for %d\n", val1);
            darr[val1].deleteEdge(val2);
        }
        else
        {
            printf ("Performing the Delete Command for %d\n", val1);
            printf("Ride is not in the list!\n");
            return;
        }
    }
    else
    {
        printf ("Invalid value for island\n");
    }
    
    
}

//ist all the items contained in the archipelagoexpedition. First display all of the islands (if
//any) that can be reached from the island #1 with one ferry ride (that have an edge in the
//archipelago), followed by all the islands (if any) that can bereached from island #2 with one
//ferry ride, etc.
void ArchipelagoExpedition::doList()
{
   int i = 1;
   printf ("Displaying the adjacency list:\n" );
    
   while(i < islandSize + 1)
   {
       darr[i].printIsland(i);
       printf("\n");
       i++;
   }
    
}

void ArchipelagoExpedition::doFile()
{
  // get a filename from the input
  char* fname = strtok (NULL, " \r\n\t");
  if ( fname == NULL )
  {
    printf ("Filename expected\n");
    return;
  }
  
  printf ("Performing the File command with file: %s\n", fname);
  
  // next steps:  (if any step fails: print an error message and return )
  //  1. verify the file name is not currently in use
  //  2. open the file using fopen creating a new instance of FILE*
  //  3. recursively call processCommandLoop() with this new instance of FILE* as the parameter
  //  4. close the file when processCommandLoop() returns
  
  if (fileLL.checkNode(fname) == FALSE)
  {
      fileLL.insertValue(fname);
      FILE *file;
      
      if ((file = fopen(fname, "r")) == NULL)
      {
          printf("Cannot open the file\n");
          return;
      }
      
      processCommandLoop(file);
      fclose(file);
  }
  else
  {
      printf("File is already in use\n");
  }
    fileLL.deleteValue(fname);

}



