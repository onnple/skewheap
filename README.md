# 斜堆(skewheap)
斜堆(skew heap)实现优先队列，原文地址：  

## 斜堆函数操作说明

### 1、初始化斜堆
extern SkewHeap *sheap_init();

### 2、检查斜堆是否已满
extern int sheap_is_full(SkewHeap *heap);

### 3、检查斜堆是否为空
extern int sheap_is_empty(SkewHeap *heap);

### 4、斜堆入队或插入数据
extern int sheap_push(SkewHeap *heap, int key, Process *process);

### 5、获取斜堆顶部元素
extern KNode *sheap_top(SkewHeap *heap);

### 6、斜堆出队或删除数据
extern int sheap_pop(SkewHeap *heap);

### 7、遍历斜堆
extern void sheap_traverse(SkewHeap *heap);

### 8、释放斜堆
extern int sheap_clear(SkewHeap *heap);

