#include <fstream>
#include <vector>

#include "Item.h"

void getData(std::ifstream& inp, std::vector<Item>& items);
int getSelection();
int searchItemByName(std::vector<Item> items, std::string searchName);
void printReport(std::vector<Item>& items);
void sortItemsByID(std::vector<Item>& items);
void orderItem(std::vector<Item>& items);
void outputFileFormat(std::ostream& os, const std::vector<Item>& items);

int main()
{
	std::vector<Item> items;
	std::ifstream file("ItemData.txt");

	getData(file, items);

	std::string txt;

	int pos; // pos only exists to determine if an item is or is not in stock, so it isn't necessary and can be removed if only the item existing in the list is what must be known
	do
	{
		switch(getSelection())
		{
		case 1:
			printReport(items);
			break;
		case 2:
			std::cout << "Enter the item name to search: ";
			std::cin >> txt;
			pos = searchItemByName(items, txt);
			if(pos > -1)
			{
				if (items.at(pos).getNumber() <= 0)
					std::cout << txt << " is not in stock" << '\n';
				else
					std::cout << txt << " is in stock" << '\n';
			} else
				std::cout << txt << " could not be found" << '\n';
			break;
		case 3:
			orderItem(items);
			break;
		case 4:
			std::cout << '\n' << "Thanks for using this application!" << '\n';
			return 0;
		default:
			std::cout << "Please choose an option from the list." << '\n';
			break;
		}
	} while (true);
}

/**
 * \brief Read item data from input file “ItemData.txt”. Create item object using each item record data. Add all item objects into the vector object items.
 * \param inp Input file stream containing the item data
 * \param items Vector to contain the read items
 */
void getData(std::ifstream& inp, std::vector<Item>& items)
{
	struct item_data // struct to hold data from my other solution, partially so I could copy the code over, partially to make it more readable
	{
		std::string id;
		int quantity{};
		std::string name;
		double value{};
	} inv_item;

	while (inp >> inv_item.id) // while there is another id, place it into the value, will stop at the end since each item is preceded by an ID
	{
		inp.ignore(100, '\n'); // flush the input and delimit it using the newline character
		getline(inp, inv_item.name); // get the line
		inp >> inv_item.quantity >> inv_item.value; // get other values
		items.emplace_back(inv_item.id, inv_item.name, inv_item.quantity, inv_item.value); // emplace back constructs the items
	}
}

/**
 * \brief Display menu, ask user to enter operation number and return the number.
 * \return Returns the value the user chose
 */
int getSelection()
{
	int input;
	std::cout << '\n' <<
		R"(Welcome to the Friendly Hardware Store!
	Choose among the following options:
	1. Print inventory by sorting item price low to high.
	2. Search for an item.
	3. Order an item.
	4. Exit.)" << '\n'; // using string literal since it's a bit nicer to read sometimes

	std::cin >> input;
	return input;
}

//int itemComparison(const std::string& i, const std::string& j) { return (i.compare(j)); }

/**
 * \brief Searches the item vector using a binary search algorithm
 * \param items Vector of items to be searched
 * \param searchName The name to be searched for
 * \return Returns the index of the item, and -1 if not found
 */
int searchItemByName(std::vector<Item> items, std::string searchName)
{

	int n = items.size(); // refer to bubble sort in printReport from here
	do {
		int new_n = 0;
		for (int i = 1; i < n; i++)
		{
			if (items.at(i - 1).getName().compare(items.at(i).getName()) > 0) {
				std::swap(items.at(i - 1), items.at(i));
				new_n = i;
			}
		}
		n = new_n;
	} while (n > 1); // to here

	int left = 0;
	int right = items.size() - 1;
	while (left <= right)
	{
		int middle = left + (right - left) / 2; // (floor + ceiling) / 2 is the midpoint

		if (items.at(middle).getName() == searchName) { // if the item is found, return the index
			return middle;
		}

		if (items.at(middle).getName().compare(searchName) < 0) { // if the item is not found but would be on the right, move floor to the middle
			left = middle + 1;
		}
		else { // if the item is not found but would be on the left, move ceiling to middle
			right = middle - 1;
		}
	}

	return -1;
}

/**
 * \brief Sorts values in items using their <b>unitPrice</b> following the bubble sort algorithm
 * \param items The items to be sorted then displayed
 */
void printReport(std::vector<Item>& items)
{
	int n = items.size();
	do {
		int new_n = 0;
		for (int i = 1; i < n; i++) // from now until the last point the array is sorted
		{
			if(items.at(i - 1).getPrice() > items.at(i).getPrice() ){ // if adjacent position is out of order
				std::swap(items.at(i - 1), items.at(i)); // swap the two positions
				new_n = i; // set new n to last known sorted position with different variable to avoid affecting for loop
			}
		}
		n = new_n; // set n
	} while (n > 1);

	// sortItemsByID(items); // here for testing

	std::cout << std::setw(4) << "ID" << std::setw(20) << "Name" << std::setw(10) << "Quantity" << std::setw(10) << std::setprecision(2) << std::fixed << "Value" << '\n';
	for (auto& i : items)
		i.printItem(); // print each item
}

/**
 * \brief Sort the items by insertion sort
 * \param items The vector to be sorted by reference
 */
void sortItemsByID(std::vector<Item>& items)
{
	for (int i = 1, j; i < items.size(); i++) // sort to the end of the array
	{
		Item temp = items.at(i); // store the item for swap later
		
		for (j = i - 1; j >= 0 && items.at(j).getID().compare(temp.getID()) > 0; j--) // this while loop recursively replaces each item until the temp is equal to or greater than the item at i
		{
			items.at(j + 1) = items.at(j);
		} 
		items.at(j + 1) = temp; // finish the swap
	}
}

/**
 * \brief Prompts the user to perform a purchase, searches vector, make sure the number is not too high, calculate amount due, update inventory in file
 * \param items The vector to be used for the purchase
 */
void orderItem(std::vector<Item>& items)
{
	std::cout << "Enter the item name to search: ";
	std::string name;
	std::cin.ignore(' ');
	getline(std::cin, name);

	const int search = searchItemByName(items, name); // hold search to be used later
	const auto quantity = items.at(search).getNumber(); // thought of using a an item containing the data, but an iterator would be best

	int desired_amount;
	std::cout << "Enter the number of items: "; std::cin >> desired_amount; // get the amount desired by user

	if (desired_amount > quantity) // make sure they're not ordering more than the store has
	{
		std::cout << "You can not order an amount over the quantity in store." << '\n';
		return; // close purchase if they are with message
	}

	items.at(search).setNumber(quantity - desired_amount); // subtract the amount from the purchase

	std::cout << "Total cost: $" << std::fixed << std::setprecision(2) << items.at(search).getPrice() * desired_amount << '\n'; // show the receipt

	sortItemsByID(items); // change sorting to ID before saving if the display function was used first

	std::ofstream file("ItemData.txt");
	outputFileFormat(file, items); // output to the file opened above
}

/**
 * \brief Preforms output on the given output string formatted to the original file format
 * \param os The output stream
 * \param items The vector containing items to be output
 */
void outputFileFormat(std::ostream& os, const std::vector<Item>& items)
{
	for (auto i : items)
	{
		os << i.getID() << '\n' << i.getName() << '\n' << i.getNumber() << ' ' << i .getPrice() << '\n'; // copied from my other version of this solution
	}
}