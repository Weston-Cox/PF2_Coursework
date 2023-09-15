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
// #include "BestSellerNode.cpp"
#include "BestSellerList.h"
// #include "BestSellerList.cpp"

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

    ifstream infile("nyt_best_sellers.tsv");
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
    cout << "File closed.\n";
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

    read_file(list);

    // list.InsertHead(1931, "1931-10-12", 1, 6477, "THE TEN COMMANDMENTS", "Warwick Deeping");
    // list.InsertHead(1967, "1967-1-06", 4, 4566, "Abra-Ca-Dabra!", "Magic Mike");
    // list.InsertTail(2023, "2023-08-26", 1, 1111, "Just Say Yes!", "John Seed");
    // list.InsertTail(2025, "2025-05-14", 8, 8793, "Graduation", "Weston Cox");

    // list.FindAuthor();

    // list.FindTitle();

    // insertByAuthor(list);

    // insertByTitle(list);

    // list.MostPopularBook();

    insertByAuthor(list);

    list.MostProlificAuthor();
}