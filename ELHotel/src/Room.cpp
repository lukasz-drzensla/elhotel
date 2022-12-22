#include "../header/Room.h"

Room::Room()
{

}

Room::Room(int _id, int _max_people, std::string _description)
{
	id = _id;
	max_people = _max_people;
	description = _description;
	cost_rate = globalConstants::roomRate;
}

Room::Room(int _id, int _max_people, std::string _description, int _cost_rate)
{
	id = _id;
	max_people = _max_people;
	description = _description;
	cost_rate = _cost_rate;
}


Room::~Room()
{
}
