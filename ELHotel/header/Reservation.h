#pragma once
#include <string>
#include "dateTime.h"
#include "globalConstants.h"
#include "Room.h"

class Reservation
{
public:
	Reservation();
    Reservation(int _ID, Room _room, std::string _name, dateTime _arrival, dateTime _departure, std::string _phone_number, int _cost, std::string _NIP, int _status, int _people=0, std::string _comment="", int _paid=0);
	int getID();
	Room getRoom();
	std::string getName();
	dateTime getArrival();
	dateTime getDeparture();
	std::string getPhone();
	int getCost();
	std::string getNIP();
	int getDuration();
    int getStatus();
    int getPeople();
    void setStatus(int _status);
    std::string getComment();
	std::string sayHello();
    int getPaid();
    int setPaid(int money);
    int set(Reservation res);
	Reservation operator = (Reservation const& obj)
	{
		return obj;
	}
private:
    std::string stat_str[6] = {"Undetermined", "Arrived and paid", "Departed", "Requires attention", "Arrived but did not pay", "Departed but did not pay"};
	int ID{};
	Room room{};
	std::string name{};
	dateTime arrival{};
	dateTime departure{};
	std::string phone_number{};
	int cost{};
	std::string NIP{};	
    int status{};
    int people{};
    std::string comment{};
    int paid{};
};

