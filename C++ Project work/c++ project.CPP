#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<dos.h>//for delay()
#include<string.h>
#include<stdio.h>
#include<process.h>//for exit()
#include<iomanip.h>//for setw()
char name[20],item[30][30],check;
int c1,num=0,nump=0,numq=0,qty[30];
double price[30];
//############### Class laptop ############################
class laptop
{
char model[20],process[40],memory[30],os[40],ofeatures[50];
float display;
double lprice;
unsigned int hdd,bbackup;
public:
void enter()
{
cout<<"\n\n\tEnter Model name=>";cin>>model;
cout<<"\tEnter processor details=>";gets(process);
cout<<"\tEnter memory details(in GB)=>";gets(memory);
cout<<"\tEnter Harddisk details(in GB)=>";cin>>hdd;
cout<<"\tEnter Display size(in inch)=>";cin>>display;
cout<<"\tEnter Battery backup details(in hrs)=>";cin>>bbackup;
cout<<"\tEnter OS details=>";gets(os);
cout<<"\tEnter price(in Rs.)=>";cin>>lprice;
cout<<"\tOther features=>";gets(ofeatures);
}//enter closed
void show()
{
cout<<"\tModel name=>"<<model;
cout<<"\n\tProcessor=>"<<process;
cout<<"\n\tMemory=>"<<memory<<"GB";
cout<<"\n\tHarddisk=>"<<hdd<<"GB";
cout<<"\n\tDisplay=>"<<display<<"inch";
cout<<"\n\tBattery Backup=>"<<bbackup<<"hrs";
cout<<"\n\tOperating system=>"<<os;
cout<<"\n\tPrice=>Rs"<<lprice;
cout<<"\n\tOther features=>"<<ofeatures;
}//show closed
char * mname()
{return model;
}
float price()
{return lprice;}
~laptop(){cout<<"Memory free.......";};//destructor DDDDDDDD
}lappy;//class laptop closed
//################## Class laptop created ########################
//################## Class desktop created #######################
class desktop
{
char model[20],process[40],memory[30],os[40],ofeatures[50];
float display;
double dprice;
unsigned int hdd,bbackup;
public:
void enter()
{
cout<<"\n\n\tEnter Model name=>";cin>>model;
cout<<"\tEnter processor details=>";gets(process);
cout<<"\tEnter memory details(in GB)=>";gets(memory);
cout<<"\tEnter Harddisk details(in GB)=>";cin>>hdd;
cout<<"\tEnter Display size(in inch)=>";cin>>display;
cout<<"\tEnter Battery backup details(in hrs)=>";cin>>bbackup;
cout<<"\tEnter OS details=>";gets(os);
cout<<"\tEnter price(in Rs.)=>";cin>>dprice;
cout<<"\tOther features=>";gets(ofeatures);
}//enter closed
void show()
{
cout<<"\tModel name=>"<<model;
cout<<"\n\tProcessor=>"<<process;
cout<<"\n\tMemory=>"<<memory<<"GB";
cout<<"\n\tHarddisk=>"<<hdd<<"GB";
cout<<"\n\tDisplay=>"<<display<<"inch";
cout<<"\n\tBattery Backup=>"<<bbackup<<"hrs";
cout<<"\n\tOperating system=>"<<os;
cout<<"\n\tPrice=>Rs"<<dprice;
cout<<"\n\tOther features=>"<<ofeatures;
}//show closed
char * mname()
{return model;
}
float price()
{return dprice;}
~desktop(){cout<<"Memory free.......";};//destructor DDDDDDDD
}desktop;//class desktop closed
// #################### Class desktop created #########################
//###################### Class customer ###########################
class customer
{
char cname[20];
char caddress[30];
char cphone[12];
char cbillno[10];
char email[40];
char date[20];
char mcheck;
public:
~customer() {cout<<"Memory Free.......";}//Destructor DDDDDDDDD
void center()
{
cout<<"\tEnter Customer name=>";gets(cname);
cout<<"\tEnter Customer Address=>";gets(caddress);
cout<<"\tEnter Customer phone no=>";gets(cphone);
cout<<"\tEnter Email Id=>";gets(email);
cout<<"\tEnter date of purchase=>";gets(date);
cout<<"\tEnter Customer Bill no=>";cin>>cbillno;
}//customer's entry closed
void cshow()
{
cout<<"\n\tCustomer Name=>"<<cname;
cout<<"\n\tCustomer Address=>"<<caddress;
cout<<"\n\tCustomer Phone no=>"<<cphone;
cout<<"\n\tCustomer Email Id=>"<<email;
cout<<"\n\tDate of purchase=>"<<date;
cout<<"\n\tCustomer bill no=>"<<cbillno;
}//cshow closed
int csearch(char x[])
{ return (strcmpi(cbillno,x)); }//customer search SSSSSSSSSSSSSSS
}cshop;//class customer closed
//############################ class customer created ########################################

//############### Customer Menu Start's from here ###############################
void title2()
{
cout<<"\n\n";
cout<<"*******************************************************************";
cout<<"\n$$$$$          ###Welcome to NITRO TECHNOLOGIES###             $$$$$$\n";
cout<<"*******************************************************************";
cout<<"\n\n";
}
void customer()//Customer menu
{cst:
clrscr();
int choice;cout<<"\n\n";
cout<<"*******************************************************************";
cout<<"\n$$$$$          ###Welcome to NITRO TECHNOLOGIES###             $$$$$$\n";
cout<<"*******************************************************************";
cout<<"\n\n";
cout<<"\t\t1.Laptops\n\t\t2.Desktops\n\t\t3.Windows Original OS cd\n\t\t4.Antivirus Software";
cout<<"\n\t\t5.Pendrives\n\t\t6.Harddisk\n\t\t7.Printer\n\t\t8.RAM\n\t\t9.Cash Memo\n\t\t10.Login menu\n\t\t11.Exit";
cout<<"\n\t\tPlease enter your choice=>";cin>>choice;
      switch(choice)
	{
	  case 1:clrscr();title2();char answer,answer2;
		 ifstream ofile("laptop.txt",ios::in);
		       if(!ofile)
			{
			cout<<"\n\n\tNo Entry available....";getch();
			ofile.close(); goto cst;
			}
			ofile.read((char *)&lappy,sizeof(lappy));
			while(!ofile.eof())
			{
			clrscr();title2();
			lappy.show();
			ofile.read((char *)&lappy,sizeof(lappy));
			cout<<"\n\tDo you want to purchase it?(Y/N)=>";cin>>answer;
			  if(answer=='y'||answer=='Y')
			    { strcpy(item[num++],lappy.mname());
			      price[nump++]=lappy.price();qty[numq++]=1;
			      cout<<"\n\tItem added to your shopping list..";
			      getch();break;
			     }
			 }//while loop closed
			  if(answer=='y')
			   { cout<<"\n\tDo you want to purchase more(Y/N)=>";
				  cin>>answer2;
				       if(answer2=='y'||answer2=='Y')
					 { ofile.close();  goto cst; }
				       else
					 { ofile.close(); break;}
			   }
			cout<<"\n\tLast Record reached.....back to main menu";
			getch();ofile.close();
			goto cst;
	  case 2:clrscr();title2();char answer3,answer4;
		 ifstream ofile2("desktop.txt",ios::in);
		       if(!ofile2)
			{
			cout<<"\n\n\tNo Entry available....";getch();
			ofile2.close();
			goto cst;
			}
			ofile2.read((char *)&desktop,sizeof(desktop));
			while(!ofile2.eof())
			{
			 clrscr();title2();
			 desktop.show();
			 ofile2.read((char *)&desktop,sizeof(desktop));
			 cout<<"\n\tDo you want to purchase it?(Y/N)=>";cin>>answer3;
			  if(answer3=='y'||answer3=='Y')
			    { strcpy(item[num++],desktop.mname());
			      price[nump++]=desktop.price();qty[numq++]=1;
			      cout<<"\n\tItem added to your shopping list..";
			      getch();break;
			     }
			  }
			   if(answer3=='y')
			     { cout<<"\n\tDo you want to purchase more(Y/N)=>";
				  cin>>answer4;
				       if(answer4=='y'||answer4=='Y')
					 { ofile2.close(); goto cst; }
				       else
					 { ofile2.close(); break; }
			      }
			cout<<"\n\tLast Record reached.....back to main menu";
			getch();ofile2.close();
			goto cst;
	  case 3:os:clrscr();title2();
		 cout<<"\t\t%%%%%Windows Original Operating System Cds%%%%";
		 cout<<"\n\n\t\tItem list"<<setw(20)<<"Rate";
		 cout<<"\n\t\t---------"<<setw(20)<<"----";
		 cout<<"\n\t\t1.Windows 98"<<setw(20)<<500;
		 cout<<"\n\t\t2.Windows XP"<<setw(20)<<1500;
		 cout<<"\n\t\t3.Windows Vista"<<setw(17)<<3000;
		 cout<<"\n\t\t4.Windows 7"<<setw(21)<<5000;
		 cout<<"\n\t\t5.Windows 8"<<setw(21)<<10000;
		 cout<<"\n\t\tPlease enter your choice=>";cin>>c1;
		  switch(c1)
		     {
		      case 1:strcpy(item[num++],"Windows 98 Cd");
			     price[nump++]=500;break;
		      case 2:strcpy(item[num++],"Windows XP Cd");
			     price[nump++]=1500;break;
		      case 3:strcpy(item[num++],"Windows Vista Cd");
			     price[nump++]=3000;break;
		      case 4:strcpy(item[num++],"Windows 7 Cd");
			     price[nump++]=5000;break;
		      case 5:strcpy(item[num++],"Windows 8 Cd");
			     price[nump++]=10000;break;
		      default:cout<<"\n\t\tPlease choose the right option...";
			getch();clrscr();
			goto os;
			}
		    cout<<"\n\t\tEnter quantity=>";cin>>qty[numq++];
		    cout<<"\n\t\tItem added to your shopping list..";getch();
		    cout<<"\n\t\tDo you want to purchase more(Y/N)=>";
		    cin>>check;
		    if(check=='y'||check=='Y')
			goto cst;
		    else
			break;
	     case 4:av:clrscr();title2();
		 cout<<"\t\t%%%%%Antivirus Software Cds%%%%";
		 cout<<"\n\n\t\tItem list"<<setw(20)<<"Rate";
		 cout<<"\n\t\t---------"<<setw(20)<<"----";
		 cout<<"\n\t\t1.Norton"<<setw(20)<<3000;
		 cout<<"\n\t\t2.Kaspersky"<<setw(17)<<2500;
		 cout<<"\n\t\t3.Avira"<<setw(21)<<2000;
		 cout<<"\n\t\t4.Quick heal"<<setw(16)<<1800;
		 cout<<"\n\t\t5.McAfee"<<setw(20)<<2000;
		 cout<<"\n\t\tPlease enter your choice=>";cin>>c1;
		   switch(c1)
		   {
		     case 1:
		      strcpy(item[num++],"Norton Antivirus");
		      price[nump++]=3000;break;
		     case 2:
		      strcpy(item[num++],"Kaspersky Antivirus");
			     price[nump++]=2500;break;
		     case 3:
			strcpy(item[num++],"Avira Antivirus");
			     price[nump++]=2000;break;
		     case 4:
			 strcpy(item[num++],"Quick heal Antivirus");
			     price[nump++]=1800;break;
		      case 5:
			strcpy(item[num++],"McAfee Antivirus");
			 price[nump++]=2000;break;

		     default:
			cout<<"\n\t\tPlease choose the right option...";
			getch();clrscr();
			goto av;
		      }
		    cout<<"\n\t\tEnter quantity=>";cin>>qty[numq++];
		    cout<<"\n\t\tItem added to your shopping list..";getch();
		    cout<<"\n\t\tDo you want to purchase more(Y/N)=>";
		    cin>>check;
		    if(check=='y'||check=='Y')
			goto cst;
		    else
			break;
	    case 5:pen:clrscr();title2();
		 cout<<"\t\t%%%%%Pendrives%%%%";
		 cout<<"\n\n\t\tItem list"<<setw(20)<<"Rate";
		 cout<<"\n\t\t---------"<<setw(20)<<"----";
		 cout<<"\n\t\t1.1 GB"<<setw(23)<<200;
		 cout<<"\n\t\t2.2 GB"<<setw(23)<<300;
		 cout<<"\n\t\t3.4 GB"<<setw(23)<<400;
		 cout<<"\n\t\t4.8 GB"<<setw(23)<<650;
		 cout<<"\n\t\t5.16 GB"<<setw(22)<<999;
		 cout<<"\n\t\tPlease enter your choice=>";cin>>c1;
		  switch(c1)
		     {
		      case 1 :
		      strcpy(item[num++],"1GB pendrive");
		      price[nump++]=200;break;
		     case 2:
		      strcpy(item[num++],"2GB pendrive");
			     price[nump++]=300;break;
		     case 3:
		      strcpy(item[num++],"4GB pendrive");
			     price[nump++]=400;break;
		     case 4:
		      strcpy(item[num++],"8GB pendrive");
			     price[nump++]=650;break;
		     case 5:
		      strcpy(item[num++],"16GB pendrive");
			 price[nump++]=999;break;
		     default:
			cout<<"\n\t\tPlease choose the right option...";
			getch();clrscr();
			goto pen;
		      }
		    cout<<"\n\t\tEnter quantity=>";cin>>qty[numq++];
		    cout<<"\n\t\tItem added to your shopping list..";getch();
		    cout<<"\n\t\tDo you want to purchase more(Y/N)=>";
		    cin>>check;
		    if(check=='y'||check=='Y')
			goto cst;
		    else
			break;
	       case 6:hdd:clrscr();title2();
		 cout<<"\t\t%%%%%Hard Disk%%%%";
		 cout<<"\n\n\t\tItem list"<<setw(20)<<"Rate";
		 cout<<"\n\t\t---------"<<setw(20)<<"----";
		 cout<<"\n\t\t1.80 GB"<<setw(23)<<999;
		 cout<<"\n\t\t2.160 GB"<<setw(22)<<1499;
		 cout<<"\n\t\t3.250 GB"<<setw(22)<<1999;
		 cout<<"\n\t\t4.320 GB"<<setw(22)<<2999;
		 cout<<"\n\t\t5.500 GB"<<setw(22)<<3999;
		 cout<<"\n\t\tPlease enter your choice=>";cin>>c1;
		  switch(c1)
		     {
		      case 1:strcpy(item[num++],"80 GB HDD");
			     price[nump++]=999;break;
		      case 2:strcpy(item[num++],"160 GB HDD");
			     price[nump++]=1499;break;
		      case 3:strcpy(item[num++],"250 GB HDD");
			     price[nump++]=1999;break;
		      case 4:strcpy(item[num++],"320 GB HDD");
			     price[nump++]=2999;break;
		      case 5:strcpy(item[num++],"500 GB HDD");
			     price[nump++]=3999;break;
		      default:cout<<"\n\t\tPlease choose the right option...";
			getch();clrscr();
			goto hdd;

		       }
		    cout<<"\n\t\tEnter quantity=>";cin>>qty[numq++];
		    cout<<"\n\t\tItem added to your shopping list..";getch();
		    cout<<"\n\t\tDo you want to purchase more(Y/N)=>";
		    cin>>check;
		    if(check=='y'||check=='Y')
			goto cst;
		    else
			break;
	      case 7:printer:clrscr();title2();
		 cout<<"\t\t%%%%%Printer%%%%";
		 cout<<"\n\n\t\tItem list"<<setw(20)<<"Rate";
		 cout<<"\n\t\t---------"<<setw(20)<<"----";
		 cout<<"\n\t\t1.Laser Jet"<<setw(20)<<7000;
		 cout<<"\n\t\t2.Dot Matrix"<<setw(19)<<4000;
		 cout<<"\n\t\tPlease enter your choice=>";cin>>c1;
		  switch(c1)
		     {
		      case 1:strcpy(item[num++],"Laser Jet Printer");
			     price[nump++]=7000;break;
		      case 2:strcpy(item[num++],"Dot Matrix Printer");
			     price[nump++]=4000;break;
		      default:cout<<"\n\t\tPlease choose the right option...";
			getch();clrscr();
			goto printer;
		       }
		    cout<<"\n\t\tEnter quantity=>";cin>>qty[numq++];
		    cout<<"\n\t\tItem added to your shopping list..";getch();
		    cout<<"\n\t\tDo you want to purchase more(Y/N)=>";
		    cin>>check;
		    if(check=='y'||check=='Y')
			goto cst;
		    else
			break;
		case 8:ram:clrscr();title2();
		 cout<<"\t\t\t%%%%%R.A.M%%%%";
		 cout<<"\n\n\t\tItem list"<<setw(20)<<"Rate";
		 cout<<"\n\t\t---------"<<setw(20)<<"----";
		 cout<<"\n\t\t1.1 GB"<<setw(23)<<999;
		 cout<<"\n\t\t2.2 GB"<<setw(23)<<1800;
		 cout<<"\n\t\t3.3 GB"<<setw(23)<<2500;
		 cout<<"\n\t\t4.4 GB"<<setw(23)<<4000;
		 cout<<"\n\t\tPlease enter your choice=>";cin>>c1;
		  switch(c1)
		     {
		      case 1:strcpy(item[num++],"1 GB RAM");
			     price[nump++]=999;break;
		      case 2:strcpy(item[num++],"2 GB RAM");
			     price[nump++]=1800;break;
		      case 3:strcpy(item[num++],"3 GB RAM");
			     price[nump++]=2500;break;
		      case 4:strcpy(item[num++],"4 GB RAM");
			     price[nump++]=4000;break;
		      default:cout<<"\n\t\tPlease choose the right option...";
			getch();clrscr();
			goto ram;
		       }
		    cout<<"\n\t\tEnter quantity=>";cin>>qty[numq++];
		    cout<<"\n\t\tItem added to your shopping list..";getch();
		    cout<<"\n\t\tDo you want to purchase more(Y/N)=>";
		    cin>>check;
		    if(check=='y'||check=='Y')
			goto cst;
		    else
			break;
		case 9:if(qty[0]==NULL)
			{ cout<<"\n\t\tYou have not purchased anything....";
			  getch();
			  goto cst;
			 }
		       else
			 break;
		case 10:delay(500);return;
		case 11:cout<<"\n\n\tThank you for visiting....";getch();
		      exit(0);
		default:cout<<"\n\tPlease enter correct option.....";getch();
		      goto cst;

	}//switch closed
clrscr();
title2();int size,s; float total=0;
cout<<"\n\t#########################################################";
cout<<"\n\tItems"<<setw(26)<<"Quantity"<<setw(20)<<"NetPrice";
cout<<"\n\t#########################################################";
cout<<"\n\n\t";
for(int i=0;i<num;i++)
{
cout<<item[i];
size=strlen(item[i]);
s=size>10?(size-10):(10-size);
if(size>10)
{ cout<<setw(20-s)<<qty[i]<<setw(20)<<qty[i]*price[i]; }
else
{ cout<<setw(20+s)<<qty[i]<<setw(20)<<qty[i]*price[i]; }
cout<<"\n\t";
total+=(qty[i]*price[i]); }//for loop closed
cout<<"\n\t-------------------------------------------------";
cout<<"\n\tTotal=>Rs"<<total;
cout<<"\n\n\tEnter customer details below...\n";
ofstream cmemo;
cmemo.open("shop.txt",ios::app);
cshop.center();
cmemo.write((char *)&cshop,sizeof(cshop));
clrscr();title2();cmemo.close();
 int x=0;
  do
   {
    cout<<"\n\n\tPlease Wait";
       for(int z=0;z<6;z++)
	 { delay(500);cout<<".";}
       clrscr();title2();x++;
    }while(x<3);
cout<<"\n\tCustomer record saved....Thank you for visiting";
getch();exit(0);
}//customer closed
 void title()
 {clrscr();
cout<<"\n\n";
cout<<"\t#####################################################################";
cout<<"\n\t      *** Welcome to NITRO TECHNOLOGIES DATABASE ***     ";
cout<<"\n\t#####################################################################";}
void owner()//owner menu
{obeg:clrscr();int choice,c11;long pos;
cout<<"\n\n";
cout<<"\t#####################################################################";
cout<<"\n\t      *** Welcome to NITRO TECHNOLOGIES DATABASE ***     ";
cout<<"\n\t#####################################################################";
cout<<"\n\n\t\t1.Customer Database\n\t\t2.Stock Database\n\t\t3.Login menu\n\t\t4.Exit";
cout<<"\n\n\t\tPlease enter your choice=>";cin>>choice;
       if(choice==1)
	 { cd:
	   title();
	   cout<<"\n\n\t\t=>=>=> Customer Database";
	   cout<<"\n\n\t\t1.View Customer Details\n\t\t2.Search Customer Details";
	   cout<<"\n\t\t3.Back to main menu\n\t\t4.Exit";
	   cout<<"\n\n\t\tPlease Enter your choice=>";cin>>c11;
	       switch(c11)
		{
		 case 1:title();ifstream ifile;
			ifile.open("shop.txt",ios::in);
			if(!ifile)
			{
			cout<<"\n\n\tNo Entry available";
			getch();break;
			}
			ifile.read((char *)&cshop,sizeof(cshop));
			while(!ifile.eof())
			{
			  title();cout<<"\n\n";
			  cshop.cshow();
			  ifile.read((char *)&cshop,sizeof(cshop));
			  cout<<"\n\n\tPress enter for next detail...."; getch();
			}//while loop closed
			cout<<"\n\tLast Record reached.....back to customer database";
			getch();
			ifile.close();
			break;
		   case 2:title();char f='n',search1[10];ifstream ifile2;
			ifile2.open("shop.txt",ios::in);
			if(!ifile2)
			{
			cout<<"\n\n\tNo Entry available";
			getch();break;
			}
			 cout<<"\n\n\tEnter Billno=>";
			 cin>>search1;
			 ifile2.read((char *)&cshop,sizeof(cshop));
			 while(!ifile2.eof())
			 { title();cout<<"\n\n";
			   if(cshop.csearch(search1)==0)
			    { cout<<"\n\n\tCustomer details found.....\n\n";
			       cshop.cshow();f='f';
			       cout<<"\n\n\tPress enter ...";
			       getch();
			    }
			    ifile2.read((char *)&cshop,sizeof(cshop));
			  }//while loop of case 2 closed
			  if(f=='n')
			    {cout<<"\n\tSorry details not found ";
			    getch();
			    }
			    ifile2.close();break;
		case 3:goto obeg;
		case 4:exit(0);
		  }//switch closed
	 goto cd;
	 }//if closed
       else if(choice==2)
	 {sd:title();int c3;
	   cout<<"\n\n\t\t=>=>=> Stock Database";
	   cout<<"\n\t\t1.Laptops\n\t\t2.Desktops\n\t\t3.Back to main menu";
	   cout<<"\n\t\tEnter your choice=>";cin>>c3;
	 if(c3==1)
	   {title();int c2;
	    cout<<"\n\n\t\t=>=>=> Stock Database";
	    cout<<"\n\n\t\t1.Add new Laptop model in stock\n\t\t2.Modify Laptop Model details";
	    cout<<"\n\t\t3.Delete Laptop model\n\t\t4.Back to previous menu";
	    cout<<"\n\n\t\tPlease enter your choice=>";cin>>c2;
	     switch(c2)
	     {
	      case 1:char proceed='y';
	       ofstream file1;
	       file1.open("laptop.txt",ios::app);
		     while(proceed=='y'||proceed=='Y')
		       {title();
			lappy.enter();
			file1.write((char *)&lappy,sizeof(lappy));
			cout<<"\n\n\tRecord saved...";getch();
			cout<<"\n\tDo you want to continue(Y/N)=>";cin>>proceed;
			}
			file1.close();
			break;
	      case 2:title();char f44='f';char s5[10],mcheck; long pos;
		     fstream fio("laptop.txt",ios::in|ios::out|ios::binary);
			  cout<<"\n\n\tEnter model name=>";cin>>s5;
			   while(!fio.eof())
			    {title();
			    pos=fio.tellg();
			    fio.read((char *)&lappy,sizeof(lappy));
				if(strcmpi(s5,lappy.mname())==0)
				 { cout<<"\n\n";
				   lappy.show();f44='t';
				   cout<<"\n\tAre you sure want to modify(Y/N)=>";
				   cin>>mcheck;
				      if(mcheck=='y'||mcheck=='Y')
					 { lappy.enter();
					   fio.seekg(pos);
					   fio.write((char *)&lappy,sizeof(lappy));
					   cout<<"\n\tRecord has been modified...";
					   getch();
					  }
				      else
				       { cout<<"\n\tRecord not modified..";
					getch();break;
				       }
				    }
				  }
			    if(f44=='f')
			       { cout<<"\n\tSorry record not found...";
				 getch(); }
			   fio.close();break;
		  case 3:title();char c='n',f5='f',search6[10];
		    ifstream file3("laptop.txt",ios::in);
		    ofstream ofile3("temp.txt",ios::out);
		    cout<<"\n\n\tEnter model name=>";
		    cin>>search6;
		    file3.read((char *)&lappy,sizeof(lappy));
		    while(!file3.eof())
		     { title();
		       if(strcmpi(search6,lappy.mname())==0)
			 { cout<<"\n\n";
			   lappy.show();
			   f5='t';
			   cout<<"\n\n\tAre you sure,you want to delete this record(Y/N)=>";
			   cin>>c;
			   if(c=='n')
			      ofile3.write((char *)&lappy,sizeof(lappy));
			  }
		       else
			  ofile3.write((char *)&lappy,sizeof(lappy));
		       file3.read((char *)&lappy,sizeof(lappy));
		      }
		    if(f5=='f')
		     {
		      cout<<"\n\tRecord not found!!!";
		      getch();
		     }
		    file3.close();
		    ofile3.close();
		    remove("laptop.txt");
		    rename("temp.txt","laptop.txt");
		    break;
		  case 4:goto sd;
	       }//current switch closed
	  goto sd;}                    //current
	  else if(c3==2)
	      { title();int c4;
		cout<<"\n\n\t\t=>=>=> Stock Database";
	    cout<<"\n\t\t1.Add new desktop model in stock\n\t\t2.Modify Desktop Model details";
	    cout<<"\n\t\t3.Delete Desktop model\n\t\t4.Back to main menu";
	    cout<<"\n\n\t\tPlease enter your choice=>";cin>>c4;
	     switch(c4)
	     {
	      case 1:char proceeD='y';
	       ofstream fileD;
	       fileD.open("desktop.txt",ios::app);
		     while(proceeD=='y'||proceeD=='Y')
		       {title();
			desktop.enter();
			fileD.write((char *)&desktop,sizeof(desktop));
			cout<<"\n\n\tRecord saved...";getch();
			cout<<"\n\tDo you want to continue(Y/N)=>";cin>>proceeD;
			}
			fileD.close();
			break;
	      case 2:title();char df44='f';char ds5[10],dmcheck; long dpos;
		     fstream dfio("desktop.txt",ios::in|ios::out|ios::binary);
			  cout<<"\n\n\tEnter model name=>";cin>>ds5;
			   while(!dfio.eof())
			    {title();
			    dpos=dfio.tellg();
			    dfio.read((char *)&desktop,sizeof(desktop));
				if(strcmpi(ds5,desktop.mname())==0)
				 { cout<<"\n\n";
				   desktop.show();df44='t';
				   cout<<"\n\tAre you sure want to modify(Y/N)=>";
				   cin>>dmcheck;
				      if(dmcheck=='y'||dmcheck=='Y')
					 { desktop.enter();
					   dfio.seekg(dpos);
					   dfio.write((char *)&desktop,sizeof(desktop));
					   cout<<"\n\tRecord has been modified...";
					   getch();
					  }
				      else
				       { cout<<"\n\tRecord not modified..";
					getch();break;
				       }
				    }
				  }
			    if(df44=='f')
			       { cout<<"\n\tSorry record not found...";
				 getch(); }
			   dfio.close();break;
		  case 3:title();char dc='n',df5='f',dsearch6[10];
		    ifstream dfile3("desktop.txt",ios::in);
		    ofstream dofile3("temp.txt",ios::out);
		    cout<<"\n\n\tEnter model name=>";
		    cin>>dsearch6;
		    dfile3.read((char *)&desktop,sizeof(desktop));
		    while(!dfile3.eof())
		     { title();
		       if(strcmpi(dsearch6,desktop.mname())==0)
			 { cout<<"\n\n";
			   desktop.show();
			   df5='t';
			   cout<<"\n\tAre you sure,you want to delete this record(Y/N)=>";
			   cin>>dc;
			   if(dc=='n')
			      dofile3.write((char *)&desktop,sizeof(desktop));
			       
			  }
		       else
			   dofile3.write((char *)&desktop,sizeof(desktop));
			   dfile3.read((char *)&desktop,sizeof(desktop));
		      }
		    if(df5=='f')
		     {
		      cout<<"\n\tRecord not found!!!";
		      getch();
		     }
		    dfile3.close();
		    dofile3.close();
		    remove("desktop.txt");
		    rename("temp.txt","desktop.txt");
		    break;
		  case 4:goto sd;
	       }//current switch closed
	  goto sd;
	       }
	 else if(c3==3) {goto obeg;}
	 else {cout<<"\n\t\tSorry...Wrong choice";getch();goto sd;}
	   }//else if closed
       else if(choice==3)
	 { delay(500);return; }
       else if(choice==4)
	   { cout<<"\n\n\tThank you for visiting";getch();exit(0);}
       else
	    {
	     cout<<"\n\n\tPlease enter correct option...";getch();
	     clrscr();
	     goto obeg;
	     }
}//owner closed

//############  main function   ############################################

void main()//Projects main part
{clrscr();
cout<<"\n\n\n\n\t##############################################################";
cout<<"\n\n\t\t =>=>  Computer Science Project work <=<= ";
cout<<"\n\t\t =>=>   Name=Saurav Bilung           <=<=";
cout<<"\n\t\t =>=>   Roll No=7662439              <=<=";
cout<<"\n\t\t =>=>   Class= XIIth                 <=<=";
cout<<"\n\t\t =>=>   Session=2012-2013            <=<=";
cout<<"\n\n\t###############################################################";
getch();
beg:
clrscr();cout<<endl<<endl;
cout<<"\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
cout<<"\n\t           **Welcome to THE COMPUTER SHOP**                   ";
cout<<"\n\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
cout<<"\n\n\t\tEnter your name=>";gets(name);

cout<<"\n\t\tUser=>";cout<<" ";cout<<"1.Customer";cout<<" ";cout<<"2.Owner";
int a;
cout<<"\n\t\tEnter your choice=>";cin>>a;
	switch(a)
	   {
	     case 2:
		   cout<<"\n\t\tEnter your password=>";
		   char pass[10];
		   pass[0]=getch();cout<<"*";
		   pass[1]=getch();cout<<"*";
		   pass[2]=getch();cout<<"*";
		   pass[3]=getch();cout<<"*";
		   pass[4]=getch();cout<<"*";
		   pass[5]='\0';getch();
		    if(strcmp(pass,"54321")==0)
		      {clrscr();
		       cout<<"\n\tLoading...10%";
		       delay(1000);clrscr();
		       cout<<"\n\tLoading...20%";
		       delay(1000);clrscr();
		       cout<<"\n\tLoading...30%";
		       delay(1000);clrscr();
		       cout<<"\n\tLoading...40%";
		       delay(1000);clrscr();
		       cout<<"\n\tLoading...60%";
		       delay(1000);clrscr();
		       cout<<"\n\tLoading...80%";
		       delay(1000);clrscr();
		       cout<<"\n\tLoading...100%";
		       delay(1000);clrscr();
		       cout<<"\n\tDone";
		       delay(1000);owner();}
		    else
			{
			cout<<"\n\t\tSorry wrong password";getch();
			goto beg;}
		   break;
	     case 1:clrscr();delay(500);
	     customer();
	     break;
	     default:cout<<"\n\t\tPlease enter correct choice";getch();
	     goto beg;
	     }
goto beg;
}