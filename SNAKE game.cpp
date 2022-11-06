#include<bits/stdc++.h>
#include<iostream>
#include<conio.h>
#include<windows.h>
typedef long long int ll;
using namespace std;
bool gameOver;
const int width=20;
const int height=20;
ll x,y,fruitX,fruitY,score;
ll tailX[100],tailY[100];
ll nTail;
enum eDirection{STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;

void Setup()
{
    gameOver=false;
    dir=STOP;
    x=width/2;
    y=height/2;
    fruitX=rand()%width; //random number generator
    fruitY=rand()%height;
    score=0;
}

void Draw()
{
    system("cls");
    for (ll i = 0 ; i < width+2 ; i++)  //width+2 cz kuna fillup kora lagbo
    {
        cout<<"#"; //uprer wall print korram
    }
    cout<<endl;

    for (ll i = 0 ; i < height ; i++) //matrix
    {
        for (ll j = 0 ; j < width ; j++)
        {
            if(j == 0) cout<< "#"; //y axix er wall bam diker
            if(i==y && j==x) cout<<"O"; //snaake head
            else if(i==fruitY && j==fruitX) cout<<"F"; //fruit
            else //tail print kora
            {
                bool print=false;
                for(ll k = 0 ; k < nTail ; k++)
                {
                    if(tailX[k]==j && tailY[k]==i)
                    {
                        cout<<"*";
                        print=true;
                    }
                }
                if(!print) cout<<" ";
            }
            if(j == width-1) cout<< "#"; //y axix er wall dandike
        }
        cout<<endl;
    }

    for (ll i = 0 ; i < width+2 ; i++)
    {
        cout<<"#"; //nicher wall print korram
    }
    cout<<endl;
    cout<<"Score: "<<score<<endl;
}

void Input()
{
    if(_kbhit()) //keyboard input
    {
        switch(_getch())
        {
            case 'a':
                dir=LEFT;
                break;
            case 'd':
                dir=RIGHT;
                break;
            case 'w':
                dir=UP;
                break;
            case 's':
                dir=DOWN;
                break;
            case 'x':
                gameOver=true;
                break;
        }
    }
}

void Logic()
{
    ll prevX=tailX[0]; //tail er ager thinaka mone rakha
    ll prevY=tailY[0];
    ll prev2X,prev2Y;
    tailX[0]=x; //head re jno dlw kore tai
    tailY[0]=y;
    for(ll i = 1 ; i < nTail ; i++)  //ei part ta bujhew bujhinai..so mone rakha lagbe
    {
        prev2X=tailX[i]; //current positon more rakha
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X; //update korram
        prevY=prev2Y;
    }
    switch(dir) //kboard input working
    {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }
    if(x>width || x<0 || y>height || y<0) gameOver=true; //wall er baire gele game over

    /*if(x>=width) x=0;    //jodi dan bamer wall e lege g.over na hoy taile
    else if(x<0) x=width-1;
    if(y>=height) y=0;
    else if(y<0) y=height-1;
    */

    for(ll i = 0 ; i<nTail ; i++) //a bug fixing
    {
        if(tailX[i]==x && tailY[i]==y) gameOver=true;
    }

    if(x==fruitX && y==fruitY)
    {
        score=score+10; //score barbo
        fruitX = rand() % width; //randm place e fruit placed oibo
		fruitY = rand() % height;
        nTail++;
    }
}

int main()
{
    Setup();
    while(!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(70);//speed barano komano
    }



}
