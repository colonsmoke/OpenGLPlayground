#version 120

attribute vec3 position;
attribute vec2 texCoord;

varying vec2 newTexCoord;

uniform mat4 transform;

void main()
{
	newTexCoord = texCoord;
	gl_Position = transform * vec4(position, 1.0);
}
