#include "playable.h"

Playable::Playable(float pX, float pY, float pZ, std::string modelName)
	:Character(pX,pY,pZ,modelName){}

Playable::~Playable() {
	delete(myCamera);
	delete(myPad);
}