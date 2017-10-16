#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include<ctype.h>
#include <windows.h>
#include <process.h>
#include<iostream>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#pragma comment(lib, "winmm.lib")

using namespace std;

char c,b,d,l;
int a[101][101],i,j,z1=4,z2=14,z3=9,z4=31,z5=28,z6=84,z7=40,z8=59,z9=63,z10=81,utime,y,who;
int w1=7,w2=17,w3=24,w4=87,w5=13,w6=98,w7=42,w8=66,w9=34,w10=54;
long ltime;
int length;
int bend_no;
int len;
char key,g;
void record();
void load();
int life;
void Delay(long double);
void Move();
void Food();
int Score();
void Print();
void gotoxy(int x, int y);
void GotoXY(int x,int y);
void Bend();
void Boarder();
void Down();
void Left();
void Up();
void Right();
void ExitGame();
int Scoreonly();
void logo();
void ladder();
void snake();
void grid();
void logo2();
void welcome();



char* Color(int color=7, char* Message = "")
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    return Message;
}



struct coordinate{
    int x;
    int y;
    int direction;
};

typedef struct coordinate coordinate;

coordinate head, bend[500],food,body[30];

int main()
{
    system("CLS");
     system("COLOR 0A");

   PlaySound(TEXT("Pokemon.wav"), NULL,SND_LOOP | SND_ASYNC);
   welcome();
    //printf("Press 1 to play Snakes and Ladders 2 to play Snakes");

    g=getche();

    int x = 0,x2=0;
    if(g=='1')
    {
        system("COLOR 0A");
        system("CLS");
        logo();
        l=getche();
        if(l=='1')
        {

         system("CLS");
        Color();
        grid();

        int flag1 = 1,flag2 = 1 ;

    while(1)
    {
         cout << Color(10,"\t\t\t\t\t\t\t|-----|----|----|----|----|----|----|----|----|----|\n"); Color();
        for(i=0;i<10;i++)
        {
            printf("\t\t\t\t\t\t\t");
            for(j=0;j<10;j++)
            {
                    if(j==0) printf("|");
                    if(i>0&&j==0)printf(" ");
                    if(a[i][j]!=z1 && a[i][j]!= w1 && a[i][j]!= z3 && (i==9 && j<9)) printf(" ");
//                if(++who%2)
//                {
                    if(x==x2 && x==a[i][j])
                    {
                        if(i<9||j==9) {cout << Color(5," Pp"); Color(); printf(" |");}
                        else if(a[i][j]==7) {cout << Color(5," Pp"); Color(); printf(" |");}
                        else {cout << Color(5,"Pp"); Color(); printf(" |");}
                        continue;
                    }
                    if(x==a[i][j])
                    {
                        if(i<9||j==9) {cout << Color(12," P1"); Color(); printf(" |");}
                        else if(a[i][j]==7) {cout << Color(12," P1"); Color(); printf(" |");}
                        else {cout << Color(12,"P1"); Color(); printf(" |");}
//                        continue;
                    }
//                }
//                else
//                {
                    if(x2==a[i][j])
                    {
                        if(i<9||j==9) {cout << Color(13," P2"); Color(); printf(" |");}
                        else if(a[i][j]==7) {cout << Color(13," P2"); Color(); printf(" |");}
                        else {cout << Color(13,"P2"); Color(); printf(" |");}

                    }

//                }
                if(x!=a[i][j] && x2!=a[i][j])
                {
                    if(a[i][j]==z1) {cout << Color(14,"(L1)|"); Color();}
                    else if(a[i][j] == z2) {cout << Color(14,"(L1)|"); Color();}
                    else if(a[i][j] == z3) {cout << Color(14,"(L2)|"); Color();}
                    else if(a[i][j] == z4) {cout << Color(14,"(L2)|"); Color();}
                    else if(a[i][j] == z5) {cout << Color(14,"(L3)|"); Color();}
                    else if(a[i][j] == z6) {cout << Color(14,"(L3)|"); Color();}
                    else if(a[i][j] == z7) {cout << Color(14,"(L4)|"); Color();}
                    else if(a[i][j] == z8) {cout << Color(14,"(L4)|"); Color();}
                    else if(a[i][j] == z9) {cout << Color(14,"(L5)|"); Color();}
                    else if(a[i][j] == z10) {cout << Color(14,"(L5)|"); Color();}
                    else if(a[i][j] == w1) {cout << Color(9,"(S1)|"); Color();}
                    else if(a[i][j] == w2) {cout << Color(9,"(S1)|"); Color();}
                    else if(a[i][j] == w3) {cout << Color(9,"(S2)|"); Color();}
                    else if(a[i][j] == w4) {cout << Color(9,"(S2)|"); Color();}
                    else if(a[i][j] == w5) {cout << Color(9,"(S3)|"); Color();}
                    else if(a[i][j] == w6) {cout << Color(9,"(S3)|"); Color();}
                    else if(a[i][j] == w7) {cout << Color(9,"(S4)|"); Color();}
                    else if(a[i][j] == w8) {cout << Color(9,"(S4)|"); Color();}
                    else if(a[i][j] == w9) {cout << Color(9,"(S5)|"); Color();}
                    else if(a[i][j] == w10) {cout << Color(9,"(S5)|"); Color();}
                    else printf("%d  |",a[i][j]);
                }



            }
            printf("\n");
            cout << Color(10,"\t\t\t\t\t\t\t|-----|----|----|----|----|----|----|----|----|----|\n"); Color();

        }
        if(x==z1)
        {

            ladder();
            x = z2;
            continue;
        }
         if(x2==z1)
        {

            ladder();
            x2 = z2;
            continue;
        }
        if(x==z3)
        {

            ladder();
            x = z4;
            continue;
        }
         if(x2==z3)
        {

            ladder();
            x2 = z4;
            continue;
        }
         if(x==z5)
        {

            ladder();
            x = z6;
            continue;
        }
         if(x2==z5)
        {

            ladder();
            x2 = z6;
            continue;
        }
         if(x==z7)
        {

            ladder();
            x = z8;
            continue;
        }
         if(x2==z7)
        {

            ladder();
            x2 = z8;
            continue;
        }
         if(x==z9)
        {

            ladder();
            x = z10;
            continue;
        }
         if(x2==z9)
        {

            ladder();
            x2 = z10;
            continue;
        }
        if(x==w2)
        {

            snake();
            x = w1;
            continue;
        }
         if(x2==w2)
        {

            snake();
            x2 = w1;
            continue;
        }
         if(x==w4)
        {

            snake();
            x = w3;
            continue;
        }
         if(x2==w4)
        {

            snake();
            x2 = w3;
            continue;
        }
         if(x==w6)
        {

            snake();
            x = w5;
            continue;
        }
         if(x2==w6)
        {

            snake();
            x2 = w5;
            continue;
        }
         if(x==w8)
        {

            snake();
            x = w7;
            continue;
        }
         if(x2==w8)
        {

            snake();
            x2 = w7;
            continue;
        }
         if(x==w10)
        {

            snake();
            x = w9;
            continue;
        }
         if(x2==w10)
        {

            snake();
            x2 = w9;
            continue;
        }
        scanf("%c",&c);
        if(c=='\n')
        {

            if(++who%2)
            {
                cout << Color(9,"\t\t\t\t\t\t\t\t         P1 Press Enter to Roll!!\n\n\n\n\n\n\n"); Color();
                cout << Color(11,"\t\t\t\t\t\t\t\t         ROLLING.......!!\n\n"); Color();
                 ltime=time(NULL);
                utime=(unsigned int) ltime/2;
                srand(time(NULL));
                y = ( rand() % 6 ) + 1;
                printf("\n\n\n\n\n\n");
                printf("\t\t\t\t\t\t\t\t\t   P1 have got %d\n\n\n\n",y);

                if(x==0 && y!=1 ) {cout << Color(13,"\t\t\t\t\t\t\t\t\t   SHOOT! P1 Needs 1\n"); Color();
                printf("%d\n",x2);
                 }
                else
                {
                if(y==1 && x==0) {cout << Color(13,"\t\t\t\t\t\t\t\t\t   YEEE B| P1 Proceeds to 1\n"); Color();}
                if(x>0 && (x+y)<100) printf("\t\t\t\t\t\t\t\t\t   P1 Proceed to %d\n",x+y);
                else if((x+y)>100 && x>0) printf("\t\t\t\t\t\t\t\t\t   Almost There!\n") , x = x-y;
//                else if(x==0) {cout << Color(13,"\t\t\t\t\t\t\t\t\t   SHOOT! P1 Needs 1\n"); Color();}
                x = x+y;
                }
            }
            else
            {
                cout << Color(9,"\t\t\t\t\t\t\t\t         P2 Press Enter to Roll!!\n\n\n\n\n\n\n"); Color();
                cout << Color(11,"\t\t\t\t\t\t\t\t         ROLLING.......!!\n\n"); Color();
                 ltime=time(NULL);
                utime=(unsigned int) ltime/2;
                srand(time(NULL));
                y = ( rand() % 6 ) + 1;
                printf("\n\n\n\n\n\n");
                printf("\t\t\t\t\t\t\t\t\t   P2 have got %d\n\n\n\n",y);
                if(x2==0 && y!=1 ) {cout << Color(13,"\t\t\t\t\t\t\t\t\t   SHOOT! P2 Needs 1\n"); Color();
                printf("%d\n",x);
                }
                else
                {
                if(y==1 && x2==0) {cout << Color(13,"\t\t\t\t\t\t\t\t\t   YEEE B| P2 Proceeds to 1\n"); Color();}
                if(x2>0 && (x2+y)<100) printf("\t\t\t\t\t\t\t\t\t   P2 Proceeds to %d\n",x2+y);
                else if((x2+y)>100 && x2>0) printf("\t\t\t\t\t\t\t\t\t   Almost There!\n") , x2 = x2 - y;
                //else if(x2==0) {cout << Color(13,"\t\t\t\t\t\t\t\t\t   SHOOT! P2 Needs 1\n"); Color();}
                x2 = x2+y;
                }
            }

        }
        if(flag1 && x!=1) { x = 0; continue;}
        else flag1 = 0;
        if(flag2 && x2!=1) {x2=0; continue;}
        else flag2 = 0;
        if(x>100) {x = x-y; continue;}
        else if(x==100)
        {
          PlaySound(TEXT("Youwon.wav"), NULL, SND_ASYNC);
            system("CLS");
            PlaySound(TEXT("Youwon.wav"), NULL, SND_ASYNC);
            //cout << Color(1,"\n\n\n\n\t\t\t\t\t\t\t\t\tYoo Broo You WON\n\n\n\n\n\n"); Color();
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
            cout << Color(9,"\t\t\t\t\t	                    ____     __                          ___                          ______\n"); Color();
            cout << Color(9,"\t\t\t\t\t	    	           | __ |   /_ |            ||      ||  / _ \\  | \\   ||              /      \\\n"); Color();
            cout << Color(9,"\t\t\t\t\t        	           ||__||  // ||            ||      ||  || ||  ||\\\\  ||             /  0  0  \\\n"); Color();
            cout << Color(9,"\t\t\t\t\t	  	           | ___/     ||            ||  __  ||  || ||  || \\\\ ||            (     |    )\n"); Color();
            cout << Color(9,"\t\t\t\t\t                           ||        _||_           ||_/  \\_||  ||_||  ||  \\\\|| __  __  __  \\  \\___/ /\n"); Color();
            cout << Color(9,"\t\t\t\t\t	                   ||       |____|          \\___/\\___/  \\___/  ||   \\_| |_| |_| |_|  \\______/\n"); Color();
            cout << Color(4,"\n\n\n\n\t\t\t\t\t\t\t\t\tPress Enter to Exit\n"); Color();
            cout << Color(4,"\n\t\t\t\t\t\t\t\t\tPress 'R' to return to main menu\n"); Color();
            //scanf("%c",&d);
            d=getche();
            if(d=='\n') break;
            else if(d=='r') main();
        }
            if(x2>100) {x2=x2-y; continue;}
           else if(x2==100)
        {
            PlaySound(TEXT("Youwon.wav"), NULL, SND_ASYNC);
            system("CLS");
            PlaySound(TEXT("Youwon.wav"), NULL, SND_ASYNC);
            //cout << Color(1,"\n\n\n\n\t\t\t\t\t\t\t\t\tYoo Broo You WON\n\n\n\n\n\n"); Color();
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
            cout << Color(9,"\t\t\t\t\t        	           ____     ___                         ___                          ______\n"); Color();
            cout << Color(9,"\t\t\t\t\t	                  | __ |   / _ \\           ||      ||  / _ \\  | \\   ||              /      \\\n"); Color();
            cout << Color(9,"\t\t\t\t\t                          ||__||   || ||           ||      ||  || ||  ||\\\\  ||             /  0  0  \\\n"); Color();
            cout << Color(9,"\t\t\t\t\t	                  | ___/      //           ||  __  ||  || ||  || \\\\ ||            (     |    )\n"); Color();
            cout << Color(9,"\t\t\t\t\t        	          ||        _//_           ||_/  \\_||  ||_||  ||  \\\\|| __  __  __  \\  \\___/ /\n"); Color();
            cout << Color(9,"\t\t\t\t\t	                  ||       |____|          \\___/\\___/  \\___/  ||   \\_| |_| |_| |_|  \\______/\n"); Color();
            cout << Color(4,"\n\n\n\n\t\t\t\t\t\t\t\t\tPress Enter to Exit\n"); Color();
            cout << Color(4,"\n\t\t\t\t\t\t\t\t\tPress 'R' to return to main menu\n"); Color();
            //scanf("%c",&d);
            d==getche();
            if(d=='\n') break;
            else if(d=='r') {system("CLS"); main();}
        }
    }
    }
    }
//Here Code of Snakes game starts

    else if(g=='2')
    {
        system("COLOR 0A");
    system("CLS");
    char key;

    Print();

    system("cls");

    load();

    length=5;

    head.x=25;

    head.y=20;

    head.direction=RIGHT;

    Boarder();

    Food(); //to generate food coordinates initially

    life=3; //number of extra lives

    bend[0]=head;

    Move();   //initialing initial bend coordinate

    }
    return 0;

}

void Move()
{
    int a,i;

    do{

        Food();
        fflush(stdin);

        len=0;

        for(i=0;i<30;i++)

        {

            body[i].x=0;

            body[i].y=0;

            if(i==length)

            break;

        }

        Delay(length);

        Boarder();

        if(head.direction==RIGHT)

            Right();

        else if(head.direction==LEFT)

            Left();

        else if(head.direction==DOWN)

            Down();

        else if(head.direction==UP)

            Up();

        ExitGame();

    }while(!kbhit());

    a=getch();

    if(a==27)

    {

        system("cls");

        exit(0);

    }
    key=getch();

    if((key==RIGHT&&head.direction!=LEFT&&head.direction!=RIGHT)||(key==LEFT&&head.direction!=RIGHT&&head.direction!=LEFT)||(key==UP&&head.direction!=DOWN&&head.direction!=UP)||(key==DOWN&&head.direction!=UP&&head.direction!=DOWN))

    {

        bend_no++;

        bend[bend_no]=head;

        head.direction=key;

        if(key==UP)

            head.y--;

        if(key==DOWN)

            head.y++;

        if(key==RIGHT)

            head.x++;

        if(key==LEFT)

            head.x--;

        Move();

    }

    else if(key==27)

    {

        system("cls");

        exit(0);

    }

    else

    {

        printf("\a");

        Move();

    }
}

void gotoxy(int x, int y)
{

 COORD coord;

 coord.X = x;

 coord.Y = y;

 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
void GotoXY(int x, int y)
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
 }
void load(){
    int row,col,r,c,q;
    gotoxy(36,14);
    printf("loading...");
    gotoxy(30,15);
    for(r=1;r<=20;r++){
    for(q=0;q<=100000000;q++);//to display the character slowly
    printf("%c",177);}
    getch();
}
void Down()
{
    int i;
    for(i=0;i<=(head.y-bend[bend_no].y)&&len<length;i++)
    {
        GotoXY(head.x,head.y-i);
        {
            if(len==0)
                printf("v");
            else
                printf("*");
        }
        body[len].x=head.x;
        body[len].y=head.y-i;
        len++;
    }
    Bend();
    if(!kbhit())
        head.y++;
}
void Delay(long double k)
{
    Score();
    long double i;
    for(i=0;i<=(10000000);i++);
}
void ExitGame()
{
    int i,check=0;
    char t;
    for(i=4;i<length;i++)   //starts with 4 because it needs minimum 4 element to touch its own body
    {
        if(body[0].x==body[i].x&&body[0].y==body[i].y)
        {
            check++;    //check's value increases as the coordinates of head is equal to any other body coordinate
        }
        if(i==length||check!=0)
            break;
    }
    if(head.x<=10||head.x>=70||head.y<=10||head.y>=30||check!=0)
    {
        life--;
        if(life>0)
        {
            head.x=25;
            head.y=20;
            bend_no=0;
            head.direction=RIGHT;
            Move();
        }
        else
        {
            system("cls");
            printf("\n\n\n\n\t\t\t\tAll lives completed\n\t\t\t\tBetter Luck Next Time!!!\n\n\n\n\n\n\t\t\t\tPress 'c' to enter your records\n");
            printf("\n\n\t\t\t\tPress 'R' to return to main menu");
            t=getche();
            if(t=='r') main();
            record();
            exit(0);
        }
    }
}
void Food()
{
    if(head.x==food.x&&head.y==food.y)
    {
        length++;
        time_t a;
        a=time(0);
        srand(a);
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)

            food.y+=11;
    }
    else if(food.x==0)/*to create food for the first time coz global variable are initialized with 0*/
    {
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)
            food.y+=11;
    }
}
void Left()
{
    int i;
    for(i=0;i<=(bend[bend_no].x-head.x)&&len<length;i++)
    {
        GotoXY((head.x+i),head.y);
       {
                if(len==0)
                    printf("<");
                else
                    printf("*");
        }
        body[len].x=head.x+i;
        body[len].y=head.y;
        len++;
    }
    Bend();
    if(!kbhit())
        head.x--;

}
void Right()
{
    int i;
    for(i=0;i<=(head.x-bend[bend_no].x)&&len<length;i++)
    {
        //GotoXY((head.x-i),head.y);
        body[len].x=head.x-i;
        body[len].y=head.y;
        GotoXY(body[len].x,body[len].y);
        {
            if(len==0)
                printf(">");
            else
                printf("*");
        }
        /*body[len].x=head.x-i;
        body[len].y=head.y;*/
        len++;
    }
    Bend();
    if(!kbhit())
        head.x++;
}
void Bend()
{
    int i,j,diff;
    for(i=bend_no;i>=0&&len<length;i--)
    {
            if(bend[i].x==bend[i-1].x)
            {
                diff=bend[i].y-bend[i-1].y;
                if(diff<0)
                    for(j=1;j<=(-diff);j++)
                    {
                        body[len].x=bend[i].x;
                        body[len].y=bend[i].y+j;
                        GotoXY(body[len].x,body[len].y);
                        printf("*");
                        len++;
                        if(len==length)
                            break;
                    }
                else if(diff>0)
                    for(j=1;j<=diff;j++)
                    {
                        /*GotoXY(bend[i].x,(bend[i].y-j));
                        printf("*");*/
                        body[len].x=bend[i].x;
                        body[len].y=bend[i].y-j;
                        GotoXY(body[len].x,body[len].y);
                        printf("*");
                        len++;
                        if(len==length)
                            break;
                    }
            }
        else if(bend[i].y==bend[i-1].y)
        {
            diff=bend[i].x-bend[i-1].x;
            if(diff<0)
                for(j=1;j<=(-diff)&&len<length;j++)
                {
                    /*GotoXY((bend[i].x+j),bend[i].y);
                    printf("*");*/
                    body[len].x=bend[i].x+j;
                    body[len].y=bend[i].y;
                    GotoXY(body[len].x,body[len].y);
                        printf("*");
                   len++;
                   if(len==length)
                           break;
               }
           else if(diff>0)
               for(j=1;j<=diff&&len<length;j++)
               {
                   /*GotoXY((bend[i].x-j),bend[i].y);
                   printf("*");*/
                   body[len].x=bend[i].x-j;
                   body[len].y=bend[i].y;
                   GotoXY(body[len].x,body[len].y);
                       printf("*");
                   len++;
                   if(len==length)
                       break;
               }
       }
   }
}
void Boarder()
{
   system("cls");
   int i;
   GotoXY(food.x,food.y);   /*displaying food*/
       //printf("F");
       cout << Color(12,"F");  system("COLOR 0A");
   for(i=10;i<71;i++)
   {
       GotoXY(i,10);
           printf("!");
       GotoXY(i,30);
           printf("!");
   }
   for(i=10;i<31;i++)
   {
       GotoXY(10,i);
           printf("!");
       GotoXY(70,i);
       printf("!");
   }
}
void Print()
{
   //GotoXY(10,12);
   logo2();
   getch();
   system("CLS");
   system("COLOR 0A");
   //printf("\tWelcome to the mini Snake game.(press any key to continue)\n");
  //getch();
   //system("cls");
   printf("\tGame instructions:\n");
   printf("\n-> Use arrow keys to move the snake.\n\n-> You will be provided foods at the several coordinates of the screen which you have to eat. Everytime you eat a food the length of the snake will be increased by 1 element and thus the score.\n\n-> Here you are provided with three lives. Your life will decrease as you hit the wall or snake's body.\n\n-> YOu can pause the game in its middle by pressing any key. To continue the paused game press any other key once again\n\n-> If you want to exit press esc. \n");
   printf("\n\nPress any key to play game...");
   if(getch()==27)
   exit(0);
}
void record(){
   char plname[20],nplname[20],cha,c;
   int i,j,px;
   FILE *info;
   info=fopen("record.txt","a+");
   getch();
   system("cls");
   printf("Enter your name\n");
   scanf("%[^\n]",plname);
   //************************
   for(j=0;plname[j]!='\0';j++){ //to convert the first letter after space to capital
   nplname[0]=toupper(plname[0]);
   if(plname[j-1]==' '){
   nplname[j]=toupper(plname[j]);
   nplname[j-1]=plname[j-1];}
   else nplname[j]=plname[j];
   }
   nplname[j]='\0';
   fprintf(info,"Player Name :%s\n",nplname);
   time_t mytime;
  mytime = time(NULL);
  fprintf(info,"Played Date:%s",ctime(&mytime));

     fprintf(info,"Score:%d\n",px=Scoreonly());//call score to display score

   for(i=0;i<=50;i++)
   fprintf(info,"%c",'_');
   fprintf(info,"\n");
   fclose(info);
   printf("Want to see past records press 'y'\n");
   cha=getch();
   system("cls");
   if(cha=='y'){
   info=fopen("record.txt","r");
   do{
       putchar(c=getc(info));
       }while(c!=EOF);}
     fclose(info);
}
int Score()
{
   int score;
   GotoXY(20,8);
   score=length-5;
   printf("SCORE : %d",(length-5));
   score=length-5;
   GotoXY(50,8);
   printf("Life : %d",life);
   return score;
}
int Scoreonly()
{
int score=Score();
system("cls");
return score;
}
void Up()
{
   int i;
   for(i=0;i<=(bend[bend_no].y-head.y)&&len<length;i++)
   {
       GotoXY(head.x,head.y+i);
       {
           if(len==0)
               printf("^");
           else
               printf("*");
       }
       body[len].x=head.x;
       body[len].y=head.y+i;
       len++;
   }
   Bend();
   if(!kbhit())
       head.y--;
}
void logo()
{
    printf("\n\n\n\n\n");
     printf("                                             _____    _          ___    __  _  _____    _____\n");
    printf("                                            | ____|  | \\   ||   / _ \\   || //  | ___|  | ____|\n");
    printf("                                            ||____   ||\\\\  ||  | / \\ |  ||//   ||___   ||____\n");
    printf("                                            |____ |  || \\\\ ||  ||___||  |||    | ___|  |____ |\n");
    printf("                      ><                     ____||  ||  \\\\||  ||___||  ||\\\\   ||___    ____||     \\\\     \\\\\n");
    printf("                     /  \\                   |_____|  ||   \\_|  ||   ||  || \\\\  |____|  |_____|      \\\\_____\\\\\n");
    printf("                    / 00 \                                                                            \\\\ ____\\\\\n");
    printf("                    \\ __ /                                                                            \\\\     \\\\\n");
    printf("                     \\  /                                 ___     _        ____                        \\\\_____\\\\\n");
    printf("                      ||                                 / _ \\   | \\   ||  | __\\                        \\\\_____\\\\\n");
    printf("                      ||_____                           | / \\ |  ||\\\\  ||  ||  \\\\                        \\\\     \\\\\n");
    printf("                      \\_____ \\                          ||___||  || \\\\ ||  ||  ||                         \\\\_____\\\\\n");
    printf("                            ||                          ||___||  ||  \\\\||  ||__//                          \\\\ ____\\\\\n");
    printf("                            ||___                       ||   ||  ||   \\_|  |___/                            \\\\     \\\\\n");
    printf("                            \\___ \\                                                                           \\\\_____\\\\\n");
    printf("                                ||                                                                            \\\\ ____\\\\\n");
    printf("                                ||____    __         ___    ____    ____    _____    ____    _____             \\\\     \\\\\n");
    printf("                                 \\____/   | |        / _ \\   | __\\   | __\\   | ___|  | __ |  | ____|            \\\\     \\\\\n");
    printf("                                          | |       | / \\ |  ||  \\\\  ||  \\\\  ||___   ||__||  ||____\n");
    printf("                                          | |       ||___||  ||  ||  ||  ||  | ___|  | ___/  |____ |\n");
    printf("                                          | |____   ||___||  ||__//  ||__//  ||___   || \\    ____||\n");
    printf("                                          |______|  ||   ||  |___/   |___/   |____|  ||  \\  |_____|\n\n\n");
    cout << Color(5,"                                                        Created By: Muhammad Shihab Rashid & Mushfique Uddin Mahmud Rafid\n\n\n\n"); Color();
    cout << Color(3,"                              *Press 1 to Play!\n\n");

}

void ladder()
{
            PlaySound(TEXT("Butterfly.wav"), NULL,SND_LOOP | SND_ASYNC);
            cout << Color(3,"\t\t\t\t\t\t\t\t\t   Oh Yeah! Ladder!\n");
            scanf("%c",&c);
            PlaySound(TEXT("Pokemon.wav"), NULL,SND_LOOP | SND_ASYNC);
}

void snake()
{
            PlaySound(TEXT("Butterfly.wav"), NULL,SND_LOOP | SND_ASYNC);
            cout << Color(3,"\t\t\t\t\t\t\t\t\t   OH SHIT! A SNAKE!!\n");
            scanf("%c",&c);
            PlaySound(TEXT("Pokemon.wav"), NULL,SND_LOOP | SND_ASYNC);
}

void grid()
{
    int x = 100;
    for(i=0;i<10;i+=2)
        {
            for(j=0;j<10;j++)
            {
                a[i][j] = x--;
            }

            x = x - 10;
        }

        x = 81;

        for(i=1;i<10;i+=2)
        {
            for(j=0;j<10;j++)
            {
                a[i][j] = x++;
            }

            x = x-30;
        }
        x = 0;
//        x2=0;
}
void logo2()
{
            printf("\n\n\n\n");
            cout << Color(11,"\t\t\t\t\t             ______\n"); Color();
            cout << Color(11,"\t\t\t\t\t            /      \\                                  ______          _____\n"); Color();
            cout << Color(11,"\t\t\t\t\t           /     0  \\                           _____/ ____ \\___     / ___ \\\n"); Color();
            cout << Color(11,"\t\t\t\t\t          /      ____\\                         / _____/    \\___ \\___/ /   \\ \\\n"); Color();
            cout << Color(11,"\t\t\t\t\t          |  _  | \\                           | |              \_____/     \\ \\\n"); Color();
            cout << Color(11,"\t\t\t\t\t          / / \\ |\\ _____    _         ___     \\ \\   __  _  _____    _____   | |\n"); Color();
            cout << Color(11,"\t\t\t\t\t         / /   \\| | ____|  | \\   ||  / _ \\     \\ \\  || //  | ___|  | ____|  | |\n"); Color();
            cout << Color(11,"\t\t\t\t\t        | |       ||____   ||\\\\  || | / \\ |    | |  ||//   ||___   ||____    \\ \\\n"); Color();
            cout << Color(11,"\t\t\t\t\t        | |       |____ |  || \\\\ || ||___||    | |  |||    | ___|  |____ |    | |\n"); Color();
            cout << Color(11,"\t\t\t\t\t        \\ \\        ____||  ||  \\\\|| ||___||   / /   ||\\\\   ||___    ____||    / /\n"); Color();
            cout << Color(11,"\t\t\t\t\t         | |      |_____|  ||   \\_| ||   ||  / /    || \\\\  |____|  |_____|   / /\n"); Color();
            cout << Color(11,"\t\t\t\t\t         \\ \\      ______          _________/ /                              | |\n"); Color();
            cout << Color(11,"\t\t\t\t\t          \\ \\____/ ____ \\___     / _________/                      ___      / /\n"); Color();
            cout << Color(11,"\t\t\t\t\t           \\______/    \\___ \\___/ /                                \\_ \\____/ /\n"); Color();
            cout << Color(11,"\t\t\t\t\t                           \\_____/                                   \\______/\n"); Color();

  cout << Color(5,"\n\n\t\t\t\t\t\t\t\tCreated by Muhammad Shihab Rashid & Mushfique Uddin Mahmud Rafid\n");Color();

            printf("\n\n\n\t\t\t\t\t\t\tPress any key to play");



}
void welcome()
{
    printf("\n\n\n\n\n\n\n\n");
  cout << Color(14,"\t\t\t\t\t                                ____     __          _____     ___     __      __     ____\n"); Color();
  cout << Color(14,"\t\t\t\t\t                 ||      ||    | ___|    | |        / ____|   / _ \\   | _\\    /_ |   | ___|\n"); Color();
  cout << Color(14,"\t\t\t\t\t                 ||      ||    ||___     | |       | /        || ||   || \\\\__// ||   ||___\n"); Color();
  cout << Color(14,"\t\t\t\t\t                 ||  __  ||    | ___|    | |       | |        || ||   ||  \\__/  ||   | ___|\n"); Color();
  cout << Color(14,"\t\t\t\t\t                 ||_/  \\_||    ||___     | |___    | \\____    ||_||   ||        ||   ||___\n"); Color();
  cout << Color(14,"\t\t\t\t\t                 \\___/\\___/    |____|    |______|   \\_____|   \\___/   ||        ||   |____|\n");Color();


  cout << Color(10,"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPress 1 to play Snakes & Ladders \n");Color();
  cout << Color(10,"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPress 2 to play Snakes II \n");Color();
    //cout << Color(10,"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPress Esc to exit \n");Color();


}



