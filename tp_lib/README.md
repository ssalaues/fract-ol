# Thread Pool Library
#### A basic implementation of a thread pool library in C

Below is a basic example of utilizing the multithreading library.
To compile this example instead of the library run **make example**

```c 
void	*thread_func(void * arg)
{
	t_job_type	*job;
	
	job = arg;
		
	printf("%s\n", (job->data));
			
	job->ret = 1;
				
	return (NULL);
}

int main(void)
{
	t_tp_thread *tp;

	tp = ft_tp_create(8);

	t_job_type	*j1 = malloc(sizeof(*j1));
	j1->data = "hey i'm job 1";
	t_job_type	*j2 = malloc(sizeof(*j2));
	j2->data = "hey i'm job 2";
	t_job_type	*j3 = malloc(sizeof(*j3));
	j3->data = "hey i'm job 3";
	t_job_type	*j4 = malloc(sizeof(*j4));
	j4->data = "hey i'm job 4";

	ft_tp_add_task(tp, &thread_func, j1);
	ft_tp_add_task(tp, &thread_func, j2);
	ft_tp_add_task(tp, &thread_func, j3);
	ft_tp_add_task(tp, &thread_func, j4);

	ft_tp_wait_for_queue(tp);

	printf("\n");

	printf("j1->ret: %d\n", j1->ret);
	printf("j2->ret: %d\n", j2->ret);
	printf("j3->ret: %d\n", j3->ret);
	printf("j4->ret: %d\n", j4->ret);

	return (0);

```
