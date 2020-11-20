/************************************************************************************
***
***	Copyright 2020 Dell(18588220928g@163.com), All Rights Reserved.
***
***	File Author: Dell, 2020-11-20 16:49:57
***
************************************************************************************/

#include "bm3d.h"

#include "bm3d_implement.cpp"

int denoise(unsigned char *imgdata, int channels, int height, int width, unsigned int *sigmas, unsigned char *outdata, int debug)
{
	BM3D bm3d;

	if (!imgdata || channels != 1 || channels != 3 || height < 1 || width < 1 || !sigmas || !outdata)
		return RET_ERROR;

	// // (n, k, N, T, p, sigma, L3D)
	bm3d.set_hard_params(19, 8, 16, 2500, 3, 2.7f);
	bm3d.set_wien_params(19, 8, 32, 400, 3);
	bm3d.set_verbose(debug);
	bm3d.denoise_host_image(imgdata, outdata, width, height, channels, sigmas, 1/*twostep*/);

	return RET_OK;
}
