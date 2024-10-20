#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
////////////////////////////////////////list_start//////////////////////////////
struct listadd{       	//list head and tail
	struct node *head;
	struct node *tail;
};
typedef struct listadd list;

typedef list String;

struct node{			//node for the list
	int data;
	struct node *next;
	struct node *per;	
};

typedef struct node node;

struct listadd *L_create(){					//create a list(listass)
	list* lis=(struct listadd*)malloc(sizeof(struct listadd));
	lis->head=NULL;
	lis->tail=NULL;
	return lis;
}

struct node *no(node *n){                 	 			//create a node
	n=(struct node*)malloc(sizeof(struct node));
	n->next=NULL;
	n->per=NULL;
	return n;
}

void L_add(list *l,int num){						//add data
	if(l->head == NULL){
		node *n;
		n = no(n);
		n->data=num;
		l->head=n;
		l->tail=n;
	}
	else{
		node *n;
		n = no(n);
		n->data = num;
		n->per=l->tail;
		n->per->next=n;
		l->tail=n;
	}
}

int L_pop(list *l){							//remove last data
	if(l->head==NULL){
		printf("no data to return (the 0 is the  default return value)");
		return 0;
	}
	else if(l->head == l->tail){
		node *n;
		n = no(n);
		n = l->head;
		l->head=NULL;
		l->tail=NULL;
		int a =n->data;
		free(n);
		return a;
	}
	else{
		node *n;
		n = no(n);
		n = l->tail;
		l->tail=n->per;
		n->per->next=NULL;
		int a =n->data;
		free(n);
		return a;
	}
}

int L_elemantAt(list *l,int inx){				//return element at a index
	if(l->head==NULL){
		printf("no data to return (the 0 is the  default return value)");
		return 0;
	}
	else{
		node *temp;
		temp = no(temp);
		temp = l->head;
		int x=0;
		for(x=0;x<inx;x++){
			temp = temp->next;
			if(temp != NULL) continue;
			printf("the index is out bound (the return value is not valied)");//list index opout of bound
			return 0;

		}
		return temp->data;
	}
}

int L_len(list *l){
	if(l->head==NULL){
		printf("no data to return (the 0 is the  default return value)");
		return 0;
	}
	else{
		node *temp;
		temp = no(temp);
		temp = l->head;
		int count =0;
		do{
			count ++;
			temp = temp ->next;
		}while(temp!=NULL);
		return count;
	}
}

list* L_join(list* l1,list* l2){
	list* ret = L_create();
	node* no = l1->head;
	while(no){
		L_add(ret,no->data);
		no = no->next;
	}
	no = l2->head;
	while(no){
		L_add(ret,no->data);
		no = no->next;
	}
	return ret;
}

void L_display(list* l){
	node* temp = l->head;
	while(temp){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

// end


int Num_digit(int num){
	int count =0;
	while(num){
		count++;
		num/=10;
	}
	return count;
}

void Tree_displayArrayTree(int* arr,int size){
	printf("\n");

	int hight = log2(size+1);

	



}

String* S_create(char* ch){
	String *str = L_create();
	for(int x=0;x<strlen(ch);x++){
		L_add(str,ch[x]);
	}
	return str;
}

void S_concat(String* str,char* ch){
	for(int x=0;x<strlen(ch);x++){
		L_add(str,ch[x]);
	}
}

// String* S_concat_String_array(String **st,int num){
// 	String* ret = S_create("");
// 	for(int x=0;x<num;x++){
// 		L_join(ret,st[x]);
// 		S_display(ret);
// 	}
// 	return ret;
// }

void S_display(String* st){
	node* temp = st->head;
	while(temp){
		printf("%c",temp->data);
		temp=temp->next;
	}
}

void S_displays(String **st,int num){
	for(int x=0;x<num;x++){
		S_display(st[x]);
		printf(" ");
	}
	printf("\n");
}

int maxInt(int x,int y){
	return (x>y)?x:y;
}

int minInt(int x,int y){
	return (x<y)?x:y;
}