#ifndef ITER_HPP
# define ITER_HPP

template <typename A, typename L, typename F>
void	iter(A& a, L len, F f)
{
	for (int i = 0; i < len; i++)
		f(a[i]);
}

#endif