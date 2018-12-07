/*============================================================================
// Name        : videoPoker.cpp
// Author      : Andy-Baba
// Version     :
// Copyright   : You are free to use this project as you like, any questions let me know andykan1984@gmail.com
// Description : Written in Borland C and working on DOS based systems.
//============================================================================*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
typedef unsigned short int shi;
const shi sec=0,col=6,text=2;           		//second araye modate vaghfeha,col range zamineye dialog box,text bara range matn dialog box
struct cart
	{
   shi num;
   shi kin;
   }deck[52],hand[5];
shi handp;												//han pointer jaye neshane gare dar areye decko neshoon  mide
bool sta[5],con;
int i,j,bank=30;
/*************************************IN TAVABE BARAYE GRAPHICE KARAN*****************************************/
void fram(int colour,int x,int y,int w,int h)//in faghat yek fram ba tange delkhah va razo toole delkhah mikeshe
	{
   register shi i,j;
   textattr(colour);
   gotoxy(x,y);
   cprintf("%c",218);
   for(i=0;i<w;i++)
   	cprintf("%c",196);
   cprintf("%c",191);
   for(i=0;i<h;i++)
   	{
      gotoxy(x,y+i+1);
   	cprintf("%c",179);
      for(j=0;j<w;j++)
      	cprintf(" ");
      cprintf("%c",179);
      }
   gotoxy(x,y+h);
   cprintf("%c",192);
   for(i=0;i<w;i++)
   	cprintf("%c",196);
   cprintf("%c",217);
   }
void dialog(int x,int y,int w,int h)    		//vase dialogue box ha
	{
   register shi i,j;
	textattr(112);
   for(i=0;i<w+1;i++)
   	{
   	for(j=0;j<h+1;j++)
      	{
      	gotoxy(x+i-1,y+j-1);
         cprintf(" ");
         }
      }
   fram(16*col+2+8,x,y,w,h);
   }
char key()                                   //in tamame klidhaye tose yaftaro migire
	{
   char key1,key2;
   	if((key1=getch())==0)
         return key2=getch();
      /*else
      	return key1; */
   }
void beh_card(int x,int y)							//in poshte karto neshoon mide
	{
   fram(240,x-2,y-2,9,11);
   textattr(132);
   for(i=0;i<8;i++)
   	{
      gotoxy(x,y+i);
      for(j=0;j<7;j++)
			cprintf("%c",178);
      }
   }
void car_cor(int num,int kin,int x,int y)		//in gooshehaye varagho nomare vakhalesho minevise
	{
   gotoxy(x+1,y+1);
   switch(num)
   	{
      case 11:	cprintf("J");
      			break;
      case 12:	cprintf("Q");
      			break;
      case 13:	cprintf("K");
      			break;
      case 14:	cprintf("A");
      			break;
      default: cprintf("%d",num);
      }
   gotoxy(x+1,y+2);
   cprintf("%c",kin);
   }
void faces(int kin,int x,int y)					//in daroone kartaye soorat daro ba khaleshoon por mikone
	{
   gotoxy(x+3,y+4);
   for(i=y+3;i<y+10;i++)
   	{
   	for(j=0;j<5;j++)
   		cprintf("%c",kin);
   	gotoxy(x+3,i);
   	}
   }
void card(int num,int kin,int x,int y)     	//in kolle kartaye ye dasto neshoon mide
	{
   fram(240,x,y,9,11);
  	if(kin==3 || kin==4)
   	textattr(252);
   switch(num)
   	{
      case 2:	car_cor(num,kin,x,y);
					for(i=4;i<8;i+=3)
                	{
      				gotoxy(x+5,y+i);
                  cprintf("%c",kin);
                  }
               car_cor(num,kin,x+8,y+8);
               break;
      case 3:  car_cor(num,kin,x,y);
					for(i=3;i<8;i+=2)
                	{
      				gotoxy(x+5,y+i);
                  cprintf("%c",kin);
                  }
               car_cor(num,kin,x+8,y+8);
               break;
      case 4:	car_cor(num,kin,x,y);
      			for(i=3;i<8;i+=4)
               	for(j=4;j<8;j+=3)
                		{
      					gotoxy(x+i,y+j);
                  	cprintf("%c",kin);
                  	}
               car_cor(num,kin,x+8,y+8);
               break;
      case 5:	car_cor(num,kin,x,y);
      			for(i=3;i<8;i+=4)
               	for(j=4;j<8;j+=3)
                		{
      					gotoxy(x+i,y+j);
                  	cprintf("%c",kin);
                  	}
               gotoxy(x+5,y+6);
					cprintf("%c",kin);
               car_cor(num,kin,x+8,y+8);
               break;
      case 6:	car_cor(num,kin,x,y);
      			for(i=3;i<8;i+=4)
               	for(j=4;j<9;j+=2)
                		{
      					gotoxy(x+i,y+j);
                  	cprintf("%c",kin);
                  	}
               car_cor(num,kin,x+8,y+8);
               break;
      case 7:	car_cor(num,kin,x,y);
      			for(i=3;i<8;i+=4)
               	for(j=4;j<9;j+=2)
                		{
      					gotoxy(x+i,y+j);
                  	cprintf("%c",kin);
                  	}
               gotoxy(x+5,y+6);
					cprintf("%c",kin);
               car_cor(num,kin,x+8,y+8);
               break;
      case 8:  car_cor(num,kin,x,y);
      			for(i=3;i<8;i+=4)
               	for(j=3;j<10;j+=2)
                		{
      					gotoxy(x+i,y+j);
                  	cprintf("%c",kin);
                  	}
               car_cor(num,kin,x+8,y+8);
               break;
      case 9:	car_cor(num,kin,x,y);
      			for(i=3;i<8;i+=4)
               	for(j=3;j<10;j+=2)
                		{
      					gotoxy(x+i,y+j);
                  	cprintf("%c",kin);
                  	}
               gotoxy(x+5,y+6);
               cprintf("%c",kin);
               car_cor(num,kin,x+8,y+8);
               break;
      case 10: car_cor(num,kin,x,y);
      			for(i=3;i<8;i+=4)
               	for(j=3;j<10;j+=2)
                		{
      					gotoxy(x+i,y+j);
                  	cprintf("%c",kin);
                  	}
               for(i=4;i<8;i+=3)
                	{
      				gotoxy(x+5,y+i);
                  cprintf("%c",kin);
                  }
               car_cor(0,kin,x+8,y+8);
               break;
      case 11: car_cor(num,kin,x,y);
               faces(kin,x,y);
               car_cor(num,kin,x+8,y+8);
               break;
      case 12: car_cor(num,kin,x,y);
      			faces(kin,x,y);
               car_cor(num,kin,x+8,y+8);
               break;
      case 13:	car_cor(num,kin,x,y);
      			faces(kin,x,y);
               car_cor(num,kin,x+8,y+8);
               break;
      case 14: car_cor(num,kin,x,y);
               gotoxy(x+5,y+5);
               cprintf("%c",kin);
               car_cor(num,kin,x+8,y+8);
      }

   }
/************************************************IN TAVABE ASLIYE BAZIYAN*****************************************/
void car_sel(shi cs,shi rs,shi howmo)        //beyne 5 carte bazi ba cursor harkat mikkone va kartaro select mikone
	{
	shi x=cs,stc;
   do
   	{
      gotoxy(x,rs);
   	printf("%c",219);
		switch(stc=key())
   		{
      	case 77:if(x<cs+12*(howmo-1))
         				{
                     gotoxy(x,rs);
                     printf(" ");
                     gotoxy(x+=12,rs);
                     }
         			else
                  	{
                  	gotoxy(x,rs);
                     printf(" ");
                     gotoxy(x=16,rs);
                     }
      				break;
      	case 75:	if(x>cs)
      					{
                     gotoxy(x,rs);
                     printf(" ");
                     gotoxy(x-=12,rs);
                     }
         			else
                  	{
                  	gotoxy(x,rs);
                     printf(" ");
                     gotoxy(x=64,rs);
                     }

      				break;
		   case 13: if(sta[(x-cs)/12]==0) 		//ba zadane enter kart ra bala va payin mibarad(dar arraye sta[state] 0 yani bala 1 yani payin)
         				{
         				sta[(x-cs)/12]=1;
         				for(i=0;i<2;i++)   		//to in for 2 khat balaye kart pak mishe ke biyad payin
            				{
         					gotoxy(11+(x-cs),8+i);
                  		printf("           ");
                  		}
      					card(hand[(x-cs)/12].num,hand[(x-cs)/12].kin,11+(x-cs),10);
         				}
         			else
                  	{
                     sta[(x-cs)/12]=0;
                     card(hand[(x-cs)/12].num,hand[(x-cs)/12].kin,11+(x-cs),8);
         				for(i=0;i<2;i++)  		//to in for 2 khat payin kart pak mishe ke kart biyad bala
            				{
         					gotoxy(11+(x-cs),20+i);
                  		printf("           ");
                  		}
         				}

         			break;
      	default: gotoxy(1,23);
         	  		printf("Use '%c' or '%c' for moving,ENTER for selecting.then press SPACE!",27,26);
      	}
      }
   while(stc!=9);
   }
void giv_hand(shi x)    							//in tabe dast xtayi random mikone va dar deck gharar mide
	{
   shi i=handp,num,kin;
	while(i<x+handp) 									//dar in while 5 kart be soorate random entekhab mishan
		{
      if(sta[i-handp]==0)
      	{
     		con=1;
			num=random(13)+2;
   		kin=random(4)+3;
   		for(j=0;j<i+1;j++)
   			if(deck[j].num==num && deck[j].kin==kin)
      			con=0;
   		if(con)
   			{
	   		deck[i].num=num;
   			deck[i++].kin=kin;
   			}
         }
      else
      	deck[i++]=deck[i-x];
   	}
   handp=i;
   }
int bet(int money)									//intabe meghdareshrat bandiro mishakhas mikone
	{
	gotoxy(1,2);
   shi x=25,stc;
   printf("How much you gonna bet?[ ]   %c[%c]",36,30);
   do
   	{
      gotoxy(x,2);
   	printf("%c",219);
      gotoxy(27,2);
      printf("%3d",money);
      gotoxy(6,1);
      printf("%-d",bank);
      gotoxy(x,2);
		switch(stc=key())
   		{
      	case 77:if(x<26)
         				{
                     gotoxy(x,2);
                     printf("%c",31);
                     gotoxy(x+=7,2);
                     }
      				break;
      	case 75:	if(x>26)
      					{
                     gotoxy(x,2);
                     printf("%c",30);
                     gotoxy(x-=7,2);
                     }
      				break;
		   case 13: if(x==25 && money>5) 		//ba zadane enter mizane shart ziyad ya kam mishavad
         				{money--;bank++;}
         			else if(bank>0 && money<100 && x==32)
                  	{money++;bank--;}
           			break;
      	default: gotoxy(1,23);
         	  		printf("Use '%c' or '%c' for moving,ENTER for selecting.then press SPACE!",27,26);
      	}

      }
   while(stc!=9);
   return money;
   }
/************************************************VOID MAIN***********************************************************/
void main()
{
shi i,j,straight[5],min,scor[5];
int money=20,mult=1;
struct cart first;
while(bank>0 && bank<10000)
	{
   for(i=0;i<52;i++)
   	{deck[i].num=0;deck[i].kin=0;handp=0;}
   for(i=0;i<5;i++)
   	{sta[i]=0;scor[i]=0;}
   clrscr();
	printf("BANK:%-5d%c\n",bank,36);
	for(i=13;i<65;i+=12)  							//to in for 5 poshte kart neshoon dade mishe ke taraf shart bebande
		beh_card(i,10);
	money=bet(money);
	randomize();
	giv_hand(5);                              //dar inja 5 kart random shode dar hand gharar migiran
	for(i=0;i<5;i++)
		hand[i]=deck[i];
	for(i=0;i<5;i++)      							//bad az maloom shodane meghdare shart in for kartaro roo mikone
		{
   	sleep(sec);
		card(hand[i].num,hand[i].kin,11+i*12,8);
   	}
	for(i=15;i<65;i+=12)  							//to in for 5 ta gozine balaye 5 kart shekl migiire
		{
   	gotoxy(i,7);
   	printf("[ ]");
	   }
	car_sel(16,7,5);
	giv_hand(5);                              //to in for kartayi ke select nashode boodan random avaz mishan
	for(i=0;i<5;i++)
		hand[i]=deck[handp-(5-i)];
	for(i=0;i<5;i++)  								//daste jadid zaher mishe
		{
	   sleep(sec);
		card(hand[i].num,hand[i].kin,11+i*12,8);
	  	for(j=0;j<2;j++)  							//to in for 2 khat payin kolle karta pak mishe ke karta biyan bala
			{
			gotoxy(11+i*12,20+j);
   		printf("           ");
      	}
   	}
/****************************az inja marhaleye tasmim giri darmorede emtiaz shoroo mishe**********************************/
	for(i=0;i<5;i++)									//in for donbale 2 dar dast migarde ke emkane royal flusho nabudano baresi kone
		if(hand[i].num==2)
			min=1;
   for(i=0;i<5;i++)								 	//in for be komake if age 2 va ace dar dast peyda kard jaye ase maloom mikone
   	straight[i]=hand[i].num==14 && min==1 ? 1:hand[i].num;	//darinja ba tavjoh be yaftehaye bala bejaye ace 1 ya 14 dar straight gozashte mishe
	for(i=0;i<4;i++)                          //in 2 for be raveshe hobabi areye straghtro az koochik be bozorg moratab mikonan
		for(j=0;j<4;j++)
      	if(straight[j]>straight[j+1])
      		{
         	min=straight[j+1];
         	straight[j+1]=straight[j];
         	straight[j]=min;
         	}
	min=0;
	for(i=0;i<4;i++)									//to in for check mishe ke areye straight ke moratab shode aya arayehash ba ham 1 fasele daran?ya na
		min=straight[i]+1==straight[i+1] ? min+1:min;
	scor[3]=min==4 ? 1:0;
	first=hand[0];
	for(i=0;i<5;i++)									//tayin mikone ke dast range ya na age scor[2]=5 beshe range
		{
   	sta[i]=1;
   	if(hand[i].kin==first.kin)
   		scor[2]++;
   	}
	scor[4]=scor[3]==1 && scor[2]==5 ? 1:0;   //inja dar morede straight flush boodan tasmim giri mishe
   dialog(26,12,27,7);
   gotoxy(27,14);
   textattr(16*col+text+8);
	if(scor[4]==1 && straight[4]==14)			//inja dar morede royal flush boodan tasmim giri mishe
		{cprintf("    WOW!ROYAL FLUSH!    ");mult=25;}
	else if(scor[4])
		{cprintf("SO LUCKY!STRAIGHT FLUSH!");mult=20;}
	else if(scor[3])
		{cprintf("        STRAIGHT        ");mult=8;}
	else if(scor[2]==5)
		{cprintf("      LUCKY!FLUSH!      ");mult=10;}
	else
		{
      con=0;
		for(i=0;i<4;i++)								//darune in for scor[0] va scor[2] meghdar dehi mishan ke az rooshon 2per 3 kare va ful malum mishe
   		if(sta[i]==1)
   			{
   			first.num=straight[i];
				for(j=0;j<5;j++)						//tedade karthaye ham adado mishomore
   				if(straight[j]==first.num)
      				{
                  sta[j]=0;
                  scor[con]++;
                  }
            if(scor[con]<=1)
         		scor[con]=0;
            if(scor[con]!=0)
         		con=!con;
         	}
   	if(scor[0]==4 || scor[1]==4)
   		{cprintf("    FOUR OF A KIND!     ");mult=15;}
   	else if((scor[0]==3 && scor[1]==2)||(scor[0]==2 && scor[1]==3))
   		{cprintf("      FULL HOUSE!       ");mult=12;}
   	else if(scor[0]==3 || scor[1]==3)
   		{cprintf("    THREE OF A KIND     ");mult=6;}
   	else if(scor[0]==2 && scor[1]==2)
   		{cprintf("       TWO PAIRS        ");mult=4;}
   	else if((straight[3]==straight[4] || straight[2]==straight[3])&& straight[3]>10)   //pair budan tu hamin ye khat check mishe
   		{cprintf("     SORRY!JUST PAIR    ");mult=2;}
   	else
   		{cprintf("        BAD LUCK!       ");mult=-1;}
   	}
   gotoxy(27,16);
   if(mult>0)
   	cprintf("     YOU WON:%4d%c!    ",money*mult,36);
   else
      cprintf("    YOU LOST:%4d%c!    ",-1*money*mult,36);
   textattr(1);
	bank=bank+money*mult;
   gotoxy(80,25);
   getch();
   }
}
