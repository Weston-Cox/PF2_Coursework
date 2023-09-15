//-----------------------------------------------------------
//  Purpose:    To read, find and output from a NYT
//              Bestsellers list file
//  Author:     Weston Cox
//-----------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "BestSellerNode.h"
#include "BestSellerNode.cpp"
#include "BestSellerList.h"
#include "BestSellerList.cpp"

// ************ Functions ************ //

void read_file(BestSellerList &list)
{
    int year;
    string week;
    int rank;
    int title_id;
    string title;
    string author;
    string extra;

    cout << endl
         << "Opening file...\n";

    ifstream infile("nyt_short_list.txt");
    if (infile.fail())
    {
        cout << "Failed to open file\n";
    }

    getline(infile, extra); // Used to grab the 1st row out of the file that has column descriptors.

    while (infile >> year)
    {

        infile >> week;
        infile >> rank;
        infile >> title_id;
        getline(infile >> ws, title, '\t');
        getline(infile, author);

        list.InsertTail(year, week, rank, title_id, title, author);
    }

    infile.close();
    cout << "File closed.\n"
         << endl;
}

//***************************************************************
void insertByAuthor(BestSellerList &list)
{
    cout << "Sorting by Author...\n";
    BestSellerList sortedList;
    BestSellerNode *ptr = list.Head;
    while (ptr != NULL)
    {
        sortedList.AuthorInsert(ptr);
        ptr = ptr->getNext();
    }
    list = sortedList;
}

//***************************************************************
void insertByTitle(BestSellerList &list)
{
    cout << "Sorting by title...\n";
    BestSellerList sortedList;
    BestSellerNode *ptr = list.Head;
    while (ptr != NULL)
    {
        sortedList.TitleInsert(ptr);
        ptr = ptr->getNext();
    }
    list = sortedList;
}

//***********************************************************
// Main Program
//***********************************************************

int main()
{

    BestSellerList list;
    BestSellerList tailList;
    BestSellerList headList;

    read_file(list);

    headList.InsertHead(1931, "1931-10-12", 1, 6477, "THE TEN COMMANDMENTS", "Warwick Deeping");
    headList.InsertHead(1967, "1967-1-06", 4, 4566, "Abra-Ca-Dabra!", "Magic Mike");
    tailList.InsertTail(2023, "2023-08-26", 1, 1111, "Just Say Yes!", "John Seed");
    tailList.InsertTail(2025, "2025-05-14", 8, 8793, "Graduation", "Weston Cox");

    cout << "Head List:\n";
    headList.print();
    cout << endl;

    cout << "Tail List:\n";
    tailList.print();
    cout << endl;

    list.FindAuthor();

    list.FindTitle();

    insertByTitle(list);

    list.MostPopularBook();

    insertByAuthor(list);

    list.MostProlificAuthor();
}