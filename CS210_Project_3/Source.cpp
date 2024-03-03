//*******************************************************
//
//  Author: Bee Best
//  Date: 2/25/2024
//  Program: ItemTracker
//
//  Purpose: Count the number of items in a given input
//           file, display said counts in three different
//           methods, count of a single inputted thing,
//           count of all from input file, or histogram
//           of all from input file.
//
//*******************************************************

#include "ItemTracker.h"

//that certainly is a main() alright, but seriously, it just makes the tracker 
//and displays the menu of options until they do 4 to exit.
int main() {
    ItemTracker tracker;
    tracker.displayMenu();
    return 0;
}