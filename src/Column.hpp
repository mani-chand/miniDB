#ifndef COLUMN_HPP
#define COLUMN_HPP
#include <iostream>
#include <iostream>
#include <string>
enum class DataType
{
	INTEGER,
	TEXT,
	BOOLEAN
};

class Column
{
private:
	std::string name;
	DataType type;
	std::string getTypeName() const
	{
		switch (type)
		{
		case DataType::INTEGER:
			return "INTEGER";

		// TODO: Handle TEXT
		case DataType::TEXT:
			return "TEXT";

		// TODO: Handle BOOLEAN
		case DataType::BOOLEAN:
			return "BOOLEAN";
		}

		return "UNKNOWN";
	}

public:
	Column(const std::string &name, DataType type) : name(name), type(type) {}

	const std::string &getName() const
	{
		return name;
	}
	DataType getType() const
	{
		return type;
	}
	void display() const
	{
		std::cout << "Column: " << name << " Type: " << getTypeName() << "\n";
	}
};
#endif
