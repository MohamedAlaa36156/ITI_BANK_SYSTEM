#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include <time.h>
#include <string.h>
#include <conio.h>
#include "bank_system.h"



void main()
{
	
	unsigned long long int client_bank_id;

	uint8	user_name[30];
	float64	client_balance_data;
	uint16 client_age_data;
	uint8 client_name_data[50];
	uint8 client_address_data[100];
	uint8 id[15];
	uint8 guardian_id[15];
	uint8 Whole_app=1;
	uint16 admin_menu=1;
	uint16 client_menu=1;
	uint16 main_menu;
	uint32 admin_pass;
	uint8 adminpasscount=0;
	while(1)
	{
		
		adminpasscount=0;
		system("cls");

		printf("Welcome to the system\n");
		printf("1) Admin Menu.\n");
		printf("2) Client Menu.\n");
		printf("0) Exit Application.\n");

		scanf("%hu",&main_menu);
		system("cls");

		/***********************MENU SHOULD BE HERE****************/
		if(main_menu==1)
		{
			do{
				
				printf("Enter Username : ");
				scanf(" %[^\n]s",&user_name);
				printf("Enter The Passcode : ");
				scanf("%lu",&admin_pass);
				adminpasscount++;
				if((admin_pass==1234)&&(strcmpi(user_name,"mohamed alaa")==0))
				{
					system("cls");
					break;
				}
				else
				{
					system("cls");
					printf("Wrong Username or Password.\n");
				}
			}while((adminpasscount<3));
			if(admin_pass==1234)
				{
					admin_pass=0;
					main_menu=0;
					/**********Right Password********/
				while(1)
					{
						printf("1) Add Account.\n");
						printf("2) Open Existing Account.\n");
						printf("3) Make A Transaction. \n");
						printf("4) Change Account Status. \n");
						printf("5) Get Cash. \n");
						printf("6) Deposit Account. \n");
						printf("0) Exit.\n");
						scanf("%hu",&admin_menu);
					if(admin_menu==1)
					{
						strcpy(id," ");
						strcpy(guardian_id," ");
						system("cls");
						printf("Add Account.\n");
						printf("Enter the New Client Name : ");
						scanf(" %[^\n]s",&client_name_data);
						do{
						printf("Enter Client's Age (0-100) : ");
						scanf(" %hu",&client_age_data);
						}while(client_age_data>=100);
						if(client_age_data>=21)
						{
							do{
							printf("Enter Your National ID *Constists of 14 Numbers* : ");
							scanf(" %[^\n]s",&id);
							}while(strlen(id)!=14);
						}
						else
						{	
							do{
							printf("Enter The Guardian National ID *Constists of 14 Numbers* : ");
							scanf(" %[^\n]s",&guardian_id);
							}while(strlen(guardian_id)!=14);

						}
						printf("Enter The Client's Address : ");
						scanf(" %[^\n]s",&client_address_data);
						printf("Enter Client's New Balance : ");
						scanf("%lf",&client_balance_data);
						system("cls");
						append(&head,client_name_data,client_address_data,client_balance_data,client_age_data,id,guardian_id);
					}
					else if(admin_menu==2)
						
						{
							//printList(head);					 //prints all the nodes ---> for application testing only.
							SearchList(head);					/*************** Search for Account using bank ID *************/
						}
					else if(admin_menu==3)
					{
						Make_Transaction(head,head);
					}	
					else if(admin_menu==4)
					{
						Change_Account_Status(head);		/************* Change Account Status**************/
					}
					else if(admin_menu==5)
					{
						Get_Cash(head);
					}
					else if(admin_menu==6)
					{
						Deposit_Cash(head);
					}
					else if(admin_menu==0)
					{
						admin_pass=0;
						adminpasscount=0;
						main_menu=0;
						system("cls");

						break;
					}
					else
					{
						system("cls");
						printf("Wrong Entry , Try Again. \n");	
					}
					}
				}
		}
		else if(main_menu==2)
			{
				while(1)
					{	main_menu=0;
						printf("Enter Your Option.\n");
						printf("1) Make Transaction.\n2) Change Password.\n3) Withdraw.\n4) Deposit Cash.\n0) Exit Client Menu.\n");
						scanf("%hu",&client_menu);
							if(client_menu==1)
							{
								Make_Transaction_Client(head,head);		//Client Transactions
							}
							else if(client_menu==2)
							{						
								Change_Password_Client(head);			//Client Change Password
							}
							else if(client_menu==3)
							{	
								Get_Cash_Client(head);					//Client Withdraw Function
							}
							else if(client_menu==4)
							{
								Deposit_Cash_Client(head);				//Client Deposit Function
							}
							else if(client_menu==0)
							{
								main_menu=0;							//Exit Client Menu
								break;
							}
							else
							{
								printf("Wrong Entry Try Again.");
							}
												
					}	
			}
		else if(main_menu==0)
			{
				printf("Have a Nice Day!\n");
				break;
			}
			else
			{
				printf("Wrong Entry. Try agan.\n");
			}
	}
		
		
		
		
}