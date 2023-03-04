#include "move_actors.h"
#include "actor.h"
#include "output_service.h"
#include <vector>
#include <memory>
using std::vector;
using std::shared_ptr;
using ActorPtr = shared_ptr<Actor>;

void MoveActors::run() {
	output_service->updateTime();
	double delta_time = output_service->deltaTime();

	vector<ActorPtr> actors = cast->getAllActors();
	for (auto &actor : actors)
		actor->update(delta_time);

}