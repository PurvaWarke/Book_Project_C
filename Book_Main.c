#include<stdio.h>
#include<string.h>

int ctr=0;
typedef struct Liabrary
{
	int book_id;
	char book_name[50];
	char book_author[50];
	char book_category[50];
	int price;
	int rating;
}Liabrary;

void hardCodedData(Liabrary*);
void storeData(Liabrary*,int);
void displayData(Liabrary*);
void searchBook(Liabrary*);
int searchByBid(Liabrary*,int);
int searchByBName(Liabrary*,char*);
int searchByBAuthor(Liabrary*,char*);
int searchByBCategory(Liabrary*,char*);
void deleteBook(Liabrary*);
void updateLiabrary(Liabrary*);
void sortingBook(Liabrary*);
void sortByPrice(Liabrary*);
void sortByRating(Liabrary*);

void main()
{
	int arr_size=50;
	Liabrary arr[arr_size];
	hardCodedData(arr);
	int choice;
	do
	{
		printf("\n------ Liabrary Management System ------\n\n");
		printf("\t1.Add Book \n\t2.Display Books \n\t3.Search Book \n\t4.Delete Book \n\t5.Update Book \n\t6.Sorting Books \n\t7.Exit\n");
		
		printf("\nEnter Choice : ");
		scanf("%d",&choice);
	
		switch(choice)
		{
			case 1:
			{
				storeData(arr,arr_size);
				break;	
			}
			case 2:
			{
				displayData(arr);
				break;	
			}
			case 3:
			{
				searchBook(arr);
				break;	
			}
			case 4:
			{
				deleteBook(arr);
				break;	
			}
			case 5:
			{
				updateLiabrary(arr);
				break;	
			}
			case 6:
			{
				sortingBook(arr);
				break;	
			}
			case 7:	
			{
				printf("Exiting Program. Thank You !\n");
				break;	
			}
			default:
			{
				printf("\nPlease Enter Valid Choice !");
			}
		}
	}while(choice!=7);
}

void storeData(Liabrary* arr,int arr_size)
{
	if(ctr<arr_size)
		{
			printf("\nEnter Number of Book : ");
			scanf("%d",&arr[ctr].book_id);
			printf("\nEnter Name of Book : ");
			scanf("%s",arr[ctr].book_name);
			printf("\nEnter Author of Book : ");
			scanf("%s",arr[ctr].book_author);
			printf("\nEnter Category of Book : ");
			scanf("%s",arr[ctr].book_category);
			printf("\nEnter Price of Book : ");
			scanf("%d",&arr[ctr].price);
			printf("\nEnter Rating of Book : ");
			scanf("%d",&arr[ctr].rating);
			ctr++;
		}
		printf("\nBook Added Successfully !! \n");	
}
void displayData(Liabrary* arr)
{
	printf("---------------------------------------------------------------------------------------------------------");
	printf("\nB_No |\tBook Name\t|\tBook Author\t|\tBook Category\t|\tPrice  \t|\tRating \t|\n");
	printf("---------------------------------------------------------------------------------------------------------");
	for(int i=0;i<ctr;i++)
	{
		printf("\n%-5d|\t%-16s|\t%-16s|\t%-16s|\t%-8d|\t%-8d|",arr[i].book_id,arr[i].book_name,arr[i].book_author,arr[i].book_category,arr[i].price,arr[i].rating);
	}
	printf("\n---------------------------------------------------------------------------------------------------------\n");
	
}
void searchBook(Liabrary* arr)
{
	int choice;
	printf("\n------ Liabrary Management System ------\n\n");
	printf("\n-1.Search By Book Id \n-2.Search By Book Name \n-3.Search By Book Author \n-4.Search By Book Category \n-5.Back");

	
	do{
		printf("\n\nEnter Choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					int bid;
					printf("\nEnter Book Id Want to Search : ");
					scanf("%d",&bid);
					int res = searchByBid(arr,bid);
					if(res==-1)
						printf("\n%d Book Not Exists !!",bid);
					else
					{
						printf("---------------------------------------------------------------------------------------------------------");
						printf("\nB_No |\tBook Name\t|\tBook Author\t|\tBook Category\t|\tPrice  \t|\tRating \t|\n");
						printf("---------------------------------------------------------------------------------------------------------");
						printf("\n%-5d|\t%-16s|\t%-16s|\t%-16s|\t%-8d|\t%-8d|",arr[res].book_id,arr[res].book_name,arr[res].book_author,arr[res].book_category,arr[res].price,arr[res].rating);
						printf("\n---------------------------------------------------------------------------------------------------------\n");
					}
					break;
				}
			case 2:
				{
					char str[50];
					printf("\nEnter Book Name Want to Search : ");
					scanf("%s",str);
					int res = searchByBName(arr,str);
					if(res==-1)
						printf("\n%s Book Not Exists !! ",str);
					else
					{
						printf("---------------------------------------------------------------------------------------------------------");
						printf("\nB_No |\tBook Name\t|\tBook Author\t|\tBook Category\t|\tPrice  \t|\tRating \t|\n");
						printf("---------------------------------------------------------------------------------------------------------");
						printf("\n%-5d|\t%-16s|\t%-16s|\t%-16s|\t%-8d|\t%-8d|",arr[res].book_id,arr[res].book_name,arr[res].book_author,arr[res].book_category,arr[res].price,arr[res].rating);
						printf("\n---------------------------------------------------------------------------------------------------------\n");
					}
					break;	
				}
			case 3:
				{
					char str[50];
					printf("\nEnter Book Author Want to Search : ");
					scanf("%s",str);
					int res = searchByBAuthor(arr,str);
					if(res==-1)
						printf("\n%s Author's Book Not Exists !! ",str);
					else
					{
						printf("---------------------------------------------------------------------------------------------------------");
						printf("\nB_No |\tBook Name\t|\tBook Author\t|\tBook Category\t|\tPrice  \t|\tRating \t|\n");
						printf("---------------------------------------------------------------------------------------------------------");
						printf("\n%-5d|\t%-16s|\t%-16s|\t%-16s|\t%-8d|\t%-8d|",arr[res].book_id,arr[res].book_name,arr[res].book_author,arr[res].book_category,arr[res].price,arr[res].rating);
						printf("\n---------------------------------------------------------------------------------------------------------\n");
					}
					break;
				}
			case 4:
				{
					char str[50];
					printf("\nEnter Book Category Want to Search : ");
					scanf("%s",str);
					int res = searchByBCategory(arr,str);
					if(res==-1)
						printf("\nBook from %s Category Not Exists !! ",str);
					else
					{
						printf("---------------------------------------------------------------------------------------------------------");
						printf("\nB_No |\tBook Name\t|\tBook Author\t|\tBook Category\t|\tPrice  \t|\tRating \t|\n");
						printf("---------------------------------------------------------------------------------------------------------");
						printf("\n%-5d|\t%-16s|\t%-16s|\t%-16s|\t%-8d|\t%-8d|",arr[res].book_id,arr[res].book_name,arr[res].book_author,arr[res].book_category,arr[res].price,arr[res].rating);
						printf("\n---------------------------------------------------------------------------------------------------------\n");
					}
					break;
				}
			case 5:
				{
					printf("\nYou Entered Back !\n");
					break;
				}
			default:
				{
					printf("\nPlease Enter Valid Choice !");
				}
		}
	}while(choice!=5);
}
int searchByBid(Liabrary* arr,int bid)
{
	int flag=0;
	for(int i=0;i<ctr;i++)
	{
		if(arr[i].book_id==bid)
		{
			flag=1;
			return i;
		}
	}
	if(flag==0)
		return -1;
}
int searchByBName(Liabrary* arr,char* str)
{
	for(int i=0;i<ctr;i++)
	{
		if(strcmp(arr[i].book_name,str)==0)
			return i;
	}
	return -1;
}
int searchByBAuthor(Liabrary* arr,char* str)
{
	for(int i=0;i<ctr;i++)
	{
		if(strcmp(arr[i].book_author,str)==0)
			return i;
	}
	return -1;
}
int searchByBCategory(Liabrary* arr,char* str)
{
	for(int i=0;i<ctr;i++)
	{
		if(strcmp(arr[i].book_category,str)==0)
			return i;
	}
	return -1;
}
void deleteBook(Liabrary* arr)
{
	int delete_book;
	printf("\nEnter Book Id want to Delete : ");
	scanf("%d",&delete_book);
	int flag=0;
	for(int i=0;i<ctr;i++)
	{
		if(arr[i].book_id==delete_book)
		{
			arr[i]=arr[i+1];
			flag=1;
			ctr=ctr-1;
			printf("\nBook Deleted Succesfully !\n");
		}
		else if(flag==1)
			arr[i]=arr[i+1];			
	}
	if(flag==0)
		printf("\n%d Book Not Exists !!",delete_book);
	displayData(arr);	
}
void updateLiabrary(Liabrary* arr)
{
	
}
void sortingBook(Liabrary* arr)
{
		int choice;
	printf("\n\n------ Player Management System ------\n");
	printf("\n-1.Sort By Price of Books \n-2.Sort By Rating of Book \n-3.Back\n");
	
	do{
		printf("\nEnter Choice : ");
		scanf("%d",&choice);
	
		switch(choice)
		{
			case 1:
				{
					sortByPrice(arr);
					break;	
				}
			case 2:
				{
					sortByRating(arr);
					break;	
				}
			case 3:
				{
					printf("\nYou Entered Back !!\n");	
					break;
				}
			default:
				{
					printf("\nPlease Enter Valid Choice !");
				}
		}
	}while(choice!=3);
}
void sortByPrice(Liabrary* arr)
{
	for(int i=0;i<ctr;i++)
	{
		for(int j=i+1;j<ctr;j++)
		{
			if(arr[i].price>arr[j].price)
			{
				Liabrary temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}
	}
	displayData(arr);
}
void sortByRating(Liabrary* arr)
{
	for(int i=0;i<ctr;i++)
	{
		for(int j=i+1;j<ctr;j++)
		{
			if(arr[i].rating>arr[j].rating)
			{
				Liabrary temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}
	}
	displayData(arr);
}
void hardCodedData(Liabrary* arr)
{
	arr[0].book_id=7;
	strcpy(arr[0].book_name,"Atomic_Habits");
	strcpy(arr[0].book_author,"James_Clear");
	strcpy(arr[0].book_category,"Motivational");
	arr[0].price=299;
	arr[0].rating=5;
	ctr++;
	
	arr[1].book_id=3;
	strcpy(arr[1].book_name,"Let_us_C");
	strcpy(arr[1].book_author,"Y_Kanetkar");
	strcpy(arr[1].book_category,"Programming");
	arr[1].price=399;
	arr[1].rating=4;
	ctr++;

	arr[2].book_id=8;
	strcpy(arr[2].book_name,"The_Histroies");
	strcpy(arr[2].book_author,"Herodotus");
	strcpy(arr[2].book_category,"Histrorial");
	arr[2].price=249;
	arr[2].rating=8;
	ctr++;
}