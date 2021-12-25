#include "BookView.h"
#include"Book.h"
#include "PthServices.h"
#include<iostream>
#include<iomanip>
#include<pthread.h>
#include<cctype>
#include<cstdio>
void BookView::showwelcome()
{
    for (int i = 0; i < 7; i++)
    {
        std::cout << std::endl;

    }

    std::cout << std::setw(40);
    std::cout << "***************************" << std::endl;
    std::cout << std::setw(36);
    std::cout << "book manager system" << std::endl;
    std::cout << std::setw(40);
    std::cout << "***************************" << std::endl;

}
void BookView::showrootmenu()
{
    std::cout << std::setw(30);
    std::cout << "select function:" << std::endl;
    std::cout << std::endl;
    std::cout << std::setw(36);
    std::cout << "1. add a book" << std::endl;
    std::cout << std::endl;
    std::cout << std::setw(36);
    std::cout << "2. list books" << std::endl;
    std::cout << std::endl;
    std::cout << std::setw(36);
    std::cout << "3.delete book" << std::endl;


}
char BookView::waitview(char t)
{
    char ch;
    int flag = 1;
    while (flag) {

        std::cout << "enter number to choice page,enter 0 to quit(0-" << t << "):";

        std::cin >> ch;




    }

    std::cout << std::endl;
    return ch;

}


void BookView::waituser()
{

    char choice;
    do {
        std::cout << "enter q to quit:";
        std::cin >> choice;
    } while (choice != 'q');
    if(choice=='q')
    {
        system("exit");
    }

}
void BookView::guideinput()
{
    char inname[NUM1];
    char inid[NUM1];
    char inprice[NUM2];
    char inauthor[NUM1];
    std::cout << "input name:";
    std::cin >> inname;
    std::cout << "input ISBN:";
    std::cin >> inid;
    std::cout << "input price:";
    std::cin >> inprice;
    std::cout << "input author:";
    std::cin >> inauthor;
    Book book(inname, inid, inprice, inauthor);
    PthServices ptser;
   ptser.pthser_writeData(book);

    std::cout << "Write Finish" << std::endl;

}



int BookView::viewdata(int iselpage = 1)
{
    int ipage = 0;
    int icurpage = 0;
    int idatacount = 0;
    icurpage = iselpage;
    char str[]="book.dat";
    PthServices ptser;
    long flen;
    ptser.pthser_getfilelength(str,&flen);
    std::cout<<"BookView::viewdata flen="<<flen<<std::endl;
    idatacount = flen / (NUM1 * 3 + NUM2);
    if (idatacount % 3 == 0)
    {
        ipage = idatacount / 3;
    }
    else
    {
        ipage = idatacount / 3 + 1;
    }
    // clearscreen();
    std::cout << "all records:" << idatacount << "  ";
    std::cout << "all pages:" << ipage << "  ";
    std::cout << "current page:" << icurpage << "  ";
    std::cout << std::endl;
    std::cout << std::setw(5) << "Index";
    std::cout << std::setw(22) << "Name" << std::setw(22) << "isbn";
    std::cout << std::setw(15) << "Price" << std::setw(15) << "Author";
    std::cout << std::endl;   
    ptser.pthser_readData(icurpage,flen);
    return ipage;
}

void BookView::delectbookfromfile()
{
    int delcount;
    std::cout << "input delete index:";
    std::cin >> delcount;
    std::cout << std::endl;
    PthServices ptser;
   ptser.pthser_deleteData(delcount);
    std::cout << "delete finish" << std::endl;
}
void BookView::mainloop()
{

    //showwelcome();
    while (1) {
        // clearscreen();
        showwelcome();
        showrootmenu();
        int flag=0;
       char choice=1;
       int chint;
        int page=0;
        char a;
        std::cin.clear();
        std::cout << "input(1-3):";
        std::cin >>a;
        switch (a) {

        case '1':
            //   clearscreen();
            guideinput();
            waituser();
            break;
        case '2':
            //   clearscreen();
             page=viewdata(1);
            do {

                std::cout << "enter number to choice page,enter 0 to quit(0-" << page << "):";
                std::cin >> choice;
                chint=choice-48;
                if(chint==0)
                {
                    flag=0;
                }
                else  if (chint>0&&chint<=page)
                {
                    viewdata(chint);
                     flag=1;

                }else{
                    flag=1;
                }

                std::cin.clear();

            } while (flag);

            break;

        case '3':
            // clearscreen();
            delectbookfromfile();
            waituser();
            break;
        default:
             std::cout << "enter number to choice page,enter 0 to quit(0-3).";
             break;

        }
    }
}
