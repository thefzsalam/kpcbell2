#include "Time.hpp"
#include "Alarm24h.hpp"
#include "Iterator.hpp"

class AlarmsChecker {
public:
    Alarm24h get_next_alarm_after_time(Time time, Iterator<Alarm24h> alarms_iterator);
    bool     has_time_passed_alarm(Time time, Alarm24h alarm);
};
