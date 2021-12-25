# BookManager
Book.h Book.cpp
图书类，成员变量：图书的名称，ISBN，价格，作者；成员方法：获取和设置成员变量。

BookServices.h BookServices.cpp
void writeData(Book book)：向文件中写入图书信息
void readData(int page,int flen)：从文件中读取图书信息
void deleteData(int icount)：从文件中删除图书信息
Book getbook(int count)：从文件中读取一条图书信息
long getfilelength(char fname[])：获取文件的长度


PthServices.h PthServices.cpp
在BookServices的方法的基础上实现了对图书信息多线程的读取写入。

BookView.h BookView.cpp
实现控制台界面
