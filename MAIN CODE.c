#include<pic.h>
#define buzzer RC2
#define led RA2
#define LCD PORTB
#define RS RD6
#define EN RD7
#define flame RA1
#define gass RA0
#define led1 RA3
void str(char *);
void transmitter();
void transmitter1();
void transmitter2();
void delay(unsigned int);	
void BUZZER();
void LED();
void LED1();
void cmd();
void data();
void lcd_clear();

__CONFIG (0X20F1);






char a[]="    WELCOME    ";
char b[]="FIRE & GAS PRE-";
char c[]="VENTION PROJECT";
char e[]="  GAS DETECTED ";
char d[]="    BY HARSH   ";
char f[]=" FIRE DETECTED ";
char g[]="NO FIRE NO GAS "; 
      
char msg_sent[]="MESSAGE SEND";
void main()

{   
ANSELH=0X00;
TRISB=TRISD=0X00;
PORTC=PORTB=0X00;

ANSEL=0X00;
TRISA=0X03;
RA0=RA1=0;

TRISC=0X80;
TXSTA=0X24;
RCSTA=0X90;
SPBRG=25;

RA2=RA3=0;



	LCD=0X38;
	cmd();
    LCD=0X0C;
    cmd();
	LCD=0X01;
	cmd();
	LCD=0X80;
	cmd();
 


for(int i=0;a[i]!='\0';i++)
{
LCD=a[i];
data();	

}


delay(10000);
delay(60000);
delay(10000);
delay(60000);




LCD=0X01;
cmd();
LCD=0X80;
cmd();
for(int i=0;b[i]!='\0';i++)
{
LCD=b[i];
data();
}





LCD=0XC0;
cmd();
for(int i=0;c[i]!='\0';i++)
{
LCD=c[i];
data();	
}

delay(10000);
delay(60000);
delay(10000);
delay(60000);



LCD=0X01;
cmd();
LCD=0X80;
cmd();
for(int i=0;d[i]\!='\0';i++)
{
LCD=d[i];
data();	
}


delay(10000);
delay(60000);
delay(10000);
delay(60000);



LCD=0X01;
cmd();


		
while(1)
	{  



       if(flame==0&&gass==0)
       {
       LCD=0x80;
       cmd();
	   for(int i=0;f[i]\!='\0';i++)
       {
       LCD=f[i];
       data();	
       }
       

       LCD=0xc0;
       cmd();
	   for(int i=0;e[i]\!='\0';i++)
       {
       LCD=e[i];
       data();	
       }
       transmitter2();
      
       }
       




       
      else if(gass==0&&flame==1)
       {
       LCD=0x80;
       cmd();
	   for(int i=0;e[i]\!='\0';i++)
       {
       LCD=e[i];
       data();	
       }
       LCD=0xC0;
       cmd();
       lcd_clear();
       transmitter();
       }

        





      
      else if(flame==0&&gass==1)
       {
       LCD=0x80;
       cmd();
	   for(int i=0;f[i]\!='\0';i++)
       {
       LCD=f[i];
       data();	
       }
       LCD=0xC0;
       cmd();
       lcd_clear();
       transmitter1();
       }




       else
       {
       LCD=0x80;
       cmd();
	   for(int i=0;g[i]\!='\0';i++)
       {
       LCD=g[i];
       data();	
       }
       LCD=0xC0;
       cmd();
       lcd_clear();
       RA2=RA3=0;
       }
            
 }
}
 
void cmd()
{
	RS=0;
	EN=1;
	delay(50);
	EN=0;
	delay(100);
	}
void data()
{
	RS=1;
	EN=1;
	delay(50);
	EN=0;
	delay(100);
	}


void transmitter()
{
   
    buzzer=1;
    led=1;
    
	delay(20000);           //adding extra delay
	str("AT");
	TXIF=0;
	TXREG=13;
	while(TXIF==0);
	RCIF=0;
	
	
	
	delay(20000);
	
	
  		LCD=0XC0;
    cmd();
   
	str("AT+CMGF=1");
	TXIF=0;
	TXREG=13;
	while(TXIF==0);
	RCIF=0;
	while(RCIF==0);
	
    	delay(20000);
    
    	
   
    
	
	
	LCD=0XC1;
   cmd();
   
	
	str("AT+CMGS=");
	TXIF=0;
	TXREG=34;
	while(TXIF==0);
	str("9711897155");
	TXIF=0;
	TXREG=34;
	while(TXIF==0);
	TXIF=0;
    delay(1000);
	TXREG=13;
	while(TXIF==0);
	RCIF=0;
	while(RCIF==0);
	
	

   	
	
	str("  PLEASE ALERT GAS DETECTED");
	TXIF=0;
	TXREG=26;
	while(TXIF==0);
	RCIF=0;
	while(RCIF==0);



	LCD=0XC0;
	cmd();
	for(int i=0;msg_sent[i]!='\0';i++)
	{
	LCD=msg_sent[i];
	data();	
	}

    delay(60000);
    buzzer=0;
    led=0;
    
    

    delay(60000);
    LCD=0XC0;
    cmd();
    lcd_clear();

 }




void transmitter1()
{

    led1=1;
    buzzer=1;
	delay(20000);           //adding extra delay
	str("AT");
	TXIF=0;
	TXREG=13;
	while(TXIF==0);
	RCIF=0;
	
	
	
	delay(20000);
	
	
  		LCD=0XC0;
    cmd();
   
	str("AT+CMGF=1");
	TXIF=0;
	TXREG=13;
	while(TXIF==0);
	RCIF=0;
	while(RCIF==0);
	
    
    
    
   	delay(20000);
   
	LCD=0XC1;
   cmd();
   
	
	str("AT+CMGS=");
	TXIF=0;
	TXREG=34;
	while(TXIF==0);
	str("9711897155");
	TXIF=0;
	TXREG=34;
	while(TXIF==0);
	TXIF=0;
    delay(1000);
	TXREG=13;
	while(TXIF==0);
	RCIF=0;
	while(RCIF==0);
	
	

   	
	
	str("  PLEASE ALERT FIRE DETECTED");
	TXIF=0;
	TXREG=26;
	while(TXIF==0);
	RCIF=0;
	while(RCIF==0);

    LCD=0XC0;
	cmd();
	for(int i=0;msg_sent[i]!='\0';i++)
	{
	LCD=msg_sent[i];
	data();	
	}

    delay(60000);
    buzzer=0;
    led1=0;


    delay(60000);
    LCD=0XC0;
    cmd();
    lcd_clear();
    
 }



void transmitter2()
{
    led=1;
    led1=1;
     buzzer=1;

	delay(20000);           //adding extra delay
	str("AT");
	TXIF=0;
	TXREG=13;
	while(TXIF==0);
	RCIF=0;
	
	
	
	delay(20000);
	
	
  		LCD=0XC0;
    cmd();
   
	str("AT+CMGF=1");
	TXIF=0;
	TXREG=13;
	while(TXIF==0);
	RCIF=0;
	while(RCIF==0);
	
    	delay(20000);
	LCD=0XC1;
   cmd();
   
	
	str("AT+CMGS=");
	TXIF=0;
	TXREG=34;
	while(TXIF==0);
	str("9711897155");
	TXIF=0;
	TXREG=34;
	while(TXIF==0);
	TXIF=0;
    delay(1000);
	TXREG=13;
	while(TXIF==0);
	RCIF=0;
	while(RCIF==0);
	
	

   	
	
	str("  PLEASE ALERT  FIRE & GAS DETECTED");
	TXIF=0;
	TXREG=26;
	while(TXIF==0);
	RCIF=0;
	while(RCIF==0);

	LCD=0XC0;
	cmd();
	for(int i=0;msg_sent[i]!='\0';i++)
	{
	LCD=msg_sent[i];
	data();	
	}

    delay(60000);
    buzzer=0;
    led1=0;
    led=0;



    delay(60000);
    LCD=0XC0;
    cmd();
    lcd_clear();



 }





void lcd_clear()
{
for(int i=0;i<16;i++)
    {
    LCD=' ';
    data();
    }

}


void str(char *s)
{
 while(*s!='\0')
{ 
 TXIF=0;
 TXREG=*s;
 while(TXIF==0);
 s++;
 delay(2000);
 delay(2000);
}
}
void delay(unsigned int x)
	{
		while(x>0)
		x--;
		}
void BUZZER()
{
buzzer=1;
delay(60000);
buzzer=0;

}
void LED()
{
led=1;
delay(60000);
led=0;

}
void LED1()
{
led1=1;
delay(60000);
led1=0;

}