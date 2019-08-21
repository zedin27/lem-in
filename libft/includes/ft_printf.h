/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:07:24 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/05 15:35:14 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

int				ft_printf(const char *format, ...);

typedef struct	s_flag
{
	int		hl;
	int		sign;
	int		precis;
	int		zero;
	int		space;
	int		hash;
	int		neg;
}				t_flag;

int				ft_printf(const char *format, ...);
int				dispatcher(va_list ap, int i, const char *format);
void			capture_the_flag(const char *f, int t, t_flag *flag);

void			increment(const char *format, int *i);
void			increment_error(const char *format, int *i, int *b);

int				check_error(const char *f, int i);
int				check_flag_hl(const char *f, int t);
int				flag_0(const char *f, int t);
int				get_space_number(const char *f, int t, t_flag flag);
int				get_hash(const char *f, int t);
void			flag_space(t_flag flag, int *ret);
void			flag_space_str(t_flag flag, int *ret);
void			flag_space_hex(t_flag flag, int *ret);
void			flag_space_o(t_flag flag, int *ret);
void			flag_space_x(t_flag flag, int *ret);
void			flag_space_f(t_flag flag, int *tmp, int tmpo);
void			flag_space_percent(const char *f, int nb, int t, int *ret);
void			flag_space_neg(int space, int nb, int *ret);
int				flag_space_neg_nb_error(const char *f, int t);

void			ft_nblen(long long nb, int base, int *sum);
void			ft_nblen_double(long long nb, int *sum);
void			ft_nblen_unsign(unsigned long long nb, int base, int *ret);
void			flag_space_neg_print_error(int b, int *sum);
int				flag_plus_space(const char *f, int t);
int				flag_plus_space_percent(const char *f, int t);
void			print_flag_plus_space(t_flag flag, int var, int *ret);
void			print_flag_plus_space1(t_flag flag, int *var, int *ret);
void			print_flag_plus_space_uns(int sign, int zero,
		unsigned long long *ret);
void			print_flag_plus_space1_uns(int sign, int zero,
		unsigned long long *var, unsigned long long *ret);
int				get_precision(const char *f, int t, int *ret);
int				get_precision2(const char *f, int t);
int				flag_precision(const char *f, int t);
void			flag_precision_nb(t_flag flag, int size, int *ret);
void			flag_hashxmaj(t_flag flag);
void			flag_hashx(t_flag flag);
void			flag_hasho(t_flag flag);
void			flag_hashf(t_flag flag);

int				ft_print_char(va_list ap, t_flag flag);
int				ft_print_string(va_list ap, t_flag flag);
int				ft_print_number(va_list ap, t_flag flag);
int				ft_print_hex(t_flag flag, va_list ap);
int				ft_print_octal(va_list ap, t_flag flag);
int				ft_print_unsign(va_list ap, t_flag flag);
int				ft_print_uhex(va_list ap, t_flag flag);
int				ft_print_uhexmaj(va_list ap, t_flag flag);
int				ft_print_float(va_list ap, t_flag flag);
int				ft_print_percent(t_flag flag, const char *f, int t);

void			ft_putnbr_base(long long nb, int base);
void			ft_putnbr_base_addr(unsigned long long nb, int base, int *ret);
void			ft_putnbr_basemaj(long long nb, int base);
void			ft_putnbr_double(long double nb, int size);
void			ft_putnbr_long_double(long double nb, int size);

void			ft_putnbr_unsign(unsigned long long nb, int base);
void			ft_putnbr_unsign_maj(unsigned long long nb, int base);
void			ft_nblen(long long nb, int base, int *sum);
void			ft_nblen_double(long long nb, int *sum);
void			ft_nblen_unsign(unsigned long long nb, int base, int *ret);
void			ft_putnstr(const char *str, int size);

void			get_var(t_flag flag, int *var, va_list ap);
int				ender(t_flag flag, int *nb);
void			gain_space_mid(int var, t_flag flag, char *a, int *size);
void			gain_space_mid1(t_flag flag, int *nb, int var);

#endif
