/*

						ITI_C_Graduation_Project
						
						ADMIN:-
						USERNAME	:	mohamed alaa
						Password	:	1234
			DONT FORGET CLIENT's BANK ID AND PASSWORD.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD_TYPES.h"
#include <time.h>
#define ACTIVE		1
#define RESTRICTED	2
#define CLOSED		3
struct Node {
	
	uint16 account_status;					//1)Active	2)Restricted	3)Closed
	uint8 client_name[50];
	uint8 client_address[100];
	uint16 client_age;						
	float64 client_balance;
	uint8 	client_National_ID[15];
	uint8 	client_Guardian_ID[15];
	unsigned long long int client_bank_id;
	uint16 client_password;					//Password Will be Generated
  
	struct Node *next;						
};

/*******************************************		Randomizing Functions		******************************/
unsigned long long int randomnumber(void)
{
	unsigned long long int lower = 1000000000, upper = 9999999999;
    srand(time(0));

   
        unsigned long long int num = (rand() % (upper - lower + 1)) + lower;
   	
	return num;

}
uint16 randompassword(void)
{
	uint16 lower = 1000, upper = 9999;
    srand(time(0));

   
        uint16 num = (rand() % (upper - lower + 1)) + lower;
   	
	return num;

}
/*************************************************************************************************************/


/*************************************************		Create Linked List Node		****************************************/
/* Given a reference (pointer to pointer) to the head
of a list and an int, appends a new node at the end */
void append(struct Node** head_ref,uint8 *name,uint8 *address ,float64 money, uint16 age,uint8 *id,uint8 *client_guardian_id)
{
	/* 1. allocate node */
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	struct Node *last = *head_ref; /* used in step 5*/
	/* 2. put in the data */	/*Entering String Data First*/
	strcpy(new_node->client_name,name);
	strcpy(new_node->client_address,address);
	strcpy(new_node->client_National_ID,id);
	strcpy(new_node->client_Guardian_ID,client_guardian_id);

	new_node->account_status=ACTIVE;			// Assigning Account Status to 1-> Active;
	new_node->client_age = age;					//Client's Age
	new_node->client_balance =money;			//Client's Balance.
	new_node->client_bank_id=randomnumber();	//randomized BANK ID
	new_node->client_password=randompassword();	//randomized Password
	
	printf("bank ID 	: %llu\n",new_node->client_bank_id);
	printf("bank Password 	: %hu\n\n\n\n",new_node->client_password);
	/* 3. This new node is going to be the last node, so make next
		of it as NULL*/
	new_node->next = NULL;

	/* 4. If the Linked List is empty, then make the new node as head */
	if (*head_ref == NULL)
	{
	*head_ref = new_node;
	return;
	}
	
	/* 5. Else traverse till the last node */
	while (last->next != NULL)
		last = last->next;

	/* 6. Change the next of last node */
	last->next = new_node;
	
	return;
}

/*********************************		For Testing Purpose Prints All Created Nodes	**********************/
void printList(struct Node *node)
{

  while (node != NULL)
  {
		if(node->account_status==ACTIVE)
			printf("Account Status : Active\n");
		else
			printf("Account Status : Suspended\n");
	printf(" Client's Name :  %s \n", node->client_name);
	printf(" Client's Address :  %s \n", node->client_address);
	printf(" Client's National ID :  %s \n", node->client_National_ID);
	printf(" Client's Guardian ID :  %s \n", node->client_Guardian_ID);
	printf(" Client's Bank ID :  %lu \n", node->client_bank_id);
	printf(" Client's Password :  %hu \n", node->client_password);
	printf(" Client's Age :  %hu \n", node->client_age);
	printf(" Client's Current Balance :  %.1lf \n", node->client_balance);
    node = node->next;
  }
}
/*************************************************************************************************************/



/***************************		Search For a Certain Node and Prints All its Content		*******************/
void SearchList(struct Node *node)
{
	unsigned long long int bank_id_search;
	printf("Enter The Bank ID : ");
	scanf("%llu",&bank_id_search);

	while ((node != NULL)&&(bank_id_search!=node->client_bank_id))
	{
		node = node->next;
	}
	if((node != NULL)&&(bank_id_search==node->client_bank_id))
	{
		if(node->account_status==ACTIVE)
		{
			printf("Account Status : Active\n");
		}
		else if(node->account_status==RESTRICTED)
		{
			printf("Account Status : Suspended\n");
		}
		else if(node->account_status==CLOSED)
		{
			printf("Account Status : Closed\n");
		}
	printf(" Client's Name				:  %s \n", node->client_name);
	printf(" Client's Address			:  %s \n", node->client_address);
	printf(" Client's National ID			:  %s \n", node->client_National_ID);
	printf(" Client's Guardian ID			:  %s \n", node->client_Guardian_ID);
	printf(" Client's Bank ID			:  %lu \n", node->client_bank_id);
	printf(" Client's Password			:  %hu \n", node->client_password);
	printf(" Client's Age				:  %hu \n", node->client_age);
	printf(" Client's Current Balance		:  %lf \n", node->client_balance);
	}
	else
	{
		printf("Wrong Bank ID.\n");
	}
}


/*************************************************************************************************************/



/***************************		Change Account Status		*******************/


void Change_Account_Status(struct Node *node)
{
	unsigned long long int bank_id_search;
	printf("Enter The Bank ID : ");
	scanf("%llu",&bank_id_search);
	uint8 new_status;
	while ((node != NULL)&&(bank_id_search!=node->client_bank_id))
	{
		node = node->next;
	}
	if((node != NULL)&&(bank_id_search==node->client_bank_id))
	{
		if(node->account_status==ACTIVE)
		{
			printf("Account Status : Active\n");
		}
		else if(node->account_status==RESTRICTED)
		{
			printf("Account Status : Suspended\n");
		}
		else if(node->account_status==CLOSED)
		{
			printf("Account Status : Closed\n");
		}
	do{
	printf("1) Activate the Account \n2) Suspend the account \n3)Delete Account \n");
	scanf("%d", &new_status);
	}while((new_status==ACTIVE)||(new_status==2)||(new_status==3));
	node->account_status=new_status;
	}
	else
	{
		printf("Wrong Bank ID.\n");
	}
	
	
	
	
}


/*************************************************************************************************************/



/***************************	Admin	:	Money Transfer		**********************************************/
void Make_Transaction(struct Node *node1,struct Node *node2)
{
	unsigned long long int bank_id_search;
	printf("Enter The Bank ID You Are Sending Money From  : ");
	scanf("%llu",&bank_id_search);
	float64 Money_Transacted;
	printf("Enter The Amount of Money You Are Sending : ");
	scanf("%lf",&Money_Transacted);
	while ((node1 != NULL)&&(bank_id_search!=node1->client_bank_id))
	{
		node1 = node1->next;
	}
	if((node1 != NULL)&&(bank_id_search==node1->client_bank_id))
	{
		if(node1->account_status==ACTIVE)
		{
			printf("Account Status : Active\n");
			printf("First Client's Current Balance :  %lf \n", node1->client_balance);
		}
		else if(node1->account_status==RESTRICTED)
		{
			printf("Account Status : Suspended\n");
		}
		else if(node1->account_status==CLOSED)
		{
			printf("Account Status : Closed\n");
		}
	}
	else
	{
		printf("First Account Wrong Bank ID.\n");
	}
	
		printf("Enter The Bank ID You Are Sending To  : ");
		scanf("%llu",&bank_id_search);
	
	while ((node2 != NULL)&&(bank_id_search!=node2->client_bank_id))
	{
		node2 = node2->next;
	}
	if((node2 != NULL)&&(bank_id_search==node2->client_bank_id))
	{
		if(node2->account_status==ACTIVE)
		{
			printf("Account Status : Active\n");
			printf("Second Client's Current Balance :  %lf \n", node2->client_balance);
		}
		else if(node2->account_status==RESTRICTED)
		{
			printf("Account Status : Suspended\n");
		}
		else if(node2->account_status==CLOSED)
		{
			printf("Account Status : Closed\n");
		}
	}
	else
	{
		printf("Second Account Wrong Bank ID.\n");
	}
	
	if((node1->account_status==ACTIVE)&&(node2->account_status==ACTIVE))
	{
		if((node1->client_balance)<Money_Transacted)
		{
			printf("Transaction Failed ... Not Enough Money on First Account.\n");
		}
		else
		{
			
			node1->client_balance-=Money_Transacted;
			node2->client_balance+=Money_Transacted;
			printf("First Client's New Balance :  %lf \n", node1->client_balance);
			printf("Second Client's New Balance :  %lf \n", node2->client_balance);
		}
		
		
		
	}
	else
	{
		if(node1->account_status!=ACTIVE)
		{
			printf("First Account is Either Suspended or Closed. \n");
		}
		else if(node2-> account_status!=ACTIVE)
		{
			printf("Secound Account is Either Suspended or Closed. \n");
		}
		else{
			printf("ERROR!!\n");
		}
	}
	
}
/*************************************************************************************************************/


/***************************	Admin	:	Money Withdraw		**********************************************/
void Get_Cash(struct Node *node)
{
	unsigned long long int bank_id_search;
	printf("Enter The Bank ID : ");
	scanf("%llu",&bank_id_search);
	float64 Withdraw;
	printf("Enter The Amount of Money you Want to Withdraw.");
	scanf("%lf",&Withdraw);
	while ((node != NULL)&&(bank_id_search!=node->client_bank_id))
	{
		node = node->next;
	}
	if((node != NULL)&&(bank_id_search==node->client_bank_id))
	{
		if(node->account_status==ACTIVE)
			
			{
				printf("Account Status : Active\n");
			if((node->client_balance)<Withdraw)
			{
				printf("Sorry Not Enough Credit.\n");
			}
			else
			{
				printf(" Client's Old Balance :  %lf \n", node->client_balance);
				node->client_balance-=Withdraw;
				printf(" Client's New Balance :  %lf \n", node->client_balance);
			}
			}
		else if(node->account_status==RESTRICTED)
		{
			printf("Account Status : Suspended\n");
		}
		else if(node->account_status==CLOSED)
		{
			printf("Account Status : Closed\n");
		}
	}
	else
	{
		printf("Wrong Bank ID.\n");
	}
}

/*************************************************************************************************************/

/***************************	Admin	:	Money Withdraw		**********************************************/
void Deposit_Cash(struct Node *node)
{
	unsigned long long int bank_id_search;
	printf("Enter The Bank ID : ");
	scanf("%llu",&bank_id_search);
	float64 Deposit;
	printf("Enter The Amount of Money you Want to Deposit.");
	scanf("%lf",&Deposit);
	while ((node != NULL)&&(bank_id_search!=node->client_bank_id))
	{
		node = node->next;
	}
	if((node != NULL)&&(bank_id_search==node->client_bank_id))
	{
		if(node->account_status==ACTIVE)
		{
			printf("Account Status : Active\n");
			printf(" Client's Old Balance :  %lf \n", node->client_balance);
			node->client_balance+=Deposit;
			printf(" Client's New Balance :  %lf \n", node->client_balance);
		}
		else if(node->account_status==RESTRICTED)
		{
			printf("Account Status : Suspended\n");
		}
		else if(node->account_status==CLOSED)
		{
			printf("Account Status : Closed\n");
		}
		

	}
	else
	{
		printf("Wrong Bank ID.\n");
	}
}
/*************************************************************************************************************/	


/***************************	Client	:	Money Transfer		**********************************************/


void Make_Transaction_Client(struct Node *node1,struct Node *node2)
{
	unsigned long long int bank_id_search;
	printf("Enter The Bank ID You Are Transacting Money From  : ");
	scanf("%llu",&bank_id_search);
	uint16 bank_pass_search;
	printf("Enter Your Password : ");
	scanf("%hu",&bank_pass_search);
	float64 Money_Transacted;
	printf("Enter The Amount of Money You Are Transacting : ");
	scanf("%lf",&Money_Transacted);
	while ((node1 != NULL)&&(bank_id_search!=node1->client_bank_id)&&(bank_pass_search!=node1->client_password))
	{
		node1 = node1->next;
	}
	if((node1 != NULL)&&(bank_id_search==node1->client_bank_id)&&(bank_pass_search==node1->client_password))
	{
		if(node1->account_status==ACTIVE)
		{
			printf("Account Status : Active\n");
			printf("First Client's Current Balance :  %lf \n", node1->client_balance);
		}
		else if(node1->account_status==RESTRICTED)
		{
			printf("Account Status : Suspended\n");
		}
		else if(node1->account_status==CLOSED)
		{
			printf("Account Status : Closed\n");
		}
		
	}
	else
	{
		printf("First Account Wrong Bank ID.\n");
		return;
	}
	
		printf("Enter The Bank ID You Are Sending To  : ");
		scanf("%llu",&bank_id_search);
		printf("Enter Your Password : ");
		scanf("%hu",&bank_pass_search);
	
	while ((node2 != NULL)&&(bank_id_search!=node2->client_bank_id)&&(bank_pass_search!=node2->client_password))
	{
		node2 = node2->next;
	}
	if((node2 != NULL)&&(bank_id_search==node2->client_bank_id)&&(bank_pass_search==node2->client_password))
	{
		if(node2->account_status==ACTIVE)
		{
			printf("Account Status : Active\n");
			printf("Second Client's Current Balance :  %lf \n", node2->client_balance);
		}
		else if(node2->account_status==RESTRICTED)
		{
			printf("Account Status : Suspended\n");
		}
		else if(node2->account_status==CLOSED)
		{
			printf("Account Status : Closed\n");
		}
		
	}
	else
	{
		printf("Second Account Wrong Bank ID.\n");
		return ;
	}
	
	if((node1->account_status==ACTIVE)&&(node2->account_status==ACTIVE))
	{
		if((node1->client_balance)<Money_Transacted)
		{
			printf("Transaction Failed ... Not Enough Money on First Account.\n");
		}
		else
		{
			printf("First Client's Old Balance :  %lf \n", node1->client_balance);
			printf("Second Client's Old Balance :  %lf \n", node2->client_balance);
			node1->client_balance-=Money_Transacted;
			node2->client_balance+=Money_Transacted;
			printf("First Client's New Balance :  %lf \n", node1->client_balance);
			printf("Second Client's New Balance :  %lf \n", node2->client_balance);
		}
	}
	else
	{
		if(node1->account_status!=1)
		{
			printf("First Account is Either Suspended or Closed. \n");
		}
		else if(node2-> account_status!=1)
		{
			printf("Secound Account is Either Suspended Closed. \n");
		}
		else{
			printf("ERROR!!\n");
		}
	}
	
}
/*************************************************************************************************************/	

/***************************	Client	:	Money Withdraw		**********************************************/
	
void Get_Cash_Client(struct Node *node)
{
	unsigned long long int bank_id_search;
	printf("Enter The Bank ID : ");
	scanf("%llu",&bank_id_search);
	uint16 bank_pass_search;
	printf("Enter Your Password : ");
	scanf("%hu",&bank_pass_search);
	float64 Withdraw;
	printf("Enter The Amount of Money you Want to Withdraw.");
	scanf("%lf",&Withdraw);
	while ((node != NULL)&&(bank_id_search!=node->client_bank_id)&&(bank_pass_search!=node->client_password))
	{
		node = node->next;
	}
	if((node != NULL)&&(bank_id_search==node->client_bank_id)&&(bank_pass_search==node->client_password))
	{
		if(node->account_status==ACTIVE)
		{
			printf("Account Status : Active\n");
			if((node->client_balance)<Withdraw)
			{
			printf("Sorry Not Enough Credit.\n");
			}
			else
			{
			printf(" Client's Old Balance :  %lf \n", node->client_balance);
			node->client_balance-=Withdraw;
			printf(" Client's New Balance :  %lf \n", node->client_balance);
			}
		}
		else if(node->account_status==RESTRICTED)
		{
			printf("Account Status : Suspended\n");
		}
		else if(node->account_status==CLOSED)
		{
			printf("Account Status : Closed\n");
		}
		
	}
	else
	{
		printf("Wrong Bank ID.\n");
	}
}	
/*************************************************************************************************************/






/***************************	Client	:	Deposit Withdraw		**********************************************/




void Deposit_Cash_Client(struct Node *node)
{
	unsigned long long int bank_id_search;
	printf("Enter Your Bank ID : ");
	scanf("%llu",&bank_id_search);
	uint16 bank_pass_search;
	printf("Enter Your Password : ");
	scanf("%hu",&bank_pass_search);
	float64 Deposit;
	printf("Enter The Amount of Money you Want to Deposit.");
	scanf("%lf",&Deposit);
	while ((node != NULL)&&(bank_id_search!=node->client_bank_id)&&(bank_pass_search!=node->client_password))
	{
		node = node->next;
	}
	if((node != NULL)&&(bank_id_search==node->client_bank_id)&&(bank_pass_search==node->client_password))
	{
		if(node->account_status==ACTIVE)
		{
			printf("Account Status : Active\n");
			printf(" Client's Old Balance :  %lf \n", node->client_balance);
			node->client_balance+=Deposit;
			printf(" Client's Current Balance :  %lf \n", node->client_balance);
		}
		else if(node->account_status==RESTRICTED)
		{
			printf("Account Status : Suspended\n");
		}
		else if(node->account_status==CLOSED)
		{
			printf("Account Status : Closed\n");
		}
		

	}
	else
	{
		printf("Wrong Bank ID OR Password .\n");
	}
}



/*************************************************************************************************************/



/***************************	Client	:	Change Password	**********************************************/


void Change_Password_Client(struct Node *node)
{
	unsigned long long int bank_id_search;
	printf("Enter Your Bank ID : ");
	scanf("%llu",&bank_id_search);
	uint16 bank_pass_search;
	printf("Enter Your Password : ");
	scanf("%hu",&bank_pass_search);
	uint16 new_pass;
	while ((node != NULL)&&(bank_id_search!=node->client_bank_id)&&(bank_pass_search!=node->client_password))
	{
		node = node->next;
	}
	if((node != NULL)&&(bank_id_search==node->client_bank_id)&&(bank_pass_search==node->client_password))
	{
		if(node->account_status==ACTIVE)
		{	
			printf(" Client's Name :  %s \n", node->client_name);
			printf("Enter Your New PassWord : \n");
			scanf("%hu",&new_pass);
			node->client_password=new_pass;
			printf("Password has been changed Successfully!\n");
		}
		else if(node->account_status==RESTRICTED)
		{
			printf("Account Status : Suspended\n");
		}
		else if(node->account_status==CLOSED)
		{
			printf("Account Status : Closed\n");
		}
	}
	
	else
	{
		printf("Wrong Bank ID OR Password .\n");
	}
}


/*************************************************************************************************************/
