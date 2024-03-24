/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:01:09 by uxmancis          #+#    #+#             */
/*   Updated: 2024/03/24 16:06:49 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//objective: to avoid writing LOCK and UNLOCK everywhere

//bool:
void set_bool(t_mtx *mutex, bool *dst, bool value)
{
    safe_mutex_handle(mutex, LOCK);
    *dst = value;
    safe_mutex_handle(mutex, UNLOCK);
}

bool get_bool (t_mtx *mutex, bool *value)
{
    bool ret;

    safe_mutex_handle(mutex, LOCK);
    //READING thread safe
    ret = *value;
    safe_mutex_handle(mutex, UNLOCK);
    return (ret);
}

long get_long(t_mtx *mutex, long *value)
{
    long ret;

    safe_mutex_handle(mutex, LOCK);
    ret = *value;
    safe_mutex_handle(mutex, UNLOCK);
    return (ret);
}

void set_long(t_mtx *mutex, long *dest, long value)
{
    safe_mutex_handle(mutex, LOCK);
    *dst = value;
    safe_mutex_handle(mutex, UNLOCK);
}

//redundant?¿
bool simulation_finished(t_table *table)
{
    return (get_bool(&table->table_mutex, &table->end_simulation));
}