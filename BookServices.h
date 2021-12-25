#pragma once
#include<fstream>
#include"Book.h"
class BookServices
{
public:
void writeData(Book book);
void readData(int page,int flen);
void deleteData(int icount);
Book getbook(int count);
long getfilelength(char fname[]);
BookServices()
{

}
~BookServices()
{

}
private:
Book book;

};

