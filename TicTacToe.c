#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stddef.h.>

int Board(char a, char b, char c, char d, char e, char f, char g, char h, char i)
{
    if (a!='1'&&a!='X'&&a!='O') return 1;
    if (b!='2'&&b!='X'&&b!='O') return 2;
    if (c!='3'&&c!='X'&&c!='O') return 3;
    if (d!='4'&&d!='X'&&d!='O') return 4;
    if (e!='5'&&e!='X'&&e!='O') return 5;
    if (f!='6'&&f!='X'&&f!='O') return 6;
    if (g!='7'&&g!='X'&&g!='O') return 7;
    if (h!='8'&&h!='X'&&h!='O') return 8;
    if (i!='9'&&i!='X'&&i!='O') return 9;
    int error;
    error=printf("\n      |      |\n   %c  |   %c  |   %c\n______|______|______\n      |      |\n   %c  |   %c  |   %c   \n______|______|______\n      |      |\n   %c  |   %c  |   %c\n      |      |\n", a, b, c, d, e, f, g, h, i);
    if (error<0) return 10;
    return 0;
}

int Win(int *p, char a, char b, char c, char d, char e, char f, char g, char h, char i)
{
    if (p==NULL) return 1;
    if (a!='1'&&a!='X'&&a!='O') return 2;
    if (b!='2'&&b!='X'&&b!='O') return 3;
    if (c!='3'&&c!='X'&&c!='O') return 4;
    if (d!='4'&&d!='X'&&d!='O') return 5;
    if (e!='5'&&e!='X'&&e!='O') return 6;
    if (f!='6'&&f!='X'&&f!='O') return 7;
    if (g!='7'&&g!='X'&&g!='O') return 8;
    if (h!='8'&&h!='X'&&h!='O') return 9;
    if (i!='9'&&i!='X'&&i!='O') return 10;
    int error;
    *p=0;
    int q=0;
    int o=0;
    int m=0;
    char z[9]= {a, b, c, d, e, f, g, h, i};
    for (m=0; m<9; m++)
    {
        if ((z[m]!='X')&&(z[m]!='O'))
        {
            o++;
        }
    }
    if (o==0) *p=3;
    for(q=0; q<3; q++)
    {
        if(z[3*q]==z[3*q+1]&&z[3*q+1]==z[3*q+2]&&z[3*q+2]=='X') *p=1;
        if(z[3*q]==z[3*q+1]&&z[3*q+1]==z[3*q+2]&&z[3*q+2]=='O') *p=2;
        if(z[q]==z[q+3]&&z[q+3]==z[q+6]&&z[q+6]=='X') *p=1;
        if(z[q]==z[q+3]&&z[q+3]==z[q+6]&&z[q+6]=='O') *p=2;
    }
    if(z[0]==z[4]&&z[4]==z[8]&&z[8]=='X') *p=1;
    if(z[0]==z[4]&&z[4]==z[8]&&z[8]=='O') *p=2;
    if(z[2]==z[4]&&z[4]==z[6]&&z[6]=='X') *p=1;
    if(z[2]==z[4]&&z[4]==z[6]&&z[6]=='O') *p=2;
    if (*p==1) error=printf("You win");
    if (error<0) return 11;
    if (*p==2) error=printf("You lose");
    if (error<0) return 12;
    if (*p==3) error=printf("Draw");
    if (error<0) return 13;
    return 0;
}


int Player(int *w)
{
    int error;
    int f=0;
    if (w==NULL) return 1;
    error=printf("Enter the number to make a turn:\n");
    if (error<0) return 2;
    do
    {
        error=scanf("%d",&f);
        if ((error==EOF)&&(error<1)) return 3;
        if(f<1||f>9) error=printf ("The cell does not exist!\n");
        if (error<0) return 4;
        getchar();
    }
    while(f<1||f>9);
    *w=f;
    if (system("cls")==-1) return 5;
    return 0;
}


int Comp(int *t, char a, char b, char c, char d, char e, char f, char g, char h, char i)
{
    if (t==NULL) return 1;
    if (a!='1'&&a!='X'&&a!='O') return 2;
    if (b!='2'&&b!='X'&&b!='O') return 3;
    if (c!='3'&&c!='X'&&c!='O') return 4;
    if (d!='4'&&d!='X'&&d!='O') return 5;
    if (e!='5'&&e!='X'&&e!='O') return 6;
    if (f!='6'&&f!='X'&&f!='O') return 7;
    if (g!='7'&&g!='X'&&g!='O') return 8;
    if (h!='8'&&h!='X'&&h!='O') return 9;
    if (i!='9'&&i!='X'&&i!='O') return 10;
    *t=50;
    int k=0;
    char z[9]= {a, b, c, d, e, f, g, h, i};
    for(k=0; k<3; k++)
    {
        if(z[3*k]==z[3*k+1]&&z[3*k+1]=='X'&&z[3*k+2]!='X'&&z[3*k+2]!='O') *t=3*k+2;
        if(z[3*k]==z[3*k+2]&&z[3*k+2]=='X'&&z[3*k+1]!='X'&&z[3*k+1]!='O') *t=3*k+1;
        if(z[3*k+2]==z[3*k+1]&&z[3*k+1]=='X'&&z[3*k]!='X'&&z[3*k]!='O') *t=3*k;
        if(z[k+6]==z[k+3]&&z[k+3]=='X'&&z[k]!='X'&&z[k]!='O') *t=k;
        if(z[k]==z[k+3]&&z[k+3]=='X'&&z[k+6]!='X'&&z[k+6]!='O') *t=k+6;
        if(z[k]==z[k+6]&&z[k+6]=='X'&&z[k+3]!='X'&&z[k+3]!='O') *t=k+3;
    }
    if(z[0]==z[4]&&z[4]=='X'&&z[8]!='X'&&z[8]!='O') *t=8;
    if(z[8]==z[4]&&z[4]=='X'&&z[0]!='X'&&z[0]!='O') *t=0;
    if(z[0]==z[8]&&z[8]=='X'&&z[4]!='X'&&z[4]!='O') *t=4;
    if(z[2]==z[4]&&z[4]=='X'&&z[6]!='X'&&z[6]!='O') *t=6;
    if(z[6]==z[4]&&z[4]=='X'&&z[2]!='X'&&z[2]!='O') *t=2;
    if(z[2]==z[6]&&z[6]=='X'&&z[4]!='X'&&z[4]!='O') *t=4;
    for(k=0; k<3; k++)
    {
        if(z[3*k]==z[3*k+1]&&z[3*k+1]=='O'&&z[3*k+2]!='X'&&z[3*k+2]!='O') *t=3*k+2;
        if(z[3*k]==z[3*k+2]&&z[3*k+2]=='O'&&z[3*k+1]!='X'&&z[3*k+1]!='O') *t=3*k+1;
        if(z[3*k+2]==z[3*k+1]&&z[3*k+1]=='O'&&z[3*k]!='X'&&z[3*k]!='O') *t=3*k;
        if(z[k+6]==z[k+3]&&z[k+3]=='O'&&z[k]!='X'&&z[k]!='O') *t=k;
        if(z[k]==z[k+3]&&z[k+3]=='O'&&z[k+6]!='X'&&z[k+6]!='O') *t=k+6;
        if(z[k]==z[k+6]&&z[k+6]=='O'&&z[k+3]!='X'&&z[k+3]!='O') *t=k+3;
    }
    if(z[0]==z[4]&&z[4]=='O'&&z[8]!='X'&&z[8]!='O') *t=8;
    if(z[8]==z[4]&&z[4]=='O'&&z[0]!='X'&&z[0]!='O') *t=0;
    if(z[0]==z[8]&&z[8]=='O'&&z[4]!='X'&&z[4]!='O') *t=4;
    if(z[2]==z[4]&&z[4]=='O'&&z[6]!='X'&&z[6]!='O') *t=6;
    if(z[6]==z[4]&&z[4]=='O'&&z[2]!='X'&&z[2]!='O') *t=2;
    if(z[2]==z[6]&&z[6]=='O'&&z[4]!='X'&&z[4]!='O') *t=4;
    return 0;
}



int main()
{
    char a[9]= {'1','2','3','4','5','6','7','8','9'};
    int i=0;
    int error;
    int j=0;
    int l=0;
    int r=0;
    srand(time(NULL));
    do
    {
        error=Board(a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);
        if (error==1)
        {
            printf("Error in function Board: invalid value 1");
            return 1;
        }
        if (error==2)
        {
            printf("Error in function Board: invalid value 2");
            return 2;
        }
        if (error==3)
        {
            printf ("Error in function Board: invalid value 3");
            return 3;
        }
        if (error==4)
        {
            printf ("Error in function Board: invalid value 4");
            return 4;
        }
        if (error==5)
        {
            printf ("Error in function Board: invalid value 5");
            return 5;
        }
        if (error==6)
        {
            printf ("Error in function Board: invalid value 6");
            return 6;
        }
        if (error==7)
        {
            printf ("Error in function Board: invalid value 7");
            return 7;
        }
        if (error==8)
        {
            printf ("Error in function Board: invalid value 8");
            return 8;
        }
        if (error==9)
        {
            printf ("Error in function Board: invalid value 9");
            return 9;
        }
        if (error==10)
        {
            printf ("Error in function Board: printf call error 1");
            return 10;
        }
        error=Player(&i);
        if (error==1)
        {
            printf ("Error in function Player: first argument is NULL pointer");
            return 11;
        }
        if (error==2)
        {
            printf ("Error in function Player: printf call error 1");
            return 12;
        }
        if (error==3)
        {
            printf("Error in function Player: scanf call error 1");
            return 13;
        }
        if (error==4)
        {
            printf("Error in function Player: printf call error 2");
            return 14;
        }
        if (error==5)
        {
            printf("Error in function Player: cls call error 1");
            return 15;
        }

        if ((a[i-1]!='X')&&(a[i-1]!='O'))
        {
            a[i-1]='X';
            error=Win(&l, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);
            if (error==1)
            {
                printf("Error in function Win: first argument is NULL pointer");
                return 16;
            }
            if (error==2)
            {
                printf("Error in function Win: invalid value 1");
                return 17;
            }
            if (error==3)
            {
                printf("Error in function Win: invalid value 2");
                return 18;
            }
            if (error==4)
            {
                printf("Error in function Win: invalid value 3");
                return 19;
            }
            if (error==5)
            {
                printf("Error in function Win: invalid value 4");
                return 20;
            }
            if (error==6)
            {
                printf("Error in function Win: invalid value 5");
                return 21;
            }
            if (error==7)
            {
                printf("Error in function Win: invalid value 6");
                return 22;
            }
            if (error==8)
            {
                printf("Error in function Win: invalid value 7");
                return 23;
            }
            if (error==9)
            {
                printf("Error in function Win: invalid value 8");
                return 24;
            }
            if (error==10)
            {
                printf("Error in function Win: invalid value 9");
                return 25;
            }
            if (error==11)
            {
                printf ("Error in function Win: printf call error 1");
                return 26;
            }
            if (error==12)
            {
                printf ("Error in function Win: printf call error 2");
                return 27;
            }
            if (error==13)
            {
                printf ("Error in function Win: printf call error 3");
                return 28;
            }
            if((l==1)||(l==2)||(l==3))
            {
                break;
            }
            error=Comp(&r, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);
            if (error==1)
            {
                printf("Error in function Comp: first argument is NULL pointer");
                return 29;
            }
            if (error==2)
            {
                printf("Error in function Comp: invalid value 1");
                return 30;
            }
            if (error==3)
            {
                printf ("Error in function Comp: invalid value 2");
                return 31;
            }
            if (error==4)
            {
                printf ("Error in function Comp: invalid value 3");
                return 32;
            }
            if (error==5)
            {
                printf ("Error in function Comp: invalid value 4");
                return 33;
            }
            if (error==6)
            {
                printf ("Error in function Comp: invalid value 5");
                return 34;
            }
            if (error==7)
            {
                printf ("Error in function Comp: invalid value 6");
                return 35;
            }
            if (error==8)
            {
                printf ("Error in function Comp: invalid value 7");
                return 36;
            }
            if (error==9)
            {
                printf ("Error in function Comp: invalid value 8");
                return 37;
            }
            if (error==10)
            {
                printf("Error in function Comp: invalid value 9");
                return 38;
            }
            if (r==50)
            {
                j = rand()%9;
                if((a[j]!='X')&&(a[j]!='O'))
                {
                    a[j]='O';
                }
                else
                {
                    do
                    {
                        j = rand()%9;
                    }
                    while((a[j]=='X') || (a[j]=='O'));
                    a[j]='O';
                }
                if (system("cls")==-1)
                {
                    printf("Error in function Main: cls call error 1");
                    return 39;
                }
            }
            else
            {
                a[r]='O';
                if (system("cls")==-1)
                {
                    printf("Error in function Main: cls call error 2");
                    return 40;
                }
            }
            error=Win(&l, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);
            if (error==1)
            {
                printf("Error in function Win: first argument is NULL pointer");
                return 41;
            }
            if (error==2)
            {
                printf("Error in function Win: invalid value 1");
                return 42;
            }
            if (error==3)
            {
                printf("Error in function Win: invalid value 2");
                return 43;
            }
            if (error==4)
            {
                printf("Error in function Win: invalid value 3");
                return 44;
            }
            if (error==5)
            {
                printf("Error in function Win: invalid value 4");
                return 45;
            }
            if (error==6)
            {
                printf("Error in function Win: invalid value 5");
                return 46;
            }
            if (error==7)
            {
                printf("Error in function Win: invalid value 6");
                return 47;
            }
            if (error==8)
            {
                printf("Error in function Win: invalid value 7");
                return 48;
            }
            if (error==9)
            {
                printf("Error in function Win: invalid value 8");
                return 49;
            }
            if (error==10)
            {
                printf("Error in function Win: invalid value 9");
                return 50;
            }
            if (error==11)
            {
                printf ("Error in function Win: printf call error 1");
                return 51;
            }
            if (error==12)
            {
                printf ("Error in function Win: printf call error 2");
                return 52;
            }
            if (error==13)
            {
                printf ("Error in function Win: printf call error 3");
                return 53;
            }
            if((l==1)||(l==2)||(l==3))
            {
                break;
            }
        }
        else
        {
            if (system("cls")==-1)
            {
                printf("Error in function Main: cls call error 3");
                return 54;
            }
            error=printf("The cell is already used! Try again\n");
            if (error<0)
            {
                printf("Error in function Main: printf call error 1");
                return 55;
            }
        }

    }
    while (l==0);
    error=Board(a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);
    if (error==1)
    {
        printf("Error in function Board: invalid value 1");
        return 56;
    }
    if (error==2)
    {
        printf("Error in function Board: invalid value 2");
        return 57;
    }
    if (error==3)
    {
        printf ("Error in function Board: invalid value 3");
        return 58;
    }
    if (error==4)
    {
        printf ("Error in function Board: invalid value 4");
        return 59;
    }
    if (error==5)
    {
        printf ("Error in function Board: invalid value 5");
        return 60;
    }
    if (error==6)
    {
        printf ("Error in function Board: invalid value 6");
        return 61;
    }
    if (error==7)
    {
        printf ("Error in function Board: invalid value 7");
        return 62;
    }
    if (error==8)
    {
        printf ("Error in function Board: invalid value 8");
        return 63;
    }
    if (error==9)
    {
        printf ("Error in function Board: invalid value 9");
        return 64;
    }
    if (error==10)
    {
        printf ("Error in function Board: printf call error 1");
        return 65;
    }
    return 0;
}
#   t i c t a c t o e  
 