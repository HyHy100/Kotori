#pragma once

#include "node.hpp"

namespace ktl {
    template<
        typename T
    >
    class SingleList {
    public:
        using Type = T;
        using Node = _Node<Type>;

        SingleList() = default;

        ~SingleList() = default;
        
        /*
        ====================TODO===============
        */
    private:
        Node* head;
    };
}
