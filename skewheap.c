//
// Created by Once on 2019/8/29.
//

#include "skewheap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SkewHeap *sheap_init(){
    SkewHeap *heap = (SkewHeap*)malloc(sizeof(SkewHeap));
    if(!heap){
        perror("alloc memory for heap error");
        return NULL;
    }
    heap->size = 0;
    heap->root = NULL;
    return heap;
}

int sheap_is_full(SkewHeap *heap){
    KNode *node = (KNode*)malloc(sizeof(KNode));
    if(!node)
        return 1;
    free(node);
    return 0;
}

int sheap_is_empty(SkewHeap *heap){
    if(heap == NULL)
        return 1;
    return heap->size == 0;
}

static void swap_children(KNode *node){
    KNode *temp = node->left;
    node->left = node->right;
    node->right = temp;
}

static KNode *merge(KNode *h1, KNode *h2);
static KNode *merge_node(KNode *h1, KNode *h2);

static KNode *merge(KNode *h1, KNode *h2){
    if(h1->left == NULL)
        h1->left = h2;
    else{
        int flag = 0;
        if(h1->right == NULL)
            flag = 1;
        h1->right = merge_node(h1->right, h2);
        if(!flag)
            swap_children(h1);
    }
    return h1;
}

static KNode *merge_node(KNode *h1, KNode *h2){
    if(h1 == NULL)
        return h2;
    if(h2 == NULL)
        return h1;
    if(h1->key < h2->key)
        return merge(h1, h2);
    else
        return merge(h2, h1);
}

int sheap_push(SkewHeap *heap, int key, Process *process){
    if(heap == NULL || process == NULL)
        return 0;
    KNode *node = (KNode*)malloc(sizeof(KNode));
    if(!node){
        perror("alloc memory for node error");
        return 0;
    }
    node->key = key;
    node->left = node->right = NULL;
    node->process.threads = process->threads;
    node->process.memsize = process->memsize;
    heap->root = merge_node(heap->root, node);
    heap->size++;
    return 1;
}

KNode *sheap_top(SkewHeap *heap){
    if(heap == NULL || heap->size == 0)
        return NULL;
    return heap->root;
}

int sheap_pop(SkewHeap *heap){
    if(heap == NULL || heap->size == 0)
        return 0;
    KNode *root = heap->root;
    KNode *left = root->left;
    KNode *right = root->right;
    free(root);
    heap->size--;
    heap->root = merge_node(left, right);
    return 1;
}

static void traverse_node(KNode *node){
    if(node == NULL)
        return;
    traverse_node(node->left);
    printf("%d ", node->key);
    traverse_node(node->right);
}

void sheap_traverse(SkewHeap *heap){
    if(heap == NULL || heap->size == 0)
        return;
    traverse_node(heap->root);
    printf("\n");
}

static void clear_node(KNode *node){
    if(node == NULL)
        return;
    clear_node(node->left);
    clear_node(node->right);
    free(node);
}

int sheap_clear(SkewHeap *heap){
    if(heap == NULL)
        return 0;
    clear_node(heap->root);
    free(heap);
    return 1;
}
