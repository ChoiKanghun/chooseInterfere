char	*ft_flags(char *flags, char format, int flag_neg, int flag_zero, char *output)
{
	char	*dest;
	int	w = 0;
	int	p = 0;
	char	*precision;
	char	*width;
	int	nbr_pad;
	int	flag_prec = 0;

	int	width_len = 0;
	while (ft_isdigit(flags[width_len]))
		width_len++;
	width = ft_strnew(width_len);

	int	i = 0;
	while (ft_isdigit(flags[i]))
	{
		width[i] = flags[i];
		i++;
	}
	if (i != 0)
		w = ft_atoi(width);
	int	precision_len = 0;
	int	tmp = width_len;
	while (ft_isdigit(flags[tmp]) || flags[tmp] == '.')
	{
		precision_len++;
		tmp++;
	}
	precision = ft_strnew(precision_len);
	i = 0;
	if (flags[width_len] == '.')
	{
		flag_prec = 1;
		width_len++;
		while (ft_isdigit(flags[width_len]))
			precision[i++] = flags[width_len++];
		p = ft_atoi(precision);
	}
	free(width);	//문제되는가 보기
	free(precision);	//문제되는가 보기

	char	*padding;
	int	k = 0;
	if (p < ft_strlen(output) && format == 's')
		output = ft_substr(output, 0, p);
	else if (flag_zero == 1 && p == 0 && flag_prec == 1)
	{
		//free(output);
		output = ft_strnew(1);
		output[0] = 1;
	}
	else if (p > ft_strlen(output) && flag_neg == 0 && (format == 'd' || format == 'x'))
	{
		nbr_pad = p - ft_strlen(output);
		padding = ft_strnew(nbr_pad);
		while (nbr_pad)
		{
			padding[k] = '0';
			k++;
			nbr_pad--;
		}
		output = ft_strjoin(padding, output);
		//char *tmp를 써서 free시켜보자 output도.
		free(padding);
	}
	else if (p > ft_strlen(output) - 1 && flag_neg == 1 && format == 'd')
	{
		nbr_pad = p - ft_strlen(output) + 1;
		padding = ft_strnew(nbr_pad + 1);
		padding[k++] = '-';
		while (nbr_pad)
		{
			padding[k] = '0';
			k++;
			nbr_pad--;
		}
		output = ft_substr(output, 1, ft_strlen(output) - 1);
		output = ft_strjoin(padding, output);
		free(padding);
	}
	k = 0;
	if (w > ft_strlen(output))
	{
		nbr_pad = w - ft_strlen(output);
		padding = ft_strnew(nbr_pad);
		while (nbr_pad)
		{
			padding[k] = ' ';
			nbr_pad--;
			k++;
		}
		output = ft_strjoin(padding, output);
		free(padding);
	}
	return (output);
}
