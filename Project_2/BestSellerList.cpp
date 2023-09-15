//-------------------------------------------------
//  Purpose: Implementation of BestSellerList class
//  Author: Weston Cox
//-------------------------------------------------

#include "BestSellerList.h"
#include "BestSellerNode.h"
#include <string.h>

//***********************************************
//! Constructor Function
//***********************************************
BestSellerList::BestSellerList()
{
    Head = NULL;
}

//***********************************************
//! Copy Constuctor Function
//***********************************************
BestSellerList::BestSellerList(const BestSellerList &list)
{
    // Create first node
    BestSellerNode *copy = new BestSellerNode();
    Head = copy;

    // Walk list to copy nodes
    BestSellerNode *ptr = list.Head; // Points to the beginning of the list to be copied
    while (ptr != NULL)
    {
        copy->setNext(new BestSellerNode());
        copy = copy->getNext();
        copy->setYear(ptr->getYear());
        copy->setWeek(ptr->getWeek());
        copy->setRank(ptr->getRank());
        copy->setTitleId(ptr->getTitleID());
        copy->setTitle(ptr->getTitle());
        copy->setAuthor(ptr->getAuthor());
        copy->setNext(NULL);
        ptr = ptr->getNext();
    }

    // Tidy first node
    copy = Head;
    Head = copy->getNext();
    delete copy;
}

//***********************************************
//! Destructor Function
//***********************************************
BestSellerList::~BestSellerList()
{
}

//***********************************************
//! Insert data into front of linked list.
//***********************************************
bool BestSellerList::InsertHead(int year, string week, int rank, int title_id, string title, string author)
{
    // Create new node
    BestSellerNode *ptr = new BestSellerNode(year, week, rank, title_id, title, author);
    ptr->setNext(Head);

    // Insert new node
    Head = ptr;
    Count++;
    return true;
}

//***********************************************
//! Insert data into back of linked list.
//***********************************************
bool BestSellerList::InsertTail(int year, string week, int rank, int title_id, string title, string author)
{
    // Find tail node
    BestSellerNode *ptr = Head;
    while ((ptr != NULL) && (ptr->getNext() != NULL))
        ptr = ptr->getNext();

    // Inserting new node
    if (ptr != NULL)
    {
        ptr->setNext(new BestSellerNode(year, week, rank, title_id, title, author));
        return true;
    }
    else
    {
        Head = new BestSellerNode(year, week, rank, title_id, title, author);
        return false;
    }
}

//***********************************************
//! Insert data into linked list by author.
//***********************************************
bool BestSellerList::AuthorInsert(BestSellerNode *listPTR)
{
    BestSellerNode *curr = Head;
    BestSellerNode *prev = Head;
    // cout << "outside\n";
    while ((curr != NULL) && (curr->getAuthor() < listPTR->getAuthor()))
    {
        prev = curr;
        curr = curr->getNext();
        // cout << "in loop\n";
    }

    // Create new node
    BestSellerNode *ptr = new BestSellerNode();
    ptr->setYear(listPTR->getYear());
    ptr->setWeek(listPTR->getWeek());
    ptr->setRank(listPTR->getRank());
    ptr->setTitleId(listPTR->getTitleID());
    ptr->setTitle(listPTR->getTitle());
    ptr->setAuthor(listPTR->getAuthor());
    ptr->setNext(curr);

    // Insert node into list
    if (curr == Head)
    {
        Head = ptr;
        // cout << "in if\n";
    }
    else
    {
        prev->setNext(ptr);
        // cout << "in else\n";
    }
    return true;
}
//***********************************************
//! Insert data into linked list by title.
//***********************************************
bool BestSellerList::TitleInsert(BestSellerNode *listPTR)
{
    BestSellerNode *curr = Head;
    BestSellerNode *prev = Head;
    // cout << "outside\n";
    while ((curr != NULL) && (curr->getTitle() < listPTR->getTitle()))
    {
        prev = curr;
        curr = curr->getNext();
        // cout << "in loop\n";
    }

    // Create new node
    BestSellerNode *ptr = new BestSellerNode();
    ptr->setYear(listPTR->getYear());
    ptr->setWeek(listPTR->getWeek());
    ptr->setRank(listPTR->getRank());
    ptr->setTitleId(listPTR->getTitleID());
    ptr->setTitle(listPTR->getTitle());
    ptr->setAuthor(listPTR->getAuthor());
    ptr->setNext(curr);

    // Insert node into list
    if (curr == Head)
    {
        Head = ptr;
        // cout << "in if\n";
    }
    else
    {
        prev->setNext(ptr);
        // cout << "in else\n";
    }
    return true;
}
//***********************************************
//! Print the contents of the linked list.
//***********************************************
void BestSellerList::print()
{
    BestSellerNode *ptr = Head;
    while (ptr != NULL)
    {
        ptr->print();
        ptr = ptr->getNext();
    }
}
//***********************************************
//! Return the number of nodes in the linked list.
//***********************************************
int BestSellerList::getCount()
{
    return Count;
}
//***********************************************
//! Find a specific author in the linked list.
//***********************************************
void BestSellerList::FindAuthor()
{
    string authorToSearch = "Warwick Deeping";
    bool valid = false;

    cout << "Searching for " << authorToSearch << endl
         << "\n";
    cout << "***** Records: ***** \n";

    BestSellerNode *ptr = Head;
    while (ptr != NULL)
    {
        if (ptr->getAuthor() == authorToSearch)
        {
            ptr->print();
            valid = true;
        }
        ptr = ptr->getNext();
    }
    if (!valid)
        cout << "Could not find " << authorToSearch << ". \n"
             << endl;
}
//***********************************************
//! Find a specific title in the linked list.
//***********************************************
void BestSellerList::FindTitle()
{
    string titleToSearch = "THE HOBBIT";
    bool valid = false;

    cout << "Searching for " << titleToSearch << endl
         << "\n";
    cout << "***** Records: ***** \n";

    BestSellerNode *ptr = Head;
    while (ptr != NULL)
    {
        if (ptr->getTitle() == titleToSearch)
        {
            ptr->print();
            valid = true;
        }
        ptr = ptr->getNext();
    }
    if (!valid)
    {
        cout << "Could not find " << titleToSearch << ". \n"
             << endl;
    }
}
//***********************************************
//! Find the most popular book in the linked list.
//***********************************************
void BestSellerList::MostPopularBook()
{
    cout << "Finding most popular book...\n"
         << endl;
    BestSellerNode *ptr = Head;

    int mostTitles = 0;
    int count = 0;
    string bestTitle = ptr->getTitle();
    string title = bestTitle;

    ptr->getNext();
    while ((ptr != NULL) && (ptr->getNext() != NULL))
    {

        if (title == ptr->getTitle())
        {
            count++;
        }
        else
        {
            title = ptr->getTitle();
            count = 1;
        }
        if (mostTitles < count)
        {
            mostTitles = count;
            bestTitle = title;
        }
        ptr = ptr->getNext();
    }

    cout << "Most popular book is " << bestTitle << " with a count of " << mostTitles << endl
         << endl;
}
//***********************************************
//! Find the most prolific author in the linked list.
//***********************************************
void BestSellerList::MostProlificAuthor()
{
    cout << "Finding most prolific author...\n"
         << endl;
    BestSellerNode *ptr = Head;

    int mostAuthor = 0;
    int count = 0;
    string bestAuthor = ptr->getAuthor();
    string author = bestAuthor;

    ptr->getNext();
    while ((ptr != NULL) && (ptr->getNext() != NULL))
    {

        if (author == ptr->getAuthor())
        {
            count++;
        }
        else
        {
            author = ptr->getAuthor();
            count = 1;
        }
        if (mostAuthor < count)
        {
            mostAuthor = count;
            bestAuthor = author;
        }
        ptr = ptr->getNext();
    }

    cout << "Most popular author is " << bestAuthor << " with a count of " << mostAuthor << endl
         << endl;
}
