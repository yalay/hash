
#pragma once

#define HASH_TABLE_LEN    100

/*********************************************************************
*                            ���ݽṹ
**********************************************************************/
//����ڵ�
typedef struct _Link_Node  
{  
    int id;
    int data;
    struct _Link_Node *next;  
}Link_Node,*Link_Node_Ptr; 

//��ϣ��ͷ
typedef struct _Hash_Header  
{  
    struct _Link_Node *next;  
}Hash_Header,*Hash_Header_Ptr;

