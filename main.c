#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "skewheap.h"

static void skew_heap(void){
    SkewHeap *heap = sheap_init();
    Process p;
    p.threads = 15;
    p.memsize = 512;
    sheap_push(heap, 1, &p);
    sheap_push(heap, 6, &p);
    sheap_push(heap, 2, &p);
    sheap_push(heap, 7, &p);
    sheap_push(heap, 5, &p);
    sheap_push(heap, 3, &p);
    sheap_push(heap, 8, &p);
    sheap_push(heap, 4, &p);
    sheap_push(heap, 9, &p);

    sheap_traverse(heap);

    while(!sheap_is_empty(heap)){
        KNode *node = sheap_top(heap);
        printf("%d\n", node->key);
        sheap_pop(heap);
    }

    sheap_clear(heap);
}

int main(void) {
    skew_heap();
    return 0;
}
