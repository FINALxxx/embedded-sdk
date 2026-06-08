#include "main.h"

int sigs = 0x00;
task_t handlerA;
task_t handlerB;
task_t handlerC;


void taskA(task_t* t){
    LOCAL(
        uint32_t unused[TASK_CTX_SIZE];
    );

    TASK_BEGIN(t);
    sigs = 0x00;
    printf("A: step 1\n");
    TASK_YIELD(t);

    printf("A: step 2\n");
    TASK_WAIT(t, (sigs==0x01));

    printf("A: step 3\n");
    TASK_YIELD(t);

    sigs = 0x02;
    printf(">>>A: done\n");
    TASK_END(t);
}

void taskB(task_t* t){
    LOCAL(
        uint32_t unused[TASK_CTX_SIZE];
    );

    TASK_BEGIN(t);
    sigs = 0x00;
    printf("B: step 1\n");
    TASK_YIELD(t);

    printf("B: step 2\n");
    TASK_WAIT(t, 1);

    printf("B: step 3\n");
    TASK_YIELD(t);

    delete_task(&handlerA);
    printf(">>>B: done\n");
    TASK_END(t);
}

void taskC(task_t* t){
    LOCAL(
        uint32_t a;
        uint32_t b;
        uint32_t unused[TASK_CTX_SIZE-2];
    );

    TASK_BEGIN(t);
    local.a = 1;
    local.b = 2;
    TASK_YIELD(t);
    printf("C: local=%d,%d\n", local.a, local.b);

    TASK_END(t);
}

int main(){
    hal_sys_uart_init();
    handlerA = create_task(0, taskA, NULL);
    handlerB = create_task(1, taskB, NULL);
    handlerC = create_task(2, taskC, NULL);
    task_scheduler(15);
    return 0;
}
