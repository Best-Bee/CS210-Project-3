#pragma once
#include <map>
#include <string>

class ItemTracker {
private:
    //make da map (private to prevent those fools from tamperring with it)
    std::map<std::string, int> frequencyMap;

public:
    //function declarations (public to allow those fools to use em)
    ItemTracker();
    void readDataFromFile(const std::string& filename);
    void displayMenu();
    void searchItem();
    void printAllItemsFrequency();
    void printHistogram();
};