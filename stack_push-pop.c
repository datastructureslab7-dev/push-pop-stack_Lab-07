#include<stdio.h>

    int stk[20], i, mx = 5, top= -1, item, c;

    int pop(){
        if(top == -1){
            printf("Stack is empty/underflow");
            return 0;
            }

            item = stk[top];
            top = top - 1;
            printf("\nSTACK\n");

            for(i = top; i>=0; i--){
            printf("\nstack[%d]= %d", i, stk[i]);
            }
    }

    int push(){
        if(top == mx){
            printf("\nStack is full/overflow");
            return 0;
        }

        top = top+1;
        printf("\nEnter new item to push");
        scanf("%d", &item);
        stk[top] = item;
        printf("\nSTACK: \n");

        for(i=top; i>=0; i--){
            printf("\nstack[%d]= %d", i, stk[i]);
        }
    }

int main(){
    for( ; ; ){
        printf("\nEnter your choice:\n 1. PUSH\n 2. POP\n 3. EXIT\n");
        scanf("%d", &c);

        switch(c){
            case 1: push();
            break;

            case 2: pop();
            break;

            default:
                return 0;
        }
    }

    return 0;
}

