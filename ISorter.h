#pragma once
#include <functional>
#include "ShrdPtr.h"
#include "Sequence.h"

template <typename T>
using Comparator = std::function<bool(const T&, const T&)>;

template<typename T>
class ISorter
{
public:
    virtual void Sort(ShrdPtr<Sequence<T>> seq, Comparator<T> comp = std::less<T>()) = 0;
    virtual ~ISorter() = default;
};