#ifndef PTHSERVICES_H
#define PTHSERVICES_H
#include"Book.h"
#include"BookServices.h"
#include<string>
#include<map>

class PthServices
{
public:
    PthServices();
    void pthser_writeData(Book book);
    void pthser_readData(int page,long flen);
    void pthser_deleteData(int icount);
    Book pthser_getbook(int count);
    void pthser_getfilelength(char fname[],long* len);

private:
    std::map<std::string,int> pthmap;

};

typedef struct rdbook
{
    int page;
    long len;
}rdbk;
typedef struct getbook
{
    int count;
    Book book;
}gbook;

typedef  struct filelength
{
    char fname[128];
    long len;
}gth;


void* pth_writeData(void* book);
void* pth_readData(void* rdbk);
void* pth_deleteData(void* icount);
void* pth_getbook(void* getbk);
void* pth_getfilelength(void* gfl);
#endif // PTHSERVICES_H
