#include "CmakeOption.h"

CmakeOption::CmakeOption(const std::string &name, const std::string &description, const cmake_option_state &state)
	: _name(name), _desc(description), _state(state)
{
	
}

CmakeOption::CmakeOption(const CmakeOption& other)
{
	_name = other._name;
	_desc = other._desc;
	_state = other._state;
}

CmakeOption& CmakeOption::operator=(const CmakeOption& other)
{
	_name = other._name;
	_desc = other._desc;
	_state = other._state;
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const CmakeOption& option) {
	cmake_option_string stringer;
	stream << "option(" << option._name << " "
		<< "\"" << option._desc << "\" " << stringer(option._state) <<")";
	return stream;
}

