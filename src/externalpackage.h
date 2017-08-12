#pragma once
#include <vector>
#include <json.hpp>
namespace {
	struct ExternalPackage
	{
		std::string name{ "" };
		std::vector<std::string> versions;
		std::vector<std::string> components;
		bool hasComponents{ false };
		bool isHeaderOnly{ false };
		std::string externalAddScript{ "" };
	};

	void to_json(nlohmann::json& j, const ExternalPackage& ep) {
		j = nlohmann::json{ { "name", ep.name },
		{ "versions", ep.versions },
		{ "components", ep.components },
		{ "hasComponents", ep.hasComponents },
		{ "headerOnly", ep.isHeaderOnly },
		{ "externalAddScript", ep.externalAddScript } };
	}

	void from_json(const nlohmann::json& j, ExternalPackage& p)
	{
		p.name = j["name"].get<std::string>();
		p.versions = j["versions"].get<std::vector<std::string>>();
		p.components = j["components"].get<std::vector<std::string>>();
		p.hasComponents = j["hasComponents"].get<bool>();
		p.isHeaderOnly = j["headerOnly"].get<bool>();
		p.externalAddScript = j["externalAddScript"].get<std::string>();
	}
}
