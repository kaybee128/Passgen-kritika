#include<iostream>
#include<conio.h>
#include<dos.h> 
#include <windows.h>
#include <time.h>

using namespace std;
 

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
void cursorr(bool visible, DWORD size) {
	if(size == 0)
		size = 20;	
	
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}

void borderline(int x=0, int y=0){
	char v = 186; // vertical
    char h = 205; // horizontal
    char tr = 187;
    char br = 188;
    char tl = 201;
    char bl = 200;
    int width = 24;
    int height = 4;
    
    gotoxy(x+4, y); cout<<"Generated Password";
    
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
	cursorr(0,0);  
	
	system("cls");
 	  
 	int comp;
 	int length;
 	
	char kk;
	do{
		system("cls");
		
		cout<<endl<<endl;
		cout<<"======================================="<<endl;
		cout<<"         PASSWORD  GENERATOR           "<<endl;
		cout<<"======================================="<<endl<<endl;
		
		cout<<"Ans the following- "<<endl<<endl;
		
		
		do{
			cout<<"1-Weak   |   2-Average   |   3-Strong"<<endl;
			cout<<endl<<"Select comp (1-3): ";
			cin>> comp;
			
			if( comp<1 || comp>3)
				cout<<"Invalid comp Entered. Please Re-Enter"<<endl;
		}while( comp<1 || comp>3 );
		
		if( comp == 1) length = 8;
		else if( comp == 2) length = 14;
		else length = 20;
	
		char passwrd[21] = "";
		
		int i;
		for( i=0; i<length; i++ ){
			if( comp == 1 ){
				if( rand()%2 == 0 )
					passwrd[i] = 97 + rand()%26;
				else
					passwrd[i] = 48 + rand()%10;
			}
			else if( comp == 2 ){
				if( rand()%3 == 0 )
					passwrd[i] = 97 + rand()%26;
				else if( rand()%3 == 1 )
					passwrd[i] = 65 + rand()%26;
				else
					passwrd[i] = 48 + rand()%10;
			}
			else if( comp == 3 ){
				if( rand()%4 == 0 )
					passwrd[i] = 97 + rand()%26;
				else if( rand()%4 == 1 )
					passwrd[i] = 65 + rand()%26;
				else if( rand()%4 == 2 )
					passwrd[i] = 33 + rand()%15;
				else
					passwrd[i] = 48 + rand()%10;
			}
		}
		passwrd[i] = '\0';
		
		cout<<"\n\n\t\t    Generating Password \n\t\t\t";
		for(int i=0; i<10; i++){
			cout<<(char)176;
			Sleep(200);
		}
		
		system("cls");
		borderline(8,5);
		
		gotoxy(11,8); cout<<passwrd;
		
		gotoxy(10,15); cout<<endl <<"Do you want to generate password again (y/n): ";
		kk = getch();
	}while(kk=='y' || kk=='Y');
	
    return 0;
}