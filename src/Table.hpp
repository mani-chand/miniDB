#ifndef TABLE_HPP
#define TABLE_HPP
#include "Column.hpp"
#include "Row.hpp"
#include <iostream>
#include <variant>
#include <vector>
#include <string>
class Table
{
private:
    std::string name;
    std::vector<Column> columns;
    std::vector<Row> rows;

public:
    // Your implementation
    Table(const std::string &table_name): name(table_name){}
    void addColumn(const std::string &name, DataType type) {
        Column c(name,type);
        columns.push_back(c);
    }
    bool insertRow(const Row& row) {
        if (row.size() != columns.size()) {
            std::cout << "Expected values: " << columns.size()
                    << ", but got: " << row.size() << '\n';
            return false;
        }

        for (std::size_t idx = 0; idx < columns.size(); idx++) {
            DataType type = columns[idx].getType();

            const Value& val = row.getValue(idx);

            bool valid = false;

            if (type == DataType::BOOLEAN) {
                valid = std::holds_alternative<bool>(val);
            }
            else if (type == DataType::TEXT) {
                valid = std::holds_alternative<std::string>(val);
            }
            else if (type == DataType::INTEGER) {
                valid = std::holds_alternative<int>(val);
            }

            if (!valid) {
                std::cout << "Invalid value type at column: "
                        << columns[idx].getName() << '\n';
                return false;
            }
        }

        rows.push_back(row);
        return true;
    }
    const std::string& getTableName() const {
        return name;
    }
    void display() const {
        std::cout << "Table Name: " << name << "\n";
        bool is_first = true;
        for (const auto& col : columns) {
            if (!is_first) {
                std::cout << " | ";
            }

            is_first = false;
            std::cout << col.getName();
        }
        std::cout << '\n';
        for(const auto &row:rows){
            row.display();
            std::cout << '\n';
        }
    }
};
#endif