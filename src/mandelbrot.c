#include "../include/fractol.h"

void	run_mandelbrot(t_fractal *fractal)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(fractal->c.x, fractal->c.y);
	while(pow(z.x, 2.0) + pow(z.y, 2.0) <= 4
		&& iteration < fractal->max_iteration)
	{
		z = init_complex(
			pow(z.x, 2.0) - pow(z.y, 2.0) + fractal->c.x,
			2.0 * z.x * z.y + fractal->c.y);
		iteration++;
	}
	return (iteration);
}
