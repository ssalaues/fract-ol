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

}

}
