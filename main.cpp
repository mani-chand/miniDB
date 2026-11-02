#include <iostream>
#include "src/Column.hpp" // Change to .hpp if Column follows the same pattern
#include "src/Row.hpp"	  // Directly includes the full Row layout
#include "src/Table.hpp"  // Directly includes the full Row layout
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	Row r;
	r.addValue(std::string("mani"));
	r.addValue(20);
	r.addValue(true);

	Table t1(std::string("users"));
	t1.addColumn(std::string("Name"), DataType::TEXT);
	t1.addColumn(std::string("age"), DataType::INTEGER);
	t1.addColumn(std::string("is_alive"), DataType::BOOLEAN);
	if (t1.insertRow(r)) {
		std::cout << "Row inserted successfully\n";
	} else {
		std::cout << "Row insertion failed\n";
	}
	Row invalidRow;
	invalidRow.addValue(std::string("mani"));
	invalidRow.addValue(std::string("twenty"));
	invalidRow.addValue(true);

	if (t1.insertRow(invalidRow)) {
		std::cout << "Row inserted successfully\n";
	} else {
		std::cout << "Row insertion failed\n";
	}
	t1.display();
	return 0;
}
