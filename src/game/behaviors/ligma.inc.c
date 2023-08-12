
// Loop to decrement timer. kill mario if timer reaches 0, and delete the obj if mario presses L to ligma shield

void bhv_ligma_loop(void) {
    // Finds dialog id?
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
            if (dialogID == 0xBD) {
                create_dialog_box(DIALOG_209);
                enable_time_stop_including_mario();
                spawn_object_relative(0x7A, 0, 0, 0, gMarioState->marioObj, MODEL_NONE, bhvWarp);
            }
            if (get_dialog_id() < 0) {
                disable_time_stop_including_mario();
                obj_mark_for_deletion(o);
            }
            
            

            // Increment the timer and kill the player with the appropriate ligma joke
        } else if (o->oTimer++ > 220) {
            // If Mario is supposed to die and there's no dialogue box
            if (o->oLigmaKilledMario &&  (get_dialog_id() < 0)) {
                disable_time_stop_including_mario();
                // set a flag to indicate ligma death
                save_file_set_flags(SAVE_FLAG_UNLOCKED_JRB_DOOR);
                // trigger death action if not already doing it.
                if (gMarioState->action != ACT_STANDING_DEATH && dialogID != 0xBD) {
                    set_mario_action(gMarioState, ACT_STANDING_DEATH, 0);
                    obj_mark_for_deletion(o);
                } else if (dialogID == 0xBD) {
                    spawn_object_relative(0x7A, 0, 0, 0, gMarioState->marioObj, MODEL_NONE, bhvWarp);
                }
            }

            // Check which joke to use and print it in center of screen, then kill mario
            if (!(o->oLigmaKilledMario)) {
                // if (dialogID == 0xBD) {
                //     spawn_object_relative(0x7A, 0, 0, 0, gMarioState->marioObj, MODEL_NONE, bhvWarp);
                // }
                // dialogID + 1 should always give correct "gottem" text
                o->oLigmaKilledMario = TRUE;
                create_dialog_box(dialogID + 1);
                // Freeze until dialog box closes?
                enable_time_stop_including_mario();
                
            }
        }
    }
}