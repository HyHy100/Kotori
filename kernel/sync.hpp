#pragma once

namespace kt::sync {
    class spinlock {
    public:
        static constexpr auto locked_value = 1;
        static constexpr auto unlocked_value = 0;

        spinlock() = default;

        spinlock(const spinlock&) = default;

        ~spinlock() = default;

        void init()
        {
            locked = unlocked_value;
        }

        void lock()
        {
            while (!__atomic_test_and_set(&locked, __ATOMIC_RELAXED));

            locked = locked_value;
        }

        void unlock()
        {
            locked = unlocked_value;
        }

        bool is_locked()
        {
            return locked;
        }

        bool try_lock()
        {
            return __atomic_test_and_set(&locked, __ATOMIC_RELAXED);
        }
    private:
        volatile int locked;
    };
}