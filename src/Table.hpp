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
    void insertRow(const Row& row) {
        if(row.size() != columns.size()){
            std::cout << "Expected values " << columns.size() << "But got " << row.size() << "\n";
            return;
        }
        rows.push_back(row);
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