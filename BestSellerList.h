#ifndef BESTSELLERLIST_H
#define BESTSELLERLIST_H

//---------------------------------------------------------
//  Purpose:    Header file for the BestSellerList class.
//  Author:     Weston Cox
//---------------------------------------------------------
#include "BestSellerNode.h"
#include <iostream>
#include <time.h>

using namespace std;

class BestSellerList
{
public:
    // Constructors
    BestSellerList();
    BestSellerList(const BestSellerList &list);
    ~BestSellerList();

    BestSellerNode *Head;

    // Methods
    bool InsertHead(int year, string week, int rank, int title_id, string title, string author);
    bool InsertTail(int year, string week, int rank, int title_id, string title, string author);
    bool AuthorInsert(BestSellerNode *listPTR);
    bool TitleInsert(BestSellerNode *listPTR);
    void print();
    int getCount();
    void FindTitle();
    void FindAuthor();
    void MostPopularBook();
    void MostProlificAuthor();

private:
    BestSellerNode *Tail;
    int Count;
};

#endif