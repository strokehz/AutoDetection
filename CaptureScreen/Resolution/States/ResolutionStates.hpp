#ifndef RESOLUTION_STATES_H_
#define RESOLUTION_STATES_H_

namespace Screen
{
	struct ResolutionState
	{
		bool enabled{ true };
		bool resolution_changed{ false };

		int count_monitor = 0;

		int x = -1;
		int y = -1;
	};
}

#endif // !RESOLUTION_STATES_H_
