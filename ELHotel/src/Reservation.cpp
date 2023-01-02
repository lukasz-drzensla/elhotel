#include "../header/Reservation.h"

Reservation::Reservation()
{
}

Reservation::Reservation(int _ID, Room _room, std::string _name, dateTime _arrival, dateTime _departure, std::string _phone_number, int _cost, std::string _NIP, int _status, int _people, std::string _comment) {
    ID = _ID; room.id = _room.id; room.cost_rate = _room.cost_rate; room.description = _room.description; room.max_people = _room.max_people; name = _name; arrival.set(_arrival); departure.set(_departure); phone_number = _phone_number; if (_cost == 0) { cost = arrival.getDifference(arrival, departure) * _room.cost_rate; status = _status; people = _people; comment=_comment;}
	else cost = _cost; NIP = _NIP;
}

int Reservation::getID()
{
	return ID;
}

Room Reservation::getRoom()
{
	return room;
}

std::string Reservation::getName()
{
	return name;
}

dateTime Reservation::getArrival()
{
	return arrival;
}

dateTime Reservation::getDeparture()
{
	return departure;
}

std::string Reservation::getPhone()
{
	return phone_number;
}

int Reservation::getCost()
{
	return cost;
}

std::string Reservation::getNIP()
{
	return NIP;
}

int Reservation::getDuration()
{
	return arrival.getDifference(arrival, departure);
}

std::string Reservation::sayHello()
{
	return "ID: " + std::to_string(ID) + " Name: " + name + " Cost: " + std::to_string(cost) + " Room: " + room.description + " Arrival: " + arrival.sayHello() + " Departure: " + departure.sayHello();
}

int Reservation::getStatus()
{
    return status;
}

int Reservation::getPeople()
{
    return people;
}

std::string Reservation::getComment()
{
    return comment;
}

void Reservation::setStatus(int _status)
{
    status = _status;
}
