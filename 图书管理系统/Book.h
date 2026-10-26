#pragma once
#include<iostream>
#include<string>

class Book
{
private:
    std::string b_name;
    std::string b_writer;
    std::string b_id;
    float b_price;
    int b_amount;
public:
    Book(std::string b_name, std::string writer, std::string b_id, float b_price, int b_amount);

    void Get_Book() const;

    const std::string& GetName() const;
    const std::string& GetWriter() const;
    const std::string& GetID() const;
    float GetPrice() const;
    int GetAmount() const;

    void Set_Name(const std::string& name);
    void Set_Writer(const std::string& writer);
    void Set_Price(float price);
    void Set_Amount(int amount);
};