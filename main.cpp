#include "parking_lot.h"

int main()
{
    time_t now = time(0);
    Parking_Lot mall_motorcycle_object("Mall", "Motorcycle", 2);
    mall_motorcycle_object.park(now);
    mall_motorcycle_object.park(now + (1 * 60 * 60));
    mall_motorcycle_object.park(now + (2 * 60 * 60));
    mall_motorcycle_object.unpark("T2", now + (4 * 60 * 60));
    mall_motorcycle_object.park(now + (6 * 60 * 60));
    mall_motorcycle_object.unpark("T1", now + (6 * 60 * 60));
    return 0;
}