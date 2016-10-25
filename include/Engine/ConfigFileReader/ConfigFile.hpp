#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <map>


// Config File class
// One config - one file!
// File structure:
// name
// {
// some_cool_downcase = I DONT mind DOWNCASE!!!
// some_COOL_value = 9
// }
class ConfigFile
{
private:
	bool parsePrecheck();

public:
	ConfigFile();
	ConfigFile(const std::string & filePath, bool parse);

	// Returns section name
	std::string GetName();
	// Returns data from given key
	// Returns "@none" if cannot find
	std::string GetData(const std::string & key);
	// Return amount of all data stored
	unsigned short GetAmountOfData();

	// Sets section name 
	void SetName(const std::string & name);
	// Adds data to container
	// Returns false if specified key already existed
	// Override = true, returns true if specified key already existed
	bool AddData(const std::string & key, const std::string & val, bool override);

	// Loads file
	// Returns false if:
	// * data is not empty
	// * file does not exist
	// * parse fail (no section name, no {} or var have no val
	bool LoadFromFile(const std::string & filePath, bool parse);
	// Parse the file
	// Returns false if no section name, no {} or var have no val
	bool Parse();
	// Saves data to file.
	// Returns false if specified file already existed
	// Override = true, returns true if specified file already existed
	bool SaveToFile(const std::string & filePath, bool override);
	// Cleans data, sets name to @none
	void Clear();

private:
	// Is parsed?
	bool m_parsed;
	// Section name
	std::string m_name;

	// Stores parsed data:
	// NAME - VALUE
	// hello - true
	std::map< std::string, std::string > m_data;
	// Stores raw file data
	std::vector< std::string > m_raw;
};

