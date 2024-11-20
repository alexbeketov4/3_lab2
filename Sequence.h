#pragma once
template<class T>
class Sequence
{
public:
    virtual size_t GetLength() const = 0;

    virtual T GetFirst() const = 0;

    virtual T GetLast() const = 0;

    virtual T Get(int index) const = 0;

    virtual UnqPtr<Sequence<T>> GetSubsequence(int startIndex, int endIndex) const = 0;

    virtual void Append(const T& item) = 0;

    virtual void Prepend(const T& item) = 0;

    virtual void InsertAt(const T& item, int index) = 0;

    virtual void Set(const T& item, int index) = 0;

    virtual UnqPtr<Sequence<T>> Concat(UnqPtr<Sequence<T>> other) const = 0;

    virtual const UnqPtr<LinkedListSmart<T>>& GetLinkedList() const = 0;

    virtual ~Sequence() {}
};