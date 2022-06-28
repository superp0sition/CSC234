#include <iostream>
using std::cin;
using std::cout;
using std::endl;

/**
 * \brief Original function to base <b>recSeqSearch</b> off of. Searches provided list iteratively to return first position of it.
 * \param list Array of integers to search in.
 * \param listLength Length of the array.
 * \param searchItem The integer to look for.
 * \return Returns the index of searchItem and -1 if not found.
 */
int seqSearch(const int list[], int listLength, int searchItem);

/**
 * \brief Original function to base <b>recFindHighest</b> off of. Traverses list iteratively to determine the highest value, then returns it
 * \param list The array to find the highest of
 * \param listLength The length of <b>list</b> array
 * \return The highest value from <b>list</b>
 */
int findHighest(const int list[], int listLength);


/**
 * \brief Searches provided list recursively to return first position of it.
 * \param list Array of integers to search in.
 * \param listLength Length of the array.
 * \param searchItem The integer to look for.
 * \return Returns the index of searchItem and -1 if not found.
 */
int recSeqSearch(const int list[], int listLength, int searchItem);


 /**
  * \brief Traverses list recursively to determine the highest value, then returns it
  * \param list The array to find the highest of
  * \param listLength The length of <b>list</b> array
  * \return The highest value from <b>list</b>
  */
int recFindHighest(const int list[], int listLength);

int mystery(int num);

int main() // main provided in lab document
{
    int list[15] = { 2, 6, 8, 23, 45, 43, 51, 62, 83, 78, 61, 18, 71, 34, 72 };
    int highest = 0;
    int item = 0;
    int location = 0;
    for (int i = 0; i < 15; i++)
        cout << list[i] << " ";
    cout << endl;
    highest = recFindHighest(list, 15);
    cout << "The highest data is: " << highest << endl;
    cout << "Enter the search item: ";
    cin >> item;
    location = recSeqSearch(list, 15, item);
    if (location != -1)
        cout << item << " found at position: " << location << endl;
    else
        cout << item << " not in the list" << endl;
    cout << mystery(5) << endl;
    return 0;
}


int seqSearch(const int list[], int listLength, int searchItem) // function provided in document
{
    int loc = 0;
    bool found = false;
    while (loc < listLength && !found)
    {
        if (list[loc] == searchItem)
        {
            found = true;
            break;
        }
        else
            loc++;
    }
    if (found)
        return loc;
    else
        return -1;
}

int findHighest(const int list[], int listLength) // function provided in document
{
    int highest = list[0];
    for (int i = 1; i < listLength; i++)
    {
        if (list[i] > highest)
            highest = list[i];
    }
    return highest;
}

int recSeqSearch(const int list[], int listLength, int searchItem)
{
    static int loc = 0;
    if (loc == listLength) // first check if the value has been found
        return -1;

    if (list[loc] == searchItem) // check if it was at the position
    {
        return loc;
    }

	loc++;
    recSeqSearch(list, listLength, searchItem); // repeat the function with new loc value
}

int recFindHighest(const int list[], int listLength)
{
    static int highest = list[0]; // set a persistent value for highest
    static int pos = 0;

    if (pos == listLength) // if the function is finished, end immediately
        return highest;

	if (list[pos] > highest) // if there's a new highest, change the value
		highest = list[pos];

	pos++;

    recFindHighest(list, listLength); // repeat function
}

int mystery(int num)
{
    if (num <= 0)
        return 0;
    else if (num % 2 == 0)
        return num + mystery(num - 1);
    else
        return num * mystery(num - 1);
}
