#pragma once
#include "Isorter.h"
#include "Person.h"
#include "ShrdPtr.h"
#include "LinkedListSequence.h"
#include <iostream>
#include <functional>

template <typename T>
class BinaryInsertionSort : public ISorter<T>
{
private:

    int BinarySearch(ShrdPtr<Sequence<T>> seq, const T& key, int left, int right, Comparator<T> comp)
    {
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (comp(seq->Get(mid), key))
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }

public:

    void Sort(ShrdPtr<Sequence<T>> seq, Comparator<T> comp = std::less<T>()) override
    {

        for (size_t i = 1; i < seq->GetLength(); ++i)
        {
            T key = seq->Get(i);

            int pos = BinarySearch(seq, key, 0, i - 1, comp);

            for (int j = i; j > pos; --j)
            {
                seq->Set(seq->Get(j - 1), j);
            }

            seq->Set(key, pos);
        }
    }
};