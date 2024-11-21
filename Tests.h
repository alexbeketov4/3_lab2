#pragma once
#include "InsertionSort.h"
#include "BinaryInsertionSort.h"
#include "BubbleSort.h"
#include "Person.h"
#include <cassert>
#include <string>

int items[] = { 5, 2, 9, 1, 5, 6 };

void TestBubbleSortInt()
{
    ShrdPtr<Sequence<int>> sequence(new LinkedListSequence<int>(items, 6));

    BubbleSort<int> sorter;

    sorter.Sort(sequence);

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i) <= sequence->Get(i + 1));
    }
};

void TestBubbleSortByYearOfBirth()
{
    ShrdPtr<Sequence<Person>> sequence(new LinkedListSequence<Person>());
    sequence->Append(Person(2020, "lll", "lll", 200, 150));
    sequence->Append(Person(2015, "bbb", "bbb", 180, 100));
    sequence->Append(Person(1990, "aaa", "aaa", 190, 64));
    sequence->Append(Person(1888, "ccc", "ccc", 160, 52));

    BubbleSort<Person> sorter;
    sorter.Sort(sequence, Person::YearOfBirthComparator());

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i).GetYearOfBirth() <= sequence->Get(i + 1).GetYearOfBirth());
    }
}

void TestBubbleSortByLastname()
{
    ShrdPtr<Sequence<Person>> sequence(new LinkedListSequence<Person>());
    sequence->Append(Person(2020, "lll", "lll", 200, 150));
    sequence->Append(Person(2015, "bbb", "bbb", 180, 100));
    sequence->Append(Person(1990, "aaa", "aaa", 190, 64));
    sequence->Append(Person(1888, "ccc", "ccc", 160, 52));

    BubbleSort<Person> sorter;
    sorter.Sort(sequence, Person::LastnameComparator());

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i).GetLastname() <= sequence->Get(i + 1).GetLastname());
    }
}

void TestBubbleSortByHeight()
{
    ShrdPtr<Sequence<Person>> sequence(new LinkedListSequence<Person>());
    sequence->Append(Person(2020, "lll", "lll", 200, 150));
    sequence->Append(Person(2015, "bbb", "bbb", 180, 100));
    sequence->Append(Person(1990, "aaa", "aaa", 190, 64));
    sequence->Append(Person(1888, "ccc", "ccc", 160, 52));

    BubbleSort<Person> sorter;
    sorter.Sort(sequence, Person::HeightComporator());

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i).GetHeight() <= sequence->Get(i + 1).GetHeight());
    }
}

void TestBubbleSortByWeight()
{
    ShrdPtr<Sequence<Person>> sequence(new LinkedListSequence<Person>());
    sequence->Append(Person(2020, "lll", "lll", 200, 150));
    sequence->Append(Person(2015, "bbb", "bbb", 180, 100));
    sequence->Append(Person(1990, "aaa", "aaa", 190, 64));
    sequence->Append(Person(1888, "ccc", "ccc", 160, 52));

    BubbleSort<Person> sorter;
    sorter.Sort(sequence, Person::WeightComporator());

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i).GetWeight() <= sequence->Get(i + 1).GetWeight());
    }
}

void TestInsertionSortInt()
{
    ShrdPtr<Sequence<int>> sequence(new LinkedListSequence<int>(items, 6));

    InsertionSort<int> sorter;

    sorter.Sort(sequence);

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i) <= sequence->Get(i + 1));
    }
};

void TestInsertionSortByYearOfBirth()
{
    ShrdPtr<Sequence<Person>> sequence(new LinkedListSequence<Person>());
    sequence->Append(Person(2020, "lll", "lll", 200, 150));
    sequence->Append(Person(2015, "bbb", "bbb", 180, 100));
    sequence->Append(Person(1990, "aaa", "aaa", 190, 64));
    sequence->Append(Person(1888, "ccc", "ccc", 160, 52));

    InsertionSort<Person> sorter;
    sorter.Sort(sequence, Person::YearOfBirthComparator());

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i).GetYearOfBirth() <= sequence->Get(i + 1).GetYearOfBirth());
    }
}

void TestInsertionSortByLastname()
{
    ShrdPtr<Sequence<Person>> sequence(new LinkedListSequence<Person>());
    sequence->Append(Person(2020, "lll", "lll", 200, 150));
    sequence->Append(Person(2015, "bbb", "bbb", 180, 100));
    sequence->Append(Person(1990, "aaa", "aaa", 190, 64));
    sequence->Append(Person(1888, "ccc", "ccc", 160, 52));

    InsertionSort<Person> sorter;
    sorter.Sort(sequence, Person::LastnameComparator());

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i).GetLastname() <= sequence->Get(i + 1).GetLastname());
    }
}

void TestInsertionSortByHeight()
{
    ShrdPtr<Sequence<Person>> sequence(new LinkedListSequence<Person>());
    sequence->Append(Person(2020, "lll", "lll", 200, 150));
    sequence->Append(Person(2015, "bbb", "bbb", 180, 100));
    sequence->Append(Person(1990, "aaa", "aaa", 190, 64));
    sequence->Append(Person(1888, "ccc", "ccc", 160, 52));

    InsertionSort<Person> sorter;
    sorter.Sort(sequence, Person::HeightComporator());

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i).GetHeight() <= sequence->Get(i + 1).GetHeight());
    }
}

void TestInsertionSortByWeight()
{
    ShrdPtr<Sequence<Person>> sequence(new LinkedListSequence<Person>());
    sequence->Append(Person(2020, "lll", "lll", 200, 150));
    sequence->Append(Person(2015, "bbb", "bbb", 180, 100));
    sequence->Append(Person(1990, "aaa", "aaa", 190, 64));
    sequence->Append(Person(1888, "ccc", "ccc", 160, 52));

    InsertionSort<Person> sorter;
    sorter.Sort(sequence, Person::WeightComporator());

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i).GetWeight() <= sequence->Get(i + 1).GetWeight());
    }
}

void TestBinaryInsertionSortInt()
{
    ShrdPtr<Sequence<int>> sequence(new LinkedListSequence<int>(items, 6));

    BinaryInsertionSort<int> sorter;

    sorter.Sort(sequence);

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i) <= sequence->Get(i + 1));
    }
};

void TestBinaryInsertionSortByYearOfBirth()
{
    ShrdPtr<Sequence<Person>> sequence(new LinkedListSequence<Person>());
    sequence->Append(Person(2020, "lll", "lll", 200, 150));
    sequence->Append(Person(2015, "bbb", "bbb", 180, 100));
    sequence->Append(Person(1990, "aaa", "aaa", 190, 64));
    sequence->Append(Person(1888, "ccc", "ccc", 160, 52));

    InsertionSort<Person> sorter;
    sorter.Sort(sequence, Person::YearOfBirthComparator());

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i).GetYearOfBirth() <= sequence->Get(i + 1).GetYearOfBirth());
    }
}

void TestBinaryInsertionSortByLastname()
{
    ShrdPtr<Sequence<Person>> sequence(new LinkedListSequence<Person>());
    sequence->Append(Person(2020, "lll", "lll", 200, 150));
    sequence->Append(Person(2015, "bbb", "bbb", 180, 100));
    sequence->Append(Person(1990, "aaa", "aaa", 190, 64));
    sequence->Append(Person(1888, "ccc", "ccc", 160, 52));

    InsertionSort<Person> sorter;
    sorter.Sort(sequence, Person::LastnameComparator());

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i).GetLastname() <= sequence->Get(i + 1).GetLastname());
    }
}

void TestBinaryInsertionSortByHeight()
{
    ShrdPtr<Sequence<Person>> sequence(new LinkedListSequence<Person>());
    sequence->Append(Person(2020, "lll", "lll", 200, 150));
    sequence->Append(Person(2015, "bbb", "bbb", 180, 100));
    sequence->Append(Person(1990, "aaa", "aaa", 190, 64));
    sequence->Append(Person(1888, "ccc", "ccc", 160, 52));

    InsertionSort<Person> sorter;
    sorter.Sort(sequence, Person::HeightComporator());

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i).GetHeight() <= sequence->Get(i + 1).GetHeight());
    }
}

void TestBinaryInsertionSortByWeight()
{
    ShrdPtr<Sequence<Person>> sequence(new LinkedListSequence<Person>());
    sequence->Append(Person(2020, "lll", "lll", 200, 150));
    sequence->Append(Person(2015, "bbb", "bbb", 180, 100));
    sequence->Append(Person(1990, "aaa", "aaa", 190, 64));
    sequence->Append(Person(1888, "ccc", "ccc", 160, 52));

    InsertionSort<Person> sorter;
    sorter.Sort(sequence, Person::WeightComporator());

    for (size_t i = 0; i < sequence->GetLength() - 1; ++i)
    {
        assert(sequence->Get(i).GetWeight() <= sequence->Get(i + 1).GetWeight());
    }
}

