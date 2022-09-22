#include<iostream>
#include<cstdio>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;
int mp[4][4],score;
bool map[4][4];
bool cal[4][4];

void print()
{
 	printf("      2048		\n");
    for(int j=0;j<4;++j)
            printf("----");
        printf("\n");
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            printf("|");
            if(map[i][j]){
                if(score<mp[i][j])
                    score=mp[i][j];
                printf("%3d",mp[i][j]);
            }else
                printf("   ");
 
        }
        printf("|\n");
        for(int j=0;j<4;++j)
            printf("----");
        printf("\n");
    }
    printf("w : up  s : down  a : left  d : right\n");
    printf("push 'r' to start a new game\npush 'e' to exit game\n\n");
    printf("Developed by Charles_Zhang\n");
}

void moveUp()
{
    bool flag;
    for(int i=1;i<4;++i){
        for(int j=0;j<4;++j){
            if(!map[i][j])
                continue;
            flag=false;
            int pos=i;
            for(int k=i-1;k>=0;--k){
                if(!map[k][j]){
                    pos=k;
                    continue;
                }
                if((mp[k][j]==mp[i][j])&&(!cal[k][j])){
                    mp[k][j]+=mp[i][j];
                    cal[k][j]=true;
                    flag=true;
                    map[i][j]=false;
                }
                else
                    break;
            }
            if(!flag){
                mp[pos][j]=mp[i][j];
                map[i][j]=false;
                map[pos][j]=true;
            }
        }
    }
}

void moveDown()
{
    bool flag;
    for(int i=2;i>=0;--i){
        for(int j=0;j<4;++j){
            if(!map[i][j])
                continue;
            flag=false;
            int pos=i;
            for(int k=i+1;k<4;++k){
                if(!map[k][j]){
                    pos=k;
                    continue;
                }
                if((mp[k][j]==mp[i][j])&&(!cal[k][j])){
                    mp[k][j]+=mp[i][j];
                    cal[k][j]=true;
                    flag=true;
                    map[i][j]=false;
                }
                else
                    break;
            }
            if(!flag){
                mp[pos][j]=mp[i][j];
                map[i][j]=false;
                map[pos][j]=true;
            }
        }
    }
}

void moveRight()
{
    bool flag;
    for(int i=0;i<4;++i){
        for(int j=2;j>=0;--j){
            if(!map[i][j])
                continue;
            flag=false;
            int pos=j;
            for(int k=j+1;k<4;++k){
                if(!map[i][k]){
                    pos=k;
                    continue;
                }
                if((mp[i][k]==mp[i][j])&&(!cal[i][k])){
                    mp[i][k]+=mp[i][j];
                    cal[i][k]=true;
                    flag=true;
                    map[i][j]=false;
                }
                else
                    break;
            }
            if(!flag){
                mp[i][pos]=mp[i][j];
                map[i][j]=false;
                map[i][pos]=true;
            }
        }
    }
}

void moveLeft()
{
    bool flag;
    for(int i=0;i<4;++i){
        for(int j=1;j<4;++j){
            if(!map[i][j])
                continue;
            flag=false;
            int pos=j;
            for(int k=j-1;k>=0;--k){
                if(!map[i][k]){
                    pos=k;
                    continue;
                }
                if((mp[i][k]==mp[i][j])&&(!cal[i][k])){
                    mp[i][k]+=mp[i][j];
                    cal[i][k]=true;
                    flag=true;
                    map[i][j]=false;
                }
                else
                    break;
            }
            if(!flag){
                mp[i][pos]=mp[i][j];
                map[i][j]=false;
                map[i][pos]=true;
            }
        }
    }
}

void inIt()
{
    srand(time(NULL));
    int x,y,v,now=0;
    for(int i=0;i<4;++i)
    for(int j=0;j<4;++j)
        if(!map[i][j])
            now++;
    if(now==0)
        return;
    int cnt=rand()%now,n=0;
    bool flag=false;
    for(int i=0;i<4;++i){
        flag=false;
        for(int j=0;j<4;++j)
        if(!map[i][j]){
            if(cnt==n){
                x=i;
                y=j;
                flag=true;
                break;
            }else
                n++;
        }
        if(flag)
            break;
    }
    v=rand()%2;
    if(v)
        v=4;
    else
        v=2;
    mp[x][y]=v;
    map[x][y]=true;
}

bool gameOver()
{
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            if(!map[i][j])
                return false;
            if(i>0){
                if(mp[i-1][j]==mp[i][j])
                    return false;
            }
            if(j>0)
                if(mp[i][j-1]==mp[i][j])
                    return false;
        }
    }
    return true;
}

void win()
{
    char ch;
    system("cls");
    printf("*******************\n");
    printf("***** YOU WIN *****\n");
    printf("*******************\n\n");
    printf("Push any button to continue\n");
    ch=getch();
    return ;
}


void lose()
{
    char ch;
    system("cls");
    printf("*******************\n");
    printf("**** GAME OVER ****\n");
    printf("**** SCORE:%3d ****\n",score);
    printf("*******************\n\n");
    printf("Push any button to continue\n");
    ch=getch();
    return ;
}

void start()
{
    system("cls");
    printf("********************\n");
    printf("**** game start ****\n");
    printf("********************\n");
    int x=5e8;
    bool flag=false;
    while(x--);
    memset(mp,0,sizeof(mp));
    memset(map,false,sizeof(map));
    score=0;
    char ch;
    while(!gameOver())
    {
        memset(cal,false,sizeof(cal));
        int cnt=0;
        system("cls");
        inIt();
        print();
        ch=getch();
        switch (ch)
        {
            case 'w':moveUp();break;
            case 's':moveDown();break;
            case 'a':moveLeft();break;
            case 'd':moveRight();break;
            case 'e':exit(0);
            case 'r':return ;
        }
        if(score>=2048){
            flag=true;
            break;
        }
    }
    if(flag)
        lose();
    else
        lose();
    return ;
}
 
int main()
{
	system("title 2048");
    char ch;
    while(1)
    {
        system("cls");
        printf("push ENTER to start game\nESC to exit\n");
        ch=getch();
        if(ch==13)
            start();
        else if(ch==27)
            break;
    }
    return 0;
}

