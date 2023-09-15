//----------------------------------------------
// Purpose: Implementation of Best Seller class.
// Author: Weston Cox
//----------------------------------------------
#include <iostream>
#include <string>

#include "BestSellerNode.h"
#include "BestSellerList.h"

//**********************************************
BestSellerNode::BestSellerNode()
{
    Year = 0;
    Week = "0000-00-00";
    Rank = 0;
    Title_Id = 0;
    Title = "";
    Author = "";
    Next = NULL;
}

//**********************************************
BestSellerNode::BestSellerNode(int year, string week, int rank, int title_id, string title, string author)
{
    Year = year;
    Week = week;
    Rank = rank;
    Title_Id = title_id;
    Title = title;
    Author = author;
    Next = NULL;
}

//**********************************************
BestSellerNode::BestSellerNode(const BestSellerNode &bs)
{
    Year = bs.Year;
    Week = bs.Week;
    Rank = bs.Rank;
    Title_Id = bs.Title_Id;
    Title = bs.Title;
    Author = bs.Author;
    Next = bs.Next;
}

//**********************************************
BestSellerNode::~BestSellerNode()
{
}

//**********************************************
int BestSellerNode::getYear() const
{
    return Year;
}

//**********************************************
string BestSellerNode::getWeek() const
{
    return Week;
}

//**********************************************
int BestSellerNode::getRank() const
{
    return Rank;
}

//**********************************************
int BestSellerNode::getTitleID() const
{
    return Title_Id;
}

//**********************************************
string BestSellerNode::getTitle() const
{
    return Title;
}

//**********************************************
string BestSellerNode::getAuthor() const
{
    return Author;
}

//**********************************************
BestSellerNode *BestSellerNode::getNext() const
{
    return Next;
}

//**********************************************
void BestSellerNode::setYear(int year)
{
    Year = year;
}

//**********************************************
void BestSellerNode::setWeek(string week)
{
    Week = week;
}

//**********************************************
void BestSellerNode::setRank(int rank)
{
    Rank = rank;
}

//**********************************************
void BestSellerNode::setTitleId(int title_id)
{
    Title_Id = title_id;
}

//**********************************************
void BestSellerNode::setTitle(string title)
{
    Title = title;
}

//**********************************************
void BestSellerNode::setAuthor(string author)
{
    Author = author;
}

//**********************************************
void BestSellerNode::setNext(BestSellerNode *next)
{
    Next = next;
}

//**********************************************
void BestSellerNode::read()
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
void BestSellerNode::print() const
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