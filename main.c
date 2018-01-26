/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:57:33 by ckrommen          #+#    #+#             */
/*   Updated: 2018/01/25 18:52:35 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	main()
{

    ft_printf("NORMAL STRING ARGS\n%s%s\n", "string", "new");
	printf("%s%s\n\n", "string", "new");
	ft_printf("%s\n", "Try to reboot the GB bus, maybe it will connect the 1080p alarm!");
	printf("%s\n", "Try to reboot the GB bus, maybe it will connect the 1080p alarm!");

	ft_printf("WIDTH AND PREC ON DECIMALS\n_%-9.7d_\n", 1234);
	printf("_%-9.7d_\n\n", 1234);
	ft_printf("_%9.7d_\n", 1234);
	printf("_%9.7d_\n\n", 1234);
	ft_printf("_%7.7d_\n", 1234);
	printf("_%7.7d_\n\n", 1234);
	ft_printf("_%10.7d_\n", 1234);
	printf("_%10.7d_\n\n", 1234);
	ft_printf("_%.7d_\n", 1234);
	printf("_%.7d_\n\n", 1234);
	ft_printf("_%.7d_\n", 1234);
	printf("_%.7d_\n\n", 1234);

	ft_printf("USING THE + FLAG ON DECIMALS\n_%+.7d_\n", 1234);
	printf("_%+.7d_\n\n", 1234);
	ft_printf("_%+.7d_\n", 1234);
	printf("_%+.7d_\n\n", 1234);
	ft_printf("_%-+7d_\n", 1234);
	printf("_%+-7d_\n\n", 1234);
	ft_printf("_%+.7d_\n", -1234);
	printf("_%+.7d_\n\n", -1234);
	ft_printf("%+-6.8d\n", -234567890);
	printf("%+-6.8d\n\n", -234567890);

	ft_printf("USING THE SPACE FLAG\n");
	ft_printf("% 05d\n",-2035065302);
	printf("% 05d\n",-2035065302);
	ft_printf("% 05d\n", 2035065302);
	printf("% 05d\n", 2035065302);
	ft_printf("% 05d\n",-7);
	printf("% 05d\n",-7);
	ft_printf("% 05d\n",0);
	printf("% 05d\n",0);

    ft_printf("WIDTH ON STRING ARGS\n_%6s_\n", "string");
	printf("_%6s_\n\n", "string");
    ft_printf("_%4s_\n", "string");
	printf("_%4s_\n\n", "string");
    ft_printf("_%-7s_\n", "string");
	printf("_%-7s_\n\n", "string");
    ft_printf("_%-10s_\n", "string");
	printf("_%-10s_\n\n", "string");
    ft_printf("_%15s_\n", "string");
	printf("_%15s_\n\n", "string");
    ft_printf("_%-1s_\n", "string");
	printf("_%-1s_\n\n", "string");

	printf("EDGE CASES WITH +/-\n\n");
	ft_printf("%++++++05d\n",7);
	printf("%+++++05d\n",7);
	ft_printf("%++++++05d\n",-7);
	printf("%+++++05d\n",-7);
	ft_printf("%+05d\n",-2035065302);
	printf("%+05d\n",-2035065302);

	printf("FLAGS\n");
	ft_printf("%%\n");
	printf("%%\n\n");
	ft_printf("% %\n");
	printf("% %\n\n");
	ft_printf("%+%\n");
	printf("%+%\n\n");
	ft_printf("%-%\n");
	printf("%-%\n\n");

	ft_printf("CONVERSIONS\n");

	ft_printf("PRINTING MEMORY/HEXADECIMAL\n");
	ft_printf("%p\n", "string");
	printf("%p\n\n", "string");
	ft_printf("%x\n", 12345);
	printf("%x\n\n", 12345);
	ft_printf("%X\n", 123456789);
	printf("%X\n\n", 123456789);
	ft_printf("%#p\n", (void *)123456789);
	printf("%p\n\n", (void *)123456789);
	ft_printf("%#x\n", 123456789);
	printf("%#x\n\n", 123456789);
	ft_printf("%#X\n", 123456789);
	printf("%#X\n\n", 123456789);

	ft_printf("PRINTING OCTAL\n");
	ft_printf("%o\n", 123456);
	printf("%o\n\n", 123456);
	ft_printf("%O\n", 123456);
	printf("%O\n\n", 123456);
	ft_printf("%#O\n", 12);
	printf("%#O\n\n", 12);

	ft_printf("INVISIBLE PLUS SIGN\n");
	ft_printf("%+d\n", 234567890);
	printf("%+d\n\n", 234567890);

	ft_printf("FORMAT SPECIFIERS\n");
	ft_printf("hh%hhs\n", "string");
	ft_printf("h%hs\n", "string");
	ft_printf("l%ls\n", "string");
	ft_printf("ll%lls\n", "string");
	ft_printf("j%js\n", "string");
	ft_printf("z%zs\n\n\n", "string");
	ft_printf("%hd\n", (short)12345);
	printf("%hd\n\n", (short)12345);
	ft_printf("%hhd\n", (char)12345);
	printf("%hhd\n\n", (char)12345);
	ft_printf("%ld\n", (long)12345);
	printf("%ld\n\n", (long)12345);
	ft_printf("\n%lld\n", (long long)LL_MAX);
	printf("%lld\n\n", (long long)LL_MAX);
	ft_printf("\n%lld\n", (long long)LL_MIN);
	printf("%lld\n\n", (long long)LL_MIN);
	ft_printf("%jd\n", (intmax_t)12345);
	printf("%jd\n\n", (intmax_t)12345);
	ft_printf("%zd\n", (size_t)3221225472);
	printf("%zd\n\n", (size_t)3221225472);
	ft_printf("%lld\n", (long long)-12345);
	printf("%lld\n\n", (long long)-12345);
	ft_printf("%d\n", INT_MAX);
	printf("%d\n\n", INT_MAX);
	ft_printf("%u\n", (unsigned int)4294967295);
	printf("%u\n\n", (unsigned int)4294967295);
	ft_printf("%U\n", (unsigned int)4294967295);
	printf("%U\n\n", (unsigned int)4294967295);
	ft_printf("%zu\n", 4294967295);
	printf("%zu\n\n", 4294967295);
	return 1;
}
