/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_controller.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:17:41 by eouhrich          #+#    #+#             */
/*   Updated: 2025/01/26 20:43:22 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAP_CONTROLLER_H
# define HEAP_CONTROLLER_H
# include <stdlib.h>
# include <unistd.h>

//==== struct of HEAP CONTROLLER =====
typedef struct s_heap
{
	void			*ptr;
	struct s_heap	*next;
}					t_heap;

//====================================
// the api functions to use

void		*mallocate(size_t size);	// instead of malloc
void		free_ptr(void *ptr);		// instead of free
void		free_all_heap(void);
void		exiter(int code);			// instead of exit
#endif
