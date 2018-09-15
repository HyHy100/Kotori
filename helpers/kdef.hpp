#pragma once

#define KO_NAKED      [[gnu::naked]]

#define KTR_VALIDATE_STRUCTURE(S, SIZE)                             \
        static_assert(sizeof(S) == SIZE,                            \
        "KTR_VALIDATE_STRUCTURE: Wrong size of \""#S"\" structure")