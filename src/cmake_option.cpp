#include "cmake_option.h"

cmake_option::cmake_option(const std::string &name, const std::string &description, const cmake_option_state &state)
	: _name(name), _desc(description), _state(state)
{
	
}

cmake_option::cmake_option(const cmake_option& other)
{
	_name = other._name;
	_desc = other._desc;
	_state = other._state;
}

cmake_option& cmake_option::operator=(const cmake_option& other)
{
	_name = other._name;
	_desc = other._desc;
	_state = other._state;
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const cmake_option& option) {
	cmake_option_string stringer;
	stream << "option(" << option._name << " "
		<< "\"" << option._desc << "\" " << stringer(option._state) <<")";
	return stream;
}

