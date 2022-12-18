/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   minitalk_client.h                                  :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: dafranco <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/12/12 23:43:59 by dafranco		  #+#	#+#			 */
/*   Updated: 2022/12/13 00:24:50 by dafranco         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#ifndef MINITALK_CLIENT_H
# define MINITALK_CLIENT_H 

struct s_sigaction
{
	void		(*sa_handler)(int);
	void		(*sa_sigaction)(int, siginfo_t *, void *);
	sigset_t	sa_mask;
	int			sa_flags;
	void		(*sa_restorer)(void);
};	t_sigaction

#endif
