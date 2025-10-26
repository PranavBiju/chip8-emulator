# include <stdio.h>
# include <stdlib.h>
#include <stdbool.h>
#include <SDL.h>

typedef struct{
    SDL_Window *window;
    SDL_Renderer *renderer;
}sdl_t;

typedef struct{
    uint32_t window_width;
    uint32_t window_height;
    uint32_t fg_color;
    uint32_t bg_color;
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
sdl->renderer= SDL_CreateRenderer(sdl->window,-1 , SDL_RENDERER_ACCELERATED);
if (!sdl->renderer){
    SDL_Log("Could not create SDL %s", SDL_GetError());
    return false;
}
return true;
}

bool set_config_from_args(config_t *config, int argc, char **argv){

   *config = (config_t){
            .window_width = 64,
              .window_height= 32,
              .fg_color = 0xFFFFFFFF,
              .bg_color = 0x00000000
   };
   for(int i =1;i<argc;i++){
   (void) argv[i];
}
return true;
}


void final_cleanup(const sdl_t sdl){
    SDL_DestroyRenderer(sdl.renderer);
   SDL_DestroyWindow(sdl.window);
   SDL_Quit();
}
void clear_screen(const sdl_t sdl,const config_t config){
const uint8_t r =(uint8_t) (config.bg_color>>24)&0xFF;
const uint8_t g =(uint8_t) (config.bg_color>>16)&0xFF;
const uint8_t b =(uint8_t) (config.bg_color>>8)&0xFF;
const uint8_t a =(uint8_t) (config.bg_color>>0)&0xFF;
}
void update_screen(const sdl_t sdl){
    SDL_RenderPresent(renderer)
}
int main(int argc, char** argv){

    config_t config ={0};
if(!set_config_from_args(&config, argc, argv))
exit(EXIT_FAILURE);
sdl_t sdl={0};
if(!init_sdl(&sdl, config))
exit(EXIT_FAILURE);
clear_screen(sdl, config);
const uint8_t


while(true){
    SDL_Delay(16);
   update_screen(sdl);
}

puts("TESTING ON MAC");
exit(EXIT_SUCCESS);
}