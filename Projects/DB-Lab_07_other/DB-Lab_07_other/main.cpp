#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

struct item
{
	std::string id;
	int quantity{};
	std::string name;
	double value{};
} inv_item;

enum class query{found = 0, no_stock, not_found};

/**
 * \brief Preforms output on the given output string formatted to the original file format
 * \param os The output stream 
 * \param inventory The vector containing items to be output
 */
void outputFileFormat(std::ostream& os, const std::vector<item>& inventory)
{
	for(const auto& i : inventory)
	{
		os << i.id << '\n' << i.name << '\n' << i.quantity << ' ' << i.value << '\n';
	}
}

/**
 * \brief Outputs a table of items including a header
 * \param os The output stream
 * \param inventory The vector containing the items to be output
 */
void outputFormat(std::ostream& os, const std::vector<item>& inventory)
{
	os << std::setw(4) << "ID" << std::setw(20) << "Name" << std::setw(10) << "Quantity" << std::setw(10) << std::setprecision(2) << std::fixed << "Value" << '\n';
	for (auto i : inventory)
	{
		os << std::setw(4) << i.id  << std::setw(20) << i.name << std::setw(10) << i.quantity << std::setw(10) << std::setprecision(2) << std::fixed << i.value << '\n';
	}
}

/**
 * \brief Search for an item with a passed through iterator to be used after the function
 * \param inventory The list of items to be searched
 * \param search The exact string to be searched for in the item names
 * \param it Iterator passed through the function to return the value
 * \return Returns what state the item was found in (in stock, no stock, not found)
 */
query searchItem(std::vector<item>& inventory, const std::string& search, std::vector<item>::iterator& it)
{
	bool found = false;
	while (!found && it != inventory.end())
	{
		++it;
		if (it->name == search)
			found = !found;
	}
	if (found && it->quantity > 0)
		return query::found;
	return found ? query::no_stock : query::not_found;
}

/**
 * \brief Search for an item in the inventory vector
 * \param inventory Vector containing items to be searched
 * \param search The string to be searched
 * \return Returns the state the item was found in (in stock, no stock, not found)
 */
query searchItem(std::vector<item>& inventory, const std::string& search)
{
	bool found = false;
	auto it = inventory.begin();
	while (!found && it != inventory.end())
	{
		++it;
		if (it->name == search)
			found = !found;
	}
	if (found && it->quantity > 0)
		return query::found;
	return found ? query::no_stock : query::not_found;
}

/**
 * \brief Displays the menu to show the user their options
 */
void displayMenu()
{
	std::cout << '\n' <<
		R"(Welcome to the Friendly Hardware Store!
	Choose among the following options:
	1. Print inventory by sorting item price low to high.
	2. Search for an item.
	3. Order an item.
	4. Exit.)" << '\n';
}

/**
 * \brief "purchases" an item from the inventory, removes a quantity and displays the price of that amount
 * \param inventory The vector containing items 
 * \param search The item to search for to preform the purchase operation on
 * \return Returns if the purchase was successful
 */
bool purchase(std::vector<item>& inventory, const std::string& search)
{
	auto it = inventory.begin();
	const query query = searchItem(inventory, search, it);
	if (query == query::no_stock || query == query::not_found)
		return false;
	int amount;
	std::cout << "Enter the number of items: "; std::cin >> amount;
	if (amount > it->quantity)
		return false;
	it->quantity -= amount;
	std::cout << "Total cost: $" << std::fixed << std::setprecision(2) << it->value * amount;

	std::ofstream file("ItemData.txt");
	outputFileFormat(file, inventory);

	return true;
}

/**
 * \brief Utility function to compare values of items
 * \param i Item 1
 * \param j Item 2
 * \return Returns true if item 1 is smaller than item 2 and vice-versa
 */
bool itemComparison(const item &i,const item &j) { return (i.value < j.value); }

/**
 * \brief Sorts the inventory vector by descending value and displays it to the console
 * \param inventory The vector containing all items
 */
void displaySorted(std::vector<item> inventory)
{
	std::sort(inventory.begin(), inventory.end(), itemComparison);
	outputFormat(std::cout, inventory);
}

int main()
{
	std::ifstream file("ItemData.txt");
	
	std::vector<item> items;
	item temp;

	int input;
	std::string txt;

	while (file >> temp.id)
	{
		file.ignore(100, '\n');
		getline(file, temp.name);
		file >> temp.quantity >> temp.value;
		items.push_back(temp);
	}

	do
	{
		displayMenu();
		std::cin >> input;

		switch (input)
		{
		case 1:
			displaySorted(items);
			break;
		case 2:
			std::cout << "Enter the item name to search: ";
			std::cin >> txt;

			try
			{
				switch (searchItem(items, txt))
				{
				case query::found:
					std::cout << txt << " is in stock." << '\n';
					break;
				case query::no_stock:
					std::cout << txt << " is not in stock." << '\n';
					break;
				case query::not_found:
					std::cout << txt << " was not found" << '\n';
					break;
				}
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << '\n';
			}
			break;
		case 3:
			std::cout << "Enter the item name to search: "; std::cin >> txt;
			if (!purchase(items, txt))
				std::cout << "Purchase could not be completed" << '\n';
			break;
		case 4:
			std::cout << "Thanks for using this application!";
			return 0;
		default:
			std::cout << "Please choose an option from the list." << '\n';
			break;
		}
		
	} while (true);
}	