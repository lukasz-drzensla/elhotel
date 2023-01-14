#include "../header/dataBase.h"

int dataBase::checkForID(int& ID)
{
    //go through the whole database (2 parts - even and odd), find the reservation with the given ID
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

int dataBase::addReservation(Reservation& Reservation)
{
    //brute force add reservation to the database (section depending on the parity)
	if (Reservation.getID() % 2 == 0)
	{
		Reservations.even.push_back(Reservation);
	}
	else {
		Reservations.odd.push_back(Reservation);
	}
	return 0;
}

int dataBase::addReservationAtDate(dateTime& dt, int& ID)
{
    //brute force add reservation to the calendar-oriented database
    int which = dt.getDifference(dateTime(1, 1, globalConstants::sharedVariables.thisYear), dt);
	daysOfYear[which].Reservation_ID.push_back(ID);
	return which;
}

int dataBase::autoAddReservation(Reservation& reservation, bool affectGlobalConstants)
{
    //the function actually used to add reservations
    //add the reservation to the database of reservations
    //for every single day occupied by reservation add at date
    dateTime dt(1, 1, globalConstants::sharedVariables.thisYear);
	addReservation(reservation);

	int arr = dt.getDifference(dt, reservation.getArrival());
	int dur = reservation.getDuration();

	for (int i = arr; i <= arr + dur; i++)
	{
		daysOfYear[i].Reservation_ID.push_back(reservation.getID());
	}
    if (affectGlobalConstants)
    {
        globalConstants::sharedVariables.next_index++;
        globalConstants::save();
    }
	return 0;
}

int dataBase::init(int year)
{
    //initialize the calendar-oriented database
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		dayMonths[2] = 29;
	}

	for (int i = 1; i < 13; i++)
	{
		for (int j = 0; j < dayMonths[i]; j++)
		{
			single_day temp;
			dateTime dt(j + 1, i, year);
			temp.date.set(dt);
			daysOfYear.push_back(temp);
		}
	}

    //add an empty reservation as first in the even section, to avoid ambiguity when checking for ID (0 is neither + or -)

    Reservation empty(-2, Room(), "Empty", dateTime(30, 2, 2022), dateTime(31, 2, 2022), "666-666-666",0, "0", 0);
    addReservation(empty);

	return 0;
}

int dataBase::load(bool LR)
{
    //shall I load the rooms database? - not always necessary
	if (LR)
	{
		loadRooms();
	}


    //read the reservations
	ifstream file("reservations.xml");
	if (!file.is_open())
		return -1;

	using std::string;
    string line{}; //we will be reading lines of our file here
	getline(file, line);
    if (line.starts_with("<?xml"))
	{
		//set encoding
	}
    bool newRow = false; //indicator if correct start of entry detected

    //variables for storing our data
	int _id{};
	int _room_id{};
	string _name{};
	dateTime _arrival{};
	dateTime _departure{};
	string _phone{};
	int _cost{};
	string _NIP{};
    int _status{};
    int _people{};
    string _comment{};
    int _paid{};

    //markers
	const string id_str = "<ID>";
	const string room_id_str = "<ROOM_ID>";
	const string name_str = "<NAME>";
	const string arr_str = "<ARRIVAL>";
	const string dep_str = "<DEPARTURE>";
	const string phone_str = "<PHONE>";
	const string cost_str = "<COST>";
	const string NIP_str = "<NIP>";
    const string status_str = "<STATUS>";
    const string people_str = "<PEOPLE>";
    const string comment_str = "<COMMENT>";
    const string paid_str = "<PAID>";

    //read the content of reservations database
	while (!file.eof())
	{
		getline(file, line);

		if (newRow)
		{
            if (line.starts_with("</Row"))
			{
				newRow = false;
				//add reservation

                //create a room variable
                Room room {};

                //check if the rooms exists, read all the room data
                for (int i = 0; i < rooms.size(); i++)
                {
                    if (rooms[i].id == _room_id)
                    {
                        room.id=rooms[i].id;
                        room.cost_rate=rooms[i].cost_rate;
                        room.description=rooms[i].description;
                        room.max_people=rooms[i].max_people;
                        break;
                    }
                }
                //if by any chance the ID is negative, skip it (a possibility to add technical negative IDs in the future)
                if (_id >=0){
                    Reservation res(_id, room, _name, _arrival, _departure, _phone, _cost, _NIP, _status, _people, _comment, _paid);
                    autoAddReservation(res, false);
                    //auto add to the database and DO NOT change the indexes count - because we only read what already exists
                }
			}
            else if (line.starts_with(id_str))
			{
                //read ID
				auto position = line.find('/');
				string temp = line.substr(id_str.length(), position - id_str.length() - 1);
				try
				{
					_id = std::stoi(temp);
				}
				catch (const std::exception&)
				{
					_id = 0;
				}
			}
            else if (line.starts_with(room_id_str)) {
                //read room ID
				auto position = line.find('/');
				string temp = line.substr(room_id_str.length(), position - room_id_str.length() - 1);
				try
				{
					_room_id = std::stoi(temp);
				}
				catch (const std::exception&)
				{
					_room_id = 0;
				}
			}
            else if (line.starts_with(name_str)) {
                //read the name
				auto position = line.find('/');
				_name = line.substr(name_str.length(), position - name_str.length() - 1);
			}
            else if (line.starts_with(arr_str))
			{
                //read the arrival date
				auto position = line.find('/');
				string temp = line.substr(arr_str.length(), position - arr_str.length() - 1);

				string d = "";
				d += temp[0];
				d += temp[1];
				string m = "";
				m += temp[4];
				m += temp[5];
				string y = "";
				y += temp[8];
				y += temp[9];
				y += temp[10];
				y += temp[11];
				try
				{
					dateTime dt(std::stoi(d), std::stoi(m), std::stoi(y));
					_arrival.set(dt);
				}
				catch (const std::exception&)
				{
					dateTime dt(1, 1, 2022);
					_arrival.set(dt);
				}
			}
            else if (line.starts_with(dep_str))
			{
                //read the departure date
				auto position = line.find('/');
				string temp = line.substr(dep_str.length(), position - dep_str.length() - 1);

				string d = "";
				d += temp[0];
				d += temp[1];
				string m = "";
				m += temp[4];
				m += temp[5];
				string y = "";
				y += temp[8];
				y += temp[9];
				y += temp[10];
				y += temp[11];
				try
				{
					dateTime dt(std::stoi(d), std::stoi(m), std::stoi(y));
					_departure.set(dt);
				}
				catch (const std::exception&)
				{
					dateTime dt(1, 1, 2022);
					_departure.set(dt);
				}
			}
            else if (line.starts_with(phone_str))
			{
                //read the phone number
				auto position = line.find('/');
				_phone = line.substr(phone_str.length(), position - phone_str.length() - 1);
			}
            else if (line.starts_with(cost_str))
			{
                //read the cost
				auto position = line.find('/');
				string temp = line.substr(cost_str.length(), position - cost_str.length() - 1);
				try
				{
					_cost = std::stoi(temp);
				}
				catch (const std::exception&)
				{
					_cost = 0;
				}
			}
            else if (line.starts_with(NIP_str))
			{
                //read NIP
				auto position = line.find('/');
				_NIP = line.substr(NIP_str.length(), position - NIP_str.length() - 1);
			}
            else if (line.starts_with(status_str))
            {
                //read the status
                auto position = line.find('/');
                string temp = line.substr(status_str.length(), position - status_str.length() - 1);
                try
                {
                    _status = std::stoi(temp);
                }
                catch (const std::exception&)
                {
                    _status = 0;
                }
            }
            else if (line.starts_with(people_str))
            {
                //read people count
                auto position = line.find('/');
                string temp = line.substr(people_str.length(), position - people_str.length() - 1);
                try
                {
                    _people = std::stoi(temp);
                }
                catch (const std::exception&)
                {
                    _people = 0;
                }
            }
            else if (line.starts_with(comment_str))
            {
                //read the reservation comment
                auto position = line.find('/');
                _comment = line.substr(comment_str.length(), position - comment_str.length() - 1);
            }
            else if (line.starts_with(paid_str))
            {
                //read how much has already been paid
                auto position = line.find('/');
                string temp = line.substr(paid_str.length(), position - paid_str.length() - 1);
                try
                {
                    _paid = std::stoi(temp);
                }
                catch (const std::exception&)
                {
                    _paid = 0;
                }
            }
		}
        else if (line.starts_with("<Row"))
		{
			//new row read
			newRow = true;
		}

	}

	file.close();
	return 1;
}

int dataBase::loadRooms()
{
    //read the rooms
	ifstream file("rooms.xml");
	if (!file.is_open())
		return -1;

	using std::string;
    //the variable which we will be reading to
	string line{};

    //get the first line, set encoding - to be developed
	getline(file, line);
    if (line.starts_with("<?xml"))
	{
		//set encoding
	}
    //indicator whether a valid start of entry was found
	bool newRoom = false;

    //variables for storing the read values
	int _id{};
	int _cost_rate{};
	string _description{};
	int _max_people;	

    //markers
	const string id_str = "<ID>";
	const string cost_rate_str = "<COST>";
	const string des_str = "<DES>";
	const string max_str = "<MAX>";
	
	while (!file.eof())
	{
		getline(file, line);

		if (newRoom)
		{
            if (line.starts_with("</Row"))
			{
				newRoom = false;
				//add room
				Room r(_id, _max_people, _description, _cost_rate);
				rooms.push_back(r);
			}
            else if (line.starts_with(id_str))
			{
                //read id
				auto position = line.find('/');
				string temp = line.substr(id_str.length(), position - id_str.length() - 1);
				try
				{
					_id = std::stoi(temp);
				}
				catch (const std::exception&)
				{
					_id = 0;
				}
			}
            else if (line.starts_with(cost_rate_str))
			{
                //read cost rate (price per night)
				auto position = line.find('/');
				string temp = line.substr(cost_rate_str.length(), position - cost_rate_str.length() - 1);
				try
				{
					_cost_rate = std::stoi(temp);
				}
				catch (const std::exception&)
				{
					_cost_rate = 0;
				}
			}
            else if (line.starts_with(des_str))
			{
                //read the description
				auto position = line.find('/');
				_description = line.substr(des_str.length(), position - des_str.length() - 1);
			}
            else if (line.starts_with(max_str))
			{
                //read the max number of people
				auto position = line.find('/');
				string temp = line.substr(max_str.length(), position - max_str.length() - 1);
				try
				{
					_max_people = std::stoi(temp);
				}
				catch (const std::exception&)
				{
					_max_people = 0;
				}
			}
		}
        else if (line.starts_with("<Row"))
		{
			newRoom = true;
		}
	}

	return 1;
}

int dataBase::saveRooms()
{
    //save the rooms in xml format
    using std::string, std::endl;
    ofstream file;
    file.open("rooms.xml", ofstream::out | ofstream::trunc);
    file.close();

    file.open("rooms.xml");

    if (!file.is_open())
        return -2;
    file << "<?xml version = \"1.0\" encoding = \"utf-8\"?><root><worksheet name = \"rooms\">" << endl;
    for (int i = 0; i < rooms.size(); i++)
    {
        file << "<Row index=\"";
        file << i;
        file << "\">" << endl;
        file << "<ID>";
        file << rooms[i].id;
        file << "</ID>" << endl;
        file << "<COST>";
        file << rooms[i].cost_rate;
        file << "</COST>" << endl;
        file << "<DES>";
        file << rooms[i].description;
        file << "</DES>" << endl;
        file << "<MAX>";
        file << rooms[i].max_people;
        file << "</MAX>" << endl;
        file << "</Row>" << endl;
    }
    file << "</worksheet>" << endl << "</root>" << endl;
    file.close();
    return 1;
}

int dataBase::save(bool SR)
{
    //save the reservations
	using std::endl;
	ofstream file;
	file.open("reservations.xml", ofstream::out | ofstream::trunc);
	file.close();

	file.open("reservations.xml");

	if (!file.is_open())
		return -1;

	file << "<?xml version = \"1.0\" encoding = \"utf-8\"?><root><worksheet name = \"reservations\">" << endl;
    for (int i = 1; i < Reservations.even.size(); i++)
	{
		file << "<Row index=\"";
		file << i;
		file << "\">" << endl;
		file << "<ID>";
		file << Reservations.even[i].getID();
		file << "</ID>" << endl;
		file << "<ROOM_ID>";
		file << Reservations.even[i].getRoom().id;
		file << "</ROOM_ID>" << endl;
		file << "<NAME>";
		file << Reservations.even[i].getName();
		file << "</NAME>" << endl;
		file << "<ARRIVAL>";
		file << Reservations.even[i].getArrival().sayHello();
		file << "</ARRIVAL>" << endl;
		file << "<DEPARTURE>";
		file << Reservations.even[i].getDeparture().sayHello();
		file << "</DEPARTURE>" << endl;
		file << "<PHONE>";
		file << Reservations.even[i].getPhone();
		file << "</PHONE>" << endl;
		file << "<COST>";
		file << Reservations.even[i].getCost();
		file << "</COST>" << endl;
		file << "<NIP>";
		file << Reservations.even[i].getNIP();
		file << "</NIP>" << endl;
        file << "<STATUS>";
        int x = Reservations.even[i].getStatus();
        file << x;
        file << "</STATUS>" << endl;
        file << "<PEOPLE>";
        file << Reservations.even[i].getPeople();
        file << "</PEOPLE>" << endl;
        file << "<COMMENT>";
        file << Reservations.even[i].getComment();
        file << "</COMMENT>" << endl;
        file << "<PAID>";
        file << Reservations.even[i].getPaid();
        file << "</PAID>" << endl;
		file << "</Row>" << endl;
	}

	for (int i = 0; i < Reservations.odd.size(); i++)
	{
		file << "<Row index=\"";
		file << i + Reservations.even.size();
		file << "\">" << endl;
		file << "<ID>";
		file << Reservations.odd[i].getID();
		file << "</ID>" << endl;
		file << "<ROOM_ID>";
		file << Reservations.odd[i].getRoom().id;
		file << "</ROOM_ID>" << endl;
		file << "<NAME>";
		file << Reservations.odd[i].getName();
		file << "</NAME>" << endl;
		file << "<ARRIVAL>";
		file << Reservations.odd[i].getArrival().sayHello();
		file << "</ARRIVAL>" << endl;
		file << "<DEPARTURE>";
		file << Reservations.odd[i].getDeparture().sayHello();
		file << "</DEPARTURE>" << endl;
		file << "<PHONE>";
		file << Reservations.odd[i].getPhone();
		file << "</PHONE>" << endl;
		file << "<COST>";
		file << Reservations.odd[i].getCost();
		file << "</COST>" << endl;
		file << "<NIP>";
		file << Reservations.odd[i].getNIP();
		file << "</NIP>" << endl;
        file << "<STATUS>";
        int x = Reservations.odd[i].getStatus();
        file << x;
        file << "</STATUS>" << endl;
        file << "<PEOPLE>";
        file << Reservations.odd[i].getPeople();
        file << "</PEOPLE>" << endl;
        file << "<COMMENT>";
        file << Reservations.odd[i].getComment();
        file << "</COMMENT>" << endl;
        file << "<PAID>";
        file << Reservations.odd[i].getPaid();
        file << "</PAID>" << endl;
		file << "</Row>" << endl;
	}

	file << "</worksheet>" << endl << "</root>" << endl;
	file.close();

    //shall I also save the rooms?
	if (SR)
	{
        saveRooms();
	}
	file.close();
	return 1;
}

vector <int> dataBase::getID(dateTime dt)
{
    //returns the vector of all reservation ID saved for a specific day in the year
    return daysOfYear[dt.getDifference(dateTime(1, 1, globalConstants::sharedVariables.thisYear), dt)].Reservation_ID;
}

Reservation dataBase::getReservationByID(int& ID)
{
    //return a reservation being given its ID
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

int dataBase::getDBIDByResID(int ID)
{
    //return the index at which the reservation is stored in the database. Warning: this is about the database vector, it is not unique, may differ every single run of the program
    //negative for even, 0 or positive for odd
    if (ID % 2 == 0)
    {
        for (int i = 0; i < Reservations.even.size(); i++)
        {
            if (Reservations.even[i].getID() == ID)
            {
                return -i;
            }
        }
    }
    else {
        for (int i = 0; i < Reservations.odd.size(); i++)
        {
            if (Reservations.odd[i].getID() == ID)
            {
                    return i;
            }
        }
    }

    return 0;
}

vector<Reservation> dataBase::getAllReservationsAtDate(dateTime& dt)
{
    //return a vector of all reservations made for a specific day
    vector <int> ids = daysOfYear[dt.getDifference(dateTime(1, 1, globalConstants::sharedVariables.thisYear), dt)].Reservation_ID;
    vector <Reservation> all{};
	for (int i = 0; i < ids.size(); i++)
	{
		all.push_back(getReservationByID(ids[i]));
	}
	return all;
}

vector<Reservation> dataBase::getAllReservationsAtDate(int index)
{
    //return a vector of all reservations made for a specific day (being given the day's number (n-th day of the year))
    vector <int> ids = daysOfYear[index].Reservation_ID;
    vector <Reservation> all{};
    for (int i = 0; i < ids.size(); i++)
    {
        all.push_back(getReservationByID(ids[i]));
    }
    return all;
}



vector <Reservation> dataBase::getAllReservationsByName(std::string _name)
{
    //change a string to lowercase
    auto to_lower = [](std::string str)
    {
        std::string temp{};
        for (int i = 0; i < str.size(); i++)
        {
            char t = str[i];
            if (int (t) > 96 && int(t) < 123)
            {
                t-=32;
            }
            temp+=t;
        }
        return temp;
    };

    //search for reservations in which names contain certain string, ignore case
    vector <Reservation> all{};
    for (int i = 0; i < Reservations.even.size(); i++)
    {
        std::string temp = to_lower(Reservations.even[i].getName());
        _name = to_lower(_name);
        if (temp.find(_name) != std::string::npos)
        {
            if (Reservations.even[i].getID()>=0)
                all.push_back(Reservations.even[i]);
        }
    }
    for (int i = 0; i < Reservations.odd.size(); i++)
    {
        std::string temp = to_lower(Reservations.odd[i].getName());
        _name = to_lower(_name);
        if (temp.find(_name) != std::string::npos)
        {
            if (Reservations.odd[i].getID()>=0)
                all.push_back(Reservations.odd[i]);
        }
    }
    return all;
}


vector <Reservation> dataBase::getAllReservationsByPhone(std::string _phone)
{
    //remove all characters which are not numbers - including slashes, spaces etc
    auto remove_non_numbers =[](std::string str)
    {
        std::string temp{};
        for (int i = 0; i < str.size(); i++)
        {
            char t = str[i];
            if (int (t) > 47 && int(t) < 58)
            {
                temp+=t;
            }
        }
        return temp;
    };

    //search for reservations in which names contain certain string, ignore non-number characters
    vector <Reservation> all{};
    for (int i = 0; i < Reservations.even.size(); i++)
    {
        std::string temp = remove_non_numbers(Reservations.even[i].getPhone());
        _phone = remove_non_numbers(_phone);
        if (temp.find(_phone) != std::string::npos)
        {
            if (Reservations.even[i].getID()>=0)
                all.push_back(Reservations.even[i]);
        }
    }
    for (int i = 0; i < Reservations.odd.size(); i++)
    {
        std::string temp = remove_non_numbers(Reservations.odd[i].getPhone());
        _phone = remove_non_numbers(_phone);
        if (temp.find(_phone) != std::string::npos)
        {
            if (Reservations.odd[i].getID()>=0)
                all.push_back(Reservations.odd[i]);
        }
    }
    return all;
}
