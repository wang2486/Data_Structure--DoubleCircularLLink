/**
  * @file name:DoubleCirLLink
  * @brief    :Realization of basic functions of bidirectional circular linked list
  * @author   :i33akq@163.com
  * @date     :2025/04/13
  * @version  :1.0
  * @note     :none
  * @CopyRight (C)   2024-2025   i33akq@163.com   ALL Right Reseverd
*/

#include "DCLLink.h"
int main(int argc,char *argv[])
{
    DCLLink_t *list=DCLLink_Create();
    /*DCLLink_HeadInsert(list,5);
    DCLLink_HeadInsert(list,4);
    DCLLink_HeadInsert(list,3);
    DCLLink_HeadInsert(list,2);
    DCLLink_HeadInsert(list,1);*/

    DCLLink_TailInsert(list,5);
    DCLLink_TailInsert(list,4);
    DCLLink_TailInsert(list,3);
    DCLLink_TailInsert(list,2);
    DCLLink_TailInsert(list,1);

    //DCLLink_HeadDelete(list);
    //DCLLink_TailDelete(list);

    //DCLLink_Insert_Place(list,100,5);
    //DCLLink_Insert_AfterValue(list,100,3);
    //DCLLink_Insert_BeforeValue(list,100,3);

    //DCLLink_Delete_Place(list,5);
    DCLLink_Delete_Value(list,3);


    DCLLink_Traverse(list);
    return 0;
}
