#ifndef BANK_SYSTEM_H
#define BANK_SYSTEM_H



struct Node* head = NULL;




/***********************	Generating Numbers Functions	**********************/
unsigned long long int randomnumber(void);			//Randominzing ID For the Client
uint16 randompassword(void);						//Randominzing Bank Password

/*****************************************************************************/


/************************		Creating Node		*********************************/

void append(struct Node** head_ref,uint8 *name,uint8 *address ,float64 money, uint16 age,uint8 *id,uint8 *client_guardian_id);


/*****************************************************************************/

/*************************		Print Nodes Function		******************************/

void printList(struct Node *node);		//mainly for Testing Purposes (Prints All Nodes In The Linked List With All The Data)


void SearchList(struct Node *node);		//Prints All The Data In A Certain Node that can be searched using Bank ID.


/*****************************************************************************************/

/*****************************************		Admin Functions		**********************/

/***********************************************/
void Change_Account_Status(struct Node *node);			//Change Client's Account Status From (Active-Passive-Susspended)
/***********************************************/

/*
Transfer Money From Bank Account To Another Account Both Must be in 
Active Status and the amount of money should be lower 
than first bank's money


					Entry Required	:	Bank ID for both Accounts
										Amount of Cash Transacted
										
*/

/************************************************/
void Make_Transaction(struct Node *node1,struct Node *node2);		
/************************************************/

/*************************		Withdraw Cash From An Account	*********************/
/*				
										Entry Required	:	Bank ID
										Amount of Cash To Withdraw.
					******MUST BE LESS THAN BANK's WHOLE 1st Account CREDIT******
										
*/



void Get_Cash(struct Node *node);
/*******************************************************************************/


/*************************		Deposit Cash to Account	*********************/


/*					Entry Required	:	Bank ID
										Amount of Cash To Deposit

										
*/

void Deposit_Cash(struct Node *node);
/***************************************************************************/

/*****************************************		Client Functions		**********************/




/*
Transfer Money From Bank Account To Another Account Both Must be in 
Active Status and the amount of money should be lower 
than first bank's money
					Entry Required	:	Bank ID for both Accounts
										Bank Passwords for both Accounts
										Amount of Cash Transacted
										******MUST BE LESS THAN BANK's WHOLE 1st Account CREDIT******
										
*/

void Make_Transaction_Client(struct Node *node1,struct Node *node2);


/**********************************************************************/

/*************************		Withdraw Cash From an Account	*********************/

/*
					Entry Required	:	Bank ID
										Password
										Amount of Money Withdrawn From Account
										******MUST BE LESS THAN BANK's WHOLE CREDIT******
										
*/

void Get_Cash_Client(struct Node *node);



/**********************************************************************/



/*************************		Deposit Cash to Account	*********************/

/*
					Entry Required	:	Bank ID
										Password
										Amount of Cash To Deposit
*/

void Deposit_Cash_Client(struct Node *node);


/**********************************************************************/


/*************************		Change Client's Bank Password	*********************/
/*
					Entry Required	:	Bank ID
										Old Password
										New Password
*/

void Change_Password_Client(struct Node *node);


/*************************************************************************/




#endif