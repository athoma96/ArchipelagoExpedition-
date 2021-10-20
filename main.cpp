//
// Author: Allen Thomas
// UIC Spring 2021
// Prof. Mobasheri
//
// Project 6: For this program, you will write a C++ Program to represent an archipelagoexpedition.
//This expedition will use an array of linked lists as its primary storage structure.
//
// main.cpp file

#include "Header.h"
#include "Island.h"
#include "Archipelago.h"


int main (int argc, char** argv)
{
  // set up the varqiable inFile to read from standard input
  FILE* inFile = stdin;

  // set up the data needed for the island adjcency list
  ArchipelagoExpedition islandData;
   
  // call the method that reads and parses the input
  islandData.showCommands();
  printf ("\nEnter commands at blank line\n");
  printf ("    (No prompts are given because of f command)\n");
  islandData.processCommandLoop (inFile);
   
  printf ("Goodbye\n");
  return 0;
 }
