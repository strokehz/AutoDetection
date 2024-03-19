#ifndef RESOLUTION_H_
#define RESOLUTION_H_

#include "States/ResolutionStates.h"

namespace Screen
{
	class Resolution
	{
	public:
		Resolution(ResolutionState& state_);
	private:
		ResolutionState& state;
	};
}

#endif // !RESOLUTION_H_
