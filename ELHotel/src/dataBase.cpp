#include "../header/dataBase.h"

int dataBase::checkForID(int &ID)
{
	if (ID % 2 == 0)
	{
		for (int i = 0; i < Reservations.even.size(); i++)
		{
			if (Reservations.even[i].getID() == ID)
			{
				return 1;
			}
		}
	}
	else {
		for (int i = 0; i < Reservations.odd.size(); i++)
		{
			if (Reservations.odd[i].getID() == ID)
			{
				return 1;
			}
		}
	}
	return 0;
}

int dataBase::addReservation(Reservation &Reservation)
{
	if (Reservation.getID() % 2 == 0)
	{
		Reservations.even.push_back(Reservation);
	}
	else {
		Reservations.odd.push_back(Reservation);
	}
	globalConstants::next_index++;
	//globalConstants::save();
	return 0;
}

int dataBase::addReservationAtDate(dateTime &dt, int &ID)
{
	int which = dt.getDifference(dateTime(1, 1, globalConstants::globalConstants::thisYear),dt);
	daysOfYear[which].Reservation_ID.push_back(ID);
	return which;
}

int dataBase::autoAddReservation(Reservation &reservation)
{
	dateTime dt(1, 1, globalConstants::thisYear);
	addReservation(reservation);
	
	int arr = dt.getDifference(dt, reservation.getArrival());
	int dur = reservation.getDuration();

	for (int i = arr; i <= arr + dur; i++)
	{
		daysOfYear[i].Reservation_ID.push_back(reservation.getID());
	}
	return 0;
}

int dataBase::init(int year)
{
	if (year % 4 == 0 && year % 100 != 0 && year % 400 == 0)
	{
		dayMonths[2] = 29;
	}

	for (int i = 1; i < 13; i++)
	{
		for (int j = 0; j < dayMonths[i]; j++)
		{
			tuple temp;
			dateTime dt(j + 1, i, year);
			temp.date.set(dt);
			daysOfYear.push_back(temp);
		}
	}

	return 0;
}

vector <int> dataBase::getID(dateTime dt)
{
	return daysOfYear[dt.getDifference(dateTime(1, 1, globalConstants::thisYear), dt)].Reservation_ID;
}

Reservation dataBase::getReservationByID(int &ID)
{
	if (ID % 2 == 0)
	{
		for (int i = 0; i < Reservations.even.size(); i++)
		{
			if (Reservations.even[i].getID() == ID)
			{
				return Reservations.even[i];
			}
		}
	}
	else {
		for (int i = 0; i < Reservations.odd.size(); i++)
		{
			if (Reservations.odd[i].getID() == ID)
			{
				return Reservations.odd[i];
			}
		}
	}
	
	return Reservation();
}

vector<Reservation> dataBase::getAllReservationsAtDate(dateTime &dt)
{
	vector <int> ids = daysOfYear[dt.getDifference(dateTime(1, 1, globalConstants::thisYear), dt)].Reservation_ID;
	vector <Reservation> all;
	for (int i = 0; i < ids.size(); i++)
	{
		all.push_back(getReservationByID(ids[i]));
	}
	return all;
}
