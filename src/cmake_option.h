#pragma once

#include <string>

class cmake_option
{	
public:
	enum class cmake_option_state
	{
		ON,
		OFF
	};
	cmake_option(const std::string &name, const std::string &description, const cmake_option_state &defalut_state = cmake_option_state::OFF);
	cmake_option(const cmake_option &other);
	cmake_option& operator=(const cmake_option& other);
	friend std::ostream& operator<<(std::ostream& stream, const cmake_option &option);

private:
	std::string _name;
	std::string _desc;
	cmake_option_state _state;
};

struct cmake_option_string
{
	std::string operator()(const cmake_option::cmake_option_state &state) const
	{
		return state == cmake_option::cmake_option_state::ON ? "ON" : "OFF";
	}
};