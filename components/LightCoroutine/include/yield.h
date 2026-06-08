#ifndef _YIELD_H_
#define _YIELD_H_

#define CONCAT(a, b) a##b
#define LABEL(line) CONCAT(L, line)

#define TASK_END(t)  (t)->resume_point = NULL

#ifdef USE_CTX
#define TASK_BEGIN(t)                                  \
    do{                                                \
        enter_load_from_ctx(t, &local);                \
        resume_task(t);                                \
        if((t)->resume_point) goto *(t)->resume_point; \
        ctx_init(t);                                   \
    }while(0)

#define TASK_YIELD_INNER(t, label)          \
    do{                                     \
        exit_save_to_ctx(t, &local);        \
        (t)->resume_point = &&label;        \
        return;                             \
        label: ;                            \
    } while(0)
#define TASK_YIELD(t) TASK_YIELD_INNER(t, LABEL(__LINE__))

#define TASK_WAIT_INNER(t, label, cond)     \
    do{                                     \
        (t)->resume_point = &&label;        \
        label: ;                            \
        if(!(cond)){                        \
            exit_save_to_ctx(t, &local);    \
            suspend_task(t);                \
            return;                         \
        }                                   \
    }while(0)
#define TASK_WAIT(t, cond) TASK_WAIT_INNER(t, LABEL(__LINE__), cond)

#define LOCAL(...)                  \
    struct { __VA_ARGS__ } local;   \
    (void)local;

#else

#define TASK_BEGIN(t)                                  \
    do{                                                \
        resume_task(t);                                \
        if((t)->resume_point) goto *(t)->resume_point; \
    }while(0)

#define TASK_YIELD_INNER(t, label)          \
    do{                                     \
        (t)->resume_point = &&label;        \
        return;                             \
        label: ;                            \
    } while(0)
#define TASK_YIELD(t) TASK_YIELD_INNER(t, LABEL(__LINE__))

#define TASK_WAIT_INNER(t, label, cond)     \
    do{                                     \
        (t)->resume_point = &&label;        \
        label: ;                            \
        if(!(cond)){                        \
            suspend_task(t);                \
            return;                         \
        }                                   \
    }while(0)
#define TASK_WAIT(t, cond) TASK_WAIT_INNER(t, LABEL(__LINE__), cond)

#define LOCAL(...) do{}while(0)
#endif






#endif