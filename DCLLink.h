/**
  * @file name:DCLLink.h
  * @brief    :Functional interface design
  * @author   :i33akq@163.com
  * @date     :2025/04/13
  * @version  :1.0
  * @note     :none
  * @CopyRight (C)   2024-2025   i33akq@163.com   ALL Right Reseverd
*/

#ifndef DCLLINK_H
#define DCLLINK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ELemtype_t;
typedef struct DCLLink
{
    ELemtype_t data;
    struct DCLLink *prev;
    struct DCLLink *next;
}DCLLink_t;

/**
  * @function name: DCLLink_Create
  * @brief        : Create a circular doubly linked list head node
  * @param        : None
  * @retval       : Returns a pointer to the head node
  * @version      : 1.0
  * @note         : The head's next and prev point to itself
*/
DCLLink_t *DCLLink_Create();

/**
  * @function name: DCLLink_NewNode
  * @brief        : Create a new circular doubly linked list node with data
  * @param        : @data: the value to be stored in the node
  * @retval       : Returns a pointer to the new node
  * @version      : 1.0
  * @note         : The new node points to itself for both next and prev
*/
DCLLink_t *DCLLink_NewNode(ELemtype_t data);

/**
  * @function name: DCLLink_Length
  * @brief        : Calculate the length of the circular doubly linked list
  * @param        : @Head: the head node pointer
  * @retval       : Returns the number of nodes in the list
  * @version      : 1.0
  * @note         : Traverses the list until it loops back to head->next
*/
int DCLLink_Length(DCLLink_t *Head);

/**
  * @function name: DCLLink_Traverse
  * @brief        : Traverse and print the circular doubly linked list
  * @param        : @Head: the head node pointer
  * @retval       : None
  * @version      : 1.0
  * @note         : Loops through the list and prints each node's data
*/
void DCLLink_Traverse(DCLLink_t *Head);

/**
  * @function name: DCLLink_HeadInsert
  * @brief        : Insert a new node at the head of the circular doubly linked list
  * @param        : @Head: the head node pointer
  * @param        : @data: the data to be inserted
  * @retval       : Returns true if insertion is successful, false otherwise
  * @version      : 1.0
  * @note         : Updates head->next and related pointers
*/
bool DCLLink_HeadInsert(DCLLink_t *Head , ELemtype_t data);

/**
  * @function name: DCLLink_TailInsert
  * @brief        : Insert a new node at the tail of the circular doubly linked list
  * @param        : @Head: the head node pointer
  * @param        : @data: the data to be inserted
  * @retval       : Returns true if insertion is successful, false otherwise
  * @version      : 1.0
  * @note         : The new node is linked before head->next (tail)
*/

bool DCLLink_TailInsert(DCLLink_t *Head , ELemtype_t data);

/**
  * @function name: DCLLink_HeadDelete
  * @brief        : Delete the head node of the circular doubly linked list
  * @param        : @Head: the head node pointer
  * @retval       : Returns true if deletion is successful, false otherwise
  * @version      : 1.0
  * @note         : Updates head->next and frees the first node
*/
bool DCLLink_HeadDelete(DCLLink_t *Head);

/**
  * @function name: DCLLink_TailDelete
  * @brief        : Delete the tail node of the circular doubly linked list
  * @param        : @Head: the head node pointer
  * @retval       : Returns true if deletion is successful, false otherwise
  * @version      : 1.0
  * @note         : Frees the last node and updates the previous node
*/
bool DCLLink_TailDelete(DCLLink_t *Head);

/**
  * @function name: DCLLink_Insert_Place
  * @brief        : Insert a node at a specific position in the list
  * @param        : @Head: the head node pointer
  * @param        : @data: the data to insert
  * @param        : @dest: the destination position (1-based)
  * @retval       : Returns true if insertion is successful, false otherwise
  * @version      : 1.0
  * @note         : Inserts the new node before the given position
*/

bool DCLLink_Insert_Place(DCLLink_t *Head,ELemtype_t data,ELemtype_t dest);

/**
  * @function name: DCLLink_Insert_BeforeValue
  * @brief        : Insert a node before a node with a specific value
  * @param        : @Head: the head node pointer
  * @param        : @data: the new data to insert
  * @param        : @dest: the target value before which to insert
  * @retval       : Returns true if insertion is successful, false otherwise
  * @version      : 1.0
  * @note         : If the value is at the head, head insert is used
*/
bool DCLLink_Insert_BeforeValue(DCLLink_t *Head,ELemtype_t data,ELemtype_t dest);

/**
  * @function name: DCLLink_Insert_AfterValue
  * @brief        : Insert a node after a node with a specific value
  * @param        : @Head: the head node pointer
  * @param        : @data: the new data to insert
  * @param        : @dest: the target value after which to insert
  * @retval       : Returns true if insertion is successful, false otherwise
  * @version      : 1.0
  * @note         : If value is at the tail, tail insert is used
*/
bool DCLLink_Insert_AfterValue(DCLLink_t *Head,ELemtype_t data,ELemtype_t dest);

/**
  * @function name: DCLLink_Delete_Place
  * @brief        : Delete a node at a specific position in the list
  * @param        : @Head: the head node pointer
  * @param        : @dest: the position to delete (1-based)
  * @retval       : Returns true if deletion is successful, false otherwise
  * @version      : 1.0
  * @note         : Head or tail delete is used for boundary positions
*/

bool DCLLink_Delete_Place(DCLLink_t *Head,ELemtype_t dest);

/**
  * @function name: DCLLink_Delete_Value
  * @brief        : Delete a node with a specific value
  * @param        : @Head: the head node pointer
  * @param        : @dest: the value to be deleted
  * @retval       : Returns true if deletion is successful, false otherwise
  * @version      : 1.0
  * @note         : If the value is at the head or tail, respective deletes are used
*/
bool DCLLink_Delete_Value(DCLLink_t *Head,ELemtype_t dest);



#endif