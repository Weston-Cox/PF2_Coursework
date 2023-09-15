#ifndef BESTSELLERSNODE_H
#define BESTSELLERSNODE_H

//----------------------------------------------
// Purpose: Define BestSellerNode class
// Author:  Weston Cox
//----------------------------------------------

#include <iostream>
using namespace std;

class BestSellerNode
{
public:
   // Constructors
   BestSellerNode();
   BestSellerNode(int year, string week, int rank, int title_id, string title, string author);
   BestSellerNode(const BestSellerNode &bs);
   ~BestSellerNode();

   //******* Methods *******//
   // Getters
   int getYear() const;
   string getWeek() const;
   int getRank() const;
   int getTitleID() const;
   string getTitle() const;
   string getAuthor() const;
   BestSellerNode *getNext() const;

   // Setters
   void setYear(int year);
   void setWeek(string week);
   void setRank(int rank);
   void setTitleId(int title_id);
   void setTitle(string title);
   void setAuthor(string author);
   void setNext(BestSellerNode *next);

   void read();
   void print() const;

private:
   int Year;
   string Week;
   int Rank;
   int Title_Id;
   string Title;
   string Author;
   BestSellerNode *Next;
};

#endif