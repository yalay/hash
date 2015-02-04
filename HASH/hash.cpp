#include "stdafx.h"

//哈希表
Hash_Header_Ptr Hash_Table[HASH_TABLE_LEN];


static int hash_func(int id)
{
    int pos = 0;
    
    pos = id % HASH_TABLE_LEN;

    return pos;
}

static Link_Node_Ptr init_link_node(void)
{
    Link_Node_Ptr node;
    
    node = (Link_Node_Ptr)malloc(sizeof(Link_Node));
    node->next = NULL;
    
    return node;
}

static Hash_Header_Ptr init_hash_header_node(void)
{
    Hash_Header_Ptr node;
    
    node = (Hash_Header_Ptr)malloc(sizeof(Hash_Header));
    node->next = NULL;
    
    return node;
}

static void init_hash_table(void)
{
    int index = 0;
    
    for (index = 0;index < HASH_TABLE_LEN;index++)
    {
        Hash_Table[index] = init_hash_header_node();
        Hash_Table[index]->next = NULL;
    }
}

static void append_link_node(Link_Node_Ptr new_node)
{
    Link_Node_Ptr node;
    int pos = 0;
    
    new_node->next = NULL;
    pos = hash_func(new_node->id);
    
    if (Hash_Table[pos]->next == NULL)
    {
        Hash_Table[pos]->next = new_node;
    }
    else
    {
        node = Hash_Table[pos]->next;
    
        while (node->next != NULL)
        {
            node = node->next;
        }
        
        node->next = new_node;
    }
}

Link_Node_Ptr search_link_node(int id, int *root)
{
    Link_Node_Ptr node;
    int pos = 0;
    
    pos = hash_func(id);
    node = Hash_Table[pos]->next;
    
    if (node == NULL)
    {
        return 0;
    }
    
    if (node->id == id)
    {
        *root = 1;
        return node;
    }
    else
    {
        *root = 0;

        while (node->next != NULL)
        {
            if (node->next->id == id)
            {
                return node;
            }
            else
            {
                node = node->next;
            }
        }
        
        return 0;
    }
}

void delete_link_node(Link_Node_Ptr node)
{
    Link_Node_Ptr delete_node;
    
    delete_node = node->next;
    node->next = delete_node->next;
    
    free(delete_node);
    delete_node = NULL;
}

void delete_link_root_node(Link_Node_Ptr node)
{
    int pos = 0;
    
    pos = hash_func(node->id);
    
    if (node != NULL)
    {
        Hash_Table[pos]->next = node->next;

        free(node);
        node = NULL;
    }
}

int get_node_num(void)
{
    Link_Node_Ptr node;
    int i = 0;
    int num = 0;
    
    for (i = 0;i < HASH_TABLE_LEN;i++)
    {
        node = Hash_Table[i]->next;

        while (node != NULL)
        {
            num++;
            node = node->next;
        }
    }
    
    return num;
}

Link_Node_Ptr get_node_from_index(int index,uint8_t *root)
{   
    Link_Node_Ptr node;
    int i = 0;
    int num = 0;
    
    for (i = 0;i < HASH_TABLE_LEN;i++)
    {
        node = Hash_Table[i]->next;
        if (node == NULL)
        {
            continue;
        }
        
        num++;
        if (num == index)
        {
            *root = 1;
            return node; 
        }
        
        while (node->next != NULL)
        {
            num++;
            if (num == index)
            {
                *root = 0;
                return node; 
            }
            node = node->next;
        }
    }
    
    return 0;
}

void drop_hash()
{
    Link_Node_Ptr node;
    int i = 0;
    Link_Node_Ptr node_next;
    
    for (i = 0;i < HASH_TABLE_LEN;i++)
    {
        node = Hash_Table[i]->next;
        
        while (1)
        {
            if (node == NULL)
            {
                Hash_Table[i]->next = NULL;
                break;
            }
            
            node_next = node->next;
            free(node);
            node = node_next;
        }
    }
}

void printf_hash()
{
    Link_Node_Ptr node;
    uint8_t root = 0;
    uint8_t i = 0;
    uint8_t num = 0;
    
    printf("-------------打印hash表-------------\n");
    
    num = get_node_num();
    for (i = 1;i <= num;i++)
    {
        node = get_node_from_index(i,&root);
        if (node != 0)
        {
            if (root)
            {
                printf("根节点:节点号%d,id为%d\n",i,node->id);
            }
            else
            {
                printf("普通节点:节点号%d,id为%d\n",i,node->next->id);
            }
        }
    }
}
