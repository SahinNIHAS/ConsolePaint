#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int WIDTH = 16;
const int HEIGHT = 16;
const char SYMBOL_FOR_PAINT = '#';
const char EMPTY = '-';

bool run = true;

void getInfo();
void getMaketArt();
void vectorWrite(vector<char>& vec);
void stop(bool&);
void getCommand();
void myArt(const vector<char>& vec);
void paint(vector<char>& EditArt);
void erese(vector<char>& EditArt);

vector<string> commands = {"paint","erese","exit","getmaket","getart", "help"};
vector<char> art;

int main(void)
{
    
    art.reserve(WIDTH * HEIGHT);
    vectorWrite(art);

    while(run)
    {
        getCommand();
    }

    return 0;
}
void getMaketArt()
{
    int id = 0;
    cout << "Maket art and id's:\n" << endl;
    for(int i = 0; i < WIDTH; ++i)
    {
        for(int j = 0; j < HEIGHT; ++j)
        {
            cout << id << " ";
            ++id;
        }
        ++id;
        cout << endl;
    }
}
void vectorWrite(vector<char>& vec)
{
    for(int i = 0; i < (WIDTH * HEIGHT); ++i)
    {
        vec.push_back(EMPTY);
    }
}
void getInfo()
{
    cout << "Commands:" << endl;
    for(int i = 0; i < commands.size(); ++i)
    {
        cout << "\n" << i << "." << commands[i];
    }
    cout << endl;
}
void stop(bool& run)
{
    run = !run;
}
void myArt(const vector<char>& vec)
{
    int i = 0;
    for(vector<char>::iterator iter = art.begin(); iter != art.end(); ++iter)
    {
        ++i;
        cout << *iter;
        if(i == WIDTH)
        {
            cout << endl;
            i = 0;
        }
        
    }
}
void getCommand()
{
    string command;
    cout << "Enter number command:\n" << endl;
        cin >> command;

    if(command == commands[0])
    {
        paint(art);
    }
    else if(command == commands[1])
    {
        erese(art);
    }
    else if(command == commands[2])
    {
        stop(run);
    }
    else if(command == commands[3])
    {
        getMaketArt();
    }
    else if(command == commands[4])
    {
        myArt(art);
    }
    else if(command == commands[5])
    {
        getInfo();
    }
    else
    {
        cout << "invalid command!" << endl;
    }
}
void paint(vector<char>& EditArt)
{
    int id;
    cout << "Enter number: (-1 - stop)" << endl;
    cout << "DONT USE A CHAR OR STRING!" << endl;
    do
    {
        cin >> id;
        EditArt[id] = SYMBOL_FOR_PAINT;
        myArt(art);
        cout << "\n" << endl;
    } while (id != -1);
}
void erese(vector<char>& EditArt)
{
    int id;
    cout << "Enter number: (-1 - stop)" << endl;
    cout << "DONT USE A CHAR OR STRING!" << endl;
    do
    {
        cin >> id;
        EditArt[id] = EMPTY;
        myArt(art);
        cout << "\n" << endl;
    } while (id != -1);
}