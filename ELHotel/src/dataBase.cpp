#include "../header/dataBase.h"

int dataBase::checkForID(int& ID)
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

int dataBase::addReservation(Reservation& Reservation)
{
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
	int which = dt.getDifference(dateTime(1, 1, globalConstants::globalConstants::thisYear), dt);
	daysOfYear[which].Reservation_ID.push_back(ID);
	return which;
}

int dataBase::autoAddReservation(Reservation& reservation, bool affectGlobalConstants)
{
	dateTime dt(1, 1, globalConstants::thisYear);
	addReservation(reservation);

	int arr = dt.getDifference(dt, reservation.getArrival());
	int dur = reservation.getDuration();

	for (int i = arr; i <= arr + dur; i++)
	{
		daysOfYear[i].Reservation_ID.push_back(reservation.getID());
	}
    if (affectGlobalConstants)
    {
        globalConstants::next_index++;
        globalConstants::save();
    }
	return 0;
}

int dataBase::init(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
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

    Reservation empty(-2, Room(), "Empty", dateTime(30, 2, 2022), dateTime(31, 2, 2022), "666-666-666",0, "0", 0);
    addReservation(empty);

	return 0;
}

int dataBase::load(bool LR)
{
	if (LR)
	{
		loadRooms();
	}
    //globalConstants::next_index = 0;
	ifstream file("reservations.xml");
	if (!file.is_open())
		return -1;

	using std::string;
	string line{};
	getline(file, line);
    if (line.starts_with("<?xml"))
	{
		//set encoding
	}
	bool newRow = false;
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
	while (!file.eof())
	{
		getline(file, line);

		if (newRow)
		{
            if (line.starts_with("</Row"))
			{
				newRow = false;
				//add reservation
                Room room {};

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
                if (_id >=0){
                    Reservation res(_id, room, _name, _arrival, _departure, _phone, _cost, _NIP, _status, _people, _comment, _paid);
                    autoAddReservation(res, false);
                }
			}
            else if (line.starts_with(id_str))
			{
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
				auto position = line.find('/');
				_name = line.substr(name_str.length(), position - name_str.length() - 1);
			}
            else if (line.starts_with(arr_str))
			{
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
				auto position = line.find('/');
				_phone = line.substr(phone_str.length(), position - phone_str.length() - 1);
			}
            else if (line.starts_with(cost_str))
			{
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
				auto position = line.find('/');
				_NIP = line.substr(NIP_str.length(), position - NIP_str.length() - 1);
			}
            else if (line.starts_with(status_str))
            {
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
                auto position = line.find('/');
                _comment = line.substr(comment_str.length(), position - comment_str.length() - 1);
            }
            else if (line.starts_with(paid_str))
            {
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
	ifstream file("rooms.xml");
	if (!file.is_open())
		return -1;

	using std::string;
	string line{};
	getline(file, line);
    if (line.starts_with("<?xml"))
	{
		//set encoding
	}
	bool newRoom = false;
	int _id{};
	int _cost_rate{};
	string _description{};
	int _max_people;
	
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
				auto position = line.find('/');
				_description = line.substr(des_str.length(), position - des_str.length() - 1);
			}
            else if (line.starts_with(max_str))
			{
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


	if (SR)
	{
        saveRooms();
	}
	file.close();
	return 1;
}

vector <int> dataBase::getID(dateTime dt)
{
	return daysOfYear[dt.getDifference(dateTime(1, 1, globalConstants::thisYear), dt)].Reservation_ID;
}

Reservation dataBase::getReservationByID(int& ID)
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

int dataBase::getDBIDByResID(int ID)
{
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
	vector <int> ids = daysOfYear[dt.getDifference(dateTime(1, 1, globalConstants::thisYear), dt)].Reservation_ID;
	vector <Reservation> all;
	for (int i = 0; i < ids.size(); i++)
	{
		all.push_back(getReservationByID(ids[i]));
	}
	return all;
}

vector<Reservation> dataBase::getAllReservationsAtDate(int index)
{
    vector <int> ids = daysOfYear[index].Reservation_ID;
    vector <Reservation> all;
    for (int i = 0; i < ids.size(); i++)
    {
        all.push_back(getReservationByID(ids[i]));
    }
    return all;
}
