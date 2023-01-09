#pragma once
#include <vector>
#include "Reservation.h"
#include "dateTime.h"
#include "globalConstants.h"
#include "Room.h"
#include <fstream>
#include <string>

using std::vector, std::ofstream, std::ifstream;
class dataBase
{
private:
	int dayMonths[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	struct tuple {
		dateTime date{};
		vector <int> Reservation_ID{};
	};
    struct res //store the reservations in two vectors - one for even and the other one for odd IDs
	{
		vector <Reservation> even{};
		vector <Reservation> odd{};
	};
    vector <tuple> daysOfYear{}; //calendar-oriented database, store the reservation IDs for every day of the year in here
public:
    res Reservations{};
    int init(int year); //initialize the calendar-oriented database with the given year (to determine whether the array needs to be size 365 or 366)
    int load(bool LR = false); //load the reservations
    int loadRooms(); //load rooms
    int save(bool SR = false); //save the reservations
    int saveRooms(); //save rooms
    vector <Room> rooms{}; //rooms-oriented database
    vector <int> getID(dateTime dt); //returns the vector of all reservation ID saved for a specific day in the year
    Reservation getReservationByID(int &ID); //return a reservation being given its ID
    int getDBIDByResID(int ID); //return the index at which the reservation is stored in the database.
    //Warning: this is about the database vector, it is not unique, may differ every single run of the program
    //negative for even, 0 or positive for odd


    vector <Reservation> getAllReservationsAtDate(dateTime &dt); //return a vector of all reservations made for a specific day
    vector <Reservation> getAllReservationsAtDate(int index); //return a vector of all reservations made for a specific day (being given the day's number (n-th day of the year))
    vector <Reservation> getAllReservationsByName(std::string _name);
    int checkForID(int &ID); //does client exist in database? 1->yes
    int addReservation(Reservation &Reservation);//add reservation to the database but do not make reservation for the given time period
	int addReservationAtDate(dateTime &dt, int &ID);//be careful! adds a reservation only for a specific day, requires reservation existing in database
    int autoAddReservation(Reservation &reservation, bool affectGlobalConstants=true);//automatically adds a reservation, all included
};

