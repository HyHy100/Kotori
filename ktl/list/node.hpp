#pragma once

namespace ktl {
    template<typename T>
    class _Node {
    public:
        using type = T;

        _Node()
            : pNext(nullptr)
        {
        }

        ~_Node() = default;

        T* operator->() const
        {
            return &data;
        }

        T& operator*()
        {
            return data;
        }

        T* get()
        {
            return &data;
        }
    public:
        T* data;
        _Node<T>* pNext;
    };
}
