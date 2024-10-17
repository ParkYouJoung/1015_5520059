#pragma once

#define MAX_ELEMENT 200

typedef struct {
	int key;
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;


extern HeapType* create();
extern void init(HeapType* h);
extern void insert_max_heap(HeapType* h, element item);
extern element delete_max_heap(HeapType* h);
extern void heap_sort(element a[], int n);
extern void swap(int* a, int* b);
extern void resortHeap(int inputData[], int heapSize, int parent);
extern void BuildMaxHeap(int inputData[], int n);
extern void BuildMaxHeapAndSort(int inputData[], int n);