
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max_Entries 300 // Number of max entries that can be there

struct Book
{
    char name[200];
    char author[200];
    char donor[200];
    char recievor[200];

};


void add();
void TestData(){

}


int main(){
    
struct Book books[Max_Entries]; // A list of Book is initialized
int index=0; //intial index
    

    while(1){ // infinite loop unless user says otherwise
    int choice;
    printf("Enter Your Choice:\n1. Add Record \n2. Delete Record\n3. Search Records\n4. Update Record\n5. Display All ecord\n0. Exit\n");
    scanf("%d",&choice);
    if(choice==0){
        break; // Exit Mechanism
    }
    switch(choice){
        case 1:{
        // We Start with initializing variables for every Field
        char name[200];
        char author[200];
        char donor[200];
        char recievor[200];
        //Then we take input from user for every field and push them into out records
        
        printf("Enter name of author : ");
        scanf("%[^\n]%*c", name);
        name[strcspn(name, "\n")] = '\0'; // remove trailing newline character
        printf("\n");
        
        printf("Enter name of author : ");
        scanf("%[^\n]%*c", author);
        author[strcspn(author, "\n")] = '\0'; // remove trailing newline character
        
        printf("Enter name of donor: ");
        scanf("%[^\n]%*c", donor);
        donor[strcspn(donor, "\n")] = '\0'; // remove trailing newline character
        
        printf("Enter name of recievor: ");
        scanf("%[^\n]%*c", recievor);
        recievor[strcspn(recievor, "\n")] = '\0'; // remove trailing newline character
        
         // push the data
         if(index==Max_Entries){
            printf("Max Entires Reached no more space left"); // safe check to make sure data doesn't overflow
         }
         else{
            strcpy(books[index].name, name);
            strcpy(books[index].author, author);
            strcpy(books[index].donor, donor);
            strcpy(books[index].recievor, recievor);
            index++;
         }
        break;
        }

        case 2:{
            int i;
            printf("Enter the index of record you want to Delete: ");
            scanf("%d",&i);
            for (int j = i; j < i - 1; j++) {
            books[i] = books[i + 1];
        }
        index--;
            printf("Record deleted.\n");
            break;
        }
       
        case 3:{
            char i[200];
            printf("Enter the name of Book you want to Search: ");
            fgets(i, sizeof(i), stdin);
            i[strcspn(i, "\n")] = '\0'; // remove trailing newline character
            int search_index = -1;
             for (int j = 0; j < index; j++) {
            if (strcmp(books[j].name, i) == 0) {
            search_index = j;
            break;
        }
    }

            if (search_index == -1) {
            printf("Author not found.\n");
        }
            else{
            printf("Book found at index: %i",search_index);
        }
            break;
        }

        case 4:{
            int choice;
            printf("Enter the number of record you want to update: ");
            scanf("%d",&choice);
            
            break;
        }
        case 5:{
            system("clear"); 
            printf("Records:\n\n");
            for (int i = 0; i < index; i++) {
            printf("Book Name: %s\nAuthor: %s\nDonor: %s\nRecievor: %s\n", books[i].name, books[i].author,books[i].donor,books[i].recievor);
            printf("\n\n"); // Intendation
            break;
    }
        }
    }
    
    
    }


}
