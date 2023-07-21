#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int numbook = 0, numauthor = 0, member = 0;
struct page {
    int pagenumber;
    string text;
};
//--------------------------------------
struct book {
    string bookname;
    string authorname;
    string publisher;
    string ISBN;
    int yearofprint;
    int numpages;
    string borrowed;
    page page2[100];
};
//---------------------------------------
struct author {
    string authorname;
    string ID;
    int numbook_author;
} author1[100];
//---------------------------------------
struct library {
    book book3[100];
} mylibrary;
//---------------------------------------
struct account {
    string username;
    string password;
} user[500];
//---------------------------------------
struct register1 {
    string flname;//first & last name
    string username;
    string password;
};
//----------------------------------------------------------------------------------------------------------------------
void newpassword() {
    cout << "*** Your password must : *** \n"
         << "1.be at least 8 characters \n"
         << "2.have at least one capital & small letter \n"
         << "3.have at least one number\n"//kolesh ta in color2
         << "Enter your password:";

    cin.ignore();
    getline(cin, user[member].password);
    int sizepassword = user[member].password.size();
    if (sizepassword < 8) {
        cout << "your password is not valid.\n";//color1
        newpassword();
    } else {
        int count1 = 0, count2 = 0, count3 = 0;
        for (int j = member; j < member + 1; j++) {
            for (int i = 0; i < sizepassword; i++) {
                if (user[member].password[i] >= 65 && user[member].password[i] <= 91)
                    count1++;
                else if (user[member].password[i] >= 97 && user[member].password[i] <= 122)
                    count2++;
                else if (user[member].password[i] >= 48 && user[member].password[i] <= 57)
                    count3++;
            }
        }
        if (count1 == 0 || count2 == 0 || count3 == 0) {
            cout << "your password is not valid.\n";//color1
            newpassword();
        }
    }
    cout<<endl;
}
//----------------------------------------------------------------------------------------------------------------------
void newaccount1() {
    string flname;;
    cin.ignore();
    cout << "Enter your first & last name:";
    getline(cin, flname);
    cout << "Enter your username:";
    getline(cin,user[member].username);
    newpassword();
    member++;
    cout<<endl;
}
//----------------------------------------------------------------------------------------------------------------------
void password()                                                                             //check password for sign in
{
    cout << "Enter your password:";
    cin.ignore();
    getline(cin, user[member].password);
    int sizepassword = user[member].password.size();
    if (sizepassword < 8) {
        cout << "your password is not true.\n";//color1
        password();
    } else {
        int count1 = 0, count2 = 0, count3 = 0;
        for (int i = 0; i < sizepassword; i++) {
            if (user[member].password[i] >= 65 && user[member].password[i] <= 91)
                count1++;
            else if (user[member].password[i] >= 97 && user[member].password[i] <= 122)
                count2++;
            else if (user[member].password[i] >= 48 && user[member].password[i] <= 57)
                count3++;
        }
        if (count1 == 0 || count2 == 0 || count3 == 0) {
            cout << "your password is not true.\n";//color1
            password();
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------
void signin() {
    cin.ignore();
    cout << "Enter your username:\n";
    getline(cin, user[member].username);
    password();
    member++;
    cout<<endl;
}
//----------------------------------------------------------------------------------------------------------------------
void printaccount()
{
    int find=0;
    cout<<"*Username:"<<user[member-1].username<<endl;
    cout<<"*Password:"<<user[member-1].password<<endl;
    cout<<"<<Borrowed Books>>\n";
    cout<<"--------------------------------\n";
    for(int i=0;i<numbook;i++)
    {
        if(mylibrary.book3[i].borrowed==user[member-1].username)
        {
            cout << "BookName:" << mylibrary.book3[i].bookname << endl;
            cout << "AuthorName:" << mylibrary.book3[i].authorname << endl;
            cout << "Publisher:" << mylibrary.book3[i].publisher << endl;
            cout << "ISBN:" << mylibrary.book3[i].ISBN << endl;
            cout << "YearOfPrint:" << mylibrary.book3[i].yearofprint << endl;
            cout<<"--------------------------------\n";
            find++;
        }
    }
    if(find==0)                                          //when we don't find borrowedbook so Getting out of the loop
    cout<<"You haven't borrowed any book yet.\n";
    cout<<"************************************\n";
}
//----------------------------------------------------------------------------------------------------------------------
void borrow()
{
    string namebook;
    cin.ignore();
    cout<<"Enter the name of book that you want to borrow it:";
    getline(cin,namebook);
    for(int i=0;i<numbook;i++)
    {
        if(mylibrary.book3[i].bookname==namebook)
        {
            if((mylibrary.book3[i].borrowed).size()==0)
                mylibrary.book3[i].borrowed=user[member-1].username;
            else
                cout<<"<<<< This book was borrowed by "<<mylibrary.book3[i].borrowed<<" >>>>\n";

        }
    }
    cout<<"************************************\n";
}
//----------------------------------------------------------------------------------------------------------------------
void addbook() {
    int booknumber;
    cout << "Enter booknumber:";
    cin >> booknumber;
    cin.ignore();
    for (int i = numbook; i < booknumber + numbook; i++) {
        cout << "Enter name of book:\n";
        getline(cin, mylibrary.book3[i].bookname);
        cout << "Enter name of author:\n";
        getline(cin, mylibrary.book3[i].authorname);
        cout << "Enter publisher:\n";
        getline(cin, mylibrary.book3[i].publisher);
        cout << "Enter ISBN:\n";
        getline(cin, mylibrary.book3[i].ISBN);
        cout << "Enter year of print:\n";
        cin >> mylibrary.book3[i].yearofprint;
        cout << "Enter number of pages:\n";
        cin >> mylibrary.book3[i].numpages;
        cin.ignore();
        for (int j = 0; j < mylibrary.book3[i].numpages; j++) {
            mylibrary.book3[i].page2[j].pagenumber = i;
            cout << "Enter text:";
            getline(cin, mylibrary.book3[i].page2[j].text);
        }
        cout << "******************************\n";
    }
    numbook += booknumber;
}
//----------------------------------------------------------------------------------------------------------------------
void addauthor() {
    int authornumber;
    cout << "Enter number of author:";
    cin >> authornumber;
    for (int i = numauthor; i < authornumber; i++) {
        cin.ignore();
        cout << "Enter name of author:";
        getline(cin, author1[i].authorname);
        cout << "Enter ID:";
        cin >> author1[i].ID;
        cout << "Enter booknumber:";
        cin >> author1[i].numbook_author;
        for (int j = numbook; j < numbook + author1[i].numbook_author; j++) {
            cin.ignore();
            cout << "Enter name of book:\n";
            getline(cin, mylibrary.book3[j].bookname);
            cout << "Enter name of author:\n";
            getline(cin, mylibrary.book3[j].authorname);
            cout << "Enter publisher:\n";
            getline(cin, mylibrary.book3[j].publisher);
            cout << "Enter ISBN:\n";
            getline(cin, mylibrary.book3[j].ISBN);
            cout << "Enter year of print:\n";
            cin >> mylibrary.book3[j].yearofprint;
            cout << "Enter number of pages:\n";
            cin >> mylibrary.book3[j].numpages;
            cin.ignore();
            for (int k = 0; k < mylibrary.book3[j].numpages; k++) {
                mylibrary.book3[i].page2[k].pagenumber = i;
                cout << "Enter text:";
                getline(cin, mylibrary.book3[j].page2[k].text);
            }
        }
        numbook += author1[i].numbook_author;
        cout << "*******************************\n";
    }
    numauthor += authornumber;
}
//----------------------------------------------------------------------------------------------------------------------
void authorinformation()                                                            //show information of author
{
    int totalnumbookauthor = 0;
    string name;
    cin.ignore();
    cout << "Enter the name of author that you want to know her/his information :";
    getline(cin, name);
    for (int i = 0; i < numbook; i++) {
        if (mylibrary.book3[i].authorname == name) {
            cout << "AuthorName:" << author1[i].authorname << endl;
            cout << "ID:" << author1[i].ID << endl;
            for (int k = 0; k < numbook; k++) {
                if (mylibrary.book3[k].authorname == name) {
                    totalnumbookauthor++;
                }
            }
            cout << "NumberOfBook:" << totalnumbookauthor << endl;
            cout << "---------------------------------\n";
            for (int j = 0; j < numbook; j++) {
                if (mylibrary.book3[j].authorname == name) {
                    cout << "BookName:" << mylibrary.book3[j].bookname << endl;
                    cout << "AuthorName:" << mylibrary.book3[j].authorname << endl;
                    cout << "Publisher:" << mylibrary.book3[j].publisher << endl;
                    cout << "ISBN:" << mylibrary.book3[j].ISBN << endl;
                    cout << "YearOfPrint:" << mylibrary.book3[j].yearofprint << endl;
                    cout << "--------------------------\n";
                }
            }
            break;
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------
void searchbookbynamebook()                                                     //show information of book with bookname
{
    string name;
    cin.ignore();
    cout << "Enter name of book:";
    getline(cin, name);
    for (int i = 0; i < numbook; i++) {
        if (mylibrary.book3[i].authorname == name) {
            cout << "BookName:" << mylibrary.book3[i].bookname << endl;
            cout << "AuthorName:" << mylibrary.book3[i].authorname << endl;
            cout << "Publisher:" << mylibrary.book3[i].publisher << endl;
            cout << "ISBN:" << mylibrary.book3[i].ISBN << endl;
            cout << "YearOfPrint:" << mylibrary.book3[i].yearofprint << endl;
            for (int j = 0; j < mylibrary.book3[i].numpages; j++) {
                cout << "<<Page" << j + 1 << ">>";
                cout << mylibrary.book3[i].page2[j].text << endl;
            }
            cout << "--------------------------------\n";
            break;//if we have some book with same name break does not need(print all book with that name)
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------
void listbook()                                                                                //list of book of library
{
    for (int i = 0; i < numbook; i++) {
        cout << "BookName:" << mylibrary.book3[i].bookname << endl;
        cout << "AuthorName:" << mylibrary.book3[i].authorname << endl;
        cout << "Publisher:" << mylibrary.book3[i].publisher << endl;
        cout << "ISBN:" << mylibrary.book3[i].ISBN << endl;
        cout << "YearOfPrint:" << mylibrary.book3[i].yearofprint << endl;
        for (int j = 0; j < mylibrary.book3[i].numpages; j++) {
            cout << "<<Page" << j + 1 << ">>";
            cout << mylibrary.book3[i].page2[j].text << endl;
        }
        cout<< "Borrower:"<<mylibrary.book3[i].borrowed<<endl;
        cout << "----------------------------------------" << endl;
    }
}
//----------------------------------------------------------------------------------------------------------------------
void deletebook()                                                                                 //delete book & author
{
    string nameauthor;
    string namebook;
    cin.ignore();
    cout << "Enter name of author that you want to delete:";
    getline(cin, nameauthor);
    cout << "Enter name of book that you want to delete:";
    getline(cin, namebook);
    for (int i = 0; i < numbook; i++) {
        if ((mylibrary.book3[i].authorname == nameauthor) && (mylibrary.book3[i].bookname == namebook)) {
            mylibrary.book3[i].bookname = mylibrary.book3[numbook - 1].bookname;
            mylibrary.book3[i].authorname = mylibrary.book3[numbook - 1].authorname;
            mylibrary.book3[i].publisher = mylibrary.book3[numbook - 1].publisher;
            mylibrary.book3[i].ISBN = mylibrary.book3[numbook - 1].ISBN;
            mylibrary.book3[i].yearofprint = mylibrary.book3[numbook - 1].yearofprint;
            mylibrary.book3[i].numpages = mylibrary.book3[numbook - 1].numpages;
            for (int j = 0; j < mylibrary.book3[i].numpages; j++) {
                mylibrary.book3[i].page2[j].text = mylibrary.book3[numbook - 1].page2[j].text;
            }
        }
        numbook--;
        break;
    }
}
//----------------------------------------------------------------------------------------------------------------------
void filterauthor() {
    string name;
    cin.ignore();
    cout << "Enter name of author:";
    getline(cin, name);
    for (int i = 0; i < numbook; i++) {
        if (mylibrary.book3[i].authorname == name) {
            cout << "BookName:" << mylibrary.book3[i].bookname << endl;
            cout << "AuthorName:" << mylibrary.book3[i].authorname << endl;
            cout << "Publisher:" << mylibrary.book3[i].publisher << endl;
            cout << "ISBN:" << mylibrary.book3[i].ISBN << endl;
            cout << "YearOfPrint:" << mylibrary.book3[i].yearofprint << endl;
            cout << "--------------------------------\n";
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------
void filteryear() {
    int year;
    cin.ignore();
    cout << "Enter year:";
    cin >> year;
    for (int i = 0; i < numbook; i++) {
        if (mylibrary.book3[i].yearofprint == year) {
            cout << "BookName:" << mylibrary.book3[i].bookname << endl;
            cout << "AuthorName:" << mylibrary.book3[i].authorname << endl;
            cout << "Publisher:" << mylibrary.book3[i].publisher << endl;
            cout << "ISBN:" << mylibrary.book3[i].ISBN << endl;
            cout << "YearOfPrint:" << mylibrary.book3[i].yearofprint << endl;
            cout << "--------------------------------\n";
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------
void filterpublisher() {
    string publisher;
    cin.ignore();
    cout << "Enter publisher:";
    getline(cin, publisher);
    for (int i = 0; i < numbook; i++) {
        if (mylibrary.book3[i].publisher == publisher) {
            cout << "BookName:" << mylibrary.book3[i].bookname << endl;
            cout << "AuthorName:" << mylibrary.book3[i].authorname << endl;
            cout << "Publisher:" << mylibrary.book3[i].publisher << endl;
            cout << "ISBN:" << mylibrary.book3[i].ISBN << endl;
            cout << "YearOfPrint:" << mylibrary.book3[i].yearofprint << endl;
            cout << "--------------------------------\n";
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------
void editauthor() {
    string name;
    cin.ignore();
    cout << "Enter the name of author that you want to edit her/his information :";
    getline(cin, name);
    for (int i = 0; i < numbook; i++) {
        if (mylibrary.book3[i].authorname == name) {
            cout << "AuthorName:\n";
            getline(cin, author1[i].authorname);
            cout << "ID:\n";
            getline(cin, author1[i].ID);
            for (int j = 0; j < numbook; j++) {
                if (mylibrary.book3[j].authorname == name) {
                    cout << "BookName:\n";
                    getline(cin, mylibrary.book3[j].bookname);
                    cout << "AuthorName:\n";
                    getline(cin, mylibrary.book3[j].authorname);
                    cout << "Publisher:\n";
                    getline(cin, mylibrary.book3[j].publisher);
                    cout << "ISBN:\n";
                    getline(cin, mylibrary.book3[j].ISBN);
                    cout << "YearOfPrint:\n";
                    cin >> mylibrary.book3[j].yearofprint;
                    cout << "**************************\n";
                }
            }
            break;
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------
void editbook() {
    string name;
    cin.ignore();
    cout << "Enter name of book that you want to edit it :";
    getline(cin, name);
    for (int i = 0; i < numbook; i++) {
        if (mylibrary.book3[i].bookname == name) {
            cout << "BookName:";
            getline(cin, mylibrary.book3[i].bookname);
            cout << "AuthorName:";
            getline(cin, mylibrary.book3[i].authorname);
            cout << "Publisher:";
            getline(cin, mylibrary.book3[i].publisher);
            cout << "ISBN:";
            getline(cin, mylibrary.book3[i].ISBN);
            cout << "YearOfPrint:";
            cin >> mylibrary.book3[i].yearofprint;
            cout << "*************************\n";
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------
void sortbookbyyear() {
    struct book temp;
    for (int i = 0; i < numbook - 1; i++) {
        for (int j = 0; j < numbook - i - 1; j++) {
            if (mylibrary.book3[j].yearofprint > mylibrary.book3[j + 1].yearofprint) {
                temp = mylibrary.book3[j];
                mylibrary.book3[j] = mylibrary.book3[j + 1];
                mylibrary.book3[j + 1] = temp;
            }
        }
    }
    listbook();
}
//----------------------------------------------------------------------------------------------------------------------
void searchphraseinpage() {
    string name;
    cin.ignore();
    cout << "Enter name of book that you want to search in:";
    getline(cin, name);
    int bookindex;
    for (int i = 0; i < numbook; i++) {
        if (mylibrary.book3[i].bookname == name) {
            bookindex = i;
            break;
        }
    }
    int f=0;
    string phrase;
    cout << "Enter the phrase that you want to search :";
    getline(cin, phrase);
    for (int i = 0; i < mylibrary.book3[bookindex].numpages; i++) {
        char *find;
        find = strstr((mylibrary.book3[bookindex].page2[i].text).c_str(), phrase.c_str());
        if (find)
        {cout << "<<Page " << i + 1 << ">>" << endl;
            f++;}
    }
    if(f==0)
    cout<<"<< Not found >>";
}
//----------------------------------------------------------------------------------------------------------------------
void printpagebynumpage() {
    string name;
    cin.ignore();
    cout << "Enter name of book that you want to print page of it:";
    getline(cin, name);
    int bookindex;
    for (int i = 0; i < numbook; i++) {
        if (mylibrary.book3[i].bookname == name) {
            bookindex = i;
            break;
        }
    }
    int numpage;
    cout << "Enter number of page that you want to print:";
    cin >> numpage;
    for (int i = 0; i < mylibrary.book3[bookindex].numpages; i++) {
        if (numpage == i + 1) {
            cout << endl << mylibrary.book3[bookindex].page2[i].text << endl;
            break;
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------
int printstart() {
    //system("color 4");
    cout << '\n'
         << "------------------<<<<<<<<<<<<<<<<<<<<<<<<<< Welcome to My Little Library >>>>>>>>>>>>>>>>>>>>>>>>--------------------\n"
         << '\n'
         << "                            [1.Sign in]                                     [2.Creat Account]                         \n"
         << "Enter your choice:";
    int n;
    cin >> n;
    if (n == 1)
        signin();
    if (n == 2)
        newaccount1();
}
//----------------------------------------------------------------------------------------------------------------------
void printmenu() {
    cout<<'\n'
        << "--------------------------------<<<<<<<<<<<<<<<<<<<<<<<<< Menu >>>>>>>>>>>>>>>>>>>>>>>>>>>----------------------------\n"
        << "                        [1] Add book to library                                     [10] Filter books by Year\n"
        << "                        [2] Delete book from library                                [12] Filter books by Author's name\n"
        << "                        [3] Add new author                                          [13] Filter books by Publisher\n"
        << "                        [4] Add book to author's books                              [14] Sort books\n"
        << "                        [5] Delete book from author's books                         [15] Search phrase in page\n"
        << "                        [6] Edit author's information                               [16] Print page\n"
        << "                        [7] Edit book's information                                 [17] Borrow book\n"
        << "                        [8] List of library's book                                  [18] Your Account\n"
        << "                        [9] Author's information                                    [19] Sign out\n"
        << "                        [10] Book's information                                     [20] Exit\n"
        << "\nEnter your choice:";
}
//----------------------------------------------------------------------------------------------------------------------
int main() {
    printstart();
    int m;
    while (m!=20)
    {
        printmenu();
        cin>>m;
        cout<<"**************************************\n";

        if(m==1)
            addbook();
        if(m==2)
            deletebook();
        if(m==3)
            addauthor();
        if(m==4)
            addbook();
        if(m==5)
            deletebook();
        if(m==6)
            editauthor();
        if(m==7)
            editbook();
        if(m==8)
            listbook();
        if(m==9)
            authorinformation();
        if(m==10)
            searchbookbynamebook();
        if(m==11)
            filteryear();
        if(m==12)
            filterauthor();
        if(m==13)
            filterpublisher();
        if(m==14)
            sortbookbyyear();
        if(m==15)
            searchphraseinpage();
        if(m==16)
            printpagebynumpage();
        if(m==17)
            borrow();
        if(m==18)
            printaccount();
        if(m==19)
            printstart();
    }
}
