#pragma once
class BookView{
public:
	void showwelcome();
	void showrootmenu();
    char waitview(char t);
	void waituser();
	void guideinput();
	int  getselect();
	int viewdata(int iselpage);
	void delectbookfromfile();
	void mainloop();
};



