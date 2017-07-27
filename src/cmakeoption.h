#pragma once

#include <string>

class CmakeOption
{	
public:
	enum class cmake_option_state
	{
		ON,
		OFF
	};
	CmakeOption(const std::string &name, const std::string &description, const cmake_option_state &defalut_state = cmake_option_state::OFF);
	CmakeOption(const CmakeOption &other);
	CmakeOption& operator=(const CmakeOption& other);
	friend std::ostream& operator<<(std::ostream& stream, const CmakeOption &option);

private:
	std::string _name;
	std::string _desc;
	cmake_option_state _state;
};

struct cmake_option_string
{
	std::string operator()(const CmakeOption::cmake_option_state &state) const
	{
		return state == CmakeOption::cmake_option_state::ON ? "ON" : "OFF";
	}
};