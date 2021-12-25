#include "BookServices.h"
#include<cstring>
#include<iostream>
#include <iomanip>

void BookServices::writeData(Book book)
{
   
    std::ofstream of;
    char name[NUM1];
    char id[NUM1];
    char price[NUM1];
    char author[NUM2];
    memcpy(name, book.getname(),sizeof(name));
    memcpy(id, book.getid(), sizeof(id));
    memcpy(price, book.getprice(), sizeof(price));
    memcpy(author, book.getauthor(), sizeof(author));
    of.open("book.dat", std::ios::binary | std::ios::app);
    try {

        of.write(name, sizeof(name));
        of.write(id, sizeof(id));
        of.write(price, sizeof(price));
        of.write(author, sizeof(author));

    }
    catch (...) {//
        std::cout << "write file error" << std::endl;
        throw "file error occurred";
        of.close();
    }
    of.close();

}

void BookServices::readData(int page,int flen)
{
    char inname[NUM1];
    char inid[NUM1];
    char inprice[NUM2];
    char inauthor[NUM1];
    bool bindex = false;
    std::ifstream ifs;
    ifs.open("book.dat", std::ios::binary);
    if(flen==0)
    {
        std::cout<<"file is empty."<<std::endl;
        return;
    }
    ifs.seekg((page - 1) * 3 * (NUM1 * 3 + NUM2), std::ios::beg);
    try {
        if (!ifs.fail())
        {

            for (int i = 1; i < 4; i++)
            {
                memset(inname, 0, sizeof(inname));
                memset(inid, 0, sizeof(inid));
                memset(inprice, 0, sizeof(inprice));
                memset(inauthor, 0, sizeof(inauthor));


                if (ifs.tellg() < 0)//tellg(): fail to return -1
                {
                    bindex = false;


                }
                else
                {
                    bindex = true;
                }
                if (bindex)
                {
                    std::cout << std::setw(3) << ((page - 1) * 3 + i);
                }

                ifs.read(inname, sizeof(inname));
                std::cout << std::setw(24) << inname;
                ifs.read(inid, sizeof(inid));
                std::cout << std::setw(24) << inid;
                ifs.read(inprice, sizeof(inprice));
                std::cout << std::setw(12) << inprice;
                ifs.read(inauthor, sizeof(inauthor));
                std::cout << std::setw(12) << inauthor;
                std::cout << std::endl << std::endl;


                if (ifs.tellg() == flen)
                {
                    break;
                }
            }
        }

    }

catch (...) {
    std::cout << "throw file exeception" << std::endl;
    throw "file error occured";
    ifs.close();
}
/*     if(icurpage<ipage)
     {
         icurpage=icurpage+1;

     }*/

ifs.close();

}


void BookServices::deleteData(int icount)
{
    std::streampos respos;
    int idatacount = 0;
    std::fstream file;
    std::fstream tmpfile;
    std::ofstream ofile;
    char tempbuf[NUM1 * 3 + NUM2];
    file.open("book.dat", std::ios::binary | std::ios::in);
    tmpfile.open("temp.dat", std::ios::binary | std::ios::in | std::ios::out | std::ios::trunc);
    file.seekg(0, std::ios::end);
    respos = file.tellg();
    std::cout << "BookServices::deleteData repos=" << respos << std::endl;
     std::cout<<"BookServices::deleteData icount="<<icount<<std::endl;
    idatacount = respos / (NUM1 * 3 + NUM2);
    if (icount<0 || icount>idatacount)
    {
        std::cout << "input number error." << std::endl;
        return;
        //throw "input number error";
    }
    else {
        file.seekg(0, std::ios::beg);
        for (int j = 0; j < idatacount; j++)
        {
            if (j == icount - 1)
            {
                file.seekg(NUM1 * 3 + NUM2, std::ios::cur);
            }
            memset(tempbuf, 0, NUM1 * 3 + NUM2);
            file.read(tempbuf, NUM1 * 3 + NUM2);
            tmpfile.write(tempbuf, NUM1 * 3 + NUM2);
        }
        file.close();
        tmpfile.seekg(0, std::ios::beg);
        ofile.open("book.dat",std::ios::binary);//
        //ofile.seekp((icount-1)*(NUM1*3+NUM2),std::ios::beg);
        for (int j = 0; j < idatacount - 1; j++)
        {

            memset(tempbuf, 0, NUM1 * 3 + NUM2);
            tmpfile.read(tempbuf, NUM1 * 3 + NUM2);
            ofile.write(tempbuf, NUM1 * 3 + NUM2);
        }
    }
    tmpfile.close();
    ofile.close();
    remove("temp.dat");

}
Book BookServices::getbook(int count)
{

    char aname[NUM1];
    char aid[NUM1];
    char aprice[NUM2];
    char aauthor[NUM1];
    std::ifstream ifile;
    ifile.open("book.dat", std::ios::binary);
    try {
        int len = NUM1*3+NUM2;
        ifile.seekg(len * count, std::ios::beg);
        ifile.read(aname, sizeof(aname));//
        // tellg()
        if (ifile.tellg() > 0)
        {
            book.setname(aname);
        }
        if (ifile.tellg() > 0)
        {
            book.setid(aid);
        }
        if (ifile.tellg() > 0)
        {
            book.setprice(aprice);
        }
        if (ifile.tellg() > 0)
        {
            book.setauthor(aauthor);
        }

    }
    catch (...) {
        ifile.close();
    }

    ifile.close();
    return book;

}


long BookServices::getfilelength(char fname[])
{
    std::ifstream ifs;
    ifs.open(fname, std::ios::binary);
    ifs.seekg(0, std::ios::end);
    std::streampos ps = ifs.tellg();
    ifs.seekg(0, std::ios::beg);
    long len = ps;
    ifs.close();
    std::cout<<"BookServices::getfilelength len="<<len<<std::endl;
    return len;
}
