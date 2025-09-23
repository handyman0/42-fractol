#include "../include/fractol.h"

int	run_celtic(t_fractal *fractal)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(fractal->c.x, fractal->c.y);
	while (z.x * z.x + z.y * z.y <= 4
		&& iteration < fractal->max_iteration)
	{
		z = init_complex(
				fabs(z.x * z.x - z.y * z.y) + fractal->c.x,
				2.0 * z.x * z.y + fractal->c.y);
		iteration++;
	}
	return (iteration);
}
