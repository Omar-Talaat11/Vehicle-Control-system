#include <stdio.h>
#include <string.h>


//functions declarations

int mainlist();//main list to ask the user to turn the engine on or off or quit
void onlist();//list while engine is on
void trafficlight();//change the vehicle speed based on traffic lights
void roomtemp();//change AC based on room temperature
void engtemp();//change Engine Temperature Controller based on engine temperature
void printV();//print vehicle state


//structure
struct Vehicle{

	struct Engine
	{
		char state[20];
		float etemp;
		char engtemcon[10];
		int engtemcontemp;
	}E;
	float rtemp;
	int speed;
	char AC[5];
	int ACtemp;
}V;








int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	//set initial values for vehicle
	strcpy(V.E.state,"OFF");
	V.E.etemp=90;
	strcpy(V.E.engtemcon,"OFF");
	V.E.engtemcontemp=0;
	V.speed=0;
	strcpy(V.AC,"OFF");
	V.rtemp=30;
	V.ACtemp=0;


	int i=1;

	while(i)i=mainlist();//infinite loop to keep the list on until user chooses to Quit
}





int mainlist() //*****REQUIRMENT 1 , 2 , 3 , 4 , 8*****
{
	char c;
	printf("Please Choose:\na. Turn on the vehicle engine\nb. Turn off the vehicle engine\nc. Quit the system\n");
	scanf(" %c",&c);

	switch(c)
	{
	case 'a':
		printf("Vehicle engine is on\n");
		strcpy(V.E.state,"On");
		onlist();
		return 1;
	case 'b':
		printf("Vehicle engine is off\n");
		strcpy(V.E.state,"Off");
		return 1;
	case 'c':
		printf("System quit");
		return 0;
	default:
		printf("Wrong entry, Please try again\n");
		return 1;
	}
}



void onlist()//*****REQUIRMENT 5 , 6*****
{
	char d;
	while(1)
	{
		printV();

		printf("Please Choose:\na. Turn off the engine\n"
				"b. Set the traffic light color\n"
				"c. Set the room temperature (Temperature Sensor)\n"
				"d. Set the engine temperature (Engine Temperature Sensor)\n");

		scanf(" %c",&d);

		switch(d)
		{
		case 'a':
			printf("Vehicle engine is off\n");
			strcpy(V.E.state,"Off");
			return;
		case 'b':
			trafficlight();
			break;
		case 'c':
			roomtemp();
			break;
		case 'd':
			engtemp(&(V.E.engtemcontemp),V.E.engtemcon,&(V.E.etemp));
			break;
		default:
			printf("Wrong entry, Please try again\n");
			break;
		}
	}
}



void trafficlight()//*****REQUIRMENT 7.a*****
{
	char t;
	printf("Please enter traffic light (G or O or R)\n");
	scanf(" %c",&t);

	switch(t)
	{
	case 'G':
		V.speed=100;
		break;
	case 'O':
		V.speed=30;//*****REQUIRMENT 7.d*****
		strcpy(V.AC,"ON");
		V.rtemp=((float)5/4*V.rtemp+1);
		strcpy(V.E.engtemcon,"ON");
		V.E.etemp=((float)5/4*V.E.etemp+1);
		break;
	case 'R':
		V.speed=0;
		break;
	default:
		printf("Wrong entry, Please try again\n");
		trafficlight();
	}
}



void roomtemp()//*****REQUIRMENT 7.b*****
{
	printf("Please enter room temperature\n");
	scanf(" %f",&V.rtemp);

	if(V.rtemp<10||V.rtemp>30)
	{
		strcpy(V.AC,"ON");
		V.ACtemp=20;
	}
	else
	{
		strcpy(V.AC,"OFF");
		V.ACtemp=0;
	}
}



void engtemp(int *engsettemp,char*engsetcon,float*engtemp)//*****REQUIRMENT 7.c*****
{
	int etemp;
	printf("Please enter engine temperature\n");
	scanf(" %d",&etemp);
	printf(" %d",etemp);
	*engtemp=(float)etemp;
	//V.E.etemp=etemp;
	if(etemp<100||etemp>150)
	{
		strcpy((engsetcon),"ON");
		//strcpy(V.E.engtemcon,"ON");
		*engsettemp=125;
		//V.E.engtemcontemp=125;
	}
	else
	{
		strcpy((engsetcon),"OFF");
		//strcpy(V.E.engtemcon,"OFF");
		*engsettemp=0;
		//V.E.engtemcontemp=0;
	}
}



void printV()//*****REQUIRMENT 7.e*****
{
	printf("\n**************\nThe Vehicle state is as follows:\n");
	printf("Speed: %d\nRoom Temperature: %.2f\nAC: %s\nAC Temperature: %d\n",V.speed,V.rtemp,V.AC,V.ACtemp);
	printf("\nEngine:\n\tState: %s\n\tEngine Temperature: %.2f\n"
			"\tEngine Temperature Controller: %s\n"
			"\tEngine Temperature Controller Temperature: %d\n**************\n"
			,V.E.state,V.E.etemp,V.E.engtemcon,V.E.engtemcontemp);
}












