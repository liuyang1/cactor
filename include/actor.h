#ifndef _ACTGOR_H_
#define _ACTGOR_H_

typedef struct actor_t actor;

actor *spwan(void *(*routine)(void *), void *arg);

void actor_destory(actor *p);

void 

#endif
