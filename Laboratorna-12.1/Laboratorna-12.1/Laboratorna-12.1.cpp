#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
#include <string>

using namespace std;

void CreateBIN(const char* fname)
{
    ofstream fout(fname, ios::binary);
    char ch;
    string s;
    do
    {
        cin.get();
        cin.sync();
        cout << "Введіть рядок: ";
        getline(cin, s);
        for (unsigned i = 0; i < s.length(); i++)
            fout.write((char*)&s[i], sizeof(s[i]));
        cout << "Продовжити? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << endl;
}

void PrintBIN(const char* fname)
{
    ifstream fin(fname, ios::binary);
    char c;
    while (fin.read((char*)&c, sizeof(c)))
    {
        cout << c << endl;
    }
    cout << endl;
}

void ProcessBIN(const char* fname, const char* gname)
{
    ifstream f(fname, ios::binary);
    ofstream g(gname, ios::binary);
    char c;
    while (f.read((char*)&c, sizeof(c)))
    {
        if (strpbrk(&c, "0123456789") == nullptr)
            g.write((char*)&c, sizeof(c));
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char fname[100];
    cout << "Введіть ім'я першого файлу: ";
    cin >> fname;
    CreateBIN(fname);
    PrintBIN(fname);

    char gname[100];
    cout << "Введіть ім'я другого файлу: ";
    cin >> gname;
    ProcessBIN(fname, gname);
    PrintBIN(gname);

    return 0;
}
