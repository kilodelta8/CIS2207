#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person {
private:
    std::string name;
    std::string birthdate; //xxxxxx - mmddyy

public:
    Person(std::string n);
    Person(std::string n, std::string b);

    static void saveToFile(Person& person, std::ofstream& outputFile);

    // Define the < operator as a non-member function
    friend bool operator<(const Person& lhs, const Person& rhs) {
        return lhs.name < rhs.name;
    }

    bool operator==(const Person& other) const {
        return name == other.name && birthdate == other.birthdate;
    }

    void setName(std::string n)
    {
        name = n;
    }
    std::string getName()
    {
        return name;
    }
    void setBirthdate(std::string b)
    {
        birthdate = b;
    }
    std::string getBirthdate()
    {
        return birthdate;
    }
};

Person::Person(std::string n) : name(n) {}
Person::Person(std::string n, std::string b) : name(n), birthdate(b) {}
void Person::saveToFile(Person& person, std::ofstream& outputFile) {
    outputFile << person.getName() << "," << person.getBirthdate() << std::endl;
}

#endif