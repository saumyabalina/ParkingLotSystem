#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

class ParkingFees
{
public:
    string Parking_Location;
    string Vehicle_Type;
    time_t Entry_Date_Time;
    time_t Exit_Date_Time;
    // Constructor
    ParkingFees(string parking_location, string vehicle, time_t entry_date_time, time_t exit_date_time)
    {
        Parking_Location = parking_location;
        Vehicle_Type = vehicle;
        Entry_Date_Time = entry_date_time;
        Exit_Date_Time = exit_date_time;
    }
    int calculate_fees()
    {
        int mins = (Exit_Date_Time - Entry_Date_Time) / 60;
        int duration_hours = mins / 60;
        int duration_mins = mins % 60;
        if (duration_mins != 0)
        {
            duration_hours += 1;
        }

        int parking_duration = duration_hours;
        int parking_fees = 0;
        if (Parking_Location == "Mall")
        {
            if (Vehicle_Type == "Motorcycle")
            {
                parking_fees = parking_duration * 10;
            }
            else if (Vehicle_Type == "Car" || Vehicle_Type == "SUV")
            {
                parking_fees = parking_duration * 20;
            }
            else if (Vehicle_Type == "Bus" || Vehicle_Type == "Truck")
            {
                parking_fees = parking_duration * 50;
            }
        }
        else if (Parking_Location == "Stadium")
        {
            if (Vehicle_Type == "Motorcycle")
            {
                if (parking_duration < 4)
                {
                    parking_fees = 30;
                }
                else if (parking_duration < 12)
                {
                    parking_fees = 30 + 60;
                }
                else
                {
                    parking_fees = 30 + 60 + (parking_duration - 12) * 100;
                }
            }
            else if (Vehicle_Type == "Car" || Vehicle_Type == "SUV")
            {
                if (parking_duration < 4)
                {
                    parking_fees = 60;
                }
                else if (parking_duration < 12)
                {
                    parking_fees = 60 + 120;
                }
                else
                {
                    parking_fees = 60 + 120 + (parking_duration - 12) * 200;
                }
            }
        }
        else if (Parking_Location == "Airport")
        {
            if (Vehicle_Type == "Motorcycle")
            {
                if (parking_duration < 1)
                {
                    parking_fees = 0;
                }
                else if (parking_duration < 8)
                {
                    parking_fees = 40;
                }
                else if (parking_duration < 24)
                {
                    parking_fees = 60;
                }
                else
                {
                    parking_fees = (parking_duration / 24 + ceil(parking_duration % 24)) * 80;
                }
            }
            else if (Vehicle_Type == "Car" || Vehicle_Type == "SUV")
            {
                if (parking_duration < 12)
                {
                    parking_fees = 60;
                }
                else if (parking_duration < 24)
                {
                    parking_fees = 80;
                }
                else
                {
                    parking_fees = (parking_duration / 24 + ceil(parking_duration % 24)) * 100;
                }
            }
        }
        return parking_fees;
    }
};