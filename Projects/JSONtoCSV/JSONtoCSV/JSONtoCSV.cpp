// JSONtoCSV.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
#include "json.hpp"

namespace fs = std::filesystem;

void processFile(fs::path s, nlohmann::json json)
{
    std::ofstream stream(s);
    nlohmann::json small;

    if (!stream.is_open())
    {
        return;
    }

    int weird = -1;
    do {
        small = json[++weird]["Cells"][0];
    } while (small.empty());

    for (auto it = small.begin(); it != small.end(); ++it)
        stream << it.key() << ",";
    stream << "\n";

    for (auto i = weird; i < json.size(); ++i)
    {
        for (auto j = 0; j < json[i]["Cells"].size(); ++j)
        {
            small = json[i]["Cells"][j];
            for (auto it = small.begin(); it != small.end(); ++it)
                stream << it.value() << ",";
            stream << "\n";
        }
    }
    stream.close();
}

int main(int argc, char* argv[])
{

	const auto path = fs::current_path();
	for (const auto entry : fs::directory_iterator(path))
	{
        if (entry.path().extension() == ".json")
        {
            std::cout << entry.path() << std::endl;
            nlohmann::json jsonFromFile;
            try
            {
                std::ifstream file(entry);
                if (!file.is_open())
                {
                    return 1;
                }
                file >> jsonFromFile;
                file.close();
            }
            catch (std::exception& e)
            {
                std::cout << e.what() << std::endl;
            }

            fs::path output = entry;
            output.replace_extension("csv");

            processFile(output, jsonFromFile);
        }
        
	}


}
