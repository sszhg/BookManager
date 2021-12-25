#include "Book.h"
#include<fstream>
#include<iostream>
#include<iomanip>//
#include<cstring>
#include<cstdlib>
Book::Book()
{

}

Book::Book(char* aname, char* aid, char* aprice, char* aauthor)
{
    memcpy(name, aname, sizeof(name));
    memcpy(id, aid, sizeof(id));
    memcpy(price, aprice, sizeof(price));
    memcpy(author, aauthor, sizeof(author));
}

char* Book::getname()
{
    return name;
}

char* Book::getid()
{
    return id;
}

char* Book::getprice()
{
    return price;
}

char* Book::getauthor()
{
    return author;
}

void Book::setname(char* aname)
{
    memcpy(name, aname, sizeof(name));
}

void Book::setid(char* aid)
{
    memcpy(id, aid, sizeof(id));
}

void Book::setprice(char* aprice)
{
    memcpy(price, aprice, sizeof(price));
}

void Book::setauthor(char* aauthor)
{
    memcpy(author, aauthor, sizeof(author));
}

