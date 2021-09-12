#include<stdio.h>
#include<stdlib.h>

struct block{
    char data;
    struct block *address_of_the_nextblock;
};

struct block *head=NULL;

void Traversal(struct block *n);

void Insertfront(char dat);

void Insertback(char dat);

void Insertmid(int pos,char dat);

void Deletefront();

void Deleteback();

void Deletemid(int pos);

void main(){

    struct block *first_block=NULL;
    struct block *second_block=NULL;
    struct block *third_block=NULL;
    struct block *final_block=NULL;

    first_block=malloc(sizeof(struct block));
    second_block=malloc(sizeof(struct block));
    third_block=malloc(sizeof(struct block));
    final_block=malloc(sizeof(struct block));

    head=first_block;

    first_block->data='A';
    first_block->address_of_the_nextblock=second_block;

    second_block->data='B';
    second_block->address_of_the_nextblock=third_block;

    third_block->data='C';
    third_block->address_of_the_nextblock=final_block;

    final_block->data='D';
    final_block->address_of_the_nextblock=NULL;

    Insertfront('X');

    Insertfront('Y');

    Insertback('Z');

    Insertback('W');

    Insertmid(4,'J');

    Insertmid(4,'K');

    Deletefront();

    Deleteback();

    Deletemid(4);

    Traversal(head);

}

void Traversal(struct block *n){
    while(n!=NULL){
        printf("%c\t",n->data);
        n=n->address_of_the_nextblock;
    }
}

void Insertfront(char dat){
    struct block* temp;
    temp=malloc(sizeof(struct block));
    temp->data=dat;
    temp->address_of_the_nextblock=head;
    head=temp;
}

void Deletefront(){
    head=head->address_of_the_nextblock;
}

void Deleteback(){
    struct block* n;
    n=head;
    while(n->address_of_the_nextblock->address_of_the_nextblock!=NULL){
        n=n->address_of_the_nextblock;
    }
    n->address_of_the_nextblock=NULL;
}

void Deletemid(int pos){
    int i;
    struct block* n;
    struct block* temp;
    n=head;
    for(i=0;i<=(pos-2);i++){
        n=n->address_of_the_nextblock;
    }
    temp=n->address_of_the_nextblock->address_of_the_nextblock;
    n->address_of_the_nextblock=temp;
}

void Insertback(char dat){
    struct block* end;
    struct block* n;
    end=malloc(sizeof(struct block));
    n=head;
    while(n->address_of_the_nextblock!=NULL){
        n=n->address_of_the_nextblock;
    }
    n->address_of_the_nextblock=end;
    end->data=dat;
    end->address_of_the_nextblock=NULL;
    
}

void Insertmid(int pos,char dat){
    int i;
    struct block* mid;
    struct block* temp;
    struct block* n;
    mid=malloc(sizeof(struct block));
    n=head;
    for(i=0;i<=(pos-2);i++){
        n=n->address_of_the_nextblock;
    }
    temp=n->address_of_the_nextblock;
    n->address_of_the_nextblock=mid;
    mid->data=dat;
    mid->address_of_the_nextblock=temp;
    
}