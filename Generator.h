#pragma once
#include "LinkedListSequence.h"
#include "Person.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <random>

int GenerateRandomInt(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

float GenerateRandomFloat(float min, float max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(min, max);
    return dist(gen);
}

void GenerateIntFile(const std::string& filename, int count, int minValue, int maxValue)
{
    std::ofstream file(filename);

    for (int i = 0; i < count; ++i)
    {
        int value = GenerateRandomInt(minValue, maxValue);
        file << value << (i == count - 1 ? "" : ",");
    }

    file.close();
}

LinkedListSequence<int> LoadIntFile(const std::string& filename)
{
    std::ifstream file(filename);

    LinkedListSequence<int> numbers;
    std::string line;

    if (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string numberStr;

        while (std::getline(ss, numberStr, ','))
        {
            int number = std::stoi(numberStr);
            numbers.Append(number);
        }
    }
    file.close();
    return numbers;
}

void WritePersonToFile(std::ofstream& file, std::string& firstName, std::string& lastName)
{
    int yearOfBirth = GenerateRandomInt(1950, 2020);
    float height = GenerateRandomFloat(150.0f, 200.0f);
    float weight = GenerateRandomFloat(50.0f, 100.0f);
    file << firstName << "," << lastName << "," << yearOfBirth << ","
        << std::fixed << std::setprecision(1) << height << ","
        << std::fixed << std::setprecision(1) << weight << "\n";
}

void GeneratePersonFile(const std::string& filename, int maleCount, int femaleCount)
{
    std::vector<std::string> maleFirstNames = { "Ivan", "Alexey", "Sergey", "Dmitry", "Vladimir", "Andrey", "Maxim", "Nikolay" };
    std::vector<std::string> femaleFirstNames = { "Maria", "Olga", "Elena", "Anna", "Natalia", "Irina", "Tatiana", "Ekaterina" };

    std::vector<std::string> maleLastNames = { "Ivanov", "Petrov", "Sidorov", "Kuznetsov", "Popov", "Smirnov", "Fedorov", "Morozov" };
    std::vector<std::string> femaleLastNames = { "Ivanova", "Petrova", "Sidorova", "Kuznetsova", "Popova", "Smirnova", "Fedorova", "Morozova" };

    std::ofstream file(filename);

    for (int i = 0; i < maleCount; ++i)
    {
        std::string firstName = maleFirstNames[GenerateRandomInt(0, maleFirstNames.size() - 1)];
        std::string lastName = maleLastNames[GenerateRandomInt(0, maleLastNames.size() - 1)];
        WritePersonToFile(file, firstName, lastName);
    }

    for (int i = 0; i < femaleCount; ++i)
    {
        std::string firstName = femaleFirstNames[GenerateRandomInt(0, femaleFirstNames.size() - 1)];
        std::string lastName = femaleLastNames[GenerateRandomInt(0, femaleLastNames.size() - 1)];
        WritePersonToFile(file, firstName, lastName);
    }

    file.close();
}

LinkedListSequence<Person> LoadPersonsFromFile(const std::string& filename)
{
    std::ifstream file(filename);

    LinkedListSequence<Person> persons;
    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string firstName, lastName, yearOfBirthStr, heightStr, weightStr;

        std::getline(ss, firstName, ',');
        std::getline(ss, lastName, ',');
        std::getline(ss, yearOfBirthStr, ',');
        std::getline(ss, heightStr, ',');
        std::getline(ss, weightStr, ',');

        int yearOfBirth = std::stoi(yearOfBirthStr);
        float height = std::stof(heightStr);
        float weight = std::stof(weightStr);

        persons.Append({ yearOfBirth, firstName, lastName, height, weight });
    }

    file.close();
    return persons;
}