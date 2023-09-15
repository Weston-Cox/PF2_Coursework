//----------------------------------------------
// Purpose: Implementation of Best Seller class.
// Author: Weston Cox
//----------------------------------------------
#include <iostream>
#include <string>

#include "BestSeller.h"

//**********************************************
BestSeller::BestSeller()
{
    Year = 0;
    Week = "0000-00-00";
    Rank = 0;
    Title_Id = 0;
    Title = "";
    Author = "";
}

//**********************************************
BestSeller::BestSeller(int year, string week, int rank, int title_id, string title, string author)
{
    Year = year;
    Week = week;
    Rank = rank;
    Title_Id = title_id;
    Title = title;
    Author = author;
}

//**********************************************
BestSeller::BestSeller(const BestSeller &bs)
{
    Year = bs.Year;
    Week = bs.Week;
    Rank = bs.Rank;
    Title_Id = bs.Title_Id;
    Title = bs.Title;
    Author = bs.Author;
}

//**********************************************
BestSeller::~BestSeller()
{
}

//**********************************************
int BestSeller::getYear() const
{
    return Year;
}

//**********************************************
string BestSeller::getWeek() const
{
    return Week;
}

//**********************************************
int BestSeller::getRank() const
{
    return Rank;
}

//**********************************************
int BestSeller::getTitleID() const
{
    return Title_Id;
}

//**********************************************
string BestSeller::getTitle() const
{
    return Title;
}

//**********************************************
string BestSeller::getAuthor() const
{
    return Author;
}

//**********************************************
void BestSeller::setYear(int year)
{
    Year = year;
}

//**********************************************
void BestSeller::setWeek(string week)
{
    Week = week;
}

//**********************************************
void BestSeller::setRank(int rank)
{
    Rank = rank;
}

//**********************************************
void BestSeller::setTitleId(int title_id)
{
    Title_Id = title_id;
}

//**********************************************
void BestSeller::setTitle(string title)
{
    Title = title;
}

//**********************************************
void BestSeller::setAuthor(string author)
{
    Author = author;
}

//**********************************************
void BestSeller::read()
{
    string week = "";

    cout << "In the BestSeller.read method\n";

    cout << "Please input Best Seller data.\n";

    cout << "Year: ";
    cin >> Year;

    cout << "Week: ";
    getline(cin >> ws, Week);

    cout << "Rank: ";
    cin >> Rank;

    cout << "Title ID: ";
    cin >> Title_Id;

    cout << "Title: ";
    cin >> Title;

    cout << "Author: ";
    getline(cin >> ws, Author);
}

//**********************************************
void BestSeller::print() const
{
    cout << Year << endl;
    cout << Week << endl;
    cout << Rank << endl;
    cout << Title_Id << endl;
    cout << Title << endl;
    cout << Author << endl;
    cout << endl;
}

//**********************************************