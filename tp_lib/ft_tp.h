#ifndef FT_THREAD_POOL_H
# define FT_THREAD_POOL_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef char *	t_job_data_type;

typedef struct
{
	int				ret;
	t_job_data_type	data;
}					t_job_type;

typedef struct		s_job
{
	struct s_job	*next;
	t_job_type		*data;
	void			*(*fn)(void *);
}					t_job;

typedef struct 
{
	pthread_t		*threads;
	size_t			thread_count;
	size_t			threads_used;
	t_job			*jobs;
}					t_tp_thread;

t_tp_thread *ft_tp_create(size_t thread_count);
int			ft_tp_add_task(t_tp_thread *tp, void *(*job_fn)(void *), t_job_type *job_data);
int			ft_tp_wait_for_queue(t_tp_thread *tp);

#endif
