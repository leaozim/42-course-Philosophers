/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_colors.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:51:21 by lade-lim          #+#    #+#             */
/*   Updated: 2023/02/06 12:10:37 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_COLORS_H
# define PRINTF_COLORS_H

// regular

# define L_RED			"\e[0;38;5;9m\002"
# define D_GREEN		"\e[0;38;5;22m\002"
# define V_GREEN		"\e[0;38;5;82m\002"
# define P_GREEN		"\e[0;38;5;23m\002"
# define V_BLUE			"\e[0;38;5;27m\002"
# define P_BLUE			"\e[0;38;5;24m\002"
# define V_CYAN			"\e[0;38;5;44m\002"
# define PURPLE			"\e[0;38;5;93m\002"
# define LILAC			"\e[0;38;5;13m\002"
# define PINK			"\e[0;38;5;199m\002"
# define L_YELLOW		"\e[0;38;5;191m\002"
# define L_GRAY			"\e[0;38;5;245m\002"
# define ORANGE			"\e[0;38;5;166m\002"
# define V_ORANGE		"\e[0;38;5;202m\002"

//Regular text
# define BLACK   "\001\e[0;30m\002"
# define RED     "\001\e[0;31m\002"
# define GREEN   "\001\e[0;32m\002"
# define YELLOW  "\001\e[0;33m\002"
# define BLUE    "\001\e[0;34m\002"
# define MAGENTA "\001\e[0;35m\002"
# define CYAN    "\001\e[0;36m\002"
# define WHITE   "\001\e[0;37m\002"

//Regular underline text
# define UBLACK   "\001\e[4;30m\002"
# define URED     "\001\e[4;31m\002"
# define UGREEN   "\001\e[4;32m\002"
# define UYELLOW  "\001\e[4;33m\002"
# define UBLUE    "\001\e[4;34m\002"
# define UMAGENTA "\001\e[4;35m\002"
# define UCYAN    "\001\e[4;36m\002"
# define UWHITE   "\001\e[4;37m\002"

//Regular background
# define BLACKB   "\001\e[40m\002"
# define REDB     "\001\e[41m\002"
# define GREENB   "\001\e[42m\002"
# define YELLOWB  "\001\e[43m\002"
# define BLUEB    "\001\e[44m\002"
# define MAGENTAB "\001\e[45m\002"
# define CYANB    "\001\e[46m\002"
# define WHITEB   "\001\e[47m\002"

//High intensty background
# define BLACKHB   "\001\e[0;100m\002"
# define REDHB     "\001\e[0;101m\002"
# define GREENHB   "\001\e[0;102m\002"
# define YELLOWHB  "\001\e[0;103m\002"
# define BLUEHB    "\001\e[0;104m\002"
# define MAGENTAHB "\001\e[0;105m\002"
# define CYANHB    "\001\e[0;106m\002"
# define WHITEHB   "\001\e[0;107m\002"

//High intensty text
# define HBLACK   "\001\e[0;90m\002"
# define HRED     "\001\e[0;91m\002"
# define HGREEN   "\001\e[0;92m\002"
# define HYELLOW  "\001\e[0;93m\002"
# define HBLUE    "\001\e[0;94m\002"
# define HMAGENTA "\001\e[0;95m\002"
# define HCYAN    "\001\e[0;96m\002"
# define HWHITE   "\001\e[0;97m\002"

//Bold high intensity text
# define BHBLACK   "\001\e[1;90m\002"
# define BHRED     "\001\e[1;91m\002"
# define BHGREEN   "\001\e[1;92m\002"
# define BHYELLOW  "\001\e[1;93m\002"
# define BHBLUE    "\001\e[1;94m\002"
# define BHMAGENTA "\001\e[1;95m\002"
# define BHCYAN    "\001\e[1;96m\002"
# define BHWHITE   "\001\e[1;97m\002"

//Reset
# define RESET       "\001\e[0m\002"
# define CRESET      "\001\e[0m\002"
# define COLOR_RESET "\001\e[0m\002"

#endif