  1 #include <stdio.h>
  2 #include <stdlib.h>
  3 #include <string.h>
  4
  5 // Employee structure with ID, name, and department
  6 typedef struct employee {
  7     int emp_id;
  8     char name[50];
  9     char department[50];
 10 } EMPLOYEE;
 11
 12 // Node structure to hold an employee record and pointer to the next node
 13 typedef struct node {
 14     EMPLOYEE emp;
 15     struct node *next; // Self-referential pointer (Self/SRP)
 16 } NODE;
 17
 18 NODE* createNode(NODE*);
 19 int dispMainMenu();
 20 void printList(NODE*);
 21 NODE* appendNode(NODE*, NODE*);
 22 NODE* addNodeBeg(NODE*, NODE*);
 23 int delNode(NODE*, int);
 24
 25 int main() {
 26     NODE *nn = NULL;
 27     NODE *head = NULL, *temp = NULL;
 28     int flag = 0;
 29     int emp_id = 0;
 30
 31     while (1) {
 32         switch (dispMainMenu()) {
 33             case 1:
 34                 nn = createNode(nn);
 35                 head = addNodeBeg(head, nn);
 36                 free(nn);
 37                 break;
 38             case 2:
 39                 nn = createNode(nn);
 40                 head = appendNode(head, nn);
 41                 free(nn);
 42                 break;
 43             case 3:
 44                 printf("\nEnter the Employee ID to delete: ");
 45                 scanf("%d", &emp_id);
 46                 delNode(head, emp_id);
 47                 break;
 48             case 4:
 49                 printList(head);
 50                 break;
 51             case 5:
 52                 flag = 1;
 53                 break;
 54             default:
 55                 printf("\nEnter the correct Choice\n");
 56                 break;
 57         }
 58         if (flag == 1) break;
 59     }
 60
 61     printf("\n\n");
 62     return 0;
 63 }
 64
 65 // Create a new node for an employee record
 66 NODE* createNode(NODE *nn) {
 67     nn = (NODE *)malloc(sizeof(NODE));
 68     printf("\nEnter Employee ID: ");
 69     scanf("%d", &nn->emp.emp_id);
 70     printf("Enter Employee Name: ");
 71     getchar();
 72     fgets(nn->emp.name, 50, stdin);
 73     nn->emp.name[strcspn(nn->emp.name, "\n")] = 0;
 74     printf("Enter Employee Department: ");
 75     fgets(nn->emp.department, 50, stdin);
 76     nn->emp.department[strcspn(nn->emp.department, "\n")] = 0;
 77     nn->next = NULL;
 78     return nn;
 79 }
 80
 81 // Display the menu
 82 int dispMainMenu() {
 83     int ch;
printf("\nEmployee Records Menu\n");
 85     printf("\nPress,");
 86     printf("\n1. Add Employee at Beginning");
 87     printf("\n2. Add Employee at End");
 88     printf("\n3. Delete an Employee");
 89     printf("\n4. Print Employee List");
 90     printf("\n5. Exit");
 91     printf("\nChoice: ");
 92     scanf("%d", &ch);
 93     return ch;
 94 }
 95
 96 int  printDetails(Employee *e)
 97  {
 98       printf("\nEmployee Details are\n");
 99       printf("\n===============================\n");
100       printf("\nID: %d",e->id);
101       printf("\nName: %s",e->Name);
102       printf("\nGender: %c",e->g);
103       printf("\nPhNo: %d",e->phno);
104       printf("\nSalary: %d",e->sal);
105       printf("\n===============================\n");
106
107      return 0;
108   }
109
110 // Print all employee records
111 void printList(NODE *head) {
112     if (head == NULL) {
113         printf("\nList is Empty\n");
114         return;
115     }
116     printf("\nEmployee List\n===================================\n");
117     while (head != NULL) {
118         printDetails(head);
119         head = head->next;
120     }
121     printf("\n===================================\n");
122 }
123
124 // Add a new employee record at the end of the list
125 NODE* appendNode(NODE *head, NODE *nn) {
 NODE *temp = head;
127
128     if (head == NULL) {
129         head = nn; // If list is empty, make the new node the head
130     } else {
131         while (head->next != NULL) {
132             head = head->next;
133         }
134         head->next = nn; // Add new node at the end of the list
135     }
136
137     return temp;
138 }
139
140 // Add a new employee record at the beginning of the list
141 NODE* addNodeBeg(NODE *head, NODE *nn) {
142     if (head == NULL) {
143         head = nn; // If list is empty, the new node becomes the head
144     } else {
145         nn->next = head; // Point the new node to the current head
146         head = nn;        // Make the new node the head
147     }
148     return head;
149 }
150
151 // Delete an employee record by employee ID
152 int delNode(NODE *head, int emp_id) {
153     NODE *temp = head;
154     NODE *prev = NULL;
155     int flag = 1;
156
157     while (head != NULL) {
158         if (head->emp.emp_id == emp_id) {
159             flag = 0;
160             if (prev == NULL) {
161                 // If the node to delete is the first node
162                 head = head->next;
163             } else {
164                 prev->next = head->next;
165             }
166             free(head); // Free the memory of the deleted node
167             printf("\nEmployee with ID %d has been deleted.\n", emp_id);
168             break;
169         }
170         prev = head;
171         head = head->next;
172     }
173
174     if (flag) {
175         printf("\nEmployee with ID %d not found.\n", emp_id);
176     }
177
178     return flag;
179 }
                    