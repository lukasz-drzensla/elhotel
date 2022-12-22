#pragma once
#include <string>
#include "dateTime.h"
#include "globalConstants.h"
#include "Room.h"

class Reservation
{
public:
	Reservation();
	Reservation(int _ID, Room _room, std::string _name, dateTime _arrival, dateTime _departure, std::string _phone_number, int _cost=0, std::string _NIP="0");
	int getID();
	Room getRoom();
	std::string getName();
	dateTime getArrival();
	dateTime getDeparture();
	std::string getPhone();
	int getCost();
	std::string getNIP();
	int getDuration();
	std::string sayHello();
	Reservation operator = (Reservation const& obj)
	{
		return obj;
	}
private:
	int ID{};
	Room room{};
	std::string name{};
	dateTime arrival{};
	dateTime departure{};
	std::string phone_number{};
	int cost{};
	std::string NIP{};	
};
