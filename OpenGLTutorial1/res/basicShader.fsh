#version 120

uniform sampler2D diffuse;

varying vec2 newTexCoord;

void main(void)
{
	gl_FragColor = texture2D(diffuse, newTexCoord);
}
