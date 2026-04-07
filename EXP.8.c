#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct node{
	int vertex;
	struct node* next;
}*GNODE;
GNODE graph[MAX];
void insertvertex(int*N);
void insertEdge(int*N);
void deleteVertex(int*N);
void deleteEdge(int*N);
void print(int*N);
void print(int*N){
	for(int i=1;i<=*N;i++){
		if(graph[i]!=NULL){
			printf("%d=>",i);
			GNODE temp=graph[i];
			while(temp!=NULL){
				printf("%d\t",temp->vertex);
							  temp=temp->next;
			}
			printf("\n");
		}
	}
}

void insertVertex(int * N) {
	(*N)++;
	graph[*N]=NULL;
	printf("Vertex %d inserted.\n",*N);
}

void insertEdge(int *N) {
	int src,des;
	GNODE q,p;
	printf("Enter the source vertex of the edge : ");
	scanf("%d",&src);
	printf("Enter the destination vertex of the edge : ");
	scanf("%d",&des);
	if(src>*N || des>=*N || src<=0 || des<=0){
		printf("Invalid vertex.\n");
	}
	GNODE newNode=(GNODE)malloc(sizeof(struct node));
	newNode->vertex=des;
	newNode->next=NULL;
	if(graph[src]==NULL)
		graph[src]=newNode;
	else{
		GNODE temp=graph[src];
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newNode;
	}
	printf("After inserting edge the adjacency list is : \n");
	print(N);
}

void deleteVertex(int *N){
	int v;
	printf("Enter the vertex to be deleted : ");
	scanf("%d",&v);
	if(v>*N || v<=0){
		printf("Invalid vertex.\n");
		return;
	}
	GNODE temp;
	while(graph[v]!=NULL){
		temp=graph[v];
		graph[v]=graph[v]->next;
		free(temp);
	}
	graph[v]=NULL;
	for(int i=1;i<*N;i++){
		if(graph[i]==NULL)continue;
		GNODE curr=graph[i],prev=NULL;
		while(curr!=NULL){
			if(curr->vertex==v){
				if(prev==NULL)
					graph[i]=curr->next;
				else prev->next=curr->next;
				free(curr);
				break;
			}
			prev=curr;
			curr=curr->next;
		}
	}
	printf("After deleting vertex the adjacency list is : \n");
	print(N);
}

void deleteEdge(int *N) {
	int src,des;
	printf("Enter the source vertex of the edge : ");
	scanf("%d",&src);
	printf("Enter the destination vertex of the edge : ");
	scanf("%d",&des);
	if(src>*N || des>*N || src<=0 || des<0 || graph[src]==NULL){
		printf("Invalid edge.\n");
		return;
	}
	GNODE curr=graph[src],prev=NULL;
	while(curr!=NULL && curr->vertex!=des){
		prev=curr;
		curr=curr->next;
	}
	if(curr==NULL){
		printf("Edge not found.\n");
		return;
	}
	if(prev==NULL)
		graph[src]=curr->next;
	else
		prev->next=curr->next;
	free(curr);
	printf("After deleting edge the adjacency list is : \n");
	print(N);
}
