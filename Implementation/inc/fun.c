/**
 * @file fun.h
 * @author Ruthwika (ruthwika.vos@gmail.com)
 * @brief brief description
 */
**
 * 
 */
struct date{
	   int month;
	   int day;
	   int year;
	   };
*@brief variables to store time of customer

  struct account {
	int number;
	char name[100];
	int acct_no;
	float mobile_no;
	char street[100];
	char city[100];
	char acct_type;
	float oldbalance;
	float newbalance;
	float payment;
	struct date lastpayment;
  }customer;
  int tl,sl,ts;
*@brief variables to store customer details


void input();

/**
 * @brief function to take the inputs of customer
 * 
 */
void writefile();
/**
 * @brief function to write in values of new customer
 * 
 */

void search();
/**
 * @brief  function to search for old customer record
 * 
 */
 
void output();
/**
 *
 *@brief function to print output for entered inputs
