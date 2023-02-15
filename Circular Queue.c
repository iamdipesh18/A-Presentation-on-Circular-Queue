#include<stdio.h>   //HEADER FILE DECLARATION
#include<conio.h>
#include<stdlib.h>
#define maxsize 10  //SIZE DECLERATION 
int queue[maxsize]; //ARRAY DECLARATION
int front=-1;       //FRONT AND REAR DECLARATION
int rear=-1;
void enqueue(); //FUNCTION TO ENQUEUE
void dequeue(); //FUNCTION TO DEQUEUE
void display(); //FUNCTION TO DISPLAY
void main()      //MAIN FUNCTION
{
	int choice=1;
	while(choice<4 && choice!=0) //LOOP
	{
		printf("\n Press 1: Enqueue an element");  //INSERTING
        printf("\n Press 2: Dequeue an element");  //DELETING
        printf("\n Press 3: Display the Queue");  //DISPLAYING
        printf("\n Enter your choice ");  
        scanf("%d", &choice);
        switch (choice)
        {
        	case 1:
        		enqueue();
        		break;
        	case 2:
        		dequeue();
        		break;
        	case 3:
        		display();
        		break;
        	default:
        		exit(0);
		}
	}
	getch();
}
void enqueue()
{
	int element;
	printf("Enter the element \n");
	scanf("%d",&element);
	if(front==-1 && rear==-1)   // QUEUE EMPTY CONDITION CHECK  
    {  
        front=0;  
        rear=0;  
        queue[rear]=element;  
    }  
    else if((rear+1)%maxsize==front)  // QUEUE FULL CONDITION CHECK 
    {  
        printf("Queue is fulll");  
    }  
    else  
    {  
        rear=(rear+1)%maxsize;       // REAR IS INCREASED  
        queue[rear]=element;     // REAR ELEMENT IS ASSIGNED TO ELEMENT VARIABLE  
    }
}
 void dequeue()
{
	int element;
	if((rear==-1)&&(front==-1)) //EMPTY CONDITION CHECK
	{
		printf("Queue is empty");
	}
    else if(front==rear)
	{
		printf("The dequeued element is %d \n",queue[front]);
		front=-1;
		rear=-1;
	}	
    else
	{ 
		element=queue[front];
		printf("The dequed element is %d \n",element);
		front=(front+1)%maxsize;     	
	}
}
void display()
{
    int i=front;  
    if(front==-1 && rear==-1)  //EMPTY CONDITION CHECK
    {  
        printf("\nQueue is empty");  
    }  
    else  
    {  
        printf("\nElements in a Queue are : ");  
        while(i<=rear)  
        {  
            printf("%d\t", queue[i]);  
            i=(i+1)%maxsize;  
        }  
    } 
}
