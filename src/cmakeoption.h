#pragma once

#include <string>
#include <QString>

class CmakeOption
{	
public:
	enum class CmakeOptionState
	{
		ON,
		OFF
	};
	CmakeOption(const QString &name, const QString &description, const CmakeOptionState &defalut_state = CmakeOptionState::OFF);
	CmakeOption(const CmakeOption &other);
	CmakeOption& operator=(const CmakeOption& other);
	friend std::ostream& operator<<(std::ostream& stream, const CmakeOption &option);

private:
	QString _name;
	QString _desc;
	CmakeOptionState _state;
};

struct CmakeOptionString
{
	std::string operator()(const CmakeOption::CmakeOptionState &state) const
	{
		return state == CmakeOption::CmakeOptionState::ON ? "ON" : "OFF";
	}
};