#include "ft_tp.h"

t_tp_thread *ft_tp_create(size_t thread_count)
{
	t_tp_thread *tp;

	if (!(tp = malloc(sizeof(*tp))))
		return (NULL);
	if (!(tp->threads = malloc(sizeof(tp->threads) * thread_count)))
		return (NULL);
	tp->thread_count = thread_count;
	tp->threads_used = 0;
	tp->jobs = NULL;

	return (tp);
}

int			ft_tp_add_task(t_tp_thread *tp, void *(*job_fn)(void *), t_job_type *job_data)
{
	t_job	*job;

	if (!(job = malloc(sizeof(*job))))
		return (-1);
	job->data = job_data;
	job->fn = job_fn;
	job->next = tp->jobs;
	tp->jobs = job;

	return (0);
}

int			ft_tp_wait_for_queue(t_tp_thread *tp)
{
	size_t		i;
	t_job		*tmp;

	while (tp->jobs)
	{
		i = 0;
		while (tp->jobs && i < tp->thread_count)
		{
			if (i == tp->threads_used)
			{
				if (pthread_create(&(tp->threads[i]), NULL, tp->jobs->fn, tp->jobs->data))
					return (-1);
				tmp = tp->jobs;
				tp->jobs = tp->jobs->next;
				free(tmp);
				tp->threads_used++;
			}
			i++;
		}
		while (tp->threads_used--)
		{
			if (pthread_join(tp->threads[tp->threads_used], NULL))
				return (-1);
		}
	}
	return (0);
}
