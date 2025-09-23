#include "../include/fractol.h"

int	run_julia(t_fractal *fractal)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(fractal->c.x, fractal->c.y);
	while (z.x * z.x + z.y * z.y <= 4
		&& iteration < fractal->max_iteration)
	{
		z = init_complex(
				z.x * z.x - z.y * z.y + fractal->k.x,
				2.0 * z.x * z.y + fractal->k.y);
		iteration++;
	}
	return (iteration);
}
