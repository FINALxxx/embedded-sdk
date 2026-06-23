#include "main.h"

void easy_print(void* param){
    printf("I will print: %s\r\n", (char*)param);
}

void main(){
    log_init(LOG_WARN, NULL);
    
    hal_sys_uart_init();

    func_node func_node = {
        .func = easy_print,
        .param = "Hello, World",
        .next = NULL,
    };
    set_fnode(&func_node);

    create_shell_env_varible();

    load_shell();

    while(1){
        printf("Never Reaching here.\r\n");
    }
    
}
