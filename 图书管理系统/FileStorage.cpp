#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<stdexcept>
#include<cmath>
#include"FileStorage.h"
#include"BookManager.h"

void SaveBooks()
{
    std::ofstream file("book.txt");
    if (!file)
    {
        std::cout << "Failed to open file!\n";
        return;
    }

    for (const Book& book : books)
    {
        file << book.GetName() << "\n";
        file << book.GetWriter() << "\n";
        file << book.GetID() << "\n";
        file << book.GetPrice() << "\n";
        file << book.GetAmount() << "\n";
    }
    file.close();
    if (!file)
    {
        std::cout << "Failed to save books!\n";
        return;
    }
    std::cout << "Books saved successfully\n";
}

void LoadBooks()
{
    std::ifstream file("book.txt");

    if (!file)
    {
        std::cout << "No save file found!\n";
        return;
    }
    std::string name;
    std::string writer;
    std::string id;
    std::string text_price;
    std::string text_amount;
    float price;
    int amount;

    while (std::getline(file, name))
    {
        if (!std::getline(file, writer) ||
            !std::getline(file, id) || 
            !std::getline(file, text_price) || 
            !std::getline(file, text_amount))
        {
            break;
        }

        std::size_t price_pos;
        std::size_t amount_pos;

        try
        {
            price = std::stof(text_price, &price_pos);
            if (price_pos != text_price.size())
            {
                continue;
            }
        }
        catch(const std::invalid_argument&)
        {
            continue;
        }
        catch (const std::out_of_range&)
        {
            continue;
        }

        try
        {
            amount = std::stoi(text_amount, &amount_pos);
            if (amount_pos != text_amount.size())
            {
                continue;
            }
        }
        catch (const std::invalid_argument&)
        {
            continue;
        }
        catch (const std::out_of_range&)
        {
            continue;
        }

        if (std::isfinite(price) && 
            price >= 0 && 
            amount >= 0 && 
            !IsBlank(name) &&
            !IsBlank(writer) 
            && !IsBlank(id))
        {
            bool duplicates = false;
            for (const Book& book : books)
            {
                if (book.GetID() == id)
                {
                    duplicates = true;
                    break;
                }
            }
            if (!duplicates)
            {
                books.emplace_back(name, writer, id, price, amount);
            }
        }
    }
}