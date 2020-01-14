/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:18:45 by npimenof          #+#    #+#             */
/*   Updated: 2020/01/13 13:31:41 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# define FLAGS "0123456789.*#+- Llh"
# define SPECIFIERS "bcfidopsux"

typedef struct	s_conv_data
{
	char		specifier;
	char		*flags;
	char		*width;
	char		*precision;
	int			size;
}				t_conv_data;

typedef struct s_list	t_list;

int				ft_printf(const char *format, ...);
char			*ft_saprintf(const char *format, ...);
int				ft_fndigitis(long double n);
t_list			*process_format(const char *format, va_list a_list);
char			*ft_print_float(long double n, int prec, t_conv_data *data);
char			*c_specifier(va_list a_list, t_conv_data *data);
char			*i_specifier(va_list a_list, t_conv_data *data);
char			*u_specifier(va_list a_list, t_conv_data *data);
char			*s_specifier(va_list a_list, t_conv_data *data);
char			*f_specifier(va_list a_list, t_conv_data *data);
char			*x_specifier(va_list a_list, t_conv_data *data);
char			*o_specifier(va_list a_list, t_conv_data *data);
char			*p_specifier(va_list a_list, t_conv_data *data);
char			*b_specifier(va_list a_list, t_conv_data *data);
char			*inv_specif(va_list a_list, t_conv_data *data);
char			*zero_flag(char *str, size_t len, t_conv_data *data, char *s2);
char			*hash_flag(char *str, size_t len, t_conv_data *data, char *s2);
char			*plus_flag(char *str, size_t len, t_conv_data *data, char *s2);
char			*spac_flag(char *str, size_t len, t_conv_data *data, char *s2);
char			*dash_flg1(char *str, size_t len, t_conv_data *data, char *s2);
char			*dash_flg2(char *str, char *pad, t_conv_data *data);
void			get_type(void *p, t_conv_data *data);
void			*ft_memjoin(const void *s1, const void *s2,
							size_t len1, size_t len2);
t_conv_data		*read_flags(char *str, va_list a_list);

typedef struct	s_action
{
	char		spec;
	char		*(*f)();
}				t_action;

#endif
