#include <bits/stdc++.h>

using namespace std;

class Parking_Ticket
{
private:
    string Ticket_Number;
    int Spot_Number;
    time_t Entry_Date_Time;

public:
    // Constructor
    Parking_Ticket(string ticket_no, int spot_no, time_t entry_date_time)
    {
        Ticket_Number = ticket_no;
        Spot_Number = spot_no;
        Entry_Date_Time = entry_date_time;
    }
    void Print_Ticket()
    {
        cout << "--------------------------------------------------\n";
        cout << "Parking Ticket:\n";
        cout << "   Ticket Number: " << Ticket_Number << endl;
        cout << "   Spot Number: " << Spot_Number << endl;
        cout << "   Entry Date-Time: " << ctime(&Entry_Date_Time);
        cout << "--------------------------------------------------\n";
    }
};