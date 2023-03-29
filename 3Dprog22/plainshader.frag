#version 410 core

in vec4 color;              //color received from the pipeline (and vertex shader)
out vec4 fragmentColor;     //color sent to fragment on screen

uniform float ambientStrength = 0.8;  // controls the shade of ambient light. It is multiplied with fragment's colour to get the correct saturation
/* how does this work in scenes with varied light? if you walk from dark to light, the colour wouldn't change, but how do we correct the ambient light? */
// uniform lets us send in values to overwrite, if nothing is sent in, then 1 is used
// uniform is to remain unchanged per object- do he mean instance? of object
// low numbers low light, high numbers high light

uniform vec4 ambientColour = vec4(1, 0, 0, 0); // controls the colour of the light, used as ambientStrength
// !! vec4*vec4 here the components are multiplied together (here x*x* ambientStrength, y*y*ambientStrength, z*z*ambientStrength, and alpha*alpha*ambientStrength
// not dot or cross product

void main() {
   fragmentColor = color * ambientColour * ambientStrength;   //color given to current fragment (pixel)
}
