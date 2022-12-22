#pragma once
#include <vector>
#include "Reservation.h"
#include "dateTime.h"
#include "globalConstants.h"
#include "Room.h"

using std::vector;
class dataBase
{
private:
	int dayMonths[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	struct tuple {
		dateTime date{};
		vector <int> Reservation_ID{};
	};
	struct res
	{
		vector <Reservation> even{};
		vector <Reservation> odd{};
	};
	vector <tuple> daysOfYear{};
	res Reservations{};
	
public:
	int init(int year);
	int load();
	int save();
	vector <Room> rooms{ Room(0, 4, "101"), Room(1, 6, "102", 200) };
	vector <int> getID(dateTime dt);
	Reservation getReservationByID(int &ID);
	vector <Reservation> getAllReservationsAtDate(dateTime &dt); //return a vector of all reservations made for a specific day
	int checkForID(int &ID); //does client exist in database? 1->yes
	int addReservation(Reservation &Reservation);//add reservation to the database but do not make reservation for the given time period
	int addReservationAtDate(dateTime &dt, int &ID);//be careful! adds a reservation only for a specific day, requires reservation existing in database
	int autoAddReservation(Reservation &reservation);//automatically adds a reservation, all included
};

