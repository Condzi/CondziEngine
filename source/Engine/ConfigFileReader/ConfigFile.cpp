#include "Engine/ConfigFileReader/ConfigFile.hpp"


bool ConfigFile::parsePrecheck()
{
	// 1 - name, 2 - opening bracket, 3 - closing bracket 
	// Nothing to parse
	if (m_raw.size() < 3)
	{
		return false;
	}
	// Missing name
	if (m_raw[0] == "" ||
		m_raw[0] == "{")
	{
		return false;
	}
	// Missing opening bracket
	if (m_raw[1] != "{")
	{
		return false;
	}
	// Missing close bracket
	if (m_raw[m_raw.size() - 1] != "}")
	{
		return false;
	}

	return true;
}

ConfigFile::ConfigFile()
{
	m_parsed = false;
	m_name = "@none";
}

ConfigFile::ConfigFile(const std::string & filePath, bool parse)
{
	ConfigFile();
	LoadFromFile(filePath, parse);
}

std::string ConfigFile::GetName()
{
	return m_name;
}

std::string ConfigFile::GetData(const std::string & key)
{
	bool foundKey = !(m_data.find(key) == m_data.end());

	if (!foundKey)
	{
		return "@none";
	}

	return m_data[key];
}

std::string ConfigFile::GetData(const unsigned short & val)
{
	unsigned short counter = 0;
	for (auto it = m_data.begin(); it != m_data.end(); ++it)
	{
		if (counter == val)
		{
			return m_data[it->first];
		}

		m_data[it->first];
		m_data[it->second];

		++counter;
	}

	return "@none";
}

unsigned short ConfigFile::GetAmountOfData()
{
	return m_data.size();
}

void ConfigFile::SetName(const std::string & name)
{
	m_name = name;
}

bool ConfigFile::AddData(const std::string & key, const std::string & val, bool override)
{
	bool foundKey = !(m_data.find(key) == m_data.end());

	if (foundKey && !override)
	{
		return false;
	}

	m_data[key] = val;

	return true;
}

bool ConfigFile::LoadFromFile(const std::string & filePath, bool parse)
{
	std::ifstream file(filePath);

	if (!file.good() ||
		m_data.size() ||
		m_raw.size())
	{
		return false;
	}

	std::string line = "";

	while (std::getline(file, line))
	{
		if (line.empty())
		{
			continue;
		}

		m_raw.push_back(line);
	}

	if (parse)
	{
		return Parse();
	}

	return true;
}

bool ConfigFile::Parse()
{
	// Error check
	if (!parsePrecheck())
	{
		return false;
	}

	std::string key = "";
	std::string data = "";

	m_name = m_raw[0];

	// -1 because 1 line for closing bracket
	// i = 4 because file starts at line 1, + 1 for name and + 1 for name
	for (unsigned int i = 2; i < m_raw.size() - 1; ++i)
	{
		// Var not assign
		if (m_raw[i].find('=') == std::string::npos ||
			m_raw[i][m_raw[i].find('=') + 2] == ' ')
		{
			return false;
		}

		key = m_raw[i].substr(0, m_raw[i].find(" = "));
		data = m_raw[i].substr(m_raw[i].find(" = ") + 3);

		m_data[key] = data;
	}

	m_parsed = true;
	return true;
}

bool ConfigFile::SaveToFile(const std::string & filePath, bool override)
{
	if (m_name == "@none" ||
		!m_name.size() ||
		m_name == " " ||
		!m_data.size())
	{
		return false;
	}

	// Checking is file existing in other scope
	{
		std::ifstream file(filePath);
		if (file.good() && !override)
		{
			return false;
		}
	}

	std::ofstream file(filePath);
	std::vector< std::string > keys;
	std::vector< std::string > values;


	for (auto it = m_data.begin(); it != m_data.end(); ++it)
	{
		keys.push_back(it->first);
		values.push_back(it->second);
	}

	file << m_name << "\n";
	file << "{" << "\n";

	for (unsigned int i = 0; i < m_data.size(); ++i)
	{
		file << keys[i];
		file << " = ";
		file << values[i] << "\n";
	}

	file << "}";

	return true;
}

void ConfigFile::Clear()
{
	m_name = "@none";
	m_data.clear();
	m_raw.clear();
}
