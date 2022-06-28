#include "Item.h"

Item::Item() : NumberInStore(0), unitPrice(0.0)
{
}

/**
 * \brief Constructor using all parameters of the Item class
 * \param id The ID of the product
 * \param name The name of the product
 * \param number The number in stock
 * \param price The price of the product
 */
Item::Item(std::string id, std::string name, int number, double price) :
	itemID(std::move(id)), itemName(std::move(name)), NumberInStore(number), unitPrice(price)
{
}

/**
 * \brief Returns ID of the product
 * \return itemID
 */
std::string Item::getID()
{
	return itemID;
}

/**
 * \brief Returns name of the product
 * \return itemName
 */
std::string Item::getName()
{
	return itemName;
}

/**
 * \brief Returns stock of the product
 * \return NumberInStore
 */
int Item::getNumber()
{
	return NumberInStore;
}

/**
 * \brief Returns price of the product
 * \return unitPrice
 */
double Item::getPrice()
{
	return unitPrice;
}

/**
 * \brief Sets the stock of the product, used during a purchase
 * \param num The number to set it to
 */
void Item::setNumber(int num)
{
	NumberInStore = num;
}

/**
 * \brief Prints a user readable table of values
 */
void Item::printItem()
{
	std::cout << std::setw(4) << itemID << std::setw(20) << itemName << std::setw(10) << NumberInStore << std::setw(10) << std::setprecision(2) << std::fixed << unitPrice << '\n';
}
