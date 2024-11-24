:#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Employee structure with ID, name, and department
typedef struct employee {
    int emp_id;
    char name[50];
    char department[50];
} EMPLOYEE;

// Node structure to hold an employee record and pointer to the next node
typedef struct node {
    EMPLOYEE emp;
    struct node *next; // Self-referential pointer (Self/SRP)
} NODE;

NODE* createNode(NODE*);
int dispMainMenu();
void printList(NODE*);
NODE* appendNode(NODE*, NODE*);
NODE* addNodeBeg(NODE*, NODE*);
int delNode(NODE*, int);

int main() {
    NODE *nn = NULL;
    NODE *head = NULL, *temp = NULL;
    int flag = 0;
    int emp_id = 0;

    while (1) {
        switch (dispMainMenu()) {
            case 1:
                nn = createNode(nn);
                head = addNodeBeg(head, nn);
                free(nn);
                break;
            case 2:
                nn = createNode(nn);
                head = appendNode(head, nn);
                free(nn);
                break;
            case 3:
                printf("\nEnter the Employee ID to delete: ");
                scanf("%d", &emp_id);
                delNode(head, emp_id);
                break;
            case 4:
                printList(head);
                break;
            case 5:
                flag = 1;
                break;
            default:
                printf("\nEnter the correct Choice\n");
                break;
        }
        if (flag == 1) break;
    }

    printf("\n\n");
    return 0;
}

// Create a new node for an employee record
NODE* createNode(NODE *nn) {
    nn = (NODE *)malloc(sizeof(NODE));
    printf("\nEnter Employee ID: ");
    scanf("%d", &nn->emp.emp_id);
    printf("Enter Employee Name: ");
    getchar(); 
    fgets(nn->emp.name, 50, stdin);e=
    nn->emp.name[strcspn(nn->emp.name, "\n")] = 0; 
    printf("Enter Employee Department: ");
    fgets(nn->emp.department, 50, stdin);
    nn->emp.department[strcspn(nn->emp.department, "\n")] = 0;
    nn->next = NULL;
    return nn;
}

// Display the menu
int dispMainMenu() {
    int ch;
    printf("\nEmployee Records Menu\n");
    printf("\nPress,");
    printf("\n1. Add Employee at Beginning");
    printf("\n2. Add Employee at End");
    printf("\n3. Delete an Employee");
    printf("\n4. Print Employee List");
    printf("\n5. Exit");
    printf("\nChoice: ");
    scanf("%d", &ch);
    return ch;
}

// Print all employee records
void printList(NODE *head) {
    if (head == NULL) {
        printf("\nList is Empty\n");
        return;
    }
    printf("\nEmployee List\n===================================\n");
    while (head != NULL) {
        printf("ID: %d, Name: %s, Department: %s\n", head->emp.emp_id, head->emp.name, head->emp.department);
        head = head->next;
    }
    printf("\n===================================\n");
}

// Add a new employee record at the end of the list
NODE* appendNode(NODE *head, NODE *nn) {
    NODE *temp = head;

    if (head == NULL) {
        head = nn; // If list is empty, make the new node the head
    } else {
        while (head->next != NULL) {
            head = head->next;
        }
        head->next = nn; // Add new node at the end of the list
    }

    return temp;
}

// Add a new employee record at the beginning of the list
NODE* addNodeBeg(NODE *head, NODE *nn) {
    if (head == NULL) {
        head = nn; // If list is empty, the new node becomes the head
    } else {
        nn->next = head; // Point the new node to the current head
        head = nn;        // Make the new node the head
    }
    return head;
}

// Delete an employee record by employee ID
int delNode(NODE *head, int emp_id) {
    NODE *temp = head;
    NODE *prev = NULL;
    int flag = 1;

    while (head != NULL) {
        if (head->emp.emp_id == emp_id) {
            flag = 0;
            if (prev == NULL) {
                // If the node to delete is the first node
                head = head->next;
            } else {
                prev->next = head->next;
            }
            free(head); // Free the memory of the deleted node
            printf("\nEmployee with ID %d has been deleted.\n", emp_id);
            break;
        }
        prev = head;
        head = head->next;
    }

    if (flag) {
        printf("\nEmployee with ID %d not found.\n", emp_id);
    }

    return flag;
}










int printDetails(EMP *e)
 {
      printf("\nEmployee Details are\n");
      printf("\n===============================\n");
      printf("\nID: %d",e->id);
      printf("\nName: %s",e->Name);
      printf("\nGender: %c",e->g);
      printf("\nPhNo: %d",e->phno);
      printf("\nSalary: %d",e->sal);
      printf("\n===============================\n");
  }











                                                                                                                                           
void printList(EMP *head)
 68 {
 69
 70     if(head == NULL)
 71     {
 72         //the list is empty
 73         printf("\nList is Empty\n");
 74         return;
 75     }
 76     printf("\nList is\n===================================\n");
 77     while(head!= NULL)
 78     {
 79         // printf("%d->",head->val);
 80         printDetails(head);
 81         head = head->next;
 82     }
 83     printf("\nEND OF Records\n");
 84     printf("\n\n===================================\n");



without using scanf in printList we can use another printDetails function and pass this function in printList.







                                                                                                                                           