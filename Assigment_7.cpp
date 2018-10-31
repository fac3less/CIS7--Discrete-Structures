#include <iostream>
#include <regex>
#include <vector>

using namespace std;

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod, vector<int>&towerA, vector<int>&towerB, vector<int>&towerC);
void removeDisk(char from_rod,vector<int>&towerA, vector<int>&towerB, vector<int>&towerC);
void addDisk(int n, char to_rod,vector<int>&towerA, vector<int>&towerB, vector<int>&towerC);
void printTowers(vector<int>&towerA, vector<int>&towerB, vector<int>&towerC);

int main()
{
    vector <int> towerA;
    vector <int> towerB;
    vector <int> towerC;
    regex rx("(\\d*)");
    string n;
    cout << "Tower Of Hanoi! How many disk would you like to use? ";
    do
    {
        cout << "Number of Disk: ";
        cin >> n;
    }
    while (!regex_match(n,rx));
    //populate tower A with starting number of disks.
    for (int i = stoi(n); i > 0; i--)
    {
        towerA.push_back(i);
    }
    printTowers(towerA, towerB, towerC);
    cout << endl;
    towerOfHanoi(stoi(n), 'A', 'C', 'B', towerA, towerB, towerC);
    cout << endl;
    return 0;
}
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod ,vector<int>&towerA, vector<int>&towerB, vector<int>&towerC)
{
    if (n == 1)
    {
        removeDisk(from_rod, towerA, towerB,towerC);
        addDisk(n, to_rod, towerA, towerB, towerC);
        printTowers(towerA, towerB,towerC);
        cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod, towerA, towerB, towerC);
    removeDisk(from_rod, towerA, towerB,towerC);
    addDisk(n, to_rod, towerA, towerB, towerC);
    printTowers(towerA, towerB,towerC);
    cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod, towerA, towerB, towerC);
}
void removeDisk(char from_rod,vector<int>&towerA, vector<int>&towerB, vector<int>&towerC)
{
    if (from_rod == 'A')
    {
        towerA.pop_back();
    }
    else if (from_rod == 'B')
    {
        towerB.pop_back();
    }
    else if (from_rod == 'C')
    {
        towerC.pop_back();
    }
}
void addDisk(int n, char to_rod,vector<int>&towerA, vector<int>&towerB, vector<int>&towerC)
{
    if (to_rod == 'A')
    {
        towerA.push_back(n);
    }
    else if (to_rod == 'B')
    {
        towerB.push_back(n);
    }
    else if (to_rod == 'C')
    {
        towerC.push_back(n);
    }
}
void printTowers(vector<int>&towerA, vector<int>&towerB, vector<int>&towerC)
{
    cout << "Press [enter] to see next move." << endl;
    cin.get();
    system("clear");
    cout << "Tower  A: ";
    for (unsigned int i = 0; i < towerA.size(); i++)
    {
      cout << towerA.at(i)<< "-";
    }
    cout << endl;
    cout << "Tower  B: ";
    for (unsigned int i = 0; i < towerB.size(); i++)
    {
      cout << towerB.at(i)<< "-";
    }
    cout << endl;
    cout << "Tower  C: ";
    for (unsigned int i = 0; i < towerC.size(); i++)
    {
      cout << towerC.at(i)<< "-";
    }
    cout << endl;
}
