// linear search

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{

    printf("Aabhas Kumar Jha - A2305221279\n\n");
    bool found = false;

    int size;
    printf("enter array size : ");
    scanf("%d", &size);
    int arr[size];

    int element;
    for (int i= 0; i < size; i++){
        printf("enter element at index %d: ", i);
        scanf("%d", &element);
        arr[i] = element;
    }

    int num;
    printf("enter number to find : ");
    scanf("%d", &num);

    for (int i= 0; i < size; i++){
        if (num == arr[i]){
            printf("found at index %d", i);
            found = true;
        }
    }

    if (!found){
        printf("not found");
    }

    return 0;
}
