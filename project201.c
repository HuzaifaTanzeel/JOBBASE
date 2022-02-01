#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<windows.h>


struct employee {
	char name[20];
	char CNIC[50];
	char email[25];
	int experience;
	int qualifications;     
	int age;
}e_data;
struct company {
	char c_name[30];
	int c_id;
	char contact[20];
	int hiring;
	int min_age;
	int min_exp;
	int pay;
	int apply;
	
}c_data;

void e_list();
void e_login();
void e_search(int c_hire, int c_min_age, int c_min_exp );
void c_search(int e_qual, int e_age, int e_exp); 
void qualification_print(int qual);
void loadingBar(void);
void loginload(void);
void logoutload(void);
void c_login();
void empsearch();
void c_prob(int c_id, int e_exp); //  might  not work so remove. called in  elogin

void menuu(){
	
	//struct employee e_data;
	//struct company c_data;
	FILE *ep;
	FILE *cp;
	int type, e_entry, c_entry, y, goback, a, eback, goback2;
	//int e_CNIC_search;
	char *ptr;
	ptr=(char*)malloc(50*sizeof(char));
	
	start:
	printf("  \t\t\t\t\t\t\t\t\t ----------------------  \n	");
	printf(" \t\t\t\t\t\t\t\t|    J O B  B A S E    | \n");
	printf("  \t\t\t\t\t\t\t\t\t ----------------------	\n");
	printf("  \t\t\t\t\t\t\t\t\t Making your ends meet! \n");
	system("pause");
	system("cls");
	// NEW SCREEN AFTER SOME TIME
	p2:
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tWho are you?\n");
	printf("\t\t\t\t\t\t\t\t\t-----------------------------\n\n");
	printf("\t\t\t\t\t\t  1. I am an Employee \t\t\t\t 2. I am an Employer?\n\n \t\t\t\t\t\t\t\t\t\t\t");
	//printf("Type 1 for employee & 2 for employer");
	scanf("%d", &type);
	system("cls");
	
	
	if( type == 1) //employee
	{
		
		e_enter:
			printf("\n\n\t\t\t\t\t\t\t\t\t\tI wish to \n\n ");
		printf("\n\t\t 1. Register as an Employee \t 2. log-in as an Employee \t 3.Edit Details of existing account \t 4.Delete Account \t 5.Go back instead \n\n\n\n\t\t\t\t\t\t\t\t\t\t");
		scanf("%d", &e_entry); // employee entry
		system("cls");
		
		if( e_entry == 1) // employee register
		{
			// ask for details to make an account
			int p3;
			printf("\n\n\t\t\t\t\t\t\t\t This is Employee Registration Page \n ");
			emp_reg_page:
			printf("\n\n\t\t\t\t\t 1. Register yourself as an Employee \t\t\t   0. Go back instead \n\n\n\t\t\t\t\t\t\t\t\t\t");
			scanf("%d",&p3);
			if(p3 == 0) //previous page
			{
				system("cls");
				goto e_enter;
			}
			else if(p3 == 1) //employee register
			{
			
				system("cls");
				ep = fopen("employee.txt","a+");
				if(ep == NULL)
		    	{
		    		printf("File Not Found");
		    		exit(1);
				}
				
		
				printf("\n\n\n \t\t\t\t\t WELCOME!! Please fill the following form to Register yourself into JobBase");
		
				printf("\n\n\n \t\t\t\t\t\t\tEnter your Name:");
				scanf("%s",&e_data.name);
				fflush(stdin);
				
                fflush(stdin);
				
				printf("\n\n \t\t\t\t\t\t\tEnter 13-digit CNIC Code: ");
				scanf("%s",&e_data.CNIC);
				 fflush(stdin);
			
				char CNIC[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
				strcpy(CNIC,e_data.CNIC);
			
				struct employee esearch;
				while(fscanf( ep, "%s %s  %d  %s %d %d\n",&esearch.name,&esearch.CNIC,&esearch.age,&esearch.email,&esearch.qualifications,&esearch.experience) != EOF )
				{
	
					if( strcmp(esearch.CNIC,CNIC)==0 )
					{
						system("cls");
						printf("\n\n \t An Account with this CNIC already exists \n\n \t Please try again");
						goto e_enter;
					}
				}
			
				printf("\n\n\t\t\t\t\t\t\tEnter your Age: ");
				scanf("%d",&e_data.age);
				printf("\n\n\t\t\t\t\t\t\tEnter your E-mail: ");
				fflush(stdin);
				scanf("%s",&e_data.email);
				fflush(stdin);
	        	printf("\n\n\t\t\t\t\t\t\tEnter your experience(in years): ");
				scanf("%d",&e_data.experience);
				printf("\n");
				e_list();
				printf("\n\n\t\t\t\t\t\tChoose your Qualification from the list above: ");
				scanf("%d",&e_data.qualifications);
			            
			
           		fprintf(ep,"%s %s  %d %s %d %d\n",e_data.name,e_data.CNIC,e_data.age,e_data.email,e_data.qualifications,e_data.experience);
            	fclose(ep);
            }
            else
            {
            	printf("\n\nInvalid input. Try again\n\n");
            	goto emp_reg_page;
			}
            // This code now stores above input data into a file
            
            printf("\n\n\t\t\t\t\t\t WAY TO GO!! You have Successfully Reigstered into JobBase \n\t\t\t\t\t\t\tYou can use your CNIC code to log in \n");
			elogin:
			printf("\n\n\t\t\t\tPress 0 to proceed to login page || Press 1 to return to main entry || Press 2 to exit\n\n\t\t\t\t\t\t\t\t\t"); 
			scanf("%d",&a);
			if(a == 0 )
			{
				system("cls");
				e_login();
				goto ereturn;
			}
			else if( a == 1)
			{
				system("cls");
				goto p2;
			}
			else if(a == 2)
			{
				exit(0);
			}
			
			else 
			{
				printf("Wrong input");
				goto elogin;
			}
		
		}
		else if( e_entry == 2 ) // employee log in
		{
			login:    
			printf("\n\n \t\t\t\t\t\t\t\t\tThis is Employee's Login page ");
			eentry2:
			printf("\n\n\t\t\t\t\t\t\t\t Press 1 login    ||    Press 0 to return  \n\n\t\t\t\t\t\t\t\t\t\t  ");
			int back;
			scanf("%d",&back);
			if(back == 1)
			{
				system("cls");
				e_login();	
				ereturn:
				printf("\nPress 0 to go back to employee enter || press 1 to login again || press 2 to go to main entry ");
				scanf("%d", &eback );
				if( eback == 0 )
				{
					system("cls");
					goto e_enter;
				}
				else if( eback == 1)
				{
					system("cls");
					goto login;
				}
				else if( eback == 2)
				{
					system("cls");
					goto p2;
				}
				else 
				{
					printf("\nWrong input. Try again.\n");
					goto ereturn;
				}
			}
			else if (back == 0)
			{
				system("cls");
				goto e_enter;
			}
			else
			{
				printf("\nWrong input. Try again\n");
				goto eentry2;
			}
		
		}
		
		else if (e_entry == 3)
		{
			int goback;
			printf("\n\n\t\t\t\t\t\t 1. Update my Details \t\t 2. Go back instead\n\n\t\t\t\t\t\t\t\t\t");
			scanf("%d",&goback);
			if(goback==2)
			{
				system("cls");
				goto e_enter;
			}
			else if (goback == 1)
			{
				FILE *rp;
				rp=fopen("replica.txt","w");
				if(rp == NULL)
			    {
		    		printf("File Not Found");
		    		exit(1);
				}
		
			char e_CNIC[50];
			system("cls");
			ep=fopen("employee.txt","r");
			if(ep == NULL)
			    {
		    		printf("File Not Found");
		    		exit(1);
				}
			printf("Enter CNIC to Update the record: ");
			scanf("%s",&e_CNIC);
			
			while(fscanf( ep, "%s %s  %d  %s %d %d\n",&e_data.name,&e_data.CNIC,&e_data.age,&e_data.email,&e_data.qualifications,&e_data.experience) != EOF )
			{
				if(strcmp(e_data.CNIC,e_CNIC)==0)
				{
					system("cls");
					printf("\n\n\t\t\t\tEnter details to update \n\n");
					
					printf("\n\n\t\t\t\t\tName:");
				    scanf("%s",&e_data.name);
			     	fflush(stdin);
				    printf("\n\t\t\t\t\tCNIC: ");
			        scanf("%s",&e_data.CNIC);
				    fflush(stdin);
				    printf("\n\t\t\t\t\tAge: ");
				    scanf("%d",&e_data.age);
			     	printf("\n\t\t\t\t\tE-mail: ");
			    	fflush(stdin);
			    	scanf("%s",&e_data.email);
			    	fflush(stdin);
	        	    printf("\n\t\t\t\t\tEnter experience(in years): ");
			    	scanf("%d",&e_data.experience);
			    	printf("\n");
				    e_list();
			    	printf("\n\n\t\t\t\t\tEnter your Qualification from the list above: ");
			     	scanf("%d",&e_data.qualifications);	
	            }
				
				fprintf(rp,"%s %s  %d %s %d %d\n",e_data.name,e_data.CNIC,e_data.age,e_data.email,e_data.qualifications,e_data.experience);
			}
			
			fclose(rp);
	        fclose(ep);
        	remove("employee.txt");
         	rename("replica.txt","employee.txt");
         	
         	printf("\n\nCONGRATULATIONS!! You have Successfully Updated your JobBase account \nYou can use your CNIC code to log in \n");
			
			printf("\nPress 0 to proceed to login page || Press 1 to return to main entry || Press 2 to exit\n"); 
			scanf("%d",&a);
			if(a == 0 )
			{
				system("cls");
				e_login();
				goto ereturn;
			}
			else if( a == 1)
			{
				system("cls");
				goto p2;
			}
			else if(a == 2)
			{
				exit(0);
			}
			
			else 
			{
				printf("Wrong input");
				goto elogin;
			}
		
				
			}
		}
		
		else if (e_entry == 4)
		{
			printf("\n\n\t\t\t\t\t\t\t1. Delete My account \t 2. Go back instead \n\n\t\t\t\t\t\t\t\t\t");
			int goback;
			scanf("%d",&goback);
			if(goback == 2)
			{
				system("cls");
				goto e_enter;
			}
			else if (goback == 1)
			{
			FILE *rp;
			rp=fopen("replica.txt","w");
			if(rp == NULL)
			    {
		    		printf("File Not Found");
		    		exit(1);
				}
		
			char e_CNIC[50];
			system("cls");
			ep=fopen("employee.txt","r");
			if(ep == NULL)
			    {
		    		printf("File Not Found");
		    		exit(1);
				}
			printf("\n\n\t\t\t\t\t\tEnter CNIC to Delete Account: \n\n\t\t\t\t\t\t");
			scanf("%s",&e_CNIC);
			
			while(fscanf( ep, "%s %s  %d  %s %d %d\n",&e_data.name,&e_data.CNIC,&e_data.age,&e_data.email,&e_data.qualifications,&e_data.experience) != EOF )
			{
				if(strcmp(e_data.CNIC,e_CNIC)!=0)
				{
					fprintf(rp,"%s %s  %d %s %d %d\n",e_data.name,e_data.CNIC,e_data.age,e_data.email,e_data.qualifications,e_data.experience);
				}
			
	    	}
	    	fclose(rp);
	        fclose(ep);
        	remove("employee.txt");
         	rename("replica.txt","employee.txt");
         	
         	printf("\t\t\t\tAccount Deleted Successfully\n");
         	printf("\n\n\t\t\t\t We wish you a wholesome Career");
         	system("pause");
         	system("cls");
         	goto p2;
	    }
	}
		
		else if (e_entry == 5)
		{
			goto p2;
		}
		else 
		{
			printf("Wrong input. Try again \n");
			goto e_enter;
		}
		
		
		
	}
	else if( type == 2) // employer
	{
		c_enter:
		printf("\n\n\t\t\t\t\t\t\t\t I wish to... ");
		printf("\n\n\n\t 1. Register as an Employer \t 2. log-in as an Employer \t 3. Edit Company Details  \t 4. Delete Company from the record\t 5.Go back instead \n\n\t\t\t\t\t\t\t\t\t\t");
		scanf("%d", &c_entry); // company entry
		system("cls");
		
		
		if( c_entry == 1) // for registering company
		{
			cp = fopen("company.txt","a+");
			if(cp == NULL)
		    {
		    	printf("File Not Found");
		    	exit(1);
			}
			int goback;
			comp_reg:
			printf("\n\n\t\t\t\t\t\t\t\tThis is Employer's Registration Page \n\n ");
			printf("\n\t\t\t\t\t\t 1. Fill the Registration form \t\t 2. Go back instead \n\n\t\t\t\t\t\t\t\t\t\t");
			scanf("%d",&goback);
			
			
			if(goback == 2)
			{
				system("cls");
				goto c_enter;
			}
			else if (goback == 1)
			{
				
				printf("\n \t\t\t\t\t\t\tWelcome!! Please Fill the details below to Register");	
				printf("\n\n\n\t\t\t\t\t\t\tEnter the name of your Company: ");
				scanf("%s",&c_data.c_name);
				printf("\n\n\t\t\t\t\t\t\tEnter Company Unique ID of Five Integers: ");
				scanf("%d",&c_data.c_id);
			
				char comp[50];
				struct company csearch;
				strcpy( comp, c_data.c_name);
			
				while( fscanf(cp, "%s %d %s %d %d %d %d \n", &csearch.c_name,&csearch.c_id,&csearch.contact,&csearch.hiring,&csearch.min_age,&csearch.min_exp,&csearch.pay ) != EOF)
				{
					if(strcmp(comp,csearch.c_name)==0 || c_data.c_id == csearch.c_id )
					{
						system("cls");
						printf("Company already registered. Name or ID already taken");
						goto c_enter;
					}
				}
			
				printf("\n\n\t\t\t\t\t\t\tEnter Contact information(eg.Email or Landline Number): )");
				scanf("%s",&c_data.contact);
				
				printf("\n\n\t\t\t\t\t\t\tWho are you looking for? Choose from the list below ");
				e_list();
				scanf("%d",&c_data.hiring);
				printf("\n\t\t\t\t\t\t\tWhat is your Minimum age requiremenet: ");
				scanf("%d",&c_data.min_age);
				printf("\n\t\t\t\t\t\t\tWhat is your minimum experience reuqirement(in Years): ");
				scanf("%d",&c_data.min_exp);
				printf("\n\t\t\t\t\t\t\tHow much are you willing to pay: ");
				scanf("%d",&c_data.pay);
			
				//printing company data on text file
				fprintf(cp,"%s %d %s %d %d %d %d \n", c_data.c_name, c_data.c_id, c_data.contact, c_data.hiring, c_data.min_age, c_data.min_exp, c_data.pay );
				fclose(cp);
				
				//PRINT THAT U HAVE SUCCESSFULLY REGISTERED
				printf("\n\t\t\t\t\t\t\tWAY TO GO!! You have succesfully registered for JobBase");
				printf("\n\n\t\t\t\t\t\t\t 1.Press 1 to view the list of employees \t\t 2.Press 2 to logout");
				int y = 0;
				scanf("%d",&y);
				if(y == 2)
				{
					system("cls");
					goto c_enter;
				}
				else if( y == 1)
				{
					system("cls");
					empsearch();
					system("cls");
					search:
					e_search(c_data.hiring, c_data.min_age, c_data.min_exp );   //where does it go after this
					
				}
				else
				{
					printf("Wrong input");
					goto search;
				}
				
				
				// TILL HERE
			}
			else
			{
				system("cls");
				printf("Wrong input. Try again\n\n");
				goto comp_reg;
			}
			
		}
		else if(  c_entry == 2 ) // log in here. of company
		{
			char company[30];
			comp_login1:
			printf("\n\n\t\t\t\t\t\t\t\t\tThis is Employer's Login Page");
			comp_login2:
			printf("\n\n\t\t\t\t\t\t\tEnter 0 to return to Employer Entry || Enter 1 to login\n");
			scanf("%d",&goback2);
			if(goback2 == 0)
			{
				system("cls");
				goto c_enter;
			}
			else if (goback2 == 1)
			{
				printf("\n\n\t\t\t\t\tPlease login below \n");	
//				printf("\n\t\t\t\t\tEnter Company Name: ");
//				scanf("%s",company);
				c_login();
				goto comp_login2;
			}
			else
			{	
				system("cls");
				printf("Wrong input. Try again\n");
				goto comp_login1;
			}
		}
		
		else if(c_entry==3)
		{
			FILE *rp;
			rp=fopen("replica.txt","w");
			if(rp==NULL)
			{
				printf("File not found");
				exit(1);
			}
			
			int c_id_search;
			
			cp=fopen("company.txt","r");
			if(cp==NULL)
			{
				printf("File not found");
				exit(1);
			}
			
			int c_id,goback;
			printf("\n\n\t\t\t\t\t 1.Update Your Company Records \t\t 2.Go back Instead");
			scanf("%d",&goback);
			if(goback==2)
			{
				system("cls");
				goto c_enter;
			}
			else if(goback == 1)
			{
				printf("\n\n\nEnter your Company Unique ID to Update the record: ");
	        	scanf("%d", &c_id); 
	        
	        while( fscanf(cp, "%s %d %s %d %d %d %d \n", &c_data.c_name,&c_data.c_id,&c_data.contact,&c_data.hiring,&c_data.min_age,&c_data.min_exp,&c_data.pay ) != EOF )
        	{
	        	if( c_data.c_id == c_id )
	        	{
	        		system("cls");
	        		printf("\n\nEnter the name of your Company: ");
				    scanf("%s",&c_data.c_name);
				    fflush(stdin);
				    printf("\nEnter Contact information(eg.Email or Landline Number): )");
			    	scanf("%s",&c_data.contact);
			    	fflush(stdin);
			    	printf("Enter Company Unique ID of Five Integers: ");
			    	scanf("%d",&c_data.c_id);
		     		printf("\nWho are you looking for? Choose from the list below ");
			    	e_list();
				    scanf("%d",&c_data.hiring);
	       			printf("\nWhat is your Minimum age requiremenet: ");
		    		scanf("%d",&c_data.min_age);
			    	printf("\nWhat is your minimum experience reuqirement(in Years): ");
		 	    	scanf("%d",&c_data.min_exp);
		     		printf("How much are you willing to pay: ");
		    		scanf("%d",&c_data.pay);
	           	}
	           	else 
	           	{
	           		printf("\nRecord Not Found\n");
	           		system("pause");
	           		system("cls");
	           	
			   	}
	        	fprintf(rp,"%s %d %s %d %d %d %d \n", c_data.c_name, c_data.c_id, c_data.contact, c_data.hiring, c_data.min_age, c_data.min_exp, c_data.pay );
		   }
		   }
		   
		   
			fclose(rp);
	        fclose(cp);
        	remove("company.txt");
         	rename("replica.txt","company.txt");
		   
		   y=0;
				printf("Press 1 get employees list that you might be interested in");
				scanf("%d", &y);
				if( y == 1)
				{
					system("cls");
					empsearch();
					system("cls");
					
					e_search(c_data.hiring, c_data.min_age, c_data.min_exp );   
				}
				else
				{
					printf("Wrong input");
					goto search;
				}
			
	}
			
	    else if(c_entry==4)	
        {
        	FILE *rp;
			rp=fopen("replica.txt","w");
			if(rp==NULL)
			{
				printf("File not found");
				exit(1);
			}
			
			int c_id_search;
			
			cp=fopen("company.txt","r");
			if(cp==NULL)
			{
				printf("File not found");
				exit(1);
			}
			
			int c_id,goback;
			printf("\n\n\t\t\t\t1.Delete Your Account \t\t 2.Go back instead");
			scanf("%d",&goback);
			if(goback == 2)
			{
				system("cls");
				goto c_enter;
			}
			else if (goback == 1)
			{
				printf("\n\n\t\t\t\t\t\ Enter your Company Unique ID to Delete Company from the record: \n\t\t\t\t\t\t");
	        	scanf("%d", &c_id); 
	        
	        	while( fscanf(cp, "%s %d %s %d %d %d %d \n", &c_data.c_name,&c_data.c_id,&c_data.contact,&c_data.hiring,&c_data.min_age,&c_data.min_exp,&c_data.pay ) != EOF )
        		{
	        		if( c_data.c_id != c_id )
	        		{
	        			fprintf(rp,"%s %d %s %d %d %d %d \n", c_data.c_name, c_data.c_id, c_data.contact, c_data.hiring, c_data.min_age, c_data.min_exp, c_data.pay );
	        		}
		
		 		   }
			
				fclose(rp);
	        	fclose(cp);
        		remove("company.txt");
         		rename("replica.txt","company.txt");
			 
		    	printf("\n\n\t\t\t\tYour Account has been deleted Successfully\n");
		    	printf("\n\n\t\t\t\t\t\tGoodbyes are hard");
         		system("pause");
         		system("cls");
         		goto p2;	
			}
		}
		else if (c_entry == 5)
		{
			goto p2;
		}
		else// input not 1 or 2
		{
			printf("Wrong input. Try again \n");
			goto c_enter;
		}
	}
	else
	{
		printf("Wrong input. Try again \n");
		goto start;
	}
	
}


void e_list()
{
	printf("\n\n\n\t\t\t\t\t\t\t1.Computer Scientist");
	printf("\n\t\t\t\t\t\t\t2.Electrical Engineer");
	printf("\n\t\t\t\t\t\t\t3.Software Engineer");
	printf("\n\t\t\t\t\t\t\t4.Doctor(MBBS)");
	printf("\n\t\t\t\t\t\t\t5.Mechanical Engineer");
	printf("\n\t\t\t\t\t\t\t6.Chartered Accountant");
	printf("\n\t\t\t\t\t\t\t7.Dentist \n");
}

void c_prob(int c_id, int e_exp) 
{
	FILE *cp;
	struct employee e_data1;
	int c_hire, c_min_age, c_min_exp;
	cp = fopen("company.txt", "r");
	if(cp == NULL)
	{
		printf("File Not Found");
		
		exit(1);
	}
	
	
	system("cls");
	rewind(cp);		
	while( fscanf(cp, "%s %d %s %d %d %d %d \n", &c_data.c_name,&c_data.c_id,&c_data.contact,&c_data.hiring,&c_data.min_age,&c_data.min_exp,&c_data.pay ) != EOF )
	{
		if( c_data.c_id == c_id )
		{
			printf("\n\t\tEmployer Name: %s  Employer ID: %d   contact: %s     pay: %d \n", c_data.c_name,c_data.c_id,c_data.contact,c_data.pay);
			
		    c_hire = c_data.hiring;
		    c_min_age = c_data.min_age;
		    c_min_exp =  c_data.min_exp;                                 
		    
			break;
	    }
	    
		
    }  
	
	fclose(cp);                                                                
	
	
	
	FILE *ep;
	int countqual=0, extra_exp, sum_extra_exp = 0, prob;
	
	
	ep = fopen("employee.txt", "r");
	if(ep == NULL)
	{
		printf("File Not Found");
		exit(1);
	}
			
	rewind(ep);
	while( fscanf( ep, "%s %s %d  %s %d %d\n",&e_data1.name,&e_data1.CNIC,&e_data1.age,&e_data1.email,&e_data1.qualifications,&e_data1.experience) != EOF)
	{
		if(c_hire == e_data1.qualifications  &&  c_min_age <= e_data1.age  &&  c_min_exp <= e_data1.experience)
		{
			countqual++;  
		}
				
	} 
	
				prob = 100/countqual;
			
			printf("\n\n\t\t\t\tYour chances of getting this job: %d %% \n\n(Pls note that this probability is only based on the number of employees qualified for the job.\nPls contact the employer for further evaluation)\n\n", prob);
			
	
	
	
	fclose(ep);
}




void e_best(int c_hire, int c_min_age, int c_min_exp)
{
	FILE *ep;
	struct employee e_best, e_best1;
	int max_exp = -10;
	char emp_CNIC[50];
	ep = fopen("employee.txt", "r");
	if(ep == NULL)
	{
		printf("File Not Found");
		exit(1);
	}
			
	printf("\n\n\t\tBest Employee with same criteria: \n");
	//printf("\n\t\t You can reach out to these employees via Email\n");
	rewind(ep);
	while( fscanf( ep, "%s %s %d  %s %d %d\n",&e_best.name,&e_best.CNIC,&e_best.age,&e_best.email,&e_best.qualifications,&e_best.experience) != EOF)
	{
		if(c_hire == e_best.qualifications  &&  c_min_age <= e_best.age  &&  c_min_exp <= e_best.experience)
		{
			
			if( e_best.experience >= max_exp)
			{
				max_exp = e_best.experience;
				strcpy(emp_CNIC, e_best.CNIC);
			}
		}
				
	} 
	
	rewind(ep);
	while( fscanf( ep, "%s %s  %d  %s %d %d\n",&e_best1.name,&e_best1.CNIC,&e_best1.age,&e_best1.email,&e_best1.qualifications,&e_best1.experience) != EOF)
	{
		if( strcmp(emp_CNIC, e_best1.CNIC) == 0)
		{
			printf("\nBest employee, based on highest experience only:\n");
			printf("Name: %s CNIC: %d age: %d  email: %s experience: %d years \n", e_best1.name, e_best1.CNIC, e_best1.age, e_best1.email, e_best1.experience);
			
			
		}
				
	} 
	
	
	fclose(ep);
}


//function for employee log in
void e_login()  
{
	FILE *ep;
	char e_CNIC_search[50];
	int x, c_id, a, invalidcnic;
	again: 
	printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tYou may login below\n");
	printf("\n\t\t\t\t\t\tEnter your CNIC to Log-in: ");
	scanf("%s",&e_CNIC_search); 
		    
	ep = fopen("employee.txt", "r");
	if(ep == NULL)
	{
		printf("File Not Found");
		exit(1);
	}
	
	system("cls");
	rewind(ep);		
	while( fscanf( ep, "%s %s  %d  %s %d %d\n",&e_data.name,&e_data.CNIC,&e_data.age,&e_data.email,&e_data.qualifications,&e_data.experience) != EOF )
	{
		if(strcmp(e_data.CNIC,e_CNIC_search )==0)
		{
			system("cls");
			loginload();
			system("cls");
			profile:
			printf("\n\n\t\t\t\t\t\t\t\t -------Welcome back %s!--------",e_data.name);
			printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\tYour Profile\n\n\n"); 
		    printf("\t\t\t\t\t\tName: %s \n", e_data.name); 
		    printf("\n\n\t\t\t\t\t\tCNIC: %s \n", e_data.CNIC);
		    printf("\n\n\t\t\t\t\t\tAge: %d \n", e_data.age);
		    printf("\n\n\t\t\t\t\t\temail: %s \n", e_data.email);
		    printf("\n\n\t\t\t\t\t\tExperience( in years): %d \n", e_data.experience);
		    printf("\n\n\t\t\t\t\t\tYour qualification: ");
			qualification_print(e_data.qualifications);
			jobfind:
			printf("\n\n\n\n\t\t\t\t\t\t\tPress 1 to find yourself a job ||  Press 0 to logout \n\n\t\t\t\t\t\t\t\t\t\t");
			scanf("%d",&x);
				if(x == 1)
				{
					system("cls");
					loadingBar();
					system("cls");
					joblist: 
					printf("\n\n \t\t\t\t\t\t\t\t We did some work for you");
					c_search( e_data.qualifications, e_data.age, e_data.experience );
					
					break;	
				}
				else if(x == 0) //logout
				{
					system("cls");
					logoutload();
					system("cls");
					return;
				}
				else// else if statement if x is neither 0 nor 1
				{
					printf("Invalid input. Try again\n");
					goto jobfind;
				}
				
			
		}
		
    }  
		if( strcmp(e_data.CNIC,e_CNIC_search ) !=0 )
		{
				enter1:
				printf("\nInvalid Login details.\nPress O to exit || Press 1 to try again || Press 2 to go back to previous page   \n "); //or go back to previous page
				scanf("%d", &invalidcnic);
				if( invalidcnic == 0 )
				{
					printf("You have exited the program");
					exit(0);
				}
				else if( invalidcnic == 1 )
				{
					system("cls");
					goto again;
				} 
				else if( invalidcnic == 2 )
				{
					system("cls");
					return;
				}
				else 
				{
					system("cls");
					printf("Invalid input. Try again\n");
					goto enter1;
				}
				
		}
	// wanna get probobabilty or previous page. or log out	
	int cprob;
	cprob:
	printf("\n\n\n\t\t\t\tPress 1 to get probabilities || Press 2 to logout || Press 3 to go back to your Profile  ");
	scanf("%d", &cprob);
	if( cprob == 1)
	{
		printf("\n\n\n\t\t\t\tEnter 5 digit Employer ID to get the probability of getting accepted:  ");
		scanf("%d", &c_id);
		system("cls");
		probload();
		system("cls");
		c_prob(c_id, e_data.experience ); 
	
	}
	else if( cprob == 2 )
	{
		system("cls");
		logoutload();
		system("cls");
		return;
	}
	else if( cprob == 3 )
	{
		system("cls");
		goto profile;
	}
	else 
	{
		system("cls");
		printf("Invalid input. Try again\n");
		goto cprob;
	}
	enter:
	printf("Press 0 to exit || Press 1 to go back to the list of available jobs || Press 2 to go back to your Profile || Press 3 to logout \n"); 
	scanf("%d", &a);
	if( a == 1 )
	{
		system("cls");
		goto joblist;
	}
	else if( a == 0)
	{
		printf("You have exited the program");
		exit(0);
	}
	else if( a == 2)
	{
		system("cls");
		goto profile;
	}
	else if( a == 3)
	{
		system("cls");
		logoutload();
		system("cls");
		return;
	}
	else 
	{
		system("cls");
		printf("Invalid input. Try again\n");
		goto enter;
	}
						

	
	fclose(ep);
}

// function for company login

void c_login()  
{
	FILE *cp;
	int c_id_search, xc, cid, x;
	
	
	
	again: 
	printf("\n\n\t\t\t\t\tYou may login below\n");
	c_login_again:
	printf("\n\n\t\t\t\t\tEnter your Company Unique ID to Log-in: ");
	scanf("%d", &c_id_search); 
		    
	cp = fopen("company.txt", "r");
	if(cp == NULL)
	{
		printf("File Not Found");
		
		exit(1);
	}
	
	system("cls");
	rewind(cp);		
	while( fscanf(cp, "%s %d %s %d %d %d %d \n", &c_data.c_name,&c_data.c_id,&c_data.contact,&c_data.hiring,&c_data.min_age,&c_data.min_exp,&c_data.pay ) != EOF )
	{
		if( c_data.c_id == c_id_search )
		{
			system("cls");
			loginload();
			system("cls");
			printf("\n\n\t\t\t\t\t\tWelcome back %s !",c_data.c_name);
			printf("\n\n\t\t\t\t\t\tCompany Profile\n\n"); // or print- your profile
		    printf("\t\t\tCompany Name: %s \n", c_data.c_name); 
		    printf("\t\t\tCompany Unique ID: %d \n", c_data.c_id);
		    printf("\t\t\tCompany Contact: %d \n", c_data.contact);
		    int best;
		    c_log_back:
		    printf("\n\n\t\t\t\t\tPress 1 to find list of employees ||  Press 0 to logout \n ");
			scanf("%d",&xc);
			system("cls");

			switch(xc)
			{
		
				case 1:
				{
					system("cls");
					loadingBar();
					system("cls");
					printf("\n We did some work for you");
					search:
		    		e_search(c_data.hiring, c_data.min_age, c_data.min_exp );// dont need it anymore if prob works
		    		printf("Press 1 to find the best employee || Press 0 to logout");
		    		scanf("%d", &best);
		    		if( best == 1)
		    		{
		    			system("cls");
		    			e_best(c_data.hiring, c_data.min_age, c_data.min_exp);
						goto c_log_back;
					}
					else if( best == 0)
					{
						system("cls");
						logoutload();
						system("cls");
						return;
					}
					else
					{
						system("cls");
						printf("Invalid input. Try again.  \n");
						goto search;
					}
		    		goto c_log_back;
		    		//e_prob(c_data.hiring, c_data.min_age, c_data.min_exp);
					break;	
				}
				case 0:
				{
					system("cls");
				
					logoutload();
					system("cls");
					//exit(0); //return instead
					return;
				}
//				case 2:
//				{
//					e_best(c_data.hiring, c_data.min_age, c_data.min_exp);
//					goto c_log_back;
//				}
			}
			break;
	    }
	    
		
    }  
    if( c_data.c_id != c_id_search )
    {
    	invalid:
    	printf("Invalid ID. Press 1 to try again || Press 0 to exit");
    	scanf("%d", &x );
    	if( x == 1 )
    	{
    		system("cls");
    		goto again;
		}
		else if( x == 0 ) //exit application
		{
			printf("program exited"); // or write something nice****
			exit(0);
		}
		else
		{
			system("cls");
			printf("Invalid input. Try again\n");
			goto invalid;
		}
	}
}

void e_search(int c_hire, int c_min_age, int c_min_exp)
{			
	//FILE *cp;
	FILE *ep;
	ep = fopen("employee.txt", "r");
	if(ep == NULL)
	{
		printf("File Not Found");
		exit(1);
	}
			
	printf("\nEmployees with same criteria: \n");
	printf("\n\t\t You can reach out to these employees via Email\n");
	while( fscanf( ep, "%s %s %d  %s %d %d\n",&e_data.name,&e_data.CNIC,&e_data.age,&e_data.email,&e_data.qualifications,&e_data.experience) != EOF)
	{
		if(c_hire == e_data.qualifications && c_min_age <= e_data.age &&  c_min_exp <= e_data.experience)
		{
			printf("Name: %s CNIC: %s age: %d  email: %s experience: %d years\n", e_data.name, e_data.CNIC, e_data.age, e_data.email, e_data.experience);
		}
				
	} 
}

void c_search(int e_qual, int e_age, int e_exp)
{
	FILE *cp;
	cp = fopen("company.txt","r");
	if(cp == NULL)
	{
		printf("File Not Found");
		exit(1);
	}
	
	printf("\n\n\t\t\t\tEmployers that might be interested in you. You can reach out to these employer's using email  \n\n");		
	while( fscanf(cp, "%s %d %s %d %d %d %d \n", &c_data.c_name, &c_data.c_id, &c_data.contact,&c_data.hiring,&c_data.min_age,&c_data.min_exp,&c_data.pay ) != EOF)		
	{
		if(  e_qual == c_data.hiring  &&  e_age >= c_data.min_age  &&   e_exp >= c_data.min_exp  )
		{
			printf("\n\t\t\t\tEmployer Name: %s  Employer ID: %d   contact: %s     pay: %d \n", c_data.c_name,c_data.c_id,c_data.contact,c_data.pay);
		}
	}
	
	fclose(cp);
}

void qualification_print(int qual)
{
	if(qual == 1 )
		printf("Computer Scientist");
	else if( qual == 2)	
    	printf("Electrical Engineer");
	else if( qual == 3)
		printf("Software Engineer");
	else if( qual == 4 )	
		printf("Doctor(MBBS)");
	else if( qual == 5 )	
		printf("Mechanical Engineer");
	else if( qual == 6  )	
		printf("Chartered Accountant");
	else if( qual == 7 )	
		printf("Dentist");
}

void loadingBar() 
{ 
    // 0 - black background, 
    // A - Green Foreground 
    system("color f0"); 
  
    // Initialize char for printing 
    // loading bar 
    char a = 177, b = 219; 
  
    printf("\n\n\n\n"); 
    printf("\n\n\n\n\t\t\t\t\t Searching jobs for you...\n\n"); 
    printf("\t\t\t\t\t"); 
  
    // Print initial loading bar
	int i; 
    for (i = 0; i < 30; i++) 
        printf("%c", a); 
  
    // Set the cursor again starting 
    // point of loading bar 
    printf("\r"); 
    printf("\t\t\t\t\t"); 
  
    // Print loading bar progress 
    for (i = 0; i < 30; i++) { 
        printf("%c", b); 
  
        // Sleep for 5 second 
        Sleep(70); 
    } 
} 

void loginload() 
{ 
    // 0 - black background, 
    // A - Green Foreground 
    system("color f0"); 
  
    // Initialize char for printing 
    // loading bar 
    char a = 177, b = 219; 
  
    printf("\n\n\n\n\n\n"); 
    printf("\n\n\n\n\t\t\t\t\t Logging in...\n\n"); 
    printf("\t\t\t\t\t"); 
  
    // Print initial loading bar
	int i; 
    for (i = 0; i < 30; i++) 
        printf("%c", a); 
  
    // Set the cursor again starting 
    // point of loading bar 
    printf("\r"); 
    printf("\t\t\t\t\t"); 
  
    // Print loading bar progress 
    for (i = 0; i < 30; i++) { 
        printf("%c", b); 
  
        // Sleep for 5 second 
        Sleep(20); 
    } 
} 
void logoutload() 
{ 
    // 0 - black background, 
    // A - Green Foreground 
    system("color f0"); 
  
    // Initialize char for printing 
    // loading bar 
    char a = 177, b = 219; 
  
    printf("\n\n\n\n"); 
    printf("\n\n\n\n\t\t\t\t\t\t Logging out...\n\n"); 
    printf("\t\t\t\t\t"); 
  
    // Print initial loading bar
	int i; 
    for (i = 0; i < 30; i++) 
        printf("%c", a); 
  
    // Set the cursor again starting 
    // point of loading bar 
    printf("\r"); 
    printf("\t\t\t\t\t"); 
  
    // Print loading bar progress 
    for (i = 0; i < 30; i++) { 
        printf("%c", b); 
  
        // Sleep for 5 second 
        Sleep(20); 
    } 
}
void empsearch() 
{ 
    system("color f0"); 
  
    // Initialize char for printing 
    // loading bar 
    char a = 177, b = 219; 
  
    printf("\n\n\n\n"); 
    printf("\n\n\n\n\t\t\t\t\t Searching Qualified Employees\n\n"); 
    printf("\t\t\t\t\t"); 
  
    // Print initial loading bar
	int i; 
    for (i = 0; i < 30; i++) 
        printf("%c", a); 
  
    // Set the cursor again starting 
    // point of loading bar 
    printf("\r"); 
    printf("\t\t\t\t\t"); 
  
    // Print loading bar progress 
    for (i = 0; i < 30; i++) { 
        printf("%c", b); 
  
        // Sleep for 5 second 
        Sleep(20); 
    }     
}


void probload() 
{ 
    system("color f0"); 
  
    // Initialize char for printing 
    // loading bar 
    char a = 177, b = 219; 
  
    printf("\n\n\n\n"); 
    printf("\n\n\n\n\t\t\t\t\t Calculating your Chances\n\n"); 
    printf("\t\t\t\t\t"); 
  
    // Print initial loading bar
	int i; 
    for (i = 0; i < 30; i++) 
        printf("%c", a); 
  
    // Set the cursor again starting 
    // point of loading bar 
    printf("\r"); 
    printf("\t\t\t\t\t"); 
  
    // Print loading bar progress 
    for (i = 0; i < 30; i++) { 
        printf("%c", b); 
  
        // Sleep for 5 second 
        Sleep(50); 
    }     
}



int main()
{
	system("color f1");
	menuu();
	return 0;
}














