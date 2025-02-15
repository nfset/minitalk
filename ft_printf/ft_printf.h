/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfset <nfset@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:25:01 by apieniak          #+#    #+#             */
/*   Updated: 2025/01/13 19:17:03 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int		format_par(char c, va_list arg);
int		ft_printf(const char *string, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_hex(unsigned int n);
int		ft_hex_up(unsigned int n);
int		ft_udec(unsigned int num);
int		ft_print_ptr(unsigned long long ptr);
void	ft_put_ptr(unsigned long long num);

#endif
