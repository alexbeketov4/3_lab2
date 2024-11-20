#pragma once
#include "Isorter.h"
#include "Person.h"
#include "ShrdPtr.h"
#include "LinkedListSequence.h"
#include <iostream>
#include <functional>

template <typename T>
class BubbleSort : public ISorter<T>
{
public:

    void Sort(ShrdPtr<Sequence<T>> seq, Comparator<T> comp = std::less<T>()) override
    {
        size_t size = seq->GetLength();

        for (size_t i = 0; i < size - 1; ++i)
        {
            for (size_t j = 0; j < size - i - 1; ++j)
            {
                if (comp(seq->Get(j + 1), seq->Get(j)))
                {
                    T temp = seq->Get(j);
                    seq->Set(seq->Get(j + 1), j);
                    seq->Set(temp, j + 1);
                }
            }
        }
    }
};