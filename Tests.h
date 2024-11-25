#pragma once
#include "InsertionSort.h"
#include "BinaryInsertionSort.h"
#include "LinkedListSequence.h"
#include "BubbleSort.h"
#include "Person.h"
#include "Generator.h"
#include <cassert>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>

void TestBubbleSortInt()
{
    GenerateIntFile("int.txt", 10, 0, 100);
    ShrdPtr<Sequence<int>> sequence(new LinkedListSequence<int>(LoadIntFile("int.txt")));

    BubbleSort<int> sorter;

    sorter.Sort(sequence);

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i) <= sequence->Get(i + 1));
    }
};

void TestBubbleSortByYearOfBirth()
{
    GeneratePersonFile("persons.txt", 3, 7);
    ShrdPtr<Sequence<Person>> sequence(new LinkedListSequence<Person>(LoadPersonsFromFile("persons.txt")));

    BubbleSort<Person> sorter;
    sorter.Sort(sequence, Person::YearOfBirthComparator());

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i).GetYearOfBirth() <= sequence->Get(i + 1).GetYearOfBirth());
    }
}

void TestBubbleSortByLastname()
{
    GeneratePersonFile("persons.txt", 3, 7);
    ShrdPtr<Sequence<Person>> sequence(new LinkedListSequence<Person>(LoadPersonsFromFile("persons.txt")));

    BubbleSort<Person> sorter;
    sorter.Sort(sequence, Person::LastnameComparator());

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i).GetLastname() <= sequence->Get(i + 1).GetLastname());
    }
}

void TestBubbleSortByHeight()
{
    GeneratePersonFile("persons.txt", 3, 7);
    ShrdPtr<Sequence<Person>> sequence(new LinkedListSequence<Person>(LoadPersonsFromFile("persons.txt")));

    BubbleSort<Person> sorter;
    sorter.Sort(sequence, Person::HeightComparator());

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i).GetHeight() <= sequence->Get(i + 1).GetHeight());
    }
}

void TestBubbleSortByWeight()
{
    GeneratePersonFile("persons.txt", 3, 7);
    ShrdPtr<Sequence<Person>> sequence(new LinkedListSequence<Person>(LoadPersonsFromFile("persons.txt")));

    BubbleSort<Person> sorter;
    sorter.Sort(sequence, Person::WeightComparator());

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i).GetWeight() <= sequence->Get(i + 1).GetWeight());
    }
}

void TestInsertionSortInt()
{
    GenerateIntFile("int.txt", 10, 0, 100);
    ShrdPtr<Sequence<int>> sequence(new LinkedListSequence<int>(LoadIntFile("int.txt")));

    InsertionSort<int> sorter;

    sorter.Sort(sequence);

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i) <= sequence->Get(i + 1));
    }
};

void TestInsertionSortByYearOfBirth()
{
    GeneratePersonFile("persons.txt", 3, 7);
    ShrdPtr<Sequence<Person>> sequence(new LinkedListSequence<Person>(LoadPersonsFromFile("persons.txt")));

    InsertionSort<Person> sorter;
    sorter.Sort(sequence, Person::YearOfBirthComparator());

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i).GetYearOfBirth() <= sequence->Get(i + 1).GetYearOfBirth());
    }
}

void TestInsertionSortByLastname()
{
    GeneratePersonFile("persons.txt", 3, 7);
    ShrdPtr<Sequence<Person>> sequence(new LinkedListSequence<Person>(LoadPersonsFromFile("persons.txt")));

    InsertionSort<Person> sorter;
    sorter.Sort(sequence, Person::LastnameComparator());

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i).GetLastname() <= sequence->Get(i + 1).GetLastname());
    }
}

void TestInsertionSortByHeight()
{
    GeneratePersonFile("persons.txt", 3, 7);
    ShrdPtr<Sequence<Person>> sequence(new LinkedListSequence<Person>(LoadPersonsFromFile("persons.txt")));

    InsertionSort<Person> sorter;
    sorter.Sort(sequence, Person::HeightComparator());

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i).GetHeight() <= sequence->Get(i + 1).GetHeight());
    }
}

void TestInsertionSortByWeight()
{
    GeneratePersonFile("persons.txt", 3, 7);
    ShrdPtr<Sequence<Person>> sequence(new LinkedListSequence<Person>(LoadPersonsFromFile("persons.txt")));

    InsertionSort<Person> sorter;
    sorter.Sort(sequence, Person::WeightComparator());

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i).GetWeight() <= sequence->Get(i + 1).GetWeight());
    }
}

void TestBinaryInsertionSortInt()
{
    GenerateIntFile("int.txt", 10, 0, 100);
    ShrdPtr<Sequence<int>> sequence(new LinkedListSequence<int>(LoadIntFile("int.txt")));

    BinaryInsertionSort<int> sorter;

    sorter.Sort(sequence);

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i) <= sequence->Get(i + 1));
    }
};

void TestBinaryInsertionSortByYearOfBirth()
{
    GeneratePersonFile("persons.txt", 3, 7);
    ShrdPtr<Sequence<Person>> sequence(new LinkedListSequence<Person>(LoadPersonsFromFile("persons.txt")));

    InsertionSort<Person> sorter;
    sorter.Sort(sequence, Person::YearOfBirthComparator());

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i).GetYearOfBirth() <= sequence->Get(i + 1).GetYearOfBirth());
    }
}

void TestBinaryInsertionSortByLastname()
{
    GeneratePersonFile("persons.txt", 3, 7);
    ShrdPtr<Sequence<Person>> sequence(new LinkedListSequence<Person>(LoadPersonsFromFile("persons.txt")));

    InsertionSort<Person> sorter;
    sorter.Sort(sequence, Person::LastnameComparator());

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i).GetLastname() <= sequence->Get(i + 1).GetLastname());
    }
}

void TestBinaryInsertionSortByHeight()
{
    GeneratePersonFile("persons.txt", 3, 7);
    ShrdPtr<Sequence<Person>> sequence(new LinkedListSequence<Person>(LoadPersonsFromFile("persons.txt")));

    InsertionSort<Person> sorter;
    sorter.Sort(sequence, Person::HeightComparator());

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i).GetHeight() <= sequence->Get(i + 1).GetHeight());
    }
}

void TestBinaryInsertionSortByWeight()
{
    GeneratePersonFile("persons.txt", 3, 7);
    ShrdPtr<Sequence<Person>> sequence(new LinkedListSequence<Person>(LoadPersonsFromFile("persons.txt")));

    InsertionSort<Person> sorter;
    sorter.Sort(sequence, Person::WeightComparator());

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i).GetWeight() <= sequence->Get(i + 1).GetWeight());
    }
}

template <typename T>
void MeasureSortTime(ISorter<T>& sorter, ShrdPtr<Sequence<T>> sequence, const std::string& sortName)
{
    auto start = std::chrono::high_resolution_clock::now();
    sorter.Sort(sequence);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    //std::cout << sortName << " took " << duration.count() << " seconds on " << sequence->GetLength() << " elements.\n";
}

void TestSorts(size_t dataSize)
{
    GenerateIntFile("int.txt", dataSize, 0, 10);
    ShrdPtr<Sequence<int>> sequence(new LinkedListSequence<int>(LoadIntFile("int.txt")));

    BubbleSort<int> bubbleSort;
    InsertionSort<int> insertionSort;
    BinaryInsertionSort<int> binaryInsertionSort;

    MeasureSortTime(bubbleSort, sequence, "Bubble Sort");
    MeasureSortTime(insertionSort, sequence, "Insertion Sort");
    MeasureSortTime(binaryInsertionSort, sequence, "Binary Insertion Sort");
}