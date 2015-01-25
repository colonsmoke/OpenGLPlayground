#version 120

attribute vec3 position;
attribute vec2 texCoord;

varying vec2 newTexCoord;

void main()
{
	newTexCoord = texCoord;
	gl_Position = vec4(position, 1.0);
}
