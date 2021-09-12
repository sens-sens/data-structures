#include<stdio.h>
#include<stdlib.h>

void main(){

    struct block{
    char data;
    struct block *address_of_the_nextblock;
    };

    struct block *initial_block=NULL;
    struct block *second_block=NULL;
    struct block *third_block=NULL;
    struct block *final_block=NULL;

    struct block *temp=NULL;

    initial_block=malloc(sizeof(struct block));
    second_block=malloc(sizeof(struct block));
    third_block=malloc(sizeof(struct block));
    final_block=malloc(sizeof(struct block));

    initial_block->data='A';
    initial_block->address_of_the_nextblock=second_block;

    second_block->data='B';
    second_block->address_of_the_nextblock=third_block;

    third_block->data='C';
    third_block->address_of_the_nextblock=final_block;

    final_block->data='D';
    final_block->address_of_the_nextblock=NULL;

    temp=initial_block;

    while (temp!=NULL)
    {
        printf("%c\t",temp->data);
        temp=temp->address_of_the_nextblock;
    }
    
}