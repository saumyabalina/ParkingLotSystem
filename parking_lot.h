#include "parking_receipt.h"
#include "parking_fees.h"
#include "parking_ticket.h"

typedef struct Ticket
{
    string ticket_num;
    time_t entry;
    int Spot;
} Ticket;

// typedef struct Ticket *T_array;

class Parking_Lot
{
private:
    string Parking_Location;
    string Vehicle_Type;
    time_t Entry_Date_Time;
    time_t Exit_Date_Time;
    int Number_of_Spots;
    int Available_Spots;
    int num_tickets;
    int num_receipts;
    Ticket *t;
    vector<Ticket> ticket;

public:
    // Constructor
    Parking_Lot(string parking_location, string vehicle, int number_spots)
    {
        Parking_Location = parking_location;
        Vehicle_Type = vehicle;
        Number_of_Spots = number_spots;
        Available_Spots = number_spots;
        num_tickets = 0;
        num_receipts = 0;
        // t[Number_of_Spots+1];
        t = (Ticket *)malloc(sizeof(Ticket) * (Number_of_Spots + 1));
        // t[Number_of_Spots + 1]={};
        for (int i = 0; i <= Number_of_Spots; i++)
        {
            t[i].Spot = 0;
        }
    }
    void park(time_t entry_date_time)
    {
        if (Available_Spots > 0)
        {
            Available_Spots--;
            num_tickets++;
            string Ticket_No;
            int Spot_No=0;
            for (int i = 1; i <= Number_of_Spots; i++)
            {
                if (t[i].Spot == 0)
                {
                    t[i].Spot = 1;
                    t[i].entry = entry_date_time;
                    Entry_Date_Time = t[i].entry;
                    // t[i].ticket_num = "T1";
                    Ticket_No = "T" + to_string(num_tickets);
                    // t[i].ticket_num = Ticket_No;
                    (t[i].ticket_num).assign(Ticket_No);
                    Spot_No = i;
                    break;
                }
            }
            Parking_Ticket pt(Ticket_No, Spot_No, Entry_Date_Time);
            pt.Print_Ticket();
        }
        else
        {
            cout << "--------------------------------------------------\n";
            cout << "Sorry, no spots available." << endl;
            cout << "--------------------------------------------------\n";
        }
    }
    void unpark(string Ticket_No, time_t exit_date_time)
    {
        Exit_Date_Time = exit_date_time;
        Available_Spots++;
        num_receipts++;
        int Spot_No = 0;
        for (int i = 1; i <= Number_of_Spots; i++)
        {
            // if (Ticket_No == t[i].ticket_num)
            if (!Ticket_No.compare(t[i].ticket_num))
            {
                Entry_Date_Time = t[i].entry;
                t[i].Spot = 0;
                Spot_No = i;
                break;
            }
        }
        string receipt_no = "R" + to_string(num_receipts);
        ParkingFees f(Parking_Location, Vehicle_Type, Entry_Date_Time, Exit_Date_Time);
        int fee = f.calculate_fees();
        Parking_Receipt pr(receipt_no, Spot_No, fee, Entry_Date_Time, Exit_Date_Time);
        pr.Print_Receipt();
    }
};