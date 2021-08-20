#include<iostream>
#include<conio.h>
#include<dos.h> 
#include <windows.h>
#include <time.h>
#include <string.h>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void borderr(int x=0, int y=0){
	char v = 186; // vertical
    char h = 205; // horizontal
    char tr = 187; // tkk right border
    char br = 188; // bottom right border
    char tl = 201; // tkk left border
    char bl = 200; // bottom left border
    int width = 30; 
    int height = 3;
    
    for( int i=1; i<=height; i++ ){
		for( int j=1; j<=width; j++ ){
	    	gotoxy(j+x,i+y);
	    	if( i==1 && j==1 ) cout<< tl;
			else if( i==height && j==1 ) cout<< bl;
	    	else if( i==1 && j==width ) cout<< tr;
			else if( i==height && j==width ) cout<< br;
			else if( i==1 || i==height ) cout<< h;
			else if( j==1 || j==width ) cout<< v;
		}
	}
}

int main() {
    srand((unsigned) time(NULL));
	
	system("cls");
 	  
 	char password[21];
 	int length;
 	
	char kk;
	do{
		system("cls");
		
		cout<<"±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±"<<endl;
		
		cout<<"        PASSWORD  STRENGTH  CHECKER      "<<endl;
		cout<<"±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±"<<endl<<endl; 
		  
		cout<<endl<<"\tEnter Password: ";
		cin>> password;
			   
		char pass[21] = "";
		int ex = strlen(password) - 6;
		int basemarks = 50;
		
		int n1 = 0;
		int n2 = 0;
		int n3 = 0;
		int n4 = 0;
		
		int bonusex = 3;
		int bnsupr = 4;
		int bnsnum = 5;
		int bnssym = 5;
		int bnscmb = 0; 
		int bnsf1 = 0;
		int bnsf2 = 0;
		
		int i;
		for( i=0; i<strlen(password); i++ ){
			if( password[i] >= 48 && password[i] <= 57 ){  // 0-9
				n4++;
			}
			if( password[i] >= 97 && password[i] <= 125 ){ // a-z
				n3++;
			}
			if( password[i] >= 65 && password[i] <= 90 ){ // A-Z
				n1++;
			}
			if( password[i] >= 33 && password[i] <= 47 ){ //symbols
				n2++;
			}
		}
		
		if (n1>0 && n4>0 && n2>0)
		{
			bnscmb = 25; 
		}
	
		else if ((n1>0 && n4>0) || (n1>0 && n2>0) || (n4>0 && n2>0))
		{
			bnscmb = 15; 
		}
		
		int marks = basemarks + (ex*bonusex) + (n1*bnsupr) + 
				(n4*bnsnum) + (n2*bnssym) + 
				bnscmb + bnsf1 + bnsf2;	
		 
		gotoxy(8,14); 
		cout<<"Checking Password Strength...";
		gotoxy(8,15); 
		for(int i=0; i<27; i++){
			cout<<(char)176;
			Sleep(100);
		}
		  
		borderr(7,17);
		
		gotoxy(10,19); 
		if (marks<50)
		{
			cout<<endl<<"Password Status: Weak"; 
		}
		else if (marks>=50 && marks<75)
		{
			cout<<endl<<"Password Status: Average"; 
		}
		else if (marks>=75 && marks<100)
		{
			cout<<endl<<"Password Status: Strong"; 
		}
		else if (marks>=100)
		{
			cout<<endl<<"Password Status: Very high/Secure"; 
		} 
		
		gotoxy(9,23); cout<<endl<<"Do you want to generate password again (y/n): ";
		kk = getch();
	}while(kk=='y' || kk=='Y');
	
    return 0;
}