#include <stdio.h>
#include <stdlib.h>
// creating a node
struct node
{
    int data;
    struct node *next; // struct node type ka next pointer
};
struct node *head = 0, *newnode, *temp;
void lastinsert()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    int item;
    printf("Enter a number to insert : \n");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    if (head == 0)
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}
void beginsert()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter value to be inserten in begining :\n");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}

void display()
{
    temp = head;
    if (head == 0)
    {
        printf("The list is empty");
    }
    else
    {

        printf("\nPrinting values ...");
        while (temp != 0)
        {
            printf("%d", temp->data);
            printf(",");

            temp = temp->next;
        }
    }
}

void begin_delete()
{
    if (head == 0)
    {
        printf("The list is empty\n");
    }
    else
    {
        temp = head;
        head = temp->next;
        free(temp);
        printf("Node deleted from begining.\n");
    }
}

void last_delete()
{
    struct node *previous_temp;
    if (head == 0)
    {
        printf("The list is empty\n");
    }
    else if (head->next == 0)
    {
        head = 0;
        free(head);
        printf("Deleted node from last \n");
    }
    else
    {
        temp = head;
        previous_temp = 0;
        while (temp->next != 0)
        {
            previous_temp = temp;
            temp = temp->next;
        }
        previous_temp->next = 0;
        free(temp);
        printf("Deleted node from last \n");
    }
}
void renorm_insert()
{
    // struct node *temp;
    int iteam, location = 0;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (head == 0)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("Enter value you want to insert\n");
        scanf("%d", &iteam);
         newnode->data = iteam;
        printf("Enter location\n");
        scanf("%d", &location);
        temp = head;
        for (int i = 1; i < location; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("Cant insert\n");
                return;
            }
           
        }
         newnode->next = temp->next;
            temp->next = newnode;
    }
}

void search()
{
    int iteam, flag = 1, location = 0;
    printf("Enter the element to search :\t");
    scanf("%d", &iteam);
    temp = head;
    if (head == 0)
    {
        printf("List is empty.");
    }
    while (temp->next != 0)
    {
        if ((temp->data) == iteam)
        {
            printf("Iteam is found at location %d", location + 1);
            flag = 0;
            return;
        }
        else
        {
            location++;
            temp = temp->next;
        }
    }
    if (flag == 1)
    {
        printf("Iteam not found\n");
    }
}

int main()
{

    int choice = 0;
    while (choice != 8)
    {
        printf("\n\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert at last\n2.display\n3.beginsert\n4.begin_delete\n5.last_delete\n6.search\n7.rendorm_insert\n8.Exit");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
        {
            lastinsert();
            break;
        }
        case 2:
        {
            display();
            break;
        }
        case 3:
        {
            beginsert();
            break;
        }
        case 4:
        {
            begin_delete();
            break;
        }
        case 5:
        {
            last_delete();
            break;
        }
        case 6:
        {
            search();
            break;
        }
        case 7:
        {
            renorm_insert();
            break;
        }
        default:
            printf("Please enter valid choice..");
        } //test
    }
    return 0;
}