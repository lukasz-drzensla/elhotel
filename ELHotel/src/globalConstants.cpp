#include "../header/globalConstants.h"

void globalConstants::save()
{
	std::ofstream file;
	file.open("config.txt", std::ofstream::out | std::ofstream::trunc);
	file.close();

	file.open("config.txt");
    file << sharedVariables.roomRate << std::endl << sharedVariables.thisYear << std::endl << sharedVariables.next_index << std::endl << sharedVariables.next_room_index;
	file.close();
}
