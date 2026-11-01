#ifndef ROW_HPP
#define ROW_HPP
#include <iostream>
#include <variant>
#include <vector>
#include <string>
#include <type_traits>
using Value = std::variant<int, std::string, bool>;
class Row
{
private:
	std::vector<Value> values;
public:
	Row() = default;
	size_t size() const {
		return values.size();
	}
	void addValue(const Value &newValue)
	{
		values.push_back(newValue);
	}
	void display() const
	{
		bool is_first = true;
		for(const auto& row : values){
			if(!is_first){
				std::cout << " | ";
			}
			is_first = false;
			std::visit([](const auto& arg) {
				using T = std::decay_t<decltype(arg)>;

				if constexpr (std::is_same_v<T, int>) {
					std::cout << "Integer: " << arg;
				}
				else if constexpr (std::is_same_v<T, std::string>) {
					std::cout << "String: " << arg;
				}
				else if constexpr (std::is_same_v<T, bool>) {
					std::cout << "Boolean: " << std::boolalpha << arg;
				}
			}, row);
		}
		std::cout << "\n";
	}
};
#endif