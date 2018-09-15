#pragma once

namespace ktl {
    template<typename ErrorType, typename ResultType>
    class Result {
    public:
        volatile ErrorType value;
        volatile ResultType result;
    }; 
}