#include "text_strings.h"

// Loop to decrement timer. kill mario if timer reaches 0, and delete the obj if mario presses L to ligma shield

void bhv_ligma_loop(void) {
    u8 ligmaString [] = { TEXT_LIGMA_DEFAULT };
    s32 dialogID;
    dialogID = o->oBehParams2ndByte;
    if (!(o->oLigmaTimerStarted)) {
        o->oTimer = 0;
        o->oLigmaTimerStarted = TRUE;

        //Kill after several seconds. 
    } else { 
        // Delete if L trigger is pressed
        if ((gPlayer1Controller->buttonPressed & L_TRIG)) {
            play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
            obj_mark_for_deletion(o);
            // Increment the timer and kill the player with the appropriate ligma joke
        } else if (o->oTimer++ > 300) {
            // Check which joke to use and print it in center of screen, then kill mario
            gMarioState->health = 0xFF;
            switch (dialogID) {
                case LIGMA_DIALOG_UPOST:
                    //ligmaString = { TEXT_LIGMA_UPOST };
                    //print_hud_lut_string(HUD_LUT_GLOBAL, 10, 69, ligmaString);
                    set_mario_action(gMarioState, ACT_STANDING_DEATH, 0);
                    obj_mark_for_deletion(o);
                break;
                case LIGMA_DIALOG_FISSTIN: 
                    //ligmaString[] = { TEXT_LIGMA_FISSTIN };
                    //print_hud_lut_string(HUD_LUT_GLOBAL, 10, 69, ligmaString);
                    set_mario_action(gMarioState, ACT_STANDING_DEATH, 0);
                    obj_mark_for_deletion(o);
                break;
                case LIGMA_DIALOG_TASTEOFEDEN:
                    //ligmaString[] = { TEXT_LIGMA_FISSTIN };
                    //print_hud_lut_string(HUD_LUT_GLOBAL, 10, 69, ligmaString);
                    set_mario_action(gMarioState, ACT_STANDING_DEATH, 0);
                    obj_mark_for_deletion(o);
                break;
                default: 
                    //ligmaString[] = { TEXT_LIGMA_DEFAULT };
                    //print_hud_lut_string(HUD_LUT_GLOBAL, 10, 69, ligmaString);
                    set_mario_action(gMarioState, ACT_STANDING_DEATH, 0);
                    obj_mark_for_deletion(o);
                break;
            }
        }
    }
}