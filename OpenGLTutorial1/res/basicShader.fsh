#version 120

uniform sampler2D diffuse;
vec3 lightDirection = vec3(0,0,1);

varying vec2 texCoord0;
varying vec3 normal0;

void main(void)
{
	gl_FragColor = texture2D(diffuse, texCoord0)
		* clamp(dot(-lightDirection, normal0), 0.0, 1.0);
}
