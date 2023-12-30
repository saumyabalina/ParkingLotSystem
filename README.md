# ParkingLotSystem

A parking lot is a dedicated area that is intended for parking vehicles.
● The parking lot will allow different types of vehicles to be parked:
    ○ Motorcycles/Scooters
    ○ Cars/SUVs
    ○ Buses/Trucks
● Each vehicle will occupy a single spot and the spot size will be different for different
 vehicles.
● The number of spots per vehicle type will be different for different parking lots. For
  example
    ○ Motorcycles/scooters: 100 spots
    ○ Cars/SUVs: 80 spots
    ○ Buses/Trucks: 40 spots
● When a vehicle is parked, a parking ticket should be generated with the spot number
  and the entry date-time.
● When a vehicle is unparked, a receipt should be generated with the entry date-time,
  exit date-time, and the applicable fees to be paid.

Different locations have different fee models. Below are a few possible models:

● Mall
    Vehicle               Fee
    Motorcycle            10 per hour
    Car/SUV               20 per hour
    Bus/Truck             50 per hour

● Stadium
    Vehicle          Interval              Fee
    Motorcycle       [0,4) hours           30 flat rate
                     [4,12) hours          60 flat rate
                     [12, Inf) hours       100 per hour 
    Car/SUV          [0,4) hours           60 flat rate
                     [4,12) hours          120 flat rate
                     [12, Inf) hours       200 per hour

● Airport
    Vehicle          Interval              Fee
    Motorcycle       [0,1) hours           Free
                     [1,8) hours           40 flat rate
                     [8, 24) hours         60 flat rate
                     Each day              80 per-day
    Car/SUV          [0,12) hours          60 flat rate
                     [12,24) hours         80 flat rate
                     Each day              100 per-day
 
Problem Statement:

Given a parking lot with details about the vehicle types that can be parked, the number of spots, and the fee model for the parking lot; compute the fees to be paid for the parked vehicles when the vehicle is unparked.


Run Examples:
"""""""""""""
    -----------------
    EXAMPLE Output:
    -----------------

Parking Lot: Mall
Vehicle Type: Motorcycle
Number of Spots: 2
--------------------------------------------------
Parking Ticket:
   Ticket Number: T1
   Spot Number: 1
   Entry Date-Time: Sat Dec 30 20:11:44 2023
--------------------------------------------------
--------------------------------------------------
Parking Ticket:
   Ticket Number: T2
   Spot Number: 2
   Entry Date-Time: Sat Dec 30 21:11:44 2023
--------------------------------------------------
--------------------------------------------------
Sorry, no spots available.
--------------------------------------------------
--------------------------------------------------
Parking Receipt:
   Receipt Number: R1
   Spot Number: 2
   Entry Date-Time: Sat Dec 30 21:11:44 2023
   Exit Date-Time: Sun Dec 31 00:11:44 2023
   Fees: 30
--------------------------------------------------
--------------------------------------------------
Parking Ticket:
   Ticket Number: T3
   Spot Number: 2
   Entry Date-Time: Sun Dec 31 02:11:44 2023
--------------------------------------------------
--------------------------------------------------
Parking Receipt:
   Receipt Number: R2
   Spot Number: 1
   Entry Date-Time: Sat Dec 30 20:11:44 2023
   Exit Date-Time: Sun Dec 31 02:11:44 2023
   Fees: 60
--------------------------------------------------