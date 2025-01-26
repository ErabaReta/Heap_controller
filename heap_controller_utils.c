/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_controller_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:58:14 by eouhrich          #+#    #+#             */
/*   Updated: 2025/01/26 19:04:07 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap_controller.h"

// code to be executed before exitig ..
void	exiter(int code)
{
	free_all_heap();
	exit(code);
}
