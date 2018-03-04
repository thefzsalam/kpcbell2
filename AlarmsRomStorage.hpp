#include "Alarm24h.hpp"
#include "Iterator.hpp"

class AlarmsRomStorage {
public:
    void store_all_to_rom(Iterator<Alarm24h> alarms);
    Iterator<Alarm24h> load_all_from_rom();
};
