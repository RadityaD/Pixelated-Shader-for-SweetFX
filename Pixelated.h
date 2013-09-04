
//Raditya D.

	int screenW = 900;
	int screenH = 1600;
	float2 pixelatedUV;
	float pixelationFactor = 8.0;

float4 PixelPass(float4 colorInput, float2 tex : TEXCOORD0) : COLOR0
{
	
	float2 pixelatedUV;
	
	float downscaleW = pixelationFactor;
	float downscaleH = (screenH / screenW) * pixelationFactor;
	
	tex.xy *= float2(screenW, screenH);
	
	
	pixelatedUV.x = round(tex.x / downscaleW) * downscaleW ;
	pixelatedUV.y = round(tex.y / downscaleH) * downscaleH ;
	
	pixelatedUV.xy /= float2(screenW, screenH);
	
	colorInput.rgb = myTex2D(colorTex,pixelatedUV).rgb;
	return colorInput;
}