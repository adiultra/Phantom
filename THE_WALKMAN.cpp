/***THE WALK MAN    (c)ARCHITDWIVEDI//ARCDWI. ALL RIGHTS RESERVED***/
/*************************************************************/

#include <iomanip.h>
#include <ctype.h>
#include <fstream.h>
#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <string.h>

typedef char str[80];

int indicator=1;
char a[15][16];
//          SOME FUNCTIONS TO CREATE USER INTERACTIVE INTERFACE        //

///////   CURTAIN     ///////
char bar(int k){
    if(k%2==0)
    return '/';
    else
    return '|';
}

void curtain(){

    char tbar;
    int i,j=0,k;
    for(i=1,j=79;i<80,j>0;i++,j--){
        for(k=1;k<25;k++){
            if(j>=76){
                gotoxy(j,k);
                tbar=bar(k);
                cout<<tbar;
            }
            else{
                gotoxy(j+4,k);
                cout<<' ';
                gotoxy(j,k);
                tbar=bar(k);
                cout<<tbar;

            }
            if(i<=4){
                gotoxy(i,k);
                tbar=bar(k);
                cout<<tbar;
            }
            else{
                gotoxy(i-4,k);
                cout<<' ';
                gotoxy(i,k);
                tbar=bar(k);
                cout<<tbar;
            }

        }
        delay(100);
    }
}
////////   </>CURTAIN    ///////////

///////   LOAD     ////////////
void load(){
    int i,j,k;
    char a[80];

    for(i=0;i<79;i++){
       a[i]=' ';
    }

    a[79]='\0';

    for(i=0;i<2;i++){

        for(j=0;j<79;j++){

            if(j<4){
                a[j]='|';
                delay(100);
                clrscr();
                cout<<"**********LOADING PLEASE WAIT********"<<endl<<endl<<endl<<endl<<endl<<endl;
                cout<<a;
            }

            if(j>=4){
                a[j-4]=' ';
                a[j]='|';
                delay(100);

                clrscr();
                cout<<"**********LOADING PLEASE WAIT********"<<endl<<endl<<endl<<endl<<endl<<endl;
            	cout<<a;
            }
        }
   }

   getch();

}

///////   </>LOAD ///////

////// P2050    ////////
void p2050(){
    fstream a("2050.txt",ios::in);
    str k;
    while(!a.eof())
    {
      a.getline(k,80);
      puts(k);
    }
}
////// </>P050   //////

//          </>SOME FUNCTIONS TO CREATE USER INTERACTIVE INTERFACE  //

//// Constructing the platform  ///
void construct(){
int i, j, k;
for(i=0; i<15; i++){

if(i%2==1){

	for(j=0; j<15; j++){

		if(j%2==0)
			::a[i][j]='|';
			else ::a[i][j]=' ';
			}
	 }
	 else{

	 for(k=0; k<15; k++)
	 ::a[i][k]='~';
	 }
 ::a[i][15]='\0';

}
}
////////// </>Constructing the platform  //////


////// some functions needed to reduse the code length  //////
int check_level(int r, int c, char f){
	int i, j, count=0;
	for(i=c, j=c; i<=15, j>=0;i++, j--){
		if(::a[r][j]!=f&&::a[r][j]!='|'&&::a[r][j]!='~'&&::a[r][i]!=f&&::a[r][i]!='|'&&::a[r][i]!='~'){
			break;
		}
		else if(::a[r][j]==f||::a[r][i]==f){
			count++;
		}
	}
	return count;
}

int check_vertical(int r, int c, char f){
	 int i, count=0;
	for(i=r ; i<15; i++){
		if(::a[i][c]!=f&&::a[i][c]!='|'&&::a[i][c]!='~'){
			break;
		}
		else if(::a[i][c]==f){
			count++;
		}
	}
	return count;
}

int check_diagonalr(int r, int c, char f){
  int i, j, ccount=0;
 j=c;
 for(i=r; i>=0; i--, c++){
	if(::a[i][c]!=f&&::a[i][c]!='|'&&::a[i][c]!='~'&&c>15){
	  break;
	}
	else if(::a[i][c]==f){
	  ccount++;
	}
 }
 for(i=r; i<=14; i++, j--){
	if(::a[i][j]!=f&&::a[i][j]!='|'&&::a[i][j]!='~'&&j<0){
	  break;
	}
	else if(::a[i][j]==f){
	  ccount++;
	}
 }
 return ccount;
}

int check_diagonall(int r, int c, char f){
	 int i, j, ccount=0;
	 j=c;
	for(i=r; i>=0; i--, c--){
		if(::a[i][c]!=f&&::a[i][c]!='|'&&::a[i][c]!='~'&&c<=0){
			break;
		}
		else if(::a[i][c]==f){
			ccount++;
		}
	}
	for(i=r; i<=14; i++, j++){
		if(::a[i][j]!=f&&::a[i][j]!='|'&&::a[i][j]!='~'&&j>=15){
			break;
		}
		else if(::a[i][j]==f){
			ccount++;
		}
	}
	return ccount;
}

/////   </>some functions needed to reduse the code length    ///////



//       function to check victory automatically        //
void check(char f, int r, int c){
	if(f=='x'){
		if(check_level(r, c, 'x')==4||check_vertical(r, c, 'x')==4||check_diagonalr(r, c, 'x')==5||check_diagonall(r, c, 'x')==5){
			indicator=0;
			cout<<"\n*******    "<<f<<"\tWON******"<<endl;
		}

		  else indicator=1;
	}
	if(f=='0'){
		if(check_level(r, c, '0')==4||check_vertical(r, c, '0')==4||check_diagonalr(r, c, '0')==5||check_diagonall(r, c, '0')==5){
		indicator=0;
		cout<<"\n*******    "<<f<<"\tWON******"<<endl;
	}
		else indicator=1;
	}
}
//        </>function to check victory automatically        //


//        THE WALK MAN        //
void play_walkman(){
clrscr();
int i, j, k, e, c=0, m=0;
char f;
construct();
cout<<setw(40)<<"PLAYER 1"<<endl;
int turn=-1;
///////// THE WALK MAN   /////////////
while(1){
    turn++;
	clrscr();
	for(i=0; i<15; i++)
	puts(::a[i]);
	if(turn%2==0)
	cout<<setw(40)<<"PLAYER 1"<<endl;
	else
	cout<<setw(40)<<"PLAYER 2"<<endl;
	x:
	cout<<"Enter in between 1 to 7."<<endl;
	cin>>e;
  //is(!isnum(e))
  //goto x;
	const int t=e*2-1;
	if(t<=0||t>14){
		cout<<"\aUh!Oh!\nINVALID ENTRY...\nEnter in between 1 to 7."<<endl;
		  cout<<"press any key to continue";
		getch();
		  clrscr();
		for(i=0; i<15; i++)
		puts(::a[i]);
		if(turn%2==0)
		cout<<setw(40)<<"PLAYER 1"<<endl;
		else
		cout<<setw(40)<<"PLAYER 2"<<endl;
		goto x;
	}
	for(i=13; i>=0; i--)
	{
		 c=0;
		 if(::a[i][t]==' '){

			  for(j=0; j<15; j++){

					 for(k=0; k<15; k++){

						if(::a[j][k]=='x'||::a[j][k]=='0')
						c++;
						}
				 }
			if(c%2==0){
				f='x';
				m=i;
				::a[i][t]='x';
			}

			else {
				f='0';
				m=i;
				::a[i][t]='0';
			}
			break;
		  }
	}
	check(f, m, t);
	if(indicator==1){
	continue;
	}
	else{
		clrscr();
		for(i=0; i<15; i++)
		puts(::a[i]);
		check(f, m, t);
		break;
	}
}
cout<<"Thank You!!\nCome Again"<<endl;
}
///////// </>THE WALK MAN   /////////////


//////// THE MAIN FUNCTION OF THE PROGRAM  //////////
void main(){
	clrscr();
	cout<<"HOPE YOU'LL ENJOY THE GAME FROM 2050..\n'THE WALK MAN'"<<endl;
	getch();
	
	p2050();
	cout<<"Press any key!"<<endl;
	getch();
	
	curtain();
	getch();
	
	cout<<"\n Let's play_walkman....\nPress any key"<<endl;
	getch();
	
	play_walkman();
	getch();
}
