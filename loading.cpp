/*******************************************************************************
                           ......VIRTUAL LOADING......
*******************************************************************************/

#include<iostream.h>
#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<string.h>

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

void main(){
	load();
}
