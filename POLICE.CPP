#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>

struct date
{ int d,m,y;
};

struct descr
{ char colour[20];
 char face[20];
 int height[6];
};


class person
{ int adhno;
 date dob;
 char name[40],gen;
 public :
 void pinput()
 { cout<<"\nAadhar No. : ";
  cin>>adhno;
  cout<<"\nName : ";
  gets(name);
  cout<<"\nDate of Birth (dd/mm/yy): ";
  cin>>dob.d>>dob.m>>dob.y;
  cout<<"\n Gender(M/F/O) : ";
  cin>>gen;
 }
 void pshow()
 { cout<<"\nAadhar No. : "<<pid;
  cout<<"\nName : "<<name;
  cout<<"\nDate of Birth : "<<dob.d<<'/'<<dob.m<<'/'<<dob.y;
  cout<<"\nGender : "<<gen;
 }
};


class FIR: public person
{ int fno;
 char add[60],place[30];
 date dooc,dor;
 char des_act[80];
 public:
 void finput();
 void fshow();
 int get_fno()
 { return fno;
 }
}


void FIR :: finput()
{ cout<<"\nFIR No. :";
 cin>>fno;
 cout<<"\nDate of Occurence : ";
 cin>>dooc.d>>dooc.m>>dooc.y;
 cout<<"\nDate when Reported : ";
 cin>>dor.d>>dor.m>>dor.y;
 cout<<"\nPlace where the Incident Occured : ";
 gets(place);
 cout<<"\nDetails of the Informer/Complainant";
 void pinput();
 cout<<"\nA Brief Description of the Incident :";
 gets(des_act);
}

void FIR :: fshow()
{ cout<<"\nFIR No. :"<<fno;
 cout<<"\nDate of Occurence : "
     <<dooc.d<<'/'<<dooc.m<<'/'<<dooc.y;
 cout<<"\nDate when Reported : "
     <<dor.d<<'/'<<dor.m<<'/'<<dor.y;
 cout<<"\nPlace where the Incident Occured : "
     <<place;
 cout<<"\nDetails of the Informer/Complainant";
 void pshow();
 cout<<"\nA Brief Description of the Incident :"
     <<des_act;
}

class criminal: public person
{ int cid;
 date doa;
 descr des;
 public:
 void cinput();
 void cshow();
 int get_cid()
 { return cid;
 }
};

void criminal :: cinput()
{ void pinput();
 cout<<"\nConvict ID :";
 cin>>cid;
 cout<<"\nFace Colour : ";
 cin>>des.color;
 cout<<"\nFace Shape : ";
 cin>>des.face;
 cout<<"\nHeight : ";
 cin>>des.height;
 cout<<"\nDate of Arrest (dd/mm/yy): ";
 cin>>doa.d>>doa.m>>doa.y;
}

void criminal :: cshow()
{ void pshow();
 cout<<"\nConvict ID :"<<cid;
 cout<<"\nFace Colour : "<<des.color;
 cout<<"\nFace Shape : "<<des.face;
 cout<<"\nHeight : "<<des.height;
 cout<<"\nDate of Arrest : "
     <<doa.d<<doa.m<<doa.y;
}


void create_cr()
{ ofstream mf("criminal.dat",ios::binary||ios::app);
 char ch;
 criminal c;
 if(!mf)
 { cout<<"\nError";
  exit(0);
  getch();
  }
 do
 { c.cinput();
  mf.write((char*)&c,sizeof(c));
  cout<<"\nContinue(Y/N)? ";cin>>ch;
  clrscr();
 }while(ch=='y'||ch=='Y');
 mf.close();
}


void display_cr()
{ ifstream mf("criminal.dat",ios::binary);
 if(!mf)
 { cout<<"\nError";
  exit(0);
  getch();
 }
 criminal c;
 mf.read((char*)&c,sizeof(c));
 while(mf)
 { c.cshow();
  mf.read((char*)&c,sizeof(c));
 }
 mf.close();
}

//Input the CONVICT ID to search
void search_cr()
{ ifstream mf("criminal.dat",ios::binary);
 if(!mf)
 { cout<<"\nError";
 exit(0);
 getch();
 }
 criminal c;
int f=0,num;
 cout<<"\nEnter Convict ID for Searching : ";
 cin>>num;
 while(mf&&f==0)
 { if(c.get_cid()==num)
  { c.cshow();
   f=1;
  }
   else
  mf.read((char*)&c,sizeof(c));
 }
 if(f==0)
 cout<<"\nNot found";
 getch();
 mf.close();
}


//Delete record from the file
void deletion_cr()
{ ifstream old("criminal.dat",ios::binary);
 ofstream nf("criminal1.dat",ios::binary);
 criminal c;
 if(!old || !nf)
 { cout<<"\nError";
  getch();
  exit(0);
 }
 int num,f=0;
 cout<<"\nEnter Convict ID : ";cin>>num;
 old.read((char*)&c,sizeof(c));
 while(old)
 { if(num!=c.get_cid())
  nf.write((char*)&c,sizeof(c));
  else
  f=1;
  old.read((char*)&c,sizeof(c));
 }
 old.close();
 nf.close();
 remove("criminal.dat");
 rename("criminal1.dat","criminal.dat");
 if(f==1)
 cout<<"\nRecord Deleted";
 else
 cout<<"\nRecord not found ";
 getch();
}

void convict_menu()
{ char ch;
 int x;
 cout<<"\n1. Entry of a new Convict "
     <<"\n2. Display the Records  of all the Convicts"
     <<"\n3. Search for a Convict's Record"
     <<"\n4. Erase a Convict's Record"
     <<"\n5. Exit"
     <<"\n\t\tEnter your Choice : ";
 cin>>x;
 clrscr();
 switch(x)
 { case 1 : create();
 break;
 case 2 : display();
 break;
 case 3 : search();
 break;
 case 4 : deletion();
 break;
 case 5 : exit(0);
 break;
 default : cout<<"\n\t!ERROR!\n!Wrong Input Given!";
 }
}

void main()
{ char ch;
 int x;
 cout<<"\n1. FIR "
     <<"\n2. Convict Records"
     <<"\n3. Change the Password"
     <<"\n4. Exit"
     <<"\n\t\tEnter your Choice : ";
 cin>>x;
 clrscr();
 switch(x)
 { case 1 : fir_menu();
 break;
 case 2 : convict_menu();
 break;
 case 3 :
 break;
 case 4 : exit(0);
 break;
 default : cout<<"\n\t!ERROR!\n!Wrong Input Given!";
 }
}

