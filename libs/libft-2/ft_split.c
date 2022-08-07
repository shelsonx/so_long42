/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:06:28 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/06/14 14:43:15 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_words(char const *s, char delimiter)
{
	size_t	i;
	size_t	num;

	i = 0;
	num = 0;
	while (s[i])
	{
		while (s[i] == delimiter)
			i++;
		if (s[i])
		{
			while (s[i] && s[i] != delimiter)
				i++;
			num++;
		}
	}
	return (num);
}

static size_t	len_word(char const *s, char delimiter, int i)
{
	size_t	c;

	c = 0;
	while (s[i] && s[i] != delimiter)
	{
		i++;
		c++;
	}
	return (c);
}

static char	**ft_alloc_words(char const *str, char c)
{
	char	**tab;

	tab = (char **) malloc((num_words(str, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	return (tab);
}

static char	*ft_alloc_word(char const *str, char c, int i)
{
	char	*word;

	word = (char *) malloc((len_word(str, c, i) + 1) * sizeof(char));
	if (!word)
		return (NULL);
	return (word);
}

char	**ft_split(char const *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	w;
	char	**tab;

	tab = ft_alloc_words(str, c);
	i = 0;
	j = 0;
	while (str[i])
	{
		w = 0;
		while (str[i] == c)
			i++;
		if (str[i])
		{
			tab[j] = ft_alloc_word(str, c, i);
			while (str[i] && str[i] != c)
				tab[j][w++] = str[i++];
			tab[j][w] = '\0';
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
