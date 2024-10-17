#include <stdio.h>
#include <stdlib.h>
#include "heap.h"


// heap 생성
HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));

}

// heap 초기화
void init(HeapType* h) {
	h->heap_size = 0;
}

//heap 추가
void insert_max_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

// heap 제거
element delete_max_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {

		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)
			child++;

		if (temp.key >= h->heap[child].key) break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

//heap 정렬 
void heap_sort(element a[], int n) {

	int i;
	HeapType* h;

	h = create();

	init(h);

	for (i = 0; i < n; i++) {
		insert_max_heap(h, a[i]);
	}

	for (i = (n - 1); i >= 0; i--) {
		a[i] = delete_max_heap(h);
	}
	free(h);
}


//swap
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Max Heap에 삽입 후 재정렬 함수
void insertAndPrintHeap(int inputData[], int currentSize) {
	int i = currentSize - 1;  // 새로 삽입된 요소의 인덱스

	// 부모 노드와 비교후 힙 재정렬
	while (i > 0 && inputData[i] > inputData[(i - 1) / 2]) {
		swap(&inputData[i], &inputData[(i - 1) / 2]);
		i = (i - 1) / 2;
	}

	// 삽입 후 힙 상태 출력
	for (int j = 0; j < currentSize; j++) {
		printf("%d ", inputData[j]);
	}
	printf("\n");
}


//힙 재정렬
void resortHeap(int inputData[], int heapSize, int parent) {
	int child = 2 * parent + 1; // 왼쪽 자식 노드
	int max = parent;

	if (child < heapSize && inputData[child] > inputData[max])
		max = child;

	if (child + 1 < heapSize && inputData[child + 1] > inputData[max])
		max = child + 1;

	if (max != parent) {
		swap(&inputData[parent], &inputData[max]);
		resortHeap(inputData, heapSize, max);  // 재귀적으로 힙 재정렬
	}
}


//max heap 만드는 함수
void BuildMaxHeap(int inputData[], int n) {
	// 위로 올라가며 힙 재정렬
	for (int i = (n / 2) - 1; i >= 0; i--) {
		resortHeap(inputData, n, i);
	}
}

//BuildMaxHeapAndSort 함수 구현

void BuildMaxHeapAndSort(int inputData[], int n) {
	
	
	for (int i = 0; i < n; i++) {
		insertAndPrintHeap(inputData, i + 1);  
	}
	

	// 하나씩 루트(최대값)를 제거하고 정렬
	for (int i = n - 1; i > 0; i--) {
		// 루트(최대값)를 배열의 마지막 요소와 교환
		swap(&inputData[0], &inputData[i]);

		// 힙을 다시 재정렬
		resortHeap(inputData, i, 0);

		// 힙 재정렬 후 상태 출력
		for (int j = 0; j < i; j++) {
			printf("%d ", inputData[j]);
		}
		printf("\n");
	}
}
