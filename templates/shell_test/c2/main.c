#include "main.h"

void main(){
    create_shell_env_varible();

    hal_sys_uart_init();

    load_shell();

    while(1){
        printf("Never Reaching here.\r\n");
    }
    
}
