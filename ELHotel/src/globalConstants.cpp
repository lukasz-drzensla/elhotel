#include "../header/globalConstants.h"

void globalConstants::save()
{
	std::ofstream file;
	file.open("config.txt", std::ofstream::out | std::ofstream::trunc);
	file.close();

	file.open("config.txt");
    file << roomRate << std::endl << thisYear << std::endl << next_index << std::endl << next_room_index;
	file.close();
}
