#include <bits/stdc++.h>

using namespace std;

class Parking_Receipt
{
private:
    string Receipt_Number;
    int Spot_No;
    time_t Entry_Date_Time;
    time_t Exit_Date_Time;
    int Parking_Fee;

public:
    // Constructor
    Parking_Receipt(string receipt_no, int spot_no, int parking_fees, time_t entry_date_time, time_t exit_date_time)
    {
        Receipt_Number = receipt_no;
        Spot_No = spot_no;
        Parking_Fee = parking_fees;
        Entry_Date_Time = entry_date_time;
        Exit_Date_Time = exit_date_time;
    }
    void Print_Receipt()
    {
        cout << "--------------------------------------------------\n";
        cout << "Parking Receipt:\n";
        cout << "   Receipt Number: " << Receipt_Number << endl;
        cout << "   Spot Number: " << Spot_No << endl;
        cout << "   Entry Date-Time: " << ctime(&Entry_Date_Time);
        cout << "   Exit Date-Time: " << ctime(&Exit_Date_Time);
        cout << "   Fees: " << Parking_Fee << endl;
        cout << "--------------------------------------------------\n";
    }
};