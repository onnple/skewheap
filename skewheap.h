//
// Created by Once on 2019/8/29.
//

#ifndef DATALGORITHM_SKEWHEAP_H
#define DATALGORITHM_SKEWHEAP_H

// 斜堆实现优先队列

// 数据实体
typedef struct process{
    int threads;
    int memsize;
} Process;

// 斜堆结点
typedef struct knode{
    int key;
    Process process;
    struct knode *left;
    struct knode *right;
} KNode;

// 斜堆对外ADT
typedef struct skewheap{
    int size;
    KNode *root;
} SkewHeap;

// 斜堆实现优先队列，函数操作声明
extern SkewHeap *sheap_init();
extern int sheap_is_full(SkewHeap *heap);
extern int sheap_is_empty(SkewHeap *heap);
extern int sheap_push(SkewHeap *heap, int key, Process *process);
extern KNode *sheap_top(SkewHeap *heap);
extern int sheap_pop(SkewHeap *heap);
extern void sheap_traverse(SkewHeap *heap);
extern int sheap_clear(SkewHeap *heap);

#endif //DATALGORITHM_SKEWHEAP_H
