#include <stdio.h>
#include <stdlib.h>
#include "heap.h"


// heap ����
HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));

}

// heap �ʱ�ȭ
void init(HeapType* h) {
	h->heap_size = 0;
}

//heap �߰�
void insert_max_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

// heap ����
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

//heap ���� 
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

// Max Heap�� ���� �� ������ �Լ�
void insertAndPrintHeap(int inputData[], int currentSize) {
	int i = currentSize - 1;  // ���� ���Ե� ����� �ε���

	// �θ� ���� ���� �� ������
	while (i > 0 && inputData[i] > inputData[(i - 1) / 2]) {
		swap(&inputData[i], &inputData[(i - 1) / 2]);
		i = (i - 1) / 2;
	}

	// ���� �� �� ���� ���
	for (int j = 0; j < currentSize; j++) {
		printf("%d ", inputData[j]);
	}
	printf("\n");
}


//�� ������
void resortHeap(int inputData[], int heapSize, int parent) {
	int child = 2 * parent + 1; // ���� �ڽ� ���
	int max = parent;

	if (child < heapSize && inputData[child] > inputData[max])
		max = child;

	if (child + 1 < heapSize && inputData[child + 1] > inputData[max])
		max = child + 1;

	if (max != parent) {
		swap(&inputData[parent], &inputData[max]);
		resortHeap(inputData, heapSize, max);  // ��������� �� ������
	}
}


//max heap ����� �Լ�
void BuildMaxHeap(int inputData[], int n) {
	// ���� �ö󰡸� �� ������
	for (int i = (n / 2) - 1; i >= 0; i--) {
		resortHeap(inputData, n, i);
	}
}

//BuildMaxHeapAndSort �Լ� ����

void BuildMaxHeapAndSort(int inputData[], int n) {
	
	
	for (int i = 0; i < n; i++) {
		insertAndPrintHeap(inputData, i + 1);  
	}
	

	// �ϳ��� ��Ʈ(�ִ밪)�� �����ϰ� ����
	for (int i = n - 1; i > 0; i--) {
		// ��Ʈ(�ִ밪)�� �迭�� ������ ��ҿ� ��ȯ
		swap(&inputData[0], &inputData[i]);

		// ���� �ٽ� ������
		resortHeap(inputData, i, 0);

		// �� ������ �� ���� ���
		for (int j = 0; j < i; j++) {
			printf("%d ", inputData[j]);
		}
		printf("\n");
	}
}
