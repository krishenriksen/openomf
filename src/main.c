#include "engine.h"
#include "utils/log.h"
#include <SDL2/SDL.h>
#include <dumb/dumb.h>
#include <libconfig.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check arguments
    if(argc >= 2) {
        if(strcmp(argv[1], "-v") == 0) {
        
        }
    }

    // Init log
    if(log_init(0)) {
        printf("Error while initializing log!\n");
        return 1;
    }
    
    // Init libDumb
    dumb_register_stdfiles();
    
    // Init SDL2
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER)) {
        ERROR("SDL2 Initialization failed: %s", SDL_GetError());
        return 1;
    }
    SDL_version sdl_linked;
    SDL_GetVersion(&sdl_linked);
    DEBUG("Found SDL v%d.%d.%d", sdl_linked.major, sdl_linked.minor, sdl_linked.patch);
    
    // Initialize engine
    if(engine_init()) {
        goto exit_0;
    }
    
    // Run
    engine_run();
    
    // Close everything
    engine_close();
exit_0:
    SDL_Quit();
    dumb_exit();
    DEBUG("Graceful exit.");
    log_close();
    return 0;
}