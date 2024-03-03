#include "ItemTracker.h"
#include <iostream>
#include <iomanip>
#include <fstream>

// Constructor, immediately read data from file.
ItemTracker::ItemTracker() {
    readDataFromFile("CS210_Project_Three_Input_File.txt");
}

// Read file input data, tell user that the data is both being read and that it has read
// successfully. 
void ItemTracker::readDataFromFile(const std::string& filename) {
    //tell user that it is being read properly
    std::cout << "Reading data from file: " << filename << std::endl;
    std::ifstream file(filename);
    if (file.is_open()) {
        //grab an "item" (an input from the file)
        std::string item;
        while (file >> item) {
            //add the item to the frequency map
            frequencyMap[item]++;
        }
        //close the file
        file.close();
        //tell user it was read properly
        std::cout << "Data read successfully." << std::endl;
    } else {
        //tell user that it couldn't open the file, probably because it was placed 
        //in the wrong directory or named wrong or something like that
        std::cout << "Unable to open file: " << filename << std::endl;
    }
}

// Displays a menu for the user to then input their choice as a numerical value in the range [1, 4].
// Go to different functions according to user input via a switch case, return an invalid input text
// if user inputted a value not in the integer range of [1, 4].
void ItemTracker::displayMenu() {
    //init var for user choice
    int choice;
    //do while user choice isn't 4 (4 is exit)
    do {
        //menu
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Search for an item" << std::endl;
        std::cout << "2. Print frequency of all items" << std::endl;
        std::cout << "3. Print histogram of item frequencies" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        //get user input
        std::cin >> choice;

        //switch case to handle user input
        switch (choice) {
        case 1:
            searchItem();
            break;
        case 2:
            printAllItemsFrequency();
            break;
        case 3:
            printHistogram();
            break;
        case 4:
            std::cout << "Exiting program..." << std::endl;
            break;
        default:
            //invalid input
            std::cout << "Invalid choice. Please enter a number between 1 and 4." << std::endl;
        }
    } while (choice != 4);
}

// Function to allow the user to search for items that have been inputted based on the input file
// Items must follow capitalization from the file. (Apple and apple are different items).
void ItemTracker::searchItem() {
    //formatting (new lines look nice)
    std::cout << std::endl;
    //init var and get the item the user wants to look for
    std::string item;
    std::cout << "Enter the item to search for: ";
    std::cin >> item;
    //find the item in the map
    if (frequencyMap.find(item) != frequencyMap.end()) {
        //tell user how many
        std::cout << "Frequency of " << item << ": " << frequencyMap[item] << std::endl;
    } else {
        //tell user that item ain't there
        std::cout << "Item not found." << std::endl;
    }
    //formatting
    std::cout << std::endl;
}

// Go through the entire map of items, displaying their counts as it goes.
void ItemTracker::printAllItemsFrequency() {
    //formatting
    std::cout << std::endl;
    //tell the user the frequency of all items
    std::cout << "Frequency of all items:" << std::endl;
    //go through all items in map
    for (const auto& pair : frequencyMap) {
        //name and number
        std::cout << pair.first << " " << pair.second << std::endl;
    }
    //formatting
    std::cout << std::endl;
}

// Go through the entire map, displaying an asterisk for each count of that item (5 apples is *****).
void ItemTracker::printHistogram() {
    //formatting
    std::cout << std::endl;
    std::cout << "Histogram of item frequencies:" << std::endl;
    //go through map
    for (const auto& pair : frequencyMap) {
        //formatting and first display (item name)
        std::cout << std::left << std::setw(15) << pair.first;
        //go for the number of the count of said item
        for (int i = 0; i < pair.second; ++i) {
            //do a *
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}