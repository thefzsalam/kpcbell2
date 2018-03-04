#include "Alarm.hpp"
#include "Iterator.hpp"

class AlarmsRomStorage {

public:
    void store_all_to_rom(Iterator<Alarm> alarms);
    Iterator<Alarm> load_all_from_rom();

};
