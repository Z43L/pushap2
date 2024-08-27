/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:30:55 by davmoren          #+#    #+#             */
/*   Updated: 2024/05/19 21:39:31 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../LIBFT/libft.h"
# include <stdarg.h>
#include <stdbool.h>

int	ft_printf(const char *format, ...);
int	ft_putchard(char c);
int	ft_putsrtd(char *s, int fd);
int	ft_putnbrd_base(long c, int base, int len, bool tof);

#endif