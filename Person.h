#pragma once
#include <string>
#include <functional>

class Person
{
private:
    int yearOfBirth;
    std::string firstName;
    std::string lastName;
    float height;
    float weight;

public:

    Person() : yearOfBirth(0), firstName(""), lastName(""), height(0), weight(0) {}

    Person(int n) : yearOfBirth(n), firstName(""), lastName(""), height(0), weight(0) {}

    Person(int yearOfBirth, const std::string& firstName, const std::string& lastName, float height, float weight)
        : yearOfBirth(yearOfBirth), firstName(firstName), lastName(lastName), height(height), weight(weight) {}

    Person(const Person& other)
        : yearOfBirth(other.yearOfBirth), firstName(other.firstName), lastName(other.lastName), height(other.height), weight(other.weight) {}

    int GetYearOfBirth() const { return this->yearOfBirth; }

    std::string GetFirstname() const { return this->firstName; }

    std::string GetLastname() const { return this->lastName; }

    std::string GetFullName() const { return this->firstName + " " + this->lastName; }

    int GetWeight() const { return this->weight; }

    int GetHeight() const { return this->height; }

    struct YearOfBirthComparator
    {
        bool operator()(const Person& a, const Person& b) const
        {
            return a.yearOfBirth < b.yearOfBirth;
        }
    };

    struct LastnameComparator
    {
        bool operator()(const Person& a, const Person& b) const
        {
            return a.lastName < b.lastName;
        }
    };

    struct WeightComporator
    {
        bool operator()(const Person& a, const Person& b) const
        {
            return a.weight < b.weight;
        }
    };

    struct HeightComporator
    {
        bool operator()(const Person& a, const Person& b) const
        {
            return a.height < b.height;
        }
    };

    /*friend std::ostream& operator<<(std::ostream& os, const Person& person)
    {
        os << person.yearOfBirth << " " << person.GetFullName() << " " << person.weight << " " << person.height << std::endl;
        return os;
    }*/

    /*friend std::istream& operator>>(std::istream& is, Person& person)
    {
        std::cout << "Enter person year of birth: ";
        while (!(is >> person.yearOfBirth))
        {
            std::cout << "Incorrect input for year of birth. Please enter an integer: ";
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Enter firstName: ";
        is >> person.firstName;

        std::cout << "Enter lastName: ";
        is >> person.lastName;

        std::cout << "Enter person weight: ";
        while (!(is >> person.weight))
        {
            std::cout << "Incorrect input for weight. Please enter float nunber: ";
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Enter person height: ";
        while (!(is >> person.height))
        {
            std::cout << "Incorrect input for height. Please enter float nunber: ";
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        return is;
    }*/

};
