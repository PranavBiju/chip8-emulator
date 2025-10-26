# include <stdio.h>
# include <stdlib.h>
#include <stdbool.h>
#include <SDL.h>

typedef struct{
    SDL_Window *window;
}sdl_t;

typedef struct{
    uint32_t window_width;
    uint32_t window_height;
}config_t;

bool init_sdl(sdl_t *sdl, const config_t config){
if(SDL_init(SDL_INIT_VIDEO| SDL_INIT_AUDIO| SDL_INIT_TIMER)!=0){
    SDL_Log("Could not initialize SDL subsystems! %s\n", SDL_GetError());
    return false;

}
sdl-> window = SDL_CreateWindow("CHIP8 Emulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, config.window_width, config.window_height, 0);

if(!sdl->window){
    SDL_Log("Could not create SDL window %s\n", SDL_GetError());
    return false;
}
return true;
}
bool set_config_from_args(config_t *config, int argc, char **argv){
    
}

void final_cleanup(void){
   SDL_DestroyWindow(window);
   SDL_Quit();
}

int main(){
sdl_t sdl={0};
if(!init_sdl(&sdl))
exit(EXIT_FAILURE);
config_t config ={0};
puts("TESTING ON MAC");
exit(EXIT_SUCCESS);
}