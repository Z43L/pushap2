#include "pushswap.h"

int minu(t_node *node, int exclude)
{
    int min = node->value;
    t_node *current = node;
    while(current)
    {
        if(min > current->value && min != exclude)
        {
            min = current->value;
        }
        current = current->next;
    }
    return min;
}

int currentpost(t_node *node, int busca)
{
    int pos = 0;
    t_node *current = node;
    while(current && current->value != busca)
    {
        pos++;
        current = current->next;
    }
    return pos;
}

int getsize(t_node *node)
{
    int size =0;
    t_node *current = node;
    while(current)
    {
        current = current->next;
        size++;
    }
    return size;
}

int maxvalue(t_node *node)
{
    int max = node->value;
    t_node *current = node;
    while(current)
    {
        if(current->value > max)
        {
            max = current->value;
        }
        current = current->next;
    }
    return max;
}

int issorted(t_node *node) {
    t_node *current = node;
    while (current && current->next) {
        if (current->value > current->next->value) {
            return 0;
        }
        current = current->next;
    }
    return 1;
}
// Function to convert the stack to an array
int *list_to_array(t_node *node, int size) {
    int *arr = malloc(size * sizeof(int));
    int i = 0;
    t_node *current = node;
    while (current) {
        arr[i++] = current->value;
        current = current->next;
    }
    return arr;
}

// Function to sort an array
void sort_array(int *arr, int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to get the number of chunks based on the stack size
int get_chunk_count(int size) {
    if (size <= 0)
        return 0;
    else if (size <= 10)
        return 1;
    else if (size <= 100)
        return 5;
    else
        return 10;
}

int *create_chunks(int *arr, int size, int chunk_count) {
    if (chunk_count <= 0 || size <= 0)
        return NULL;

    int *chunks = malloc(chunk_count * sizeof(int));
    if (!chunks) {
        perror("Failed to allocate memory for chunks");
        exit(EXIT_FAILURE);
    }

    int chunk_size = size / chunk_count;
    int remainder = size % chunk_count;
    int start = 0;

    for (int i = 0; i < chunk_count; i++) {
        int current_chunk_size = chunk_size + (i < remainder ? 1 : 0);
        int end = start + current_chunk_size - 1;
        if (end >= size)
            end = size - 1;
        chunks[i] = arr[end];
        start = end + 1;
    }
    return chunks;
}

// The main sorting algorithm
void algo(pushswap *ps) {
    int size = getsize(ps->stacka);
    if (size <= 0)
        return;

    printf("Stack size: %d\n", size);

    int *arr = list_to_array(ps->stacka, size);
    if (!arr) {
        fprintf(stderr, "Error allocating array\n");
        exit(EXIT_FAILURE);
    }

    sort_array(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int chunk_count = get_chunk_count(size);
    if (chunk_count <= 0) {
        fprintf(stderr, "Invalid chunk count: %d\n", chunk_count);
        free(arr);
        return;
    }

    printf("Chunk count: %d\n", chunk_count);

    int *chunks = create_chunks(arr, size, chunk_count);
    if (!chunks) {
        fprintf(stderr, "Error allocating chunks\n");
        free(arr);
        exit(EXIT_FAILURE);
    }

    printf("Chunks: ");
    for (int i = 0; i < chunk_count; i++) {
        printf("%d ", chunks[i]);
    }
    printf("\n");

    int current_chunk = 0;

    while (ps->stacka) {
        if (current_chunk >= chunk_count) {
            printf("All chunks processed\n");
            break;
        }

        t_node *current = ps->stacka;
        int pos = 0;

        while (current) {
            if (current->value <= chunks[current_chunk]) {
                /* printf("Found value %d in chunk %d (<= %d) at position %d\n",
                       current->value, current_chunk, chunks[current_chunk], pos); */
                break;
            }
            pos++;
            current = current->next;
        }

        if (!current) {
            current_chunk++;
            continue;
        }

        int size_a = getsize(ps->stacka);
        if (pos <= size_a / 2) {
            while (pos-- > 0) {
                ra(&(ps->stacka));
                printf("ra\n");
            }
        } else {
            pos = size_a - pos;
            while (pos-- > 0) {
                rra(&(ps->stacka));
                printf("rra\n");
            }
        }

        pb(&(ps->stacka), &(ps->stackb));
        /* printf("pb (pushed %d to stack B)\n", ps->stackb->value); */
    }

    // Rest of the code remains the same...
}
