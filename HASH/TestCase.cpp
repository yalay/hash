// HASH.cpp : 定义控制台应用程序的入口点。
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
    
    //插入数据id = 1,data = 2;
    node = init_link_node();
    node->id = 1;
    node->data = 2;
    append_link_node(node);
    
    //查询节点数
    printf("1节点数为%d\n",get_node_num());
    
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
    
    //查询节点数
    printf("2节点数为%d\n",get_node_num());
    
    //查询id = 1000;
    node = search_link_node(100,&temp);
    if (node != 0)
    {
        if (temp == 0)
        {
            printf("删除普通节点:所需查询id的值为%d,数据为%d\n",node->next->id,node->next->data);
            
            //删除
            delete_link_node(node);
        }
        else
        {
            //根节点
            printf("删除根节点所需查询id的值为%d,数据为%d\n",node->id,node->data);
            
            //删除
            delete_link_root_node(node);
        }
    }
    else
    {
        printf("查询失败\n");
    }
    
    //查询id = 1000;
    node = search_link_node(1001,&temp);
    if (node != 0)
    {
        if (temp == 0)
        {
            printf("所需查询id的值为%d\n",node->next->data);
        }
        else
        {
            //根节点
            printf("所需查询id的值为%d\n",node->data);
        }
    }
    else
    {
        printf("查询失败\n");
    }
    
    printf("节点数为%d\n",get_node_num());
    
    printf_hash();
    
    getchar();
    return 0;
}
