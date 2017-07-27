const sampler_t sampler = CLK_NORMALIZED_COORDS_FLASE | CLK_FILTER_NEA

kernel void	mandelbrot(write_only image2d_t output, float width, float height, int iter)
{

	size_t x = get_global_id(0);
	size_t y = get_global_id(1);

	float2 z, c;

	c.x = (float)width /(float)height * ((float)x / width - 0.5) * 2.2 - 0.7;
	c.y = ((float)y / height - 0.5) *2.2 - 0.0;

	int i;
	z = c;

	while (i < iter)
	{
		float x = (z.x * z.x - z.y * z.y) + c.x;
		float y = (z.y * z.x + z.x * z.y) + c.y;
		
		if ((x * x + y * y) > 4.)
			break;
		z.x = x;
		z.y = y;
		i++;
	}
	float p = (float)i / (float)iter;
	float so = sin(p * 3.141592652) * 255.;
	float co = (1 - cos(p * 3.141592652)) * 255.;
	
	write_imageui(output, (int2)(x,y), (uint4)((uint)co, co, (uint)(co + so), 255));

}
