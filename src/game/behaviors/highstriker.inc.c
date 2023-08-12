// // breakable_box.inc.c

// struct ObjectHitbox sBreakableBoxHitbox = {
//     /* interactType:      */ INTERACT_BREAKABLE,
//     /* downOffset:        */  20,
//     /* damageOrCoinValue: */   0,
//     /* health:            */   1,
//     /* numLootCoins:      */   0,
//     /* radius:            */ 150,
//     /* height:            */ 200,
//     /* hurtboxRadius:     */ 150,
//     /* hurtboxHeight:     */ 200,
// };

// void breakable_box_init(void) {
//     o->oHiddenObjectSwitchObj = NULL;
//     o->oAnimState = BREAKABLE_BOX_ANIM_STATE_CORK_BOX;
//     switch (o->oBehParams2ndByte) {
//         case BREAKABLE_BOX_BP_NO_COINS: o->oNumLootCoins = 0; break;
//         case BREAKABLE_BOX_BP_3_COINS:  o->oNumLootCoins = 3; break;
//         case BREAKABLE_BOX_BP_5_COINS:  o->oNumLootCoins = 5; break;
//         case BREAKABLE_BOX_BP_LARGE:    cur_obj_scale(1.5f);  break;
//         case BREAKABLE_BOX_SUPER:       cur_obj_scale(0.5f);  break; // NEW
//     }
// }

// void hidden_breakable_box_actions(void) {
//     struct Object *switchObj;
//     obj_set_hitbox(o, &sBreakableBoxHitbox);
//     cur_obj_set_model(MODEL_BREAKABLE_BOX);
//     switch (o->oAction) {
//         case BREAKABLE_BOX_ACT_HIDDEN:
//             cur_obj_disable_rendering();
//             cur_obj_become_intangible();
//             if (o->oTimer == 0) {
//                 breakable_box_init();
//             }
//             if (o->oHiddenObjectSwitchObj == NULL) {
//                 o->oHiddenObjectSwitchObj = cur_obj_nearest_object_with_behavior(bhvFloorSwitchHiddenObjects);
//             }
//             switchObj = o->oHiddenObjectSwitchObj;
//             if ((switchObj != NULL) && (switchObj->oAction == PURPLE_SWITCH_ACT_TICKING)) {
//                 o->oAction = BREAKABLE_BOX_ACT_ACTIVE;
//                 cur_obj_enable_rendering();
//                 cur_obj_unhide();
//             }
//             break;
//         case BREAKABLE_BOX_ACT_ACTIVE:
//             cur_obj_become_tangible();
//             if (cur_obj_wait_then_blink(360, 20)) o->oAction = BREAKABLE_BOX_ACT_HIDDEN;
//             if (cur_obj_was_attacked_or_ground_pounded()) {
//                 spawn_mist_particles();
//                 spawn_triangle_break_particles(30, MODEL_DIRT_ANIMATION, 3.0f, TINY_DIRT_PARTICLE_ANIM_STATE_YELLOW);
//                 o->oAction = BREAKABLE_BOX_ACT_BROKEN;
//                 cur_obj_play_sound_2(SOUND_GENERAL_BREAK_BOX);
//             }
//             load_object_collision_model();
//             break;
//         case BREAKABLE_BOX_ACT_BROKEN:
//             cur_obj_become_intangible();
//             cur_obj_disable_rendering();
//             o->oInteractStatus = INT_STATUS_NONE;
//             switchObj = o->oHiddenObjectSwitchObj;
//             if ((switchObj != NULL) && (switchObj->oAction == PURPLE_SWITCH_ACT_IDLE)) {
//                 o->oAction = BREAKABLE_BOX_ACT_HIDDEN;
//             }
//             break;
//     }
// }

// void hidden_unbreakable_box_actions(void) {
//     struct Object *switchObj;
//     obj_set_collision_data(o, wdw_seg7_collision_hidden_platform);
//     switch (o->oAction) {
//         case BREAKABLE_BOX_ACT_HIDDEN:
//             cur_obj_disable_rendering();
//             cur_obj_become_intangible();
//             if (o->oHiddenObjectSwitchObj == NULL) {
//                 o->oHiddenObjectSwitchObj = cur_obj_nearest_object_with_behavior(bhvFloorSwitchHiddenObjects);
//             }
//             switchObj = o->oHiddenObjectSwitchObj;
//             if ((switchObj != NULL) && (switchObj->oAction == PURPLE_SWITCH_ACT_TICKING)) {
//                 o->oAction = BREAKABLE_BOX_ACT_ACTIVE;
//                 cur_obj_enable_rendering();
//                 cur_obj_unhide();
//             }
//             break;
//         case BREAKABLE_BOX_ACT_ACTIVE:
//             cur_obj_become_tangible();
//             if (cur_obj_wait_then_blink(360, 20)) o->oAction = BREAKABLE_BOX_ACT_HIDDEN;
//             load_object_collision_model();
//             break;
//     }
// }

// void bhv_hidden_object_loop(void) {
//     if (o->oBehParams2ndByte == BREAKABLE_BOX_BP_NO_COINS) {
//         hidden_breakable_box_actions();
//     } else {
//         hidden_unbreakable_box_actions();
//     }
// }

// void bhv_breakable_box_loop(void) {
//     obj_set_hitbox(o, &sBreakableBoxHitbox);
//     cur_obj_set_model(MODEL_BREAKABLE_BOX);
//     if (o->oTimer == 0) breakable_box_init();
//     if (o->oBehParams2ndByte == BREAKABLE_BOX_SUPER) {
//         if (cur_obj_is_mario_superpounding_platform()) { // NEW check if mario superpounds the block instead
//             obj_explode_and_spawn_coins(46.0f, COIN_TYPE_YELLOW);
//             create_sound_spawner(SOUND_GENERAL_BREAK_BOX);
//         }
//     } else 
//         if (cur_obj_was_attacked_or_ground_pounded()) {
//             obj_explode_and_spawn_coins(46.0f, COIN_TYPE_YELLOW);
//             create_sound_spawner(SOUND_GENERAL_BREAK_BOX);
//         }
//     
// }

// Action 1: init
// 2: fail
// 3: success

void bhv_highstriker_bell_init (void) {
    //o->oAnimations = HIGHSTRIKER_BELL_LAUNCH;
    // Bell on the ground if true
    if (save_file_get_flags() & SAVE_FLAG_UNLOCKED_BITFS_DOOR) {
        o->oAction = HIGHSTRIKER_ACT_COMPLETE;
        // set pos?
    }
    cur_obj_unhide();
    cur_obj_scale(1.0f);
}
void bhv_highstriker_bell_loop (void) {
    o->oAnimations = 0;
    if (o->oDistanceToMario < 300) {
        gMarioState->hurtCounter += 40;
    }
}
void bhv_highstriker_machine_init (void) {
    if (o->oBehParams2ndByte != 0) {
        cur_obj_scale(5.0f);
    }
    //load_object_collision_model();
}
void bhv_highstriker_machine_loop (void) {
    if (cur_obj_is_mario_superpounding_platform()) { // success
        if (o->oBehParams2ndByte == 0) {
            struct Object *carnyObj = cur_obj_nearest_object_with_behavior(bhvHighStrikerCarny);
            carnyObj->oAction = 3;
        }
        else { // prevents a million spawns
            if (o->oAction == 0) {
                spawn_object_relative(0xBD, 100, 100, 300, gMarioState->marioObj, MODEL_LAKITU, bhvCameraLakitu);
                o->oAction++;
            }
        }
        
    } else if (cur_obj_was_attacked_or_ground_pounded()) { // fail
        // The machine sets the Carny's action
        if (o->oBehParams2ndByte == 0) {
            struct Object *carnyObj = cur_obj_nearest_object_with_behavior(bhvHighStrikerCarny);
            carnyObj->oAction = 2;
        }
        // if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP,
        // DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_DIALOG, o->oBehParams2ndByte)) {

        //}
    }
}
void bhv_highstriker_carny_init (void) {
    // Carny dead if true
    // if (save_file_get_flags() & SAVE_FLAG_UNLOCKED_BITFS_DOOR) {
    //     o->oAction = HIGHSTRIKER_ACT_COMPLETE;
    //     // set pos?
    // }
    cur_obj_unhide();
    cur_obj_scale(0.6f);
    o->oInteractionSubtype = INT_SUBTYPE_NPC;
}

static void carny_not_talking(void) {
    if (o->oInteractStatus == INT_STATUS_INTERACTED) {
        o->oInteractStatus = INT_STATUS_NONE;
        o->oAction = 1;
    }
}

static void carny_message_default(void) {
    // o->oFaceAngleYaw = o->oAngleToMario;
    if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_FRONT,
        DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_DIALOG, DIALOG_195)) {
        // Handle special dialogue.
        o->oInteractStatus = INT_STATUS_NONE;
        o->oAction = 0;
    }
}
static void carny_message_fail(void) {
    if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_FRONT,
        DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_DIALOG, DIALOG_196)) {
        // Handle special dialogue.
        o->oInteractStatus = INT_STATUS_NONE;
        o->oAction = 0;
    }
}

static void carny_message_success(void) {
    if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_FRONT,
        DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_DIALOG, DIALOG_197)) {
        // Award a star.
        struct Object *starObj = spawn_object_abs_with_rot(o, 0, MODEL_STAR, bhvStarSpawnCoordinates, o->oPosX, o->oPosY + 200, o->oPosZ + 200, 0, 0, 0);
        starObj->oBehParams = 0x01000000;
        starObj->oInteractionSubtype = INT_SUBTYPE_NO_EXIT;
        vec3f_set(&starObj->oHomeVec, o->oPosX, o->oPosY + 400, o->oPosZ + 500);
        starObj->oFaceAnglePitch = 0;
        starObj->oFaceAngleRoll = 0;

        o->oInteractStatus = INT_STATUS_NONE;
        o->oAction = 0;
    }
}
void bhv_highstriker_carny_loop (void) {
    switch(o->oAction) {
            case 0:
            carny_not_talking();
            break;

            case 1:
            carny_message_default();
            break;

            case 2:
            carny_message_fail();
            break;

            case 3:
            carny_message_success();
            break;
        }
}