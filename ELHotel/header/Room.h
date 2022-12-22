#pragma once
#include <string>
#include "globalConstants.h"
class Room
{
public:
	int id{};
	int max_people{};
	std::string description{};

	int cost_rate{};

	Room();
	Room(int _id, int _max_people, std::string _description);
	Room(int _id, int _max_people, std::string _description, int _cost_rate);
	Room operator=(const Room& r)
	{
		return r;
	}
	~Room();
};

