#ifndef _CONF_H_
#define _CONF_H_

#define USE_IDLE_TASK
#define MAX_TASK_NUM 10
#define EXEC_WAIT_POLICY (resume_cnt <= suspend_cnt)

#define USE_CTX
#define TASK_CTX_SIZE 64

#endif