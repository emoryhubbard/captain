#include "cast.h"
#include "output_service.h"
#include "input_service.h"
#include "script.h"
#include "director.h"
using cast::Cast;
using director::Director;

int main() {
    Cast cast;
    InputService input_service;
    OutputService output_service;
    Script script;

    Director director(cast, input_service, output_service,
        script);
    director.startGame();
}
