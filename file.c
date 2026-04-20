
#include <stdio.h>
#include "file.h"
#include<string.h>
#include<stdlib.h>
void saveContactsToFile(AddressBook *addressBook) 
{
    int x;
    printf("Are you want to save the contact details:\n");
    printf("1.YES\n2.NO\n");
    scanf("%d",&x);
   // printf("\n");
    if(x==1)
    {
    FILE *save=fopen("contact.csv","w+");//creating contact.csv file and writing user created contacts to it
    if(save == NULL)//validating is file present or not if not it is going to create new file
    {
        printf("File doesn't exsits... & creating new file\n");
        return;
    }
    fprintf(save,"%d\n",addressBook->contactCount);
    for(int i=0;i<addressBook->contactCount;i++)
        fprintf(save,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    fclose(save);
    printf("Contact saved successfully");
    }
    else if(x==2)
	exit(EXIT_SUCCESS);
}
void loadContactsFromFile(AddressBook *addressBook) 
{
    FILE *load_c = fopen("contact.csv", "r");
    if (load_c == NULL)
    {
        printf("File is not present\n");
        return;
    }
   fscanf(load_c,"%d\n", &addressBook->contactCount);
    for (int i = 0; i < addressBook->contactCount; i++)
     {
        char line[300];
        fgets(line,300, load_c);
	    char *token=strtok(line,",");//for name 
	    if(token!=NULL)
	    strcpy(addressBook->contacts[i].name,token);
        token=strtok(NULL,",");//copying name into .csv extension file
	    if(token!=NULL)
	    strcpy(addressBook->contacts[i].phone,token);
        token=strtok(NULL,"\n");
	    if(token!=NULL)
	    strcpy(addressBook->contacts[i].email,token);
       // sscanf(line, "%[^,],%[^,],%[^\n]",addressBook->contacts[i].name, addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(load_c);
}
