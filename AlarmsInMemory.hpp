#include <cstdint>
#include "Alarm.hpp"
#include "Iterator.hpp"

#define ALARM_STORE_MAX_NO_OF_ALARMS 100

class AlarmsInMemory {
private:
    Alarm storage[ALARM_STORE_MAX_NO_OF_ALARMS];
    uint8_t storage_end_index = 0;

public:
    template <typename T>
    class StoreEntry {
        const uint8_t index;
        const T *const entry;
    };

    void add_alarm(Alarm alarm);
    void replace_alarm(uint8_t index, Alarm alarm);
    void delete_alarm(uint8_t index);
    void delete_all();

    Iterator<StoreEntry<Alarm>> iterator();
};
