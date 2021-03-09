#include <stdio.h>
#include <os.h>

OS_SEM(sem, 0);

OS_TSK_DEF(sla)
{
	tsk_begin();

	sem_wait(sem);
	printf("tick...\n");

	tsk_end();
}

OS_TSK_DEF(mas)
{
	tsk_begin();

	tsk_delay(SEC);
	sem_give(sem);

	tsk_end();
}

int main()
{
	tsk_start(sla);
	tsk_start(mas);
	sys_start();
}
