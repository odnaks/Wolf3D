/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmarks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 22:31:57 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/24 21:50:49 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <time.h>
#include <stdio.h>

void	benchmark(t_engine *engine)
{
	clock_t	start;
	clock_t	end;
    double cpu_time_used;

	start = clock();
	render(engine);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	//printf("%f\n", cpu_time_used);
}
