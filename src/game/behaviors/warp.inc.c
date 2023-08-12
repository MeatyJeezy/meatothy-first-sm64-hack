// warp.inc.c

void bhv_warp_loop(void) {
    if (o->oTimer == 0) {
        u16 radius = GET_BPARAM1(o->oBehParams);
        u16 disabled = GET_BPARAM4(o->oBehParams);
        u16 finalBossPipe = GET_BPARAM3(o->oBehParams);
        // NEW this is devilish code. Setting param 4 disables the warp effectively
        if (disabled != 0) {
            o->hitboxRadius = 0.0f;
            // SET BPARAM3 to denote the final boss warp. Handles whether to hide it or not.
        } else if (finalBossPipe != 0) { // RESERVED 0x69 for final boss!
            // At X stars, show the pipe warp.
            if((save_file_get_total_star_count(gCurrSaveFileNum - 1, COURSE_MIN - 1, COURSE_MAX - 1)) >= 5) {
               cur_obj_unhide();
               cur_obj_become_tangible(); 
            } else {
                o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
                cur_obj_hide();
                cur_obj_become_intangible();
            }
        } else {
            if (radius == 0) {
                o->hitboxRadius = 50.0f;
            } else if (radius == 0xFF) {
                o->hitboxRadius = 10000.0f;
            } else {
                o->hitboxRadius = radius * 10.0f;
            }
            o->hitboxHeight = 50.0f;
        }
    }

    o->oInteractStatus = INT_STATUS_NONE;
}

// identical to the above function except for o->hitboxRadius
void bhv_fading_warp_loop() {
    if (o->oTimer == 0) {
        u16 radius = GET_BPARAM1(o->oBehParams);

        if (radius == 0) {
            o->hitboxRadius = 85.0f;
        } else if (radius == 0xFF) {
            o->hitboxRadius = 10000.0f;
        } else {
            o->hitboxRadius = radius * 10.0f;
        }
        o->hitboxHeight = 50.0f;
    }

    o->oInteractStatus = INT_STATUS_NONE;
}
