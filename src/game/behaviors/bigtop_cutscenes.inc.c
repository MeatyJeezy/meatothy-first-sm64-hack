#include "game/interaction.h"
/*
 * Behavior for bhvBigtopCutscene. 
 */

/*
    Bigtop acts: 
*/

// TODO: Add init function to choose which cutscene to play. Checks the players WF star flags.


// NEW enum for fappy bigtop dialogue
// 1 and 2 for cutscene 1
// for cutscene 2
enum FappyBigtopDialog {
    FAPPY_BIGTOP_DIALOG_0   = 0xAE,
    FAPPY_BIGTOP_DIALOG_1,
    FAPPY_BIGTOP_DIALOG_2,
    FAPPY_BIGTOP_DIALOG_3
};

// Lock Mario in place prepare for cutscene
static void bigtop_act_trigger_cutscene(void) {
    if (o->oDistanceToMario < 8000.0f) {
        o->oAnimState = FAPPY_ANIM_DEFAULT;

        if (set_mario_npc_dialog(MARIO_DIALOG_LOOK_UP) == MARIO_DIALOG_STATUS_START) { // CHANGED to detect Proximity instead of hard-coded values
                o->oAction = BIGTOP_ACT_MOVE_CAMERA;
        }
    }
}

static void fappy_face_camera(void) {
    o->oFaceAnglePitch = 0;
    //o->oFappyYawVel = approach_s16_symmetric(o->oFappyYawVel, 2000, 100);
    o->oFaceAngleYaw = o->oAngleToMario; //cur_obj_rotate_yaw_toward(yaw, 50);
    
}
// Move camera up and towards Fappy
static void move_and_point_camera_at_object(void) {
    Vec3f focus;
    //s16 pitch;
    //s16 yaw;

    // Gets Fappy position
    object_pos_to_vec3f(focus, o);
    focus[0] = o->oPosX +300;
    focus[1] = o->oPosY + 200;
    focus[2] = o->oPosZ + 200;
    approach_vec3f_asymptotic(gPlayerCameraState->pos, focus, 0.2f, 0.93f, 0.85f);
    fappy_face_camera();
}

static void bigtop_act_move_camera(void) {
    //f32 focusDistance
    // 2nd Byte Param specifies which cutscene and dialogue. Starts at 0x00.
    switch (o->oBehParams2ndByte) {
        case BIGTOP_FIRST_CUTSCENE:
        // Point cam at Fappy, and turn him towards camera a bit
        move_and_point_camera_at_object();
        // Once dialog is done, set object movement vars advance action
            if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP,
            DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_DIALOG, FAPPY_BIGTOP_DIALOG_0)) {
                set_mario_npc_dialog(MARIO_DIALOG_LOOK_UP);
                o->oAction = BIGTOP_ACT_MOVE_FAPPY_TO_MARIO;

                o->oMoveAnglePitch = 0x4000;
                o->oFappySpeed = 60.0f; 
                o->oFappyCircleRadius = 1000.0f;

                save_file_set_flags(SAVE_FLAG_CUSTOM_1);
            }
        break;

        case BIGTOP_SECOND_CUTSCENE:
            //SKIP THIS FIRST PART FOR EVERYTHING BUT CUTSCENE 1
            // move_and_point_camera_at_object();
            // if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP,
            // DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_DIALOG, FAPPY_BIGTOP_DIALOG_1)) {
                o->oAction = BIGTOP_ACT_MOVE_FAPPY_TO_MARIO;
                o->oMoveAnglePitch = 0x4000;
                o->oFappySpeed = 60.0f; 
                o->oFappyCircleRadius = 1000.0f;

                save_file_set_flags(SAVE_FLAG_CUSTOM_2);
        break;

        case BIGTOP_THIRD_CUTSCENE:
            // move_and_point_camera_at_object();
            // if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP,
            // DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_DIALOG, FAPPY_BIGTOP_DIALOG_2)) {
                o->oAction = BIGTOP_ACT_MOVE_FAPPY_TO_MARIO;
                o->oMoveAnglePitch = 0x4000;
                o->oFappySpeed = 60.0f; 
                o->oFappyCircleRadius = 1000.0f;

                save_file_set_flags(SAVE_FLAG_CUSTOM_3);
        break;

        // I don't intend to have this many challenges probably, so this just deletes the object and lets the player roam freely
        case BIGTOP_FOURTH_CUTSCENE:

        break;
    }
}

// Fly fappy down to Mario and deliver final dialogue,
static void bigtop_act_move_fappy_to_mario(void) {
    s16 targetMovePitch = 0x0;
    s16 targetMoveYaw = 0x0;

// TEMPORARY HERE TO TEST
    //cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_DIALOG, DIALOG_174);
    // Move to next action if dialogue is done, else move to mario and initiate dialogue
    o->oFaceAnglePitch = obj_turn_pitch_toward_mario(120.0f, 0);
    o->oFaceAngleYaw = o->oAngleToMario;
    if (o->oFappyFinishedDialog) {
        // Keep mario locked in so he is forced to use warp
        o->oFappyCounter = 0;
        o->oAction++;
        targetMovePitch = -0x3000;
        targetMoveYaw = -0x6000;
    } else {
        if (o->oFappySpeed != 0.0f) {
            if (o->oDistanceToMario > 5000.0f) {
                targetMovePitch = o->oMoveAnglePitch;
                targetMoveYaw = o->oAngleToMario;
            } else {
                // Move cam close behind mario and look slightly up, like in c-up mode almost
                // maybe this function will work? shit idk.

                // Stay moving in a circle around mario
                s16 turnAmount = 0x4000
                                 - atan2s(o->oFappyCircleRadius,
                                          o->oDistanceToMario - o->oFappyCircleRadius);
                if ((s16)(o->oMoveAngleYaw - o->oAngleToMario) < 0) {
                    turnAmount = -turnAmount;
                }

                targetMoveYaw = o->oAngleToMario + turnAmount;
                targetMovePitch = o->oFaceAnglePitch;

                approach_f32_ptr(&o->oFappyCircleRadius, 200.0f, 50.0f);
                if (o->oDistanceToMario < 1000.0f) {
                    if (!o->oFappyIntroMusicPlayed) {
                        //play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(15, SEQ_EVENT_CUTSCENE_LAKITU), 0); //CHANGED don't want music interrupted.
                        cur_obj_play_sound_1(SOUND_ACTION_FLYING_FAST);
                        o->oFappyIntroMusicPlayed = TRUE;
                    }
                    // Once within 1000 units, slow down
                    approach_f32_ptr(&o->oFappySpeed, 20.0f, 1.0f);
                    if (o->oDistanceToMario < 600.0f // CHANGED 500 to 600
                        && abs_angle_diff(gMarioObject->oFaceAngleYaw, o->oFaceAngleYaw) > 0x7000) {
                        // Once within 500 units and facing toward mario, come to a stop
                        approach_f32_ptr(&o->oFappySpeed, 0.0f, 5.0f);
                    }
                }
            }
        } else if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP,
            DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_DIALOG, (o->oBehParams2ndByte + FAPPY_BIGTOP_DIALOG_1))) { // Adding BIGTOP_DIALOG_1 should play the second dialogue in cutscene 1.
            o->oFappyFinishedDialog = TRUE;
            set_mario_npc_dialog(MARIO_DIALOG_LOOK_FRONT);
        }
    }
    
    o->oFappyPitchVel = approach_s16_symmetric(o->oFappyPitchVel, 2000, 400);
    obj_move_pitch_approach(targetMovePitch, o->oFappyPitchVel);

    o->oFappyYawVel = approach_s16_symmetric(o->oFappyYawVel, 2000, 100);
    cur_obj_rotate_yaw_toward(targetMoveYaw, o->oFappyYawVel);

    // vel y is explicitly computed, so gravity doesn't apply
    obj_compute_vel_from_move_pitch(o->oFappySpeed);
    cur_obj_move_using_fvel_and_gravity();
    //o->oFappyFinishedDialog = TRUE;
}

// Warp mario into the right place, play final dialogue and fly away
static void bigtop_act_end_cutscene(void) {
    s16 warpParam = 0xF1;
    s16 targetMovePitch = 0x0;
    s16 targetMoveYaw = 0x0;

    // Set warp param to move mario to new area
    switch (o->oBehParams2ndByte) {
        case BIGTOP_FIRST_CUTSCENE: // warp 0xB - C
        warpParam = 0xB;
        break;
        case BIGTOP_SECOND_CUTSCENE: // warp 0xD - E
        warpParam = 0xD;
        break;
        case BIGTOP_THIRD_CUTSCENE: // warp 0xF - 0x10
        warpParam = 0xF;
        break;
    }
    // Added these checks for if Mario is skipping the cutscene. Makes sure the warp doesnt appear before he is grounded.
    if (o->oFappyCounter == 0) {
        // Airborne check
        if (!(gMarioState->action & ACT_FLAG_AIR)) {
            // Make a new object with the param set to the warp we want to use
            spawn_object_relative(warpParam, 0, 0, 0, gMarioState->marioObj, MODEL_NONE, bhvFadingWarp);
            o->oFappyCounter++;
        }
    } else {
        approach_f32_ptr(&o->oFappySpeed, 60.0f, 3.0f);
        if (o->oDistanceToMario > 5000.0f) {
            set_mario_npc_dialog(MARIO_DIALOG_STOP);
            // This all might be a little extra but if it works idgaf
                struct Object *fappyObj = o;
                struct Object *fadeWarp = cur_obj_nearest_object_with_behavior(bhvFadingWarp);
                gMarioState->usedObj = fadeWarp;
                gMarioState->interactObj = fadeWarp;
                // Force tele?
                gMarioState->action = ACT_IDLE;
                set_camera_mode(gMarioState->area->camera, CAMERA_MODE_8_DIRECTIONS, 1);
                obj_mark_for_deletion(fappyObj);
        }
        targetMovePitch = -0x3000;
        targetMoveYaw = -0x6000;

        o->oFappyPitchVel = approach_s16_symmetric(o->oFappyPitchVel, 2000, 400);
        obj_move_pitch_approach(targetMovePitch, o->oFappyPitchVel);

        o->oFappyYawVel = approach_s16_symmetric(o->oFappyYawVel, 2000, 100);
        cur_obj_rotate_yaw_toward(targetMoveYaw, o->oFappyYawVel);

        // vel y is explicitly computed, so gravity doesn't apply
        obj_compute_vel_from_move_pitch(o->oFappySpeed);
        cur_obj_move_using_fvel_and_gravity();
    }
}

// Check each flag to see whether to skip straight to end
void check_bigtop_cutscene_flags(void) {
    u32 flags = save_file_get_flags();

    switch (o->oBehParams2ndByte) {
        case BIGTOP_FIRST_CUTSCENE:
        if (flags & SAVE_FLAG_CUSTOM_1) {
            o->oAction = BIGTOP_ACT_END_CUTSCENE;
            cur_obj_hide();
        }
        break;
        case BIGTOP_SECOND_CUTSCENE:
        if (flags & SAVE_FLAG_CUSTOM_2) {
            o->oAction = BIGTOP_ACT_END_CUTSCENE;
            cur_obj_hide();
        }
        break;
        case BIGTOP_THIRD_CUTSCENE:
        if (flags & SAVE_FLAG_CUSTOM_3) {
            o->oAction = BIGTOP_ACT_END_CUTSCENE;
            cur_obj_hide();
        }
        break;
    }
}

void bhv_bigtop_cutscene_init(void) {
    o->oBehParams2ndByte = 0;

    //TEMPORARY SKIP THE FIRST CUTSCENE FOR DEBUG PURPOSES
    save_file_set_flags(SAVE_FLAG_CUSTOM_1);
    // Add 1 to the 
    if (save_file_get_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(COURSE_WF)) & STAR_FLAG_ACT_1) {
        o->oBehParams2ndByte = 1;
        if (save_file_get_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(COURSE_WF)) & STAR_FLAG_ACT_2) {
            o->oBehParams2ndByte = 2;
            if (save_file_get_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(COURSE_WF)) & STAR_FLAG_ACT_3) {
                o->oBehParams2ndByte = 3;
                
            }
        }
    }
}
/**
 * Update function for bigtop cutscene.
 */
void bhv_bigtop_cutscene_loop(void) {

    cur_obj_unhide();
    if (o->oBehParams2ndByte >= BIGTOP_FOURTH_CUTSCENE) {
        // Delete it, no cutscene to play
        obj_mark_for_deletion(o);
    }
    // Fixes cam until last function call
    // The camera gets all weird, reset it somewhere
    if (o->oDistanceToMario < 8000.0f && o->oAction < BIGTOP_ACT_END_CUTSCENE) {
        if (o->oAction == BIGTOP_ACT_TRIGGER_CUTSCENE) {
            check_bigtop_cutscene_flags();
        }
        set_camera_mode(gMarioState->area->camera, CAMERA_MODE_FIXED, 1);
    }
        switch (o->oAction) {
            case BIGTOP_ACT_TRIGGER_CUTSCENE:
                bigtop_act_trigger_cutscene();
                break;
            case BIGTOP_ACT_MOVE_CAMERA:
                bigtop_act_move_camera(); 
                break;
            case BIGTOP_ACT_MOVE_FAPPY_TO_MARIO:
                bigtop_act_move_fappy_to_mario();
                break;
            case BIGTOP_ACT_END_CUTSCENE:
                bigtop_act_end_cutscene();
                break;
        }
}
