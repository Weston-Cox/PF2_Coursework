//-----------------------------------------------------------
//  Purpose:    To read, find and output from a NYT
//              Bestsellers list file
//  Author:     Weston Cox
//-----------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#include "BestSeller.h"
#include "BestSeller.cpp"

// ************ Functions ************ //

void read_file(vector<BestSeller> &BestSellers)
{
    BestSeller temp;
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

        temp.setYear(year);
        temp.setWeek(week);
        temp.setRank(rank);
        temp.setTitleId(title_id);
        temp.setTitle(title);
        temp.setAuthor(author);

        BestSellers.push_back(temp);
    }

    infile.close();
    cout << "File closed.\n";
}

void find_title(vector<BestSeller> BestSellers)
{
    string titleToSearch = "THE HOBBIT";

    cout << "Searching for " << titleToSearch << endl
         << ".\n";
    cout << "***** Records: ***** \n";
    for (int i = 0; i < (int)BestSellers.size(); i++)
    {
        if (BestSellers[i].getTitle() == titleToSearch)
        {
            BestSellers[i].print();
        }
    }
}

void find_author(vector<BestSeller> BestSellers)
{
    string authorToSearch = "Tiffany Thayer";

    cout << "Searching for " << authorToSearch << endl
         << ".\n";

    cout << "***** Records: ***** \n";
    for (int i = 0; i < (int)BestSellers.size(); i++)
    {
        if (BestSellers[i].getAuthor() == authorToSearch)
        {
            BestSellers[i].print();
        }
    }
}

void find_week(vector<BestSeller> BestSellers)
{
    string startDate = "1935-05-04";
    string endDate = "1935-06-20";

    cout << "Searching from " << startDate << " to " << endDate << endl
         << endl;

    cout << "***** Records: ***** \n";
    for (int i = 0; i < (int)BestSellers.size(); i++)
    {
        if ((BestSellers[i].getWeek() >= startDate) && (BestSellers[i].getWeek() <= endDate))
        {
            BestSellers[i].print();
        }
    }
}

//***********************************************************
// Main Program
//***********************************************************

int main()
{
    // BestSeller temp;

    vector<BestSeller> BestSellers;
    read_file(BestSellers);

    cout << "\n";
    find_title(BestSellers);
    cout << "\n";
    find_author(BestSellers);
    cout << "\n";
    find_week(BestSellers);
    cout << "\n";

    // temp.read();
    // BestSellers.push_back(temp);
}