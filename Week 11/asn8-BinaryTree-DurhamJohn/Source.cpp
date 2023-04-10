/*
You are asked to complete Programming Problem 5 on page 512 of your textbook.
This program is meant to apply what you have learned in this topic.
Write a program that maintains a database containing data, Name and Birthday of your friends and relatives.
You will be able to enter, remove, modify or search this data.  Initially, you can assume that the
names are unique.  The program will be able to save and load the data in a file for use later.
Also, you will need to implement the following functions:
Enter -- Add a new person to you list.
Modify -- Change the name or birthday of a person.
Remove -- Remove a person from your list.
Search -- Display the information about a given person (unique name).
Query -- Run a query that displays the people by asking the user to enter a month.
Print -- List everyone in the database.
Problem 5 on page 512 says, “Use a binary search tree of people as a data member of the database class.”
The header file for a linked-based implementation of the class BinarySearchTree is displayed in
Listing 16-4 on page 502.

@author John Durham
@date   03/29/2023
@version     0.0.1
@file   Source.cpp
*/

#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include "BinaryNode.h"
#include "BinaryNodeTree.h"
#include "BinarySearchTree.h"
#include "Person.h"

using namespace std;

// Function prototypes
BinaryNodeTree<Person> readTree(BinaryNodeTree<Person>& treePtr, int n);
void displayMenu();
void enterNewPerson(BinaryNodeTree<Person>& database);
void modifyPerson(BinaryNodeTree<Person>& database);
void removePerson(BinaryNodeTree<Person>& database);
void processPerson(Person& foundPerson);
void processNode(Person& person, const string& searchName, bool& found);
void searchDatabase(const BinaryNodeTree<Person>& database);
void queryByMonth(BinaryNodeTree<Person>& database);
void printDatabase(BinaryNodeTree<Person>& database);
void processPersonToFile(ofstream& outputFile, Person& foundPerson);
static void saveToFile(Person& person, std::ofstream& outputFile);
void saveToFile(BinaryNodeTree<Person>& database, const string& filename);
void loadFromFile(BinaryNodeTree<Person>& database, const string& filename);



int main() {
    //std::shared_ptr<BinaryNodeTree<Person>> database;
    //database = std::make_shared<BinarySearchTree<Person>>();
    BinaryNodeTree<Person> database;

    bool quit = false;
    while (!quit) {
        displayMenu();
        char choice;
        cin >> choice;
        switch (choice) {
        case '1':
            enterNewPerson(database);
            break;
        case '2':
            modifyPerson(database);
            break;
        case '3':
            removePerson(database);
            break;
        case '4':
            searchDatabase(database);
            break;
        case '5':
            queryByMonth(database);
            break;
        case '6':
            printDatabase(database);
            break;
        case '7': {
            std::cout << "Enter a filename to save the database to: ";
            string filename;
            cin >> filename;
            saveToFile(database, filename);
            break;
        }
        case '8': {
            std::cout << "Enter a filename to load the database from: ";
            string filename;
            cin >> filename;
            loadFromFile(database, filename);
            break;
        }
        case '9':
            quit = true;
            break;
        default:
            std::cout << "Invalid choice. Please enter a number from 1-9.\n";
        }
    }

    return 0;
}


BinaryNodeTree<Person> readTree(BinaryNodeTree<Person>& treePtr, int n)
{
    if (n > 0)
    {
        BinaryNode<Person> newPtr;
        treePtr.setRootData(newPtr);
    }
}


void displayMenu() {
    std::cout << "Please choose an option:\n"
        << "1. Enter new person\n"
        << "2. Modify person\n"
        << "3. Remove person\n"
        << "4. Search database\n"
        << "5. Query by month\n"
        << "6. Print database\n"
        << "7. Save to file\n"
        << "8. Load from file\n"
        << "9. Quit\n";
}


void enterNewPerson(BinaryNodeTree<Person>& database) {
    std::string name;
    std::string birthdate;

    std::cout << "Enter name: ";
    std::getline(std::cin, name);

    std::cout << "Enter birthdate (mm/dd/yyyy): ";
    std::getline(std::cin, birthdate);

    Person* newPerson = new Person(name, birthdate);

    database.add(*newPerson);

    delete newPerson;
    newPerson = nullptr;
}


// Function to modify a person's information in the database
void modifyPerson(BinaryNodeTree<Person>& database) {

    std::string name;
    std::cout << "enter the name of the person to modify: ";
    std::getline(std::cin, name);

    Person* person = new Person(database.getEntry(*person));
    if (person == nullptr) {
        std::cerr << "Error: Person with name " << name << " does not exist in the database." << std::endl;
        return;
    }

    std::string birthdate;
    std::cout << "Enter new birthdate for " << name << ": ";
    std::getline(std::cin, birthdate);

    person->setBirthdate(birthdate);

    std::cout << "Person with name " << name << " successfully modified." << std::endl;
}


// Function to remove a person from the database
void removePerson(BinaryNodeTree<Person>& database) {
    std::string name;

    std::cout << "Enter name to remove: ";
    std::getline(std::cin, name);

    Person* targetPerson = nullptr;
    targetPerson->setName(name);

    bool isSuccessful = false;
    database.remove(*targetPerson);

    if (!isSuccessful) {
        std::cout << "Error: Person not found in database." << std::endl;
    }

    delete targetPerson;
    targetPerson = nullptr;
}


void processPerson(Person& foundPerson) {
    cout << "Name: " << foundPerson.getName() << endl;
    cout << "Birthdate: " << foundPerson.getBirthdate() << endl;
}


void processNode(Person& person, const string& searchName, bool& found) {
    if (person.getName() == searchName) {
        cout << "Person found: " << person.getName() << endl;
        found = true;
    }
}


void searchDatabase(const BinaryNodeTree<Person>& database) {
    string searchName;
    cout << "Enter the name of the person to search: ";
    cin >> searchName;

    bool found = false;
    auto callback = [searchName, &found](Person& item) -> void {
        processNode(item, searchName, found);
    };
    database.inorderTraversal(callback);

    if (!found) {
        cout << "Person with name " << searchName << " not found in the database." << endl;
    }
}


void queryByMonth(BinaryNodeTree<Person>& database) {
    string month;
    cout << "Enter the month (MM): ";
    cin >> month;

    auto callback = [&month](Person& foundPerson) -> void {
        if (foundPerson.getBirthdate() == month) {
            cout << "Name: " << foundPerson.getName() << endl;
            cout << "Birthdate: " << foundPerson.getBirthdate() << endl;
        }
    };

    database.inorderTraversal(callback);
}

void printDatabase(BinaryNodeTree<Person>& database) {
    auto printPerson = [&](Person& person) {
        cout << "Name: " << person.getName() << endl;
        cout << "Birthdate: " << person.getBirthdate() << endl << endl;
    };

    cout << "Current database:" << endl;
    //database.inorderTraversal(&processNode);
    database.inorderTraversal(processNode(this->getName(), person, true));
}



void processPersonToFile(ofstream& outputFile, Person& foundPerson) {
    outputFile << foundPerson.getName() << "," << foundPerson.getBirthdate() << endl;
}



void saveToFile(BinaryNodeTree<Person>& database, const std::string& filename) {
    std::ofstream outputFile(filename);
    if (!outputFile) {
        std::cout << "Failed to open file for writing: " << filename << std::endl;
        return;
    }

    auto callback = [&](Person& foundPerson) -> void {
        saveToFile(foundPerson, outputFile);
    };

    database.inorderTraversal(callback);
    outputFile.close();
}


void loadFromFile(BinaryNodeTree<Person>& database, const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cout << "Failed to open file for reading: " << filename << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string name, birthdate;
        if (getline(iss, name, ',') && getline(iss, birthdate)) {
            Person newPerson(name, birthdate);
            database.add(newPerson);
        }
        else {
            cout << "Failed to parse line: " << line << endl;
        }
    }

    inputFile.close();
}