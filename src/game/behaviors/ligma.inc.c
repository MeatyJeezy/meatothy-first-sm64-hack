//#include "text_strings.h"

// Loop to decrement timer. kill mario if timer reaches 0, and delete the obj if mario presses L to ligma shield

void bhv_ligma_loop(void) {
    // Finds dialog id?
    //void **dialogTable = segmented_to_virtual(seg2_dialog_table);
    s32 dialogID;
    dialogID = o->oBehParams2ndByte;

    if (!(o->oLigmaTimerStarted)) {
        o->oTimer = 0;
        o->oLigmaTimerStarted = TRUE;

        //Kill after several seconds. 
    } else { 
        // Delete if L trigger is pressed
        if (((gPlayer1Controller->buttonPressed & L_TRIG) && !(o->oLigmaKilledMario))) {
            play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
            obj_mark_for_deletion(o);

            // Increment the timer and kill the player with the appropriate ligma joke
        } else if (o->oTimer++ > 250) {
            // If Mario is supposed to die and there's no dialogue box
            if (o->oLigmaKilledMario &&  (get_dialog_id() < 0)) {
                disable_time_stop_including_mario();
                // trigger death action if not already doing it.
                if (gMarioState->action != ACT_STANDING_DEATH) {
                    set_mario_action(gMarioState, ACT_STANDING_DEATH, 0);
                    obj_mark_for_deletion(o);
                }
            }

            // Check which joke to use and print it in center of screen, then kill mario
            if (!(o->oLigmaKilledMario)) {
                // dialogID + 1 should always give correct "gottem" text
                o->oLigmaKilledMario = TRUE;
                create_dialog_box(dialogID + 1);
                // Freeze until dialog box closes?
                enable_time_stop_including_mario();
            }
        }
    }
}