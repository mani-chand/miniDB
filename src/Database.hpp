#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "Table.hpp"
#include <vector>
#include <string>
#include <algorithm>
#include <ranges>
class Database {
private:
    std::string name;
    std::vector<Table> tables;

    bool checkTableExist(
    const std::string& table_name,
    const std::string& present_name = ""
    ) const {
        for (const auto& table : tables) {
            if (table.getTableName() == table_name &&
                table.getTableName() != present_name) {
                return true;
            }
        }
        return false;
    }

public:
    Database(const std::string& db_name)
        : name(db_name) {}

    void displayTables() const {
        for (const auto& table : tables) {
            std::cout << table.getTableName() << '\n';
        }
    }
    bool createTable(const std::string& table_name) {
        if (checkTableExist(table_name)) {
            return false;
        }

        tables.emplace_back(table_name);
        return true;
    }
     Table* getTable(const std::string& table_name){
        for (auto& table : tables) {
            if (table.getTableName() == table_name) {
                return &table;
            }
        }
        return nullptr;
    }
    bool dropTable(const std::string& table_name) {
        auto target_table = std::find_if(
            tables.begin(),
            tables.end(),
            [&table_name](const Table& table) {
                return table.getTableName() == table_name;
            }
        );

        if (target_table != tables.end()) {
            tables.erase(target_table);
            return true;
        }

        return false;
    }
    std::vector<Table> getTablesStartsWith(const std::string& prefix_table_name) {
        auto view = tables 
            | std::views::filter([&prefix_table_name](const Table& table) {
                return table.getTableName().starts_with(prefix_table_name);
            });

        return std::vector<Table>(view.begin(), view.end());
    }

    std::size_t dropTablesWithPrefix(const std::string& prefix){
       return std::erase_if(tables,[&prefix](const Table& table) {
                return table.getTableName().starts_with(prefix);
            });
    }
    bool renameTable(
    const std::string& old_name,
    const std::string& new_name
    ) {
        if (new_name.empty()) {
            return false;
        }

        if (checkTableExist(new_name, old_name)) {
            return false;
        }

        for (auto& table : tables) {
            if (table.getTableName() == old_name) {
                return table.updateTableName(new_name);
            }
        }

        return false;
    }
};

#endif