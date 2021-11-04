/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:06:39 by wleite            #+#    #+#             */
/*   Updated: 2021/11/04 02:00:31 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_all(t_stack *stack_a, t_stack *stack_b, t_stack *stack_c)
{
	return ;
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
	print_stack(stack_c, 'C');
}

static void	clrscr(int time)
{
	return ;
	sleep(time);
	printf("\e[1;1H\e[2J");
}

static void	transformice(int *ref_array, int ref_size,
	int *dst_array, int dst_size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ref_size)
	{
		j = -1;
		while (++j < dst_size)
			if (ref_array[i] == dst_array[j])
				dst_array[j] = i;
	}
}

void	sort_algo_a(t_data *data)
{
	int		len;
	t_stack	*stack_c;
	t_algo	*algo;

	algo = data->algo_a;
	init_stack(algo->stack_a, data->args, data->args_size);
	stack_c = new_stack(data->args_size);
	init_stack(stack_c, data->args, data->args_size);
	brute_sort(stack_c->items, stack_c->size);
	transformice(stack_c->items, stack_c->size,
		algo->stack_a->items, algo->stack_a->size);
	if (!valid_sort(algo))
	{
		len = data->args_size - 1;
		while (!is_sorted(algo->stack_a->items, algo->stack_a->size))
		{
			if (algo->stack_a->items[0] == 0
				|| algo->stack_a->items[0] == stack_c->items[len])
				do_op(RA, algo);
			else
				do_op(PB, algo);
		}
		while (algo->stack_b->size > 0)
		{
			push_b_to_a(algo->stack_a, algo->stack_b, algo, data->args_size);
			if (algo->stack_a->items[0] < algo->stack_b->items[0])
			{
				do_op(RA, algo);
				do_op(PA, algo);
			}
			else
				do_op(PA, algo);
		}
		go_to(algo->stack_a, algo, 0, 'a');
	}
	clrscr(1);
	print_all(algo->stack_a, algo->stack_b, stack_c);
	ft_free_ptr((void *)&stack_c->items);
	ft_free_ptr((void *)&stack_c);
}

// void	sort_algo_a(t_data *data)
// {
// 	int		chunk;
// 	int		n1;
// 	int		n2;
// 	int		pieces;
// 	int		pivot1;
// 	int		pivot2;
// 	int		mov1;
// 	int		mov2;
// 	t_stack	*stack_c;
// 	t_algo	*algo;

// 	algo = data->algo_a;
// 	init_stack(algo->stack_a, data->args, data->args_size);
// 	stack_c = new_stack(data->args_size);
// 	init_stack(stack_c, data->args, data->args_size);
// 	brute_sort(stack_c->items, stack_c->size);
// 	transformice(stack_c->items, stack_c->size,
// 		algo->stack_a->items, algo->stack_a->size);
// 	if (!valid_sort(algo))
// 	{
// 		pieces = 4;
// 		chunk = data->args_size / pieces;
// 		pivot1 = chunk * (pieces - 1);
// 		pivot2 = chunk * pieces;
// 		while (pivot2 > 0)
// 		{
// 			while (algo->stack_b->size < chunk)
// 			{
// 				if (algo->stack_a->items[0] >= pivot1 && algo->stack_a->items[0] <= pivot2)
// 					do_op(PB, algo);
// 				else
// 					do_op(RA, algo);
// 			}
// 			while (algo->stack_b->size > 0)
// 			{
// 				n1 = get_smallest_nbr(algo->stack_b->items, algo->stack_b->size);
// 				n2 = get_biggest_nbr(algo->stack_b->items, algo->stack_b->size);
// 				mov1 = get_moves(algo->stack_b, n1) + 1;
// 				mov2 = get_moves(algo->stack_b, n2);
// 				if (mov1 < mov2)
// 				{
// 					go_to(algo->stack_b, algo, n1, 'b');
// 					if (algo->stack_a->items[0] < n1)
// 					{
// 						do_op(RA, algo);
// 						do_op(PA, algo);
// 					}
// 					else
// 						do_op(PA, algo);
// 				}
// 				else
// 				{
// 					go_to(algo->stack_b, algo, n2, 'b');
// 					if (algo->stack_a->items[0] < n2)
// 					{
// 						do_op(RA, algo);
// 						do_op(PA, algo);
// 					}
// 					else
// 						do_op(PA, algo);
// 				}
// 			}
// 			pivot1 -= chunk;
// 			pivot2 -= chunk;
// 		}
// 		// while (!valid_sort(algo))
// 		// 	do_op(RRA, algo);

// 	}
// 	clrscr(1);
// 	print_all(algo->stack_a, algo->stack_b, stack_c);
// 	ft_free_ptr((void *)&stack_c->items);
// 	ft_free_ptr((void *)&stack_c);
// }

// void	sort_algo_a(t_data *data)
// {
// 	int		n;
// 	int		i;
// 	int		index;
// 	int		chunk;
// 	t_stack	*stack_c;
// 	t_algo	*algo;

// 	algo = data->algo_a;
// 	init_stack(algo->stack_a, data->args, data->args_size);
// 	stack_c = new_stack(data->args_size);
// 	init_stack(stack_c, data->args, data->args_size);
// 	brute_sort(stack_c->items, stack_c->size);
// 	transformice(stack_c->items, stack_c->size,
// 		algo->stack_a->items, algo->stack_a->size);
// 	if (!valid_sort(algo))
// 	{
// 		chunk = stack_c->size / 4;
// 		while (algo->stack_a->size > chunk * 3)
// 		{
// 			if (algo->stack_a->items[0] == stack_c->items[stack_c->size - 1])
// 				do_op(RA, algo);
// 			else if (algo->stack_a->items[0] <= chunk)
// 				do_op(PB, algo);
// 			else
// 				do_op(RA, algo);
// 		}
// 		while (algo->stack_a->size > chunk * 2)
// 		{
// 			if (algo->stack_a->items[0] == stack_c->items[stack_c->size - 1])
// 				do_op(RA, algo);
// 			else if (algo->stack_a->items[0] <= chunk * 2)
// 				do_op(PB, algo);
// 			else
// 				do_op(RA, algo);
// 		}
// 		while (algo->stack_a->size > chunk)
// 		{
// 			if (algo->stack_a->items[0] == stack_c->items[stack_c->size - 1])
// 				do_op(RA, algo);
// 			else if (algo->stack_a->items[0] <= chunk * 3)
// 				do_op(PB, algo);
// 			else
// 				do_op(RA, algo);
// 		}
// 		while (algo->stack_a->size > 1)
// 		{
// 			if (algo->stack_a->items[0] == stack_c->items[stack_c->size - 1])
// 				do_op(RA, algo);
// 			else
// 				do_op(PB, algo);
// 		}
// 		while (!stack_is_empty(algo->stack_b))
// 		{
// 			index = -1;
// 			i = 1;
// 			while(index == -1 && i <= stack_c->items[stack_c->size - 1])
// 			{
// 				n = algo->stack_b->items[0];
// 				index = get_index(algo->stack_a->items, algo->stack_a->size, n + i);
// 				i++;
// 			}
// 			go_to(algo->stack_a, algo, algo->stack_a->items[index], 'a');
// 			do_op(PA, algo);
// 		}
// 		index = get_index(algo->stack_a->items, algo->stack_a->size, 0);
// 		if (index > algo->stack_a->size / 2)
// 		{
// 			while (!stack_is_sorted(algo->stack_a))
// 				do_op(RRA, algo);
// 		}
// 		else
// 		{
// 			while (!stack_is_sorted(algo->stack_a))
// 				do_op(RA, algo);
// 		}
// 	}
// 	clrscr(1);
// 	print_all(algo->stack_a, algo->stack_b, stack_c);
// 	ft_free_ptr((void *)&stack_c->items);
// 	ft_free_ptr((void *)&stack_c);
// }

// void	sort_algo_a(t_data *data)
// {
// 	int	index_b;
// 	int	index_m;
// 	int	mid;
// 	t_stack	*stack_c;
// 	t_algo	*algo;

// 	algo = data->algo_a;
// 	init_stack(algo->stack_a, data->args, data->args_size);
// 	stack_c = new_stack(data->args_size);
// 	init_stack(stack_c, data->args, data->args_size);
// 	brute_sort(stack_c->items, stack_c->size);
// 	transformice(stack_c->items, stack_c->size,
// 		algo->stack_a->items, algo->stack_a->size);
// 	if (!valid_sort(algo))
// 	{
// 		mid = stack_c->items[(stack_c->size - 1) / 2];
// 		while (algo->stack_a->size > 1)
// 		{
// 			if (algo->stack_a->items[0] == mid || algo->stack_a->items[0] == 0)
// 				do_op(RA, algo);
// 			else
// 				do_op(PB, algo);
// 		}
// 		while (algo->stack_b->size > 0)
// 		{
// 			index_m = get_index(algo->stack_b->items, algo->stack_b->size, algo->stack_a->items[0] - 1);
// 			index_b = get_index(algo->stack_b->items, algo->stack_b->size, algo->stack_a->items[algo->stack_a->size - 1] + 1);

// 			if ((index_b - algo->stack_b->size - 1) < index_m && index_b < INT_MAX)
// 			{
// 				go_to(algo->stack_b, algo, algo->stack_a->items[algo->stack_a->size - 1] + 1, 'b');
// 				do_op(PA, algo);
// 			}
// 			else if (index_m <= (index_b - algo->stack_b->size - 1) && index_m < INT_MAX)
// 			{
// 				go_to(algo->stack_b, algo, algo->stack_a->items[0] - 1, 'b');
// 				do_op(PA, algo);
// 			}
// 			else
// 			{
// 				do_op(RA, algo);
// 			}
// 		}
// 		while (!valid_sort(algo))
// 			do_op(RA, algo);
// 	}
// 	clrscr(1);
// 	print_all(algo->stack_a, algo->stack_b, stack_c);
// 	ft_free_ptr((void *)&stack_c->items);
// 	ft_free_ptr((void *)&stack_c);
// }

// void	sort_algo_a(t_data *data)
// {
// 	int		i;
// 	int		j;
// 	int		n;
// 	t_stack	*stack_c;
// 	t_algo	*algo;

// 	algo = data->algo_a;
// 	init_stack(algo->stack_a, data->args, data->args_size);
// 	stack_c = new_stack(data->args_size);
// 	init_stack(stack_c, data->args, data->args_size);
// 	brute_sort(stack_c->items, stack_c->size);
// 	transformice(stack_c->items, stack_c->size,
// 		algo->stack_a->items, algo->stack_a->size);
// 	j = 0;
// 	i = 1;
// 	if (!valid_sort(algo))
// 	{
// 		 while (!valid_sort(algo))
// 		 {
// 			for (int i = 1; i <= data->args_size; i++)
// 			{
// 				n = algo->stack_a->items[0];
// 				if ((n >> j)&1)
// 				{
// 					do_op(PB, algo);
// 					do_op(RB, algo);
// 				}
// 				else
// 				{
// 					do_op(RA, algo);
// 				}
// 			}
// 			while(!stack_is_empty(algo->stack_b))
// 			{
// 				do_op(PA, algo);
// 				do_op(RA, algo);
// 			}
// 			j++;
// 		 }
// 	}
// 	clrscr(1);
// 	print_all(algo->stack_a, algo->stack_b, stack_c);
// 	ft_free_ptr((void *)&stack_c->items);
// 	ft_free_ptr((void *)&stack_c);
// }

// void	sort_algo_a(t_data *data)
// {
// 	int		i;
// 	int		j;
// 	int		n;
// 	t_stack	*stack_c;
// 	t_algo	*algo;

// 	algo = data->algo_a;
// 	init_stack(algo->stack_a, data->args, data->args_size);
// 	stack_c = new_stack(data->args_size);
// 	init_stack(stack_c, data->args, data->args_size);
// 	brute_sort(stack_c->items, stack_c->size);
// 	transformice(stack_c->items, stack_c->size,
// 		algo->stack_a->items, algo->stack_a->size);
// 	i = 0;
// 	n = 0;
// 	if (!valid_sort(algo))
// 	{
// 		void    perform_more_5(t_deque *a, t_deque *b, int size)====
// {
//     int     max_num;
//     int     max_bits;
//     int     num;
//     int     i;
//     int     j;

//     max_num = size - 1;
//     max_bits = 0;//최대 비트수
//     while ((max_num >> max_bits) != 0)
//         ++max_bits;
//     i = -1;
//     while (++i < max_bits)//비트 수 만큼 반복
//     {
//         j = -1;
//         while (++j < size)//숫자 개수만큼 반복
//         {
//             num = a->tail->data;
//             if (((num >> i) & 1) == 1)//최하위 비트가 1이면 a스택에 남김
//                 rotate(&a->head, &a->tail, 'a');
//             else //0이라면 b 스택에 넘김
//                 test_push(a, b, 'b');
//         }
//         while (!dq_is_empty(b))
//             test_push(b, a, 'a');//b스택에 있는 숫자들을 a로 넘김
//     }
// }

// int push_swap(t_queue *a, t_queue *b, int size)
// {
//     if (size <= 0)
//         return (1);
//     if (size == 1)
//         return (0);
//     if (size == 2 && /*a 스텍의 top이 top->next 보다 클 때*/)
//         sa(t_queue *a);
//     if (size == 3)
//         perform_3.......
// ....
// }====
// 	}
// 	clrscr(1);
// 	print_all(algo->stack_a, algo->stack_b, stack_c);
// 	ft_free_ptr((void *)&stack_c->items);
// 	ft_free_ptr((void *)&stack_c);
// }


// void	sort_algo_a(t_data *data)
// {
// 	int		i;
// 	int		j;
// 	int		n;
// 	t_stack	*stack_c;
// 	t_algo	*algo;

// 	algo = data->algo_a;
// 	init_stack(algo->stack_a, data->args, data->args_size);
// 	stack_c = new_stack(data->args_size);
// 	init_stack(stack_c, data->args, data->args_size);
// 	brute_sort(stack_c->items, stack_c->size);
// 	transformice(stack_c->items, stack_c->size,
// 		algo->stack_a->items, algo->stack_a->size);
// 	i = 0;
// 	n = 0;
// 	if (!valid_sort(algo))
// 	{
// 		while (!is_sorted(algo->stack_a->items, algo->stack_a->size))
// 		{
// 			j = 0;
// 			while (j < data->args_size)
// 			{
// 				n = algo->stack_a->items[0];
// 				if ((n >> i)&1)
// 					do_op(RA, algo);
// 				else
// 					do_op(PB, algo);
// 				j++;
// 			}
// 			while(!stack_is_empty(algo->stack_b))
// 			{
// 				// if (algo->stack_b->items[0] > algo->stack_b->items[1])
// 				// 	do_op(SB, algo);
// 				do_op(PA, algo);
// 			}
// 			i++;
// 		}
// 	}
// 	clrscr(1);
// 	print_all(algo->stack_a, algo->stack_b, stack_c);
// 	ft_free_ptr((void *)&stack_c->items);
// 	ft_free_ptr((void *)&stack_c);
// }

// void	sort_algo_a(t_data *data)
// {
// 	int		i;
// 	t_stack	*stack_c;
// 	t_algo	*algo;

// 	algo = data->algo_a;
// 	init_stack(algo->stack_a, data->args, data->args_size);
// 	stack_c = new_stack(data->args_size);
// 	init_stack(stack_c, data->args, data->args_size);
// 	brute_sort(stack_c->items, stack_c->size);
// 	if (!valid_sort(algo))
// 	{
// 		i = 0;
// 		while (!stack_is_empty(algo->stack_a))
// 		{
// 			while (stack_c->items[i] != algo->stack_a->items[0])
// 				do_op(RRA, algo);
// 			if (stack_c->items[i] == algo->stack_a->items[0])
// 			{
// 				do_op(PB, algo);
// 				i++;
// 			}
// 			if (i == stack_c->size)
// 				i = 0;
// 		}
// 		while (!stack_is_empty(algo->stack_b))
// 			do_op(PA, algo);
// 	}
// 	clrscr(1);
// 	(void)transformice;
// 	print_all(algo->stack_a, algo->stack_b, stack_c);
// 	ft_free_ptr((void *)&stack_c->items);
// 	ft_free_ptr((void *)&stack_c);
// }
