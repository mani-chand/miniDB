#include <iostream>
#include "src/Column.hpp" // Change to .hpp if Column follows the same pattern
#include "src/Row.hpp"	  // Directly includes the full Row layout
#include "src/Table.hpp"  // Directly includes the full Row layout
#include "src/Database.hpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	Database db("company_db");

	db.createTable("users");
	db.createTable("products");
	db.createTable("orders");

	std::cout << std::boolalpha;

	// Test 1: Normal rename
	std::cout << "Test 1: "
			  << db.renameTable("users", "customers") << '\n';

	// Test 2: Duplicate name
	std::cout << "Test 2: "
			  << db.renameTable("users", "products") << '\n';

	// Test 3: Same name
	std::cout << "Test 3: "
			  << db.renameTable("customers", "customers") << '\n';

	// Test 4: Non-existent table
	std::cout << "Test 4: "
			  << db.renameTable("unknown", "new_table") << '\n';

	// Test 5: Empty new name
	std::cout << "Test 5: "
			  << db.renameTable("customers", "") << '\n';

	std::cout << "\nRemaining tables:\n";
	db.displayTables();

	return 0;
}
