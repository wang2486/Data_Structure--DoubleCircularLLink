/**
  * @file name:DCLLink
  * @brief    :Realization of basic functions of bidirectional circular linked list
  * @author   :i33akq@163.com
  * @date     :2025/04/13
  * @version  :1.0
  * @note     :Function interface implementation method
  * @CopyRight (C)   2024-2025   i33akq@163.com   ALL Right Reseverd
*/
#include "DCLLink.h"

DCLLink_t *DCLLink_Create(){
    DCLLink_t *Head=(DCLLink_t *)calloc(1,sizeof(DCLLink_t));
    if(!Head)  return NULL;

    Head->next=Head;
    Head->prev=Head;
    return Head;
}

DCLLink_t *DCLLink_NewNode(ELemtype_t data){
    DCLLink_t *New=(DCLLink_t *)calloc(1,sizeof(DCLLink_t));
    if(!New)  return NULL;

    New->data=data;
    New->prev=New;
    New->next=New;
    return New;
}

int DCLLink_Length(DCLLink_t *Head){
    if(!Head || Head->next==NULL)  return 0;
    
    DCLLink_t *current=Head->next;
    int Len=1;
    while(current->next!=Head->next){
        current=current->next;
        Len++;
    }
    return Len;
}

void DCLLink_Traverse(DCLLink_t *Head){
    if(!Head || Head->next==NULL)  return;

    DCLLink_t *current=Head->next;
    do{
        printf("%d <-> ",current->data);
        current=current->next;
    }while (current!=Head->next); 
    printf("(Head->next)\n");
}

bool DCLLink_HeadInsert(DCLLink_t *Head , ELemtype_t data){
    DCLLink_t *New=(DCLLink_t *)calloc(1,sizeof(DCLLink_t));
    if(!New)  return false;
    New->data=data;

    if(Head->next==NULL){ //判空
        Head->next=New;
        New->next=New;
        New->prev=New;
        return true;
    }

    New->prev=(Head->next)->prev;
    (Head->next->prev)->next=New;
    New->next=Head->next;
    (Head->next)->prev=New;
    Head->next=New;
    return true;
}

bool DCLLink_TailInsert(DCLLink_t *Head , ELemtype_t data){
    DCLLink_t *New=(DCLLink_t *)calloc(1,sizeof(DCLLink_t));
    if(!New)  return false;
    New->data=data;

    if(Head->next==NULL){  //判空
        Head->next=New;
        New->next=New;
        return true;
    }

    (Head->next->prev)->next=New;
    New->prev=(Head->next->prev);
    (Head->next)->prev=New;
    New->next=Head->next;
    return true;
}

bool DCLLink_HeadDelete(DCLLink_t *Head){
    if(!Head || Head->next == NULL)  return false;
    
    DCLLink_t *current=Head->next;
    if(current->next==Head->next){  //表中只有一个结点
        Head->next=NULL;
        free(current);
        return true;
    }

    (current->prev)->next=current->next;
    (current->next)->prev=current->prev;
    Head->next=current->next;
    current->next=NULL;
    current->prev=NULL;
    return true;
}

bool DCLLink_TailDelete(DCLLink_t *Head){
    if(!Head || Head->next == NULL)  return false;
    
    DCLLink_t *current=Head->next;
    if(current->next==Head->next){  //表中只有一个结点
        Head->next=NULL;
        free(current);
        return true;
    }

    DCLLink_t *tail = current->prev; // Get the tail node,save address
    tail->prev->next = current;      // Update the previous node's next pointer
    current->prev = tail->prev;      // Update the head's previous pointer
    free(tail); // Free the memory of the tail node
    return true;
}

bool DCLLink_Insert_Place(DCLLink_t *Head,ELemtype_t data,ELemtype_t dest){
    if((DCLLink_Length(Head))<dest || !Head)  return false;

    DCLLink_t *New=(DCLLink_t *)calloc(1,sizeof(DCLLink_t));
    if(!New)  return false;
    New->data=data;

    DCLLink_t *current=Head->next;
    DCLLink_t *previous=Head;
    if(dest==1){
        DCLLink_HeadInsert(Head,data);
        return true;
    }

    int cnt=1;
    while (cnt<dest){
        cnt++;
        current=current->next;
        previous=previous->next;
    }
    New->next=current;
    New->prev=previous;
    current->prev=New;
    previous->next=New;
    return true;
}

bool DCLLink_Insert_BeforeValue(DCLLink_t *Head,ELemtype_t data,ELemtype_t dest){
    if(!Head || Head->next==NULL) return false;

    DCLLink_t *New=(DCLLink_t *)calloc(1,sizeof(DCLLink_t));
    if(!New)  return false;
    New->data=data;

    DCLLink_t *current=Head->next;
    DCLLink_t *previous=Head;
    if(current->data == dest){
        DCLLink_HeadInsert(Head,data);
        return true;
    }
    while(current->data!=dest){
        current=current->next;
        previous=previous->next;
    }
    if(current->next==Head->next && current->data!=dest) return false;
    else{
        New->next=current;
        New->prev=previous;
        current->prev=New;
        previous->next=New;
    }
    return true;   
}

bool DCLLink_Insert_AfterValue(DCLLink_t *Head,ELemtype_t data,ELemtype_t dest){
    if(!Head || Head->next==NULL) return false;

    DCLLink_t *New=(DCLLink_t *)calloc(1,sizeof(DCLLink_t));
    if(!New)  return false;
    New->data=data;

    DCLLink_t *latter=Head->next;
    DCLLink_t *current=Head;
    while(latter->data!=dest){
        latter=latter->next;
        current=current->next;
    }
    if(latter->next==Head->next && latter->data!=dest) return false;
    else if(latter->next==Head->next && latter->data==dest){
        DCLLink_TailInsert(Head,data);
    }
    else{
        New->next=latter->next;
        New->prev=latter;
        latter->next->prev=New;
        latter->next=New;
    }
    return true;   
}

bool DCLLink_Delete_Place(DCLLink_t *Head,ELemtype_t dest){
    if((DCLLink_Length(Head))<dest || !Head)  return false;

    DCLLink_t *current=Head->next;
    DCLLink_t *previous=Head;
    if(dest==1){
        DCLLink_HeadDelete(Head);
        return true;
    }
    if(dest==DCLLink_Length(Head)){
        DCLLink_TailDelete(Head);
        return true;
    }
    int cnt=1;
    while (cnt<dest){
        cnt++;
        current=current->next;
        previous=previous->next;
    }
    (current->next)->prev=previous;
    previous->next=current->next;
    current->prev=NULL;
    free(current);
    return true;
}

bool DCLLink_Delete_Value(DCLLink_t *Head,ELemtype_t dest){
    if(!Head || Head->next==NULL) return false;

    DCLLink_t *current=Head->next;
    DCLLink_t *previous=Head;
    if(current->data == dest){
        DCLLink_HeadDelete(Head);
        return true;
    }
    while(current->data!=dest){
        current=current->next;
        previous=previous->next;
    }
    if(current->next==Head->next && current->data!=dest) return false;
    else if(current->next==Head->next && current->data==dest){
        DCLLink_TailDelete(Head);
    }
    else{
        (current->next)->prev=previous;
        previous->next=current->next;
        current->prev=NULL;
        current->prev=NULL;
        free(current);
    }
    return true;   
}
