#include <iostream>
#include <set>
using namespace std;

set<string> make_exit_commands()
{
    return {"q", "quit", "e", "exit"};
}

int main()
{
    string input;

    while (true)
    {
        cout << "Write something" << endl;
        cin >> input;
        cout << "Your worte : " << input << endl;
        if(make_exit_commands().count(input) != 0){
            break;
        }
        // cout << "This is a translator, but it does nothing for now..." << endl;
        // cin.ignore();
    }

    return 0;
}