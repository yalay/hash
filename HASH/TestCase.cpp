// HASH.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

int _tmain(int argc, _TCHAR* argv[])
{
    Link_Node_Ptr node;
    uint8_t temp = 0;
    uint8_t root = 0;
    uint8_t i = 0;
    
    init_hash_table();
    
    //��������id = 1,data = 2;
    node = init_link_node();
    node->id = 1;
    node->data = 2;
    append_link_node(node);
    
    //��ѯ�ڵ���
    printf("1�ڵ���Ϊ%d\n",get_node_num());
    
    node = init_link_node();
    node->id = 100;
    node->data = 101;
    append_link_node(node);
    
    node = init_link_node();
    node->id = 1002;
    node->data = 1001;
    append_link_node(node);
    
    node = init_link_node();
    node->id = 10000;
    node->data = 10001;
    append_link_node(node);
    
    node = init_link_node();
    node->id = 1000;
    node->data = 10001;
    append_link_node(node);
    
    node = init_link_node();
    node->id = 2;
    node->data = 10001;
    append_link_node(node);
    
    //��ѯ�ڵ���
    printf("2�ڵ���Ϊ%d\n",get_node_num());
    
    //��ѯid = 1000;
    node = search_link_node(100,&temp);
    if (node != 0)
    {
        if (temp == 0)
        {
            printf("ɾ����ͨ�ڵ�:�����ѯid��ֵΪ%d,����Ϊ%d\n",node->next->id,node->next->data);
            
            //ɾ��
            delete_link_node(node);
        }
        else
        {
            //���ڵ�
            printf("ɾ�����ڵ������ѯid��ֵΪ%d,����Ϊ%d\n",node->id,node->data);
            
            //ɾ��
            delete_link_root_node(node);
        }
    }
    else
    {
        printf("��ѯʧ��\n");
    }
    
    //��ѯid = 1000;
    node = search_link_node(1001,&temp);
    if (node != 0)
    {
        if (temp == 0)
        {
            printf("�����ѯid��ֵΪ%d\n",node->next->data);
        }
        else
        {
            //���ڵ�
            printf("�����ѯid��ֵΪ%d\n",node->data);
        }
    }
    else
    {
        printf("��ѯʧ��\n");
    }
    
    printf("�ڵ���Ϊ%d\n",get_node_num());
    
    printf_hash();
    
    getchar();
    return 0;
}
