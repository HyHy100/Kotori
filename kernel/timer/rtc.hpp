#pragma once

namespace kt {
    class RTC {
    public:
        using time_t = long long;

        RTC(const time_t time) const;

        void update(const time_t time);
    private:
        
    };
}

namespace kt {
    RTC::RTC(const time_t time) const
        : update(time)
    {
        
        platform::requestTimeruo
    }
}