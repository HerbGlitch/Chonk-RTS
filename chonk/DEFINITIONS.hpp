#pragma once

#define SPRITESHEET "../res/img/scifi_tilesheet.png"

#define TEMP_BUILDING          SDL_Rect { 128 * 14, 128 * 02, 128, 128 }
#define TEMP_BUILDING_SELECTED SDL_Rect { 128 * 14, 128 * 01, 128, 128 }

#define TEMP_BASIC             SDL_Rect { 128 * 06 + 48, 128 * 03 + 40, 32, 48 }
#define TEMP_ADVANCED          SDL_Rect { 128 * 06 + 48, 128 * 04 + 40, 32, 48 }


enum EntityType {
    BASE, BASIC, ADVANCED
};