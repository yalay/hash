
#pragma once

#define HASH_TABLE_LEN    100

/*********************************************************************
*                            数据结构
**********************************************************************/
//链表节点
typedef struct _Link_Node  
{  
    int id;
    int data;
    struct _Link_Node *next;  
}Link_Node,*Link_Node_Ptr; 

//哈希表头
typedef struct _Hash_Header  
{  
    struct _Link_Node *next;  
}Hash_Header,*Hash_Header_Ptr;

