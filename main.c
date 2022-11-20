/* Name: Ahmet Sezer AKDENÝZ , Number: 190254006 Ders: COM 201_HW_1 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct HospitalList {
    char firstLetter;
    struct Record *firstRecordPtr;
};

struct Record {
    char name[50];
    char surname[50];
    int personId;
    char polyclinic[50];
    struct Record *nextRecord;
 };

 typedef struct Record node;

 void firstLetter(struct HospitalList patientList[]){
    int i=0;
    int c ='a';
    for(c ='a';c<='z';c++,i++){
        patientList[i].firstLetter = c;
        patientList[i].firstRecordPtr = NULL;
    }
}

 node * addRecord(node * head){
     node * rec =(node * )malloc(sizeof(node));
     node *temp = head;
     printf("Name: "); scanf("%s",&rec->name);
     printf("Surname: "); scanf("%s",&rec->surname);
     printf("Person ID: "); scanf("%d",&rec->personId);
     printf("Polyclinic: Orthodontics - Endoscopy - Implant - Cardiology\n "); scanf("%s",&rec->polyclinic);

     if(head == NULL){
        head = rec;
        head->nextRecord = NULL;
        printf("list created, first record added \n");
     }
     else{
        while(temp->nextRecord != NULL){
            temp=temp->nextRecord;
        }
        temp->nextRecord=rec;
        rec->nextRecord = NULL;
        printf("Record added\n");
     }

     return head;
 }

 node * deleteRecord(node * head){
     int r;
     printf("How would you like to delete?\n");
     printf("1->Delete by name\n");
     printf("2->Delete by surname\n");
     printf("3->Delete by polyclinic name\n");
     scanf("%d",&r);

     if(r==1){
        if(head != NULL){
        char recname[50];
        struct Record *temp, *prev;
        temp=head;

        printf("What is the name you wish to delete? : ");
        scanf("%s", recname);
        while(temp->nextRecord != NULL){
            temp = temp->nextRecord;
            if(strcmp(recname, temp->name)==0){
            break;
            }
            prev = temp;
        }

        if ( temp != NULL ){
            if ( temp == head ){
                head = temp->nextRecord;
            }
            else{
            prev->nextRecord = temp->nextRecord;
            }

         free(temp);
         printf("%s was deleted successfully\n", recname);
        }
     }
     else{
        printf("Records not found\n");
     }
     }
     if(r==2){
        if(head != NULL){
        char recsurname[50];
        struct Record *temp, *prev;
        temp=head;

        printf("What is the surname you wish to delete? : ");
        scanf("%s", recsurname);
        while(temp->nextRecord != NULL){
            temp = temp->nextRecord;
            if(strcmp(recsurname, temp->surname)==0){
            break;
            }
            prev = temp;
        }

        if ( temp != NULL ){
            if ( temp == head ){
                head = temp->nextRecord;
            }
            else{
            prev->nextRecord = temp->nextRecord;
            }

         free(temp);
         printf("%s was deleted successfully\n", recsurname);
        }
     }
     else{
        printf("Records not found\n");
     }

     }

     if(r==3){
        if(head != NULL){
        char recpolyclinic[50];
        struct Record *temp, *prev;
        temp=head;

        printf("What is the polyclinic name you wish to delete? : ");
        scanf("%s", recpolyclinic);
        while(temp->nextRecord != NULL){
            temp = temp->nextRecord;
            if(strcmp(recpolyclinic, temp->polyclinic)==0){
            break;
            }
            prev = temp;
        }

        if ( temp != NULL ){
            if ( temp == head ){
                head = temp->nextRecord;
            }
            else{
            prev->nextRecord = temp->nextRecord;
            }

         free(temp);
         printf("First record in %s polyclinic deleted\n", recpolyclinic);
        }
     }
     else{
        printf("Records not found\n");
     }
     }

     return head;
}

 node * printRecord(node * head){

     system("cls");
     if(head==NULL){
        printf("list is empty\n");
     }
     else{
        node *temp = head;
        while(temp->nextRecord != NULL){
            printf("Name : %s \t Surname : %s \t PersonID : %d \t Polyclinic: %s \n", temp->name, temp->surname, temp->personId, temp->polyclinic);
            temp = temp->nextRecord;
        }
        printf("Name : %s \t Surname : %s \t PersonID : %d \t Polyclinic: %s \n", temp->name, temp->surname, temp->personId, temp->polyclinic);
     }
     return head;
 }

 node * searchName(node * head, char name[50]){
        system("cls");
        if(head == NULL){
        printf("list is empty \n");
        }
        else{
        char recname[50];
        strcpy(recname,name);
        node *temp =head;
        while(temp != NULL){
            if(strcmp(temp->name,recname) == 0){
                printf("patient information: \n");
                printf("Name        : %s\n", temp->name);
                printf("Surname     : %s\n", temp->surname);
                printf("Person ID   : %d\n", temp->personId);
                printf("Polyclinic  : %s\n", temp->polyclinic);
            }
            temp= temp->nextRecord;
        }
    }
    return head;
}

 node * searchSurname(node * head, char surname[50]){
        system("cls");
        if(head == NULL){
        printf("list is empty \n");
        }
        else{
        char recsurname[50];
        strcpy(recsurname,surname);
        node *temp =head;
        while(temp != NULL){
            if(strcmp(temp->surname,recsurname) == 0){
                printf("patient information: \n");
                printf("Name        : %s\n", temp->name);
                printf("Surname     : %s\n", temp->surname);
                printf("Person ID   : %d\n", temp->personId);
                printf("Polyclinic  : %s\n", temp->polyclinic);
            }
            temp= temp->nextRecord;
        }
    }
    return head;
}

 node * searchPolyclinic(node  * head, char polyclinic[50]){
        system("cls");
        if(head == NULL){
        printf("list is empty \n");
        }
        else{
        char recpolyclinic[50];
        strcpy(recpolyclinic,polyclinic);
        node *temp =head;
        while(temp != NULL){
            if(strcmp(temp->polyclinic,recpolyclinic) == 0){
                printf("patient information: \n");
                printf("Name        : %s\n", temp->name);
                printf("Surname     : %s\n", temp->surname);
                printf("Person ID   : %d\n", temp->personId);
                printf("Polyclinic  : %s\n", temp->polyclinic);
            }
            temp= temp->nextRecord;
        }
    }

    return head;
}

 int recordsNum(node * head){
    node *temp = head;
    int number=0;
    if(head==NULL)
    {
        return number;
    }
    else
    {
        temp=head;
        while(temp->nextRecord != NULL)
        {
            temp=temp->nextRecord;
            number++;
        }
        number++;
        return number;
    }
}

int main()
{
    char c;
    int r;
    char recname[50];
    char recsurname[50];
    char polyclinic[50];
    int choice,x;
    node *head = NULL;
    while(1)
    {
        printf("\n1->Add New Record\n");
        printf("2->Search Record\n");
        printf("3->Delete Record \n");
        printf("4->Sort Records By Name\n");
        printf("5->Sort Records By Surname\n");
        printf("6->Sort Records By Polyclinic Name\n");
        printf("7->To print the list\n");
        printf("8->Number of records\n");
        printf("9->to exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: head = addRecord(head);
            break;
            case 2: printf("How would you like to search?\n");
                    printf("1->Search by name\n");
                    printf("2->Search by surname\n");
                    printf("3->Search by polyclinic name\n");
                    scanf("%d",&r);
                    if(r==1){
                        printf("Patient name: ");
                        scanf("%s", &recname);
                        head = searchName(head, recname);
                    }
                    else if(r==2){
                        printf("Patient surname: ");
                        scanf("%s", &recsurname);
                        head = searchSurname(head, recsurname);
                    }
                    else if (r==3){
                        printf("Patient polyclinic name: ");
                        scanf("%s", &polyclinic);
                        head = searchPolyclinic(head, polyclinic);
                    }
            break;
            case 3: head = deleteRecord(head);
            break;
            case 7: head = printRecord(head);
            break;
            case 8: x = recordsNum(head);
                    printf("Number of  records : %d",x);
            break;
            case 9:
            return 0;
            break;
            case 0:
            default : printf("error\n");
        }
    }
}
