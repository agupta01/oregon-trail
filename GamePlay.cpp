#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int money = 2000;
int distance = 1600;
int ammo;
int food;
struct Person{
    string name; 
    int health;
};
int main()
{
    
    cout<<"Welcome to the Oregon-Trail Mission San Jose Edition"<<endl; 
    Person players[5];
    for (int i =0; i< 5; i++)
    {
        cout<<"What is player "<< i<< " name?"<<endl; 
        string name; 
        cin >> name;
        players[i] = Person{name, 10};
    }
    cout<<"You will be embarking on a 1600 mile journey for 30 days, where only the fittest will survive"<<endl;
    cout<<"Before you begin you must buy ammo and food with your starting $2000"<<endl; 
    cout<<"Ammo costs $10 while food costs $20"<<endl; 
    cout<<"How much ammo would you like to buy?"<<endl; 
    int ammoBought; 
    cin>> ammoBought;
    while(1)
    {
        if(cin.fail())
    {  
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),
        '\n');
        cout<<"You must enter an integer value "<<endl;
        cin>>ammoBought;
    }

    int foodBought; 
    cin>>foodBought;
     while(1)
    {
        if(cin.fail())
    {  
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),
        '\n');
        cout<<"You have entered wrong input"<<endl;
        cin>>ammoBought;
    }

if(!cin.fail())
break;
}
    cout<<"How much food would you like to buy?"<<endl; 

    
    //set characters
    //set item amounts, etc
    while(/*at least one player's health > 0, and distance to finish > 0*/)
    {
        //option to travel
        //obstacles per "turn"
    }

    if (/*died*/)
    {
        cout << "You died along the journey at " << /*print wherever the last person died*/ << endl;
    } else if (/*distance to finish = 0*/)
    {
        cout << "Congratulations! You have made it to Oregon! Let's see how many points you have recieved." << endl;
        //print date of arrival
        //total and print number of points earned
    }
}
