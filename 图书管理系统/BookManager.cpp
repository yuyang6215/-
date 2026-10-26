#include "BookManager.h"
#include"Book.h"
#include<iostream>
#include<string>
#include<stdexcept>
#include<vector>
#include<cctype>
#include<algorithm>

std::vector<Book> books;

void ShowBooks();

void AddBook();

void FindBooks();

void DeleteBooks();

void ModifyBooks();

void SaveBooks();

int InputInt();

float InputFloat();

bool IsBlank(const std::string& str);

int ManagerTitle()
{
	std::cout << "\n";
	std::cout << "--------------------------\n"
		<< "      Book Manager\n"
		<< "--------------------------\n"
		<< "1. Add Books\n"
		<< "2. Show Books\n"
		<< "3. Find Books\n"
		<< "4. Delete Books\n"
		<< "5. Modify Books\n"
		<< "6. Save Books\n"
		<< "7. Exit\n"
		<< "Input: ";
	int choice = InputInt();

	std::cout << "\n";
	return choice;
}

void Manager()
{
	while (true)
	{
		int choice = ManagerTitle();
		switch (choice)
		{
		case 1:
			AddBook();
			break;
		case 2:
			ShowBooks();
			break;
		case 3:
			FindBooks();
			break;
		case 4:
			DeleteBooks();
			break;
		case 5:
			ModifyBooks();
			break;
		case 6:
			SaveBooks();
			break;
		case 7:
			SaveBooks();
			return;
		default:
			std::cout << "Invalid input! Please enter 1-7: ";
			break;
		}
	}
}

int InputInt()
{
	std::string value;
	while (true)
	{
		std::size_t pos = 0;
		std::getline(std::cin, value);
		try
		{
			int result = std::stoi(value, &pos);

			if (pos == value.size())
			{
				//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return result;
			}
		}
		catch (const std::invalid_argument&)
		{
			std::cout << "Invalid input! Please enter an integer: ";
			continue;
		}
		catch (const std::out_of_range&)
		{
			std::cout << "Out of range! Please enter an integer: ";
			continue;
		}

		//防止用户非法输入导致循环进入Manager
		//std::cin.clear();
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input! Please enter an integer: ";
	}
}

float InputFloat()
{
	std::string value;
	while (true)
	{
		std::getline(std::cin, value);
		std::size_t pos = 0;
		try
		{
			float result = std::stof(value, &pos);
			if (pos == value.size())
			{
				return result;
			}
		}
		catch (const std::invalid_argument&)
		{
			std::cout << "Invalid input! Please enter a float: ";
			continue;
		}
		catch (const std::out_of_range&)
		{
			std::cout << "Out of range! Please enter a float: ";
			continue;
		}
		std::cout << "Invalid Input! Please enter float: ";
	}
}

bool IsBlank(const std::string& str)
{
	return std::all_of(str.begin(), str.end(),
		[](unsigned char ch)
		{
			return std::isspace(ch);
		});
}

void ShowBooks()
{
	std::cout << "--------------------------\n"
		<< "      Show All Books\n"
		<< "--------------------------\n";
	for (const Book& value : books)
	{
		value.Get_Book();
	}
}

void AddBook()
{
	float price;
	int amount;
	std::string name;
	std::string writer;
	std::string id;

	while (true)//书名输入
	{
		std::cout << "Input book name: ";
		std::getline(std::cin, name);
		if (IsBlank(name))		//确保输入不为空值
		{
			std::cout << "Book name cannot be empty! Please enter again!\n";
		}
		else
			break;
	}

	while (true)//作者输入
	{
		std::cout << "Input book writer: ";
		std::getline(std::cin, writer);
		if (IsBlank(writer))
		{
			std::cout << "Writer cannot be empty! Please enter again!\n";
		}
		else
			break;
	}

	while (true)//ID输入
	{
		bool duplicates = false;

		std::cout << "Input book id: ";
		std::getline(std::cin, id);
		if (IsBlank(id))
		{
			std::cout << "ID cannot be empty! Please enter again!\n";
			continue;
		}

		for (const Book& book : books)			//防止有重复ID
		{
			if (book.GetID() == id)
			{
				duplicates = true;
				break;
			}
		}
		if (!duplicates)
		{
			break;
		}
		std::cout << "ID has duplicates! Please enter again!\n";
	}

	while (true) //价格输入
	{
		std::cout << "Input book price: ";
		price = InputFloat();
		if (price >= 0)
			break;
		std::cout << "Price cannot be negative!\n";
	}

	while (true)//库存输入
	{
		std::cout << "Input book amount: ";
		amount = InputInt();
		if (amount >= 0)
		{
			break;
		}
		std::cout << "Amount cannot be negative!\n";
	}
	books.emplace_back(name, writer, id, price, amount);
	std::cout << "Add book successfully!\n";
}

void FindBooks()
{
	bool found = false;
	std::string name;
	std::string writer;
	std::string id;
	std::cout << "--------------------------\n"
		<< "       Find Books\n"
		<< "--------------------------\n"
		<< "1. Book name\n"
		<< "2. Writer\n"
		<< "3. ID\n"
		<< "4. Go Back\n"
		<< "Input: ";
	int choice = InputInt();
	switch (choice)
	{
	case 1:
		std::cout << "Please input Book Name: ";
		std::getline(std::cin >> std::ws, name);
		for (const Book& book : books)
		{
			if (name == book.GetName())
			{
				book.Get_Book();
				found = true;
			}
		}
		if (!found)
		{
			std::cout << "Book not found!\n";
		}
		std::cout << "Enter to Managerment......";
		std::cin.get();
		break;
	case 2:
		std::cout << "Please input Writer: ";
		std::getline(std::cin >> std::ws, writer);
		for (const Book& book : books)
		{
			if (writer == book.GetWriter())
			{
				book.Get_Book();
				found = true;
			}
		}
		if (!found)
		{
			std::cout << "Book not found!\n";
		}
		std::cout << "Enter to Managerment......";
		std::cin.get();
		break;
	case 3:
		std::cout << "Please input ID: ";
		std::getline(std::cin >> std::ws, id);
		for (const Book& book : books)
		{
			if (id == book.GetID())
			{
				book.Get_Book();
				found = true;
			}
		}
		if (!found)
		{
			std::cout << "Book not found!\n";
		}
		std::cout << "Enter to Managerment......";
		std::cin.get();
		break;
	case 4:
		return;
	default:
		std::cout << "Invalid input!\n";
		return;
	}
}

void DeleteBooks()
{
	std::string r;
	std::string id;
	std::cout << "--------------------------\n"
		<< "       Delete Books\n"
		<< "--------------------------\n"
		<< "1. ID\n"
		<< "2. Go back\n"
		<< "Input: ";
	int choice = InputInt();
	switch (choice)
	{
	case 1:
		std::cout << "Please enter ID: ";
		std::getline(std::cin >> std::ws, id);
		for (std::vector<Book>::size_type i = 0; i < books.size(); i++) //book.size()返回的是无符号数与int不同
		{
			if (id == books[i].GetID())
			{
				books[i].Get_Book();
				std::cout << "Are you sure you want to delete ? (Y/N) : ";
				std::getline(std::cin >> std::ws, r);

				if (r == "Y" || r == "y")
				{
					books.erase(books.begin() + i);
					std::cout << "\nDelete successfully!\n";
					ShowBooks();
				}
				else
				{
					std::cout << "Delete cancelled\n";
				}
				return;
			}
		}
		std::cout << "Book not found!\n";
		break;

	case 2:
		return;
	default:
		std::cout << "Invalid input!\n";
		return;
	}
}

void ModifyBooks()
{
	std::vector<Book>::size_type i;		////book.size()返回的是无符号数与int不同
	float price;
	int amount;
	std::string id;
	std::string obj;
	std::string s_value;
	std::cout << "--------------------------\n"
		<< "       Modify Books\n"
		<< "--------------------------\n"
		<< "1.ID\n"
		<< "2.Go back\n"
		<< "Input: ";
	int choice = InputInt();
	switch (choice)
	{
	case 1:
		while (true)		//确保输入不为空值
		{
			std::cout << "Please input ID: ";
			std::getline(std::cin, id);
			if (IsBlank(id))
			{
				std::cout << "ID cannot be empty! Please enter again!\n";
			}
			else
				break;
		}

		for (i = 0; i < books.size(); i++)
		{
			if (books[i].GetID() == id)
			{
				books[i].Get_Book();
				break;
			}
		}
		if (i == books.size())
		{
			std::cout << "Book not found!\n";
			return;
		}

		while (true)
		{
			std::cout << "What would you like to change? (Name/Writer/Price/Amount): ";
			std::getline(std::cin >> std::ws, obj);
			if (obj == "Name" || obj == "name" || obj == "Writer" || obj == "writer" || obj == "Price" || obj == "price" || obj == "Amount" || obj == "amount")
			{
				break;
			}
			std::cout << "Invalid input! Please enter again!\n";
		}



		if (obj == "Name" || obj == "name")
		{
			while (true)	//确保输入不为空值
			{
				std::cout << "Please input new data: ";
				std::getline(std::cin, s_value);
				if (IsBlank(s_value))
				{
					std::cout << "Name cannot be empty! Please enter again!\n";
				}
				else
					break;
			}
			books[i].Set_Name(s_value);
			books[i].Get_Book();
		}
		else if (obj == "Writer" || obj == "writer")
		{
			while (true)		//确保输入不为空值
			{
				std::cout << "Please input new data: ";
				std::getline(std::cin, s_value);
				if (IsBlank(s_value))
				{
					std::cout << "Writer cannot be empty! Please enter again!\n";
				}
				else
					break;
			}
			books[i].Set_Writer(s_value);
			books[i].Get_Book();
		}
		else if (obj == "Price" || obj == "price")
		{
			while (true)
			{
				std::cout << "Please input new data: ";
				price = InputFloat();
				if (price >= 0)
				{
					break;
				}
				std::cout << "Price cannot be negative!\n";

			}
			books[i].Set_Price(price);
			books[i].Get_Book();
		}
		else if (obj == "Amount" || obj == "amount")
		{
			while (true)
			{
				std::cout << "Please input new data: ";
				amount = InputInt();
				if (amount >= 0)
				{
					break;
				}
				std::cout << "Amount cannot be negative!\n";
			}
			books[i].Set_Amount(amount);
			books[i].Get_Book();
		}
	}
}