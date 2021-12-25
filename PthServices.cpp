#include "PthServices.h"
#include<iostream>
#include<cstring>
PthServices::PthServices()
{

}
void* pth_writeData(void* book)
{
    BookServices bks;
    Book *bk=(Book*)book;
    bks.writeData(*bk);
    return NULL;

}
void* pth_readData(void* rk)
{
    BookServices bks;
    rdbk *r=(rdbk *)rk;
    int pg=r->page;
    long flen=r->len;
    bks.readData(pg,flen);
    return NULL;

}
void* pth_deleteData(void* icount)
{
     BookServices bks;
     int *cnt=(int *)icount;
     std::cout<<"pth_deleteData cnt="<<*cnt<<std::endl;
    bks.deleteData(*cnt);
    return NULL;
}
void* pth_getbook(void* gtbk)
{
    BookServices bks;
    gbook *gk=(gbook*)gtbk;
    int count=gk->count;
    Book book=bks.getbook(count);
    gk->book=book;
    return NULL;

}
void* pth_getfilelength(void* gfl)
{
    BookServices bks;
    gth* gn=(gth*)gfl;
    char fname[128];
    memcpy(fname,gn->fname,strlen(gn->fname)+1);
    long tmp=bks.getfilelength(fname);
    gn->len=tmp;
    return NULL;
}

void PthServices::pthser_writeData(Book book)
{
    pthread_t pid;
    std::cout<<"start writing"<<std::endl;
    int ret=pthread_create(&pid,NULL,pth_writeData,&book);
    if(ret!=0)
    {
        std::cout<<"create PthServices::pthser_writeData fail"<<std::endl;
    }

      pthread_join(pid,NULL);
       std::cout<<"PthServices::pthser_writeData£ºfinish writing"<<std::endl;
   // pthread_exit(NULL);
}

void PthServices::pthser_readData(int page,long flen)
{
    rdbk *rk=new rdbk;
    rk->page=page;
    rk->len=flen;
    pthread_t pid;
     std::cout<<"start reading"<<std::endl;
    int ret=pthread_create(&pid,NULL,pth_readData,rk);
    if(ret!=0)
    {
        std::cout<<"create PthServices::pthser_readData fail"<<std::endl;
    }

     pthread_join(pid,NULL);
      std::cout<<"finish reading"<<std::endl;
    //pthread_exit(NULL);
}

void PthServices::pthser_deleteData(int icount)
{
    pthread_t pid;
     std::cout<<"start deleting"<<std::endl;
    int ret=pthread_create(&pid,NULL,pth_deleteData,&icount);
    if(ret!=0)
    {
        std::cout<<"create PthServices::pthser_deleteData fail"<<std::endl;
    }
     std::cout<<"finish deleting"<<std::endl;
      pthread_join(pid,NULL);
    //pthread_exit(NULL);
}

Book PthServices::pthser_getbook(int count)
{
    pthread_t pid;
    gbook *gk=new gbook;
    gk->count=count;
    int ret=pthread_create(&pid,NULL,pth_getbook,gk);

    if(ret!=0)
    {
        std::cout<<"create PthServices::pthser_getbook"<<std::endl;
    }
     pthread_join(pid,NULL);
      Book book=gk->book;
    delete gk;

    return book;
}

void PthServices::pthser_getfilelength(char fname[],long* len)
{
    pthread_t pid;
    gth *gn = new gth;
    memcpy(gn->fname,fname,strlen(fname)+1);
    std::cout<<"start reading length of file"<<std::endl;
    int ret=pthread_create(&pid,NULL,pth_getfilelength,gn);


    if(ret!=0)
    {
        std::cout<<"create PthServices::pthser_getfilelength fail"<<std::endl;
    }

     pthread_join(pid,NULL);
     memcpy(len,&(gn->len),sizeof (long));
     std::cout<<"PthServices::pthser_getfilelength file length="<<gn->len<<std::endl;
     std::cout<<"finish reading length of file"<<std::endl;
    delete gn;

}
