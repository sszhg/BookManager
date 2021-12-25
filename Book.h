#pragma once
#define NUM1 128
#define NUM2 8
class Book
{

public:
    Book();
    Book(char* aname, char* aid, char* aprice, char* aauthor);
    ~Book() {};
public:
    char* getname();
    void setname(char* aname);
    char* getid();
    void setid(char* aid);
    char* getprice();
    void setprice(char* aprice);
    char* getauthor();
    void setauthor(char* aauthor);


private:
    char name[NUM1];
    char id[NUM1];
    char price[NUM2];
    char author[NUM1];


};


