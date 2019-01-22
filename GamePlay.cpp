#include <iostream>
#include <iomanip>
#include <fstream>
#include <random>
using namespace std;

//global variables
int money = 2000;
int distToTravel = 1600;
int ammo;
int food;
int days = 1;

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

Event missionCreek[2];
Event elitePrep[2];
Event missionPeak[2];
Person players[5];

void init()
{
    //create obstacle classes
    for(int i = 0; i < 10; i++)
    {
        missionCreek[i].dDist = a[i][0];
        missionCreek[i].dHealth = a[i][1];
        missionCreek[i].dAmmo = a[i][2];
        missionCreek[i].dMoney = a[i][3];
        missionCreek[i].dFood = a[i][4];
        //cout << "Done copying a" << endl;
    }
    
    
    for(int i = 0; i < 10; i++)
    {
        elitePrep[i].dDist = b[i][0];
        elitePrep[i].dHealth = b[i][1];
        elitePrep[i].dAmmo = b[i][2];
        elitePrep[i].dMoney = b[i][3];
        elitePrep[i].dFood = b[i][4];
        //cout << "Done copying b" << endl;
        
    }
    
    
    for(int i = 0; i < 10; i++)
    {
        missionPeak[i].dDist = c[i][0];
        missionPeak[i].dHealth = c[i][1];
        missionPeak[i].dAmmo = c[i][2];
        missionPeak[i].dMoney = c[i][3];
        missionPeak[i].dFood = c[i][4];
        //cout << "Done copying c" << endl;
        
    }
    
    //create players
    for (int i = 0; i< 5; i++)
    {
        cout<<"What is player "<< i + 1 << "'s name?"<<endl;
        string name;
        cin >> name;
        players[i].name = name;
        players[i].health = 10;
    }
}


void store()
{
    cout << "WELCOME TO THE STORE" << endl;
    cout << "You must buy ammo and food with your $"  << money << endl;
    cout << "Ammo costs $10 while food costs $20" << endl;
    cout << "How much ammo would you like to buy?" << endl;
    double ammoBoughtraw;
    cin >> ammoBoughtraw;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "You must enter an integer value " << endl;
        cin>>ammoBoughtraw;
    }
    int ammoBought = ammoBoughtraw;
    while (ammoBoughtraw<0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "You can't buy negative ammo"  << endl;
        cin>>ammoBoughtraw;
    }
    int temp = ammoBoughtraw;
    if (ammoBoughtraw!=temp)
    {
        cout << "You have entered a non-integer value. " << ammoBoughtraw << " has been truncated to " << temp << "." << endl;
        ammoBought = temp;
    }
    ammoBought = temp;
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
    money -= ammoBought * 10;
    
    cout << "Money left: $" << money << endl;
    
    cout << "How much food would you like to buy? Food costs $20, and each person consumes 1 food per day" << endl;
    double foodBoughtraw;
    cin >> foodBoughtraw;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "You must enter an integer value " << endl;
        cin>>foodBoughtraw;
    }
    int foodBought = foodBoughtraw;
    while (foodBoughtraw<0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "You can't buy negative food"  << endl;
        cin>>foodBoughtraw;
    }
    int temp2 = foodBoughtraw;
    if (foodBoughtraw!=temp2)
    {
        cout << "You have entered a non-integer value. " << foodBoughtraw << " has been truncated to " << temp2 << "." << endl;
        foodBought = temp2;
    }
    foodBought = temp2;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "You must enter an integer value " << endl;
        cin>>foodBought;
    }
    while(20 * foodBought > money)
    {
        cout<<"This amount is too much, please enter another amount"<<endl;
        cin>>foodBought;
        
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),
                       '\n');
            cout<<"You must enter an integer value "<<endl;
            cin>>foodBought;
        }
    }
    food += foodBought;
    money -= foodBought * 20;
    
    cout << "You have $" << money << " left." << endl;
    cout << "Items bought:" << endl;
    cout << "Food: " << foodBought << endl;
    cout << "Total Food: " << food << endl;
    cout << "Ammo: " << ammoBought << endl;
    cout << "Total Ammo: " << ammo << endl;
    cin.clear();
}

bool gameOn()
{
    cin.clear();
    int dead = 0;
    
    for(int i = 0; i < 5; i++)
    {
        if (players[i].health <= 1)
        {
            cout << players[i].name << " died along the journey on day " << days << " due to bad health." << endl;
            dead++;
        }
    }
    
    if (dead == 5)
    {
        cout << "Everyone on the journey has died and the game is over." << endl;
        return false;
    }
    
    if (distToTravel <= 0)
    {
        cout << "Contratulations! You have made it to Oregon! Let's see how many points you have recieved." << endl;
        return false;
    } else if (days > 30)
    {
        cout << "Your journey has now surpassed 30 days and everyone alive has contracted dysentery. You are all doomed to die." << endl;
        return false;
    }
    
    return true;
}

void updateValues(int dDist, int dHealth, int dAmmo, int dMoney, int dFood) //NOTE: dFood is total amount req'd for the day by one player
{
    cin.clear();
    distToTravel += dDist;
    for (int i = 0; i < 5; i++)
    {
        //if no food left, takes 1 away from each unfed players' health
        if (food <= 0)
        {
            cout << "You are out of food. " << players[i].name << "'s health will drop by 1 every day until they are fed." << endl;
            players[i].health--;
        } else {
            food -= dFood;
        }
    }
    
    days++;
    
    cout << "Distance left to travel: " << distToTravel << endl;
    cout << "$" << money << endl;
    cout << "Ammo Left: " << ammo << endl;
    cout << "Food Left: " << food << endl;
    cout << "Player Health Levels:" << endl;
    for (Person x: players)
    {
        cout << x.name << " - " << x.health << endl;
    }
}

//features

//called in determine_action()
void good_news()
{
    // 3 types of good news randomly chosen
    int variety_news = rand()%3 + 1;
    string g_news_choice;
    switch (variety_news)
    {
        case 1:
            cout << "Your friend is actually low-key smart and took the right shortcut with healing herbs. You have traveled 200 miles and gained 2 health." << endl;
            //now update values
            updateValues(-200, 2,0,0,0);
            break;
            
        case 2:
            cout << "You found a Starbucks vendor leading you to gain 10 health and 20 food." << endl;
            //update
            updateValues(-175, 10, 0,0, 20);
            break;
            
        case 3:
            cout << "You enter a ghost town...a man appears. He is slient. You are afraid. However, he is holding a hot cup of delectable ramen, so you approach him. As you get closer, you see a holster on his side which holds his glock." << endl << "You have 2 choices, interact(enter \"i\") or run away(enter \"r\")" << endl;
            
            cin >> g_news_choice;
            while(g_news_choice!="i"||g_news_choice!="r")
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "You must enter either \"i\" or \"r\"!" << endl;
            }
            if(g_news_choice=="i")
            {
                cout << "Congrats! Interacting with people is the way to go. Your social skills have gotten you a new friend as well as 5 health, 10 ammo, $200, and 10 food" << endl;
                updateValues(-150, 5, 10, 200, 10);
            } else if(g_news_choice=="r"){
                cout << "Your lack of social skills is pathetic. If you could lose a heart...wait you can...you lose 2 health but since you found food in the town you gain 15 food." << endl;
                updateValues(-150, -2, 0,0, 15);
            }else{
                cerr << "some error has occurred at line 150" << endl;
            }
            
            break;
            
        default:
            cerr << "some error has occurred at line 326" << endl;
            break;
    }
    
    
}




//called in determine_action()
void bad_news()
{
    
    //3 types of bad news with varying effects
    int variety_news = rand()%3 + 1;
    string b_news_choice;
    switch (variety_news)
    
    
    {
        case 1:
            cout << "The dum friend who was clearly instructed to do nothing has once again doomed your party. He strolled into a forest and attracted a horde of wild goblins. Though you succesfully fended them all off, you have gone a hundred miles off-track and lost 1 health." << endl;
            //add storyline/punishment
            //add updateValues()
            updateValues(100, -1, 0,0,0);
            break;
            
        case 2:
            cout << "You were mugged along the way by a group of bandits. You lost 10 health, 10 food, 10 ammo, and $100 ";
            updateValues(0, -10, -10, -100, -10);
            break;
        case 3:
            cout << "You enter a small village warm with a welcoming atmosphere. People walking around welcome you in and invite you to rest. They offer a warm shower and then a hearty meal. You finally walk upstairs to rest." << endl << "You have two choices, sleep in the room. You are hesitant because everything feels slightly too perfect (enter \"i\") or leave for the night (enter \"r\") " << endl;
            
            cin >> b_news_choice;
            while (b_news_choice!="i"||b_news_choice!="r")
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "You must enter either \"i\" or \"r\"!" << endl;
                cin.clear();
            }
            if(b_news_choice=="i")
            {
                cout << "Congrats! Your suspicion was correct. You got mugged in your sleep and lost everything. You even got moved into the middle of the forest, away from your destination." << endl;
                updateValues(150, -10, -10, -20, -10);
            }
            else if(b_news_choice=="r")
            {
                cout << "You got played once again. This was a dead-end, you woudlve lost either ways. You got mugged and lost your food and money." << endl;
                updateValues(0, 0, 0,-50, -15);        }
            else
            {
                cerr << "some error has occurred at line ___" << endl;
                
            }
            
            break;
            
        default:
            cerr << "some error has occurred at line ___" << endl;
            break;
    }
}



//conduct each day's action
void determine_action()
{
    while(gameOn())
    {
        //rand num for determining today's action
        int action = rand() % 10 + 1;
        cout << action << endl;
        string ct;
        switch (action)
        {
            case 1 ... 3: //no action - 30%
                cout << "Nothing happened today, but you traveled 80 miles!" << endl;
                updateValues(-80, 0, 0, 0, 1);
                cout << "Press any key to continue." << endl;
                cin >> ct;
                break;
                
            case 4 ... 6: //bad news - 30%
                //debugging: cout << "\nBAD NEWS\n" << endl;
                bad_news();
                cout << "Press any key to continue." << endl;
                cin >> ct;
                break;
                
            case 7 ... 9: //good news - 30%
                //debugging: cout <<"\nGOOD NEWS\n"<<endl;
                //process good news function
                good_news();
                cout << "Press any key to continue." << endl;
                cin >> ct;
                break;
                
            case 10: //store - 10%
                cout << "You have chanced upon a store in the wilderness! If you would not like to buy anything, you do not have to." << endl;
                store();
                updateValues(-80, 0, 0, 0, 1);
                cout << "Press any key to continue." << endl;
                cin >> ct;
                break;
                
            default:
                cerr << "error in choosing today's action" << endl;
                break;
        }
    }
}

int main()
{
    srand (time(NULL)/1000);
    
    cout << "Welcome to Oregon Trail: MSJ Edition! You will be embarking on a 1600 mile journey for 30 days, where only the fittest will survive." << endl;
    
    init();
    store();
    
    //conduct each day's action
    determine_action();
    
    return 0;
}
