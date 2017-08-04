#include "CmakeOption.h"

CmakeOption::CmakeOption(const QString &name, const QString &description, const CmakeOptionState &state)
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
	CmakeOptionString stringer;
	stream << "option(" << option._name.toStdString() << " "
		<< "\"" << option._desc.toStdString() << "\" " << stringer(option._state) <<")";
	return stream;
}

