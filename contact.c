/*
Name:Chithra M
Description:Address book project.
Date:06-07-25
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
//#include "populate.h"
int mobile_validation(char *mobile_num);
int mail_validation(char *email);
void createContact(AddressBook *addressBook)
{
   char per_name[50]; // Temporarily creating variable for name
printf("Enter the Name:\n");
getchar(); // Waiting for input from stdin 
again_again: // Label
 scanf("%[^\n]", per_name); // Taking return value of scanf and taking input from user
getchar();

char mobile_num[20]; // Creating string for mobile number temporarily
enter_again: // Label for mobile number
printf("Enter mobile number:\n");
scanf("%[^\n]", mobile_num); // Asking values to return from user
getchar();
int valid_mobile = mobile_validation(mobile_num); // Validating mobile
if (valid_mobile != 0) { // If mobile number is validated
    int k; // Creating a variable
    for (k = 0; k < addressBook->contactCount; k++) { // Loop boundary corrected
        int ph = strcmp(addressBook->contacts[k].phone, mobile_num); // Comparing mobile number with dummy contacts 
        if (ph == 0) {
            printf("This Contact is Already saved. Please Enter a 10-digit number (0-9):\n"); // If contact is found
            goto enter_again;
        }
    }
} else {
    printf("Enter a 10-digit '0'-'9' mobile number:\n");
    goto enter_again;
}

// Creating temporary variable for email
char temp_gmail[200]; // Creating a string for a temporary variable
retry_email:
printf("Enter the Email: ");
scanf("%[^\n]", temp_gmail); // Asking mail from user
getchar();
int valid_email = mail_validation(temp_gmail); // Validating mail
if (valid_email == 0) {
    printf("Enter a valid email with both @ & .com:\n");
    goto retry_email;
}

int p; // Creating a variable
for (p = 0; p < addressBook->contactCount; p++) { // Loop boundary corrected
    int ml = strcmp(addressBook->contacts[p].email, temp_gmail); // Comparing email with existing contacts
    if (ml == 0) {
        printf("This mail is Already saved. Please Enter a unique email with correct validations:\n"); // If contact is found
        goto retry_email;
    }
}

// Copying user-entered name, phone number, and email into addressBook
strcpy(addressBook->contacts[addressBook->contactCount].name, per_name);
strcpy(addressBook->contacts[addressBook->contactCount].phone, mobile_num);
strcpy(addressBook->contacts[addressBook->contactCount].email, temp_gmail);
addressBook->contactCount++;
printf("Contact Added Successfully\n");

}
void listContacts(AddressBook *addressBook) 
{
    int i;
    for(i=0;i<addressBook->contactCount;i++)//run untill count times 
    {
	printf("Name:%s",addressBook->contacts[i].name);
	printf("Phone:%s",addressBook->contacts[i].phone);
	printf("mail:%s",addressBook->contacts[i].email);
	printf("\n");
    }

}
void searchContact(AddressBook *addressBook) 
{
    char search;
    label:
    printf("1. Name\n");
    printf("2. Mobile number\n");
    printf("3. E-mail id\n");
    printf("What do you want to search:\n");
    getchar();
    scanf("%c", &search);

    if (search >= '1' && search <= '3')
    {
        if (search == '1') // To Search Name
        {
            char str2[20]; // String with name to search
            getchar(); // Buffer clear
            printf("Enter the name to search for: ");
            scanf("%[^\n]", str2); // Asking user for input
            getchar();
            int found = 0; // To track if any contact is found

            for (int i = 0; i < addressBook->contactCount; i++)
            {
                // Check if the name starts with the given input
                if (strncmp(addressBook->contacts[i].name, str2, strlen(str2)) == 0)
                {
                    printf("Name: %s\n", addressBook->contacts[i].name);
                    printf("Phone: %s\n", addressBook->contacts[i].phone);
                    printf("E-mail: %s\n", addressBook->contacts[i].email);
                    found = 1;
                    printf("Contact searched successfully through name %s\n",str2);
                }
            }

            if (found == 0) // If no contact is found
            {
                printf("No contact with the name exists in the address bookwith %s.\n",str2);
            }
        }
        else if (search == '2') // Mobile number
        {
            char str2[20]; // String for mobile number
            enter_again: // Label for re-entering
            printf("Enter the mobile number to search for: ");
            getchar(); // Buffer clear
            scanf("%[^\n]", str2); // Asking user for input
            getchar();
            int validate_mobile = mobile_validation(str2); // Validating mobile number

            if (validate_mobile != 0) // If valid mobile number
            {
                int found = 0;
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (strncmp(addressBook->contacts[i].phone, str2, strlen(str2)) == 0)
                    {
                        printf("Name: %s\n", addressBook->contacts[i].name);
                        printf("Phone: %s\n", addressBook->contacts[i].phone);
                        printf("E-mail: %s\n", addressBook->contacts[i].email);
                        found = 1;
                        printf("Contact searched successfully through mobile number[%s]\n",str2);
                    }
                }

                if (found == 0)
                {
                    printf("No contact with the mobile number exists in the address book[%s].\n",str2);
                }
            }
            else
            {
                printf("Enter a valid 10-digit number from 0-9:\n");
                goto enter_again;
            }
        }
        else if (search == '3') // Email
        {
            char str2[30]; // String for email
            re_enter: // Label for re-entering
            printf("Enter the e-mail to search for: ");
            getchar(); // Buffer clear
            scanf("%[^\n]", str2); // Asking user for input
            getchar();
            int mail_validate = mail_validation(str2); // Validating email

            if (mail_validate != 0) // If valid email
            {
                int found = 0;
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (strncmp(addressBook->contacts[i].email, str2, strlen(str2)) == 0)
                    {
                        printf("Name: %s\n", addressBook->contacts[i].name);
                        printf("Phone: %s\n", addressBook->contacts[i].phone);
                        printf("E-mail: %s\n", addressBook->contacts[i].email);
                        found = 1;
                        printf("Contact searched successfully through email[%s]\n",str2);
                    }
                }

                if (found == 0)
                {
                    printf("No contact with the e-mail exists in the address book[%s].\n",str2);
                }
            }
            else
            {
                printf("Please enter a valid email with '@' and '.com'\n");
                goto re_enter;
            }
        }
    }
    else
    {
        printf("Please enter digits only between 1 to 3:\n");
        goto label;
    }
}

void editContact(AddressBook *addressBook)
{
    int num;
    printf("1.Name:\n");
    printf("2.mail:\n");
    printf("3.phone:\n");
    printf("Enter which one you want to edit:\n");
    scanf("%d", &num);
    getchar();
    if (num >= 1 && num <= 3)
    {
        if (num == 1)
        {
            char str[20];
            printf("Enter the name you want to edit:");
            scanf("%[^\n]", str);
            int found = 0;
            int matchCount = 0;
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(addressBook->contacts[i].name, str) == 0)
                {
                    printf("%d. Name: %s, Phone: %s, E-mail: %s\n",i, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    matchCount++;
                }
            }
            if (matchCount > 0)
            {
                int choice;
                printf("Enter the number of the contact you want to edit (1-%d):\n", matchCount);
                scanf("%d", &choice);
                if (choice >= 1 && choice <=addressBook->contactCount)
                {
                    
                    char edit_name[20];
                    printf("Enter the new name: ");
                    getchar();
                    scanf("%[^\n]", edit_name);
                    strcpy(addressBook->contacts[choice].name, edit_name);
                    printf("Name Updated Successfully\n");
                }
            }
            else
            {
                printf("No contacts found with the name.\n");
            }
        }
  else if(num==2)
        {
         char str[20];//creating string for mail from user
        again:
	    printf("Enter the mail what you want to replace:");
	    scanf("%[^\n]",str);//asking mail from user
	    int i;
        int ret=mail_validation(str);//validating mail
        if(ret!=0)
        {
        int found=0;
	    for(i=0;i<addressBook->contactCount;i++)
	    {
	       if(strcmp(addressBook->contacts[i].email,str)==0)//comparing mail with the addressBook Contacts
	       {
              char mail[100];
               re_enter:
               printf("Enter the mail you want to edit:");
	       getchar();
               scanf("%[^\n]",mail);// ask new mail from user
               int ret33=mail_validation(mail);
               if(ret33!=0)
               {
                strcpy(addressBook->contacts[i].email,mail);//copying new mail into addressBook
		printf("Email Updated successfully\n");
               }
               found=1;
           }
        }
        if(found==0)
        printf("User entered mail is not found");
        }
        else
        {
            printf("Please Enter valid mail to search");
            goto again;
        }
    }
    else if(num==3)
    {
        char str[20];
        again1:
	    printf("Enter the mobile_number what you want to replace:");
	    scanf("%[^\n]",str);
	    int i;
        int ret=mobile_validation(str);
        if(ret!=0)
        {
        int found=0;
	    for(i=0;i<addressBook->contactCount;i++)
	    {
	       if(strcmp(addressBook->contacts[i].phone,str)==0)
	       {
              char mobile[20];
               re_enter1:
               printf("Enter the mail you want to edit:");
               scanf("%s",mobile);
               int squ=mail_validation(mobile);
               if(squ!=0)
               {
                strcpy(addressBook->contacts[i].phone,mobile);
                printf("Mobile Number updated Succesfully");
               }
               else
               {
                printf("Invalid mobile_number");
                   goto re_enter1;
               }
               found=1;
               break;
           }
        }
        if(found==0)
        printf("User entered mobile_number is not found");
        }
        else
        {
            printf("Please Enter valid mail to search");
            goto again1;
        }
    }
}
}
void deleteContact(AddressBook *addressBook)//shifting unwanted contact deleting contact by referencing name phone number or mail
{
    printf("1.Name:\n");
    printf("2.mobile:\n");
    printf("3.mail:\n");
    printf("Enter which want you delete:\n");
    int numb;
    scanf("%d",&numb);
    getchar();
    int i,j;
    int found=0;
    if(numb>=1&&numb<=3)
    {
    if(numb==1)
    {
        char str4[15];
            printf("Enter the name:\n");
            scanf("%[^\n]", str4);
            int matchCount = 0;
            for (i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(addressBook->contacts[i].name, str4) == 0)
                {
                    printf("%d. Name: %s, Phone: %s, E-mail: %s\n",i, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    matchCount++;
                }
            }
            if (matchCount > 0)
            {
                int choice;
                printf("Enter the number of the contact you want to delete :\n");
                scanf("%d", &choice);
                if (choice >= 1 && choice <= addressBook->contactCount)
                {
                    int index = choice - 1;
                    for (j = index; j < addressBook->contactCount - 1; j++)
                    {
                        addressBook->contacts[j] = addressBook->contacts[j + 1];
                    }
                    addressBook->contactCount--;
                    printf("Contact Deleted Successfully\n");
                }
            }
            else
            {
                printf("No contacts found with the name.\n");
            }
    }
    if(numb==2)
    {
        char str4[20];
        printf("Enter the number:");
        scanf("%[^\n]",str4);
        int rett=mobile_validation(str4);
        if(rett!=0)
        {
        for(i=0;i<addressBook->contactCount;i++)
        {
          if(strcmp(addressBook->contacts[i].phone,str4)==0)
          {
          for(j=i;j<addressBook->contactCount-1;j++)
          {
            addressBook->contacts[j]=addressBook->contacts[j+1];
          }
          addressBook->contactCount--;
            found=1;
	    printf("Contact deleted successfully\n");
            break;
           }
        }
         if(found==0)
          printf("Contact not found");
      }
    else
    printf("Enter a 10 digit mobile number from 0-9");
    }
    if(numb==3)
    {
        char str4[50];
        printf("Enter the mail:");
        scanf("%[^\n]",str4);//asking user to enter mail
        int rett=mail_validation(str4);//validating mail
        if(rett!=0)
        {
        for(i=0;i<addressBook->contactCount;i++)
        {
          if(strcmp(addressBook->contacts[i].email,str4)==0)//comparing mobile number with addressBook cotacts
          {
          for(j=i;j<addressBook->contactCount-1;j++)
          {
            addressBook->contacts[j]=addressBook->contacts[j+1];
          }
          addressBook->contactCount--;
            found=1;
	    printf("Contact deleted successfully\n");
            break;
           }
        }
         if(found==0)
          printf("email not found");
        }
        else
        printf("Enter valid mail with @ & .com");
    }
    }
    else
    printf("Enter the number from 1 to upto 3");
}
void initialize(AddressBook *addressBook)
{
    addressBook->contactCount = 0;
   // populateAddressBook(addressBook);
    loadContactsFromFile(addressBook);
}
void saveAndExit(AddressBook *addressBook)
{
   	exit(EXIT_SUCCESS);
}
int mobile_validation(char *mobile_num)//function for mobile number validation
{
   int i,x=0,flag=0;
   for(i=0;mobile_num[i]!='\0';i++)
   {
    if(mobile_num[i]>='0' && mobile_num[i]<='9')
    {
        x++;
    }
    else
    flag=1;
   } 
   if(flag==1)
   {
    printf("Please Enter only integers");
    return 0;
   }
   else
   {
      if(x!=10)
      return 0;
      else
      return 1;
   }  
}
int len(char *str)//function to find length of a string
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {

    }
    return i;
}
int mail_validation(char *email)//function to find email from user
{
    if(email[0]=='@')//if mail starts with @ it is not valid
    return 0;
    char *ret1 = strchr(email, '@');//checking wether the mail has @ or not
    char *ret2 = strstr(email, ".com");//checking wether mail has .com extension or not
    char *ret3 =strstr(email,"@.com");//checking wether mail has @.com extension
    if (ret1 == NULL || ret2 == NULL|| ret3!=NULL)//checking all the conditions for mail
        return 0;
    if(*(ret2+4)!='\0')
        return 0;
    else
  return 1;
}
