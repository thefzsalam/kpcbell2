#include <cstdint>
#include "Alarm24h.hpp"
#include "Iterator.hpp"

#define ALARM_STORE_MAX_NO_OF_ALARMS 100

class AlarmsInMemory {
public:
    template <typename T>
    struct StoreEntry {
        const uint8_t index;
        const T *const entry;
    };

    void add_alarm(Alarm24h alarm);
    void replace_alarm(uint8_t index, Alarm24h alarm);
    void delete_alarm(uint8_t index);
    void delete_all();

    /* Note:
        AlarmsInMemory may contain logic to reduce 
        fragmentation and reuse unused memory.
        StoreEntry.index may not be contiguous.
    */
    Iterator<StoreEntry<Alarm24h>> iterator();



private:
    struct StorageCell;
    StorageCell storage[ALARM_STORE_MAX_NO_OF_ALARMS];
    uint8_t storage_end_index = 0;



};
