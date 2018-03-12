#include "catch/catch.hpp"

#include "AlarmsInMemory.hpp"
#include "iterator.hpp"
#include "Alarm24h.hpp"

SCENARIO("AlarmsInMemory should support basic CRUD operations.") {
	GIVEN("an empty AlarmsInMemory container") {
		AlarmsInMemory aim;
		REQUIRE(aim.iterator().has_next() == false);

		WHEN("an Alarm24h is added") {
			aim.add_alarm(Alarm24h{01,02});
			THEN("it should appear in the iterator") {
				REQUIRE(aim.iterator().has_next() == true);
			}
			THEN("it should be equal to the one we just added") {
				auto store_entry = aim.iterator().next();
				Alarm24h a = *store_entry.entry_ptr;
				REQUIRE(a.hours == 01);
				REQUIRE(a.minutes = 02);
			}
		}
		WHEN("multiple iterators are obtained") {
			auto iterator1 = aim.iterator();
			auto iterator2 = aim.iterator();
			THEN("they may be called independently") {
				auto store_entry1 = iterator1.next();
				auto store_entry2 = iterator2.next();
				REQUIRE(store_entry1.entry_ptr == store_entry2.entry_ptr);
			}
			
			iterator1 = aim.iterator();
			iterator2 = aim.iterator();
			THEN("exhaustion of one must not cause the other to exhaust") {
				
				/* both the iterators must have some data to iterate on
				   as we have not deleted the Alarm24h we just added.
				*/
				REQUIRE(iterator1.has_next() == true)
				REQUIRE(iterator2.has_next() == true)

				while(iterator1.has_next()) {
					iterator1.next();
				}
				REQUIRE(iterator2.has_next()==true)
			}

		}
		WHEN("that Alarm24h is replaced") {
			auto iterator = aim.iterator();
			REQUIRE(iterator.has_next()==TRUE);

			auto store_entry = iterator.next();
			aim.replace_alarm(store_entry.index, Alarm24h{10,20});

			THEN("the old store entry should reflect the changes") {
				REQUIRE( *store_entry.entry_ptr == Alarm24h{10,20});
			}
			
			THEN("new iterators should contain the new entry") {
				auto iterator_new = aim.iterator();
				AlarmsInMemory::StoreEntry<Alarm24h> store_entry_new;
				while(iterator_new.has_next()) {
					auto new_store_entry = iterator_new.next();
					if(new_store_entry.index == store_entry.index) {
						REQUIRE(*new_store_entry.entry_ptr == *store_entry.entry_ptr);
						break;
					}
				}
			}
		}
	}
}