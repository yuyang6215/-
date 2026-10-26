#include<iostream>
#include<string>
#include"Book.h"

Book::Book(std::string b_name, std::string writer, std::string b_id, float b_price, int b_amount)
    :b_name(b_name), b_writer(writer), b_id(b_id), b_price(b_price), b_amount(b_amount) {
}

void Book::Get_Book() const
{
    std::cout << "--------------------------\n"
        << "Book name: " << b_name << "\n"
        << "Writer: " << b_writer << "\n"
        << "ID: " << b_id << "\n"
        << "Price: " << b_price << "\n"
        << "Amount: " << b_amount << "\n"
        << "--------------------------\n";
}

const std::string& Book::GetName() const { return b_name; }
const std::string& Book::GetWriter() const { return b_writer; }
const std::string& Book::GetID() const { return b_id; }
float Book::GetPrice() const { return b_price; }
int Book::GetAmount() const { return b_amount; }

void Book::Set_Name(const std::string& name) { b_name = name; }
void Book::Set_Writer(const std::string& writer) { b_writer = writer; }
void Book::Set_Price(float price) { b_price = price; }
void Book::Set_Amount(int amount) { b_amount = amount; }