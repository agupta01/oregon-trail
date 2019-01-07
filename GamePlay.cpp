#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int money = 2000;
int distance = 1600;
int ammo;
int food;
//aruaruaruaru
struct Event
{
    int dDist;
    int dHealth;
    int dAmmo;
    int dMoney;
    int dFood;
};

struct Person{
    string name; 
    int health;
};

int a[10][5]={{0,-2,0,0,0},
              {0,0,0,0,-150},  
              {0,-1,0,0,0},  
              {0,0,0,0,-100},  
              {0,0,-10,0,0},  
              {0,0,-20,0,0},  
              {0,0,0,-200,0},  
              {0,0,0,-50,0},  
              {-50,0,0,0,0},  
              {-10,0,0,0,0}};

int b[10][5]={{0,-2,0,0,0},
              {0,0,0,0,-500},  
              {0,-1,0,0,0},  
              {0,0,0,0,-600},  
              {0,0,-5,0,0},  
              {0,0,-10,0,0},  
              {0,0,0,0,-100},  
              {0,0,0,-300,0},  
              {-150,0,0,0,0},  
              {-50,0,0,0,0}};

int c[10][5]={{0,0,-20,0,0},
              {-100,0,0,0,0},  
              {0,-2,0,0,0},  
              {0,-3,0,0,0},  
              {0,0,-30,0,0},  
              {-10,0,0,0,0},  
              {0,0,0,-25,0},  
              {0,0,0,-250,0},  
              {0,0,0,0,-100},  
              {0,0,0,0,-30}};

int main()
{
    
    cout<<"Welcome to the Oregon-Trail Mission San Jose Edition"<<endl;
    Event missionCreek[2];
    for(int i = 0; i < 2; i++)
    {
        missionCreek[i].dDist = a[i][0];
        missionCreek[i].dHealth = a[i][1];
        missionCreek[i].dAmmo = a[i][2];
        missionCreek[i].dMoney = a[i][3];
        missionCreek[i].dFood = a[i][4];
    }
    
    Event elitePrep[2];
    for(int i = 0; i < sizeof(b); i++)
    {
        elitePrep[i].dDist = b[i][0];
        elitePrep[i].dHealth = b[i][1];
        elitePrep[i].dAmmo = b[i][2];
        elitePrep[i].dMoney = b[i][3];
        elitePrep[i].dFood = b[i][4];
    }

    Event missionPeak[2];
    for(int i = 0; i < sizeof(c); i++)
    {
        missionPeak[i].dDist = c[i][0];
        missionPeak[i].dHealth = c[i][1];
        missionPeak[i].dAmmo = c[i][2];
        missionPeak[i].dMoney = c[i][3];
        missionPeak[i].dFood = c[i][4];
    } 
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
    
        if(cin.fail())
    {  
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),
        '\n');
        cout<<"You must enter an integer value "<<endl;
        cin>>ammoBought;
    }
    while(10 * ammoBought > money)
    {
        cout<<"This amount is too much, please enter another amount"<<endl;
        cin>>ammoBought;
        if(cin.fail())
    {  
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),
        '\n');
        cout<<"You must enter an integer value "<<endl;
        cin>>ammoBought;
    }
    }
    ammo += ammoBought;
    money -= ammoBought *10;
    cout << "How much food would you like to buy? Food costs $20"
    int foodBought;
    cin >> foodBought;
    if(cin.fail())
    {  
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),
        '\n');
        cout<<"You must enter an integer value "<<endl;
        cin>>foodBought;
    }
    while(foodBought*20>money)
    {
        cout<<"This amount is too much, please enter another amount"<<endl;
        cin>>foodBought;
        if(cin.fail())
    {  
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),
        '\n');
        cout<<"You must enter an integer value "<<endl;
        cin>>ammoBought;
    }
    }
    food +=foodBought;
    money -= foodBought*20;
    
    

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
