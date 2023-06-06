/*

Company maintains employee information as employee ID, name, designation and
salary. Allow user to add, delete information of employee. Display information of
particular employee. If employee does not exist an appropriate message is displayed. If
it is, then the system displays the employee details. Use index sequential file to maintain
the data.

*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Employee
{
    int id;
    string name;
    string designation;
    double salary;
} rec;

struct Index
{
    int id;
    int index;
} in;

class file
{
    static int i;

public:
    void insert();
    void display();
    pair<int, int> search();
    void remove();
};

int file::i = 0;

void file::insert()
{
    fstream fout;
    fstream findex;
    fout.open("text.txt", ios::out | ios::binary | ios::app);
    findex.open("index.txt", ios::out | ios::binary | ios::app);
    cout << "\n\tEnter id of the employee    : ";
    cin >> rec.id;
    cout << "\n\tEnter a Name of the employee     : ";
    cin >> rec.name;
    cout << "\n\tEnter a designation of the employee : ";
    cin >> rec.designation;
    cout << "\n\tEnter a salary of the employee  : ";
    cin >> rec.salary;
    fout.write((char *)&rec, sizeof(Employee));
    in.id = rec.id;
    in.index = i;
    findex.write((char *)&in, sizeof(Index));
    ++i;
    fout.close();
    findex.close();
}

pair<int, int> file::search()
{
    ifstream fin, findex;
    fin.open("text.txt", ios::in | ios::binary);
    findex.open("index.txt", ios::in | ios::binary);
    int r, pos = 0;
    cout << "\nIndex to be searched : ";
    cin >> r;
    while (findex.read((char *)&in, sizeof(Index)))
    {
        if (in.id = r)
        {
            return pair<int, int>(in.id, pos);
        }
        pos++;
    }
    return pair<int, int>(-1, -1);
}

void file::display()
{
    ifstream fin;
    fin.open("text.txt", ios::in | ios::binary);
    fin.seekg(0, ios::beg);
    cout << "\n\tThe Content of File are:\n";
    cout << "\n\tRoll\tName\tDiv\tAddress";
    while (fin.read((char *)&rec, sizeof(Employee)))
    {
        if (rec.id != -1)
            cout << "\n\t" << rec.id << "\t" << rec.name << "\t" << rec.designation << "\t" << rec.salary;
    }
    fin.close();
}

void file::remove()
{
    fstream f, fi;
    pair<int, int> pos = search();
    if (pos.first == -1)
    {
        cout << "Not in file";
        return;
    }
    f.open("text.txt", ios::out | ios::binary | ios::in);
    f.seekg(0, ios::beg);
    f.seekp(0, ios::beg);
    fi.open("index.txt", ios::out | ios::binary | ios::in);
    fi.seekg(0, ios::beg);
    fi.seekp(0, ios::beg);

    int offset = pos.first * sizeof(Index);
    fi.seekp(offset, ios::beg);
    in.id = -1;
    in.index = -1;
    fi.write((char *)&in, sizeof(Index));
    fi.seekg(0, ios::beg);

    offset = pos.second * sizeof(Employee);
    f.seekp(offset, ios::beg);
    rec.id = -1;
    rec.name = "NULL";
    rec.designation = "NULL";
    rec.salary = -1;
    f.write((char *)&rec, sizeof(Employee));
    f.seekg(0, ios::beg);

    f.close();
    fi.close();
}

int main()
{
    file a;
    a.insert();
    a.insert();
    a.display();
    a.remove();
    a.display();

    return 0;
}
