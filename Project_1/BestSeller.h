#ifndef BESTSELLERS_H
#define BESTSELLERS_H

//----------------------------------------------
// Purpose: Define BestSeller class
// Author:  Weston Cox
//----------------------------------------------

#include <iostream>
using namespace std;

class BestSeller
{
public:
   // Constructors
   BestSeller();
   BestSeller(int year, string week, int rank, int title_id, string title, string author);
   BestSeller(const BestSeller &bs);
   ~BestSeller();

   //******* Methods *******//
   // Getters
   int getYear() const;
   string getWeek() const;
   int getRank() const;
   int getTitleID() const;
   string getTitle() const;
   string getAuthor() const;
   // Setters
   void setYear(int year);
   void setWeek(string week);
   void setRank(int rank);
   void setTitleId(int title_id);
   void setTitle(string title);
   void setAuthor(string author);

   void read();
   void print() const;

private:
   int Year;
   string Week;
   int Rank;
   int Title_Id;
   string Title;
   string Author;
};

#endif