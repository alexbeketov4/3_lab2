#pragma once
#include "Isorter.h"
#include "Person.h"
#include "ShrdPtr.h"
#include "LinkedListSequence.h"
#include <iostream>
#include <functional>

template <typename T>
class InsertionSort : public ISorter<T>
{
public:

    void Sort(ShrdPtr<Sequence<T>> seq, Comparator<T> comp = std::less<T>()) override
    {
        size_t size = seq->GetLength();

        for (size_t i = 1; i < size; ++i)
        {
            T key = seq->Get(i);
            int j = i - 1;

            while (j >= 0 && comp(key, seq->Get(j)))
            {
                seq->Set(seq->Get(j), j + 1);
                j--;
            }
            seq->Set(key, j + 1);
        }
    }
};