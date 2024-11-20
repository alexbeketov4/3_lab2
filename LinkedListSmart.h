#pragma once
#include "ShrdPtr.h"
#include "UnqPtr.h"
#include <stdexcept>

template <typename T>
class LinkedListSmart
{
private:
    struct Node
    {
        T data;
        ShrdPtr<Node> next;

        Node(const T& item) : data(item), next(nullptr) {}
    };

    ShrdPtr<Node> head;
    size_t length;

public:
    LinkedListSmart() : head(nullptr), length(0) {}

    LinkedListSmart(const T* items, int count)
    {
        this->length = count;
        if (count <= 0) return;

        this->head = ShrdPtr<Node>(new Node(items[0]));
        ShrdPtr<Node> current = this->head;

        for (int i = 1; i < count; i++)
        {
            current->next = ShrdPtr<Node>(new Node(items[i]));
            current = current->next;
        }
    }

    ~LinkedListSmart() = default;

    LinkedListSmart(const LinkedListSmart<T>& other)
    {
        this->length = 0;
        this->head = nullptr;

        ShrdPtr<Node> current = other.head;
        while (current)
        {
            Append(current->data);
            current = current->next;
        }
    }

    size_t GetLength() const
    {
        return length;
    }

    T GetFirst() const
    {
        if (this->GetLength() == 0)
        {
            throw  "EmptyList";
        }
        return head->data;
    }

    T GetLast() const
    {
        if (this->GetLength() == 0)
        {
            throw  "EmptyList";
        }

        ShrdPtr<Node> current = head;

        while (current->next)
        {
            current = current->next;
        }
        return current->data;
    }

    T Get(int index) const
    {
        if (index < 0 || index >= this->GetLength())
        {
            throw  "IndexOutOfRange";
        }

        ShrdPtr<Node> current = head;

        for (int i = 0; i < index; ++i)
        {
            current = current->next;
        }

        return current->data;
    }

    UnqPtr<LinkedListSmart<T>> GetSubsequence(int startIndex, int endIndex) const
    {
        if (startIndex < 0 || endIndex >= this->GetLength() || startIndex > endIndex)
        {
            throw "IndexOutOfRange";
        }

        UnqPtr<LinkedListSmart<T>> subSeq(new LinkedListSmart<T>());

        ShrdPtr<Node> current = head;
        for (int i = 0; i <= endIndex; ++i)
        {
            if (i >= startIndex)
            {
                subSeq->Append(current->data);
            }
            current = current->next;
        }
        return subSeq;
    }

    void Append(const T& item)
    {
        ShrdPtr<Node> newNode = ShrdPtr<Node>(new Node(item));
        ShrdPtr<Node> newShrdPtr(newNode);

        if (this->GetLength() == 0)
        {
            head = std::move(newShrdPtr);
        }

        else
        {
            ShrdPtr<Node> current = head;
            while (current->next)
            {
                current = current->next;
            }

            current->next = std::move(newShrdPtr);
        }
        length++;
    }

    void Prepend(const T& item)
    {
        ShrdPtr<Node> newNode = ShrdPtr<Node>(new Node(item));
        newNode->next = std::move(head);
        head = ShrdPtr<Node>(newNode);
        length++;
    }

    void InsertAt(const T& item, int index)
    {
        if (index > this->GetLength() || index < 0)
        {
            throw  "IndexOutOfRange";
        }

        if (index == 0)
        {
            this->Prepend(item);
        }

        else if (this->GetLength() == 0 || this->GetLength() == index)
        {
            this->Append(item);
        }

        else
        {
            ShrdPtr<Node> left = head;
            for (int i = 0; i < index - 1; i++) {
                left = left->next;
            }

            ShrdPtr<Node> ptr = ShrdPtr<Node>(new Node(item));

            ptr->next = std::move(left->next);
            left->next = std::move(ptr);
            length++;
        }
    }

    void Set(const T& item, int index)
    {
        if (this->GetLength() == 0)
        {
            throw "Cannot set item in an empty list";
        }

        if (index >= this->GetLength() || index < 0)
        {
            throw "IndexOutOfRange";
        }

        ShrdPtr<Node> current = this->head;
        for (int i = 0; i < index; ++i)
        {
            current = current->next;
        }
        current->data = item;
    }

    UnqPtr<LinkedListSmart<T>> Concat(const UnqPtr<LinkedListSmart<T>>& list) const
    {
        UnqPtr<LinkedListSmart<T>> newList(new LinkedListSmart<T>(*this));

        ShrdPtr<Node> lastNode = newList->head;
        while (lastNode->next)
        {
            lastNode = lastNode->next;
        }

        ShrdPtr<Node> current = list->head;
        while (current)
        {
            lastNode->next = ShrdPtr<Node>(new Node(current->data));
            lastNode = lastNode->next;
            current = current->next;
        }

        newList->length = this->length + list->GetLength();

        return newList;
    }
};