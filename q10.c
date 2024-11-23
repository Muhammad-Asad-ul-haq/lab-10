#include<stdio.h>
struct travelpackages{
	char package_name[20];
	char destination[20];
	int duration;
	float cost;
	int no_ofseats;
};

// function to display packages
void display_packages(struct travelpackages packages[])
    	{
    		int i;
			for(i=0;i<5;i++)
			{
				printf("\n%d:\n",i+1);
				printf("%s\n",packages[i].package_name);
				printf("%s\n",packages[i].destination);
				printf("%d days\n",packages[i].duration);
				printf("Rs.%.2f\n",packages[i].cost);
				printf("%d seats available\n",packages[i].no_ofseats);
			}
     	}
     	
//function to book a package   	
void book_a_package(struct travelpackages packages[])
{
	int ch,n;
	printf("Enter no of package you want to book: ");
	scanf("%d",&ch);
	if(ch<1 || ch>5)
	{
		printf("Invalid choice");
		return;
	}
	printf("Enter no of seats you want to book: ");
	scanf("%d",&n);
	if(packages[ch-1].no_ofseats<n)
	{
		printf("Not enough seats, only %d seats available for this package",packages[ch-1].no_ofseats);
	}
	else
	{
		packages[ch-1].no_ofseats-=n;
		printf("Booking successful! %d seats booked for %s",n,packages[ch-1].package_name);
	}
}

int main()
{
	int choice;
	struct travelpackages tpackage[5]={
        {"LangKawi Island", "Malaysia", 10, 135900.0, 24},
        {"Sentosa", "Singapore", 8, 250000.0, 25},
        {"Colombo", "Sri lanka", 12, 125900.0, 38},
        {"Niagra falls", "Canada", 9, 298000.0, 12},
        {"NathiaGali", "Pakistan", 21, 80000.0, 3}
    };
    
	printf("Enter 1 to see all packages\nEnter 2 to book a package\nEnter your Choice: ");
	scanf("%d",&choice);
	switch (choice)
	{
		case 1:
			display_packages(tpackage);
			break;
		case 2:
			book_a_package(tpackage);
			break;
	}	
			
	}