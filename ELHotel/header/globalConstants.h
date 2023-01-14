#pragma once
#include <fstream>
class globalConstants
{

public:
	static int roomRate;
    static int thisYear;
	static int next_index;
    static int next_room_index;
	static void save();
    struct shared_variables{
        int roomRate{};
        int thisYear{};
        int next_index{};
        int next_room_index{};
    };
    static shared_variables sharedVariables;
};

